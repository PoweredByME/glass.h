#pragma once
#pragma once
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
#include<string>
void myDisplayFunction();

using namespace std;

namespace FundamentleGlass
{
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

	bool Bool______123456__efo__ufo__saadi__aliboy__showChonsole = false;

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

	void ShowConsole()
	{
		Bool______123456__efo__ufo__saadi__aliboy__showChonsole = true;
	}

	void ScreenClear() // to clear screen
	{
		//mouse_x = 0;
		//mouse_y = 0;
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void ClearScreen() // to clear screen
	{
		//mouse_x = 0;
		//mouse_y = 0;
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
		if (!Bool______123456__efo__ufo__saadi__aliboy__showChonsole)
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
		glutDisplayFunc(myDisplayFunction);
		glutTimerFunc(RefreshRate, myTimerFunction, 0);

		//	glutFullScreen();	// make the screen fullscreen
		SetCursor(CursorType);	//Displays the type of cursor u want
		glutMainLoop();

	}



	void mainWindowLoop(int argc, char**argv, char *windowName = "Glass", int height = 400, int width = 400, char *color = "Black", int WindowPosition_x = 0, int WindowPosition_y = 0, int RefreshRate = 11, char*CursorType = "RightArrow")
	{


		glutInit(&argc, argv);		//initilize the GLUT libraray
		if (!Bool______123456__efo__ufo__saadi__aliboy__showChonsole)
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
		glutDisplayFunc(myDisplayFunction);
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
		myDisplayFunction();
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

	void Text12(double x, double y, char *string, char *color = "Black", char* Font = "Helvetica", char*size = "Large", char *style = "NULL")
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
	void CreateRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, char* color, char* state)
	{
		StartShape(state, color);
		ShapeLine(x1, y1, x2, y2);
		ShapeLine(x2, y2, x3, y3);
		ShapeLine(x3, y3, x4, y4);
		ShapeLine(x4, y4, x1, y1);
		EndShape();
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

}



//////////////////////////////////// The Objective Glass////////////////////////////////////////////////////////////////////////////


namespace ObjectiveGlass
{
	using namespace FundamentleGlass;
	class shape     // an interface class for all the other objects of the cglass
	{
	public:
		virtual void Draw() = 0;
		virtual void Move(double x, double y) = 0;
		virtual void Rotate(double angleInDegree) = 0;
		virtual void UseMouse(int x, int y) {};
	protected:
		double getPathagorus(double X1, double Y1, double X2, double Y2)
		{
			return (sqrt((pow((X1 - X2), 2) + pow((Y1 - Y2), 2))));
		}
		double getAngle(double X1, double Y1, double X2, double Y2)
		{
			return (atan((Y1 - Y2) / (X1 - X2)));
		}
	};

	class line : public shape
	{
	private:
		double CenterX, CenterY, Lenght, Radius, End1X, End1Y, End2Y, End2X;
		double MoveX, MoveY, rotateAngle, edgeX, edgeY, rex, rey, slope;
		string color;
		unsigned int thickness;
		bool usingMouse;
		void CalculateLenght()
		{
			Lenght = sqrt((pow((End1X - End2X), 2) + pow((End1Y - End2Y), 2)));
		}

		void CalculateRadius()
		{
			Radius = sqrt((pow((CenterX - End2X), 2) + pow((CenterY - End2Y), 2)));
		}

		void CalculateCenter()
		{
			CenterX = (End1X + End2X) / 2;
			CenterY = (End1Y + End2Y) / 2;
		}

		void MoveProcess()
		{
			CenterX += MoveX;
			CenterY += MoveY;
			getSlopeAngle();
			End1X = CenterX + (Lenght / 2)*cos(M_PI + slope);
			End1Y = CenterY + (Lenght / 2)*sin(M_PI + slope);   // MATHS FOR ROTATION
			End2X = CenterX + (Lenght / 2)*cos(slope);
			End2Y = CenterY + (Lenght / 2)*sin(slope);

		}

		void RotateProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			End1X = CenterX + Radius * cos(M_PI + radian);
			End1Y = CenterY + Radius * sin(M_PI + radian);
			End2X = CenterX + Radius * cos(radian);
			End2Y = CenterY + Radius * sin(radian);
		}

		void EdgeRotateProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			double radius1 = getPathagorus(edgeX, edgeY, End1X, End1Y);
			double radius2 = getPathagorus(edgeX, edgeY, End2X, End2Y);
			End1X = edgeX + radius1 * cos(M_PI + radian);
			End1Y = edgeY + radius1 * sin(M_PI + radian);
			End2X = edgeX + radius2 * cos(radian);
			End2Y = edgeY + radius2 * sin(radian);

		}

		bool firstCall;
		double an1, an2;
		void RevolveProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			double radius1 = getPathagorus(rex, rey, End1X, End1Y);
			double radius2 = getPathagorus(rex, rey, End2X, End2Y);
			if (!firstCall)
			{
				an1 = atan((rey - End1Y) / (rex - End1X));
				an2 = atan((rey - End2Y) / (rex - End2X));
				firstCall = true;
			}
			End1X = rex + radius1 * cos(radian + an1);
			End1Y = rey + radius1 * sin(radian + an1);
			End2X = rex + radius2 * cos(radian + an2);
			End2Y = rey + radius2 * sin(radian + an2);
		}

