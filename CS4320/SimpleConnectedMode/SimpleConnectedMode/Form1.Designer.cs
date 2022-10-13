namespace SimpleConnectedMode
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_Load = new System.Windows.Forms.Button();
            this.txtBranch = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.comboAccountNo = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtBalance = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtOpenDate = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txtHolderName = new System.Windows.Forms.TextBox();
            this.btnBranches = new System.Windows.Forms.Button();
            this.sqlConnection1 = new System.Data.SqlClient.SqlConnection();
            this.SuspendLayout();
            // 
            // btn_Load
            // 
            this.btn_Load.Location = new System.Drawing.Point(41, 270);
            this.btn_Load.Name = "btn_Load";
            this.btn_Load.Size = new System.Drawing.Size(96, 40);
            this.btn_Load.TabIndex = 78;
            this.btn_Load.Text = "Load";
            this.btn_Load.Click += new System.EventHandler(this.btn_Load_Click);
            // 
            // txtBranch
            // 
            this.txtBranch.Location = new System.Drawing.Point(137, 102);
            this.txtBranch.Name = "txtBranch";
            this.txtBranch.Size = new System.Drawing.Size(142, 26);
            this.txtBranch.TabIndex = 77;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(17, 102);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(120, 32);
            this.label5.TabIndex = 76;
            this.label5.Text = "Branch";
            // 
            // comboAccountNo
            // 
            this.comboAccountNo.Location = new System.Drawing.Point(137, 22);
            this.comboAccountNo.Name = "comboAccountNo";
            this.comboAccountNo.Size = new System.Drawing.Size(240, 28);
            this.comboAccountNo.TabIndex = 69;
            this.comboAccountNo.SelectedIndexChanged += new System.EventHandler(this.comboAccountNo_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(17, 62);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(120, 24);
            this.label4.TabIndex = 72;
            this.label4.Text = "Holder Name";
            // 
            // txtBalance
            // 
            this.txtBalance.Location = new System.Drawing.Point(137, 182);
            this.txtBalance.Name = "txtBalance";
            this.txtBalance.Size = new System.Drawing.Size(142, 26);
            this.txtBalance.TabIndex = 71;
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(17, 182);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(104, 24);
            this.label3.TabIndex = 70;
            this.label3.Text = "Balance";
            // 
            // txtOpenDate
            // 
            this.txtOpenDate.Location = new System.Drawing.Point(137, 142);
            this.txtOpenDate.Name = "txtOpenDate";
            this.txtOpenDate.Size = new System.Drawing.Size(240, 26);
            this.txtOpenDate.TabIndex = 75;
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(17, 142);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(112, 24);
            this.label2.TabIndex = 74;
            this.label2.Text = "Open Date";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(17, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(120, 24);
            this.label1.TabIndex = 68;
            this.label1.Text = "Account No.";
            // 
            // txtHolderName
            // 
            this.txtHolderName.Location = new System.Drawing.Point(137, 62);
            this.txtHolderName.Name = "txtHolderName";
            this.txtHolderName.Size = new System.Drawing.Size(240, 26);
            this.txtHolderName.TabIndex = 77;
            // 
            // btnBranches
            // 
            this.btnBranches.Location = new System.Drawing.Point(183, 270);
            this.btnBranches.Name = "btnBranches";
            this.btnBranches.Size = new System.Drawing.Size(96, 40);
            this.btnBranches.TabIndex = 78;
            this.btnBranches.Text = "Branches";
            this.btnBranches.Click += new System.EventHandler(this.btnBranches_Click);
            // 
            // sqlConnection1
            // 
            this.sqlConnection1.ConnectionString = "Data Source=EI;Initial Catalog=BankDB;Integrated Security=True";
            this.sqlConnection1.FireInfoMessageEventOnUserErrors = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(627, 328);
            this.Controls.Add(this.btnBranches);
            this.Controls.Add(this.btn_Load);
            this.Controls.Add(this.txtHolderName);
            this.Controls.Add(this.txtBranch);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.comboAccountNo);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtBalance);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtOpenDate);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Load;
        private System.Windows.Forms.TextBox txtBranch;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox comboAccountNo;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtBalance;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtOpenDate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtHolderName;
        private System.Windows.Forms.Button btnBranches;
        private System.Data.SqlClient.SqlConnection sqlConnection1;
    }
}

