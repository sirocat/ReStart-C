using System;
using System.Windows.Forms;
using DBProject;

namespace MyCompanyApp
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            // WinForm 환경 설정
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormMain());
        }
    }
}
