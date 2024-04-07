#include "Pyramid.h"
Pyramid::Pyramid() {};
Pyramid::Pyramid(double A, double B, double C, double H) {
	try
	{
		if (A <= 0 || B <= 0 || C <= 0)
		{
			std::string e = "Одна из сторон основания пирамиды меньше либо равна 0";
			throw e;
		}
		if (H == 0)
		{
			std::string e = "Высота пирамиды меньше либо равна 0";
			throw e;
		}
		if (A + B <= C || C + B <= A || A + C <= B)
		{
			std::string e = "В основании пирамиды сумма двух сторон меньше третьей стороны";
			throw e;
		}
		if (!(A * A + B * B == C * C || B * B + C * C == A * A || A * A + C * C == B * B))
		{
			std::string e = "Введен не прямоугольный треугольник в основании пирамиды";
			throw e;
		}
		setA(A);
		setB(B);
		setC(C);
		setH(H);
	}
	catch (std::string e)
	{
		std::cout << "Некорректные данные в файле. " << e;
		throw 1;
		//exit(0);
	}
}

double Pyramid::getH() { return m_H; }
void Pyramid::setH(double H) { m_H = H; }

double Pyramid::SquareArea() {// Площадь поверхности
	double Sosn = RightTriangle(m_A, m_B, m_C).Square();// Площадь в основании
	double P = (getA() + m_B + m_C) / 2; // полупериметр

	double R = sqrt(((P-m_A) * (P - m_B) * (P - m_C))/P);// радиус окружности вписанной в прямноугольный треугольник в основании.
	
	
	double HBokStor = sqrt(R*R + m_H*m_H); // высота боковой стороны
	double cosfi = R/ HBokStor; //косинус угла между боковой стороной и радиусом вписаной окружности

	return Sosn*(1+1/ cosfi);

}

double Pyramid::Volume() {
	double Sosn = RightTriangle(m_A, m_B, m_C).Square(); 
	return 1.00 / 3.00 * Sosn * m_H;

}

void Pyramid::Print() {
	std::cout << "Pyramid ";
	std::cout << getA() << " " << getB() << " " << getC() << " " << getH();
}


