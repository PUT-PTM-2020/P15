namespace TCP_Client
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
            this.buttonForward = new System.Windows.Forms.Button();
            this.buttonLeft = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxIP = new System.Windows.Forms.TextBox();
            this.textBoxPort = new System.Windows.Forms.TextBox();
            this.buttonConnect = new System.Windows.Forms.Button();
            this.LabelConnection = new System.Windows.Forms.Label();
            this.buttonDisconnect = new System.Windows.Forms.Button();
            this.buttonLF = new System.Windows.Forms.Button();
            this.buttonRF = new System.Windows.Forms.Button();
            this.buttonRight = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonForward
            // 
            this.buttonForward.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonForward.Enabled = false;
            this.buttonForward.Location = new System.Drawing.Point(285, 97);
            this.buttonForward.Name = "buttonForward";
            this.buttonForward.Size = new System.Drawing.Size(214, 109);
            this.buttonForward.TabIndex = 0;
            this.buttonForward.TabStop = false;
            this.buttonForward.Text = "FORWARD";
            this.buttonForward.UseVisualStyleBackColor = true;
            this.buttonForward.Click += new System.EventHandler(this.ForwardButton_Click);
            // 
            // buttonLeft
            // 
            this.buttonLeft.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonLeft.Enabled = false;
            this.buttonLeft.Location = new System.Drawing.Point(65, 262);
            this.buttonLeft.Name = "buttonLeft";
            this.buttonLeft.Size = new System.Drawing.Size(214, 109);
            this.buttonLeft.TabIndex = 1;
            this.buttonLeft.TabStop = false;
            this.buttonLeft.Text = "LEFT";
            this.buttonLeft.UseVisualStyleBackColor = true;
            this.buttonLeft.Click += new System.EventHandler(this.LeftButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "IP:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(144, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Port:";
            // 
            // textBoxIP
            // 
            this.textBoxIP.Location = new System.Drawing.Point(38, 8);
            this.textBoxIP.Name = "textBoxIP";
            this.textBoxIP.Size = new System.Drawing.Size(100, 20);
            this.textBoxIP.TabIndex = 6;
            // 
            // textBoxPort
            // 
            this.textBoxPort.Location = new System.Drawing.Point(179, 8);
            this.textBoxPort.Name = "textBoxPort";
            this.textBoxPort.Size = new System.Drawing.Size(100, 20);
            this.textBoxPort.TabIndex = 7;
            // 
            // buttonConnect
            // 
            this.buttonConnect.Location = new System.Drawing.Point(285, 6);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(75, 23);
            this.buttonConnect.TabIndex = 8;
            this.buttonConnect.Text = "connect";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // LabelConnection
            // 
            this.LabelConnection.AutoSize = true;
            this.LabelConnection.Location = new System.Drawing.Point(635, 13);
            this.LabelConnection.Name = "LabelConnection";
            this.LabelConnection.Size = new System.Drawing.Size(81, 13);
            this.LabelConnection.TabIndex = 9;
            this.LabelConnection.Text = "Not connected!";
            // 
            // buttonDisconnect
            // 
            this.buttonDisconnect.Enabled = false;
            this.buttonDisconnect.Location = new System.Drawing.Point(366, 6);
            this.buttonDisconnect.Name = "buttonDisconnect";
            this.buttonDisconnect.Size = new System.Drawing.Size(75, 23);
            this.buttonDisconnect.TabIndex = 10;
            this.buttonDisconnect.Text = "disconnect";
            this.buttonDisconnect.UseVisualStyleBackColor = true;
            this.buttonDisconnect.Click += new System.EventHandler(this.buttonDisconnect_Click);
            // 
            // buttonLF
            // 
            this.buttonLF.Enabled = false;
            this.buttonLF.Location = new System.Drawing.Point(65, 97);
            this.buttonLF.Name = "buttonLF";
            this.buttonLF.Size = new System.Drawing.Size(214, 109);
            this.buttonLF.TabIndex = 11;
            this.buttonLF.TabStop = false;
            this.buttonLF.Text = "LF";
            this.buttonLF.UseVisualStyleBackColor = true;
            this.buttonLF.Click += new System.EventHandler(this.buttonLF_Click);
            // 
            // buttonRF
            // 
            this.buttonRF.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonRF.Enabled = false;
            this.buttonRF.Location = new System.Drawing.Point(502, 97);
            this.buttonRF.Name = "buttonRF";
            this.buttonRF.Size = new System.Drawing.Size(214, 109);
            this.buttonRF.TabIndex = 12;
            this.buttonRF.TabStop = false;
            this.buttonRF.Text = "RF";
            this.buttonRF.UseVisualStyleBackColor = true;
            this.buttonRF.Click += new System.EventHandler(this.buttonRF_Click);
            // 
            // buttonRight
            // 
            this.buttonRight.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonRight.Enabled = false;
            this.buttonRight.Location = new System.Drawing.Point(502, 262);
            this.buttonRight.Name = "buttonRight";
            this.buttonRight.Size = new System.Drawing.Size(214, 109);
            this.buttonRight.TabIndex = 13;
            this.buttonRight.TabStop = false;
            this.buttonRight.Text = "RIGHT";
            this.buttonRight.UseVisualStyleBackColor = true;
            this.buttonRight.Click += new System.EventHandler(this.buttonRight_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(744, 225);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 13);
            this.label3.TabIndex = 14;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.buttonRight);
            this.Controls.Add(this.buttonRF);
            this.Controls.Add(this.buttonLF);
            this.Controls.Add(this.buttonDisconnect);
            this.Controls.Add(this.LabelConnection);
            this.Controls.Add(this.buttonConnect);
            this.Controls.Add(this.textBoxPort);
            this.Controls.Add(this.textBoxIP);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonLeft);
            this.Controls.Add(this.buttonForward);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonForward;
        private System.Windows.Forms.Button buttonLeft;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxIP;
        private System.Windows.Forms.TextBox textBoxPort;
        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.Label LabelConnection;
        private System.Windows.Forms.Button buttonDisconnect;
        private System.Windows.Forms.Button buttonLF;
        private System.Windows.Forms.Button buttonRF;
        private System.Windows.Forms.Button buttonRight;
        private System.Windows.Forms.Label label3;
    }
}

