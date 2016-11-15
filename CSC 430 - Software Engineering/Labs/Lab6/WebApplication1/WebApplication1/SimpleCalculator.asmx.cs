using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
namespace WebApplication1
{
    /// <summary>
    /// Summary description for SimpleCalculator
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class SimpleCalculator : System.Web.Services.WebService
    {
        
        [WebMethod(EnableSession = true)]
        public double doTheMath(double fn, double sn, SharedProject.operators operat)
        {
            double res;
            string sign;

            switch (operat)
            {
                case SharedProject.operators.Add:
                    res = fn + sn;
                    sign = "+";
                    break;
                case SharedProject.operators.Subtract:
                    res = fn - sn;
                    sign = "-";
                    break;
                case SharedProject.operators.Multiply:
                    res = fn * sn;
                    sign = "*";
                    break;
                case SharedProject.operators.Divide:
                    res = fn / sn;
                    sign = "/";
                    break;
                
                case SharedProject.operators.None:
                default:
                    res = 0;
                    sign = "unknown sign";
                    break;
            }

            List<string> calculations;

            if (Session["CALCULATIONS"] == null)
                calculations = new List<string>();
            else
                calculations = (List<string>)Session["CALCULATIONS"];

            string strRecentCalculation = fn.ToString() + " "+ sign +" " + sn.ToString() + " = " + res.ToString();
            calculations.Add(strRecentCalculation);
            Session["CALCULATIONS"] = calculations;

            return res;
        }

        [WebMethod(EnableSession = true)]
        public List<string> getCalculations()
        {
            if (Session["CALCULATIONS"] == null)
            {
                List<string> calculations = new List<string>();
                calculations.Add("There are no calculations yet.");
                return calculations;
            }
            else
                return ((List<string>)Session["CALCULATIONS"]);
        }
    }
}
