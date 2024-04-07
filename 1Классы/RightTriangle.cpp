#include "RightTriangle.h"
#include <iostream>



RightTriangle::~RightTriangle(){}

double RightTriangle::getA() { return m_A; }
void RightTriangle::setA(double A) { m_A = A; }
double RightTriangle::getB() { return m_B; }
void RightTriangle::setB(double B) { m_B = B; }
double RightTriangle::getC() { return m_C; }
void RightTriangle::setC(double C) { m_C = C; }

RightTriangle::RightTriangle () {};
RightTriangle::RightTriangle(double A, double B, double C)
{
	try
	{
		if (A <= 0 || B <= 0 || C <= 0)
		{
			std::string e = "Одна из сторон меньше либо равна 0";
			throw e;
		}
		if (A + B <= C || C + B <= A || A + C <= B)
		{
			std::string e = "Сумма двух сторон меньше третьей стороны";
			throw e;
		}
		if (!(A * A + B * B == C * C || B * B + C * C == A * A || A * A + C * C == B * B))
		{
			std::string e = "Введен не прямоугольный треугольник";
			throw e;
		}
		setA(A);
		setB(B);
		setC(C);
	}
	catch(std::string e)
	{
		std::cout << "Некорректные данные в файле. " << e;
		throw 1;
	}

}
//Площадь
double RightTriangle::Square() {
	return sqrt(((m_A + m_B + m_C) / 2) * (((m_A + m_B + m_C) / 2) - m_A) * (((m_A + m_B + m_C) / 2) - m_B) * (((m_A + m_B + m_C) / 2) - m_C));
}
double RightTriangle::Perimeter() {
	return m_A + m_B + m_C;

}
void RightTriangle::Print() {
	std::cout << "RightTriangle ";
	std::cout << getA() << " " << getB() << " " << getC();
}
std::vector<double> RightTriangle::CountAngles() {
	std::vector<double> Angles;
	Angles.push_back(acos((m_B * m_B + m_C * m_C - m_A * m_A) / (2 * m_C * m_B)) * 180 / 3.14);
	Angles.push_back(acos((m_C * m_C - m_B * m_B + m_A * m_A) / (2 * m_C * m_A)) * 180 / 3.14);
	Angles.push_back(acos((m_B * m_B - m_C * m_C + m_A * m_A) / (2 * m_B * m_A)) * 180 / 3.14);

	return Angles;
}




