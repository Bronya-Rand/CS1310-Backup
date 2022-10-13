using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.SqlClient;
using System.Configuration;

using System.Data.SqlClient;

namespace SimpleConnectedMode
{
    public partial class BranchesForm : Form
    {
        public SqlConnection DBConnection;

        public BranchesForm()
        {
            InitializeComponent();
        }

        private void BranchesForm_Load(object sender, EventArgs e)
        {
            SqlCommand cmdLoadBranches = DBConnection.CreateCommand();
            cmdLoadBranches.CommandText = "SELECT BranchName FROM Branches";
            SqlDataReader reader =  cmdLoadBranches.ExecuteReader();

            while(reader.Read())
            {
                comboBranches.Items.Add(reader[0].ToString());
            }
            reader.Close();
        }

        private void comboBranches_SelectedIndexChanged(object sender, EventArgs e)
        {
            string br = comboBranches.Text;
            SqlCommand cmdBranchAccounts = DBConnection.CreateCommand();
            //SQL Attack
            //cmdBranchAccounts.CommandText = "SELECT * FROM Accounts WHERE Branch = '" + br + "'";

            //parametrized query
            cmdBranchAccounts.CommandText = "SELECT * FROM Accounts WHERE Branch = @br";
            cmdBranchAccounts.Parameters.AddWithValue("@br", br);
            SqlDataReader reader = cmdBranchAccounts.ExecuteReader();
            DataTable table = new DataTable();
            table.Load(reader);
            dataGridView1.DataSource = table;
            reader.Close();
        }
    }
}
