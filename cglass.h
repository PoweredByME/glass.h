//_____________________________________________Licence_______-----------------------------------------//

/*Copyright (c) 2015, PoweredByME

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.*/


// The library is made by  De'Burgers(PoweredByM.E.)//

// This code is Created by Ali Danish and Saad Ahmad. Students of NUST H-12 pakistan// 
//#define _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<mmsystem.h>
#include <glut.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>
#include <memory>
#include<iostream>
#define Image GLuint;
#define _CRT_SECURE_NO_DEPRECATEs
#define TGA_FILE_NOT_FOUND			13								// file was not found
#define TGA_BAD_IMAGE_TYPE			14								// color mapped image or image is not uncompressed
#define TGA_BAD_DIMENSION			15								// dimension is not a power of 2
#define TGA_BAD_BITS				16								// image bits is not 8, 24 or 32
#define TGA_BAD_DATA				17								// image data could not be loaded
#define M_PI 3.14159265358979323846f
#define LEFT  GLUT_LEFT_BUTTON
#define RIGHT GLUT_RIGHT_BUTTON
#define PRESSED GLUT_DOWN
#define RELEASED GLUT_UP
#define F1 GLUT_KEY_F1		
#define F2 GLUT_KEY_F2		
#define F3 GLUT_KEY_F3		
#define F4 GLUT_KEY_F4		
#define F5 GLUT_KEY_F5		
#define F6 GLUT_KEY_F6		
#define F7 GLUT_KEY_F7		
#define F8 GLUT_KEY_F8		
#define F9 GLUT_KEY_F9		
#define F10 GLUT_KEY_F10		
#define F11 GLUT_KEY_F11		
#define F12 GLUT_KEY_F12		
#define A_LEFT GLUT_KEY_LEFT		
#define A_RIGHT GLUT_KEY_RIGHT		
#define A_UP GLUT_KEY_UP		
#define A_DOWN GLUT_KEY_DOWN		
#define PAGE_UP GLUT_KEY_PAGE_UP	
#define PAGE_DOWN GLUT_KEY_PAGE_DOWN	
#define HOME GLUT_KEY_HOME		
#define END GLUT_KEY_END		
#define INSERT GLUT_KEY_INSERT
#define CONTROL GLUT_ACTIVE_CTRL
#define ALT GLUT_ACTIVE_ALT
#define SHIFT GLUT_ACTIVE_SHIFT
#define ENTER 13
void DisplayFunction();

namespace FundamentleGlass{

	

int __Ali_saad123 = 11;

//___________________________________________________________________________________________________________//
int g_Width = 400;		//define size of the window
int g_Height = 400;

//global mouse position
int mouse_x = 0;	//xcod
int mouse_y = 0;    //ycod
int mouse_s = 0;	//mouse state
int mouse_b = 0;	// mouse buttons

char Keyboard;				  //Keyboard key press detection
int Key = 0;				  //Key press detection
int SpecialKey = 0;			  //Special Key press detection 
int ModKey = 0;				  //ModKey detection


int Amotion_x = 0;
int Amotion_y = 0;
int Pmotion_x = 0;
int Pmotion_y = 0;
void init();
void MouseButtons(int button, int state, int mouseX, int mouseY);
void Amotion(int mouseX, int mouseY);
void Pmotion(int mouseX, int mouseY);
void myKeyboardFunction(unsigned char key, int mouseX, int mouseY);
void mySpecialKeysFunction(int key, int x, int y);
void myReshapeFunction(int width, int height);
void myTimerFunction(int val);


//_______________________________________________________________________________________________________________//

struct SpriteSheet {
	GLuint _imageID;
	double orignalHeight;
	double orignalWidth;
};

struct SpriteSlice {
	SpriteSheet spriteSheetID;
	double slice_origin_x;
	double slice_origin_y;
	double slice_height;
	double slice_width;
};


//_____________________________________________---Support functions---________________________________________?//

void ScreenClear() // to clear screen
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void ClearScreen() // to clear screen
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void _as___change(int a)
{
	__Ali_saad123 = a;
}

void SetFont(char* Font, char *size, char *c)
{
	if ((strcmp(Font, "Helvetica") == 0) && (strcmp(size, "Small") == 0))
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
	}
	else if (((strcmp(Font, "Helvetica") == 0) || (strcmp(Font, "timesNewRoman") == 0)) && (strcmp(size, "Medium") == 0))
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
	else if ((strcmp(Font, "Helvetica") == 0) && (strcmp(size, "Large") == 0))
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
	else if ((strcmp(Font, "timesNewRoman") == 0) && (strcmp(size, "Small") == 0))
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
	else if ((strcmp(Font, "timesNewRoman") == 0) && (strcmp(size, "Large") == 0))
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
	else
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}

void SetState(char *state) // for setting the state
{
	if (strcmp(state, "Filled") == 0)
		glBegin(GL_POLYGON);
	if (strcmp(state, "Hollow") == 0)
		glBegin(GL_LINE_STRIP);
}

