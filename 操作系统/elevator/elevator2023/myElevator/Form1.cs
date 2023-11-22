using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static myElevator.Ele;

namespace myElevator
{
    public partial class Form1 : Form
    {
        public Ele ctrl;            //对象
        public int CNT = 5;         //最多电梯数
        public int MAX = 21;        //最高楼层数（索引起始1）
        public Timer infoTimer;     //更新信息计时器
        public List<int> tmp;       //临时楼层（记录路径要用）

        public Form1()
        {
            InitializeComponent();
        }

        private void loadForm(object sender, EventArgs e)       //加载窗口时初始化
        {
            tinfo.Text += "欢迎来到电梯调度！\n";
            ctrl = new Ele();
            tmp = new List<int>(CNT);
            tmp.InsertRange(0, ctrl.floor);
            //计时器，1秒更新一次状态
            this.infoTimer = new Timer
            {
                Interval = 10
            };
            this.infoTimer.Tick += this.updateInfo;
            this.infoTimer.Start();
        }

        //更新每部电梯对外显示信息
        public void updateInfo(object sender, EventArgs e)
        {
            for (int i = 0; i < CNT; i++)       //每部电梯
            {
                for (int j = 0; j < MAX; j++)   //每层楼
                {
                    Control[] myfindcs = this.Controls.Find("b" + i.ToString() + j.ToString(), true);   //找楼层按钮
                    Control[] myfindw = this.Controls.Find("b" + i.ToString() + "warn", true);          //找报警按钮
                    if (myfindcs.Length > 0 && myfindw.Length > 0)      //找到了
                    {
                        //找到控件
                        if (myfindcs[0].Enabled == false && !ctrl.request[i].Contains(j) && !ctrl.requestRev[i].Contains(j) && myfindw[0].Enabled == true)
                        {   
                            //楼层按钮禁用，不在任何队列里，报警按钮启用
                            myfindcs[0].Enabled = true;             //按钮启用
                            myfindcs[0].BackColor = Color.White;    //颜色重置
                        }

                        //禁用后清空请求队列按钮
                        if (myfindcs[0].Enabled == false && !ctrl.request[i].Contains(j) && !ctrl.requestRev[i].Contains(j) && myfindw[0].Enabled == false)
                        {
                            //楼层按钮禁用，不在任何队列里，报警按钮禁用
                            if (myfindcs[0].BackColor != Color.Pink)    //不是当前楼层
                            {
                                myfindcs[0].BackColor = Color.White;    //颜色重置
                            }
                        }

                        //电梯在运行过程中禁止点击报警按钮
                        if (ctrl.eleEnabled[i])     //可调度电梯
                        {
                            if (ctrl.eleMove[i] == ELEMOVE.STILL)       //静止
                            {
                                myfindw[0].Enabled = true;      //可以按报警按钮
                            }
                            else
                            {
                                myfindw[0].Enabled = false;     //否则不能
                            }
                        }

                        //显示路径
                        if (ctrl.floor[i] == j)
                        {
                            //MessageBox.Show(tmp[i].ToString());
                            if (tmp[i] == ctrl.floor[i])        //上一次楼层与现在楼层相同，没动
                            {
                                myfindcs[0].BackColor = Color.Pink;     //置粉红色
                            }
                            else if (tmp[i] > ctrl.floor[i])    //电梯下行了
                            {
                                //myfindcs[0].BackColor = Color.Pink;
                                myfindcs = this.Controls.Find("b" + i.ToString() + (j + 1).ToString(), true);
                                myfindcs[0].BackColor = Color.White;
                                tmp[i]--;
                            }
                            else 
                            {
                                //myfindcs[0].BackColor = Color.Pink;
                                myfindcs = this.Controls.Find("b" + i.ToString() + (j - 1).ToString(), true);
                                myfindcs[0].BackColor = Color.White;
                                tmp[i]++;
                            }
                        }
                    }
                }
            }
            //更新电梯状态
            #region
            t01.Text = ctrl.eleEnabled[0].ToString();
            t02.Text = ctrl.eleDoor[0].ToString();
            t03.Text = ctrl.eleMove[0].ToString();
            t04.Text = ctrl.floor[0].ToString();
            t11.Text = ctrl.eleEnabled[1].ToString();
            t12.Text = ctrl.eleDoor[1].ToString();
            t13.Text = ctrl.eleMove[1].ToString();
            t14.Text = ctrl.floor[1].ToString();
            t21.Text = ctrl.eleEnabled[2].ToString();
            t22.Text = ctrl.eleDoor[2].ToString();
            t23.Text = ctrl.eleMove[2].ToString();
            t24.Text = ctrl.floor[2].ToString();
            t31.Text = ctrl.eleEnabled[3].ToString();
            t32.Text = ctrl.eleDoor[3].ToString();
            t33.Text = ctrl.eleMove[3].ToString();
            t34.Text = ctrl.floor[3].ToString();
            t41.Text = ctrl.eleEnabled[4].ToString();
            t42.Text = ctrl.eleDoor[4].ToString();
            t43.Text = ctrl.eleMove[4].ToString();
            t44.Text = ctrl.floor[4].ToString();
            #endregion
        }

