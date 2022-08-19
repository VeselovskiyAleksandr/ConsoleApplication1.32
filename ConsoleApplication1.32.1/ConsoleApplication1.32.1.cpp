// Cons. Задача oleApplication1.32.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы..
// Урок 29. Задача 1. Суперпёс.

#include <iostream>
#include <string>
#include <clocale>
#include <vector>
using namespace std;

class Talents {
public:
	virtual string talent() = 0;
};

class Swimming: public Talents{
public:
	virtual string talent() {
		string str = "\nОн(а) умеет плавать.";
		return str;
	}
	Swimming() {
		talent();
	};
};

class Dancing : public Talents {
public:
	virtual string talent() {
		string str = "\nОн(а) умеет танцевать.";
		return str;
	}
	Dancing() {
		talent();
	};
};

class Counting : public Talents {
public:
	virtual string talent() {
		string str= "\nОн(а) умеет считать.";
		return str;
	}
	Counting() {
		talent();
	};
};

class Dog {
	string name = "";
	vector<string> storageTalants;
public:
     void	setdogName(string dogName) {
		name = dogName;
	};

	string getName() {
		return name;
	}

	void downloadTalants() {
		Dancing dancing;
		Counting counting;
		storageTalants.push_back(dancing.talent());
		storageTalants.push_back(counting.talent());
	}

	void showTalents() {
		for (int i = 0; i < storageTalants.size(); ++i) {
			cout << storageTalants[i];
}
}
		Dog (string inname): name(inname) {
			setdogName(inname);
			cout << "\nЭто " << getName();
	}
};

int main()
{ 
	setlocale(LC_ALL, "rus");
	Dog dog1("Шарик");
	dog1.downloadTalants();
	dog1.showTalents();
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
