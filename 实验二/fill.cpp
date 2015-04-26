//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ fill.cpp -o fill -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stack>
#include <iostream>
#include <stdio.h>
//stack<int> test;
using namespace std;
struct Point{
	int x;
	int y;
};
void pnarc(int radius,int rx,int ry,int situation){
	int x,y,f;
	f=0;
	x=0;
	y=0+radius;
	while(y>0){
		switch(situation){
			case 1:
				glVertex2f(x+rx,y+ry);
				break;
			case 2:
				glVertex2f(rx-x,y+ry);
				break;
			case 3:
				glVertex2f(rx-x,ry-y);
				break;
			case 4:
				glVertex2f(x+rx,ry-y);
				break;
		}
		if(f>0)
		{
			f=f-2*y+1;
			y=y-1;
		}	
		else{
			f=f+2*x+1;
			x=x+1;
		}
	}
	if(y==0){
		switch(situation){
			case 1:
				glVertex2f(x+rx,y+ry);
				break;
			case 2:
				glVertex2f(rx-x,y+ry);
				break;
			case 3:
				glVertex2f(rx-x,ry-y);
				break;
			case 4:
				glVertex2f(x+rx,ry-y);
				break;
		}
	}
}
//判断颜色是否相同
bool sameColor(int x,int y,GLubyte boundaryColor[]){
	GLubyte seed[3];
	int halfwidth=400;
	int halfheight=300;
	//当坐标(x,y)点被画上颜色,通过glReadPixels(x-1,y)得到的点其实也被画上了
	glReadPixels(x+halfwidth,y+halfheight,1,1,GL_RGB,GL_UNSIGNED_BYTE,&seed);
	if(seed[0]==boundaryColor[0] && seed[1]==boundaryColor[1] && seed[2]==boundaryColor[2]){
		return true;
	}
	else
		return false;
}
//绘制像素点
void drawColor(int x,int y,GLubyte newColor[]){
    glRasterPos2i(x,y);
    //GLubyte Color[3]={255,255,0};
    glDrawPixels(1.0, 1.0,GL_RGB, GL_UNSIGNED_BYTE, newColor);
   	glutSwapBuffers();
//		glPointSize(1.0f);
//		glBegin(GL_POINTS);
//		glColor3ub(newColor[0],newColor[1],newColor[2]);
//		glVertex2i(x,y);
//		glEnd();
//		glFlush();
//		printf("r=%d g=%d b=%d x=%d y=%d\n",newColor[0],newColor[1],newColor[2],x,y);
}
void fill(int xp,int yp){//种子填充算法
	//声明栈用于存储种子点
	int x=xp;
	int y=yp;
	GLubyte boundaryColor[3]={255,0,0};
	GLubyte newColor[3]={255,255,0};
	GLubyte oldColor[3]={0,0,0};
	stack<Point> location;
	Point start={x,y};
	location.push(start);
	int xsave;
	int xright;
	int xleft;
	while(!location.empty()){
		Point p=location.top();
		location.pop();
		xsave=p.x;
		x=p.x;
		y=p.y;
		x=x;
		
		while(!sameColor(x,y,boundaryColor)){//从种子像素开始填充到右边界;
			drawColor(x,y,newColor);
			x=x+1;
		}
		
		xright=x-1;
		x=xsave-1;
		while(!sameColor(x,y,boundaryColor)){//从种子像素开始填充到左边界;
			drawColor(x,y,newColor);
			x=x-1;
		}
		xleft=x+1;
		x=xleft;
		y=y+1;
		while(x<=xright){
			bool need_fill=false;
			while(sameColor(x,y,oldColor)){
				need_fill=true;
				x=x+1;
			}
			if(need_fill){
				Point temp={x-1,y};
				location.push(temp);
				need_fill=false;
				
			}
			while(!sameColor(x,y,oldColor) && x<=xright)
				x=x+1;
//			if(!sameColor(x,y,boundaryColor)){
//				Point temp={x,y};
//				location.push(temp);
//				break;
//			}
//			else{
//				x++;
//			}
		}
		x=xleft;
		y=y-2;
		while(x<=xright){
			bool need_fill=false;
			while(sameColor(x,y,oldColor)){
				need_fill=true;
				x=x+1;
			}
			if(need_fill){
				Point temp={x-1,y};
				location.push(temp);
				need_fill=false;
			}
			while(!sameColor(x,y,oldColor) && x<=xright)
				x=x+1;
//			if(!sameColor(x,y,boundaryColor)){
//				Point temp={x,y};
//				location.push(temp);
//				break;
//			}
//			else{
//				x++;
//			}
		}
	}
	
}
void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //不填充多边形内部颜色,只填充内部边框颜色
	glColor3f(255.0f,0.0f, 0.0f);
	glPointSize(2.0f);
//	glBegin(GL_POINTS);
	glBegin(GL_POLYGON);  
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex2f(0.0f,0.0f);
	glVertex2f(100.0f,0.0f);
	glVertex2f(100.0f,100.0f);
	glVertex2f(0.0f,100.0f);
//	pnarc(100,-200,-200,1);
//	pnarc(100,-200,-200,2);
//	pnarc(100,-200,-200,3);
//	pnarc(100,-200,-200,4);
	glEnd();
	fill(50,50);
	glFlush();
	
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
