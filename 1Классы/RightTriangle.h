#pragma once
#include "Figure.h"
#include <vector>
#include <iostream>
class RightTriangle : public Figure
{
protected:
	double m_A;
	double m_B;
	double m_C;
public:
	~RightTriangle();
	double getA();
	void setA(double A);
	double getB();
	void setB(double B);
	double getC();
	void setC(double C);

	RightTriangle();
	RightTriangle(double A, double B, double C);

	double Square();
	double Perimeter();
	std::vector<double> CountAngles();

	void Print();
};

