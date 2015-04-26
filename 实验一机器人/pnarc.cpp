//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ pnarc.cpp -o pnarc -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
void pnarc(int radius,int rx,int ry,int situation){
	int x,y,f;
	f=0;
	x=0;
	y=0+radius;
	//第一象限
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

void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(1.0f);  
	glBegin(GL_POINTS);
	pnarc(200,100,100,1);
	pnarc(200,100,100,2);
	pnarc(200,100,100,3);
	pnarc(200,100,100,4);
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