void SetColor(char *color) // function to set color
{
	if (strcmp(color, "Black") == 0)
	{
		glColor3f(0.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Red") == 0)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Blue") == 0)
	{
		glColor3f(0.0, 0.0, 1.0);
	}
	else if (strcmp(color, "Green") == 0)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	else if (strcmp(color, "White") == 0)
	{
		glColor3f(1.0, 1.0, 1.0);
	}
	else if (strcmp(color, "Yellow") == 0)
	{
		glColor3f(1.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Purple") == 0)
	{
		glColor4f(1.0, 0.0, 1.0, 1.0);
	}
	else if (strcmp(color, "Cyan") == 0)
	{
		glColor3f(0.0, 1.0, 1.0);
	}
	else if (strcmp(color, "Orange") == 0)
	{
		glColor3f(1.0, 0.5, 0.0);
	}
	else if (strcmp(color, "DarkRed") == 0)
	{
		glColor4f(1.0, 0.0, 0.0, 0.9);
	}
	else if (strcmp(color, "GreenishYellow") == 0)
	{
		glColor3f(0.5, 1.0, 0.0);
	}
	else if (strcmp(color, "LightGreen") == 0)
	{
		glColor3f(0.5, 1.0, 0.5);
	}
	else if (strcmp(color, "DarkGreen") == 0)
	{
		glColor3f(0.0, 0.5, 0.0);
	}
	else if (strcmp(color, "Brown") == 0)
	{
		glColor3f(0.5, 0.35, 0.05);
	}
	else if (strcmp(color, "Grey") == 0)
	{
		glColor4f(0.8, 0.8, 0.8, 1.0);
	}
	else if (strcmp(color, "DarkGrey") == 0)
	{
		glColor4f(0.2, 0.2, 0.2, 1.0);
	}
	else if (strcmp(color, "Magenta") == 0)
	{
		glColor3f(1.0, 0.0, 1.0);
	}
	else
		glColor3f(0.0, 0.0, 0.0);
}

void init(void)
{
	//set (0,0) on left top
}


void SetCursor(char* CursorType)
{
	if (strcmp(CursorType, "RightArrow") == 0)
	{
		glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
	}
	else if (strcmp(CursorType, "LeftArrow") == 0)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
	else if (strcmp(CursorType, "InformationArrow") == 0)
	{
		glutSetCursor(GLUT_CURSOR_INFO);
	}
	else if (strcmp(CursorType, "QuestionMarkArrow") == 0)
	{
		glutSetCursor(GLUT_CURSOR_HELP);
	}
	else
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
}


void mainWindow(int argc, char**argv, char *windowName = "Glass", int height = 400, int width = 400, char *color = "Black", int WindowPosition_x = 0, int WindowPosition_y = 0, int RefreshRate = 11, char*CursorType = "RightArrow")
{


	glutInit(&argc, argv);		//initilize the GLUT libraray
	FreeConsole();
	_as___change(RefreshRate);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		//has four colour components red, green,blue, and alpha 
	glutInitWindowSize(width, height);	//size of window
	glutInitWindowPosition(WindowPosition_x, WindowPosition_y);		//poistion of window
	glutCreateWindow(windowName);

	if (strcmp(color, "Black") == 0)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Red") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Blue") == 0)
	{
		glClearColor(0.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Green") == 0)
	{
		glClearColor(0.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "White") == 0)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Yellow") == 0)
	{
		glClearColor(1.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Purple") == 0)
	{
		glClearColor(1.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Cyan") == 0)
	{
		glClearColor(0.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Orange") == 0)
	{
		glClearColor(1.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(color, "DarkRed") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.9);
	}
	else if (strcmp(color, "GreenishYellow") == 0)
	{
		glClearColor(0.5, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "LightGreen") == 0)
	{
		glClearColor(0.5, 1.0, 0.5, 0.0);
	}
	else if (strcmp(color, "DarkGreen") == 0)
	{
		glClearColor(0.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(color, "Brown") == 0)
	{
		glClearColor(0.5, 0.35, 0.05, 0.0);
	}
	else if (strcmp(color, "Grey") == 0)
	{
		glClearColor(0.8, 0.8, 0.8, 1.0);
	}
	else if (strcmp(color, "DarkGrey") == 0)
	{
		glClearColor(0.2, 0.2, 0.2, 1.0);
	}
	else if (strcmp(color, "Magenta") == 0)
	{
		glClearColor(1.0, 0.0, 1.0, 0.0);
	}
	else
		glClearColor(0.0, 0.0, 0.0, 0.0);		//background color of openGl window
												//			 ^red, green, blue, alpha(opens) 
	glMatrixMode(GL_PROJECTION);		//glMatrixMode — specify which matrix is the current matrix ????
	glLoadIdentity();		//glLoadIdentity — replace the current matrix with the identity matrix	????

	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);

	glutMouseFunc(MouseButtons);
	glutMotionFunc(Amotion);

	glutPassiveMotionFunc(Pmotion);
	glutKeyboardFunc(myKeyboardFunction);
	glutSpecialFunc(mySpecialKeysFunction);

	glutReshapeFunc(myReshapeFunction);
	glutDisplayFunc(DisplayFunction);
	glutTimerFunc(RefreshRate, myTimerFunction, 0);

	//	glutFullScreen();	// make the screen fullscreen
	SetCursor(CursorType);	//Displays the type of cursor u want
	glutMainLoop();

}

void mainWindowLoop(int argc, char**argv, char *windowName = "Glass", int height = 400, int width = 400, char *color = "Black", int WindowPosition_x = 0, int WindowPosition_y = 0, int RefreshRate = 11, char*CursorType = "RightArrow")
{


	glutInit(&argc, argv);		//initilize the GLUT libraray
	FreeConsole();
	_as___change(RefreshRate);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		//has four colour components red, green,blue, and alpha 
	glutInitWindowSize(width, height);	//size of window
	glutInitWindowPosition(WindowPosition_x, WindowPosition_y);		//poistion of window
	glutCreateWindow(windowName);

	if (strcmp(color, "Black") == 0)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Red") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Blue") == 0)
	{
		glClearColor(0.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Green") == 0)
	{
		glClearColor(0.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "White") == 0)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Yellow") == 0)
	{
		glClearColor(1.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "Purple") == 0)
	{
		glClearColor(1.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Cyan") == 0)
	{
		glClearColor(0.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(color, "Orange") == 0)
	{
		glClearColor(1.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(color, "DarkRed") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.9);
	}
	else if (strcmp(color, "GreenishYellow") == 0)
	{
		glClearColor(0.5, 1.0, 0.0, 0.0);
	}
	else if (strcmp(color, "LightGreen") == 0)
	{
		glClearColor(0.5, 1.0, 0.5, 0.0);
	}
	else if (strcmp(color, "DarkGreen") == 0)
	{
		glClearColor(0.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(color, "Brown") == 0)
	{
		glClearColor(0.5, 0.35, 0.05, 0.0);
	}
	else if (strcmp(color, "Grey") == 0)
	{
		glClearColor(0.8, 0.8, 0.8, 1.0);
	}
	else if (strcmp(color, "DarkGrey") == 0)
	{
		glClearColor(0.2, 0.2, 0.2, 1.0);
	}
	else if (strcmp(color, "Magenta") == 0)
	{
		glClearColor(1.0, 0.0, 1.0, 0.0);
	}
	else
		glClearColor(0.0, 0.0, 0.0, 0.0);		//background color of openGl window
												//			 ^red, green, blue, alpha(opens) 
	glMatrixMode(GL_PROJECTION);		//glMatrixMode — specify which matrix is the current matrix ????
	glLoadIdentity();		//glLoadIdentity — replace the current matrix with the identity matrix	????

	glOrtho(0.0, g_Width, 0.0, g_Height, -1.0, 1.0);

	glutMouseFunc(MouseButtons);
	glutMotionFunc(Amotion);

	glutPassiveMotionFunc(Pmotion);
	glutKeyboardFunc(myKeyboardFunction);
	glutSpecialFunc(mySpecialKeysFunction);

	glutReshapeFunc(myReshapeFunction);
	glutDisplayFunc(DisplayFunction);
	glutTimerFunc(RefreshRate, myTimerFunction, 0);

	//	glutFullScreen();	// make the screen fullscreen
	SetCursor(CursorType);	//Displays the type of cursor u want
}

void EndLoop()
{
	glutMainLoop();
}

void MainWindow(int argc, char**argv, char *windowName = "Glass", int height = 400, int width = 400, char *color = "Black", int WindowPosition_x = 0, int WindowPosition_y = 0, int RefreshRate = 11, char*CursorType = "RightArrow")
{
	mainWindow(argc, argv, windowName, height, width, color, WindowPosition_x, WindowPosition_y, RefreshRate, CursorType);
}

void MouseButtons(int button, int state, int mouseX, int mouseY)
{
	mouse_x = mouseX;
	mouse_y = mouseY;
	mouse_b = button;
	mouse_s = state;
}

void Amotion(int mouseX, int mouseY)
{
	Amotion_x = mouseX;
	Amotion_y = mouseY;
}

void Pmotion(int mouseX, int mouseY)
{
	Pmotion_x = mouseX;
	Pmotion_y = mouseY;
}

void myKeyboardFunction(unsigned char key, int mouseX, int mouseY)
{

	Keyboard = key;
	Key = (int)Keyboard;
	ModKey = glutGetModifiers();
}

void mySpecialKeysFunction(int key, int x, int y)
{
	SpecialKey = key;
	printf("special key is %d\n", SpecialKey);

}

void myReshapeFunction(int width, int height)
{
	glClear(GL_COLOR_BUFFER_BIT);

	g_Width = width;
	g_Height = height;

	glViewport(0, 0, g_Width, g_Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, g_Width, g_Height, 0.0, -1.0, 1.0);	//change the (0,0) to top left
}

void myTimerFunction(int val)
{
	glutTimerFunc(__Ali_saad123, myTimerFunction, 0);
	DisplayFunction();
}

int i = 0;


void RefreshScreen()
{
	glutSwapBuffers();
}
void refreshScreen()
{
	glutSwapBuffers();
}

//____________________________________---Support Functions---________________________________________//


//_______________________________-line -_____________________________________________________________________//

void DrawLine(double __x1, double __y1, double __x2, double __y2, char * color)
{
	glBegin(GL_LINES);
	SetColor(color);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glEnd();
}

void DrawLine(int __x1, int __y1, int __x2, int __y2, char * color)
{
	glBegin(GL_LINES);
	SetColor(color);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glEnd();
}

//_______________________________line_____________________________________________________________________----//


//_________________________________________Text_______________________________________________________--//

void Text(int x, int y, char *string, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{

	char *c;
	SetColor(color);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		SetFont(Font, size, c);
	}

	if (strcmp(style, "Underline") == 0)
	{
		DrawLine(x, y + 8, x + strlen(string) * 9, y + 8, color);
	}
	if (strcmp(style, "Bold") == 0)
	{
		Text(x + 1, y, string, color, Font, size);
	}

}

void Text(double x, double y, char *string, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{

	char *c;
	SetColor(color);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		SetFont(Font, size, c);
	}

	if (strcmp(style, "Underline") == 0)
	{
		DrawLine(x, y + 8, x + strlen(string) * 9, y + 8, color);
	}
	if (strcmp(style, "Bold") == 0)
	{
		Text(x + 1, y, string, color, Font, size);
	}

}

void Text(double x, double y, double text, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{
	char e[50];
	_snprintf_s(e, 50, "%f", text);
	Text(x, y, e, color, Font, size, style);
}

void Text(int x, int y, double text, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{
	char e[50];
	_snprintf_s(e, 50, "%f", text);
	Text(x, y, e, color, Font, size, style);
}

void Text(int x, int y, int text, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, color, Font, size, style);
}

void Text(double x, double y, int text, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, color, Font, size, style);
}

//__________________________________________________________Text________________________________________________//


//________________________Triangle______________________________________________________________________?//

void CreateTriangle(double __x1, double __y1, double __x2, double __y2, double __x3, double __y3, char * color = "Black", char * state = "Filled")
{
	SetState(state);
	SetColor(color);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
	glEnd();
}

void CreateTriangle(int __x1, int __y1, int __x2, int __y2, int __x3, int __y3, char * color = "Black", char * state = "Filled")
{
	SetState(state);
	SetColor(color);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
	glEnd();
}

//_____________________________Triangle__________________________________________________________________//

//__________________________________________RECTANGLE_____________________________________________________--//

void CreateRectangle(int x, int y, int height, int lenght, char * color = "Black", char * state = "Filled")
{
	SetState(state);
	SetColor(color);
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();
}

void CreateRectangle(double x, double y, double height, double lenght, char * color = "Black", char * state = "Filled")
{
	SetState(state);
	SetColor(color);
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();
}

void CreateRectangle(double x, double y, double height, double lenght, char * color, char * state, int LineThickness_inEvenNumber)
{
	float t = LineThickness_inEvenNumber;
	for (int c = t; c >= 0; c--)
	{
		float a = t / 2 + 2;
		SetState(state);
		SetColor(color);
		glVertex2f(x - a, y - a);
		glVertex2f(x - a + lenght + t, y - a);
		glVertex2f(x - a + lenght + t, y - a + height + t);
		glVertex2f(x - a, y - a + height + t);
		glVertex2f(x - a, y - a);
		t--;
		glEnd();
	}
}

void CreateRectangle(int x, int y, int height, int lenght, char * color, char * state, int LineThickness_inEvenNumber)
{
	float t = LineThickness_inEvenNumber;
	for (int c = t; c >= 0; c--)
	{
		float a = t / 2 + 2;
		SetState(state);
		SetColor(color);
		glVertex2f(x - a, y - a);
		glVertex2f(x - a + lenght + t, y - a);
		glVertex2f(x - a + lenght + t, y - a + height + t);
		glVertex2f(x - a, y - a + height + t);
		glVertex2f(x - a, y - a);
		t--;
		glEnd();
	}
}
//____________________________________________________________________________________RECTANGLE______?//

//________________________________________--ellipse__________________________________________________?//

void CreateEllipse(double origin_x, double origin_y, double max_height, double max_width, char * color = "Black", char * state = "Filled")
{
	double angle = 0;
	SetState(state);
	SetColor(color);
	glLineWidth(1.0f);
	for (int i = 0; i < 360; i++)
	{
		angle = i * 2 * M_PI / 180;
		glVertex2f(origin_x + (cos(angle) * max_width), origin_y + (sin(angle) * max_height));
	}
	glEnd();
}

void CreateEllipse(int origin_x, int origin_y, int max_height, int max_width, char * color = "Black", char * state = "Filled")
{
	double angle = 0;
	SetState(state);
	SetColor(color);
	glLineWidth(1.0f);
	for (int i = 0; i < 360; i++)
	{
		angle = i * 2 * M_PI / 180;
		glVertex2f(origin_x + (cos(angle) * max_width), origin_y + (sin(angle) * max_height));
	}
	glEnd();
}

void  CreateEllipse(double origin_x, double origin_y, double max_height, double max_width, char*color, char*state, int LineThickness)
{
	for (int c = 0; c <= LineThickness; c++)
	{
		CreateEllipse(origin_x, origin_y, max_height, max_width, color, state);
		max_height -= 0.5;
		max_width -= 0.5;
	}
}

//___________________________________________--ELLIPSE--_________________________________________________?//

//___________________________________________________________-circle-__________________________________//
void CreateCircle(int x, int y, int radius, char * color = "Black", char * state = "Filled") {
	float angle;
	SetState(state);
	SetColor(color);
	glLineWidth(1.0f);

	for (int i = 0; i < 120; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle + 5) * radius), y + (sin(angle + 5) * radius));
	}
	glEnd();
}

void CreateCircle(double x, double y, double radius, char * color = "Black", char * state = "Filled") {
	float angle;
	SetState(state);
	SetColor(color);
	glLineWidth(1.0f);

	for (int i = 0; i < 120; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle + 5) * radius), y + (sin(angle + 5) * radius));
	}
	glEnd();
}

void CreateCircle(double x, double y, double radius, char* color, char*state, int LineThickness)
{
	double r = radius;
	for (float c = 0; c <= 1 * LineThickness; c += 1)
	{
		CreateCircle(x, y, r, color, state);
		r -= 0.5;
	}
}

/////__________________________------circle------____________________________________________//

//_____________________----functionality for keyboard___________________________________________________//

void InputText(double x, double y, char* nameofstring, int sizeofstring, char* color = "Black", char* Font = "Helvetica", char* size = "Large")
{
	int a = strlen(nameofstring);
	char* stringText = (char*)calloc(sizeofstring + 1, 4);
	stringText = nameofstring;
	if (Keyboard == '\b')
	{
		strncpy_s(nameofstring, sizeofstring, stringText, (strlen(stringText) - 1));
	}

	if (a != sizeofstring - 1)
	{
		if (Keyboard == 'a')
			strcat_s(nameofstring, sizeofstring, "a");
		else if (Keyboard == 'b')
			strcat_s(nameofstring, sizeofstring, "b");
		else if (Keyboard == 'c')
			strcat_s(nameofstring, sizeofstring, "c");
		else if (Keyboard == 'd')
			strcat_s(nameofstring, sizeofstring, "d");
		else if (Keyboard == 'e')
			strcat_s(nameofstring, sizeofstring, "e");
		else if (Keyboard == 'f')
			strcat_s(nameofstring, sizeofstring, "f");
		else if (Keyboard == 'g')
			strcat_s(nameofstring, sizeofstring, "g");
		else if (Keyboard == 'h')
			strcat_s(nameofstring, sizeofstring, "h");
		else if (Keyboard == 'i')
			strcat_s(nameofstring, sizeofstring, "i");
		else if (Keyboard == 'j')
			strcat_s(nameofstring, sizeofstring, "j");
		else if (Keyboard == 'k')
			strcat_s(nameofstring, sizeofstring, "k");
		else if (Keyboard == 'l')
			strcat_s(nameofstring, sizeofstring, "l");
		else if (Keyboard == 'm')
			strcat_s(nameofstring, sizeofstring, "m");
		else if (Keyboard == 'n')
			strcat_s(nameofstring, sizeofstring, "n");
		else if (Keyboard == 'o')
			strcat_s(nameofstring, sizeofstring, "o");
		else if (Keyboard == 'p')
			strcat_s(nameofstring, sizeofstring, "p");
		else if (Keyboard == 'q')
			strcat_s(nameofstring, sizeofstring, "q");
		else if (Keyboard == 'r')
			strcat_s(nameofstring, sizeofstring, "r");
		else if (Keyboard == 's')
			strcat_s(nameofstring, sizeofstring, "s");
		else if (Keyboard == 't')
			strcat_s(nameofstring, sizeofstring, "t");
		else if (Keyboard == 'u')
			strcat_s(nameofstring, sizeofstring, "u");
		else if (Keyboard == 'v')
			strcat_s(nameofstring, sizeofstring, "v");
		else if (Keyboard == 'w')
			strcat_s(nameofstring, sizeofstring, "w");
		else if (Keyboard == 'x')
			strcat_s(nameofstring, sizeofstring, "x");
		else if (Keyboard == 'y')
			strcat_s(nameofstring, sizeofstring, "y");
		else if (Keyboard == 'z')
			strcat_s(nameofstring, sizeofstring, "z");
		else if (Keyboard == ' ')
			strcat_s(nameofstring, sizeofstring, " ");
		else if (Keyboard == 'A')
			strcat_s(nameofstring, sizeofstring, "A");
		else if (Keyboard == 'B')
			strcat_s(nameofstring, sizeofstring, "B");
		else if (Keyboard == 'C')
			strcat_s(nameofstring, sizeofstring, "C");
		else if (Keyboard == 'D')
			strcat_s(nameofstring, sizeofstring, "D");
		else if (Keyboard == 'E')
			strcat_s(nameofstring, sizeofstring, "E");
		else if (Keyboard == 'F')
			strcat_s(nameofstring, sizeofstring, "F");
		else if (Keyboard == 'G')
			strcat_s(nameofstring, sizeofstring, "G");
		else if (Keyboard == 'H')
			strcat_s(nameofstring, sizeofstring, "H");
		else if (Keyboard == 'I')
			strcat_s(nameofstring, sizeofstring, "I");
		else if (Keyboard == 'J')
			strcat_s(nameofstring, sizeofstring, "J");
		else if (Keyboard == 'K')
			strcat_s(nameofstring, sizeofstring, "K");
		else if (Keyboard == 'L')
			strcat_s(nameofstring, sizeofstring, "L");
		else if (Keyboard == 'M')
			strcat_s(nameofstring, sizeofstring, "M");
		else if (Keyboard == 'N')
			strcat_s(nameofstring, sizeofstring, "N");
		else if (Keyboard == 'O')
			strcat_s(nameofstring, sizeofstring, "O");
		else if (Keyboard == 'P')
			strcat_s(nameofstring, sizeofstring, "P");
		else if (Keyboard == 'Q')
			strcat_s(nameofstring, sizeofstring, "Q");
		else if (Keyboard == 'R')
			strcat_s(nameofstring, sizeofstring, "R");
		else if (Keyboard == 'S')
			strcat_s(nameofstring, sizeofstring, "S");
		else if (Keyboard == 'T')
			strcat_s(nameofstring, sizeofstring, "T");
		else if (Keyboard == 'U')
			strcat_s(nameofstring, sizeofstring, "U");
		else if (Keyboard == 'V')
			strcat_s(nameofstring, sizeofstring, "V");
		else if (Keyboard == 'W')
			strcat_s(nameofstring, sizeofstring, "W");
		else if (Keyboard == 'X')
			strcat_s(nameofstring, sizeofstring, "X");
		else if (Keyboard == 'Y')
			strcat_s(nameofstring, sizeofstring, "Y");
		else if (Keyboard == 'Z')
			strcat_s(nameofstring, sizeofstring, "Z");
		else if (Keyboard == '1')
			strcat_s(nameofstring, sizeofstring, "1");
		else if (Keyboard == '2')
			strcat_s(nameofstring, sizeofstring, "2");
		else if (Keyboard == '3')
			strcat_s(nameofstring, sizeofstring, "3");
		else if (Keyboard == '4')
			strcat_s(nameofstring, sizeofstring, "4");
		else if (Keyboard == '5')
			strcat_s(nameofstring, sizeofstring, "5");
		else if (Keyboard == '6')
			strcat_s(nameofstring, sizeofstring, "6");
		else if (Keyboard == '7')
			strcat_s(nameofstring, sizeofstring, "7");
		else if (Keyboard == '8')
			strcat_s(nameofstring, sizeofstring, "8");
		else if (Keyboard == '9')
			strcat_s(nameofstring, sizeofstring, "9");
		else if (Keyboard == '0')
			strcat_s(nameofstring, sizeofstring, "0");
		else if (Keyboard == '`')
			strcat_s(nameofstring, sizeofstring, "`");
		else if (Keyboard == '~')
			strcat_s(nameofstring, sizeofstring, "~");
		else if (Keyboard == '!')
			strcat_s(nameofstring, sizeofstring, "!");
		else if (Keyboard == '@')
			strcat_s(nameofstring, sizeofstring, "@");
		else if (Keyboard == '#')
			strcat_s(nameofstring, sizeofstring, "#");
		else if (Keyboard == '$')
			strcat_s(nameofstring, sizeofstring, "$");
		else if (Keyboard == '%')
			strcat_s(nameofstring, sizeofstring, "%");
		else if (Keyboard == '^')
			strcat_s(nameofstring, sizeofstring, "^");
		else if (Keyboard == '&')
			strcat_s(nameofstring, sizeofstring, "&");
		else if (Keyboard == '*')
			strcat_s(nameofstring, sizeofstring, "*");
		else if (Keyboard == '(')
			strcat_s(nameofstring, sizeofstring, "(");
		else if (Keyboard == ')')
			strcat_s(nameofstring, sizeofstring, ")");
		else if (Keyboard == '_')
			strcat_s(nameofstring, sizeofstring, "_");
		else if (Keyboard == '-')
			strcat_s(nameofstring, sizeofstring, "-");
		else if (Keyboard == '+')
			strcat_s(nameofstring, sizeofstring, "+");
		else if (Keyboard == '[')
			strcat_s(nameofstring, sizeofstring, "[");
		else if (Keyboard == ']')
			strcat_s(nameofstring, sizeofstring, "]");
		else if (Keyboard == '=')
			strcat_s(nameofstring, sizeofstring, "=");
		else if (Keyboard == '{')
			strcat_s(nameofstring, sizeofstring, "{");
		else if (Keyboard == '}')
			strcat_s(nameofstring, sizeofstring, "}");
		else if (Keyboard == '|')
			strcat_s(nameofstring, sizeofstring, "|");
		else if (Keyboard == '\\')
			strcat_s(nameofstring, sizeofstring, "\\");
		else if (Keyboard == ':')
			strcat_s(nameofstring, sizeofstring, ":");
		else if (Keyboard == ';')
			strcat_s(nameofstring, sizeofstring, ";");
		else if (Keyboard == '\'')
			strcat_s(nameofstring, sizeofstring, "\'");
		else if (Keyboard == '\"')
			strcat_s(nameofstring, sizeofstring, "\"");
		else if (Keyboard == ',')
			strcat_s(nameofstring, sizeofstring, ",");
		else if (Keyboard == '<')
			strcat_s(nameofstring, sizeofstring, "<");
		else if (Keyboard == '>')
			strcat_s(nameofstring, sizeofstring, ">");
		else if (Keyboard == '.')
			strcat_s(nameofstring, sizeofstring, ".");
		else if (Keyboard == '/')
			strcat_s(nameofstring, sizeofstring, "/");
		else if (Keyboard == '?')
			strcat_s(nameofstring, sizeofstring, "?");
	}

	Keyboard = 0;
	Text(x, y, nameofstring, color, Font, size);
}

//___________________________----function for keyboard---__________________________________________________??//

//______________________________shape_________________________________________________________________//

void StartShape(char*state = "Black", char*color = "Filled")
{
	SetState(state);
	SetColor(color);

}

void ShapeLine(double x1, double y1, double x2, double y2)
{
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
}

void ShapeCircle(double origin_x, double origin_y, double radius)
{
	double angle;
	double x = origin_x;
	double y = origin_y;
	glLineWidth(1.0f);

	for (int i = 0; i < 120; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle + 5) * radius), y + (sin(angle + 5) * radius));
	}
}
void ShapeCircle(int origin_x, int origin_y, int radius)
{
	double angle;
	double x = origin_x;
	double y = origin_y;
	glLineWidth(1.0f);

	for (int i = 0; i < 120; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle + 5) * radius), y + (sin(angle + 5) * radius));
	}
}

