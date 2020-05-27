using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace TCP_Client
{
    public partial class Form1 : Form
    {
        StreamWriter writer;
        StreamReader reader;
        TcpClient client;
        Thread t1;
        string read = string.Empty;
        string danger = "dg";
        bool isConnected = false;

        public Form1()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
            /*inicjalizacja wątku odpowiedzialnego za sprawdzenie łączności z serwerem oraz 
             sprawdzającego czy klient otrzymał komunikat o napotkaniu przeszkodzy*/
            t1 = new Thread(new ThreadStart(sensor));
        }

        /*Sprawdzenie czy serwer wysłał pakiet z komunikatem oznaczającym, że pojazd napotkał przeszkodę*/
        public void sensor()                                        
        {
            while(true)
            {
                while (isConnected == true)
                {
                    if (readData() == true)                         
                    {
                        /*Wyłączenie przednich przycisków*/
                        buttonRF.Invoke(new Action(delegate ()
                        {
                            buttonRF.Enabled = false;
                        }));
                        buttonLF.Invoke(new Action(delegate ()
                        {
                            buttonLF.Enabled = false;
                        }));
                        buttonForward.Invoke(new Action(delegate ()
                        {
                            buttonForward.Enabled = false;
                        }));
                    }
                    else                                            
                    {
                        /*Włączenie przednich przycisków*/
                        buttonRF.Invoke(new Action(delegate ()
                        {
                            buttonRF.Enabled = true;
                        }));
                        buttonLF.Invoke(new Action(delegate ()
                        {
                            buttonLF.Enabled = true;
                        }));
                        buttonForward.Invoke(new Action(delegate ()
                        {
                            buttonForward.Enabled = true;
                        }));
                    }
                    //writer.Write("");
                    Thread.Sleep(200);

                    /*Sprawdzenie czy klient nadal jest połączony z serwerem*/
                    if (client.Connected == false)                  
                    {
                        MessageBox.Show("Lost connection with server!");
                        buttonRF.Invoke(new Action(delegate ()
                        {
                            disconnect();
                        }));
                    }
                }
            }
        }

        bool readData()
        {
            try
            {
                read = string.Empty;
                client.ReceiveTimeout = 1;
                read = reader.ReadLine();
                if (read == danger) return true;
                else return false;
            }
            catch (System.IO.IOException)
            {
                return false;
            }
        }

        void connect()
        {
            try
            {
                if (textBoxIP.Text == "") throw new System.FormatException();
               
                /*Ustawienie połączenia z serwerem*/
                client = new TcpClient(textBoxIP.Text, int.Parse(textBoxPort.Text));      
                writer = new StreamWriter(client.GetStream());
                reader = new StreamReader(client.GetStream());
                Thread.Sleep(1000);

                if (client.Connected == true) MessageBox.Show("Connected"); 
                string lbl = "Connected to: " + textBoxIP.Text + ":" + textBoxPort.Text;
                LabelConnection.Text = lbl;
                this.KeyPreview = true;
                isConnected = true;

                /*Włączenie przycisków umożliwiających kontrolowanie pojazdu oraz przycisku 'disconnect'*/
                buttonForward.Enabled = true;
                buttonLeft.Enabled = true;
                buttonRight.Enabled = true;
                buttonLF.Enabled = true;
                buttonRF.Enabled = true;
                buttonDisconnect.Enabled = true;

                /*Wyłączenie przycisku 'connect'*/
                buttonConnect.Enabled = false;

                /*Wyłączenie pól tekstowych*/
                textBoxIP.Enabled = false;
                textBoxPort.Enabled = false;

                client.SendBufferSize = 20;

                /*Wystartowanie lub wznowienie działania wątku t1*/
                if(t1.ThreadState == ThreadState.Suspended)
                {
                    t1.Resume();
                }
                else t1.Start();
            }
            catch (System.Net.Sockets.SocketException ex)
            {
                MessageBox.Show("Failed to connect!");

            }
            catch (System.FormatException ex)
            {
                MessageBox.Show("Wrong text format");
            }
        }

        void disconnect()
        {
            /*Przerwanie połączenie z serwerem*/
            client.Close();
            writer.Close();
            reader.Close();

            if (client.Connected == false) MessageBox.Show("Disconnected");
            LabelConnection.Text = "Not connected!";
            this.KeyPreview = false;
            isConnected = false;

            /*Wyłączenie przycisków umożliwiających kontrolowanie pojazdu oraz przycisku 'disconnect'*/
            buttonForward.Enabled = false;
            buttonLeft.Enabled = false;
            buttonRight.Enabled = false;
            buttonLF.Enabled = false;
            buttonRF.Enabled = false;
            buttonDisconnect.Enabled = false;

            /*Włączenie przycisku 'connect'*/
            buttonConnect.Enabled = true;

            /*Wyłączenie pól tekstowych*/
            textBoxIP.Enabled = true;
            textBoxPort.Enabled = true;

            /*Zawieszenie działania wątku t1*/
            t1.Suspend();  
        }

        /*Zdarzenie związane z wciśnięciem przycisku na klawiaturze*/
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
                if (e.KeyCode == Keys.W)
                {
                    buttonForward.PerformClick();
                }
                else if (e.KeyCode == Keys.A)
                {
                    buttonLeft.PerformClick();
                }
                else if (e.KeyCode == Keys.D)
                {
                    buttonRight.PerformClick();
                }
                else if (e.KeyCode == Keys.Q)
                {
                    buttonLF.PerformClick();
                }
                else if (e.KeyCode == Keys.E)
                {
                    buttonRF.PerformClick();
                }
            //System.Threading.Thread.Sleep(100);
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            connect();
            label3.Focus();
        }

        private void buttonDisconnect_Click(object sender, EventArgs e)
        {
            disconnect();
            label3.Focus();
        }

        private void ForwardButton_Click(object sender, EventArgs e)
        {
            try
            {
                writer.WriteLine("Forward");
                writer.Flush();
                label3.Focus();
            }
            catch(System.IO.IOException)
            {
                MessageBox.Show("Lost connection with server!");
                disconnect();
            }

        }

        private void LeftButton_Click(object sender, EventArgs e)
        {
            try
            {
                writer.WriteLine("Left");
                writer.Flush();
                label3.Focus();
            }
            catch(System.IO.IOException)
            {
                MessageBox.Show("Lost connection with server!");
                disconnect();
            }
           }

        private void buttonRight_Click(object sender, EventArgs e)
        {
            try
            {
                writer.WriteLine("Right");
                writer.Flush();
                label3.Focus();
            }
            catch (System.IO.IOException)
            {
                MessageBox.Show("Lost connection with server!");
                disconnect();
            }
        }

        private void buttonLF_Click(object sender, EventArgs e)
        {
            try
            {
                writer.WriteLine("LLL");
                writer.Flush();
                label3.Focus();
            }
            catch (System.IO.IOException)
            {
                MessageBox.Show("Lost connection with server!");
                disconnect();
            }
        }

        private void buttonRF_Click(object sender, EventArgs e)
        {
            try
            {
                writer.WriteLine("PP");
                writer.Flush();
                label3.Focus();
            }
            catch (System.IO.IOException)
            {
                MessageBox.Show("Lost connection with server!");
                disconnect();
            }
        }
    }
}
