namespace WindowsFormsApp1__STM
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.left_button = new System.Windows.Forms.Button();
            this.right_button = new System.Windows.Forms.Button();
            this.up_button = new System.Windows.Forms.Button();
            this.down_button = new System.Windows.Forms.Button();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            this.SuspendLayout();
            // 
            // left_button
            // 
            this.left_button.CausesValidation = false;
            this.left_button.Location = new System.Drawing.Point(103, 126);
            this.left_button.Name = "left_button";
            this.left_button.Size = new System.Drawing.Size(88, 50);
            this.left_button.TabIndex = 0;
            this.left_button.Text = "Left";
            this.left_button.UseVisualStyleBackColor = true;
            this.left_button.KeyDown += new System.Windows.Forms.KeyEventHandler(this.left_button_KeyDown);
            // 
            // right_button
            // 
            this.right_button.CausesValidation = false;
            this.right_button.Location = new System.Drawing.Point(293, 126);
            this.right_button.Name = "right_button";
            this.right_button.Size = new System.Drawing.Size(88, 50);
            this.right_button.TabIndex = 2;
            this.right_button.Text = "Right";
            this.right_button.UseVisualStyleBackColor = true;
            this.right_button.KeyDown += new System.Windows.Forms.KeyEventHandler(this.right_button_KeyDown);
            // 
            // up_button
            // 
            this.up_button.CausesValidation = false;
            this.up_button.Location = new System.Drawing.Point(199, 70);
            this.up_button.Name = "up_button";
            this.up_button.Size = new System.Drawing.Size(88, 50);
            this.up_button.TabIndex = 3;
            this.up_button.Text = "Up";
            this.up_button.UseVisualStyleBackColor = true;
            this.up_button.KeyDown += new System.Windows.Forms.KeyEventHandler(this.up_button_KeyDown);
            // 
            // down_button
            // 
            this.down_button.CausesValidation = false;
            this.down_button.Location = new System.Drawing.Point(199, 126);
            this.down_button.Name = "down_button";
            this.down_button.Size = new System.Drawing.Size(88, 50);
            this.down_button.TabIndex = 4;
            this.down_button.Text = "Down";
            this.down_button.UseVisualStyleBackColor = true;
            this.down_button.KeyDown += new System.Windows.Forms.KeyEventHandler(this.down_button_KeyDown);
            // 
            // trackBar1
            // 
            this.trackBar1.CausesValidation = false;
            this.trackBar1.Location = new System.Drawing.Point(23, 12);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trackBar1.Size = new System.Drawing.Size(45, 256);
            this.trackBar1.TabIndex = 5;
            this.trackBar1.Value = 5;
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(91, 223);
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(343, 45);
            this.trackBar2.TabIndex = 5;
            this.trackBar2.Value = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CausesValidation = false;
            this.ClientSize = new System.Drawing.Size(491, 302);
            this.Controls.Add(this.trackBar2);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.down_button);
            this.Controls.Add(this.up_button);
            this.Controls.Add(this.right_button);
            this.Controls.Add(this.left_button);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button left_button;
        private System.Windows.Forms.Button right_button;
        private System.Windows.Forms.Button up_button;
        private System.Windows.Forms.Button down_button;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.TrackBar trackBar2;
    }
}