        //点击报警按钮
        private void bwarnClick(object sender, EventArgs e)
        {
            Button warnButton = (Button)sender;
            string[] tmp = warnButton.Name.Split(); //获取报警按钮索引
            int index = Convert.ToInt32(tmp[0][1]) - 48;
            tinfo.Text += "第" + index.ToString() + "号电梯报警！已停用！\n";
            warnButton.BackColor = Color.Red;   //置红色
            warnButton.Enabled = false;         //禁用
            ctrl.eleEnabled[index] = false;     //此电梯不可调度
            switch (index)      //禁用所有楼层按钮
            {
                case 0:
                    b0open.Enabled = false;
                    b0close.Enabled = false;
                    b01.Enabled = false;
                    b02.Enabled = false;
                    b03.Enabled = false;
                    b04.Enabled = false;
                    b05.Enabled = false;
                    b06.Enabled = false;
                    b07.Enabled = false;
                    b08.Enabled = false;
                    b09.Enabled = false;
                    b010.Enabled = false;
                    b011.Enabled = false;
                    b012.Enabled = false;
                    b013.Enabled = false;
                    b014.Enabled = false;
                    b015.Enabled = false;
                    b016.Enabled = false;
                    b017.Enabled = false;
                    b018.Enabled = false;
                    b019.Enabled = false;
                    b020.Enabled = false;
                    break;
                case 1:
                    b1open.Enabled = false;
                    b1close.Enabled = false;
                    b11.Enabled = false;
                    b12.Enabled = false;
                    b13.Enabled = false;
                    b14.Enabled = false;
                    b15.Enabled = false;
                    b16.Enabled = false;
                    b17.Enabled = false;
                    b18.Enabled = false;
                    b19.Enabled = false;
                    b110.Enabled = false;
                    b111.Enabled = false;
                    b112.Enabled = false;
                    b113.Enabled = false;
                    b114.Enabled = false;
                    b115.Enabled = false;
                    b116.Enabled = false;
                    b117.Enabled = false;
                    b118.Enabled = false;
                    b119.Enabled = false;
                    b120.Enabled = false;
                    break;
                case 2:
                    b2open.Enabled = false;
                    b2close.Enabled = false;
                    b21.Enabled = false;
                    b22.Enabled = false;
                    b23.Enabled = false;
                    b24.Enabled = false;
                    b25.Enabled = false;
                    b26.Enabled = false;
                    b27.Enabled = false;
                    b28.Enabled = false;
                    b29.Enabled = false;
                    b210.Enabled = false;
                    b211.Enabled = false;
                    b212.Enabled = false;
                    b213.Enabled = false;
                    b214.Enabled = false;
                    b215.Enabled = false;
                    b216.Enabled = false;
                    b217.Enabled = false;
                    b218.Enabled = false;
                    b219.Enabled = false;
                    b220.Enabled = false;
                    break;
                case 3:
                    b3open.Enabled = false;
                    b3close.Enabled = false;
                    b31.Enabled = false;
                    b32.Enabled = false;
                    b33.Enabled = false;
                    b34.Enabled = false;
                    b35.Enabled = false;
                    b36.Enabled = false;
                    b37.Enabled = false;
                    b38.Enabled = false;
                    b39.Enabled = false;
                    b310.Enabled = false;
                    b311.Enabled = false;
                    b312.Enabled = false;
                    b313.Enabled = false;
                    b314.Enabled = false;
                    b315.Enabled = false;
                    b316.Enabled = false;
                    b317.Enabled = false;
                    b318.Enabled = false;
                    b319.Enabled = false;
                    b320.Enabled = false;
                    break;
                case 4:
                    b4open.Enabled = false;
                    b4close.Enabled = false;
                    b41.Enabled = false;
                    b42.Enabled = false;
                    b43.Enabled = false;
                    b44.Enabled = false;
                    b45.Enabled = false;
                    b46.Enabled = false;
                    b47.Enabled = false;
                    b48.Enabled = false;
                    b49.Enabled = false;
                    b410.Enabled = false;
                    b411.Enabled = false;
                    b412.Enabled = false;
                    b413.Enabled = false;
                    b414.Enabled = false;
                    b415.Enabled = false;
                    b416.Enabled = false;
                    b417.Enabled = false;
                    b418.Enabled = false;
                    b419.Enabled = false;
                    b420.Enabled = false;
                    break;
            }
            ctrl.request[index].Clear();        //清空禁用的请求队列
            ctrl.requestRev[index].Clear();     //清空禁用的不顺路请求队列
        }

