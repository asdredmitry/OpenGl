#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include "description.h"
#define PI 3.14159265359
timespec begin;
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
GLfloat zRot = 0.0f;
GLfloat selfRot = 1.0f;
int counterFPS = 0;
GLfloat v[50];
GLfloat V[50];
GLfloat v_in[50];
GLfloat v_in_2[50];
GLfloat V_2[50];
	GLfloat V_in[50];
	GLfloat V_1[50];
	void Paint_Grip()
	{
		 glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2.0);
	int tmp = 100;
	glBegin(GL_LINES);
	for(int i=0;i<=tmp ;i++)
	{
				
		glVertex3f(50.2*cos((2*PI*(i))/tmp), 50.2*sin((2*PI*(i))/tmp) , -16.0);
		glVertex3f(50.2*cos((2*PI*(i+1))/tmp), 50.2*sin((2*PI*(i+1))/tmp) , -16.0-pow(-1, i%2));
		glVertex3f(50.2*cos((2*PI*(i))/tmp), 50.2*sin((2*PI*(i))/tmp) , 16.0);
		glVertex3f(50.2*cos((2*PI*(i+1))/tmp), 50.2*sin((2*PI*(i+1))/tmp) , 16.0-pow(-1, i%2));
        glVertex3f(50.2*cos((2*PI*(i))/tmp), 50.2*sin((2*PI*(i))/tmp) , pow(-1, i%2)*5.0);
		glVertex3f(50.2*cos((2*PI*(i+1))/tmp), 50.2*sin((2*PI*(i+1))/tmp) , -pow(-1, i%2)*5.0);	
	}
glEnd();
}
void CircleSurface (int Accuracy,int Quantity , GLfloat Vertex[], GLfloat Color_RGB[])
{
	//Сначала в массив вершин записывается координата по z , а потом радиус окружности 
	for(int i = 2; i < 2*Quantity  ; i+=2)
	{
		glColor3f(Color_RGB[3*(i/2-1)]/255.0f, Color_RGB[3*(i/2-1)+1]/255.0f, Color_RGB[3*(i/2-1)+2]/255.0f);
		glBegin(GL_TRIANGLE_STRIP);
		for(GLfloat phi = 0 ; phi <= 2*PI+PI/Accuracy; phi += PI/Accuracy)
		{
			glVertex3f(Vertex[i+1]*cos(phi), Vertex[i+1]*sin(phi), Vertex[i]);
			glVertex3f(Vertex[i-1]*cos(phi), Vertex[i-1]*sin(phi), Vertex[i-2]);
		}
		glEnd();
	}
}
void EllipseSurface (int Accuracy , int Quantity, GLfloat Vertex[], GLfloat Color_RGB[])
{
		//Сначала в массив вершин записывается координата по z , а потом a_Ellipse , b_Ellipse 
	for(int i = 3; i < 3*Quantity  ; i+=3)
	{
		
		glColor3f(Color_RGB[i-3]/255.0f, Color_RGB[i-2]/255.0f, Color_RGB[i-1]/255.0f);
		glBegin(GL_TRIANGLE_STRIP);
		for(GLfloat phi = 0 ; phi <= 2*PI+PI/Accuracy; phi += PI/Accuracy)
		{
			glVertex3f(Vertex[i+1]*cos(phi), Vertex[i+2]*sin(phi), Vertex[i]);
			glVertex3f(Vertex[i-2]*cos(phi), Vertex[i-1]*sin(phi), Vertex[i-3]);
		}
		glEnd();
	}
}
void Circle(int Accuracy , GLfloat Radius, GLfloat Color_R, GLfloat Color_G, GLfloat Color_B)
{
	glColor3f(Color_R/255.0f, Color_G/255.0f, Color_B/255.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for(GLfloat phi = 0 ; phi <= 2*PI+PI/Accuracy; phi += PI/Accuracy)
	{
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(Radius*cos(phi), Radius*sin(phi), 0.0f);
	}
	glEnd();
}
void Krep(int Accuracy,GLfloat Radius)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	for(GLfloat phi = 0.0f; phi <= 2*PI+PI/Accuracy ; phi += PI/Accuracy)
	{
		glPushMatrix();
		glTranslatef(Radius*cos(phi), Radius*sin(phi), 0.0f);
		Circle(2,1.0f, 0.0f, 0.0f, 0.0f);
		glPopMatrix();
	}
}
		
