//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ glReadPixels.cpp -o glReadPixels -lglut -lGL -lGLU
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
using namespace std;
void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(2.0f);  
	glBegin(GL_POINTS);
//	GLfloat curSizeLine=5;
////    glGetFloatv(GL_LINE_WIDTH_RANGE,sizesLine);
////    glGetFloatv(GL_LINE_WIDTH_GRANULARITY,&stepLine);
//    glLineWidth(curSizeLine); 
//    glColor3f(0.0f,255.0f,0.0f);
//    glBegin(GL_LINES);
//    glVertex3f(0.0f,160.0f,0.0f);
//    glVertex3f(200.0f,160.0f,0.0f); 
//    glEnd();
//    GLubyte test[3]={0.0,255.0,0.0};
//    GLubyte test2[3]={255.0,0.0,0.0};
    int x=0;
    int y=0;
    glColor3f(255.0f,0.0f,0.0f);
    for(int i=0;i<300;i++){
//    	glRasterPos2i(x,y);
//		glDrawPixels(1, 1,GL_RGB, GL_UNSIGNED_BYTE, &test);
//		glDrawPixels(1, 1,GL_RGB, GL_UNSIGNED_BYTE, &test2);
//		// 完成绘制
//		glutSwapBuffers();
//    	x++;
//    	y++;
		//glColor3f(test[0],test[1],test[2]);
		
		glVertex2f(x, y);  
		x++;
		y++;
    }
//    x=0;
//   	y=0;
//    for(int i=0;i<300;i++){
//    	glRasterPos2i(x,y);
//		glDrawPixels(1, 1,GL_RGB, GL_UNSIGNED_BYTE, &test2);
//		// 完成绘制
//		glutSwapBuffers();
//    	x++;
//    	y--;
//    }
   	glEnd();
	glFlush();
//	GLubyte test[3];
//	glReadPixels(400,460,1,1,GL_RGB,GL_UNSIGNED_BYTE,&test);
//	for(int i=0;i<3;i++)
//		printf("%d \n",test[i]);
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
