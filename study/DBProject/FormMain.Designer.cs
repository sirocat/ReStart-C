// FormMain.Designer.cs
namespace MyCompanyApp
{
    partial class FormMain
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.CheckBox cbName;
        private System.Windows.Forms.CheckBox cbEmail;
        private System.Windows.Forms.CheckBox cbDept;
        private System.Windows.Forms.CheckBox cbJob;
        private System.Windows.Forms.CheckBox cbLevel;
        private System.Windows.Forms.CheckBox cbSalary;
        private System.Windows.Forms.DataGridView dgvEmployees;
        private System.Windows.Forms.Button btnCondition;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null)) components.Dispose();
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.cbName = new System.Windows.Forms.CheckBox();
            this.cbEmail = new System.Windows.Forms.CheckBox();
            this.cbDept = new System.Windows.Forms.CheckBox();
            this.cbJob = new System.Windows.Forms.CheckBox();
            this.cbLevel = new System.Windows.Forms.CheckBox();
            this.cbSalary = new System.Windows.Forms.CheckBox();
            this.dgvEmployees = new System.Windows.Forms.DataGridView();
            this.btnCondition = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployees)).BeginInit();
            this.SuspendLayout();
            // 
            // cbName
            // 
            this.cbName.AutoSize = true;
            this.cbName.Checked = true;
            this.cbName.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbName.Location = new System.Drawing.Point(12, 15);
            this.cbName.Name = "cbName";
            this.cbName.Size = new System.Drawing.Size(48, 16);
            this.cbName.TabIndex = 0;
            this.cbName.Text = "name";
            this.cbName.UseVisualStyleBackColor = true;
            // 
            // cbEmail
            // 
            this.cbEmail.AutoSize = true;
            this.cbEmail.Checked = true;
            this.cbEmail.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbEmail.Location = new System.Drawing.Point(70, 15);
            this.cbEmail.Name = "cbEmail";
            this.cbEmail.Size = new System.Drawing.Size(48, 16);
            this.cbEmail.TabIndex = 1;
            this.cbEmail.Text = "email";
            this.cbEmail.UseVisualStyleBackColor = true;
            // 
            // cbDept
            // 
            this.cbDept.AutoSize = true;
            this.cbDept.Checked = true;
            this.cbDept.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbDept.Location = new System.Drawing.Point(130, 15);
            this.cbDept.Name = "cbDept";
            this.cbDept.Size = new System.Drawing.Size(45, 16);
            this.cbDept.TabIndex = 2;
            this.cbDept.Text = "dept";
            this.cbDept.UseVisualStyleBackColor = true;
            // 
            // cbJob
            // 
            this.cbJob.AutoSize = true;
            this.cbJob.Checked = true;
            this.cbJob.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbJob.Location = new System.Drawing.Point(188, 15);
            this.cbJob.Name = "cbJob";
            this.cbJob.Size = new System.Drawing.Size(37, 16);
            this.cbJob.TabIndex = 3;
            this.cbJob.Text = "job";
            this.cbJob.UseVisualStyleBackColor = true;
            // 
            // cbLevel
            // 
            this.cbLevel.AutoSize = true;
            this.cbLevel.Checked = true;
            this.cbLevel.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbLevel.Location = new System.Drawing.Point(240, 15);
            this.cbLevel.Name = "cbLevel";
            this.cbLevel.Size = new System.Drawing.Size(42, 16);
            this.cbLevel.TabIndex = 4;
            this.cbLevel.Text = "level";
            this.cbLevel.UseVisualStyleBackColor = true;
            // 
            // cbSalary
            // 
            this.cbSalary.AutoSize = true;
            this.cbSalary.Checked = true;
            this.cbSalary.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbSalary.Location = new System.Drawing.Point(298, 15);
            this.cbSalary.Name = "cbSalary";
            this.cbSalary.Size = new System.Drawing.Size(49, 16);
            this.cbSalary.TabIndex = 5;
            this.cbSalary.Text = "salary";
            this.cbSalary.UseVisualStyleBackColor = true;
            // 
            // dgvEmployees
            // 
            this.dgvEmployees.Anchor = ((System.Windows.Forms.AnchorStyles)
                ((((System.Windows.Forms.AnchorStyles.Top |
                    System.Windows.Forms.AnchorStyles.Bottom) |
                  System.Windows.Forms.AnchorStyles.Left) |
                  System.Windows.Forms.AnchorStyles.Right)));
            this.dgvEmployees.ColumnHeadersHeightSizeMode =
                System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvEmployees.Location = new System.Drawing.Point(12, 50);
            this.dgvEmployees.Name = "dgvEmployees";
            this.dgvEmployees.RowTemplate.Height = 23;
            this.dgvEmployees.Size = new System.Drawing.Size(760, 400);
            this.dgvEmployees.TabIndex = 6;
            // 
            // btnCondition
            // 
            this.btnCondition.Anchor = ((System.Windows.Forms.AnchorStyles)
                (System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right));
            this.btnCondition.Location = new System.Drawing.Point(650, 10);
            this.btnCondition.Name = "btnCondition";
            this.btnCondition.Size = new System.Drawing.Size(122, 24);
            this.btnCondition.TabIndex = 7;
            this.btnCondition.Text = "조건을 넣고 만들기";
            this.btnCondition.UseVisualStyleBackColor = true;
            this.btnCondition.Click += new System.EventHandler(this.btnCondition_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode =
                System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 461);
            this.Controls.Add(this.btnCondition);
            this.Controls.Add(this.dgvEmployees);
            this.Controls.Add(this.cbSalary);
            this.Controls.Add(this.cbLevel);
            this.Controls.Add(this.cbJob);
            this.Controls.Add(this.cbDept);
            this.Controls.Add(this.cbEmail);
            this.Controls.Add(this.cbName);
            this.Name = "FormMain";
            this.Text = "메인 창";
            this.Load += new System.EventHandler(this.FormMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployees)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }
    }
}