void ShapeEllipse(int origin_x, int origin_y, int max_height, int max_width)
{
	double angle = 0;
	glLineWidth(1.0f);
	for (int i = 0; i < 360; i++)
	{
		angle = i * 2 * M_PI / 180;
		glVertex2f(origin_x + (cos(angle) * max_width), origin_y + (sin(angle) * max_height));
	}
}

void ShapeEllipse(double origin_x, double origin_y, double max_height, double max_width)
{
	double angle = 0;
	glLineWidth(1.0f);
	for (int i = 0; i < 360; i++)
	{
		angle = i * 2 * M_PI / 180;
		glVertex2f(origin_x + (cos(angle) * max_width), origin_y + (sin(angle) * max_height));
	}
}

void ShapeRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	ShapeLine(x1, y1, x2, y2);
	ShapeLine(x2, y2, x3, y3);
	ShapeLine(x3, y3, x4, y4);
	ShapeLine(x4, y4, x1, y1);
}

void ShapeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	ShapeLine(x1, y1, x2, y2);
	ShapeLine(x2, y2, x3, y3);
	ShapeLine(x3, y3, x4, y4);
	ShapeLine(x4, y4, x1, y1);
}

void ShapeRectangle(double x, double y, double height, double lenght)
{
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
}

void ShapeRectangle(int x, int y, int height, int lenght)
{
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
}

