using System;
using System.Windows.Forms;

namespace FileManagementSystem
{
    public partial class FileCreator : Form
    {
        public Catalog currentCatalog;  //当前目录
        string fileName;    //文件名
        string fileType;    //文件类型
        public enum operationType { newfile, rename };  //操作类型，新建或重命名
        public operationType operation_type;            //实例化
        public DelegateMethod.delegateFunction CallBack;//回调函数

        //构造函数
        public FileCreator(ref Catalog currentCatalog, string name, string type, operationType otype)
        {
            InitializeComponent();  //初始化控件
            this.currentCatalog = currentCatalog;
            this.fileName = name;
            this.fileType = type;
            this.operation_type = otype;
            textBox1.Text = name;   //显示名称
        }

        //回调函数
        private void callBack()
        {
            if (CallBack != null)
            {
                if (currentCatalog.parentCatalog != null)
                {
                    //更新修改时间
                    currentCatalog.parentCatalog.updatedTime = DateTime.Now;
                }
                this.CallBack();
            }
        }

        //检测重名
        private string nameCheck(string name, string type)
        {
            int counter = 0;    //重名数量
            if (type == "")     //文件夹类型
            {
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count; i++)
                {
                    //找到文件夹
                    if (currentCatalog.nodelist[i].nodeType == Node.NodeType.folder)
                    {
                        //分割名称字符串
                        string[] sArray = currentCatalog.nodelist[i].folder.name.Split('(');
                        if (sArray[0] == name)  //前半部分相同
                        {
                            counter++;  //数量统计
                        }
                    }
                }
            }
            else
            {
                //文件类型
                for (int i = 0; i < currentCatalog.nodelist.Count; i++)
                {
                    if (currentCatalog.nodelist[i].nodeType == Node.NodeType.file)
                    {
                        //相同操作
                        string[] sArray = currentCatalog.nodelist[i].file.name.Split('(');
                        if (sArray[0] == name)
                        {
                            counter++;
                        }
                    }
                }
            }
            //有重名
            if (counter > 0)
                name += "(" + counter.ToString() + ")"; //添加尾标
            return name;
        }

        //点击按钮
        private void button1_Click(object sender, EventArgs e)
        {
            string fatherPath = currentCatalog.path;    //当前路径是父路径
            textBox1.Text = nameCheck(textBox1.Text, fileType); //检查一下
            if (operation_type == operationType.newfile)    //新建文件
            {
                if (fileType == "")
                {
                    //文件夹类型
                    currentCatalog.addNode(currentCatalog, textBox1.Text, fatherPath);
                }
                else
                {
                    //文件类型
                    currentCatalog.addNode(textBox1.Text, fileType, fatherPath);
                }
            }
            else if (operation_type == operationType.rename)
            {
                //重命名
                if (fileType == "")
                {
                    //遍历
                    for (int i = 0; i < currentCatalog.nodelist.Count; i++)
                    {
                        //找到当前文件夹
                        if (currentCatalog.nodelist[i].name == fileName && currentCatalog.nodelist[i].nodeType == Node.NodeType.folder)
                        {
                            //重命名后退出
                            currentCatalog.nodelist[i].rename(textBox1.Text);
                            break;
                        }
                    }
                }
                else if (fileType == "txt")
                {
                    //对文件进行相同操作
                    for (int i = 0; i < currentCatalog.nodelist.Count; i++)
                    {
                        if (currentCatalog.nodelist[i].name == fileName && currentCatalog.nodelist[i].nodeType == Node.NodeType.file)
                        {
                            currentCatalog.nodelist[i].rename(textBox1.Text);
                            break;
                        }
                    }
                }
            }
            callBack(); //回调
            this.Close();
        }

        //委托方法
        public class DelegateMethod
        {
            public delegate void delegateFunction();
        }

        //取消按钮
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