        //点击按钮
        private void bClick(object sender, EventArgs e)
        {
            Button floorButton = (Button)sender;
            string[] tmp = floorButton.Name.Split();        //寻找按钮
            int index = Convert.ToInt32(tmp[0][1]) - 48;
            int floor = int.Parse(floorButton.Name.Substring(2));
            tinfo.Text += "第" + index.ToString() + "号电梯增加楼层" + floor.ToString() + "！\n";
            floorButton.Enabled = false;        //按下去禁用
            floorButton.BackColor = Color.Orange;       //置橙色
            ctrl.eleInside(index, floor, floorButton);      //处理楼层按钮请求
        }

        //外调度上下按钮点击
        private void bupdownClick(object sender, EventArgs e)
        {
            Button updownButton = (Button)sender;
            if (comboBox.SelectedIndex == -1)       //没选楼层
            {
                MessageBox.Show("未选择楼层！请选择您所在楼层！");
                return;
            }
            string tmp = updownButton.Name;         //确认上下行
            bool goUp = (tmp == "bup");
            int start = comboBox.SelectedIndex + 1;     //获取当前所在楼层
            tinfo.Text += start.ToString() + "层有人要" + (goUp ? "上" : "下") + "楼！\n";

            List<int> EnabledList = new List<int>();    //获取可调度电梯列表
            for(int i = 0; i < CNT; i++)
            {
                if (ctrl.eleEnabled[i])
                    EnabledList.Add(i);
            }

            List<int> dist = new List<int>();       //最短路径列表
            for(int i =0; i < CNT; i++)
                dist.Add(ctrl.INFINITE);
            foreach (int i in EnabledList)          //迭代器遍历可调度电梯列表
            {
                    if (ctrl.eleMove[i] == Ele.ELEMOVE.UP && goUp && start > ctrl.floor[i]) //调度向上顺路的电梯
                        dist[i] = start - ctrl.floor[i];
                    else if (ctrl.eleMove[i] == Ele.ELEMOVE.DOWN && !goUp && start < ctrl.floor[i]) //调度向下顺路的电梯
                        dist[i] = ctrl.floor[i] - start;
                    else if (ctrl.eleMove[i] == Ele.ELEMOVE.STILL)  //调度静止的电梯
                        dist[i] = abs(ctrl.floor[i] - start);
            }

            int bestIndex = dist.IndexOf(dist.Min());   //求最佳电梯索引
            MessageBox.Show("为您调度了#" + bestIndex.ToString() + "号电梯！");

            if (dist[bestIndex] == 0)       //所在楼层有电梯停靠
            {
                ctrl.eleDoor[bestIndex] = Ele.ELEDOOR.OPEN;     //打开门
            }
            else
            {
                ctrl.request[bestIndex].Add(start);     //调度
                setButton(bestIndex, start, false, 2);  //按钮设置特殊颜色（浅蓝色）
            }
        }

        //绝对值方法
        private int abs(int x)
        {
            if (x > 0)
                return x;
            else
                return -x;
        }

        //开关门按钮点击
        private void bopencloseClick(object sender, EventArgs e)
        {
            Button opencloseButton = (Button)sender;
            string[] tmp = opencloseButton.Name.Split();        //找到开关门电梯的索引
            int index = Convert.ToInt32(tmp[0][1]) - 48;
            bool oc = (tmp[0][2] == 'o');
            tinfo.Text += "第" + index.ToString() + "号电梯请求" + (oc?"开":"关") + "门！\n";
            ctrl.eleOpenCloseDoor(index, oc);       //检查能否开关门
        }

        //设置按钮
        public void setButton(int index, int flr, bool e, int color = 0/*0白1橙2蓝3红4绿*/)
        {
            string s = "b" + index.ToString() + flr.ToString();
            Control[] myfindcs = this.Controls.Find(s, true);       //查找按钮
            if (myfindcs.Length > 0)
            {
                //找到控件
                myfindcs.First().Enabled = e;
                switch(color)
                {
                    case 0:
                        myfindcs.First().BackColor = Color.White;
                        break;
                    case 1:
                        myfindcs.First().BackColor = Color.Orange;
                        break;
                    case 2:
                        myfindcs.First().BackColor = Color.LightBlue;
                        break;
                    case 3:
                        myfindcs.First().BackColor = Color.Red;
                        break;
                    case 4:
                        myfindcs.First().BackColor= Color.LightGreen;
                        break;
                }
            }
        }
    }
}