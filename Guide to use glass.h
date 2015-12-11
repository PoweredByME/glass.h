
glass.h
Try every code like presented in the following example… you will grasp the basics of graphics and animation… It is a derived from glut so it contains the powers of glut…. You may use the codes and functions of glut too.
How to start the coding is the first activation barrier in the field of programming…. For glass do something like this.

#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Red");
}
void myDisplayFunction()
{
ScreenClear(); 


refreshScreen();
}



Well what is (int argc and char** argv). For now just consider it to be a requirement of syntax. These are required to project a graphics window on the screen.

Now, as per common sense the mainWindow function generates the main Window for you graphics. 
You just write the argc and argv as it is… they are mandatory.  What is 400 and 500, well 400 is the height of window and and 500 is the width of window and “Red”  this defines the color of window, background color I mean.











Now what the hell is void myDisplayFunction()

It is something mandatory, too. Is the function that is implicitly called by mainWindow function from main so you don’t have to call in main. It is the function in which you entire code will be written and displayed on the graphic screen. 

Notice: the display function is just like a loop that repeats itself as long as you program runs on the screen.It is called by the mainWindow  function 60times per second.  So whatever logic you make for your code…. Keep this point in you mind.
You will write the body of your code in between the ScreenClear() function and refreshScreen() function. They are mandatory too….. 


Here are the functions of glass till now… we will try to add more too. If you make some awesome to extend glass… feel free to add it to it with your name if you want.

Text (  x-coordinate, y-coordinate,  ”text string” , ”Color”, “Bold” )
Function is used to print text on screen. Takes 5 parameters . First 2 parameters are coordinates are x and y coordinates of screen which will define the starting point of text, 3 parameter is desired text , 4 parameter is color of text and 5 parameter is attribute to make text bold and it is not mandatory you can skip it as well. The code will be like.
x-coordinate, y-coordinate are the coordinated of the lower left corner of the text block.





FOR EXAMPLE :

#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Black");
}
void myDisplayFunction()
{
	ScreenClear();

Text(100, 100, "HELLO! Its me", "White", "Bold");
	
	refreshScreen();
}

	







See here the code Text(…..) is written in between the ScreenClear() and refreshScreen() functions.

CreateRectangle (x-coordinate, y-coordinate, height, length, ”color”, ”state”)
Function is used to create a rectangle on screen and takes 6 parameters . First 2 parameters are x and y coordinates of starting point of rectangle (you can use Pmotion_x as x coordinate and Pmotion_y as y coordinate to move rectangle with mouse pointer),next 2 parameters are dimensions of rectangle. You can add color in as next parameter (list of colors will be given below) and last parameter can be used to mention state (Filled or Hollow).
Here the x-coordinate, y-coordinate, are of the upperleft corner of the rectangle 
FOR EXAMPLE : 

#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Yellow");
}
void myDisplayFunction()
{
	ScreenClear();
	CreateRectangle(200, 300, 50, 100, "Blue", "Filled");
	refreshScreen();
}
Try it on your visual studio…… make some changes to see what happen, but beware of the syntax.
Also try this code too…. See what will happen if you use two functions.

#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Yellow");
}
void myDisplayFunction()
{
	ScreenClear();
Text(100, 100, "HELLO! Its me", "White", "Bold");	
CreateRectangle(200, 300, 50, 100, "Blue", "Filled");
	refreshScreen();
}

CreateCircle (x-coordinate, y-coordinate, radius, “Color”, “State”)
Function is used to create a circle on screen. First 2 parameters are x and y coordinate of center of  circle and 3 parameter defines its radius. Next parameter defines color (list of color is in the end) and last parameter is for state of circle( Filled or Hollow).
Here x and y coordinate are of the center of the circle.
FOR EXAMPLE : 
Try adding this code in the above code.
CreateCircle(150,150, 100, "Red", "Filled");


CreateCircle(150,150, 100, "Green", "Hollow");
 

CreateTriangle ( x1, y1, x2, y2, x3, y3, “color”, “state”)
Function is used to create a triangle and takes x and y coordinates of 3 vertices in first 6 parameters and next parameter defines color and last parameter is for state (Filled or Hollow).
x1, y1, x2, y2, x3, y3, the corrdinates of its three axes.   Use you sense of geometry to figure out the orientation of your triangle.
FOR EXAMPLE :
CreateTriangle(50, 50, 100, 150, 300, 20, "Yellow", "Filled");




