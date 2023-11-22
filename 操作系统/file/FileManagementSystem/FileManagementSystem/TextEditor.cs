using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static FileManagementSystem.FileCreator;

namespace FileManagementSystem
{
    public partial class TextEditor : Form
    {
        private BitMap bitmap;  //位图
        public File txtFile;    //文本文件
        public DelegateMethod.delegateFunction CallBack;    //回调函数

        //构造函数
        public TextEditor()
        {
            InitializeComponent();
        }

        //构造函数重载
        public TextEditor(ref BitMap bitMap, ref File file)
        {
            InitializeComponent();
            bitmap = bitMap;    //位图
            txtFile = file;     //文本文件
            showContent();      //显示内容
        }

        //显示内容
        public void showContent()
        {
            //从文件类调用读取内容方法
            richTextBox1.Text = txtFile.getFileContent();
        }

        //回调
        private void callBack()
        {
            if (CallBack != null)
                this.CallBack();
        }

        //点击保存按钮事件
        private void button1_Click(object sender, EventArgs e)
        {
            //弹窗选择是
            if (MessageBox.Show("保存更改？", "提示信息", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                //写文本
                txtFile.writeFile(richTextBox1.Text, ref bitmap);
                //更新修改时间
                txtFile.updatedTime = DateTime.Now;
            }
            callBack(); //回调
            this.Close();
        }

        //点击取消按钮事件
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
