#include<iostream>
#include<string>

using namespace std;

int input_validation(int n)
{
	while (true)
	{
		cin >> n;
		if (!cin)
		{
			cout << "Enter invalid value" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else return n;
	}
}

string Convert(long long Number)									// перевод числа в обратный код 
{

	string StraightCode;
	long long NumberMod = abs(Number);

	while (NumberMod >= 1)											// перевод в двоичную СС
	{
		StraightCode.insert(0, 1, NumberMod % 2 + '0');
		NumberMod /= 2;
	}

	string BackCode;
	if (Number > 0)													 // если число положительное то обратный код равен прямому коду
	{
		StraightCode.insert(0, 1, '0');
		BackCode += StraightCode;
		BackCode.insert(0, 1, '0');
	}

	if (Number < 0)													// если число отрицательное то обратный код равен прямому коду с противоположными занчениями
	{
		StraightCode.insert(0, 1, '0');
		for (int i = 0; i < StraightCode.length(); i++)				// получение обратного кода, путем смены значений всех элементов
		{
			if (StraightCode[i] == '1')
			{
				StraightCode[i] = '0';
			}

			else
			{
				StraightCode[i] = '1';
			}
		}
		BackCode.push_back('1');
		BackCode += StraightCode;
	}
	else
	{
		BackCode.push_back('0');
	}
	return BackCode;
}


int main()
{
	cout << "Program will sum your numbers in the back code.\n";
	long long number1, number2;

	number1 = input_validation(number1);
	number1 = input_validation(number2);
	
	bool f = false;
	if (number1 < 0 && number2 < 0)
	{
		f = true;
		number1 *= -1;
		number2 *= -1;
	}
	string first_number, second_number;
	first_number = Convert(number1);

	second_number = Convert(number2);

	if (first_number.length() > second_number.length())
	{
		while (first_number.length() != second_number.length())
		{
			second_number.insert(2, 1, '0');
		}																	// если длина первого числа больше второго, дополнить второе нулями
	}

	if (first_number.length() < second_number.length())
	{
		while (first_number.length() != second_number.length())
		{
			first_number.insert(2, 1, '0');
		}																	// если длина второго числа больше первого, дополнить первое нулями
	}

	int count = 0;
	string result;

	for (int i = first_number.length() - 1; i >= 0; i--)					// нахождение суммы
	{
		if (count == 1)														 // счетчик на случай переполнения разряда
		{
			first_number[i]++;
			count = 0;
		}

		if (first_number[i] + second_number[i] - 96 > 1)					// условие переполнения разряда
		{
			result.insert(0, 1, '0');
			count++;
		}


		if (first_number[i] + second_number[i] - 96 == 1)
		{
			result.insert(0, 1, '1');
		}

		else
		{
			result.insert(0, 1, '0');
		}
	}

	long long new_number = 0;
	bool t = false;

	if (result[0] == '1')
	{
		t = true;
		result.erase(0, 1);
		for (int i = 0; i < result.length(); i++)							// замена записи на противоположные значения
		{
			if (result[i] == '1')
			{
				result[i] = '0';
			}

			else
			{
				result[i] = '1';
			}
		}

	}

	for (int i = result.length() - 1, j = 0; i >= 0; i--, j++)				// перевод в десятичную СС
	{
		new_number += (result[i] - '0') * pow(2, j);
	}

	if (t || f) new_number *= -1;											// проверка числа на знак
	cout << new_number << endl;
}