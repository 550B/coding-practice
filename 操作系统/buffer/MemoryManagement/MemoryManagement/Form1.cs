using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            title.Text = "欢迎来到操作系统动态分区分配方式模拟程序！\n作者：赵明泽2151974";
            InitializeMemory();
        }
        private const int TotalMemorySize = 640;        //假设初始态下，可用内存空间为640K
        private List<MemoryBlock> memoryBlocks;         //内存块列表

        private void InitializeMemory()                 //初始化内存块
        {
            memoryBlocks = new List<MemoryBlock>
            {
                new MemoryBlock(0, TotalMemorySize, true)
            };

            UpdateMemoryView();
        }

        //申请内存空间
        private void AllocateMemory(int processId, int size, string algorithm)
        {
            MemoryBlock allocatedBlock = null;
            switch (algorithm)          //选择算法
            {
                case "First Fit":       //首次适应算法
                    allocatedBlock = AllocateFirstFit(processId, size);
                    break;
                case "Best Fit":        //最佳适应算法
                    allocatedBlock = AllocateBestFit(processId, size);
                    break;
                default:                //没选择算法
                    MessageBox.Show("请选择算法！");
                    return;
            }

            if (allocatedBlock != null)
            {
                MessageBox.Show($"从 {allocatedBlock.Start} 开始的 {allocatedBlock.Size} KB内存中，成功为作业 {processId} 申请到内存空间！");
            }
            else
            {
                MessageBox.Show($"为作业 {processId} 申请内存空间失败！");
            }

            UpdateMemoryView();
        }

        //为首次适应算法分配内存空间
        private MemoryBlock AllocateFirstFit(int processId, int size)
        {
            foreach (var block in memoryBlocks)
            {
                if (block.IsFree && block.Size >= size)
                {
                    return AllocateBlock(block, processId, size);
                }
            }

            return null;
        }

        //为最佳适应算法分配内存空间
        private MemoryBlock AllocateBestFit(int processId, int size)
        {
            MemoryBlock bestFitBlock = null;
            int bestFitDifference = int.MaxValue;       //赋极大值

            foreach (var block in memoryBlocks)
            {
                if (block.IsFree && block.Size >= size)     //寻找最佳的内存块
                {
                    int difference = block.Size - size;
                    if (difference < bestFitDifference)
                    {
                        bestFitBlock = block;
                        bestFitDifference = difference;
                    }
                }
            }

            if (bestFitBlock != null)       //找到了
            {
                return AllocateBlock(bestFitBlock, processId, size);
            }

            return null;
        }

        //分配内存块
        private MemoryBlock AllocateBlock(MemoryBlock block, int processId, int size)
        {
            if (block.Size == size)
            {
                block.ProcessId = processId;
                block.IsFree = false;
            }
            else
            {
                var newBlock = new MemoryBlock(block.Start, size, processId);
                var remainingBlock = new MemoryBlock(block.Start + size, block.Size - size, true);
                memoryBlocks.Insert(memoryBlocks.IndexOf(block) + 1, newBlock);
                memoryBlocks.Insert(memoryBlocks.IndexOf(block) + 2, remainingBlock);
                memoryBlocks.Remove(block);
            }

            return block;
        }

        //释放内存块
        private void DeallocateMemory(int processId)
        {
            bool deallocated = false;

            foreach (var block in memoryBlocks)
            {
                if (block.ProcessId == processId)
                {
                    block.ProcessId = -1;
                    block.IsFree = true;
                    MergeAdjacentFreeBlocks();
                    deallocated = true;
                    break;
                }
            }

            if (deallocated)
            {
                MessageBox.Show($"释放作业号 {processId} 的内存成功！");
            }
            else
            {
                MessageBox.Show($"作业号为 {processId} 的作业还没有申请内存！");
            }

            UpdateMemoryView();
        }

        //合并空闲空间
        private void MergeAdjacentFreeBlocks()
        {
            for (int i = 0; i < memoryBlocks.Count - 1; i++)
            {
                if (memoryBlocks[i].IsFree && memoryBlocks[i + 1].IsFree)
                {
                    memoryBlocks[i].Size += memoryBlocks[i + 1].Size;
                    memoryBlocks.RemoveAt(i + 1);
                    i--;
                }
            }
        }

        //更新内存分配情况图
        private void UpdateMemoryView()
        {
            info.Clear();

            foreach (var block in memoryBlocks)
            {
                if (block.IsFree)
                {
                    info.Text += "存在" + block.Size.ToString() + "KB空闲的内存！\n";
                }
                else if (block.ProcessId != -1)
                {
                    info.Text += block.ProcessId.ToString() + "号作业占用从" + block.Start.ToString() + "开始的" + block.Size.ToString() + "KB内存！\n";
                }
            }

            panel.Controls.Clear(); // 清空所有控件
            panellabel.Controls.Clear();

            int panelWidth = panel.Width;
            int panelHeight = panel.Height;
            int blockCount = memoryBlocks.Count;

            for (int i = 0; i < blockCount; i++)
            {
                MemoryBlock block = memoryBlocks[i];
                int blockX = block.Start;
                int blockWidth = block.Size;        // 计算每个内存块的宽度

                // 创建内存块矩形框
                Panel blockPanel = new Panel();
                blockPanel.BackColor = (block.ProcessId != -1) ? Color.Yellow : Color.LightGray;
                blockPanel.BorderStyle = BorderStyle.FixedSingle;
                blockPanel.Location = new Point(blockX, 0);
                blockPanel.Size = new Size(blockWidth, panelHeight);

                // 创建内存块开始标记
                Label startLabel = new Label();
                startLabel.Text = (block.Start).ToString();
                startLabel.Font = new Font(FontFamily.GenericSansSerif, 8, FontStyle.Bold);
                startLabel.Location = new Point(blockX, 10);
                startLabel.Size = new Size(40, 15);

                // 将控件添加到面板中
                panel.Controls.Add(blockPanel);
                panellabel.Controls.Add(startLabel);
            }
        }

        public string algorithm;

        //点击申请按钮
        private void allocateButton_Click(object sender, EventArgs e)
        {
            int processId = int.Parse(processIdTextBox.Text);
            int size = int.Parse(sizeTextBox.Text);
            AllocateMemory(processId, size, algorithm);
        }

        //点击释放按钮
        //释放按钮只需要作业号就能释放，不需要输入释放空间大小
        private void deallocateButton_Click(object sender, EventArgs e)
        {
            int processId = int.Parse(processIdTextBox.Text);
            DeallocateMemory(processId);
        }

        //数字框数字与拖动条数字同步
        private void updateTrackBarValue(object sender, EventArgs e)
        {
            sizeTextBox.Value = trackBar.Value;
        }

        //选择算法
        private void algoChoose(object sender, EventArgs e)
        {
            RadioButton radioButton = (RadioButton)sender;
            switch(radioButton.Name)
            {
                case "algo1":
                    algorithm = "First Fit";
                    break;
                case "algo2":
                    algorithm = "Best Fit";
                    break;
            }
        }
    }

    //内存块数据结构
    public class MemoryBlock
    {
        public int Start { get; set; }
        public int Size { get; set; }
        public int ProcessId { get; set; }
        public bool IsFree { get; set; }

        public MemoryBlock(int start, int size, bool isFree)
        {
            Start = start;
            Size = size;
            ProcessId = -1;
            IsFree = isFree;
        }

        public MemoryBlock(int start, int size, int processId)
        {
            Start = start;
            Size = size;
            ProcessId = processId;
            IsFree = false;
        }
    }
}
