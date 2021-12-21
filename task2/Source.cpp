#include<iostream>
#include<string>
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

int tranclation_2_10(string str)
{
	int number = 0;


	if (str[my_size(str) - 1] == '0')
	{
		for (int i = 0;i<my_size(str)-1; i++)
		{

			if (str[i] >= '0' && str[i] <= '1')
			{
				number = number + (int(str[i]) - 48) * pow(2, i);
			}

		}
		return number;
	}

	else
	{
		for (int i = 0; i < my_size(str); i++)
		{
			if (str[i] == '1')
			{
				str[i] = '0';
			}
			else
			{
				str[i] = '1';
			}
		}

		for (int i = 0; i < my_size(str) - 1; i++)
		{
			if (str[i] >= '0' && str[i] <= '1')
			{
				number = number + (int(str[i]) - 48) * pow(2, i);
			}

		}
		return -number;
	}
}

int main()
{
	cout << "The program converts the number from the reverse code to the natural form" << endl << endl;
	cout << "The first digit is signed" << endl;
	string num;
	cout << "Enter the number in the reverse code" << endl;
	cin >> num;

	my_reverse(num);
	cout << tranclation_2_10(num) << endl;


}