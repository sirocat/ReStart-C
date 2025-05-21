// FormMain.cs
using System;
using System.Data;
using System.Windows.Forms;
using MySqlConnector;

namespace MyCompanyApp
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            LoadData();
        }

        private void LoadData(string whereClause = "")
        {
            var cols = new System.Collections.Generic.List<string> { "id" };
            if (cbName.Checked) cols.Add("name");
            if (cbEmail.Checked) cols.Add("email");
            if (cbDept.Checked) cols.Add("dept");
            if (cbJob.Checked) cols.Add("job");
            if (cbLevel.Checked) cols.Add("level");
            if (cbSalary.Checked) cols.Add("salary");

            string sql = "SELECT " + string.Join(",", cols) + " FROM mycompany";
            if (!string.IsNullOrEmpty(whereClause))
                sql += " WHERE " + whereClause;

            using (MySqlConnection conn = new MySqlConnection(DBConfig.ConnectionString))
            {
                using (MySqlCommand cmd = new MySqlCommand(sql, conn))
                {
                    using (MySqlDataAdapter adapter = new MySqlDataAdapter(cmd))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);
                        dgvEmployees.DataSource = dt;
                    }
                }
            }
        }

        private void btnCondition_Click(object sender, EventArgs e)
        {
            using (FormSearch f = new FormSearch())
            {
                if (f.ShowDialog() == DialogResult.OK)
                    LoadData(f.WhereClause);
            }
        }
    }
}
