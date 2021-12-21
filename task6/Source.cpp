#include <iostream>
#include <string>
using namespace std; 

int input_validation()     
{
    char str[13];
    bool is_not_number;

    do 
    {
        is_not_number = false;
        cin >> str;
        for (int i = 0; i < strlen(str); i++) 
        {
            if (str[i] < '0' || str[i] > '9' || atoi(str) > pow(10, 9))
            {
                cout << "\nInvalid input. Try again.\n";
                is_not_number = true;
                break;
            }
        }
    } 
    while (is_not_number);

    return atoi(str);
}

int main()
{
    unsigned int number = 0, sets = 0;
    cout << "Enter number of input sets"<<endl;
    sets = input_validation();

    unsigned int* arr = new unsigned int[sets];

    cout << "Enter your data" << endl;
    for (int i = 0; i < sets; i++) 
    {
        arr[i] = input_validation();
    }

    for (int i = 0; i < sets; i++) 
    {
        if (arr[i] % 10 == 9)
        {
            cout << arr[i] / 10 + 1 << endl;
        }

        else
        {
            cout << arr[i] / 10 << endl;
        }
    }

    delete[] arr;


    return 0;
}