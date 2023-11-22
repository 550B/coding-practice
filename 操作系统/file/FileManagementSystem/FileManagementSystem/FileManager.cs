using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Collections.ObjectModel;
using System.Runtime.Serialization.Formatters.Binary;
using System.Linq.Expressions;
using System.Data.Common;

namespace FileManagementSystem
{
    public partial class FileManager : Form
    {
        public TreeNode rootNode;   //根节点
        public BitMap bitmap = new BitMap();    //位图
        public Catalog rootCatalog = new Catalog("root");   //根目录
        public Catalog currentCatalog;  //当前目录
        private List<ListViewItem> listViewItems = new List<ListViewItem>();//界面
        public string dir = Application.StartupPath;    //起始路径

        //构造函数
        public FileManager()
        {
            InitializeComponent();  //初始化控件
            FileStream f1, f2;      //文件流
            //检查是否存在路径，不存在就创建
            if (!System.IO.Directory.Exists(System.IO.Path.Combine(@dir, "storage")))
                System.IO.Directory.CreateDirectory(System.IO.Path.Combine(@dir, "storage"));
            BinaryFormatter bf = new BinaryFormatter(); //二进制格式
            //检查在根目录里是否存在相应文件
            if (System.IO.File.Exists(System.IO.Path.Combine(dir, "storage/rootCatalog.txt")) && System.IO.File.Exists(System.IO.Path.Combine(dir, "storage/bitMap.txt")))
            {
                //赋值文件流属性
                f1 = new FileStream(System.IO.Path.Combine(dir, "storage/rootCatalog.txt"), FileMode.Open, FileAccess.Read, FileShare.Read);
                //二进制反序列流负责从磁盘读取文件到内存，as检查强制类型转换合法性
                rootCatalog = bf.Deserialize(f1) as Catalog;
                f1.Close(); //用完记得关闭

                //对f2执行相同操作，类型变为位图
                f2 = new FileStream(System.IO.Path.Combine(dir, "storage/bitMap.txt"), FileMode.Open, FileAccess.Read, FileShare.Read);
                bitmap = bf.Deserialize(f2) as BitMap;
                f2.Close();
            }
            //根目录为当前目录
            currentCatalog = rootCatalog;
            //界面显示路径
            textBox1.Text = trimPath(currentCatalog.path);
            //更新文件目录
            updateTreeView();
            //更新视图目录
            updateListView();
        }

        //关闭窗口事件
        private void FileManager_FormClosing(object sender, FormClosingEventArgs e)
        {
            FileStream f1, f2;  //声明两个新的文件流
            BinaryFormatter bf = new BinaryFormatter();
            //负责创建流文件
            f1 = new FileStream(System.IO.Path.Combine(dir, "storage/rootCatalog.txt"), FileMode.Create);
            bf.Serialize(f1, rootCatalog);  //负责写入文件
            f1.Close();
            //同样操作对应位图
            f2 = new FileStream(System.IO.Path.Combine(dir, "storage/bitMap.txt"), FileMode.Create);
            bf.Serialize(f2, bitmap);
            f2.Close();
        }

        //裁剪路径信息
        public string trimPath(string path)
        {
            string trimedPath = path;
            if (path.Length > 6)    //正常路径
            {
                //根目录
                string root = path.Substring(0, 5);
                //子目录
                string detail = path.Substring(5);
                //拼接
                trimedPath = root + detail;
            }
            return trimedPath;  //返回裁剪后的路径
        }

        //更新视图
        public void updateView()
        {
            updateTreeView();   //更新文件目录
            updateListView();   //更新视图目录
            //展示路径
            textBox1.Text = trimPath(currentCatalog.path);
        }

        //更新文件目录
        public void updateTreeView()
        {
            treeView1.Nodes.Clear();    //清空当前目录节点
            rootNode = new TreeNode("root");    //分配根节点
            addTreeNode(rootNode, rootCatalog); //添加节点和目录
            treeView1.Nodes.Add(rootNode);      //添加根节点
            rootNode.ExpandAll();   //展开所有
        }

