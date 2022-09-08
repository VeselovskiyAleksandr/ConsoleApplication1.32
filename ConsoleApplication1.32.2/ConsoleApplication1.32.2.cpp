// ConsoleApplication1.32.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 29. Задача 2. Интерфейс shape.

#include <iostream>
#include <clocale>
#include <string>
#include <cmath>
using namespace std;

struct BoundingBoxDimensions {
	double width = 0, height = 0;		
};

class Shape {
protected:
	double square = 0, parametr = 0, secondParametr = 0, thirdParametr = 0;
public:
	virtual double squareShape() = 0;
	virtual BoundingBoxDimensions dimensions() = 0;
	virtual string type() = 0;
	virtual void setParametr(double param, double secondParam, double thirdParam) = 0;
	virtual double getParametr() = 0;
	virtual double getSecondParametr() = 0;
	virtual double getThirdParametr() = 0;
};

class Circle :virtual public Shape {
protected:
	double pi = 4 * atan(1);
public:
	virtual void setParametr(double param, double secondParam = 0, double thirdParam = 0) {
		parametr = param;
	}

	virtual double getParametr() {
		return parametr;
	}

	virtual double getSecondParametr() {
		return secondParametr;
	}

	virtual double getThirdParametr() {
		return thirdParametr;
	}

	virtual double squareShape() {
		square = pi * getParametr() * getParametr();
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
public:
	virtual void setParametr(double param, double secondParam, double thirdParam = 0) {
		parametr = param;
		secondParametr = secondParam;
	}

	virtual double getParametr() {
		return parametr;
	}

	virtual double getSecondParametr() {
		return secondParametr;
	}

	virtual double getThirdParametr() {
		return thirdParametr;
	}

	virtual double squareShape() {
		square = getParametr() * getSecondParametr();
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
public:
	virtual void setParametr(double param, double secondParam, double thirdParam) {
		parametr = param;
		secondParametr = secondParam;
		thirdParametr = thirdParam;
	}

	virtual double getParametr() {
		return parametr;
	}

	virtual double getSecondParametr() {
		return secondParametr;
	}

	virtual double getThirdParametr() {
		return thirdParametr;
	}

	virtual double squareShape() {
		double perimeter =(getParametr() + getSecondParametr() + getThirdParametr())/2;
		square = sqrt(perimeter*(perimeter- getParametr())*(perimeter- getSecondParametr())*(perimeter- getThirdParametr()));
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
	double par = 0, secondPar = 0, thirdPar = 0;
	Shape *shape;
	Circle circle;
	do{
	cout << "\nУкажите радиус круга.";
	cin >> par;
	if (par < 0) {
		cout << "\nРадиус круга указан неправильно.";
	}
	}while (par < 0);
	circle.setParametr(par, secondPar = 0, thirdPar = 0);
	printParams(&circle);
	Rectangle rectangle;
	do{
	cout << "\nУкажите длину прямоугольника.";
	cin >> par;
	cout << "\nУкажите щирину прямоугольника.";
	cin >> secondPar;
	if(par < 0 || secondPar < 0) {
		cout << "\nСтороны прямоугольника указаны неправильно."; }
	}while (par < 0 || secondPar < 0);
	rectangle.setParametr(par, secondPar, thirdPar = 0);
	printParams(&rectangle);
	Triangle triangle;
	do{
	cout << "\nУкажите первую сторону треугольника.";
	cin >>par;
	cout << "\nУкажите вторую сторону треугольника.";
	cin >>secondPar;
	cout << "\nУкажите третью сторону треугольника.";
	cin >> thirdPar;
	if (par < 0 || secondPar < 0 || thirdPar < 0) {
		cout << "\nCтороны треугольника указаны неправильно."; }
	}while (par < 0 || secondPar < 0 || thirdPar < 0);
	triangle.setParametr(par, secondPar, thirdPar);
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
