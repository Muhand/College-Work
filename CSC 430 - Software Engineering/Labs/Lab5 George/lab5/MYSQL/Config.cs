using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MYSQL
{
    class Config
    {
        public static string un = "george";
        public static string pw = "test1234";
        public static string db = "george_lab5";
        public static string host = "127.0.0.1";
        public static string port = "3306";
        public static string cn = "Server = " + host + "; uid = " + un + "; Password = " + pw + "; Database = " + db + "; Port = " + port + ";";
    }
}
