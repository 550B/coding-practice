using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FileManagementSystem
{
    public partial class FileAttributes : Form
    {
        //构造函数
        public FileAttributes(Node node)
        {
            InitializeComponent();
            if (node.nodeType == Node.NodeType.file)
            {
                this.pictureBox1.Image = this.imageList1.Images[0];
                this.textBox1.Text = node.file.name + ".txt";
                this.textBox2.Text = "文本文件";
                this.textBox3.Text = node.file.path.Substring(0, node.file.path.Length - node.file.name.Length);
                this.textBox4.Text = node.file.size.ToString() + " B";
                this.textBox5.Text = node.file.createdTime.ToString();
                this.textBox6.Text = node.file.updatedTime.ToString();
                this.label3.Text = "大小";
            }
            else
            {
                this.pictureBox1.Image = this.imageList1.Images[1];
                this.textBox1.Text = node.folder.name;
                this.textBox2.Text = "文件夹";
                this.textBox3.Text = node.folder.path.Substring(0, node.folder.path.Length - node.folder.name.Length);
                this.textBox4.Text = node.folder.childrenCnt.ToString() + "个子项";
                this.textBox5.Text = node.folder.createdTime.ToString();
                this.textBox6.Text = node.folder.updatedTime.ToString();
                this.label3.Text = "包含";
            }
        }

        //按钮
        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