void ShapeTriangle(int __x1, int __y1, int __x2, int __y2, int __x3, int __y3)
{
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
}

void ShapeTriangle(double __x1, double __y1, double __x2, double __y2, double __x3, double __y3)
{
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
}

void EndShape()
{
	glEnd();
}

//______________________________shape_________________________________________________________________//


//_________________________________-rectangle-____________________________________________________________-//
void CreateRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, char* color, char* state, unsigned int LineThickness_inEvenNumber)
{
	StartShape(state, color);
	float t = LineThickness_inEvenNumber;
	for (int c = t; c >= 0; c--)
	{
		float a = t / 2 + 2;
		

		t--;
		
	}
	}

void CreateRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, char* color, char* state)
{
	StartShape(state, color);
	ShapeLine(x1, y1, x2, y2);
	ShapeLine(x2, y2, x3, y3);
	ShapeLine(x3, y3, x4, y4);
	ShapeLine(x4, y4, x1, y1);
	EndShape();
}
// _________________________________-rectangle-____________________________________________________________-//

//__________________________________________Image______________________________________________________________________//

GLenum texFormat;													// texFormat
int loadTGA(char *name, int id);

// Load texture
GLuint LoadImage(char *name)
{
	GLuint temp;
	glGenTextures(1, &temp);
	loadTGA(name, temp);
	return temp;
}

