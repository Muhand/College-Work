using System;
using System.Data;
using System.Web;
using MySql.Data.MySqlClient;

namespace CityDataReader
{
    public class CityDataReader
    {
        public MySqlDataReader GetCity()
        {
            // Create Connection
            MySqlConnection con = new MySqlConnection("server=localhost;User Id=root;password=csi1;database=world");

            // Create Command
            MySqlCommand cmd = new MySqlCommand();

            cmd.Connection = con;
            cmd.CommandText = "SELECT Name, CountryCode, District, Population FROM CITY";
            // Return DataReader
            con.Open();
            return cmd.ExecuteReader(CommandBehavior.CloseConnection);
        }
    }     
}