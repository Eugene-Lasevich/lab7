#include <iostream>
#include <string>
#include <cmath>

using namespace std;



string roman_numerals(int number)
{
    string roman[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
    int nums[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    string res;
    for (int i = 12; i >= 0; i--)
    {  
        while (number - nums[i] >= 0)
        {
            res += roman[i];
            number -= nums[i];
        }
    }
    return res;
}

int main()
{
    cout << "This program convert arabian numbers to roman" << endl;
    int number = 0;
    cin >> number;
    cout << "Your number in roman numerals: " << roman_numerals(number);
    return 0;
}