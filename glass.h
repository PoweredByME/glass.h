

// The liberary is powered by M.E.//

// Please use this code, modify it, wit each modification write your name with it, learn form it and expand it//

// This code is Created by Ali Danish. Student of NUST H-12 pakistan// 

#include <glut.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
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

void ScreenClear() // to clear screen
{
	glClear(GL_COLOR_BUFFER_BIT);
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

}

void SetState(char *state) // for setting the state
{
	if (strcmp(state, "Filled") == 0)
		glBegin(GL_POLYGON);
	if (strcmp(state, "Hollow") == 0)
		glBegin(GL_LINE_STRIP);
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

void CreateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, char * name, char * state)
{
	SetState(state);
	SetColor(name);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x1, y1);
	glEnd();



}

void DrawLine(float x1, float y1, float x2, float y2, char * name)
{
	glBegin(GL_LINES);
	SetColor(name);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
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
