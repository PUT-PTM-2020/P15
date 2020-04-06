using System;
using System.Windows.Forms;

namespace WindowsFormsApp1__STM
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();

        }

        private void left_button_KeyDown(object sender, KeyEventArgs e)
        {
            button_KeyDown_send(sender, e);
        }

        private void right_button_KeyDown(object sender, KeyEventArgs e)
        {
            button_KeyDown_send(sender, e);
        }

        private void up_button_KeyDown(object sender, KeyEventArgs e)
        {
            button_KeyDown_send(sender, e);
        }

        private void down_button_KeyDown(object sender, KeyEventArgs e)
        {
            button_KeyDown_send(sender, e);
        }

        private void button_KeyDown_send(object sender, KeyEventArgs e)
        {
            Sender sendMessage = new Sender();
            switch (e.KeyCode)
            {
                case Keys.A:
                    sendMessage.sendMessage("LEFT");
                    tracBar_location(e);
                    break;
                case Keys.W:
                    sendMessage.sendMessage("UP");
                    tracBar_location(e);
                    break;
                case Keys.S:
                    sendMessage.sendMessage("DOWN");
                    tracBar_location(e);
                    break;
                case Keys.D:
                    sendMessage.sendMessage("RIGHT");
                    tracBar_location(e);
                    break;
            }
        }

        private void tracBar_location(KeyEventArgs e)
        {
            if ((trackBar1.Value >= 0) && (trackBar1.Value <= 10))
            {
                switch (e.KeyCode)
                {
                    case Keys.A:
                        if(trackBar2.Value > 0)
                        trackBar2.Value -= 1;
                        break;
                    case Keys.W:
                        if(trackBar1.Value <10)
                            trackBar1.Value += 1;
                        break;
                    case Keys.S:
                        if (trackBar1.Value > 0)
                            trackBar1.Value -= 1;
                        break;
                    case Keys.D:
                        if (trackBar2.Value < 10)
                            trackBar2.Value += 1;
                        break;
                }
            }
        }


    }
}



