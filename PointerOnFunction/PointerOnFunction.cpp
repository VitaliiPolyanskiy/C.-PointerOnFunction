#include <iostream>
#include <ctime>

using namespace std;

double Add(double a, double b)
{
	return a + b;
}

double Sub(double a, double b)
{
	return a - b;
}

double Mult(double a,double b)
{
	return a * b;
}

double Div(double a,double b)
{
	return a / b;
}

bool compare(int a, int b)
{
	return a < b ? true : false;
}

bool compare_descending(int a, int b)
{
	return a > b ? true : false;
}

bool compare_negative_positive(int a, int b)
{
	return a < 0 && b >= 0 ? true : false;
}

void sort(int* ptr, int size, bool(*p) (int, int))
{
	for (int i = 1; i < size; i++)
	{
		int key = ptr[i];
		int j = i - 1;
		while (j >= 0 && p(key, ptr[j]))
		{
			ptr[j + 1] = ptr[j];
			j--;
		}
		ptr[j + 1] = key;
	}
}

void print(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << '\t';
	}
	cout << endl;
}

void init(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 41 - 20;
	}
	cout << endl;
}

/*
	Указатель на функцию содержит адрес в сегменте кода, 
	по которому располагается исполняемый код функции, 
	то есть адрес, по которому передается управление при вызове функции. 
	Указатели на функции используются для косвенного вызова функции 
	(не через ее имя, а через обращение к переменной, хранящей ее адрес), 
	а также для передачи имени функции в другую функцию в качестве параметра. 
	Указатель функции имеет тип «указатель функции, возвращающей значение 
	заданного типа и имеющей аргументы заданного типа»: 
	тип (*имя) ( список_типов_аргументов ); 
	Например, объявление: int (*fun) (double, double); задает указатель с именем fun 
	на функцию, возвращающую значение типа int и имеющую два аргумента типа double.
*/

int main()
{
	srand(time(0));
	int arr[10];
	void(*ptr)(int*, int);
	ptr = init;
	ptr(arr, 10);
	ptr = print;
	cout << "Unordered array: \n";
	ptr(arr, 10);
	sort(arr, 10, compare);
	cout << "Ordered array by ascending: \n";
	ptr(arr, 10);
	sort(arr, 10, compare_descending);
	cout << "Ordered array by descending: \n";
	ptr(arr, 10);

	ptr = init;
	ptr(arr, 10);
	ptr = print;
	cout << "Unordered array: \n";
	ptr(arr, 10);
	sort(arr, 10, compare_negative_positive);
	cout << "Ordered array: \n";
	ptr(arr, 10);


	double(*p[4])(double, double) = { Add, Sub, Mult, Div };
	double n1, n2;
	int choice;
	cout << "Enter two number: ";
	cin >> n1 >> n2;
	cout << "\n1.+\n2.-\n3.*\n4./\n";
	cout << "Make your choice: ";
	cin >> choice;
	if (choice < 1 || choice > 4)
	{
		cout << "Incorrect choice!!!";
		return 0;
	}
	cout << "Result: ";
	cout << p[choice - 1](n1, n2);
	cout << endl;

	return 0;
}



