// The liberary is powered by M.E.//

// Please use this code, modify it, wit each modification write your name with it, learn form it and expand it//

// This code is Created by Ali Danish. Student of NUST H-12 pakistan// 

#include <glut.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <math.h>
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
#define ENTER 13;


void ScreenClear() // to clear screen
{
	glClear(GL_COLOR_BUFFER_BIT);
}


void SetState(char *state) // for setting the state
{
	if (strcmp(state, "Filled") == 0)
		glBegin(GL_POLYGON);
	if (strcmp(state, "Hollow") == 0)
		glBegin(GL_LINE_STRIP);
}

void SetColor(char *name) // function to set color
{
	if (strcmp(name, "Black") == 0)
	{
		glColor3f(0.0, 0.0, 0.0);
	}
	else if (strcmp(name, "Red") == 0)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (strcmp(name, "Blue") == 0)
	{
		glColor3f(0.0, 0.0, 1.0);
	}
	else if (strcmp(name, "Green") == 0)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	else if (strcmp(name, "White") == 0)
	{
		glColor3f(1.0, 1.0, 1.0);
	}
	else if (strcmp(name, "Yellow") == 0)
	{
		glColor3f(1.0, 1.0, 0.0);
	}
	else if (strcmp(name, "Purple") == 0)
	{
		glColor3f(1.0, 0.0, 1.0);
	}
	else if (strcmp(name, "Cyan") == 0)
	{
		glColor3f(0.0, 1.0, 1.0);
	}
	else if (strcmp(name, "Orange") == 0)
	{
		glColor3f(1.0, 0.5, 0.0);
	}
	else if (strcmp(name, "DarkRed") == 0)
	{
		glColor4f(1.0, 0.0, 0.0, 0.9);
	}
	else if (strcmp(name, "GreenishYellow") == 0)
	{
		glColor3f(0.5,1.0,0.0);
	}
	else if (strcmp(name, "LightGreen") == 0)
	{
		glColor3f(0.5, 1.0, 0.5);
	}
	else if (strcmp(name, "DarkGreen") == 0)
	{
		glColor3f(0.0, 0.5, 0.0);
	}
	else if (strcmp(name, "Brown") == 0)
	{
		glColor3f(0.5, 0.35, 0.05);
	}
	else if (strcmp(name, "Grey") == 0)
	{
		glColor4f(0.8, 0.8, 0.8,1.0);
	}
	else if (strcmp(name, "DarkGrey") == 0)
	{
		glColor4f(0.2, 0.2, 0.2,1.0);
	}
	else if (strcmp(name, "Magenta") == 0)
	{
		glColor3f(1.0, 0.0, 1.0);
	}
}

void CreateRectangle(int x, int y, int height, int lenght, char * name, char * state)
{
	SetState(state);
	SetColor(name);
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();



}

void CreateTriangle(int __x1, int __y1, int __x2, int __y2, int __x3, int __y3, char * name, char * state)
{
	SetState(state);
	SetColor(name);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
	glEnd();
}

void DrawLine(float __x1, float __y1, float __x2, float __y2, char * name)
{
	glBegin(GL_LINES);
	SetColor(name);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glEnd();
}

