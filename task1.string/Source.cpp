#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int my_size(string str)
{
	int size = 0;
	for (int i = 0; str[i]; i++)
	{
		size++;
	}
	return size;
}

void my_reverse(string &str)
{
	char tmp = 't';
	for (int i = 0; i < my_size(str) / 2; i++)
	{
		tmp = str[i];
		str[i] = str[my_size(str) - 1 - i];
		str[my_size(str) - 1 - i] = tmp;

	}
}

int tranclation_13_10(string str)
{
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = number + (int(str[i]) - 48) * pow(13, i);
		}

		if (str[i] == 'A')
		{
			number = number + (int(str[i]) - 55) * pow(13, i);

		}

		if (str[i] == 'B')
		{
			number = number + (int(str[i]) - 55) * pow(13, i);
		}

		if (str[i] == 'C')
		{
			number = number + (int(str[i]) - 55) * pow(13, i);
		}

		//number = number + (int(str[i]) - 48) * pow(13, i);
	}
	return number;
}

string translation_10_5(int number)
{
	int number_tmp = number;
	string str;
	while (number_tmp != 0)
	{
		str.push_back((number_tmp % 5) + 48);
		number_tmp /= 5;
	}

	for (int i = 0; i < my_size(str) / 2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[my_size(str) - 1 - i];
		str[my_size(str) - 1 - i] = tmp;
	}
	return str;
}

int main()
{
	cout << "0 = 0, 1 = 1, 2 = 2, 3 = 3, 4 = 4, 5 = 5, 6 = 6, 7 = 7, 8 = 8, 9 = 9, A = 10, B = 11, C = 12" << endl;
	cout << "Enter numbers in thirteen system" << endl;
	string number;
	cin >> number;

	my_reverse(number);
	cout << "number_10 = " << tranclation_13_10(number) << endl;
	cout << "number_5 = " << translation_10_5(tranclation_13_10(number));

}