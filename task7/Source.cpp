#include<iostream>
using namespace std;

int main()
{
	cout << "Enter the number" << endl;

	int n = 0, tmp = 0;
	cin >> n;

	while (tmp != n)
	{
		if (tmp < n)
		{
			tmp += 7;
		}

		if (tmp > n)
		{
			cout << "This number is NOT divisible by a prime number 7" << endl << endl;
			break;
		}

		if (tmp == n)
		{
			cout << "The given number is divisible by a prime number 7" << endl << endl;
		}
	}

	tmp = 0;

	while (tmp != n)
	{
		if (tmp < n)
		{
			tmp += 29;
		}

		if (tmp > n)
		{
			cout << "This number is NOT divisible by a prime number 29" << endl << endl;
			break;
		}

		if (tmp == n)
		{
			cout << "The given number is divisible by a prime number 29" << endl << endl;
		}
	}

	tmp = 0;

	while (tmp != n)
	{
		if (tmp < n)
		{
			tmp += 149;
		}

		if (tmp > n)
		{
			cout << "This number is NOT divisible by a prime number 149" << endl << endl;
			break;
		}

		if (tmp == n)
		{
			cout << "The given number is divisible by a prime number 149" << endl << endl;
		}
	}
}