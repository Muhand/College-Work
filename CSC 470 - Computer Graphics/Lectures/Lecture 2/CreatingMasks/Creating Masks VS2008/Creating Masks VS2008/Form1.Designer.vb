<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.autoUpdate = New System.Windows.Forms.ToolStripMenuItem
        Me.drawData = New System.Windows.Forms.Button
        Me.OptionsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.inverse = New System.Windows.Forms.ToolStripMenuItem
        Me.Label3 = New System.Windows.Forms.Label
        Me.AboutUsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip
        Me.boxNumberX = New System.Windows.Forms.ToolStripStatusLabel
        Me.mainButton = New System.Windows.Forms.Button
        Me.dot = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.typeTextBox = New System.Windows.Forms.TextBox
        Me.HelpToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.Label2 = New System.Windows.Forms.Label
        Me.varName = New System.Windows.Forms.TextBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.clear = New System.Windows.Forms.Button
        Me.createMask = New System.Windows.Forms.Button
        Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.textMask = New System.Windows.Forms.TextBox
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip
        Me.StatusStrip1.SuspendLayout()
        Me.MenuStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'ExitToolStripMenuItem
        '
        Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
        Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(123, 22)
        Me.ExitToolStripMenuItem.Text = "Exit"
        '
        'autoUpdate
        '
        Me.autoUpdate.Name = "autoUpdate"
        Me.autoUpdate.Size = New System.Drawing.Size(141, 22)
        Me.autoUpdate.Text = "Auto Update"
        '
        'drawData
        '
        Me.drawData.Location = New System.Drawing.Point(346, 391)
        Me.drawData.Margin = New System.Windows.Forms.Padding(2)
        Me.drawData.Name = "drawData"
        Me.drawData.Size = New System.Drawing.Size(165, 54)
        Me.drawData.TabIndex = 27
        Me.drawData.Text = "Draw"
        Me.drawData.UseVisualStyleBackColor = True
        '
        'OptionsToolStripMenuItem
        '
        Me.OptionsToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.autoUpdate, Me.inverse})
        Me.OptionsToolStripMenuItem.Name = "OptionsToolStripMenuItem"
        Me.OptionsToolStripMenuItem.Size = New System.Drawing.Size(61, 20)
        Me.OptionsToolStripMenuItem.Text = "Options"
        '
        'inverse
        '
        Me.inverse.Checked = True
        Me.inverse.CheckState = System.Windows.Forms.CheckState.Checked
        Me.inverse.Name = "inverse"
        Me.inverse.Size = New System.Drawing.Size(141, 22)
        Me.inverse.Text = "Inverse Y"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(523, 27)
        Me.Label3.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(64, 13)
        Me.Label3.TabIndex = 29
        Me.Label3.Text = "Hex display:"
        '
        'AboutUsToolStripMenuItem
        '
        Me.AboutUsToolStripMenuItem.Name = "AboutUsToolStripMenuItem"
        Me.AboutUsToolStripMenuItem.Size = New System.Drawing.Size(123, 22)
        Me.AboutUsToolStripMenuItem.Text = "About Us"
        '
        'StatusStrip1
        '
        Me.StatusStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.boxNumberX})
        Me.StatusStrip1.Location = New System.Drawing.Point(0, 447)
        Me.StatusStrip1.Name = "StatusStrip1"
        Me.StatusStrip1.Padding = New System.Windows.Forms.Padding(1, 0, 10, 0)
        Me.StatusStrip1.Size = New System.Drawing.Size(845, 22)
        Me.StatusStrip1.TabIndex = 26
        Me.StatusStrip1.Text = "StatusStrip1"
        '
        'boxNumberX
        '
        Me.boxNumberX.Name = "boxNumberX"
        Me.boxNumberX.Size = New System.Drawing.Size(82, 17)
        Me.boxNumberX.Text = "Box Number:  "
        '
        'mainButton
        '
        Me.mainButton.BackColor = System.Drawing.Color.White
        Me.mainButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.mainButton.Location = New System.Drawing.Point(17, 69)
        Me.mainButton.Margin = New System.Windows.Forms.Padding(2)
        Me.mainButton.Name = "mainButton"
        Me.mainButton.Size = New System.Drawing.Size(8, 20)
        Me.mainButton.TabIndex = 17
        Me.mainButton.UseVisualStyleBackColor = False
        '
        'dot
        '
        Me.dot.AutoSize = True
        Me.dot.Font = New System.Drawing.Font("Microsoft Sans Serif", 30.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.dot.Location = New System.Drawing.Point(8, 25)
        Me.dot.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.dot.Name = "dot"
        Me.dot.Size = New System.Drawing.Size(31, 46)
        Me.dot.TabIndex = 28
        Me.dot.Text = "."
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(6, 42)
        Me.Label4.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(72, 13)
        Me.Label4.TabIndex = 30
        Me.Label4.Text = "Draw Display:"
        '
        'typeTextBox
        '
        Me.typeTextBox.Location = New System.Drawing.Point(583, 407)
        Me.typeTextBox.Margin = New System.Windows.Forms.Padding(2)
        Me.typeTextBox.Name = "typeTextBox"
        Me.typeTextBox.Size = New System.Drawing.Size(86, 20)
        Me.typeTextBox.TabIndex = 24
        Me.typeTextBox.Text = "GLubyte"
        Me.typeTextBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'HelpToolStripMenuItem
        '
        Me.HelpToolStripMenuItem.Name = "HelpToolStripMenuItem"
        Me.HelpToolStripMenuItem.Size = New System.Drawing.Size(123, 22)
        Me.HelpToolStripMenuItem.Text = "Help"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.8!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(548, 407)
        Me.Label2.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(44, 17)
        Me.Label2.TabIndex = 23
        Me.Label2.Text = "Type:"
        '
        'varName
        '
        Me.varName.Location = New System.Drawing.Point(732, 407)
        Me.varName.Margin = New System.Windows.Forms.Padding(2)
        Me.varName.Name = "varName"
        Me.varName.Size = New System.Drawing.Size(86, 20)
        Me.varName.TabIndex = 22
        Me.varName.Text = "mask"
        Me.varName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.8!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(691, 407)
        Me.Label1.Margin = New System.Windows.Forms.Padding(2, 0, 2, 0)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(49, 17)
        Me.Label1.TabIndex = 21
        Me.Label1.Text = "Name:"
        '
        'clear
        '
        Me.clear.Location = New System.Drawing.Point(9, 391)
        Me.clear.Margin = New System.Windows.Forms.Padding(2)
        Me.clear.Name = "clear"
        Me.clear.Size = New System.Drawing.Size(165, 54)
        Me.clear.TabIndex = 20
        Me.clear.Text = "Clear"
        Me.clear.UseVisualStyleBackColor = True
        '
        'createMask
        '
        Me.createMask.Location = New System.Drawing.Point(177, 391)
        Me.createMask.Margin = New System.Windows.Forms.Padding(2)
        Me.createMask.Name = "createMask"
        Me.createMask.Size = New System.Drawing.Size(165, 54)
        Me.createMask.TabIndex = 19
        Me.createMask.Text = "Create Mask"
        Me.createMask.UseVisualStyleBackColor = True
        '
        'FileToolStripMenuItem
        '
        Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.HelpToolStripMenuItem, Me.AboutUsToolStripMenuItem, Me.ExitToolStripMenuItem})
        Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
        Me.FileToolStripMenuItem.Size = New System.Drawing.Size(37, 20)
        Me.FileToolStripMenuItem.Text = "File"
        '
        'textMask
        '
        Me.textMask.Location = New System.Drawing.Point(526, 48)
        Me.textMask.Margin = New System.Windows.Forms.Padding(2)
        Me.textMask.Multiline = True
        Me.textMask.Name = "textMask"
        Me.textMask.Size = New System.Drawing.Size(318, 336)
        Me.textMask.TabIndex = 18
        '
        'MenuStrip1
        '
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem, Me.OptionsToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Padding = New System.Windows.Forms.Padding(4, 2, 0, 2)
        Me.MenuStrip1.Size = New System.Drawing.Size(845, 24)
        Me.MenuStrip1.TabIndex = 25
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(845, 469)
        Me.Controls.Add(Me.drawData)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.StatusStrip1)
        Me.Controls.Add(Me.mainButton)
        Me.Controls.Add(Me.dot)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.typeTextBox)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.varName)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.clear)
        Me.Controls.Add(Me.createMask)
        Me.Controls.Add(Me.textMask)
        Me.Controls.Add(Me.MenuStrip1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.StatusStrip1.ResumeLayout(False)
        Me.StatusStrip1.PerformLayout()
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents autoUpdate As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents drawData As System.Windows.Forms.Button
    Friend WithEvents OptionsToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents inverse As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents AboutUsToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents StatusStrip1 As System.Windows.Forms.StatusStrip
    Friend WithEvents boxNumberX As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents mainButton As System.Windows.Forms.Button
    Friend WithEvents dot As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents typeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents HelpToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents varName As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents clear As System.Windows.Forms.Button
    Friend WithEvents createMask As System.Windows.Forms.Button
    Friend WithEvents FileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents textMask As System.Windows.Forms.TextBox
    Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip

End Class