// Background canvas
void ___123__draw(GLuint id, int x, int y, int wd, int ht)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glScalef(1, 1, 1);
	glColor4ub(255, 255, 255, 255);

	glBegin(GL_POLYGON);

	glTexCoord2f(0.0, 0.0);		glVertex2i(x, y + ht);
	glTexCoord2f(1.0, 0.0);		glVertex2f(x + wd, y + ht);
	glTexCoord2f(1.0, 1.0);		glVertex2f(x + wd, y);
	glTexCoord2f(0.0, 1.0);		glVertex2f(x, y);

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}

void ___123__draw(GLuint id, double x, double y, double wd, double ht)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glScalef(1, 1, 1);
	glColor4ub(255, 255, 255, 255);

	glBegin(GL_POLYGON);

	glTexCoord2f(0.0, 0.0);		glVertex2i(x, y + ht);
	glTexCoord2f(1.0, 0.0);		glVertex2f(x + wd, y + ht);
	glTexCoord2f(1.0, 1.0);		glVertex2f(x + wd, y);
	glTexCoord2f(0.0, 1.0);		glVertex2f(x, y);

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}


// checkSize: Make sure its a power of 2.
int checkSize(int x)
{
	if (x == 2 || x == 4 ||
		x == 8 || x == 16 ||
		x == 32 || x == 64 ||
		x == 128 || x == 256 || x == 512 || x == 1024)
		return 1;
	else return 0;
}

// getRGBA: Reads in RGBA data for a 32bit image.
unsigned char *getRGBA(FILE *s, int size)
{
	unsigned char *rgba;
	unsigned char temp;
	int bread;
	int i;

	rgba = (unsigned char*)malloc(size * 4);

	if (rgba == NULL)
		return 0;

	bread = fread(rgba, sizeof(unsigned char), size * 4, s);

	/* TGA is stored in BGRA, make it RGBA */
	if (bread != size * 4)
	{
		free(rgba);
		return 0;
	}

	for (i = 0; i < size * 4; i += 4)
	{
		temp = rgba[i];
		rgba[i] = rgba[i + 2];
		rgba[i + 2] = temp;
	}

	texFormat = GL_RGBA;
	return rgba;
}

// getRGB: Reads in RGB data for a 24bit image.
unsigned char *getRGB(FILE *s, int size)
{
	unsigned char *rgb;
	unsigned char temp;
	int bread;
	int i;

	rgb = (unsigned char *)malloc(size * 3);

	if (rgb == NULL)
		return 0;

	bread = fread(rgb, sizeof(unsigned char), size * 3, s);

	if (bread != size * 3)
	{
		free(rgb);
		return 0;
	}

	/* TGA is stored in BGR, make it RGB */
	for (i = 0; i < size * 3; i += 3)
	{
		temp = rgb[i];
		rgb[i] = rgb[i + 2];
		rgb[i + 2] = temp;
	}

	texFormat = GL_RGB;

	return rgb;
}

// getGray: Gets the grayscale image data.  Used as an alpha channel.
unsigned char *getGray(FILE *s, int size)
{
	unsigned char *grayData;
	int bread;

	grayData = (unsigned char *)malloc(size);

	if (grayData == NULL)
		return 0;

	bread = fread(grayData, sizeof(unsigned char), size, s);

	if (bread != size)
	{
		free(grayData);
		return 0;
	}

	texFormat = GL_ALPHA;

	return grayData;
}

// getData: Gets the image data for the specified bit depth.
char *getData(FILE *s, int sz, int iBits)
{
	if (iBits == 32)
		return (char*)getRGBA(s, sz);
	else if (iBits == 24)
		return (char*)getRGB(s, sz);
	else if (iBits == 8)
		return (char*)getGray(s, sz);
	else
		return 0;
}

// returnError: Called when there is an error loading the .tga file.
int returnError(FILE* s, int error)
{
	fclose(s);
	return error;
}


// loadTGA: Loads up a targa file.  Supported types are 8,24 and 32 uncompressed images.
int loadTGA(char *name, int id)
{
	unsigned char type[4];
	unsigned char info[7];
	unsigned char *imageData = NULL;
	int imageWidth, imageHeight;
	int imageBits, size;
	FILE *s;

	if (fopen_s(&s, name, "r+b"))
		return TGA_FILE_NOT_FOUND;

	fread(&type, sizeof(char), 3, s); // read in colormap info and image type, byte 0 ignored
	fseek(s, 12, SEEK_SET);			// seek past the header and useless info
	fread(&info, sizeof(char), 6, s);

	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
		returnError(s, TGA_BAD_IMAGE_TYPE);

	imageWidth = info[0] + info[1] * 256;
	imageHeight = info[2] + info[3] * 256;
	imageBits = info[4];

	size = imageWidth * imageHeight;

	/* make sure dimension is a power of 2 */
	if (!checkSize(imageWidth) || !checkSize(imageHeight))
		returnError(s, TGA_BAD_DIMENSION);

	/* make sure we are loading a supported type */
	if (imageBits != 32 && imageBits != 24 && imageBits != 8)
		returnError(s, TGA_BAD_BITS);

	imageData = (unsigned char*)getData(s, size, imageBits);

	/* no image data */
	if (imageData == NULL)
		returnError(s, TGA_BAD_DATA);

	fclose(s);

	glBindTexture(GL_TEXTURE_2D, id);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	/* glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	/*glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, texFormat, imageWidth, imageHeight, 0, texFormat, GL_UNSIGNED_BYTE, imageData);

	/* release data, its been uploaded */
	free(imageData);

	return 1;
}

void UploadImage(GLuint ImageID, int x, int y, int image_height, int image_width)    //display the image on the screen
{
	___123__draw(ImageID, x, y, image_width, image_height);
}

void UploadImage(GLuint ImageID, double x, double y, double image_height, double image_width)  // display the image on the screen
{
	___123__draw(ImageID, x, y, image_width, image_height);
}