		void MouseProcess()
		{
			getSlopeAngle();
			End1X = CenterX + (Lenght / 2)*cos(M_PI + slope);
			End1Y = CenterY + (Lenght / 2)*sin(M_PI + slope);   // MATHS FOR ROTATION
			End2X = CenterX + (Lenght / 2)*cos(slope);
			End2Y = CenterY + (Lenght / 2)*sin(slope);
		}

		void ProcessChange()
		{
			this->Lenght = Lenght;
			this->thickness = thickness;
			Radius = this->Lenght / 2;
			End1X = CenterX - Radius;
			End2X = CenterX + Radius;
			End1Y = CenterY; End2Y = CenterY;
		}
	public:

		line() {
			color = "Red";
		}
		line(double originX, double originY, double Lenght, string theColor = "Red", unsigned int thickness = 1)
		{
			firstCall = false;
			usingMouse = false;
			CenterX = originX;
			CenterY = originY;
			this->Lenght = Lenght;
			color = theColor;
			this->thickness = thickness;
			Radius = this->Lenght / 2;
			End1X = CenterX - Radius;
			End2X = CenterX + Radius;
			End1Y = CenterY; End2Y = CenterY;
		}

		line(double X1, double Y1, double X2, double Y2, string theColor = "Red", unsigned int thickness = 1)
		{
			firstCall = false;
			usingMouse = false;
			End1X = X1;
			End1Y = Y1;
			End2X = X2;
			End2Y = Y2;
			this->thickness = thickness;
			this->color = theColor;
			CalculateCenter();
			CalculateLenght();
			CalculateRadius();
		}

		void Draw()
		{
			CalculateCenter();
			CalculateLenght();
			CalculateRadius();
			char * theColor = const_cast<char*>(color.c_str());;
			glLineWidth(thickness);
			DrawLine(End1X, End1Y, End2X, End2Y, theColor);
		}

		void Move(double x, double y) {
			MoveX = x; MoveY = y;
			MoveProcess();
		}

		void Rotate(double angleInDegree) {
			rotateAngle = -1 * angleInDegree;
			RotateProcess();
		}

		void Rotate(double X, double Y, double angleInDegree)
		{
			if (!usingMouse) {
				edgeX = X;
				edgeY = Y;
				rotateAngle = -1 * angleInDegree;
				EdgeRotateProcess();
			}
			else
				Rotate(angleInDegree);
		}

		void Revolve(double X, double Y, double angleInDegree)
		{
			if (!usingMouse) {
				rex = X;
				rey = Y;
				rotateAngle = -1 * angleInDegree;
				RevolveProcess();
			}
			else
				Rotate(angleInDegree);
		}

		void UseMouse(int mouse_x = Pmotion_x, int mouse_y = Pmotion_y)
		{
			usingMouse = true;
			CenterX = mouse_x;
			CenterY = mouse_y;
			MouseProcess();
		}

		double getSlopeAngle()
		{
			slope = atan((End1Y - End2Y) / (End1X - End2X));
			return slope;
		}

