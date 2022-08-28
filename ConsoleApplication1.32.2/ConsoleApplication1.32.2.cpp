// ConsoleApplication1.32.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 29. Задача 2. Интерфейс shape.

#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

struct BoundingBoxDimensions {
	double width = 0, height = 0;		
};

class Shape {
public:
	virtual double square() = 0;
	virtual BoundingBoxDimensions dimensions() = 0;
	virtual string type() = 0;
};

class Circle : public Shape {
protected:
	double pi = 4* atan(1), square = 0, radius=5;

public:
	virtual double square() {
		square = pi * radius*radius;
		return square;
	}

	virtual string type() {
		string str = " Круг.";
		return str;
	}

	BoundingBoxDimensions boundingBoxCircle;

	BoundingBoxDimensions dimensions() {
		BoundingBoxDimensions boundingBoxCircle;
		boundingBoxCircle.width = 2 * radius;
		boundingBoxCircle.height = 2 * radius;
	}

	void printParams(Shape* shape) {
		cout << "\nФигура: " << shape->type();
		cout << "\nПлощадь: " << shape->square();
		cout << "\nШирина описывающего прямоугольника: " << boundingBoxCircle.width;
		cout << "\nВысота описывающего прямоугольника: " << boundingBoxCircle.height;
	}

	Circle( inradius): radius(inradius) {
	//	Circle circle();
	//	square(inradius);
		dimensions();

	};
};

class Triangle : public Shape {
public:
	
};

class Rectangle :public  Shape {
	double secondParametr = 0, coordY = 0;
public:
	void setHandInput(double secPar) {
		secondParametr = secPar;
	}

	double getSecondParametr() {
		return secondParametr;
	}

	double getSquare() {
	//	return getParametr() * getSecondParametr();
	}

	double getCoordY() {
		return getSecondParametr() / 2;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Circle circle(5.);
//	circle->square();
	//сircle->printParams(*circle);
	//circle->dimensions();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
