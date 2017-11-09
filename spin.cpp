#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#define PI 3.1415
using namespace std;
int z = 18000;
GLfloat xRot = 20.0f ;
GLfloat yRot = 100.0f;
GLfloat zRot = 0.0f;
GLfloat self = 1.0f;
float x_prev=0.0;
float y_prev= 0.0;
float z_prev = 20.0;
float x_=0.0;
float t= 0.0;
float z_ = 20.0;
void x_Rotate( float Angle , int where,float x_1, float y_1, float x, float y)
{
	//cout<<1;
	float tmp1,tmp2;
	tmp1= x;
	tmp2= y;
	float in[4];
	//in[] = { sin(Angle), where*(-sin(Angle)), where*cos(Angle), cos(Angle) }; 
	in[0] = cos(Angle);
	in[1] = where*(-sin(Angle));
	in[2] = where*sin(Angle);
	in[3] =  cos(Angle) ;
	//x=0;
	//x=0;
	//cout<<in[0];
	
	x=in[0]*x_1+in[1]*y_1;
	y=in[2]*x_1+in[3]*y_1;
	//cout<<x<<"   "<<y;
	x_1=tmp1;
	y_1 =tmp2;
}
void test()
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(-40.0, 0.0, 0.0);
	glEnable(GL_CULL_FACE);
	glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 1.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, 0.0f);
	 glVertex3f(0.0f , 0.0f,50.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 glPopMatrix();
	}
