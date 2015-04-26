//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ rectgle.cpp -lglut -lGL -lGLU
#include <GL/glut.h>
#include <stdlib.h>

void dda(void){
	int x1=0;
	int y1=0;
	int x2=200;
	int y2=200;
	int k,i;
	float x,y,dx,dy;
	k=abs(x2-x1);
	if(abs(y2-y1)>k)
		k =abs(y2-y1);
	dx = float(x2-x1)/k;
	dy = float(y2-y1)/k;
	x = float(x1);
	y = float(y1);
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(1.0f);  
	glBegin(GL_POINTS);
	for(i=0;i<k;i++){
		int xp = int(x+0.5);
		int yp = int(y+0.5);  
		glVertex2f(xp, yp);     
		x = x+dx;
		y = y+dy; 
	} 
	glEnd();  
	glFlush();
}

int main(int argc, char *argv[])
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
 glutInitWindowPosition(0, 0);
 glutInitWindowSize(800, 600);
 glutCreateWindow("第一个OpenGL程序");
 /*glOrtho2D(x1,y1,x2,y2)
 	建立二维坐标系:(x1,y1)
 */
 gluOrtho2D(-400,400,-300,300);
 glutDisplayFunc(&dda);
 glutMainLoop();
 return 0;
}
