#include <iostream>
#include <fstream>
#include <string>
#include "Converter.h"


int main(){
    setlocale(LC_ALL, "Russian");
    //printf("hello!\n");

    bool over = false;
    int choose = 0, num = 0;
    string str, s;
    string str_1 = "You're ";
    string str_2 = "breathtaking!";
    //str_1.append(str_2);
    str = str_1 + str_2;
    cout << str << endl;

    Converter number(2077, "MMLXXVII");
    //cout << number << endl;
    //cin >> number;
    //cout << number << endl;
    cout << "Cyberpunk" << " ";
    number.toArabic("MMLXXVII");
    cout << "That's 2077 in roman: ";
    number.toRoman(2077);

    //--------------------------------------

    while (true) {
        cout << "Choose the action you want to perform: " << endl;
        cout << "1. Convert the number from roman to arabic;" << endl;
        cout << "2. Convert the number from arabic to roman;" << endl;
        cout << "3. Convert the dates in file from roman to arabic format;" << endl;
        cout << "4. Check if the entered roman number is correct;" << endl;
        cout << "5. Exit the program." << endl;
        cout << endl;

        cin >> choose;

        
        switch (choose) {
        case 1: {
            //number.toArabic(number.GetRoman());
            cout << "Enter the roman number you want to convert: ";
            cin >> s;
            cout << number.toArabic(s) << endl;
            cout << endl;
            break;
        }
        case 2: {
            //number.toRoman(number.GetArabic());
            cout << "Enter the arabic number you want to convert: ";
            cin >> num;
            cout << number.toRoman(num) << endl;
            cout << endl;
            break;
        }
        case 3: {
            string filename;
            cout << "Please enter the name of text file you want to open: ";
            cin >> filename;
            ifstream file;
            file.open(filename);
            number.ChangeFileDates(file);
            cout << endl;
            break;
        }
        case 4: {
            string number;
            Converter obj;
            cout << "Please enter the roman number you want to check: ";
            cin >> number;
            if (obj.check(number)) {
                cout << "The entered number is correct!" << endl;
            }
            else {
                cout << "The entered number is incorrect!" << endl;
            }
            cout << endl;
            break;
        }
        case 5: {
            over = true;
            break;
        }
        }
        
        if (over == true)
            break;
    }

    cout << "The program has been executed successfully!" << endl;

    return 0;
}
