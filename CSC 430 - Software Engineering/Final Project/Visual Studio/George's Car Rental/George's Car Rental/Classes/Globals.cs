using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using George_s_Car_Rental.Objects;
using System;
using System.ComponentModel;
using System.Net.Mail;
using System.Net;

namespace George_s_Car_Rental.Classes
{
    public class Globals
    {
        private static string _supportEmailAddress = "georgescarrental@gmail.com";
        private static string _supportEmailPassword = "Test123456789";
        public static string CONNECTION_USERNAME = "Muhand";
        public static string CONNECTION_PASSWORD = "Tiesto223";
        public static string DATABASE_NAME = "carrental";
        public static string SERVER_IP = "127.0.0.1";
        public static string SERVER_PORT = "3306";
        
        public static List<Store> FoundStores = new List<Store>();
        //public static List<CartItem> Cart = new List<CartItem>();
        
        public static Cart cart = new Cart();
        
        //public static Cart cart = new Cart();
        private static string _errorMessage;
        private static int _cartQuantity;
        
        private static string SupportEmailAddress
        {
            get { return _supportEmailAddress; }
            set { _supportEmailAddress = value; }
        }

        private static string SupportEmailPassword
        {
            get { return _supportEmailPassword; }
            set { _supportEmailPassword = value; }
        }



        public static MainWindow mainWindow
        {
            set;
            get;
        }
        public static Store selectedStore
        {
            set;
            get;
        }

        public static string searchedZipCode
        {
            set;
            get;
        }

        public static string buyerFirstName
        {
            set;
            get;
        }
        public static string buyerMiddleName
        {
            set;
            get;
        }

        public static string buyersLastName
        {
            set;
            get;
        }

        public static string buyersEmail
        {
            set;
            get;
        }
        public static string errorMessage
        {
            get { return _errorMessage; }
            set
            {
                if (_errorMessage == value) return;
                if (value != string.Empty)
                    _errorMessage = "Error, " + value;
                else
                    _errorMessage = string.Empty;
                
                RaiseStaticPropertyChanged("errorMessage");
            }
        }

        public static int cartQuantity
        {
            get { return _cartQuantity; }
            set
            {
                if (_cartQuantity == value) return;
                _cartQuantity = value;
                RaiseStaticPropertyChanged("cartQuantity");
            }
        }

        public static event EventHandler<PropertyChangedEventArgs> StaticPropertyChanged;
        public static void RaiseStaticPropertyChanged(string propName)
        {
            EventHandler<PropertyChangedEventArgs> handler = StaticPropertyChanged;
            if (handler != null)
                handler(null, new PropertyChangedEventArgs(propName));
        }

      public static void allowOnlyNumbers(TextBox field)
        {
            bool enteredLetter = false;
            Queue<char> text = new Queue<char>();
            foreach (var ch in field.Text)
            {
                if (char.IsDigit(ch))
                    text.Enqueue(ch);
                else
                {
                    enteredLetter = true;
                    errorMessage = "Please enter only numbers.";
                }
            }

            if (enteredLetter)
            {
                StringBuilder sb = new StringBuilder();
                while (text.Count > 0)
                    sb.Append(text.Dequeue());

                field.Text = sb.ToString();
                field.SelectionStart = field.Text.Length;
            }
        }

      public static void sendEmail(string from,string password,string to, string subject, string body)
      {

          MailMessage msg = new MailMessage();
          msg.Subject = subject;
          msg.From = new MailAddress(from);
          msg.Body = body;
          msg.To.Add(new MailAddress(to));
          SmtpClient smtp = new SmtpClient();
          smtp.Host = "smtp.gmail.com";
          smtp.Port = 587;
          smtp.UseDefaultCredentials = false;
          smtp.EnableSsl = true;
          NetworkCredential nc = new NetworkCredential(from, password);
          smtp.Credentials = nc;
          smtp.Send(msg);
      }
      public static void sendEmail(string to, string subject, string body)
      {
          sendEmail(SupportEmailAddress,SupportEmailPassword, to, subject, body);
      }
    }
}
