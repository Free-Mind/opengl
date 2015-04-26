//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ bresenham_acc.cpp -o bresenham_acc -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void draw(int x,int y,int r,int rx,int ry,int situation){
	//画八分之一圆弧,分为八种情况
	switch(situation){
		case 1:
			glVertex2f(x+rx,y+ry);
			break;
		case 2:
			glVertex2f(y+rx,x+ry);
			break;
		case 3:
			glVertex2f(y+rx,-x+ry);
			break;
		case 4:
			glVertex2f(-x+rx,y+ry);
			break;
		case 5:
			glVertex2f(-x+rx,-y+ry);
			break;
		case 6:
			glVertex2f(-y+rx,-x+ry);
			break;
		case 7:
			glVertex2f(-y+rx,x+ry);
			break;
		case 8:
			glVertex2f(x+rx,-y+ry);
			break;
	}
}
void bresenham_acc(int r,int rx,int ry,int situation){
	int x,y,d;
	x=0;
	y=r;
	d=3-2*r;
	while(x<y){
		draw(x,y,r,rx,ry,situation);
		if(d<0)
		{
			d=d+4*x+6;
		}
		else{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}
	if(x==y)
		draw(x,y,r,rx,ry,situation);
}
void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(2.0f);  
	glBegin(GL_POINTS);
	bresenham_acc(100,-98,-21,1);
	bresenham_acc(100,-98,-21,2);
	bresenham_acc(100,-98,-21,3);
	bresenham_acc(100,-98,-21,4);
	bresenham_acc(100,-98,-21,5);
	bresenham_acc(100,-98,-21,6);
	bresenham_acc(100,-98,-21,7);
	bresenham_acc(100,-98,-21,8);
	
	glEnd();  
	glFlush();
	
}

int main(int argc, char *argv[]){
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	 glutInitWindowPosition(0, 0);
	 glutInitWindowSize(800, 600);
	 glutCreateWindow("第一个OpenGL程序");
	 /*glOrtho2D(x1,y1,x2,y2)
	 	建立二维坐标系:(x1,y1)
	 */
	 gluOrtho2D(-400,400,-300,300);
	 glutDisplayFunc(&disPlay);
	 glutMainLoop();
	 return 0;
}
