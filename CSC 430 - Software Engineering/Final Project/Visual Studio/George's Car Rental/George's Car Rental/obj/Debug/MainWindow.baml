   M S B A M L   `   `   `  ����M  IGeorges Car Rental, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null9!clr-namespace:George_s_Car_RentalGeorge_s_Car_Rental  5   	   W0clr-namespace:George_s_Car_Rental.CustomControls"George_s_Car_Rental.CustomControls  5   	   I)clr-namespace:George_s_Car_Rental.ClassesGeorge_s_Car_Rental.Classes  5   	   $    George_s_Car_Rental.MainWindow   5   	   W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   3local!clr-namespace:George_s_Car_Rental     5   	   KcustomControls0clr-namespace:George_s_Car_Rental.CustomControls     5   	   =globals)clr-namespace:George_s_Car_Rental.Classes     5   	     � Title$  
MainWindow��5
   	   $	��350��6   $	��525��6)    � 	Resources 5      )   #George_s_Car_Rental.Classes.Globals   GlobalsClass��%   &	          5   
   6   5      .��5      � -   5        $��mainGrid��5       � ColumnDefinitions 5   
   �� 5      $��* �6    � RowDefinitions 5   
   �� 5      $��0.08* �6   �� 5      $��* �6   .+�5#   
   � $��0��6   $��0��6   $��0,10,0,0q�6,    5$      �� 5%      $��0.95* �6#   �� 5&      $��* �6#   �� 5'      $
��Auto �6#   .+�5+      ]� ��. $��0��6-   .+�5-      �� $��
Zip Code: ��6   $
��Left=�6.   $��Center=�6D   $��30(�6_   $
��Bold"�6m   $��5,0,0,0q�6   2   ,George_s_Car_Rental.CustomControls.SearchBox  5.      -   5          Name$ 	searchBox��5.   T   $��30(�6+   $��TimesNewRoman)�69   $��0,0,0,0q�6g   50      � 54      $��1��6   .+�55      �� $
��Auto=�6   $��0,0,5,0q�6O   .��56      �� 
���  ��$��Arial)�61   $
��Bold"�57      $
��Wrap=�6.   $��10,0,0,0q�6B   $��Center=�6T   ��56   D   ��  �� Source# [   �� Path$ errorMessage�57   T   58      59      �� 5<      -   5        $��2��5<       �� Orientation$ 
Horizontal=�6)   $��0,0,10,0q�6B    � Cursor$
 Hand��6T   	 � ToolTip$	 	Your Cart��6b   .+�5>      �� $#��Images/ShoppingCart_50x50.png��6   $��50��6?   $��50��6J   �� 5A      $��4,0,0,0q�6   
 �� CornerRadius$
 2��6*   
��� ���$��25��6O   ._�5B      �� 
�������$
��Wrap=�63   $��Center=�5C       $��Center=�6;   $��20(�6X   $��5,0,5,2q�6f   ��5B   G   �� # [  $ cartQuantity�5C   f   5D      5E      5G       � 5J   
   -   5          �Name$ 	mainFrame��5J   "   $��0,10,0,0q�6   $��1��65   $��0��6B     � NavigationUIVisibility$ Hidden=�6k   5L      5M      5N      