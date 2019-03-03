#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstring>			// библиотека работы со строками


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char *my_strstr(char *s1, char *s2)
{
	char *p1 = s1;
	char *p2 = s2;
	int count = 0;
	while (*s1++ != '\0')
	{
		p1 = s1;
		p2 = s2;
		if (*p1 == *p2)									// находим первый совпадающий символ с искомым символом 
		{
			for (int i = 1; i < strlen(s2); i++)		// strlen вычисляет длину строки-массива
				if (s1[i] == s2[i]) count++;			// считаем символы которые идут подряд с искомыми символами
			if (count == (strlen(s2) - 1)) return p2;	// если счетчик совпадает с кол-вом символов искомого слова/строки, 
														// то возвращаем начальный адрес искомого слова/строки в вызвавшую функцию
		}
		count = 0;											// обнуляет счетчик найденных совпадающих символов, чтобы продолжить поиск 
														// искомого слова до конца строки
	}
	return 0;
}

char *changeSymbol(char *str, char search, char change)
{
	int count = 0;
	
	while (*str++ != '\0')		
	{
		if (*str == search)
		{
			*str = change;
			count++;
		}
	}
	if (count > 0) return 0;
}

void Task1()
{
	/* 1.	**Пользователь вводит строку и слово. Осуществить в этой строке поиск заданного слова. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char str[100];
	char search[50];

	cout << "Введите текст -> ";
	cin.getline(str, 100, '.');			// ввод данных пользователем из консольного окна в массив str[100]
	
	cout << endl << "Введите искомое слово в тексте -> ";
	cin >> search;

	char *p;
	//p = strstr(str, search);
	p = my_strstr(str, search);

	if (p)
		cout << endl << "Искомое слово \"" << p << "\" найдено" << endl;

	else cout <<endl<< "Искомое слово не найдено"<< endl;
}

void Task2()
{
	/* 2.	*Пользователь вводит строку, символ для поиска и символ для замены. 
	Программа заменяет все вхождения символа поиска на символ замены. */
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	char str[100];
	char search;
	char change;


	cout << endl << "Введите текст -> ";
	cin.getline(str, 100, '.');	
	cout << endl;

	cout << endl << "Введите искомый символ -> ";
	cin >> search;
	cout << endl;

	cout << "Введите символ для замены -> ";
	cin >> change;
	cout << endl;

	char *p;
	p = changeSymbol(str, search, change);

	if (p)
		cout << "Искомый символ не найден!" << endl;
	else
		cout << "Измененный текст:" << endl << str << endl;
	
}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_27_02_2019_1551281479 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;


		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