        //更新视图目录
        public void updateListView()
        {
            //新建列表
            listViewItems = new List<ListViewItem>();
            listView1.Items.Clear();
            //当前目录不为空
            if (currentCatalog.nodelist != null)
            {
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    ListViewItem file;  //列表项
                    if (currentCatalog.nodelist[i].nodeType == Node.NodeType.file)
                    {
                        //文件类型的显示
                        file = new ListViewItem(new string[] { currentCatalog.nodelist[i].file.name + ".txt", currentCatalog.nodelist[i].file.updatedTime.ToString(), "文本文件", currentCatalog.nodelist[i].file.size.ToString() + "B" });
                        file.ImageIndex = 0;
                    }
                    else
                    {
                        //文件夹类型的显示
                        file = new ListViewItem(new string[] { currentCatalog.nodelist[i].folder.name, currentCatalog.nodelist[i].folder.updatedTime.ToString(), "文件夹", "-" });
                        file.ImageIndex = 1;
                    }
                    listViewItems.Add(file);    //添加到列表
                    listView1.Items.Add(file);  //添加到列表项
                }
            }
            //统计数目
            textBox2.Text = "  " + listView1.Items.Count.ToString() + "个项目";
        }

        //递归增加子节点
        public void addTreeNode(TreeNode node, Catalog dir)
        {
            if (dir.nodelist != null)   //路径下结点数不为0
            {
                //遍历
                for (int i = 0; i < dir.nodelist.Count(); i++)
                {
                    //递归进入文件夹
                    if (dir.nodelist[i].nodeType == Node.NodeType.folder)
                    {
                        TreeNode newNode = new TreeNode(dir.nodelist[i].name);
                        //递归进入子目录
                        addTreeNode(newNode, dir.nodelist[i].folder);
                        //添加节点
                        node.Nodes.Add(newNode);
                    }
                }
            }
        }

