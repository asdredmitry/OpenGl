void suCircleSurface (int Accuracy,int Quantity , GLfloat Vertex[], GLfloat Color_RGB[])
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
void suEllipseSurface (int Accuracy , int Quantity, GLfloat Vertex[])
{
		//Сначала в массив вершин записывается координата по z , а потом a_Ellipse , b_Ellipse 
	for(int i = 3; i < 3*Quantity  ; i+=3)
	{
		glColor3f(1.0f/2*i, 2*1.0f/i, 1.0f/i);
		glBegin(GL_TRIANGLE_STRIP);
		for(GLfloat phi = 0 ; phi <= 2*PI+PI/Accuracy; phi += PI/Accuracy)
		{
			glVertex3f(Vertex[i+1]*cos(phi), Vertex[i+2]*sin(phi), Vertex[i]);
			glVertex3f(Vertex[i-2]*cos(phi), Vertex[i-1]*sin(phi), Vertex[i-3]);
		}
		glEnd();
	}
}
	
