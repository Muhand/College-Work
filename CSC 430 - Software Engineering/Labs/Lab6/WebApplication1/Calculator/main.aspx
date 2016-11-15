<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="main.aspx.cs" Inherits="Calculator.main" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <table style="font-family:Arial">
         <tr>
            <td>
                <asp:Label ID="errorMessage" runat="server" Visible="false" ForeColor="Red"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>
                <b>First Number: </b>
            </td>
            <td>
                <asp:TextBox ID="firstNum" runat="server"></asp:TextBox>
            </td>
        </tr>
         <tr>
            <td>
                <b>Second Number: </b>
            </td>
            <td>
                <asp:TextBox ID="secondNum" runat="server"></asp:TextBox>
            </td>
        </tr>
         <tr>
            <td>
                <b>Result: </b>
            </td>
            <td>
                <asp:Label ID="results" runat="server"></asp:Label>
            </td>
        </tr>
        <tr>
           <td>
               <table style="font-family:Arial">

                   <tr>
                       <td>
                           <span style="margin-right:5px;">
                               <asp:Button ID="add" runat="server" Text="+" OnClick="add_Click" />
                           </span>

                           <span style="margin-right:5px;">
                               <asp:Button ID="subt" runat="server" Text="-" OnClick="subt_Click" />
                           </span>

                            <span style="margin-right:5px;">
                               <asp:Button ID="mult" runat="server" Text="*" OnClick="mult_Click" />
                           </span>
                            <span style="margin-right:5px;">
                               <asp:Button ID="divide" runat="server" Text="/" OnClick="divide_Click" />
                           </span>
                       </td>
                     <%-- <asp:Button ID="add" runat="server" Text="+"/>
                       <asp:Button ID="subt" runat="server" Text="-"/>
                       <asp:Button ID="mult" runat="server" Text="*"/>
                       <asp:Button ID="divide" runat="server" Text="/"/>--%>
                       
                   </tr>
               </table>
           </td>
        </tr>
        <tr>
            <td colspan="2">
               <div style="width:100%;">
                 <asp:Button ID="resBtn" runat="server" Text="Calculate" OnClick="resBtn_Click" width="100%"/>
               </div>
               <div>
                 <asp:Button ID="calculationsBtn" runat="server" Text="Show recent calculations" width="100%" OnClick="calculationsBtn_Click"/>
               </div>
            </td>
            <td>
                
            </td>
        </tr>

        <tr>
            <td colspan="2">
                <asp:GridView ID="calculations" runat="server" Visible="false">

                </asp:GridView>
            </td>
        </tr>
    </table>
    </div>
    </form>
</body>
</html>
