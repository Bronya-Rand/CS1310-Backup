namespace VS2022SimpleConnectedForm
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.accountNoLabel = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.holderNameLabel = new System.Windows.Forms.Label();
            this.branchLabel = new System.Windows.Forms.Label();
            this.openDateLabel = new System.Windows.Forms.Label();
            this.balanceLabel = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.loadButton = new System.Windows.Forms.Button();
            this.branchButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // accountNoLabel
            // 
            this.accountNoLabel.AutoSize = true;
            this.accountNoLabel.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.accountNoLabel.Location = new System.Drawing.Point(35, 45);
            this.accountNoLabel.Name = "accountNoLabel";
            this.accountNoLabel.Size = new System.Drawing.Size(115, 25);
            this.accountNoLabel.TabIndex = 0;
            this.accountNoLabel.Text = "Account No.";
            this.accountNoLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(175, 47);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(223, 23);
            this.comboBox1.TabIndex = 1;
            // 
            // holderNameLabel
            // 
            this.holderNameLabel.AutoSize = true;
            this.holderNameLabel.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.holderNameLabel.Location = new System.Drawing.Point(35, 87);
            this.holderNameLabel.Name = "holderNameLabel";
            this.holderNameLabel.Size = new System.Drawing.Size(124, 25);
            this.holderNameLabel.TabIndex = 2;
            this.holderNameLabel.Text = "Holder Name";
            // 
            // branchLabel
            // 
            this.branchLabel.AutoSize = true;
            this.branchLabel.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.branchLabel.Location = new System.Drawing.Point(35, 128);
            this.branchLabel.Name = "branchLabel";
            this.branchLabel.Size = new System.Drawing.Size(71, 25);
            this.branchLabel.TabIndex = 4;
            this.branchLabel.Text = "Branch";
            // 
            // openDateLabel
            // 
            this.openDateLabel.AutoSize = true;
            this.openDateLabel.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.openDateLabel.Location = new System.Drawing.Point(35, 172);
            this.openDateLabel.Name = "openDateLabel";
            this.openDateLabel.Size = new System.Drawing.Size(102, 25);
            this.openDateLabel.TabIndex = 6;
            this.openDateLabel.Text = "Open Date";
            // 
            // balanceLabel
            // 
            this.balanceLabel.AutoSize = true;
            this.balanceLabel.Font = new System.Drawing.Font("Segoe UI", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.balanceLabel.Location = new System.Drawing.Point(35, 217);
            this.balanceLabel.Name = "balanceLabel";
            this.balanceLabel.Size = new System.Drawing.Size(78, 25);
            this.balanceLabel.TabIndex = 8;
            this.balanceLabel.Text = "Balance";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(175, 89);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(223, 23);
            this.textBox1.TabIndex = 9;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(175, 130);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(162, 23);
            this.textBox2.TabIndex = 10;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(175, 174);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(223, 23);
            this.textBox3.TabIndex = 11;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(175, 217);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(125, 23);
            this.textBox4.TabIndex = 12;
            // 
            // loadButton
            // 
            this.loadButton.Location = new System.Drawing.Point(35, 354);
            this.loadButton.Name = "loadButton";
            this.loadButton.Size = new System.Drawing.Size(75, 23);
            this.loadButton.TabIndex = 13;
            this.loadButton.Text = "Load";
            this.loadButton.UseVisualStyleBackColor = true;
            // 
            // branchButton
            // 
            this.branchButton.Location = new System.Drawing.Point(131, 354);
            this.branchButton.Name = "branchButton";
            this.branchButton.Size = new System.Drawing.Size(75, 23);
            this.branchButton.TabIndex = 14;
            this.branchButton.Text = "Branches";
            this.branchButton.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 424);
            this.Controls.Add(this.branchButton);
            this.Controls.Add(this.loadButton);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.balanceLabel);
            this.Controls.Add(this.openDateLabel);
            this.Controls.Add(this.branchLabel);
            this.Controls.Add(this.holderNameLabel);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.accountNoLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label accountNoLabel;
        private ComboBox comboBox1;
        private Label holderNameLabel;
        private Label branchLabel;
        private Label openDateLabel;
        private Label balanceLabel;
        private TextBox textBox1;
        private TextBox textBox2;
        private TextBox textBox3;
        private TextBox textBox4;
        private Button loadButton;
        private Button branchButton;
        private SqlConnection sqlConnection1;
    }
}