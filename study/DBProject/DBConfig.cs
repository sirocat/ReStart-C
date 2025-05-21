using System;
using System.Windows.Forms;
using MySqlConnector;

namespace MyCompanyApp
{
    public static class DBConfig
    {
        // 실제 사용할 DB: myprog
        public const string ConnectionString =
            "Server=127.0.0.1;Port=3306;Database=myprog;Uid=abcd1234;Pwd=1234;";

        static DBConfig()
        {
            try
            {
                using (var conn = new MySqlConnection(ConnectionString))
                {
                    conn.Open();
                    MessageBox.Show("DB 연결 성공", "정보", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"DB 연결 실패: {ex.Message}", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
