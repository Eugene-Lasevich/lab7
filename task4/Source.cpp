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

void my_reverse(string& str)
{
	char tmp = 't';
	for (int i = 0; i < my_size(str) / 2; i++)
	{
		tmp = str[i];
		str[i] = str[my_size(str) - 1 - i];
		str[my_size(str) - 1 - i] = tmp;

	}
}


void compare_add(string& str1, string& str2, string& new_str, int i, int j)
{
	int tmp;
	if (str1[i] - '0' + str2[j] - '0' >= 13 || str1[i] - '7' + str2[j] - '0' >= 13 || str1[i] - '0' + str2[j] - '7' >= 13 || str1[i] - '7' + str2[j] - '7' >= 13)								//Если переход в другой разряд 
	{
		if (str1[i] - '0' + str2[j] - '0' >= 13 && (str1[i] >= '0' && str1[i] <= '9') && (str2[j] >= '0' && str2[j] <= '9'))
		{
			tmp = str1[i] - '0' + str2[j] - '0';		 // Две цифры

			new_str.push_back(tmp % 13 + 48);


			if (i + 1 > my_size(str1) - 1)				// Выход за границы строки
			{
				str1.resize(str1.size() + 1);
			}

			if (i + 1 <= str1.size() - 1)				// Расширение строки
			{
				str1[i + 1] = str1[i + 1] + '1';
			}
			
			return;
		}

		if (str1[i] - '7' + str2[j] - '0' >= 13 && (str1[i] >= 'A' && str1[i] <= 'C') && (str2[j] >= '0' && str2[j] <= '9'))
		{
			tmp = str1[i] - '7' + str2[j] - '0';		// Буква и цифра
			new_str.push_back(tmp % 13 +48);

			if (i + 1 > my_size(str1) - 1)
			{
				str1.resize(str1.size() + 1);
			}

			if (i + 1 <= str1.size() - 1)
			{
				str1[i + 1] = str1[i + 1] + '1';
			}

			return;
		}

		if (str1[i] - '0' + str2[j] - '7' >= 13 && (str1[i] >= '0' && str1[i] <= '9') && (str2[j] >= 'A' && str2[j] <= 'C'))
		{
			tmp = str1[i] - '0' + str2[j] - '7';		// Цифра и буква
			new_str.push_back(tmp % 13 +48);

			if (i + 1 > my_size(str1) - 1)
			{
				str1.resize(str1.size() + 1);
			}

			if (i + 1 <= str1.size() - 1)
			{
				str1[i + 1] = str1[i + 1] + '1';
			}

			return;
		}

		if (str1[i] - '7' + str2[j] - '7' >= 13 && (str1[i] >= 'A' && str1[i] <= 'C') && (str2[j] >= 'A' && str2[j] <= 'C'))
		{
			tmp = str1[i] - '7' + str2[j] - '7';		//две буквы
			if (tmp % 13 < 10)
			{
				new_str.push_back(tmp % 13 + 48);		//добавление числа

				if (i + 1 > my_size(str1) - 1)
				{
					str1.resize(str1.size() + 1);
				}

				if (i + 1 <= str1.size() - 1)
				{
					str1[i + 1] = str1[i + 1] + '1';
				}

			}

			if (tmp % 13 == 10)
			{
				new_str.push_back('A');					// добавление буквы А

				if (i + 1 > my_size(str1) - 1)
				{
					str1.resize(str1.size() + 1);
				}

				if (i + 1 <= str1.size() - 1)
				{
					str1[i + 1] = str1[i + 1] + 1;
				}
			}
		
			if(tmp % 13 == 11)
			{
				new_str.push_back('B');					// добаввление буквы В

				if (i + 1 > my_size(str1) - 1)
				{
					str1.resize(str1.size() + 1);
				}

				if (i + 1 <= str1.size() - 1)
				{
					str1[i + 1] = str1[i + 1] + 1;
				}
			}

			return;
		}
	}

	if (str1[i] - '0' + str2[j] - '0' == 12 || str1[i] - '7' + str2[j] - '0' == 12 || str1[i] - '0' + str2[j] - '7' == 12 || str1[i] - '7' + str2[j] - '7' == 12)								// нет перехода в следующий разряд
	{
		new_str.push_back('C');
		return;

	}

	if (str1[i] - '0' + str2[j] - '0' == 11 || str1[i] - '7' + str2[j] - '0' == 11 || str1[i] - '0' + str2[j] - '7' == 11 || str1[i] - '7' + str2[j] - '7' == 11)
	{
		new_str.push_back('B');
		return;
	}

	if (str1[i] - '0' + str2[j] - '0' == 10 || str1[i] - '7' + str2[j] - '0' == 10 || str1[i] - '0' + str2[j] - '7' == 10 || str1[i] - '7' + str2[j] - '7' == 10)
	{
		new_str.push_back('A');
		return;
	}

	if ((str1[i] - '0') + (str2[j] - '0') <= 9 && (str1[i] - '0') + (str2[j] - '0') >= 0)
	{
		new_str.push_back((str1[i] - '0' + str2[j] - '0') + '0');
		return;
	}


}

void compare_add(string str1, string& new_str, int i)
{
	if (str1[i] - '7'  == 12 )								// Если одна строка больше другой
	{
		new_str.push_back('C');
		return;

	}

	if (str1[i] - '7' == 11)
	{
		new_str.push_back('B');
		return;
	}

	if (str1[i] - '7' == 10)
	{
		new_str.push_back('A');
		return;
	}

	if ((str1[i] - '0') <= 9 && (str1[i] - '0') >= 0)
	{ 
		new_str.push_back(str1[i]);
		return;
	}
}



int main()
{
	string str1, str2, new_str;
	cout << "Enter two number in 13 system" << endl;
	cin >> str1;
	cin >> str2;

	int size1 = my_size(str1);
	int size2 = my_size(str2);

	my_reverse(str1);
	my_reverse(str2);

	int size1_tmp = 0;
	int size2_tmp = 0;

	for (int i = 0, j = 0; i < str1.size() || j < str2.size(); i++, j++)
	{
		while(size1_tmp == size2_tmp)
		{
	
			compare_add(str1, str2, new_str, i, j);
			size1_tmp++; i++;
			size2_tmp++; j++;

			if (size1_tmp == str1.size())
			{
				i++;
				break;
			}

			if (size2_tmp == str2.size())
			{
				j++;
				break;
			}


		}
				

		if ( str1.size() > size2_tmp)
		{
			if (str1[i] - '0' < 13 || str1[i] - '7'  < 13)
			{
				compare_add(str1, new_str, i);
			}
		
		}

		if ( str2.size() > size1_tmp)
		{
			if  (str2[j] - '0' < 13 || str2[j] - '7' < 13 )
			{
				compare_add(str2, new_str, j);
			}
		
		}
	}


	my_reverse(new_str);
	cout <<"new_str = " << new_str;
	//main();
	
}