void wheel()
{
	int acuracy = 10000;
	glRotatef(selfRot , 0.0f, 0.0f, 1.0f);
	//glTranslatef(40.0, 0.0, 0.0);
	//selfRot += 15;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	Fill_Grip(V);
	v[0] = 0;
	v[1] = 0;
	v[2] =  0;
	
	v[3] =  0;
	v[4] =  0;
	v[5] =  0;
	
	v[6] =  0;
	v[7] = 0;
	v[8] = 0;
	
	v[9] = 0;
	v[10] =0;
	v[11] =0;
	
	v[12] = 0;
	v[13] = 0;
	v[14] = 0;
	
	v[15] = 0;
	v[16] =0;
	v[17] = 0;
	//v[18] = 0.0f;
	//v[19] = 70 ;
	
	Fill_Line(V_in, v_in);
	//CircleSurface( 900, 4, V_in, v_in);
	//glPushMatrix();
	
	//glutSolidCylinder();
	//glPopMatrix();
	 
    CircleSurface( acuracy ,6, V,v); 
    Paint_Grip();
   
   glPushMatrix();
   
   //glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   //glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
   //glTranslatef(0.0f, 0.0f, 30.0f);
   Fill_Disk_2(V_1,v_in);
   //glTranslatef(0.0f, 0.0f, 1.3f);
 CircleSurface(acuracy, 6, V_1, v_in);\
 FillDisk3(V_2, v_in_2);
 CircleSurface(acuracy, 5, V_2, v_in_2);
 glPushMatrix();
 glTranslatef(0.0f, 0.0f, 25.1f);
 Krep(3, 5.0f);
 glPopMatrix();
   // CircleSurface( 900 ,6, V); 
   glPopMatrix();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
}
	
void RenderScene()
{
	counterFPS++;
	timespec end;
	clock_gettime(CLOCK_REALTIME,&end);
	std :: cout <<(double)counterFPS/( (double)(end.tv_sec - begin.tv_sec) + (double)(end.tv_nsec - begin.tv_nsec)/1000000000) << std :: endl;
	//printf("%i    ",counterFPS);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -40.0f);
	//glPolygonMode(GL_BACK,GL_LINE);

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	wheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -70.0);
	//wheel();
	glPopMatrix();
	
	glPopMatrix();
	glutSwapBuffers();
}
void ChangeSize3(int w , int h)
{
	
	GLfloat nRange = 100.0f;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h==0)
	h=1;
	GLfloat aspectRatio = w/h;
	if(w >= h)
	{
		glOrtho( -nRange , nRange , -nRange*h/w, nRange*h/w , -nRange ,nRange);
	}
	else 
	{
		glOrtho( -nRange*w/h , nRange*w/h , -nRange, nRange , -nRange , nRange);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void ChangeSize(int w, int h)
{
    GLfloat nRange = 100.0;
    if(h==0)
        h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    printf("%i   w" , w);
    printf("%i   h" , h);
    printf("\n");
    
    if(w <= h) {
        glOrtho ( -nRange, nRange , -nRange*h/w ,nRange*h/w, -nRange, nRange);
        printf("%f   h" , -nRange);
         printf("%f   w" , -nRange*h/w);
   
    printf("\n");
    } else {
        glOrtho ( -nRange*w/h, nRange*w/h ,-nRange , nRange , -nRange , nRange);
        // printf("%f   w" , -nRange*h/w);
    printf("%f   h" , -nRange*w/h);
     printf("%f   w" , -nRange);
    printf("\n");
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void ChangeSize2(int w, int h)
{
	GLfloat nRange = 100.0;
    if(h==0)
        h=1;
    glViewport(0,0,w,h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w <= h) {
        glFrustum( -100.0, 100.0, -100.0*h/w ,100.0*h/w, 10.0, 100.0);
                  } 
            else 
            {
        glFrustum( -100.0*w/h, 100.0*w/h ,-100.0 , 100.0 , 10.0 , 100.0);
        //glFrustum( -40.0*w/h, 40.0*w/h ,-40.0 , 40.0 , 10.0 , 100.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
      glTranslatef(0.0f, 0.0f, -50.0f);
}
void SpecialKeys(int key , int x, int y)
{
	 if(key==GLUT_KEY_UP)
        xRot += 5.0f;
    if(key==GLUT_KEY_DOWN)
        xRot -= 5.0f;
    if(key==GLUT_KEY_LEFT)
        yRot -= 5.0f;
    if(key==GLUT_KEY_RIGHT)
        yRot += 5.0f;
    if(key=='z')
       // self+= 5.0f;    
    if(key > 356.0f)
        xRot = 0.0f;
    if(key < -1.0f )
        xRot =355.0f;
    if(key >356.0f)
        yRot=0.0f;
    if(key < -1.0f )
        yRot =355.0f;
    if(zRot>356.0f)
       zRot=0.0f;
    if(zRot<-1.0f)
       zRot= 355.0f;
      
       glutPostRedisplay();
}
void TimerFunction(int value)
{
	selfRot+=1;
	
	glutTimerFunc(2, TimerFunction, 1);
	glutPostRedisplay();
}
void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
int main(int argv , char *argc [])
{
	clock_gettime(CLOCK_REALTIME,&begin);
	
	glutInit(&argv , argc);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutTimerFunc(10, TimerFunction, 1);
	glutCreateWindow("Wheel");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	
	SetupRC();
	glutMainLoop();
}
	
	
	
	