		double getX1() { return End1X; }
		double getY1() { return End1Y; }
		double getX2() { return End2X; }
		double getY2() { return End2Y; }
		double getCenterX() { return CenterX; }
		double getCenterY() { return CenterY; }
		double getLength() { return Lenght; }
		string getColor() { return color; }
		unsigned int getThickness() { return thickness; }
		void setX1(double X) { End1X = X; }
		void setY1(double Y) { End1Y = Y; }
		void setX2(double X) { End2X = X; }
		void setY2(double Y) { End2Y = Y; }
		void setCenterX(double X) { CenterX = X; }
		void setCenterY(double Y) { CenterY = Y; }
		void setColor(string color = "Red") { this->color = color; }
		void setThickness(unsigned int thick = 1) { this->thickness = thick; }
		void setLength(double lenght)
		{
			Lenght = lenght;
			ProcessChange();
		}
	};   //end class line






	class rectangle : public shape
	{
	private:
		double CenterX, CenterY, UpperLeftX, UpperLeftY, UpperRightX, UpperRightY;
		double LowerLeftX, LowerLeftY, LowerRightX, LowerRightY, ULRadius, URRadius, LLRadius, LRRadius;
		double height, width, rx, ry, rex, rey;
		double ULLRSlope, URLLSlope, rotateAngle;
		string color, state;
		unsigned int thickness;
		bool usingMouse;
		struct RadiusAtPoint
		{
			double ULRadius1, URRadius1, LLRadius1, LRRadius1;
		};
		struct Slopes
		{
			double ULLRSlope, URLLSlope;
		};
		Slopes slope;
		RadiusAtPoint r;

		void calculateCenter()
		{
			CenterX = (LowerLeftX + LowerRightX + UpperRightX + UpperLeftX) / 4;
			CenterY = (LowerLeftY + LowerRightY + UpperRightY + UpperLeftY) / 4;
		}

		void calculateRadius()
		{
			ULRadius = getPathagorus(CenterX, CenterY, UpperLeftX, UpperLeftY);
			LLRadius = getPathagorus(CenterX, CenterY, LowerLeftX, LowerLeftY);
			URRadius = getPathagorus(CenterX, CenterY, UpperRightX, UpperRightY);
			LRRadius = getPathagorus(CenterX, CenterY, LowerRightX, LowerRightY);
		}

		void CalculateRadiusFromPoint(double CenterX1, double CenterY1)
		{
			r.ULRadius1 = getPathagorus(CenterX1, CenterY1, UpperLeftX, UpperLeftY);
			r.LLRadius1 = getPathagorus(CenterX1, CenterY1, LowerLeftX, LowerLeftY);
			r.URRadius1 = getPathagorus(CenterX1, CenterY1, UpperRightX, UpperRightY);
			r.LRRadius1 = getPathagorus(CenterX1, CenterY1, LowerRightX, LowerRightY);
		}


		void getSlope()
		{
			ULLRSlope = atan((UpperLeftY - LowerRightY) / (UpperLeftX - LowerRightX));
			URLLSlope = atan((UpperRightY - LowerLeftY) / (UpperRightX - LowerLeftX));
		}

		void getSlope1()
		{
			slope.ULLRSlope = atan((UpperLeftY - LowerRightY) / (UpperLeftX - LowerRightX));
			slope.URLLSlope = atan((UpperRightY - LowerLeftY) / (UpperRightX - LowerLeftX));
		}

		void MoveProcess()
		{
			UpperLeftX = CenterX + ULRadius*cos(M_PI + slope.ULLRSlope);
			UpperLeftY = CenterY + ULRadius*sin(M_PI + slope.ULLRSlope);
			LowerRightX = CenterX + LRRadius*cos(slope.ULLRSlope);
			LowerRightY = CenterY + LRRadius*sin(slope.ULLRSlope);
			UpperRightX = CenterX + URRadius*cos(slope.URLLSlope);
			UpperRightY = CenterY + URRadius*sin(slope.URLLSlope);
			LowerLeftX = CenterX + LLRadius*cos(M_PI + slope.URLLSlope);
			LowerLeftY = CenterY + LLRadius*sin(M_PI + slope.URLLSlope);
		}

		void RotateProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			UpperLeftX = CenterX - ULRadius*cos(ULLRSlope + radian);
			UpperLeftY = CenterY - ULRadius*sin(ULLRSlope + radian);
			LowerRightX = CenterX + LRRadius*cos(ULLRSlope + radian);
			LowerRightY = CenterY + LRRadius*sin(ULLRSlope + radian);
			UpperRightX = CenterX + URRadius*cos(URLLSlope + radian);
			UpperRightY = CenterY + URRadius*sin(URLLSlope + radian);
			LowerLeftX = CenterX + LLRadius*cos(M_PI + URLLSlope + radian);
			LowerLeftY = CenterY + LLRadius*sin(M_PI + URLLSlope + radian);
		}

		void MouseProcess()
		{
			getSlope1();
			UpperLeftX = CenterX + ULRadius*cos(M_PI + slope.ULLRSlope);
			UpperLeftY = CenterY + ULRadius*sin(M_PI + slope.ULLRSlope);
			LowerRightX = CenterX + LRRadius*cos(slope.ULLRSlope);
			LowerRightY = CenterY + LRRadius*sin(slope.ULLRSlope);
			UpperRightX = CenterX + URRadius*cos(slope.URLLSlope);
			UpperRightY = CenterY + URRadius*sin(slope.URLLSlope);
			LowerLeftX = CenterX + LLRadius*cos(M_PI + slope.URLLSlope);
			LowerLeftY = CenterY + LLRadius*sin(M_PI + slope.URLLSlope);
		}

		bool firstCall;
		double thetaULR, thetaURR, thetaLLR, thetaLRR, thetaOAR;
		double ulr, urr, llr, lrr, oar;

		void EdgeRotateProcess()
		{
			double radian = rotateAngle * M_PI / 180;

			if (firstCall == false) {

				//distances...
				ulr = sqrt(pow(rx - UpperLeftX, 2) + pow(ry - UpperLeftY, 2));
				urr = sqrt(pow(rx - UpperRightX, 2) + pow(ry - UpperRightY, 2));
				llr = sqrt(pow(rx - LowerLeftX, 2) + pow(ry - LowerLeftY, 2));
				lrr = sqrt(pow(rx - LowerRightX, 2) + pow(ry - LowerRightY, 2));
				oar = sqrt(pow(rx - CenterX, 2) + pow(ry - CenterY, 2));
				//distances...
				//angles

				if (ulr != 0)
				{
					thetaULR = -1 * atan((UpperLeftY - ry) / (UpperLeftX - rx));
					if (!(rx == UpperLeftX || ry == UpperLeftY)) {      // FOR THE AXIS DIRECTLY OPPSITE TO THE GIVEN AXIS
						thetaULR = -1 * thetaULR;
					}
				}
				else;
				if (urr != 0)
				{
					thetaURR = -1 * atan((UpperRightY - ry) / (UpperRightX - rx));
				}
				else;
				if (llr != 0)
				{
					thetaLLR = -1 * atan((LowerLeftY - ry) / (LowerLeftX - rx));
					if (!(rx == LowerLeftX || ry == LowerLeftY))
					{
						thetaLLR = -1 * thetaLLR;
					}
				}
				else;
				if (lrr != 0)
				{
					thetaLRR = atan((LowerRightY - ry) / (LowerRightX - rx));
				}
				if (oar != 0)
				{
					thetaOAR = atan((CenterY - ry) / (CenterX - rx));
				}
				firstCall = true;
			}

			UpperLeftX = rx + ulr * cos(M_PI + thetaULR - radian);      //Calculation of translated axes
			UpperLeftY = ry + ulr * sin(M_PI - radian + thetaULR);
			UpperRightX = rx + urr * cos(thetaURR + radian);
			UpperRightY = ry + urr * sin(M_PI + thetaURR + radian);
			LowerRightX = rx + lrr * cos(thetaLRR - radian);
			LowerRightY = ry + lrr * sin(thetaLRR - radian);
			LowerLeftX = rx + llr * cos(M_PI + thetaLLR - radian);
			LowerLeftY = ry + llr * sin(M_PI + thetaLLR - radian);
			CenterX = rx + oar* cos(thetaOAR - radian);
			CenterY = ry + oar* sin(thetaOAR - radian);
		}
		bool RotateCall;
		void RevolveProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			radian = M_PI + radian;
			double axis_X = rex;
			double axis_Y = rey;

			if (RotateCall == false) {

				//distances...
				ulr = sqrt(pow(axis_X - UpperLeftX, 2) + pow(axis_Y - UpperLeftY, 2));
				urr = sqrt(pow(axis_X - UpperRightX, 2) + pow(axis_Y - UpperRightY, 2));
				llr = sqrt(pow(axis_X - LowerLeftX, 2) + pow(axis_Y - LowerLeftY, 2));
				lrr = sqrt(pow(axis_X - LowerRightX, 2) + pow(axis_Y - LowerRightY, 2));
				oar = sqrt(pow(axis_X - CenterX, 2) + pow(axis_Y - CenterY, 2));
				//distances...
				//angles

				if (ulr != 0)
				{
					thetaULR = -1 * atan((UpperLeftY - axis_Y) / (UpperLeftX - axis_X));
					if (!(axis_X == UpperLeftX || axis_Y == UpperLeftY)) {      // FOR THE AXIS DIRECTLY OPPSITE TO THE GIVEN AXIS
						thetaULR = -1 * thetaULR;
					}
				}
				else;
				if (urr != 0)
				{
					thetaURR = -1 * atan((UpperRightY - axis_Y) / (UpperRightX - axis_X));
				}
				else;
				if (llr != 0)
				{
					thetaLLR = -1 * atan((LowerLeftY - axis_Y) / (LowerLeftX - axis_X));
					if (!(axis_X == LowerLeftX || axis_Y == LowerLeftY))
					{
						thetaLLR = -1 * thetaLLR;
					}
				}
				else;
				if (lrr != 0)
				{
					thetaLRR = atan((LowerRightY - axis_Y) / (LowerRightY - axis_X));
				}
				if (oar != 0)
				{
					thetaOAR = atan((CenterY - axis_Y) / (CenterX - axis_X));
				}
				RotateCall = true;
			}


			UpperLeftX = axis_X + ulr * cos(M_PI + thetaULR - radian);      //Calculation of translated axes
			UpperLeftY = axis_Y + ulr * sin(M_PI - radian + thetaULR);
			UpperRightX = axis_X + urr * cos(M_PI + thetaURR + radian);
			UpperRightY = axis_Y + urr * sin(thetaURR + radian);
			LowerRightX = axis_X + lrr * cos(M_PI + thetaLRR - radian);
			LowerRightY = axis_Y + lrr * sin(M_PI + thetaLRR - radian);
			LowerLeftX = axis_X + llr * cos(M_PI + thetaLLR - radian);
			LowerLeftY = axis_Y + llr * sin(M_PI + thetaLLR - radian);
			CenterX = axis_X + oar* cos(thetaOAR - radian);
			CenterY = axis_Y + oar* sin(thetaOAR - radian);


		}

		void ProcessChange()
		{
			UpperRightX = UpperLeftX + (this->width);
			UpperRightY = UpperLeftY;
			LowerRightX = UpperRightX;
			LowerRightY = UpperRightY + this->height;
			LowerLeftX = UpperLeftX;
			LowerLeftY = UpperLeftY + this->height;
			calculateCenter();
			calculateRadius();
			this->color = color;
			this->state = state;
			this->thickness = thickness;
		}

	public:
		rectangle() {}
		rectangle(double UpperLeft_x, double UpperLeft_y, double height, double width, string color = "Red", string state = "Filled", unsigned int thickness = 1)
		{
			UpperLeftX = UpperLeft_x;
			UpperLeftY = UpperLeft_y;
			this->height = height;
			this->width = width;
			UpperRightX = UpperLeftX + (this->width);
			UpperRightY = UpperLeftY;
			LowerRightX = UpperRightX;
			LowerRightY = UpperRightY + this->height;
			LowerLeftX = UpperLeftX;
			LowerLeftY = UpperLeftY + this->height;
			calculateCenter();
			calculateRadius();
			this->color = color;
			this->state = state;
			this->thickness = thickness;
			getSlope();
			firstCall = false;
			usingMouse = false;
			RotateCall = false;
		}

		void Draw()
		{
			char * col = const_cast<char*>(color.c_str());
			char * stat = const_cast<char*>(state.c_str());
			getSlope1();
			glLineWidth(thickness / 1.5);
			SetState(stat);
			SetColor(col);
			glVertex2f(UpperLeftX, UpperLeftY);
			glVertex2f(UpperRightX, UpperRightY);
			glVertex2f(LowerRightX, LowerRightY);
			glVertex2f(LowerLeftX, LowerLeftY);
			glVertex2f(UpperLeftX, UpperLeftY);
			glEnd();
		}

		void Move(double x, double y) {
			CenterX += x;
			CenterY += y;
			//MoveProcess();
			RotateProcess();
		}

		void Rotate(double angleInDegree)
		{
			rotateAngle = -1 * angleInDegree;
			RotateProcess();
		}

		void UseMouse(int mouse_x, int mouse_y)
		{
			usingMouse = true;
			CenterX = mouse_x;
			CenterY = mouse_y;
			MouseProcess();
		}

		void Rotate(double X, double Y, double angleInDegree)
		{
			if (!usingMouse) {
				rx = X;
				ry = Y;
				rotateAngle = 1 * angleInDegree;
				EdgeRotateProcess();
			}
			else
				Rotate(angleInDegree);
		}

		void Revolve(double X, double Y, double angleIndegree)
		{
			if (!usingMouse)
			{
				rex = X;
				rey = Y;
				rotateAngle = 1 * angleIndegree;
				RevolveProcess();
			}
			else
				Rotate(angleIndegree);
		}

		bool ifMouseHover()
		{
			return (Pmotion_x >= UpperLeftX && Pmotion_x <= UpperRightX && Pmotion_y >= UpperLeftY && Pmotion_y <= LowerLeftY);
		}

		double getUpperLeftX() { return UpperLeftX; }
		double getUpperLeftY() { return UpperLeftY; }
		double getLowerLeftX() { return LowerLeftX; }
		double getLowerLeftY() { return LowerLeftY; }
		double getUpperRightX() { return UpperRightX; }
		double getUpperRightY() { return UpperRightY; }
		double getLowerRightX() { return LowerRightX; }
		double getLowerRightY() { return LowerRightY; }
		double getCenterX() { return CenterX; }
		double getCenterY() { return CenterY; }
		void setUpperLeftX(double X) {
			UpperLeftX = X;
			LowerLeftX = X;
			width = sqrt((pow(UpperLeftX - UpperRightX, 2)) + (pow(UpperLeftY - UpperRightY, 2)));
		}
		void setUpperLeftY(double Y)
		{
			UpperLeftY = Y;
			UpperRightY = Y;
			height = sqrt((pow(UpperLeftX - LowerLeftX, 2)) + (pow(UpperLeftY - LowerLeftY, 2)));
		}
		void setHeight(double height) {
			this->height = height;
			ProcessChange();
		}
		void setWidth(double width)
		{
			this->width = width;
			ProcessChange();
		}
		void setColor(string color)
		{
			this->color = color;
			ProcessChange();
		}
		void setState(string state)
		{
			this->state = state;
			ProcessChange();
		}
		void setThickness(unsigned int thickeness)
		{
			this->thickness = thickeness;
			ProcessChange();
		}
	};

	class circle : public shape
	{
	private:
		double centerX, centerY, radius, rotateAngle, an;
		string color, state;
		unsigned int thickness;
		bool firstCall;
	public:
		circle() {}
		circle(double originX, double originY, double radius, string color = "Red", string state = "Filled", unsigned int thickness = 1)
		{
			firstCall = false;
			centerX = originX;
			centerY = originY;
			this->radius = radius;
			this->color = color;
			this->state = state;
			this->thickness = thickness;
		}

		void Draw()
		{
			char * col = const_cast<char*>(color.c_str());
			char * stat = const_cast<char*>(state.c_str());
			CreateCircle(centerX, centerY, radius, col, stat, thickness);
		}

		void Move(double X, double Y)
		{
			centerX += X;
			centerY += Y;
		}

		void Rotate(double angleInDegree) {}

		void Revolve(double X, double Y, double angleInDegree)
		{
			rotateAngle = -1 * angleInDegree * M_PI / 180;
			double pr = getPathagorus(X, Y, centerX, centerY);
			if (!firstCall)
			{
				an = atan((centerY - Y) / (centerX - X));
				firstCall = true;
			}
			centerX = X + pr * cos(rotateAngle + an);
			centerY = Y + pr * sin(rotateAngle + an);
		}

		double getCenterX() { return centerX; }
		double getCenterY() { return centerY; }
		void setCenterX(double X) { centerX = X; }
		void setCenterY(double Y) { centerY = Y; }
		double getRadius() { return radius; }
		string getColor() { return color; }
		string getState() { return state; }
		void setColor(string theColor) { color = theColor; }
		void setState(string theState) { state = theState; }
		void setThickness(unsigned int theThickness) { thickness = theThickness; }
		unsigned int getThickness() { return thickness; }
	};//end circle class

	class text
	{
	private:
		string TheText, Text1;
		string color;
		string state;
		string size;
		string font;
		string fontSize;
		double originX, originY;
		char *c, *f, *fs, *s;

		void ProcessChange()
		{
			c = const_cast<char*>(color.c_str());
			f = const_cast<char*>(font.c_str());
			fs = const_cast<char*>(fontSize.c_str());
			s = const_cast<char*>(state.c_str());
		}

	public:
		text() {}
		text(double LowerLeftX, double LowerLeftY, string color = "Red")
		{
			TheText = "";
			Text1 = "";
			originX = LowerLeftX;
			originY = LowerLeftY;
			this->color = color;
			this->font = "Helvetica";
			this->fontSize = "Large";
			this->state = "Normal";
			s = const_cast<char*>(state.c_str());
			c = const_cast<char*>(this->color.c_str());
			f = const_cast<char*>(font.c_str());
			fs = const_cast<char*>(fontSize.c_str());
		}

		void Write(string text)
		{
			TheText = text;
			char * t = const_cast<char*>(TheText.c_str());
			Text(originX, originY, t, c, f, fs, s);
		}

		void Write(double text)
		{
			Text(originX, originY, text, c, f, fs, s);
		}

		void Write(int text)
		{
			Text(originX, originY, text, c, f, fs, s);
		}

		void setColor(string theColor)
		{
			color = theColor;
			ProcessChange();
		}

		void setFont_Helvetica()
		{
			font = "Helvetica";
			ProcessChange();
		}

		void setFont_TimesNewRoman()
		{
			font = "timesNewRoman";
			ProcessChange();
		}

		void setFont_Bold()
		{
			state = "Bold";
			ProcessChange();
		}

		void setFont_Normal()
		{
			state = "Normal";
			ProcessChange();
		}
		void Move(double X, double Y)
		{
			originX += X;
			originY += Y;
		}

		void UseMouse(int x, int y)
		{
			originX = x;
			originY = y;
		}

		void setFontSize_Small()
		{
			fontSize = "Small";
			ProcessChange();
		}

		void setFontSize_Medium()
		{
			fontSize = "Medium";
			ProcessChange();
		}

		void setFontSize_Large()
		{
			fontSize = "Large";
			ProcessChange();
		}

		string Read()
		{
			string Text = Text1;
			if (Keyboard == '\b' && Text.length() != 0)
			{
				char * s = const_cast<char*>(Text.c_str());
				strncpy_s(s, Text.length(), s, (Text.length() - 1));
				string nt = string(s);
				Text = nt;
			}

			if (Keyboard == 'a')
				Text += "a";
			else if (Keyboard == 'b')
				Text += "b";
			else if (Keyboard == 'c')
				Text += "c";
			else if (Keyboard == 'd')
				Text += "d";
			else if (Keyboard == 'e')
				Text += "e";
			else if (Keyboard == 'f')
				Text += "f";
			else if (Keyboard == 'g')
				Text += "g";
			else if (Keyboard == 'h')
				Text += "h";
			else if (Keyboard == 'i')
				Text += "i";
			else if (Keyboard == 'j')
				Text += "j";
			else if (Keyboard == 'k')
				Text += "k";
			else if (Keyboard == 'l')
				Text += "l";
			else if (Keyboard == 'm')
				Text += "m";
			else if (Keyboard == 'n')
				Text += "n";
			else if (Keyboard == 'o')
				Text += "o";
			else if (Keyboard == 'p')
				Text += "p";
			else if (Keyboard == 'q')
				Text += "q";
			else if (Keyboard == 'r')
				Text += "r";
			else if (Keyboard == 's')
				Text += "s";
			else if (Keyboard == 't')
				Text += "t";
			else if (Keyboard == 'u')
				Text += "u";
			else if (Keyboard == 'v')
				Text += "v";
			else if (Keyboard == 'w')
				Text += "w";
			else if (Keyboard == 'x')
				Text += "x";
			else if (Keyboard == 'y')
				Text += "y";
			else if (Keyboard == 'z')
				Text += "z";
			else if (Keyboard == ' ')
				Text += " ";
			else if (Keyboard == 'A')
				Text += "A";
			else if (Keyboard == 'B')
				Text += "B";
			else if (Keyboard == 'C')
				Text += "C";
			else if (Keyboard == 'D')
				Text += "D";
			else if (Keyboard == 'E')
				Text += "E";
			else if (Keyboard == 'F')
				Text += "F";
			else if (Keyboard == 'G')
				Text += "G";
			else if (Keyboard == 'H')
				Text += "H";
			else if (Keyboard == 'I')
				Text += "I";
			else if (Keyboard == 'J')
				Text += "J";
			else if (Keyboard == 'K')
				Text += "K";
			else if (Keyboard == 'L')
				Text += "L";
			else if (Keyboard == 'M')
				Text += "M";
			else if (Keyboard == 'N')
				Text += "N";
			else if (Keyboard == 'O')
				Text += "O";
			else if (Keyboard == 'P')
				Text += "P";
			else if (Keyboard == 'Q')
				Text += "Q";
			else if (Keyboard == 'R')
				Text += "R";
			else if (Keyboard == 'S')
				Text += "S";
			else if (Keyboard == 'T')
				Text += "T";
			else if (Keyboard == 'U')
				Text += "U";
			else if (Keyboard == 'V')
				Text += "V";
			else if (Keyboard == 'W')
				Text += "W";
			else if (Keyboard == 'X')
				Text += "X";
			else if (Keyboard == 'Y')
				Text += "Y";
			else if (Keyboard == 'Z')
				Text += "Z";
			else if (Keyboard == '1')
				Text += "1";
			else if (Keyboard == '2')
				Text += "2";
			else if (Keyboard == '3')
				Text += "3";
			else if (Keyboard == '4')
				Text += "4";
			else if (Keyboard == '5')
				Text += "5";
			else if (Keyboard == '6')
				Text += "6";
			else if (Keyboard == '7')
				Text += "7";
			else if (Keyboard == '8')
				Text += "8";
			else if (Keyboard == '9')
				Text += "9";
			else if (Keyboard == '0')
				Text += "0";
			else if (Keyboard == '`')
				Text += "`";
			else if (Keyboard == '~')
				Text += "~";
			else if (Keyboard == '!')
				Text += "!";
			else if (Keyboard == '@')
				Text += "@";
			else if (Keyboard == '#')
				Text += "#";
			else if (Keyboard == '$')
				Text += "$";
			else if (Keyboard == '%')
				Text += "%";
			else if (Keyboard == '^')
				Text += "^";
			else if (Keyboard == '&')
				Text += "&";
			else if (Keyboard == '*')
				Text += "*";
			else if (Keyboard == '(')
				Text += "(";
			else if (Keyboard == ')')
				Text += ")";
			else if (Keyboard == '_')
				Text += "_";
			else if (Keyboard == '-')
				Text += "-";
			else if (Keyboard == '+')
				Text += "+";
			else if (Keyboard == '[')
				Text += "[";
			else if (Keyboard == ']')
				Text += "]";
			else if (Keyboard == '=')
				Text += "=";
			else if (Keyboard == '{')
				Text += "{";
			else if (Keyboard == '}')
				Text += "}";
			else if (Keyboard == '|')
				Text += "|";
			else if (Keyboard == '\\')
				Text += "\\";
			else if (Keyboard == ':')
				Text += ":";
			else if (Keyboard == ';')
				Text += ";";
			else if (Keyboard == '\'')
				Text += "\'";
			else if (Keyboard == '\"')
				Text += "\"";
			else if (Keyboard == ',')
				Text += ",";
			else if (Keyboard == '<')
				Text += "<";
			else if (Keyboard == '>')
				Text += ">";
			else if (Keyboard == '.')
				Text += ".";
			else if (Keyboard == '/')
				Text += "/";
			else if (Keyboard == '?')
				Text += "?";
			Keyboard = 0;
			Text1 = Text;
			Text12(originX, originY, const_cast<char*>(Text1.c_str()), c, f, fs, s);

			return this->Text1;
		}
	};    //end class text

	class sprite : public shape
	{
	private:
		GLuint theImage;
		double CenterX, CenterY, UpperLeftX, UpperLeftY, UpperRightX, UpperRightY;
		double LowerLeftX, LowerLeftY, LowerRightX, LowerRightY, ULRadius, URRadius, LLRadius, LRRadius;
		double height, width, rx, ry, rex, rey;
		double ULLRSlope, URLLSlope, rotateAngle;
		bool usingMouse;
		struct RadiusAtPoint
		{
			double ULRadius1, URRadius1, LLRadius1, LRRadius1;
		};
		struct Slopes
		{
			double ULLRSlope, URLLSlope;
		};
		Slopes slope;
		RadiusAtPoint r;

		void calculateCenter()
		{
			CenterX = (UpperLeftX + UpperRightX + LowerLeftX + LowerRightX) / 4;
			CenterY = (UpperLeftY + UpperRightY + LowerLeftY + LowerRightY) / 4;
		}

		void getSlope1()
		{
			slope.ULLRSlope = atan((UpperLeftY - LowerRightY) / (UpperLeftX - LowerRightX));
			slope.URLLSlope = atan((UpperRightY - LowerLeftY) / (UpperRightX - LowerLeftX));
		}

		void calculateRadius()
		{
			ULRadius = getPathagorus(CenterX, CenterY, UpperLeftX, UpperLeftY);
			LLRadius = getPathagorus(CenterX, CenterY, LowerLeftX, LowerLeftY);
			URRadius = getPathagorus(CenterX, CenterY, UpperRightX, UpperRightY);
			LRRadius = getPathagorus(CenterX, CenterY, LowerRightX, LowerRightY);
		}

		void CalculateRadiusFromPoint(double CenterX1, double CenterY1)
		{
			r.ULRadius1 = getPathagorus(CenterX1, CenterY1, UpperLeftX, UpperLeftY);
			r.LLRadius1 = getPathagorus(CenterX1, CenterY1, LowerLeftX, LowerLeftY);
			r.URRadius1 = getPathagorus(CenterX1, CenterY1, UpperRightX, UpperRightY);
			r.LRRadius1 = getPathagorus(CenterX1, CenterY1, LowerRightX, LowerRightY);
		}


		void RotateProcess()
		{
			double radian = rotateAngle * M_PI / 180;
			UpperLeftX = CenterX - ULRadius*cos(M_PI / 4 + radian);
			UpperLeftY = CenterY - ULRadius*sin(M_PI / 4 + radian);
			LowerRightX = CenterX + LRRadius*cos(1 * M_PI / 4 + radian);
			LowerRightY = CenterY + LRRadius*sin(1 * M_PI / 4 + radian);
			UpperRightX = CenterX + URRadius*cos(-1 * M_PI / 4 + radian);
			UpperRightY = CenterY + URRadius*sin(-1 * M_PI / 4 + radian);
			LowerLeftX = CenterX + LLRadius*cos(M_PI - M_PI / 4 + radian);
			LowerLeftY = CenterY + LLRadius*sin(M_PI - M_PI / 4 + radian);
		}

		void RotateProcessX()
		{
			double radian = 0;
			UpperLeftX = CenterX - ULRadius*cos(M_PI / 4 + radian);
			UpperLeftY = CenterY - ULRadius*sin(M_PI / 4 + radian);
			LowerRightX = CenterX + LRRadius*cos(1 * M_PI / 4 + radian);
			LowerRightY = CenterY + LRRadius*sin(1 * M_PI / 4 + radian);
			UpperRightX = CenterX + URRadius*cos(-1 * M_PI / 4 + radian);
			UpperRightY = CenterY + URRadius*sin(-1 * M_PI / 4 + radian);
			LowerLeftX = CenterX + LLRadius*cos(M_PI - M_PI / 4 + radian);
			LowerLeftY = CenterY + LLRadius*sin(M_PI - M_PI / 4 + radian);
		}

		void ProcessChange()
		{
			UpperRightX = UpperLeftX + (this->width);
			UpperRightY = UpperLeftY;
			LowerRightX = UpperRightX;
			LowerRightY = UpperRightY + this->height;
			LowerLeftX = UpperLeftX;
			LowerLeftY = UpperLeftY + this->height;
			calculateCenter();
			pos_x = UpperLeftX; pos_y = UpperLeftY;
			bh = height; bw = width;
			calculateRadius();
		}

		bool FirstCall;
		double pos_x, pos_y;
		double bh, bw;

	public:
		sprite() {
			FirstCall = false;
		}
		void LoadSprite(string ImagePath, double UpperLeftX = 0, double UpperLeftY = 0, double Height = 0, double Width = 0)
		{
			this->UpperLeftX = UpperLeftX;
			this->UpperLeftY = UpperLeftY;
			height = Height;
			width = Width;
			UpperRightX = UpperLeftX + (this->width);
			UpperRightY = UpperLeftY;
			LowerRightX = UpperRightX;
			LowerRightY = UpperRightY + this->height;
			LowerLeftX = UpperLeftX;
			LowerLeftY = UpperLeftY + this->height;
			calculateCenter();
			pos_x = UpperLeftX; pos_y = UpperLeftY;
			bh = height; bw = width;
			calculateRadius();
			FirstCall = true;
			theImage = LoadImage(const_cast<char*>(ImagePath.c_str()));
		}

		void setLocation(double UpperLeftX, double UpperLeftY, double Height, double Width)
		{
			if (FirstCall) {
				this->UpperLeftX = UpperLeftX;
				this->UpperLeftY = UpperLeftY;
				height = Height;
				width = Width;
				UpperRightX = UpperLeftX + (this->width);
				UpperRightY = UpperLeftY;
				LowerRightX = UpperRightX;
				LowerRightY = UpperRightY + this->height;
				LowerLeftX = UpperLeftX;
				LowerLeftY = UpperLeftY + this->height;
				calculateCenter();
				pos_x = UpperLeftX; pos_y = UpperLeftY;
				bh = height; bw = width;
				calculateRadius();
				FirstCall = false;
			}
		}


		void Draw()
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, theImage);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// Enable transparency
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glScalef(1, 1, 1);
			glColor4ub(255, 255, 255, 255);

			glBegin(GL_POLYGON);

			glTexCoord2f(0.0, 0.0);		glVertex2i(LowerLeftX, LowerLeftY);
			glTexCoord2f(1.0, 0.0);		glVertex2f(LowerRightX, LowerRightY);
			glTexCoord2f(1.0, 1.0);		glVertex2f(UpperRightX, UpperRightY);
			glTexCoord2f(0.0, 1.0);		glVertex2f(UpperLeftX, UpperLeftY);

			glEnd();
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
		}

		void UseMouse(int x, int y)
		{
			CenterX = x;
			CenterY = y;
		}

		void Move(double X, double Y)
		{
			CenterX += X;
			CenterY += Y;
			RotateProcess();
		}

		void Rotate(double angleInDegree)
		{
			rotateAngle = -1 * angleInDegree;
			RotateProcess();
		}

		bool isMouseHover()
		{
			return (Pmotion_x >= UpperLeftX && Pmotion_x <= UpperRightX && Pmotion_y >= UpperLeftY && Pmotion_y <= LowerLeftY);
		}

		void resetTriggers()
		{
			FirstCall = false;
		}

		double getUpperLeftX() { return UpperLeftX; }
		double getUpperLeftY() { return UpperLeftY; }
		double getUpperRightX() { return UpperRightX; }
		double getUpperRightY() { return UpperRightY; }
		double getLowerLeftX() { return LowerLeftX; }
		double getLowerLeftY() { return LowerLeftY; }
		double getLowerRightX() { return LowerRightX; }
		double getLowerRightY() { return LowerRightY; }
		double getCenterX() { return CenterX; }
		double getCenterY() { return CenterY; }
		void setHeight(double Height) { height = Height; ProcessChange(); }
		void setWidth(double Width) { width = Width; ProcessChange(); }
		void setCenter(double X, double Y) {
			CenterX = X; CenterY = Y;
		}
		void setUpperLeftX(double X) { UpperLeftX = X; }
		void setUpperLeftY(double Y) { UpperLeftY = Y; }
		void setUpperRightX(double X) { UpperRightX = X; }
		void setUpperRightY(double Y) { UpperRightY = Y; }
		void setLowerRightX(double X) { LowerRightX = X; }
		void setLowerRightY(double Y) { LowerRightY = Y; }
		void setLowerLeftX(double X) { LowerLeftX = X; }
		void setLowerLeftY(double Y) { LowerLeftY = Y; }

		GLuint getGLuint() { return theImage; }

	};


}