        //视图项双击
        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            //新视图项
            ListViewItem item = new ListViewItem();
            //不为空
            if (listView1.SelectedItems.Count != 0)
            {
                item = listView1.SelectedItems[0];  //第一个
                //所有项
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //匹配
                    if (listViewItems[i] == item)
                    {
                        Node currentNode = currentCatalog.nodelist[i];
                        //打开文件或文件夹
                        openListViewItem(ref currentNode);
                        break;
                    }
                }
            }
        }

        //打开节点下视图
        private void openListViewItem(ref Node node)
        {
            //节点是文件夹类型
            if (node.nodeType == Node.NodeType.folder)
            {
                //当前目录为节点文件夹
                currentCatalog = node.folder;
                //显示当前路径
                textBox1.Text = trimPath(currentCatalog.path);
                updateListView();
            }
            else
            {
                //文本编辑
                TextEditor txtEditor = new TextEditor(ref bitmap, ref node.file);
                //向用户显示控件
                txtEditor.Show();
                //回调
                txtEditor.CallBack = updateView;
            }
        }

        //检测重名
        private string nameCheck(string name, string type)
        {
            int counter = 0;    //重名的文件数量
            if (type == "")
            {
                //遍历所有文件夹类型
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //文件夹类型
                    if (currentCatalog.nodelist[i].nodeType == Node.NodeType.folder)
                    {
                        //分开
                        string[] sArray = currentCatalog.nodelist[i].folder.name.Split('(');
                        if (sArray[0] == name)
                            counter++;  //数量增加
                    }
                }
            }
            else
            {
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //文本文件类型
                    if (currentCatalog.nodelist[i].nodeType == Node.NodeType.file)
                    {
                        string[] sArray = currentCatalog.nodelist[i].file.name.Split('(');
                        if (sArray[0] == name)
                            counter++;
                    }
                }
            }
            //有重名
            if (counter > 0)
                name += "(" + counter.ToString() + ")"; //添加数量
            return name;
        }

        //返回按钮
        private void returnToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //没到达根节点
            if (currentCatalog != rootCatalog)
            {
                //当前节点变为父节点
                currentCatalog = currentCatalog.parentCatalog;
                updateView();   //更新视图
            }
        }

        //打开按钮
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //新列表项
            ListViewItem item = new ListViewItem();
            //列表项不为空
            if (listView1.SelectedItems.Count != 0)
            {
                //选取头部
                item = listView1.SelectedItems[0];
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //匹配
                    if (listViewItems[i] == item)
                    {
                        Node currentNode = currentCatalog.nodelist[i];
                        //打开
                        openListViewItem(ref currentNode);
                        //更新大小
                        updateFolderSize(ref currentCatalog);
                        break;
                    }
                }
            }
        }

        //更新文件夹大小
        private void updateFolderSize(ref Catalog currentCatalog)
        {
            currentCatalog.fileSize = 0;
            //遍历
            for (int j = 0; j < currentCatalog.nodelist.Count(); j++)
            {
                //给文件夹和文件重新计算大小
                if (currentCatalog.nodelist[j].nodeType == Node.NodeType.file)
                {
                    currentCatalog.fileSize += currentCatalog.nodelist[j].file.size;
                }
                else
                {
                    currentCatalog.fileSize += currentCatalog.nodelist[j].folder.fileSize;
                }
            }
        }

        //新建文本文件
        private void fileToolStripMenuItem2_Click(object sender, EventArgs e)
        {
            string fileName = "新建文本文档";
            string fileType = "txt";
            fileName = nameCheck(fileName, fileType);   //默认文件名
            FileCreator.operationType otype = FileCreator.operationType.newfile;    //操作是新建文件
            //文件创建器
            FileCreator newfile = new FileCreator(ref currentCatalog, fileName, fileType, otype);
            newfile.Show(); //向用户显示控件
            newfile.CallBack = updateView;  //回调
        }

        //新建文件夹
        private void folderToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            string fileName = "新建文件夹";
            string fileType = "";
            fileName = nameCheck(fileName, fileType);
            FileCreator.operationType otype = FileCreator.operationType.newfile;
            FileCreator newfile = new FileCreator(ref currentCatalog, fileName, fileType, otype);
            newfile.Show();
            newfile.CallBack = updateView;
        }

        //重命名
        private void renameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ListViewItem currentItem = new ListViewItem();
            string fileType = "txt";
            if (listView1.SelectedItems.Count != 0)
            {
                //选取第一项
                currentItem = listView1.SelectedItems[0];
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //匹配
                    if (listViewItems[i] == currentItem)
                    {
                        //文件夹
                        if (currentCatalog.nodelist[i].nodeType == Node.NodeType.folder)
                            fileType = "";
                        //操作为重命名
                        FileCreator.operationType op = FileCreator.operationType.rename;
                        //改好名字的文件夹
                        FileCreator newfile = new FileCreator(ref currentCatalog, currentCatalog.nodelist[i].name, fileType, op);
                        newfile.Show(); //向用户显示控件
                        newfile.CallBack = updateView;  //回调
                        break;
                    }
                }
            }
        }

        //删除
        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ListViewItem item = new ListViewItem();
            //不空
            if (listView1.SelectedItems.Count != 0)
            {
                //选取第一个
                item = listView1.SelectedItems[0];
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count();i++)
                {
                    //匹配
                    if (listViewItems[i] == item)
                    {
                        //更新修改时间
                        currentCatalog.updatedTime = DateTime.Now;
                        //执行删除操作
                        delete(ref currentCatalog.nodelist, i);
                        //重算大小
                        updateFolderSize(ref currentCatalog);
                        //更新视图
                        updateView();
                        break;
                    }
                }
            }
        }

        //删除操作
        public void delete(ref List<Node> nodelist, int i)
        {
            //不空
            if (nodelist.Count() > 0)
            {
                //删文件
                if (nodelist[i].nodeType == Node.NodeType.file)
                {
                    //位图清空
                    nodelist[i].file.setEmpty(ref bitmap);
                    //移除节点
                    nodelist.RemoveAt(i);
                }
                else if (nodelist[i].nodeType == Node.NodeType.folder)  //删文件夹
                {
                    //不空
                    if (nodelist[i].folder.nodelist != null)
                    {
                        //遍历
                        for (int j = 0; j < nodelist[i].folder.nodelist.Count(); j++)
                        {
                            //删除
                            delete(ref nodelist[i].folder.nodelist, j);
                        }
                        //移除节点
                        nodelist.RemoveAt(i);
                    }
                    else
                    {
                        //直接移除空文件夹节点
                        nodelist.RemoveAt(i);
                    }
                }
            }
            return;
        }

        //格式化
        private void formatToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //删除
            delete(ref currentCatalog.nodelist, 0);
            //根目录下节点不空
            if (rootCatalog.nodelist.Count() != 0)
            {
                //遍历
                for (int i = 0; i < rootCatalog.nodelist.Count(); i++)
                {
                    //删除
                    delete(ref rootCatalog.nodelist, i);
                }
            }
            //建立新的根节点
            rootCatalog = new Catalog("root");
            //当前为根节点
            currentCatalog = rootCatalog;
            //更新视图
            updateView();
        }

        //属性
        private void attToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //列表不空
            if (listView1.SelectedItems.Count != 0)
            {
                ListViewItem item = new ListViewItem();
                item = listView1.SelectedItems[0];
                //遍历
                for (int i = 0; i < currentCatalog.nodelist.Count(); i++)
                {
                    //匹配
                    if (listViewItems[i] == item)
                    {
                        //属性类
                        FileAttributes attributes = new FileAttributes(currentCatalog.nodelist[i]);
                        //向用户显示控件
                        attributes.Show();
                    }
                }
            }
            else
            {
                if (currentCatalog.parentCatalog != null)
                {
                    //父节点
                    for (int i = 0; i < currentCatalog.parentCatalog.nodelist.Count(); i++)
                    {
                        if (currentCatalog.parentCatalog.nodelist[i].name == currentCatalog.name)
                        {
                            FileAttributes attributes = new FileAttributes(currentCatalog.parentCatalog.nodelist[i]);
                            attributes.Show();
                        }
                    }
                }
                else
                {
                    MessageBox.Show("根目录");
                }
            }
        }

        //刷新
        private void refreshToolStripMenuItem_Click(object sender, EventArgs e)
        {
            updateView();   //更新视图
        }
    }

    [Serializable]
    public class BitMap     //位图
    {
        public const int BYTE_SIZE = 8;     //字节大小
        public const int MAX_CAPACITY = 100 * 100;  //最大容量
        public const int BYTE_CNT = 100 * 100 / 8;  //字节数
        public Block[] blocks = new Block[MAX_CAPACITY];    //块
        public bool[] bitMap = new bool[MAX_CAPACITY];  //位图

        //构造函数
        public BitMap()
        {
            for(int i = 0; i < MAX_CAPACITY; i++)
            {
                bitMap[i] = true;   //初始化位图为全部空闲
            }
        }

        //寻找空闲块
        public int findFreeBlock()
        {
            int bytePos = 0;    //字节位置
            int bitPos = 0;     //二进制位位置
            while (bytePos < BYTE_CNT)
            {
                if (bitMap[bytePos * BYTE_SIZE + bitPos])
                {
                    return (bytePos * BYTE_SIZE + bitPos);  //返回空闲位置
                }
                else
                {
                    bitPos++;   //向后一位
                    if (bitPos == BYTE_SIZE)    //凑满1字节
                    {
                        bitPos = 0;     //二进制位归零
                        bytePos++;      //字节位置后移1
                    }
                }
            }
            return -1;
        }

        //置空闲
        public void setFree(int i)
        {
            bitMap[i] = true;
        }

        //置占用
        public void setOccupy(int i)
        {
            bitMap[i] = false;
        }
    }

    [Serializable]
    public class Block      //块
    {
        public const int BLOCK_SIZE = 512;  //块大小
        public char[] data;     //数据
        public int len;     //数据长度

        //构造函数
        public Block()
        {
            data = new char[BLOCK_SIZE];    //分配块大小的数据
        }

        //设置数据
        public void setData(string newData)
        {
            //数据长度的判断
            len = (newData.Length > BLOCK_SIZE) ? BLOCK_SIZE : newData.Length;
            for(int i = 0; i < len; i++)
            {
                data[i] = newData[i];   //设置数据
            }
        }

        //读取数据
        public string getData()
        {
            string tmp = new string(data);
            return tmp;     //返回当前块的数据
        }
    }

    [Serializable]
    public class Catalog    //目录
    {
        public List<Node> nodelist; //节点表
        public int childrenCnt;     //子节点数目
        public string name;         //文件名
        public string path;         //文件路径
        public int fileSize;        //文件大小
        public DateTime createdTime;//创建时间
        public DateTime updatedTime;//更新时间
        public Catalog parentCatalog = null;    //父节点是空

        //构造函数
        public Catalog(string nameData, string fatherPath)
        {
            nodelist = new List<Node>();    //节点列表
            childrenCnt = 0;        //子节点数目
            name = nameData;        //文件名
            path = fatherPath + "\\" + nameData;    //路径
            fileSize = 0;       //文件大小
            createdTime = DateTime.Now; //创建时间
            updatedTime = DateTime.Now; //更新时间
        }

        //构造函数重载（文件夹）
        public Catalog(string nameData)
        {
            nodelist = new List<Node>();
            name = nameData;
            path = nameData + ":";
            createdTime= DateTime.Now;
            updatedTime= DateTime.Now;
            fileSize = 0;
            childrenCnt = 0;
        }

        //添加节点
        public void addNode(Catalog catalog, string nameData, string fatherPath)
        {
            Node node = new Node(nameData, fatherPath); //新的节点
            node.folder.parentCatalog = catalog;    //当前目录变成父目录
            nodelist.Add(node);     //添加节点
            childrenCnt++;      //子节点数量加1
            updatedTime = DateTime.Now; //更新更新时间
        }

        //添加节点重载函数（文件形式）
        public void addNode(string nameData, string fileType, string fatherPath)
        {
            Node node = new Node(nameData, fileType, fatherPath);
            nodelist.Add(node);
            childrenCnt ++;
            updatedTime = DateTime.Now;
        }
    }

    [Serializable]
    public class Node   //节点
    {
        public enum NodeType { folder, file};   //节点类型
        public NodeType nodeType;   //声明
        public File file;   //文件
        public Catalog folder;  //文件夹
        public string name;     //文件名
        public string path;     //文件路径

        //文件夹节点构造函数
        public Node(string nameData, string fatherPath)
        {
            nodeType = NodeType.folder; //说明文件夹类型
            path = fatherPath + "\\" + nameData;    //路径
            name = nameData;    //文件夹名称
            folder = new Catalog(nameData, fatherPath); //文件夹目录
        }

        //文件节点构造函数
        public Node(string nameData, string fileType, string fatherPath)
        {
            nodeType = NodeType.file;   //说明文件类型
            path = fatherPath + "\\" + nameData;    //路径
            name = nameData;        //文件名称
            file = new File(name, fileType, fatherPath);    //文件目录
        }

        //重命名
        public void rename(string newName)
        {
            name = newName; //新名字
            if (nodeType == Node.NodeType.folder)
            {
                //更换路径为新的文件夹名
                folder.path = folder.path.Remove(folder.path.Length - folder.name.Length - 1, folder.name.Length + 1);
                folder.name = newName;  //文件夹名为新名字
                folder.path = folder.path + "\\" + newName; //新路径
            }
            else
            {
                //相同操作对文件操作
                file.path = file.path.Remove(file.path.Length - file.name.Length - 1, file.name.Length + 1);
                file.name = newName;
                file.path = file.path + "\\" + file.name;
            }
        }
    }

    [Serializable]
    public class File   //文件
    {
        public const int TXT = 0;   //代表文本的常数
        public int type;    //类型
        public int size;    //大小
        public string name; //文件名
        public DateTime createdTime;    //创建时间
        public DateTime updatedTime;    //修改时间
        public List<Block> blocklist;   //文件指针
        public string path; //路径

        //构造函数
        public File(string name, string type, string fatherPath)
        {
            this.type = TXT;    //文本文件
            this.name = name;   //文件名
            createdTime = DateTime.Now; //更新创建时间
            updatedTime = DateTime.Now; //更新修改时间
            size = 0;   //文件大小
            blocklist = new List<Block>();  //实例化文件指针
            path = fatherPath + "\\" + name;    //路径
        }

        //清空数据
        public void setEmpty(ref BitMap bitmap)
        {
            //对每个指针
            for (int i = 0; i < blocklist.Count(); i++)
            {
                //释放位图里可以释放的
                bitmap.setFree(bitmap.findFreeBlock());
            }
            blocklist.Clear();  //清空指针
            size = 0;   //文件大小为0
        }

        //写文件
        public void writeFile(string data, ref BitMap bitmap)
        {
            setEmpty(ref bitmap);   //清空位图
            while (data.Count() > 512)  //分配完整块
            {
                //在空闲位置分配一个块
                bitmap.blocks[bitmap.findFreeBlock()] = new Block();
                //设置字符串块大小的字符
                bitmap.blocks[bitmap.findFreeBlock()].setData(data.Substring(0, 512));
                //添加指针
                blocklist.Add(bitmap.blocks[bitmap.findFreeBlock()]);
                bitmap.setOccupy(bitmap.findFreeBlock());   //设置已经占用
                size += 512;    //大小增加512
                data = data.Remove(0, 512); //移除已经写入的字符
            }
            //分配不完整的部分
            bitmap.blocks[bitmap.findFreeBlock()] = new Block();
            bitmap.blocks[bitmap.findFreeBlock()].setData(data);
            blocklist.Add(bitmap.blocks[bitmap.findFreeBlock()]);
            bitmap.setOccupy(bitmap.findFreeBlock());
            size += data.Length;
            updatedTime = DateTime.Now; //写完再更新修改时间
        }

        //读取文本内容
        public string getFileContent()
        {
            string content = "";    //一开始是空着的
            for (int i = 0; i < blocklist.Count(); i++)
            {
                //跟着指针读数据
                content += blocklist[i].getData();
            }
            return content;
        }
    }
}
