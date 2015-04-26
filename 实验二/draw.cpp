//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ draw.cpp -o draw -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stack>
#include <stdio.h>
//stack<int> test;
void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);	  
	GLubyte newColor[3]={255,255,0};
	GLubyte oldColor[3]={255,0,0};
	GLubyte seed[3];
	
	glRasterPos2i(0,0);
	glDrawPixels(1.0, 1.0,GL_RGB, GL_UNSIGNED_BYTE, &newColor);
	glutSwapBuffers();
//	glPointSize(1.0f);
//	glBegin(GL_POINTS);
//	glColor3ub(newColor[0],newColor[1],newColor[2]);
//	glVertex2d(0,0);
//	glEnd();
//	glFlush();
	
	glReadPixels(400,300,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(399,300,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(400,299,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(401,300,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(401,301,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(400,301,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
	glReadPixels(399,301,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	printf("after:r=%d g=%d b=%d \n",seed[0],seed[1],seed[2]);
}

int main(int argc, char *argv[]){
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	 glutInitWindowPosition(0, 0);
	 glutInitWindowSize(800, 600);
	 glutCreateWindow("第一个OpenGL程序");
	 
	/* glOrtho2D(x1,y1,x2,y2)
	 	建立二维坐标系:(x1,y1)*/
	 gluOrtho2D(-400,400,-300,300);
	 glutDisplayFunc(&disPlay);
	 glutMainLoop();
	 return 0;
}
