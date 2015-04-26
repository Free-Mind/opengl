#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdlib.h>
#include <iostream>
using namespace std;
class Robot{
	//正负法画圆
	public:
	void pnarc(int radius,int rx,int ry,int situation);
	//bresenham算法画圆
	void bresenham_acc(int r,int rx,int ry,int situation);
	void draw(int x,int y,int r,int rx,int ry,int situation);
	//bresenham算法画直线
	void Bresenham(int xs,int ys,int xe,int ye);
	
	static void disPlay(void);
	
	int show(int argc, char *argv[]);
};
#endif
