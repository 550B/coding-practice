using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolTip;

namespace myElevator
{
    public class Ele
    {
        public int INFINITE = 100;      //无穷大
        public enum ELEDOOR             //开关门状态
        {
            CLOSE, OPEN
        }
        public enum ELEMOVE             //电梯移动状态
        {
            STILL, UP, DOWN
        }
        public enum ELESTART            //电梯启动状态
        {
            NONE, START, STOP
        }

        private Timer aTimer;               //计时器
        public List<List<int>> request;     //顺路消息队列
        public List<List<int>> requestRev;  //不顺路消息队列
        public int CNT = 5;                 //电梯数
        public int MAX = 21;                //最大楼层数（舍弃0）
        public List<bool> eleEnabled;       //电梯禁用状态
        public List<ELEDOOR> eleDoor;       //电梯门状态
        public List<ELEMOVE> eleMove;       //电梯移动状态
        public List<ELESTART> eleStart;     //电梯运动状态
        public List<int> floor;             //电梯所在楼层

        public Ele()
        {
            //计时器，1秒更新一次状态
            this.aTimer = new Timer
            {
                Interval = 1000
            };
            this.aTimer.Tick += this.updateEleState;
            this.aTimer.Start();

            //消息队列，分顺路和不顺路两种
            request = new List<List<int>>();
            for (int i = 0; i < CNT; i++)
                request.Add(new List<int>());
            requestRev = new List<List<int>>();
            for (int i = 0; i < CNT; i++)
                requestRev.Add(new List<int>());

            //电梯参数数组初始化
            eleEnabled = new List<bool>(CNT);
            eleDoor = new List<ELEDOOR>(CNT);
            eleMove = new List<ELEMOVE>(CNT);
            eleStart = new List<ELESTART>(CNT);
            floor = new List<int>(CNT);
            for (int i = 0; i < CNT; i++)
            {
                eleEnabled.Add(true);
                eleDoor.Add(ELEDOOR.CLOSE);
                eleMove.Add(ELEMOVE.STILL);
                eleStart.Add(ELESTART.NONE);
                floor.Add(1);
            }
        }

        //开关门检查
        public void eleOpenCloseDoor(int index, bool oc)
        {
            if (oc)         //用户请求开门
            {
                if (eleDoor[index] == ELEDOOR.CLOSE && eleMove[index] == ELEMOVE.STILL) //门关闭且电梯静止
                {
                    eleDoor[index] = ELEDOOR.OPEN;
                    eleEnabled[index] = false;
                    MessageBox.Show(index.ToString() + "号电梯门已开！");
                }
            }
            else            //用户请求关门
            {
                if (eleDoor[index] == ELEDOOR.OPEN && eleMove[index] == ELEMOVE.STILL)  //门开启且电梯静止
                {
                    eleDoor[index] = ELEDOOR.CLOSE;
                    eleEnabled[index] = true;
                    MessageBox.Show(index.ToString() + "号电梯门已关！");
                }
            }
        }

        //内部点击按钮
        public void eleInside(int index, int dest, Button button)
        {
            int cur = floor[index];        //当前电梯位置
            if (cur < dest)                //按键大于当前楼层
            {
                if (eleMove[index] == ELEMOVE.STILL)        //电梯静止
                    request[index].Add(dest);            //加入请求队列
                else
                {
                    if (eleMove[index] == ELEMOVE.UP)       //电梯向上
                    {
                        request[index].Add(dest);        //加入请求队列
                        request[index].Sort();              //排序
                    }
                    else if(eleMove[index] == ELEMOVE.DOWN) //电梯向下
                    {
                        requestRev[index].Add(dest);     //加入不顺路队列
                        requestRev[index].Sort();           //排序
                    }
                }
            }
            else if (cur > dest)        //按键小于当前楼层
            {
                if (eleMove[index] == ELEMOVE.STILL)
                    request[index].Add(dest);
                else
                {
                    if (eleMove[index] == ELEMOVE.DOWN)
                    {
                        request[index].Add(dest);
                        request[index].Sort();
                        request[index].Reverse();       //反向
                    }
                    else if (eleMove[index] == ELEMOVE.UP)
                    {
                        requestRev[index].Add(dest);
                        requestRev[index].Sort();
                        requestRev[index].Reverse();    //反向
                    }
                }
            }
            else
            {
                if(eleMove[index] == ELEMOVE.STILL)     //在本层
                {
                    eleDoor[index] = ELEDOOR.OPEN;      //开门
                }
                button.BackColor = Color.White;         //恢复颜色
                button.Enabled = true;                  //恢复可点击
            }
        }

        //更新数据
        private void updateEleState(object sender, EventArgs e)
        {
            for (int i = 0; i < request.Count; i++)     //遍历五部电梯
            {
                if (request[i].Count > 0)              //某电梯消息队列不空
                {
                    if (eleDoor[i] == ELEDOOR.OPEN)     //如果开着门
                    {
                        //MessageBox.Show("第" + i.ToString() + "部电梯请先关门！");
                        continue;
                    }
                    else if (eleMove[i] == ELEMOVE.STILL)   //关门静止
                    {
                        if (floor[i] < request[i].First())  //当前楼层小于请求楼层
                        {
                            eleMove[i] = ELEMOVE.UP;        //电梯向上
                        }
                        else if (floor[i] > request[i][0])  //当前楼层大于请求楼层
                        {
                            eleMove[i] = ELEMOVE.DOWN;      //电梯向下
                        }
                        eleStart[i] = ELESTART.START;       //电梯启动
                    }
                    else if (eleStart[i] == ELESTART.START) //电梯启动状态
                    {
                        eleStart[i] = ELESTART.NONE;        //无动作
                    }
                    else if (eleStart[i] == ELESTART.STOP)  //电梯停止状态
                    {
                        request[i].RemoveAt(0);             //出队
                        eleStart[i] = ELESTART.NONE;        //无动作
                        eleMove[i] = ELEMOVE.STILL;         //静止
                    }
                    else                                    //在行驶途中
                    {
                        int dest = request[i][0];           //取出队头

                        if (floor[i] < dest)                //目的地在上面
                        {
                            eleMove[i] = ELEMOVE.UP;        //上行
                            floor[i]++;                     //当前楼层上移一层
                        }
                        else if (floor[i] > dest)           //目的地在下面
                        {
                            eleMove[i] = ELEMOVE.DOWN;      //下行
                            floor[i]--;                     //当前楼层下移一层
                        }
                        else                                //到达
                        {
                            eleStart[i] = ELESTART.STOP;    //电梯停止状态
                        }
                    }
                }
                else if (requestRev[i].Count > 0)           //有不顺路请求
                {
                    request[i].InsertRange(0, requestRev[i]);   //更改为顺路
                    requestRev[i].Clear();      //不顺路清空
                }
            }
        }
    }
}