void test3()
{
	glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 1.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, 0.0f);
	 glVertex3f(0.0f , 0.0f,50.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 /*
	glLineWidth(1.0);
	 glBegin(GL_LINES);
	 glColor3f(1.0f, 1.0f, 1.0f);
	 glVertex3f(0.0f , 20.0f, 0.0f);
	 glVertex3f(0.0f , -20.0f,0.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 glLineWidth(1.0);
	 glBegin(GL_LINES);
	 //glColor3f(1.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, -20.0f);
	 glVertex3f(0.0f , 0.0f,20.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 glLineWidth(1.0);
	 glBegin(GL_LINES);
	 //glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(20.0f , 0.0f, 0.0f);
	 glVertex3f(-20.0f , 0.0f,0.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 
	 glutSolidSphere(20.0, 20.0, 20.0);
	 */
	glColor3f(0.0, 0.0, 0.0);
	//glTranslatef(20*cos(2*PI*xRot/360)*cos(PI*2*yRot/360), 20*sin(PI*2*xRot/360), 20*cos(PI*2*xRot/360)*sin(PI*2*yRot/360));
    glutSolidSphere(3.0, 10.0, 10.0);
	 glPopMatrix();
	 glutSwapBuffers();
	}
 void System()
 {
	
	 glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, 60.0f);
	 glVertex3f(0.0f , 0.0f,-60.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f , 60.0f, 0.0f);
	 glVertex3f(0.0f , -60.0f,0.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(60.0f , 0.0f, 0.0f);
	 glVertex3f(-60.0f , 0.0f,0.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
 }
		
 void Test()
 {
	 //glEnable(GL_CULL_FACE);
	 //glPushMatrix();
	 /*glLineWidth(3.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, 0.0f);
	 glVertex3f(0.0f , 0.0f,20.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	 cout<<xRot<<"  "<<yRot<<endl;
	 glPopMatrix();
	glPushMatrix();
	* */
	//x_++;
	/*z_prev=z_;
	x_prev=x_;
	x_Rotate(2*PI*yRot/360, 1,z_prev, x_prev, z_, x_); 
	cout<<z_;
	* */
	float where =1.0;
	float Angle = 2*PI*yRot/360;
	float tmp1,tmp2;
	tmp1= z_;
	tmp2= x_;
	float in[4];
	//in[] = { sin(Angle), where*(-sin(Angle)), where*cos(Angle), cos(Angle) }; 
	in[0] = cos(Angle);
	in[1] = where*(-sin(Angle));
	in[2] = where*sin(Angle);
	in[3] =  cos(Angle) ;
	//x=0;
	//x=0;
	//cout<<in[0];
	
	z_=in[0]*z_prev+in[1]*x_prev;
	x_=in[2]*z_prev+in[3]*x_prev;
	//cout<<x<<"   "<<y;
	x_prev=tmp1;
	y_prev =tmp2;
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(x_, 0.0, z_);
	//cout<<yRot;
		  //glTranslatef(20*cos((2*PI)*(-xRot)/360.0)*sin((2*PI)*(yRot)/360.0),20*sin((2*PI)*(-xRot)/360.0),  20*cos((2*PI)*(-xRot)/360.0)*cos((2*PI)*(yRot)/360.0)); 
	 //20*sin((2*PI)*(yRot)/360.0)
	// glTranslatef( 20*sin((2*PI)*(yRot)/360.0),20*sin((2*PI)*(xRot)/360.0)*cos((2*PI)*(yRot)/360.0),-20*cos((2*PI)*(xRot)/360.0)*cos((2*PI)*(yRot)/360.0));
	 //glTranslatef(20*sin((2*PI)*(xRot)/360.0)*sin((2*PI)*(yRot)/360.0),0.0f,  20*cos((2*PI)*(xRot)/360.0)*sin((2*PI)*(yRot)/360.0));
	 glutSolidSphere(3.0, 10.0, 10.0);
	 glPopMatrix();
	 glutSwapBuffers();
 }
void wheel()
{
	
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(-40.0, 0.0, 0.0);
	glEnable(GL_CULL_FACE);
	glLineWidth(5.0);
	 glBegin(GL_LINES);
	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(0.0f , 0.0f, 14.0f);
	 glVertex3f(0.0f , 0.0f,30.0f );
	 //glVertex3f(30.0f, 30.0f, -40.0f);
	 glEnd();
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(139.0/255.0, 69.0/255.0, 19.0/255.0);
	for(int i=0;i<=z+1; i++)
	{
		if(i==0)
		{
			glVertex3f(30*cos(0.0), 30*sin(0.0), 10.0);
			glVertex3f(30*cos(0.0), 30*sin(0.0), -10.0);
		}
		else
		{
			glVertex3f(30*cos((2*PI*i)/z), 30*sin((2*PI*i)/z) , 10.0);
			glVertex3f(30*cos((2*PI*i)/z), 30*sin((2*PI*i)/z) , -10.0);
		}
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.5450980, 0.537254, 0.537254);
	for(int i=0;i<=z+1; i++)
	{
		if(i==0)
		{
			glVertex3f(25*cos(0.0), 25*sin(0.0), 14.0);
			glVertex3f(30*cos(0.0), 30*sin(0.0), 10.0);
			//glVertex3f(25*cos(0.0), 25*sin(0.0), 14.0);
			
		}
		else
		{
			glVertex3f(25*cos((2*PI*i)/z), 25*sin((2*PI*i)/z) , 14.0);
			glVertex3f(30*cos((2*PI*i)/z), 30*sin((2*PI*i)/z) , 10.0);
		}
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.5450980, 0.537254, 0.537254);
	for(int i=0;i<=z+1; i++)
	{
		if(i==0)
		{
			glVertex3f(30*cos(0.0), 30*sin(0.0), -10.0);
			glVertex3f(25*cos(0.0), 25*sin(0.0), -14.0);
			
		}
		else
		{
			glVertex3f(30*cos((2*PI*i)/z), 30*sin((2*PI*i)/z) , -10.0);
			glVertex3f(25*cos((2*PI*i)/z), 25*sin((2*PI*i)/z) , -14.0);
			//glVertex3f(30*cos((2*PI*i)/z), 30*sin((2*PI*i)/z) , -10.0);
		}
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(128.0/255.0, 104.0/255.0, 238.0/255.0);
	GLfloat t = 30;
		for(int i=0;i<=t+1; i++)
		{
			if(i==0)
			{
			glVertex3f( 0.0 , 0.0 ,14.0);
			glVertex3f(26*cos(0.0), 26*sin(0.0), 14.0);  
			}
			else
			{
				glColor3f((128.0/255.0)/(i%2+1), (104.0/255.0)/(i%2+1), (238.0/255.0)/(i%2+1));
			glVertex3f(26*cos((2*PI*i)/t), 26*sin((2*PI*i)/t) , 14.0);
		    }
		}
		glEnd();
	glBegin(GL_TRIANGLES);
	for(int  i = 0; i<=z+1 ;i++)
	{
		glVertex3f(26*cos((2*PI*i)/t), 26*sin((2*PI*i)/t) , -14.0);
		glVertex3f( 0.0, 0.0, -10.0f);
		glVertex3f(26*cos((2*PI*(i+1))/t), 26*sin((2*PI*(i+1))/t) , -14.0);
	}
	glEnd();
	GLfloat tmp =30.0;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	for(int i=0;i<=tmp ;i++)
	{
				
		glVertex3f(30.2*cos((2*PI*(i))/tmp), 30.2*sin((2*PI*(i))/tmp) , -7.0);
		glVertex3f(30.2*cos((2*PI*(i+1))/tmp), 30.2*sin((2*PI*(i+1))/tmp) , -7.0-pow(-1, i%2));
		glVertex3f(30.2*cos((2*PI*(i))/tmp), 30.2*sin((2*PI*(i))/tmp) , 7.0);
		glVertex3f(30.2*cos((2*PI*(i+1))/tmp), 30.2*sin((2*PI*(i+1))/tmp) , 7.0-pow(-1, i%2));
	
	}
glEnd();
		
				

		
	//glutSwapBuffers();
}
void test2()
{
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(10, 0.0, 0.0);
	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	 //glRotatef(self, 0.0, 1.0, 1.0);
	glutSolidTeapot(10);

}
void RenderScene()
{
	glPushMatrix();
	
	  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	//System();
	//glTranslated(-70,0,-20);
	//glRotatef(self, 0.0, 0.0, 1.0);
	//glRotatef(90 , 1.0, 0.0, 0.0);
	
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot,0.0f,1.0f,0.0f);
   // glPushMatrix();
   System();
    glTranslatef(0.0, 0.0,60.0);
   //glRotatef(self, 0.0, 0.0, 1.0);
    wheel();
    //glutWireCube(10.0);
    //glPopMatrix();
    //glPushMatrix();
    
    // glTranslatef(0.0, 0.0,-60.0);
    // glRotatef(180, 1.0, 0.0, 0.0);
    // glRotatef(-self, 0.0, 0.0, 1.0);
   // wheel();
    
    //glRotatef(self,20*cos(2*PI*xRot/360)*cos(PI*2*yRot/360), 20*sin(PI*2*xRot/360), 20*cos(PI*2*xRot/360)*sin(PI*2*yRot/360));
    //glRotatef(self ,0.0f,sin((2*PI)*(yRot)/360.0),  cos((2*PI)*(yRot)/360.0));
    //test();
    //test();
    //wheel();
   // glPopMatrix();
    //glPopMatrix();
    glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glutSwapBuffers();
/*
	//glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	//glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	//glPushMatrix();
	//glTranslatef( 0.0, 0.0, -40.0);
	//glRotatef(89.0, 0.0, 1.0, 0.0);
    glRotatef(xRot,1.0f,0.0f,0.0f);
    glRotatef(yRot,0.0f,1.0f,0.0f);
     //glRotatef(self ,0.0f,sin((2*PI)*(yRot)/360.0),  cos((2*PI)*(yRot)/360.0)); 
     //glRotatef(self ,sin((2*PI)*(xRot)/360.0),0.0f,  cos((2*PI)*(xRot)/360.0)); 
     //glRotatef(self, sin((2*PI)*(xRot)/360.0)*cos((2*PI)*(yRot)/360.0),sin((2*PI)*(yRot)/360.0),cos((2*PI)*(xRot)/360.0)*cos((2*PI)*(yRot)/360.0));
	 //glRotatef(self, 0.0f, 1.0f, 0.0f);
	wheel();
	//Test();
	glPopMatrix();

	//glPopMatrix();
	//glPopMatrix();
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glutSwapBuffers();
	* */
	glPopMatrix();
	
}
void ChangeSize(int w, int h)
{
    GLfloat nRange = 100.0;
    if(h==0)
        h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(w <= h) {
        glOrtho ( -nRange, nRange , -nRange*h/w ,nRange*h/w, -nRange, nRange);
    } else {
        glOrtho ( -nRange*w/h, nRange*w/h ,-nRange , nRange , -nRange , nRange);
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
        glFrustum( -40.0, 40.0, -40.0*h/w ,40.0*h/w, 10.0, 100.0);
                  } 
            else 
            {
        glFrustum( -40.0*w/h, 40.0*w/h ,-40.0 , 40.0 , 10.0 , 100.0);
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
        self+= 5.0f;    
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
void SetupRC()
{
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}
void TimerFunction (int value)
{
	self += 5;
	t+=PI/100;
	glutTimerFunc(33, TimerFunction , 1);
	glutPostRedisplay();
}
int main( int argc , char *argv[])
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(" Koleso");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(33 , TimerFunction, 1);
	SetupRC();
	glutMainLoop();
}
 
	
	
		
