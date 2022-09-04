﻿// ConsoleApplication1.32.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	virtual double squareShape() = 0;
	virtual BoundingBoxDimensions dimensions() = 0;
	virtual string type() = 0;
	virtual void printParams(Shape* shape) {
		cout << "Type: " << shape->type();
	};
};

class Circle :virtual public Shape {
protected:
	double pi = 4 * atan(1), square = 0;

public:
	double parametr=0;

	virtual double squareShape() {
		square = pi * parametr * parametr;
		return square;
	};

	virtual string type() {
		string str = " Круг.";
		return str;
	}
		BoundingBoxDimensions boundingBoxCircle;

		virtual BoundingBoxDimensions dimensions() {
			boundingBoxCircle.width = 2 * parametr;
			boundingBoxCircle.height = 2 * parametr;
		 cout << "\nШирина описывающего прямоугольника: " << boundingBoxCircle.width;
		 cout << "\nВысота описывающего прямоугольника: " <<boundingBoxCircle.height;
		 return boundingBoxCircle;
		}
};

class Rectangle: virtual public Shape {
protected:
	double square = 0;

public:
	double parametr = 0, secondParametr=0;

	virtual double squareShape() {
		square = parametr * secondParametr;
		return square;
	};

	virtual string type() {
		string str = " Прямоугольник.";
		return str;
	}
	BoundingBoxDimensions boundingBoxRectangle;

	virtual BoundingBoxDimensions dimensions() {
		boundingBoxRectangle.width = parametr;
		boundingBoxRectangle.height = secondParametr;
		cout << "\nШирина описывающего прямоугольника: " << boundingBoxRectangle.width;
		cout << "\nВысота описывающего прямоугольника: " << boundingBoxRectangle.height;
		return boundingBoxRectangle;
	}
};

class Triangle: virtual public Shape {
protected:
	double square = 0;

public:
	double parametr = 0, secondParametr = 0, thirdParametr=0;

	virtual double squareShape() {
		double perimeter =(parametr + secondParametr + thirdParametr)/2;
		square = sqrt(perimeter*(perimeter- parametr)*(perimeter- secondParametr)*(perimeter- thirdParametr));
		return square;
	};

	virtual string type() {
		string str = " Треугольник.";
		return str;
	}
	BoundingBoxDimensions boundingBoxTriangle;

	virtual BoundingBoxDimensions dimensions() {
		boundingBoxTriangle.width = (parametr* secondParametr* thirdParametr)/(2* squareShape());
		boundingBoxTriangle.height = (parametr * secondParametr * thirdParametr) / (2 * squareShape());
		cout << "\nШирина описывающего прямоугольника: " << boundingBoxTriangle.width;
		cout << "\nВысота описывающего прямоугольника: " << boundingBoxTriangle.height;
		return boundingBoxTriangle;
	}
};

 void printParams(Shape* shape) {
			cout << "\nФигура: " << shape->type();
		    cout << "\nПлощадь: " << shape->squareShape();
			shape->dimensions();
		}

int main()
{
	setlocale(LC_ALL, "rus");
	Shape *shape;
	Circle circle;
	cout << "\nУкажите радиус круга.";
	cin >> circle.parametr;
	printParams(&circle);
	Rectangle rectangle;
	cout << "\nУкажите длину прямоугольника.";
	cin >> rectangle.parametr;
	cout << "\nУкажите щирину прямоугольника.";
	cin >> rectangle.secondParametr;
	printParams(&rectangle);
	Triangle triangle;
	cout << "\nУкажите первую сторону треугольника.";
	cin >> triangle.parametr;
	cout << "\nУкажите вторую сторону треугольника.";
	cin >> triangle.secondParametr;
	cout << "\nУкажите третью сторону треугольника.";
	cin >> triangle.thirdParametr;
	printParams(&triangle);
	return 0;
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