void Animation(GLuint *imageArray, int imageArraySize, int origin_x, int origin_y, int imageHeight, int imageWidht, unsigned int _delayFrames = 3)   // animate an array of image indefinately... only for one animation display
{
	static int calls = 0;
	static int counter = 0;
	//static bool Returner = false;
	___123__draw(imageArray[counter], origin_x, origin_y, imageWidht, imageHeight);
	if (counter == ((imageArraySize)-1))
	{
		counter = 0; //Returner = true;
	}
	else if (calls%_delayFrames == 0)
	{
		counter++; //Returner = false;
	}
	if (calls == _delayFrames * 10)
		calls = 0;
	calls++;
}

bool MultiAnimation(GLuint *imageArray, int imageArraySize, double origin_x, double origin_y, double imageHeight, double imageWidht, unsigned int _delayFrames = 3, bool Reset = false)  //animate and array of images
{
	static int calls = 0;
	static int counter = 0;
	static bool Returner = false;
	if (Reset == true)
	{
		calls = 0; counter = 0; Returner = false;
	}
	___123__draw(imageArray[counter], origin_x, origin_y, imageWidht, imageHeight);
	if (counter == ((imageArraySize)-1))
	{
		counter = 0; Returner = true;
	}
	else if (calls%_delayFrames == 0)
	{
		counter++; Returner = false;
	}
	if (calls == _delayFrames * 10)
		calls = 0;
	calls++;
	if (Returner == true)
		return true;
	else
		return false;
}

bool MultiAnimation(GLuint *imageArray, int imageArraySize, int origin_x, int origin_y, int imageHeight, int imageWidht, unsigned int _delayFrames = 3, bool Reset = false)   //Animate an array of images.
{
	static int calls = 0;
	static int counter = 0;
	static bool Returner = false;
	if (Reset == true)
	{
		calls = 0; counter = 0; Returner = false;
	}
	___123__draw(imageArray[counter], origin_x, origin_y, imageWidht, imageHeight);
	if (counter == ((imageArraySize)-1))
	{
		counter = 0; Returner = true;
	}
	else if (calls%_delayFrames == 0)
	{
		counter++; Returner = false;
	}
	if (calls == _delayFrames * 10)
		calls = 0;
	calls++;
	if (Returner == true)
		return true;
	else
		return false;
}
//-------------------------------------Constructors --------------------------------------------------//

SpriteSheet LoadSheet(GLuint imageID, int imageOrignalHeight, int imageOrignalWidth)
{
	SpriteSheet *holder = (SpriteSheet*)malloc(sizeof(struct SpriteSheet));
	if (holder != NULL)
	{
		holder->_imageID = imageID;
		holder->orignalHeight = imageOrignalHeight;
		holder->orignalWidth = imageOrignalWidth;
		return (*holder);
	}
	else
		return (*holder);
}

SpriteSlice LoadSlice(SpriteSheet sprite_Sheet_ID, double pos_x, double pos_y, double slice_height, double slice_width)// makes the sprite sheet in user defined slices.
{
	SpriteSlice* holder = (SpriteSlice*)malloc(sizeof(struct SpriteSlice));
	if (holder != NULL)
	{
		holder->spriteSheetID = sprite_Sheet_ID;
		holder->slice_origin_x = pos_x;
		holder->slice_origin_y = pos_y;
		holder->slice_height = slice_height;
		holder->slice_width = slice_width;
		return (*holder);
	}
	else
		return (*holder);
}

//_________________________________________________________________________________________________________________//
void ___123__draw1(GLuint id, double pos_x, double pos_y, double bh, double bw, double x, double y, double ht, double wd)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glScalef(1, 1, 1);
	glColor4ub(255, 255, 255, 255);

	glBegin(GL_POLYGON);

	glTexCoord2f(pos_x, pos_y);            glVertex2f(x, y + ht);
	glTexCoord2f(pos_x + bw, pos_y);		glVertex2f(x + wd, y + ht);
	glTexCoord2f(pos_x + bw, pos_y + bh);		glVertex2f(x + wd, y);
	glTexCoord2f(pos_x, pos_y + bh);			glVertex2i(x, y);

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}
//_________________________________________________________________________________________________________//
bool MultiAnimation(SpriteSlice *SliceArray, int SliceArraySize, double display_x, double display_y, double display_height, double display_Width, unsigned int _delayFrame = 1, bool Reset = false)// Animate the SpriteSlice array.
{
	static int counter = 0;
	static int calls = 0;
	static bool Returner = false;
	if (Reset == true)
	{
		counter = 0; calls = 0; Returner = false;
	}
	else;

	SpriteSlice s = SliceArray[counter];
	SpriteSheet a = s.spriteSheetID;
	GLuint _Image = a._imageID;
	double orignal_h = a.orignalHeight;
	double orignal_w = a.orignalWidth;
	double slice_x1 = s.slice_origin_x;
	double slice_y1 = s.slice_origin_y;
	double slice_h1 = s.slice_height;
	double slice_w1 = s.slice_width;
	double slice_x = slice_x1 / orignal_w;
	double slice_y = slice_y1 / orignal_h;
	double slice_h = slice_h1 / orignal_h;
	double slice_w = slice_w1 / orignal_w;
	___123__draw1(_Image, slice_x, slice_y, slice_h, slice_w, display_x, display_y, display_height, display_Width);

	if (counter == (SliceArraySize - 1))
	{
		counter = 0; Returner = true;
	}
	else if (calls%_delayFrame == 0)
	{
		counter++; Returner = false;
	}
	else;

	if (calls == _delayFrame * 10)
		calls = 0;
	else
		calls++;
	if (Returner == true)
		return true;
	else
		return false;
}

bool MultiAnimation(SpriteSlice *SliceArray, int SliceArraySize, int display_x, int display_y, int display_height, int display_Width, unsigned int _delayFrame = 1, bool Reset = false)// Animate the SpriteSlice array.
{
	static int counter = 0;
	static int calls = 0;
	static bool Returner = false;
	if (Reset == true)
	{
		counter = 0; calls = 0; Returner = false;
	}
	else;

	SpriteSlice s = SliceArray[counter];
	SpriteSheet a = s.spriteSheetID;
	GLuint _Image = a._imageID;
	double orignal_h = a.orignalHeight;
	double orignal_w = a.orignalWidth;
	double slice_x1 = s.slice_origin_x;
	double slice_y1 = s.slice_origin_y;
	double slice_h1 = s.slice_height;
	double slice_w1 = s.slice_width;
	double slice_x = slice_x1 / orignal_w;
	double slice_y = slice_y1 / orignal_h;
	double slice_h = slice_h1 / orignal_h;
	double slice_w = slice_w1 / orignal_w;
	___123__draw1(_Image, slice_x, slice_y, slice_h, slice_w, display_x, display_y, display_height, display_Width);

	if (counter == (SliceArraySize - 1))
	{
		counter = 0; Returner = true;
	}
	else if (calls%_delayFrame == 0)
	{
		counter++; Returner = false;
	}
	else;

	if (calls == _delayFrame * 10)
		calls = 0;
	else
		calls++;
	if (Returner == true)
		return true;
	else
 		return false;
}

void Fullscreen()
{
	glutFullScreen();
}

}     //end of fundamentle glass namespace

//________________________________________________________________________________________________________________?/


namespace ObjectiveGlass {        //the objective glass start.

	using namespace FundamentleGlass;

	class Shape {

	protected: //atibutes
		double origin_x = 0;                     //origin_x of the shape
		double origin_y = 0;                     //origin_y of the shape  
		double givenHeight = 0;                  //In case of rectangle height
		double givenWidth = 0;                   //in case of rectangle width
		double givenRadius = 0;                  //In case of circle 
		unsigned int givenThickness = 1;         //In case of hollow shapes the thickness of lines
		char* givenColor = "Red";                //Shapes colors
		char* givenState = "Filled";             //States of the colors
		double speedx = 0;                       //movement speeds of the shapes along x
		double speedy = 0;                       //movement speed of the shape  along y
		bool FirstCall = false;                  //For first call for the shape makers function.
		double axis_X = 0;                       //The axis X for the rotation of the shape
		double axis_Y = 0;                       //The axis Y for the rotation of the shape
		bool RotateCall = false; bool RevolveCall = false;       //Revolve and rotate first call noters 
	
