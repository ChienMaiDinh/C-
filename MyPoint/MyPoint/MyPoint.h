#pragma once
class MyPoint
{
private:
	int mPosX;
	int mPosY;

public:
	MyPoint();	//defaul constructor
	MyPoint(int, int);//constructor
	~MyPoint(); //ham huy
	
	void Display();//print value of mPosX and mPosY

	double Distance(MyPoint p);//return distance between current point and p

	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
};

