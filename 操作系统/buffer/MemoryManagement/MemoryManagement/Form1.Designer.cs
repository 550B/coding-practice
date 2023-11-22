namespace test
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.id = new System.Windows.Forms.Label();
            this.size = new System.Windows.Forms.Label();
            this.algo = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.panel = new System.Windows.Forms.Panel();
            this.panellabel = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.processIdTextBox = new System.Windows.Forms.NumericUpDown();
            this.sizeTextBox = new System.Windows.Forms.NumericUpDown();
            this.trackBar = new System.Windows.Forms.TrackBar();
            this.algo1 = new System.Windows.Forms.RadioButton();
            this.algo2 = new System.Windows.Forms.RadioButton();
            this.info = new System.Windows.Forms.RichTextBox();
            this.title = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.processIdTextBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sizeTextBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar)).BeginInit();
            this.SuspendLayout();
            // 
            // id
            // 
            this.id.AutoSize = true;
            this.id.Location = new System.Drawing.Point(509, 196);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(134, 18);
            this.id.TabIndex = 4;
            this.id.Text = "请输入作业编号";
            // 
            // size
            // 
            this.size.AutoSize = true;
            this.size.Location = new System.Drawing.Point(477, 266);
            this.size.Name = "size";
            this.size.Size = new System.Drawing.Size(197, 18);
            this.size.TabIndex = 5;
            this.size.Text = "请输入申请内存大小(K)";
            // 
            // algo
            // 
            this.algo.AutoSize = true;
            this.algo.Location = new System.Drawing.Point(491, 386);
            this.algo.Name = "algo";
            this.algo.Size = new System.Drawing.Size(98, 18);
            this.algo.TabIndex = 6;
            this.algo.Text = "请选择算法";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(494, 429);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(98, 40);
            this.button1.TabIndex = 7;
            this.button1.Text = "申请";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.allocateButton_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(822, 185);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(98, 40);
            this.button2.TabIndex = 8;
            this.button2.Text = "释放";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.deallocateButton_Click);
            // 
            // panel
            // 
            this.panel.Location = new System.Drawing.Point(12, 54);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(1058, 100);
            this.panel.TabIndex = 9;
            // 
            // panellabel
            // 
            this.panellabel.Location = new System.Drawing.Point(12, 12);
            this.panellabel.Name = "panellabel";
            this.panellabel.Size = new System.Drawing.Size(1017, 36);
            this.panellabel.TabIndex = 10;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(954, 157);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 24);
            this.label1.TabIndex = 11;
            this.label1.Text = "640";
            // 
            // processIdTextBox
            // 
            this.processIdTextBox.Location = new System.Drawing.Point(680, 194);
            this.processIdTextBox.Maximum = new decimal(new int[] {
            640,
            0,
            0,
            0});
            this.processIdTextBox.Name = "processIdTextBox";
            this.processIdTextBox.Size = new System.Drawing.Size(120, 28);
            this.processIdTextBox.TabIndex = 12;
            // 
            // sizeTextBox
            // 
            this.sizeTextBox.Location = new System.Drawing.Point(680, 264);
            this.sizeTextBox.Maximum = new decimal(new int[] {
            640,
            0,
            0,
            0});
            this.sizeTextBox.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.sizeTextBox.Name = "sizeTextBox";
            this.sizeTextBox.Size = new System.Drawing.Size(120, 28);
            this.sizeTextBox.TabIndex = 13;
            this.sizeTextBox.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // trackBar
            // 
            this.trackBar.Location = new System.Drawing.Point(451, 309);
            this.trackBar.Maximum = 640;
            this.trackBar.Minimum = 1;
            this.trackBar.Name = "trackBar";
            this.trackBar.Size = new System.Drawing.Size(578, 69);
            this.trackBar.TabIndex = 14;
            this.trackBar.Value = 1;
            this.trackBar.ValueChanged += new System.EventHandler(this.updateTrackBarValue);
            // 
            // algo1
            // 
            this.algo1.AutoSize = true;
            this.algo1.Location = new System.Drawing.Point(606, 384);
            this.algo1.Name = "algo1";
            this.algo1.Size = new System.Drawing.Size(141, 22);
            this.algo1.TabIndex = 15;
            this.algo1.TabStop = true;
            this.algo1.Text = "首次适应算法";
            this.algo1.UseVisualStyleBackColor = true;
            this.algo1.Click += new System.EventHandler(this.algoChoose);
            // 
            // algo2
            // 
            this.algo2.AutoSize = true;
            this.algo2.Location = new System.Drawing.Point(765, 384);
            this.algo2.Name = "algo2";
            this.algo2.Size = new System.Drawing.Size(141, 22);
            this.algo2.TabIndex = 16;
            this.algo2.TabStop = true;
            this.algo2.Text = "最佳适应算法";
            this.algo2.UseVisualStyleBackColor = true;
            this.algo2.Click += new System.EventHandler(this.algoChoose);
            // 
            // info
            // 
            this.info.Location = new System.Drawing.Point(12, 220);
            this.info.Name = "info";
            this.info.ReadOnly = true;
            this.info.Size = new System.Drawing.Size(416, 262);
            this.info.TabIndex = 17;
            this.info.Text = "";
            // 
            // title
            // 
            this.title.Location = new System.Drawing.Point(13, 161);
            this.title.Name = "title";
            this.title.ReadOnly = true;
            this.title.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.title.Size = new System.Drawing.Size(415, 53);
            this.title.TabIndex = 18;
            this.title.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1033, 501);
            this.Controls.Add(this.title);
            this.Controls.Add(this.info);
            this.Controls.Add(this.algo2);
            this.Controls.Add(this.algo1);
            this.Controls.Add(this.trackBar);
            this.Controls.Add(this.sizeTextBox);
            this.Controls.Add(this.processIdTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panellabel);
            this.Controls.Add(this.panel);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.algo);
            this.Controls.Add(this.size);
            this.Controls.Add(this.id);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "赵明泽2151974操作系统动态分区分配方式模拟";
            ((System.ComponentModel.ISupportInitialize)(this.processIdTextBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sizeTextBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label id;
        private System.Windows.Forms.Label size;
        private System.Windows.Forms.Label algo;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Panel panel;
        private System.Windows.Forms.Panel panellabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown processIdTextBox;
        private System.Windows.Forms.NumericUpDown sizeTextBox;
        private System.Windows.Forms.TrackBar trackBar;
        private System.Windows.Forms.RadioButton algo1;
        private System.Windows.Forms.RadioButton algo2;
        private System.Windows.Forms.RichTextBox info;
        private System.Windows.Forms.RichTextBox title;
    }
}

