using System;
using System.Data;
using System.Web;
//To use MySql data base, you need to (1) add MySql.Data to Reference folder
//(2) add the line below:
using MySql.Data.MySqlClient;

namespace CityDataSet
{
    public class ShowCityDataSet
    {
        private readonly string _conString = "server=localhost;User Id=root;password=monitor;database=world";
        public DataSet GetCity2()
        {
            // Create DataAdapter
            string commandText = "SELECT Name, CountryCode, District, Population FROM CITY";
            MySqlDataAdapter dad = new MySqlDataAdapter(commandText, _conString);
            // Return DataSet
            DataSet dstCity = new DataSet();
            using (dad)
            {
                dad.Fill(dstCity);
            }
            return dstCity;
        }

    }
}
