//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ Bresenham.cpp -o Bresenhanm -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void Bresenham(int xs,int ys,int xe,int ye){
	//确保起点在终点左边
	if(xs>xe){
		int temp;
		temp=xs;
		xs=xe;
		xe=temp;
		temp=ys;
		ys=ye;
		ye=temp;
	}
	int dy=ye-ys;
	int dx=xe-xs;
	int x=xs;
	int y=ys;
	//根据m判断四种情况
	int situation=0;
	int vertical=0;
	double m;
	//垂直
	if(dx==0){
		situation=0;
		vertical=1;
	}
	//不垂直 根据斜率划分四种情况
	else{
		m=(double)dy/(double)dx;
		if(m>=1.0)
			situation=0;
		else if(m>=0 && m<1)
			situation=1;
		else if(m<0 && m>=-1)
			situation=2;
		else
			situation=3;
	}
	switch(situation){
		case 0:{
			//斜率>1
			//垂直情况
			if(vertical==1){
				if(dy>0){
					for(int i=0;i<dy;i++){
					glVertex2f(x,y);
					y++;
					}
				}
				else{
					for(int i=0;i>dy;i--){
					glVertex2f(x,y);
					y--;
					}
				}
				
			}
			//非垂直情况  斜率>=1
			else{
				m=(double)1/m;
				double e=m-0.5;
				for(int i=0;i<dy;i++){
					glVertex2f(x,y);
					if(e>=0){
						x=x+1;
						e=e-1;
					}
					y=y+1;
					e=e+m;
				}
			}
			break;
		}
		case 1:{
			//0=<斜率<1
			double e=m-0.5;
			for(int i=0;i<dx;i++){
				glVertex2f(x,y);
				if(e>=0){
					y=y+1;
					e=e-1;
				}
				x=x+1;
				e=e+m;
			}
			break;
		}
		case 2:{
		    //-1<=斜率<0
			double e=m-0.5;
			for(int i=0;i<dx;i++){
				glVertex2f(x,y);
				if(e>0){
					y=y-1;
					e=e-1;
				}
				x=x+1;
				e=e-m;
			}
			break;
		}
		case 3:{
			//斜率<-1
			m=(double)1/m;
			double e=m-0.5;
			for(int i=0;i<dx;i++){
				glVertex2f(x,y);
				if(e>0){
					x=x+1;
					e=e-1;
				}
				y=y-1;
				e=e-m;
			}
			break;
		}
	}	
	
}

void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(2.0f);  
	glBegin(GL_POINTS);
	Bresenham(100,0,100,-500);
	//Bresenham(100,0,300,400);
	//Bresenham(50,0,300,100);
	//Bresenham(50,0,150,-150);
	glEnd();  
	//glBegin(GL_POINTS);
	//double y=-150;
    // for(int x=100;x>0;x--){
    // 	y=y+1.5;
    //  	glVertex2f(x,y);
    //  }
  //  glEnd();
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
