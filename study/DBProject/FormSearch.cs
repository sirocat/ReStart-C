using System;
using System.Collections.Generic;
using System.Windows.Forms;
// MySqlConnector 네임스페이스
using MySqlConnector;

namespace MyCompanyApp
{
    public partial class FormSearch : Form
    {
        // 메인 폼에 전달할 WHERE 절
        public string WhereClause { get; private set; } = "";

        public FormSearch()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Insert 버튼 클릭 시 새 레코드 삽입
        /// </summary>
        private void btnInsert_Click(object sender, EventArgs e)
        {
            string sql = @"
                INSERT INTO mycompany
                    (id, name, email, dept, job, level, salary)
                VALUES
                    (@id, @name, @email, @dept, @job, @level, @salary);";

            using (MySqlConnection conn = new MySqlConnection(DBConfig.ConnectionString))
            {
                using (MySqlCommand cmd = new MySqlCommand(sql, conn))
                {
                    // 파라미터 설정
                    cmd.Parameters.AddWithValue("@id", txtID.Text);
                    cmd.Parameters.AddWithValue("@name", txtName.Text);
                    cmd.Parameters.AddWithValue("@email", txtEmail.Text);
                    cmd.Parameters.AddWithValue("@dept", txtDept.Text);
                    cmd.Parameters.AddWithValue("@job", txtJob.Text);
                    cmd.Parameters.AddWithValue("@level", txtLevel.Text);
                    cmd.Parameters.AddWithValue("@salary", txtSalary.Text);

                    conn.Open();
                    cmd.ExecuteNonQuery();
                    conn.Close();
                }
            }

            MessageBox.Show("삽입 완료", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        /// <summary>
        /// Search 버튼 클릭 시 WHERE 절 생성 후 다이얼로그 종료
        /// </summary>
        private void btnSearch_Click(object sender, EventArgs e)
        {
            var list = new List<string>();

            if (!string.IsNullOrWhiteSpace(txtID.Text))
                list.Add($"id LIKE '%{txtID.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtName.Text))
                list.Add($"name LIKE '%{txtName.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtEmail.Text))
                list.Add($"email LIKE '%{txtEmail.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtDept.Text))
                list.Add($"dept LIKE '%{txtDept.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtJob.Text))
                list.Add($"job LIKE '%{txtJob.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtLevel.Text))
                list.Add($"level LIKE '%{txtLevel.Text}%'");
            if (!string.IsNullOrWhiteSpace(txtSalary.Text))
                list.Add($"salary = {txtSalary.Text}");

            // AND 로 연결
            WhereClause = string.Join(" AND ", list);
            DialogResult = DialogResult.OK;
            Close();
        }
    }
}
