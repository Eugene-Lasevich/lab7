#include<iostream>
#include<string>
#include<cmath>

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

int my_size(string str)
{
    int size = 0;
    for (int i = 0; str[i]; i++)
    {
        size++;
    }
    return size;
}


long long int my_stoi(string str)
{
    long long int result = 0;
    int sign = 1;

    if (str[0] == '-')
    {
        sign = -1;
    }

    for (int i = 0; i < my_size(str); i++) 
    {
        if (str[i] != '-')
        {
            result += (int(str[i]) - 48) * pow(10, my_size(str) - 1 - i);
        }
    }

    return sign * result;
}

string conv_to_bin(const string& number)
{
    long long int tmp = my_stoi(number);
    string result;

    while (tmp != 0) 
    {
        result = char((tmp % 2)+48) + result;
        tmp /= 2;
    }

    return result;
}

string bin_counter(const int& end)  
{
    string result = "0";
    int counter = 0;
    int i = 0;
    string tmp;

    while (i < end) 
    {                                                   
        if (result[my_size(result) - 1] == '0')
        {
            result[my_size(result) - 1] = '1';
        }

        else 
        {
            counter = 0;
            while (counter < my_size(result)) 
            {
                if (result[my_size(result) - 1 - counter] == '0') 
                {
                    result[my_size(result) - 1 - counter] = '1';

                    for (int k = my_size(result) - counter; k < my_size(result); k++)
                    {
                        result[k] = '0';
                    }
                    break;
                }

                counter++;
            }

            if (counter == my_size(result)) 
            {
                for (int j = 0; j < my_size(result); j++)
                {
                    result[j] = '0';
                }
                result = '1' + result;
            }
        }

        tmp = conv_to_bin(result);                                                
        tmp = tmp.substr(my_size(tmp) - my_size(result), my_size(tmp));

        if (result == tmp) 
        {                                                    
            i++;
        }
    }
    return result;
}



int main()
{
    cout << "Program find bindecimal number. Enter serial number" << endl;
    int num = 0;
    num = input_validation(num);
    cout << bin_counter(num);
    return 0;
}