# chbr
Two programs to change a laptop's screen brightness.  
Written with Qt using C++11.  

It's made for when your Linux distro doesn't manage to change the screen brightness.  
If it doesn't work try:  
- running as root  
- going to "mod/include/utils.h" and setting "fpath" to whatever file contains your screen brightness  
In "mod/include/utils.h" you can also set the minimum ("MIN_B") and maximum ("MAX_B") brightness that can be set.  

chbr is a console application.  
For further information run it with the "-h" option.  

chbrg is a GUI application.  
For further information run it with the "-h" option.