using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MYSQL
{
    public class mysqlManager
    {
        private MySqlConnection cn;

        public mysqlManager()
        {
            cn = new MySqlConnection(Config.cn);
        }

        protected internal bool connect()
        {
            if (cn.State == System.Data.ConnectionState.Open)
            {
                disconnect();
                cn.Open();                                                  
                return true;
           
            }
            cn.Open();

            return true;
        }
        protected internal bool disconnect()
        {
            if (cn.State == System.Data.ConnectionState.Open)
            {
                cn.Close();
                return true;
            }

            return false;
        }

        public DataSet fetch()
        {
            DataSet data = new DataSet();

            string Query = "Select * FROM people";

            try
            {
                connect();

                MySqlDataAdapter reader = new MySqlDataAdapter(Query, cn);

                reader.Fill(data, "people");
            }
            catch (Exception)
            {
                throw;
            }
            finally
            {
                disconnect();
            }

            return data;
        }
    }
}