	public:                       //Public Functions
		virtual void Move(double x, double y) = 0;    //Function for movement of shape
		//virtual void Rotate(double angle) = 0;        //Function for Angle rotation of a shape
		//virtual void Rotate(double inLine_axis_X, double inLine_axis_Y, double angle) = 0; // -do-
		//virtual void Revolve(double outLine_axis_X, double outLine_axis_Y, double angle) = 0;
	                           //Function to revolve a shape around an axis out side the shape.
	}; 

	class LINE : Shape
	{                      //A line class inherited form base class shape.

	private:
		double lx1 = 0, ly1 = 0, lx2 = 0, ly2 = 0;   //Private points of the line
		double LineRadius = 0;                 //Line Center to end distance.
		double TotalLenght = 0;
		void mover()    //function for movement.
		{
			lx1 += speedx; ly1 += speedy;
			lx2 += speedx; ly2 += speedy;
			origin_x += speedx; origin_y += speedy;
			axis_X += speedx; axis_Y += speedy;
		}

		void MeasureRadius()    //Function to measure line radius.
		{
			double r = pow((lx1 - origin_x), 2) + pow((ly1 - origin_y), 2);
			LineRadius = sqrt(r);
		}

	public:      //Public characteristics.
		~LINE() {
			lx1 = 0; lx2 = 0; ly1 = 0; ly2 = 0; LineRadius = 0;
			origin_x = 0; origin_y = 0; speedx = 0; speedy = 0;
			axis_X = 0; axis_Y = 0; givenColor = "Red";
			givenState = "Filled", givenThickness = 1;
			FirstCall = false; RevolveCall = false; RotateCall = false;
		};
		LINE() {    //Defualt constructor.
			lx1 = 0; lx2 = 0; ly1 = 0; ly2 = 0; LineRadius = 0;
			origin_x = 0; origin_y = 0; speedx = 0; speedy = 0;
			axis_X = 0; axis_Y = 0; givenColor = "Red";
			givenState = "Filled", givenThickness = 1;
			FirstCall = false; RevolveCall = false; RotateCall = false;
		}

		void Draw(double LineCenter_x, double LineCenter_y, double Lenght, char*Color = "Red", unsigned int LineThickness = 1)
		{
			if (FirstCall == false) {    //When the call is first...
				origin_x = LineCenter_x;
				origin_y = LineCenter_y;
				lx1 = LineCenter_x + Lenght / 2;
				ly1 = LineCenter_y;
				lx2 = LineCenter_x - Lenght / 2;
				ly2 = LineCenter_y;
				TotalLenght = Lenght;
				FirstCall = true;
			}
			else;
			mover();
			glLineWidth(LineThickness);
			DrawLine(lx2, ly2, lx1, ly1, Color);
		}  //End line

		   // Line 
		void Draw(double x, double y, double x1, double y1, char*Color = "Red", unsigned int LineThickness = 1)
		{
			//static bool FirstCall = false;
			double totalLenght = 0;
			if (FirstCall == false) {    //When the call is first...
				lx1 = x;
				ly1 = y;
				lx2 = x1;
				ly2 = y1;
				totalLenght = pow((x - x1), 2) + pow((y - y1), 2);
				totalLenght = sqrt(totalLenght);
				TotalLenght = totalLenght;
				origin_x = (x + x1) / 2;
				origin_y = (y + y1) / 2;
				FirstCall = true;
			}
			else;
			mover();
			Draw(origin_x, origin_y, totalLenght, Color, LineThickness);
		}  //End line

		//Function to rotate from the center
		void Rotate(double angle)
		{
			double radian = angle*M_PI / 180;
			MeasureRadius();
			lx1 = origin_x + LineRadius*cos(M_PI + radian);
			ly1 = origin_y + LineRadius*sin(M_PI + radian);
			lx2 = origin_x + LineRadius*cos(radian);
			ly2 = origin_y + LineRadius*sin(radian);
		}//End

		// Function to rotate the line from any inline axis
		void Rotate(double inLine_axis_X, double inLine_axis_Y, double angle)
		{
			if (RotateCall == false)
			{
				axis_X = inLine_axis_X; axis_Y = inLine_axis_Y;  // For the first call.
				RotateCall = true;
			}
			double radian = angle*M_PI / 180;
			double lineRadius = pow((axis_X - lx1), 2) + pow((axis_Y - ly1), 2);
			lineRadius = sqrt(lineRadius);
			double lineRadius1 = pow((axis_X - lx2), 2) + pow((axis_Y - ly2), 2);
			lineRadius1 = sqrt(lineRadius1);
			lx1 = axis_X + lineRadius*cos(M_PI + radian);
			ly1 = axis_Y + lineRadius*sin(M_PI + radian);   // MATHS FOR ROTATION
			lx2 = axis_X + lineRadius1*cos(radian);
			ly2 = axis_Y + lineRadius1*sin(radian);

		}//End

		//Function to revolve the line around a centeral point
		void Revolve(double outLine_axis_X, double outLine_axis_Y, double angle)
		{
			if (RevolveCall == false) {
				axis_X = outLine_axis_X; axis_Y = outLine_axis_Y;
			}
			else;
			double radian = angle*M_PI / 180;
			double OrigintoAxes = sqrt(pow((axis_X - origin_x), 2) + pow((axis_Y - origin_y), 2));

			origin_x = axis_X - OrigintoAxes* cos(radian);
			origin_y = axis_Y - OrigintoAxes* sin(radian);

			lx1 = origin_x + TotalLenght / 2;
			ly1 = origin_y;
			lx2 = origin_x - TotalLenght / 2;
			ly2 = origin_y;

			double radian1 = (angle - 30)*M_PI / 180;
			radian1 += 90;
			MeasureRadius();
			lx1 = origin_x + LineRadius*cos(M_PI + radian1);
			ly1 = origin_y + LineRadius*sin(M_PI + radian1);
			lx2 = origin_x + LineRadius*cos(radian1);
			ly2 = origin_y + LineRadius*sin(radian1);

		}//END

		void Revolve(double outLine_axis_X, double outLine_axis_Y, double Revolve_Angle, double Spin_Angle)
		{
			double angle = Revolve_Angle;
			double Orientation_Angle = Spin_Angle;
			if (RevolveCall == false) {
				axis_X = outLine_axis_X; axis_Y = outLine_axis_Y;
			}
			else;
			double radian = angle*M_PI / 180;
			double OrigintoAxes = sqrt(pow((axis_X - origin_x), 2) + pow((axis_Y - origin_y), 2));

			origin_x = axis_X - OrigintoAxes* cos(radian);
			origin_y = axis_Y - OrigintoAxes* sin(radian);

			lx1 = origin_x + TotalLenght / 2;
			ly1 = origin_y;
			lx2 = origin_x - TotalLenght / 2;
			ly2 = origin_y;

			double radian1 = (Orientation_Angle)*M_PI / 180;
			radian1 += 90;
			MeasureRadius();
			lx1 = origin_x + LineRadius*cos(M_PI + radian1);
			ly1 = origin_y + LineRadius*sin(M_PI + radian1);
			lx2 = origin_x + LineRadius*cos(radian1);
			ly2 = origin_y + LineRadius*sin(radian1);

		}//END

		 // Interface for mover.
		void Move(double x, double y)
		{
			speedx = x;
			speedy = y;
		}
		//END

		// Interface of dynamic lenght chager
		void ChangeLenght(double Lenght)
		{
			lx1 = origin_x + Lenght / 2;
			ly1 = origin_y;
			lx2 = origin_x - Lenght / 2;
			ly2 = origin_y;
			TotalLenght = Lenght;
		}
		//END

