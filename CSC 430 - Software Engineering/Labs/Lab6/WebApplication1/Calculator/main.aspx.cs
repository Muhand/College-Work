using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Calculator
{
  
    public partial class main : System.Web.UI.Page
    {
        static Calculator.CalculatorService.operators mathoper = CalculatorService.operators.None;
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void resBtn_Click(object sender, EventArgs e)
        {
            if(firstNum.Text == string.Empty || secondNum.Text== string.Empty || mathoper == CalculatorService.operators.None)
            {
                errorMessage.Text = "Error, Please make sure all fields are filled, and that you have chosen an operator.";
                errorMessage.Visible = true;
                return;
            }
            errorMessage.Text = "";
            errorMessage.Visible = false;

            CalculatorService.SimpleCalculatorSoapClient client = new CalculatorService.SimpleCalculatorSoapClient();
            double result = client.doTheMath(Convert.ToDouble(firstNum.Text), Convert.ToDouble(secondNum.Text), mathoper);

            results.Text = result.ToString();
            calculations.DataSource =  client.getCalculations();
            calculations.DataBind();

            calculations.HeaderRow.Cells[0].Text = "Your previous calculations";
        }

        protected void calculationsBtn_Click(object sender, EventArgs e)
        {
            if (calculations.Visible == false)
            {
                calculations.Visible = true;
                calculationsBtn.Text = "Hide recent calculations";
            }
            else
            {
                calculations.Visible = false;
                calculationsBtn.Text = "Show recent calculations";
            }
        }

        protected void add_Click(object sender, EventArgs e)
        {
            mathoper = CalculatorService.operators.Add;
        }

        protected void subt_Click(object sender, EventArgs e)
        {
            mathoper = CalculatorService.operators.Subtract;
        }

        protected void mult_Click(object sender, EventArgs e)
        {
            mathoper = CalculatorService.operators.Multiply;
        }

        protected void divide_Click(object sender, EventArgs e)
        {
            mathoper = CalculatorService.operators.Divide;
        }
    }
}