DrawLine (x1, y1, x2, y2, “color”)
Function is used to draw a line on screen and takes x and y coordinates of end points of line as first 4 parameters and last parameter is to define color of line 
x1 and y1 are the coordinate of the first point of the line and the x2 and y2 are the coordinate of the final point of the line.

FOR EXAMPLE :
DrawLine(10, 30,90,120, "Yellow");




LIST of COLORS:

The colors you can use in glass.h right now.
•	Black
•	Red
•	Blue
•	Green
•	White
•	Yellow
•	Purple
•	Cyan
•	Orange 

Keyboard KEYS and Mouse Button
Glass.h has made it easier to work with keyboard keys and mouse . Each key you enter will store in “Keyboard” variable (in case of shift, Alt, Ctrl, key is stored in “ModKey” and in case of function keys, arrow keys, other keys, key is stored in “SpeacialKey”)  . To perform any task you can simply use Name of Key in quotation marks e.g ‘A’ in comparison with keyword “Keyboard” or “SpeacialKey” or “ModKey” , if same key on keyboard is pressed or released it will check and preform task if condition is true.  
SpeacialKeys:
  F1 ,   F2 ,    F3 ,    F4 ,  F5 ,  F6 ,  F7,  F8 , F9 ,  F10 ,  F11 ,  F12 ,   A_LEFT ,  A_RIGHT ,  A_UP ,  A_DOWN , PAGE_UP, PAGE_DOWN , HOME , END , INSERT
ModKeys:
CONTROL ,  ALT ,  SHIFT
MOUSE:
mouse_x                   (for x coordinate of mouse pointer) 
mouse_y                  (for y coordinate of mouse pointer)
mouse_s                   (for state of mouse button, PRESSED/RELEASED)
mouse_b                   (for button of mouse , LEFT/RIGHT)

The movements in glass.h.

Try using the code.
#include<glass.h>

int x = 100, y = 100;              //global variables.

void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Black");
}
void myDisplayFunction()
{
	ScreenClear();
	if (SpecialKey == A_UP)     //if the key UP is pressed then do.
		y -= 5;
	if (SpecialKey == A_DOWN)	//if the key DOWN is pressed then do.
		y += 5;
	if (SpecialKey == A_LEFT)	//if the key LEFT is pressed then do.
		x-= 5;
	if (SpecialKey == A_RIGHT) //if the key RIGHT is pressed then do.
		x += 5;

	SpecialKey = 0;                 //reinitiallization of special key.

	CreateCircle(x, y, 100, "Green", "Hollow");
	refreshScreen();
}
Run this code on your computer. Try pressing the arrow keys.
Try experimenting something:
>> try removing SpecialKey = 0, and see what will happen.
>> try removing ScreenClear() and see what will happen.
>>try removing both SpecialKey=0 and ScreenClear() at the same time and see what will happen. 
Try another code:
#include<glass.h>

int x = 100, y = 100;              //global variables.
int x1=200, y=200;         //global variables.
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Black");
}
void myDisplayFunction()
{
	ScreenClear();
	if (SpecialKey == A_UP)     //if the key UP is pressed then do.
		y -= 5;
	if (SpecialKey == A_DOWN)	//if the key DOWN is pressed then do.
		y += 5;
	if (SpecialKey == A_LEFT)	//if the key LEFT is pressed then do.
		x-= 5;
	if (SpecialKey == A_RIGHT) //if the key RIGHT is pressed then do.
		x += 5;

	SpecialKey = 0;                 //reinitiallization of special key.

	CreateCircle(x, y, 100, "Green", "Hollow");
	CreateRectangle(x1,y1,50,50, "Red", "Filled");	
    x1 += 1;
refreshScreen();
}
Try Experiment:
>> Try replacing x1 with y1
>> Try adding  y1+=1, below x1+=1;
>> Try changing the increment constant of x1 (x1+=5). 
>> try doing other experiments too.
Try this code:

#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Black");
}
void myDisplayFunction()
{
	CreateCircle(Pmotion_x, Pmotion_x, 100, "Green", "Hollow");
	refreshScreen();
}

Pmotion_x and Pmotion_y, are the built-in variables, they give the coordinate of the pointer of the mouse. Try moving your mouse cursor on your graphic screen.
#include<glass.h>
void main(int argc, char** argv)
{
		mainWindow(argc, argv, 400, 500, "Black");
}
void myDisplayFunction()
{
	CreateCircle(Amotion_x, Amotion_x, 100, "Green", "Hollow");
	refreshScreen();
}
Amotion_x and Amotion_y, are the built-in variables, they give the coordinate of the pointer of the mouse. Try left clicking on the figure you have created and while clicking move the pointer.


 