void CreateCircle(int x, int y, int radius, char * name, char *state){
	float angle;
	SetState(state);
	SetColor(name);
	glLineWidth(1.0f);

	for (int i = 0; i < 100; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
}





void Text(int x, int y, char *string, char *name, char *style = "NULL")
{

	char *c;
	SetColor(name);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	if (strcmp(style, "Underline") == 0)
	{
		DrawLine(x, y + 8, x + strlen(string) * 9, y + 8, name);
	}
	if (strcmp(style, "Bold") == 0)
	{
		Text(x + 1, y, string, name);
	}

}
int g_Width = 400;		//define size of the window
int g_Height = 400;

//global mouse position
int mouse_x = 0;	//xcod
int mouse_y = 0;    //ycod
int mouse_s = 0;	//mouse state
int mouse_b = 0;	// mouse buttons

char Keyboard;
int Key = 0;
int SpecialKey = 0;
int ModKey = 0;


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
void myDisplayFunction();




void init(void)
{
	//set (0,0) on left top
}

void mainWindow(int argc, char**argv, int height, int width, char *name)
{

	glutInit(&argc, argv);		//initilize the GLUT libraray

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		//has four colour components red, green,blue, and alpha 
	glutInitWindowSize(height, width);	//size of window
	glutInitWindowPosition(0, 0);		//poistion of window
	glutCreateWindow("Glut");

	if (strcmp(name, "Black") == 0)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(name, "Red") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.0);
	}
	else if (strcmp(name, "Blue") == 0)
	{
		glClearColor(0.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(name, "Green") == 0)
	{
		glClearColor(0.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(name, "White") == 0)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(name, "Yellow") == 0)
	{
		glClearColor(1.0, 1.0, 0.0, 0.0);
	}
	else if (strcmp(name, "Purple") == 0)
	{
		glClearColor(1.0, 0.0, 1.0, 0.0);
	}
	else if (strcmp(name, "Cyan") == 0)
	{
		glClearColor(0.0, 1.0, 1.0, 0.0);
	}
	else if (strcmp(name, "Orange") == 0)
	{
		glClearColor(1.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(name, "DarkRed") == 0)
	{
		glClearColor(1.0, 0.0, 0.0, 0.9);
	}
	else if (strcmp(name, "GreenishYellow") == 0)
	{
		glClearColor(0.5, 1.0, 0.0,0.0);
	}
	else if (strcmp(name, "LightGreen") == 0)
	{
		glClearColor(0.5, 1.0, 0.5, 0.0);
	}
	else if (strcmp(name, "DarkGreen") == 0)
	{
		glClearColor(0.0, 0.5, 0.0, 0.0);
	}
	else if (strcmp(name, "Brown") == 0)
	{
		glClearColor(0.5, 0.35, 0.05, 0.0);
	}
	else if (strcmp(name, "Grey") == 0)
	{
		glClearColor(0.8, 0.8, 0.8, 1.0);
	}
	else if (strcmp(name, "DarkGrey") == 0)
	{
		glClearColor(0.2, 0.2, 0.2, 1.0);
	}
	else if (strcmp(name, "Magenta") == 0)
	{
		glClearColor(1.0, 0.0, 1.0,0.0);
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
	glutTimerFunc(33, myTimerFunction, 0);

	//	glutFullScreen();	// make the screen fullscreen
	glutSetCursor(GLUT_CURSOR_INFO);	//Displays the type of cursor u want



	glutMainLoop();

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
	glutTimerFunc(33, myTimerFunction, 0);
	myDisplayFunction();
}

int i = 0;


void refreshScreen()
{
	glutSwapBuffers();
}

// This code is written by Ali Danish. A Student of NUST H-12 pakistan

// this code is written by Saad Ahmad 

void Text(int x, int y, int text, char *name, char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, name, style);
}

void Text(double x, double y, int text, char *name, char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, name, style);
}



void Text(int x, int y, long text, char *name, char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, name, style);
}

void Text(float x, float y, long text, char *name, char *style = "NULL")
{
	char e[20];
	_itoa_s(text, e, 10);
	Text(x, y, e, name, style);
}

void CreateCircle(double x, double y, double radius, char * name, char *state){
	float angle;
	SetState(state);
	SetColor(name);
	glLineWidth(1.0f);

	for (int i = 0; i < 100; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
}

void CreateCircle(int x, int y, double radius, char * name, char *state){
	float angle;
	SetState(state);
	SetColor(name);
	glLineWidth(1.0f);

	for (int i = 0; i < 100; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
}

void CreateCircle(double x, double y, int radius, char * name, char *state){
	float angle;
	SetState(state);
	SetColor(name);
	glLineWidth(1.0f);

	for (int i = 0; i < 100; i++)
	{
		angle = i * 2 * M_PI / 100;
		glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
}

void CreateTriangle(double __x1, double __y1, double __x2, double __y2, double __x3, double __y3, char * name, char * state)
{
	SetState(state);
	SetColor(name);
	glVertex2f(__x1, __y1);
	glVertex2f(__x2, __y2);
	glVertex2f(__x3, __y3);
	glVertex2f(__x1, __y1);
	glEnd();
}

void CreateRectangle(double x, double y, double height, double lenght, char * name, char * state)
{
    SetState(state);
	SetColor(name);
	glVertex2f(x, y);
	glVertex2f(x + lenght, y);
	glVertex2f(x + lenght, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();
}

void InputText(double x, double y, char* nameofstring, int sizeofstring, char* color)
{
	int a=strlen(nameofstring);
	char* stringText = (char*)calloc(sizeofstring+1, 4);
	stringText = nameofstring;
		if (Keyboard == '\b')
		{
			strncpy_s(nameofstring, sizeofstring, stringText, (strlen(stringText) - 1));
		}

		if (a != sizeofstring-1)
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
		Text(x, y, nameofstring, color);
}




// Coded by Saad Ahmad
