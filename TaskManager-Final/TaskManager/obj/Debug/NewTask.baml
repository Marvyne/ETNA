   M S B A M L   `   `   `  ����F  BTaskManager, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null)clr-namespace:TaskManagerTaskManager  5   	       TaskManager.NewTask   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   +localclr-namespace:TaskManager     5   	     � Title$  Nouvelle Tache��5   	   $	��300��6    $	��300��6-    � WindowStyle$ 
ToolWindow=�69   .��5	      � ��5
   
   �� 5       �� ImageSource$N Himg/minimalism-simple-simple-background-abstract-red-white-1920x1200.jpg��6    � ColumnDefinitions 5   
   �� 5      $	��42* �6   �� 5      $	��31* �6   .+�5   
   �� -   5         ��Name$ saveNewTask��5      $��Enregistrer��6&   $��	0,0,90,10q�6<   $��Right=�6O   $��75��6k   $��20��6v   $��Bottom=�6�   $��2��6�   $
��Bold"�6�   ��5      �� 5      $ 	img/r.png��6   5      �� 5   
   -   5        $ cancelNewTask��5      $��Annuler��6(   $��	0,0,10,10q�6:   $��20��6M   $��Bottom=�6Y   $��Right=�6t   $��75��6�   $��1��6�   $
��Bold"�6�   ��5      �� 5      $ 	img/r.png��6   5      �� 5   
   -   5         ��Name$ comment��5      $��10,64,10,35q�6'   $��2��6<   . �5      /� 5      (  "System.Windows.Controls.DatePicker  5   
   -   5        $��beginDatePicker��5      $
��Left=�6,   $��	10,35,0,0q�6G   $	��Top=�6Z   6r     5   
   -   5        $��endDatePicker��5      $��	12,35,0,0q�6*   $	��Top=�6=   $��1��6p   $
��Left=�6�   $	��102��6�   �� 5    
   -   5         ��Name$ beginDateText��5       $
��Left=�6+   $��	10,14,0,0q�6F   $
��Wrap=�6Y   $��Date de début��6m   $	��Top=�6�   $	��102��6�   �� 5!   
   -   5        $ endDateText��5!      $��	12,14,0,0q�6)   $
��Wrap=�6<   $��Date de fin��6P   $	��Top=�6c   $��1��6{   $
��Left=�6�   $	��102��6�   5#      5$      