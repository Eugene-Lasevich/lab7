#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int size_number(int number)
{
	int size = 0;
	while (number != 0)
	{
		number /= 10;
		size++;
	}
	return size;
}

int reverse_number(int number)
{
	int number_tmp = number;
	int reverse = 0;
	for (int i = 1; i <= size_number(number); i++)
	{
		int tmp = number_tmp % 10;
		reverse += tmp * pow(10, size_number(number) - i);
		number_tmp /= 10;
	}
	return reverse;
}

int translation_10_5(int number)
{
	int number_5 = 0, number_tmp = number;;

	int i = 0;
	while (number_tmp != 0)
	{
		number_5 = (number_5 * 10 + number_tmp % 5);
		number_tmp /= 5;
		i++;
	}
	return reverse_number(number_5);

}

int recursive_input(char a)
{
	static int  k = 0;
	//cout << "i  = " << i << endl;
	static int sum = 0;
	int num = 0;
	if (a == '\n')
	{
		return 0;
	}

	else
	{

		if (a >= '0' && a <= '9')
		{
			recursive_input(cin.get());
			num = (a - '0');
			k++;
			sum += num * pow(13, k - 1);
			//cout << "K  = " << k << endl;
		}

		if (a == 'A')
		{
			recursive_input(cin.get());
			num = (a - '7');
			k++;
			sum += num * pow(13, k - 1);
			//cout << "kA  = " << k << endl;
		}

		if (a == 'B')
		{
			recursive_input(cin.get());
			num = (a - '7');
			k++;
			sum += num * pow(13, k - 1);
			//cout << "kB  = " << k << endl;
		}

		if (a == 'C')
		{
			recursive_input(cin.get());
			num = (a - '7');
			k++;
			sum += num * pow(13, k - 1);
			//cout << "kC  = " << k << endl;
		}

	}
	return sum;

}

int main()
{
	int num = recursive_input(cin.get());
	cout << num << endl;
	cout << translation_10_5(num);
}