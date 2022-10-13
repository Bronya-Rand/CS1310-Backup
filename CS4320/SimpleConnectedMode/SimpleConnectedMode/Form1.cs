using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.SqlClient; //for SQL commands




namespace SimpleConnectedMode
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                sqlConnection1.Open();
                MessageBox.Show("DB Connected", "St. mary's");
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btn_Load_Click(object sender, EventArgs e)
        {
            SqlCommand cmdLoadAccounts = sqlConnection1.CreateCommand();
            cmdLoadAccounts.CommandText = "SELECT AccountNo FROM Accounts";
            SqlDataReader reader =  cmdLoadAccounts.ExecuteReader();

            while(reader.Read())
            {
                comboAccountNo.Items.Add(reader[0].ToString());
            }
            reader.Close();
        }

        private void comboAccountNo_SelectedIndexChanged(object sender, EventArgs e)
        {
            SqlCommand cmdFindAccount = sqlConnection1.CreateCommand();
            cmdFindAccount.CommandText = "SELECT * FROM Accounts WHERE AccountNo = " + comboAccountNo.Text;
            SqlDataReader reader = cmdFindAccount.ExecuteReader();

            if(reader.Read())
            {
                txtHolderName.Text = reader[1].ToString();
                txtBranch.Text = reader[2].ToString();
                txtOpenDate.Text = reader[3].ToString();
                txtBalance.Text = reader[4].ToString();
            }
            else
            {
                MessageBox.Show("Account No found");
            }
            reader.Close();
        }

        private void btnBranches_Click(object sender, EventArgs e)
        {
            BranchesForm frm = new BranchesForm();
            frm.DBConnection = sqlConnection1;
            frm.ShowDialog();
        }
    }
}
