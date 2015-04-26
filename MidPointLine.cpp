//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ MidPointLine.cpp -o MidPointLine -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*
	正负法画直线:
	斜率四种情况:[0,1],[1,~],[-1,0],[-~,-1]
*/
void MidPointLine(int xs,int ys,int xe,int ye){
	//确保起点在终点的左边
	double temp;
	if(xs>xe){
		temp=xs;
		xs=xe;
		xe=temp;
		temp=ys;
		ys=ye;
		ye=temp;
		
	}
	//计算斜率
	double k = (double)(ye-ys)/(xe-xs);
	int situation = 0;
	int a,b,dt1,dt2,x,y,d;
	a = ys-ye;
	b = xe-xs;
	if(k>=1)
		situation = 0;
	else if(k>=0 && k<1)
		situation =1;
	else if(k>=-1 && k<0)
		situation =2;
	else
		situation=3;
	switch(situation){
		case 0:
		{
			d=a+2*b;
			dt1=2*b;
			dt2=2*(a+b);
			x=xs;
			y=ys;
			glVertex2f(x,y);
			while(y<ye){
				if(d<0){
					y++;
					d=d+dt1;
				}
				else{
					y++;
					x++;
					d=d+dt2;
				}
				glVertex2f(x, y);    
			}
			break;
		}
		case 1:
		{
			d=2*a+b;
			dt1=2*a;
			dt2=2*(a+b);
			x=xs;
			y=ys;
			glVertex2f(x, y);    
			while(x<xe){
				if(d<0){
					x++;
					y++;
					d=d+dt2;
				}
				else{
					x++;
					d=d+dt1;
				}
				glVertex2f(x, y);    
			}
			break;
		}
		case 2:
		{
			d=2*a-b;
			dt1=2*a;
			dt2=2*(a-b);
			x=xs;
			y=ys;
			glVertex2f(x, y);    
			while(x<xe){
				if(d<0){
					x++;
					d=d+dt1;
				}
				else{
					x++;
					y--;
					d=d+dt2;
				}
				glVertex2f(x, y);    
			}
			break;
		}
		case 3:
		{
			d=a-2*b;
			dt1=-2*b;
			dt2=2*(a-b);
			x=xs;
			y=ys;
			glVertex2f(x, y);    
			while(y>ye){
				if(d<0){
					x++;
					y--;
					d=d+dt2;
				}
				else{
					y--;
					d=d+dt1;
				}
				glVertex2f(x, y);    
			}
			break;
		}
	}
}
void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(1.0f);  
	glBegin(GL_POINTS);
	MidPointLine(0,0,100,30);
	MidPointLine(0,0,30,300);
	MidPointLine(0,0,300,-50);
	MidPointLine(0,0,100,-400);
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
