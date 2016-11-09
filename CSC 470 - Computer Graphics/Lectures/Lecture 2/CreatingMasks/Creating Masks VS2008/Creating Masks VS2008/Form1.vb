Public Class Form1

    Dim allCellButtons As New Collection
    Const numberOfCellRows As Integer = 16, numberOfCellcols As Integer = 64

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        DoubleBuffered = True
        mainButton.Hide()
        dot.Location = New Point(31 * mainButton.Size.Width - 2, dot.Location.Y)
        Dim row As Integer, col As Integer
        Dim btnDigit As Button
        '  allocate & postion the buttons on the form in rows & columns
        For row = 1 To numberOfCellRows
            For col = 1 To numberOfCellcols
                btnDigit = New Button    'allocate a new button
                With btnDigit           'set properties & location of the new button
                    .Size = mainButton.Size
                    .Text = " "   'blank
                    .BackColor = mainButton.BackColor
                    .ForeColor = mainButton.ForeColor
                    .TextAlign = mainButton.TextAlign
                    .Location = New Point(0 + col * mainButton.Size.Width, 35 + row * mainButton.Size.Height)
                    .FlatStyle = FlatStyle.Flat
                    .Tag = "X: " + col.ToString + " Y: " + row.ToString
                End With
                allCellButtons.Add(btnDigit) ' add to our collection
                'Me.Controls.AddRange(New Control() {btnDigit})   'and to the form too
                Me.Controls.AddRange(New Control() {btnDigit})   'and to the form too
                AddHandler btnDigit.Click, AddressOf mainButton_Click
                AddHandler btnDigit.MouseHover, AddressOf mainBoutton_Number
            Next
        Next
        dot.SendToBack()
    End Sub

    Private Sub mainBoutton_Number(ByVal sender As System.Object, ByVal e As System.EventArgs)
        boxNumberX.Text = "Box Number: ( " + CType(sender, Button).Tag + " )"
    End Sub

    Private Sub mainButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        If CType(sender, Button).BackColor = Color.White Then
            CType(sender, Button).BackColor = Color.Black
        Else
            CType(sender, Button).BackColor = Color.White
        End If
        If autoUpdate.Checked Then
            Call createMask_Click(sender, e)
        End If
    End Sub

    Private Sub createMask_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles createMask.Click
        Dim temp As String = Nothing
        Dim aTemp As String = Nothing
        Dim invText(16) As String
        Dim regText As String = Nothing
        Dim line As String = Nothing
        Dim j As Integer = 16
        textMask.Text = typeTextBox.Text + " " + varName.Text + "[] = {" + Environment.NewLine
        For i As Integer = 1 To numberOfCellcols * numberOfCellRows
            If allCellButtons(i).BackColor = Color.White Then
                temp += "0"
            Else
                temp += "1"
            End If
            If i Mod 4 = 0 Then
                aTemp += getHex(temp)
                temp = Nothing
            End If
            If i Mod 8 = 0 Then
                line += " 0x" + aTemp
                If Not i Mod 64 = 0 Then
                    line += ", "
                End If
                aTemp = Nothing
            End If
            If i Mod 64 = 0 Then
                regText += line
                If Not i Mod numberOfCellcols * numberOfCellRows = 0 Then
                    regText += ","
                End If
                regText += Environment.NewLine
                invText(j) += line
                j -= 1
                line = Nothing
            End If

        Next

        If inverse.Checked Then
            For j = 1 To 16
                textMask.Text += invText(j)
                If Not j Mod 16 = 0 Then
                    textMask.Text += ","
                End If
                textMask.Text += Environment.NewLine
            Next
        Else
            textMask.Text += regText
        End If
        textMask.Text += " };"
    End Sub

    Private Function getHex(ByVal value As String) As String
        Select Case value
            Case "0000"
                Return "0"
                Exit Select
            Case "0001"
                Return "1"
                Exit Select
            Case "0010"
                Return "2"
                Exit Select
            Case "0011"
                Return "3"
                Exit Select
            Case "0100"
                Return "4"
                Exit Select
            Case "0101"
                Return "5"
                Exit Select
            Case "0110"
                Return "6"
                Exit Select
            Case "0111"
                Return "7"
                Exit Select
            Case "1000"
                Return "8"
                Exit Select
            Case "1001"
                Return "9"
                Exit Select
            Case "1010"
                Return "A"
                Exit Select
            Case "1011"
                Return "B"
                Exit Select
            Case "1100"
                Return "C"
                Exit Select
            Case "1101"
                Return "D"
                Exit Select
            Case "1110"
                Return "E"
                Exit Select
            Case "1111"
                Return "F"
                Exit Select
        End Select
        Return Nothing
    End Function

    Private Sub autoUpdate_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
        If autoUpdate.Checked Then
            MsgBox("This might slow down the program", MsgBoxStyle.OkOnly, "Warning")
        End If
    End Sub

    Private Sub clear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles clear.Click
        For i As Integer = 1 To numberOfCellcols * numberOfCellRows
            allCellButtons(i).BackColor = Color.White
        Next
    End Sub

    Private Sub AboutUsToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AboutUsToolStripMenuItem.Click
        MsgBox("Created By Elhassan Ahmed (2010) , All Right Reserved", MsgBoxStyle.OkOnly, "About Us")
    End Sub

    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        Me.Close()
    End Sub

    Private Sub HelpToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles HelpToolStripMenuItem.Click
        MsgBox("After box 32 in each row it will go to the start", MsgBoxStyle.OkOnly, "Help")
    End Sub

    Private Sub inverse_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles inverse.Click
        inverse.Checked = Not inverse.Checked
    End Sub

    Private Sub autoUpdate_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles autoUpdate.Click
        autoUpdate.Checked = Not autoUpdate.Checked
    End Sub

    Private Function getBin(ByVal value As String) As String
        Select Case value.ToUpper
            Case "0"
                Return "0000"
                Exit Select
            Case "1"
                Return "0001"
                Exit Select
            Case "2"
                Return "0010"
                Exit Select
            Case "3"
                Return "0011"
                Exit Select
            Case "4"
                Return "0100"
                Exit Select
            Case "5"
                Return "0101"
                Exit Select
            Case "6"
                Return "0110"
                Exit Select
            Case "7"
                Return "0111"
                Exit Select
            Case "8"
                Return "1000"
                Exit Select
            Case "9"
                Return "1001"
                Exit Select
            Case "A"
                Return "1010"
                Exit Select
            Case "B"
                Return "1011"
                Exit Select
            Case "C"
                Return "1100"
                Exit Select
            Case "D"
                Return "1101"
                Exit Select
            Case "E"
                Return "1110"
                Exit Select
            Case "F"
                Return "1111"
                Exit Select
        End Select
        Return Nothing
    End Function

    Private Function getTheBinOfTheString() As String
        Dim fileText As String = textMask.Text
        Dim position As UInt64 = 0
        Dim storeBin As String = Nothing
        Dim line As String = Nothing
        Dim endOfLine As Integer = 0
        While Not position = fileText.Length
            If fileText(position) = "x" Then
                If Not inverse.Checked Then
                    storeBin += getBin(fileText(position + 1)) + getBin(fileText(position + 2))
                Else
                    line += getBin(fileText(position + 1)) + getBin(fileText(position + 2))
                    endOfLine += 2
                    If endOfLine = 16 Then
                        Dim tempString As String = storeBin
                        storeBin = line
                        storeBin += tempString
                        endOfLine = 0
                        line = Nothing
                    End If
                End If
                position += 2
            End If
            position += 1
        End While
        Return storeBin
    End Function
    Private Sub drawData_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles drawData.Click
        Try
            Dim binText As String = getTheBinOfTheString()
            For i As Integer = 1 To numberOfCellcols * numberOfCellRows
                If binText(i - 1) = "0" Then
                    allCellButtons(i).BackColor = Color.White
                Else
                    allCellButtons(i).BackColor = Color.Black
                End If
            Next
        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.OkOnly, "Error")
        End Try
    End Sub
End Class