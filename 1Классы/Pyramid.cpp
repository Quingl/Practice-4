#include "Pyramid.h"
Pyramid::Pyramid() {};
Pyramid::Pyramid(double A, double B, double C, double H) {
	try
	{
		if (A <= 0 || B <= 0 || C <= 0)
		{
			std::string e = "���� �� ������ ��������� �������� ������ ���� ����� 0";
			throw e;
		}
		if (H == 0)
		{
			std::string e = "������ �������� ������ ���� ����� 0";
			throw e;
		}
		if (A + B <= C || C + B <= A || A + C <= B)
		{
			std::string e = "� ��������� �������� ����� ���� ������ ������ ������� �������";
			throw e;
		}
		if (!(A * A + B * B == C * C || B * B + C * C == A * A || A * A + C * C == B * B))
		{
			std::string e = "������ �� ������������� ����������� � ��������� ��������";
			throw e;
		}
		setA(A);
		setB(B);
		setC(C);
		setH(H);
	}
	catch (std::string e)
	{
		std::cout << "������������ ������ � �����. " << e;
		throw 1;
		//exit(0);
	}
}

double Pyramid::getH() { return m_H; }
void Pyramid::setH(double H) { m_H = H; }

double Pyramid::SquareArea() {// ������� �����������
	double Sosn = RightTriangle(m_A, m_B, m_C).Square();// ������� � ���������
	double P = (getA() + m_B + m_C) / 2; // ������������

	double R = sqrt(((P-m_A) * (P - m_B) * (P - m_C))/P);// ������ ���������� ��������� � �������������� ����������� � ���������.
	
	
	double HBokStor = sqrt(R*R + m_H*m_H); // ������ ������� �������
	double cosfi = R/ HBokStor; //������� ���� ����� ������� �������� � �������� �������� ����������

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


