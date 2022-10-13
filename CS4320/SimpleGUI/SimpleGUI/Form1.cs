using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SimpleGUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Welcome to C#", "DB Class", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information);
        }

        private void btnForm2_Click(object sender, EventArgs e)
        {
            string name = txtStudentName.Text;
            MessageBox.Show("Weclome: " + name, "DB Class");
        }

        private void btnOpenForm2_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.F2Name = comboBox1.Text;
            frm2.ShowDialog();
        }
    }
}
