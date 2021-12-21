#include <iostream>
#include <cmath>
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


string translation_10_3(int number)
{
	int number_tmp = number;
	string str;
	while (number_tmp != 0)
	{	
			str.push_back((number_tmp % 3)+48);
			number_tmp /= 3;		
	}

	for (int i = 0;i< my_size(str)/2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[my_size(str) - 1 - i];
		str[my_size(str) - 1 - i] = tmp;
	}
	return str;
}


string translation_10_3_1(const string& num)
{
	string result = num;
	for (int i = 1; i < my_size(result); i++)
	{
		if (result[i] == '0') 
		{
			result[i - 1] = char((int)result[i - 1] - 1);
			result[i] = '3';
		}
	}

	return result;
}
int main()
{
	int n = 0;
	cin >> n;
	string str =  translation_10_3(n);
	cout << translation_10_3_1(str);
}
