#pragma once
#include "RightTriangle.h"
class Pyramid :
	public RightTriangle
{
private:
	double m_H; // Высота пирамиды
public:
	Pyramid();
	Pyramid(double A, double B, double C, double H);

	double getH();
	void setH(double H);

	double SquareArea();
	double Volume();
	
	void Print();
};
