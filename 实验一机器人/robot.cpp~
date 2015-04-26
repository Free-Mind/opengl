//第三方库： sudo apt-get install freeglut3-dev
//           其中，用到了glut.h文件
//编译命令：g++ robot.cpp -o robot -lglut -lGL -lGLU
#include <GL/glut.h>
#include <iostream>
using namespace std;
//正负法画直线
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
//正负法画圆
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

//bresenham算法画圆
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
			glVertex2f(x+rx,-y+ry);
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
			glVertex2f(-x+rx,y+ry);
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
//bresenham算法画直线
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
				if(e>=0){
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
			for(int i=0;i<(-dy);i++){
				glVertex2f(x,y);
				if(e>=0){
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
//dda算法画直线
void dda(int x1,int y1,int x2,int y2){
	int k,i;
	float x,y,dx,dy;
	k=abs(x2-x1);
	if(abs(y2-y1)>k)
		k =abs(y2-y1);
	dx = float(x2-x1)/k;
	dy = float(y2-y1)/k;
	x = float(x1);
	y = float(y1);
	for(i=0;i<k;i++){
		int xp = int(x+0.5);
		int yp = int(y+0.5);  
		glVertex2f(xp, yp);     
		x = x+dx;
		y = y+dy; 
	} 

}

void disPlay(void){
	glClear(GL_COLOR_BUFFER_BIT);  
	glPointSize(2.0f);  
	glBegin(GL_POINTS);
	//中间圆
	for(int i=0;i<=8;i++)
		bresenham_acc(15,0,0,i);
	//中间三角形
	Bresenham(-30,-15,0,28);
	MidPointLine(-30,-15,30,-15);
	dda(0,28,30,-15);
	//中间圆弧矩阵
	Bresenham(-63,60,63,60);
	Bresenham(-63,-60,63,-60);
	Bresenham(-73,50,-73,-50);
	Bresenham(73,50,73,-50);
	//圆弧:圆心(-63,50),半径r=10
	pnarc(10,-63,50,2);
	pnarc(10,63,50,1);
	pnarc(10,-63,-50,3);
	pnarc(10,63,-50,4);
	//左手臂
	//上面矩形
	Bresenham(-81,45,-108,45);
	Bresenham(-108,45,-108,0);
	Bresenham(-108,0,-81,0);
	Bresenham(-81,0,-81,45);
	//中间连接
	Bresenham(-88,0,-88,-4);
	Bresenham(-101,0,-101,-4);
	//右边连接
	Bresenham(-81,43,-73,43);
	Bresenham(-81,25,-73,25);
	//下面矩形
	Bresenham(-108,-4,-81,-4);
	Bresenham(-108,-4,-108,-37);
	Bresenham(-108,-37,-81,-37);
	Bresenham(-81,-37,-81,-4);
	//下面圆 圆心(-95.-47) r=10
	for(int i=1;i<=8;i++)
		bresenham_acc(10,-95,-47,i);
	
	//右手臂
	//上面矩形
	Bresenham(81,45,108,45);
	Bresenham(108,45,108,0);
	Bresenham(108,0,81,0);
	Bresenham(81,0,81,45);
	//中间连接
	Bresenham(88,0,88,-4);
	Bresenham(101,0,101,-4);
	//左边连接
	Bresenham(81,43,73,43);
	Bresenham(81,25,73,25);
	//下面矩形
	Bresenham(108,-4,81,-4);
	Bresenham(108,-4,108,-37);
	Bresenham(108,-37,81,-37);
	Bresenham(81,-37,81,-4);
	//下面圆 圆心(-95.-47) r=10
	for(int i=0;i<=8;i++)
		bresenham_acc(10,95,-47,i);
		
	//左脚
	Bresenham(-41,-62,-41,-66);
	Bresenham(-21,-62,-21,-66);
	Bresenham(-42,-66,-22,-66);
	Bresenham(-51,-75,-51,-108);
	Bresenham(-42,-117,-22,-117);
	Bresenham(-13,-108,-13,-75);
	
	pnarc(9,-42,-75,2);
	pnarc(9,-22,-75,1);
	pnarc(9,-42,-108,3);
	pnarc(9,-22,-108,4);
	
	Bresenham(-41,-117,-41,-125);
	Bresenham(-26,-117,-26,-125);
	
	Bresenham(-59,-125,-8,-125);
	Bresenham(-8,-125,-8,-137);
	Bresenham(-8,-137,-59,-137);
	Bresenham(-59,-137,-59,-125);
	
	//右脚
	Bresenham(41,-62,41,-66);
	Bresenham(21,-62,21,-66);
	
	Bresenham(42,-66,22,-66);
	Bresenham(51,-75,51,-108);
	Bresenham(42,-117,22,-117);
	Bresenham(13,-108,13,-75);
	
	pnarc(9,42,-75,1);
	pnarc(9,22,-75,2);
	pnarc(9,42,-108,4);
	pnarc(9,22,-108,3);
	
	Bresenham(41,-117,41,-125);
	Bresenham(26,-117,26,-125);
	
	Bresenham(59,-125,8,-125);
	Bresenham(8,-125,8,-137);
	Bresenham(8,-137,59,-137);
	Bresenham(59,-137,59,-125);
	//头
	Bresenham(-35,150,-35,173);
	Bresenham(35,150,35,173);
	//矩形
	Bresenham(-54,150,54,150);
	Bresenham(-64,140,-64,86);
	Bresenham(-54,76,54,76);
	Bresenham(64,86,64,140);
	//圆弧
	pnarc(10,54,140,1);
	pnarc(10,-54,140,2);
	pnarc(10,-54,86,3);
	pnarc(10,54,86,4);
	
	//眼睛
	for(int i=1;i<=4;i++){
		pnarc(10,-30,111,i);
		pnarc(10,30,111,i);
	}	
	//嘴巴
	bresenham_acc(20,0,111,4);
	bresenham_acc(20,0,111,5);
	
	//右耳
	Bresenham(87,134,77,134);
	Bresenham(87,95,77,95);
	Bresenham(92,129,92,100);
	Bresenham(72,100,72,129);
	//圆弧
	pnarc(5,87,129,1);
	pnarc(5,77,129,2);
	pnarc(5,77,100,3);
	pnarc(5,87,100,4);
	
	//左耳
	Bresenham(-87,134,-77,134);
	Bresenham(-87,95,-77,95);
	Bresenham(-92,129,-92,100);
	Bresenham(-72,100,-72,129);
	//圆弧
	pnarc(5,-87,129,2);
	pnarc(5,-77,129,1);
	pnarc(5,-77,100,4);
	pnarc(5,-87,100,3);
	
	//脖子
	Bresenham(-25,60,-25,76);
	Bresenham(25,60,25,76);
	
	glEnd();  
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