		double GetCenter_x() { return origin_x; }
		double GetCenter_y() { return origin_y; }
		double GetPoint_x1(){return lx1;}
		double GetPoint_y1() { return ly1; }
		double GetPoint_x2() { return lx2; }
		double GetPoint_y2() { return ly2; }

	};     //END class LINE.

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	class CIRCLE : Shape    //  Circle Object
	{
	private:
	  
		void mover()       //mover function for shape
		{
			origin_x += speedx; origin_y += speedy;
			axis_X += speedx; axis_Y += speedy;
		}

	public:
		~CIRCLE() {
			origin_x = 0; origin_y = 0; givenColor = "Red";
			givenState = "Filled"; givenThickness = 1; givenRadius = 0;
			speedx = 0; speedy = 0; axis_X = 0; axis_Y = 0;
			FirstCall = false;
		};
		CIRCLE()      //Constructor
		{ 
			origin_x = 0; origin_y = 0; givenColor = "Red";
			givenState = "Filled"; givenThickness = 1; givenRadius = 0;
			speedx = 0; speedy = 0; axis_X = 0; axis_Y = 0;
			FirstCall = false;
		}     //END

		void Draw(double x, double y, double radius, char* color = "Red", char* state = "Filled", unsigned int LineThickness = 1)    // Function to draw the Circle.
		{
			if (FirstCall == false)   //When there is a first call.
			{
				FirstCall = true;
				origin_x = x; origin_y = y; givenRadius = radius;
				givenColor = color; givenState = state; givenThickness = LineThickness;
			}
			else;
			mover();
			CreateCircle(origin_x, origin_y, givenRadius, givenColor, givenState, givenThickness);
		}    // END draw function.

		void Move(double x, double y)    //Movement for shape.
		{
			speedx = x; speedy = y;
		}                //
		void Revolve(double x, double y, double angle)    //Revolve function
		{
			axis_X = x;
			axis_Y = y;
			double LineDistance = pow((origin_x-axis_X), 2) + pow((origin_y-axis_Y), 2);
			LineDistance = sqrt(LineDistance);
			double radian = angle*M_PI / 180;
			origin_x = axis_X + LineDistance*cos(radian);
			origin_y = axis_Y + LineDistance*sin(radian);
		}   //End function 




	};    //END CIRCLE CLASS.


	////////////////////////////////////////////////////////////////////////////////////////////////////////



	class RECTANGLE : Shape
	{
	private:
		double UpperLeft_x = 0, UpperLeft_y=0,UpperRight_x=0,UpperRight_y=0;
		double LowerLeft_x = 0, LowerLeft_y = 0, LowerRight_x = 0, LowerRight_y = 0;
		double ULR = 0, URR = 0, LLR = 0, LRR = 0;
		double givenAngle;
		bool DrawCall = false;

		void Maker1()
		{
			glLineWidth(givenThickness / 1.5);
				SetState(givenState);
				SetColor(givenColor);
				glVertex2f(UpperLeft_x , UpperLeft_y );
				glVertex2f(UpperRight_x , UpperRight_y );
				glVertex2f(LowerRight_x , LowerRight_y );
				glVertex2f(LowerLeft_x , LowerLeft_y );
				glVertex2f(UpperLeft_x , UpperLeft_y );
				glEnd();
			
		}

		void mover()
		{
		    origin_x += speedx; origin_y += speedy; 
			UpperLeft_x += speedx; UpperLeft_y += speedy;
			UpperRight_x += speedx; UpperRight_y += speedy;
			LowerLeft_x += speedx; LowerLeft_y += speedy;
			LowerRight_x += speedx; LowerRight_y += speedy;
			axis_X += speedx; axis_Y += speedy;
		}

		void sqRotate(double angle) {
			double radian = -1 * angle * M_PI / 180;
             
			double pangle = atan((givenHeight / 2) / (givenWidth / 2))*180/M_PI;

			double multi = pangle / 180;

			UpperLeft_x = origin_x - ULR*cos(M_PI + (3*multi*M_PI) + radian);
			UpperLeft_y = origin_y + ULR*sin(M_PI + (3*multi*M_PI) + radian);

			UpperRight_x = origin_x + URR * cos((9*multi*M_PI) + radian);
			UpperRight_y = origin_y - URR * sin((9*multi*M_PI) + radian);

			LowerLeft_x = origin_x - LLR * cos((7*multi*M_PI) - radian);
			LowerLeft_y = origin_y - LLR * sin((7*multi*M_PI) - radian);

			LowerRight_x = origin_x + LRR * cos((15*multi*M_PI) + radian);
			LowerRight_y = origin_y - LRR * sin((15*multi*M_PI) + radian);
		}

		void reRotate(double angle) {
		   	double radian = -1 * angle * M_PI / 180;
        	double pangle = atan((givenHeight / 2) / (givenWidth / 2)) * 180 / M_PI;
        	double multi = pangle / 180;

			UpperLeft_x = origin_x + ULR*cos( (M_PI) + radian- pangle*M_PI/180);
			UpperLeft_y = origin_y - ULR*sin( (M_PI) + radian - pangle*M_PI / 180);

			UpperRight_x = origin_x + URR * cos((1 * multi*M_PI) + radian);
			UpperRight_y = origin_y - URR * sin((1 * multi*M_PI) + radian);

		    LowerLeft_x = origin_x - LLR * cos((-1* multi*M_PI) - radian);
     		LowerLeft_y = origin_y - LLR * sin((-1* multi*M_PI) - radian);

			LowerRight_x = origin_x + LRR * cos(radian-pangle*M_PI/180);
			LowerRight_y = origin_y - LRR * sin(radian-pangle*M_PI/180);
        }

		bool isRectangle = true;

	public:
		
		RECTANGLE() 
		{
			UpperLeft_x = 0;
			UpperLeft_y = 0;
			givenHeight = 0;
			givenWidth = 0;
			givenColor = "Red";
			givenState = "Filled";
			givenThickness = 1;
			origin_x = 0;
			origin_y = 0;
			LowerLeft_x = 0; LowerLeft_y = 0; LowerRight_x = 0; LowerRight_y = 0;
			UpperRight_x = 0; UpperRight_y = 0;
			DrawCall = false;
		}


		void Draw(double upperLeft_x, double upperLeft_y, double height, double width, char* color = "Red", char* state = "Filled", unsigned int LineThickness = 1)
		{
		
		if(DrawCall == false)
		{
			if (height == width)
			{
				isRectangle = false;
			}
			UpperLeft_x = upperLeft_x;
			UpperLeft_y = upperLeft_y;
			givenHeight = height;
			givenWidth = width;
			givenColor = color;
			givenState = state;
			givenThickness = LineThickness;
			origin_x = upperLeft_x + width / 2;
			origin_y = upperLeft_y + height / 2;
			DrawCall = true;
			UpperRight_x = UpperLeft_x + givenWidth;
			UpperRight_y = UpperLeft_y;
			LowerLeft_x = UpperLeft_x;
			LowerLeft_y = UpperLeft_y + givenHeight;
			LowerRight_x = UpperLeft_x + givenWidth;
			LowerRight_y = UpperLeft_y + givenHeight;
			ULR = sqrt(pow((origin_x - UpperLeft_x), 2) + pow((origin_y - UpperLeft_y), 2));
			URR = sqrt(pow((origin_x - UpperRight_x), 2) + pow((origin_y - UpperRight_y), 2));
			LLR = sqrt(pow((origin_x - LowerLeft_x), 2) + pow((origin_y - LowerLeft_y), 2));
			LRR = sqrt(pow((origin_x - LowerRight_x), 2) + pow((origin_y - LowerRight_y), 2));
		
		}
		    mover();
			Maker1();
		
        }

		void Move(double x, double y) {
			speedx = x;
			speedy = y;
		}

		void Rotate(double angle)
		{
			if (isRectangle == false)
			{
				sqRotate(angle);
			}
			else {
				reRotate(angle);
			}
		}

     	double GetCenter_x() { return origin_x; }
		double GetCenter_y() { return origin_y; }
		double GetUpperLeft_x() { return UpperLeft_x; }
		double GetUpperLeft_y() { return UpperLeft_y; }
		double GetUpperRight_x() { return UpperRight_x; }
		double GetUpperRight_y() { return UpperRight_y; }
		double GetLowerLeft_x() {return LowerLeft_x;}
		double GetLowerLeft_y() { return LowerLeft_y; }
		double GetLowerRight_x() { return LowerRight_x; }
		double GetLowerRight_y() { return LowerRight_y; }
	};

}    //END NAMESPACE OBJECTIVEGLASS
