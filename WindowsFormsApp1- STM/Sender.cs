using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Text;
using System;
using System.Windows.Forms;

namespace WindowsFormsApp1__STM
{
    class Sender
    {
        bool  exception_thrown;
        string addressToSend;
        Socket sending_socket;
        IPAddress send_to_adress;
        IPEndPoint sending_end_point;

        public Sender()
        {
            this.exception_thrown = false;
            this.addressToSend = "127.0.0.1";

            this.sending_socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            this.send_to_adress = IPAddress.Parse(addressToSend);
            this.sending_end_point = new IPEndPoint(send_to_adress, 50000); // 50000 is the port but you can choose every port over 1000 to 80000 i guess.

        }

        ~Sender() { }

        public void sendMessage(string command)
        {
            //Console.WriteLine("Enter text to send and blank line to quit. ");
            //while ()
                //{
                //    //string text_to_send = Console.ReadLine();
                //    if ( )
                //    {
                //        done = true;
                //    }
                //    else
                //    {
                byte[] send_buffer = Encoding.ASCII.GetBytes(command);

                //Console.WriteLine("Sending the message to the IP: {0} port: {1}",
                //                    sending_end_point.Address,
                //                    sending_end_point.Port);
                try
                {
                    sending_socket.SendTo(send_buffer, sending_end_point);
                }
                catch (Exception send_exception)
                {
                    exception_thrown = true;
                    //Console.WriteLine("Exception {0}", send_exception);
                }
                if (exception_thrown == false)
                {
                    //Console.WriteLine("Message has been send to the IP Adress");
                }
                else
                {
                    exception_thrown = false;
                    //Console.WriteLine("The exception indicates the message was not sen");
                }
            //}
            //}
        }
    }



}