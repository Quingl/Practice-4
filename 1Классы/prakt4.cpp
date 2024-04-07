// prakt4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include "RightTriangle.h"
#include <vector>
#include "Figure.h"
#include "Pyramid.h"
#include "typeinfo.h"

using namespace std;
void func1(vector<Figure*>& figs) {
	ifstream fin("input.txt");
	
	while (!fin.eof()) {
		int fig_id;
		double a, b, c, h;
		fin >> fig_id;
		switch (fig_id)
		{
		case 1: {
			fin >> a >> b >> c;
			fin.get();
			try 
			{
				figs.push_back(new RightTriangle(a, b, c));
			}
			catch (int i)
			{
				figs.clear();
				exit(0);
			};
			break;
		}
		case 2: {
			fin >> a >> b >> c >> h;
			fin.get();
			try 
			{
				figs.push_back(new Pyramid(a, b, c, h));
			}
			catch (int i) 
			{ 
				figs.clear();
				exit(0);
			};
			break;
		}
		default:
			break;
		}

	}
}

void func2(vector<Figure*>& figs) {
	for (int i = 0; i < figs.size(); i++) {
		figs[i]->Print();
		cout << endl;

	}
}

void func3(vector<Figure*>& figs) {
	double MinAngle = 90, Vsr = 0;
	int CountPyramid = 0;
	RightTriangle* TriangleWithMinAngle = NULL;
	
	for (int i = 0; i < figs.size(); i++)
	{
		string ClassName = typeid(*figs[i]).name();
		
		if (ClassName == "class RightTriangle")
		{
			RightTriangle* tempTriangle = dynamic_cast<RightTriangle*>(figs[i]);

			vector<double> Angles = tempTriangle->CountAngles();
			if (MinAngle > Angles[0])
			{
				MinAngle = Angles[0];
				TriangleWithMinAngle = tempTriangle;
			}
			if (MinAngle > Angles[1])
			{
				MinAngle = Angles[1];
				TriangleWithMinAngle = tempTriangle;
			}
			if (MinAngle > Angles[2])
			{
				MinAngle = Angles[2];
				TriangleWithMinAngle = tempTriangle;
			}
		}
		else
		{	
			CountPyramid++;
			Pyramid* tempPyramid = dynamic_cast<Pyramid*>(figs[i]);
			Vsr += tempPyramid->Volume();
		}
		

	}
	cout << "Треугольник с минимальным углом ";
	cout << endl;
	TriangleWithMinAngle->Print();
	cout << endl;
	cout << "минимальный угол ";
	cout << endl;
	cout << MinAngle;
	cout << endl;
	cout << "средний объем пирамид ";
	cout << endl;
	cout << Vsr / (double)CountPyramid;
}

int main()
{ 
	setlocale(LC_ALL, "Rus");
	
	vector<Figure*> s;
	func1(s);
	func2(s);
	func3(s);

	s.clear();
	return 0;
}