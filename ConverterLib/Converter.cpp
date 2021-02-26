#include "Converter.h"
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

Converter::Converter()
{
	arabic = 0;
	roman = " ";
}

Converter::Converter(int val, string v)
{
	arabic = val;
	roman = v;
}

Converter::Converter(const Converter& obj)
{
	arabic = obj.arabic;
	roman = obj.roman;
}

Converter::~Converter()
{
	arabic = 0;
	roman = "";
}

int Converter::toArabic(string d)
{
	int result = 0;
	int rem = 0;
	string ch1, ch2;
	map <string, int> mp = { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} };
	while (rem < d.length()) {
		ch1 = d[rem];
		ch2 = d[rem + 1];
		//cout << rem << endl;
		//cout << ch1 << " " << ch2 << endl;
		if (mp[ch1] < mp[ch2]) {
			result += (mp[ch2] - mp[ch1]);
			rem += 2;
		}
		else {
			result += mp[ch1];
			rem++;
		}
		if (d[rem] == 0) {

		}
		if (rem == d.length()) {
			break;
		}
		//result += mp[ch1];
		//cout << result << endl;
	}
	//cout << " " << endl;
	//cout << result << endl;
	return result;
}

string Converter::toRoman(int d)
{
	string result;
	int thousands = 0, hundreds = 0, dozens = 0, units = 0;
	thousands = d / 1000;
	hundreds = (d / 100) % 10;
	dozens = (d / 10) % 10;
	units = d % 10;
	//map <string, int> mp = { {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000} };

	result += make(thousands, "", "", "M");
	result += make(hundreds, "M", "D", "C");
	result += make(dozens, "C", "L", "X");
	result += make(units, "X", "V", "I");

	//cout << result << endl;
	return result;
}

bool Converter::check(string d)  //Проверяет правильность написания числа в "римской" форме
{
	Converter obj;
	int value = obj.toArabic(d);
	string res = obj.toRoman(value);
	return d == res;
}

string Converter::make(int num, string hi, string re, string lo)
{
	switch (num)
	{
	case 9:
	{
		return lo + hi;
	}
	case 8:
	{
		return re + lo + lo + lo;
	}
	case 7:
	{
		return re + lo + lo;
	}
	case 6:
	{
		return re + lo;
	}
	case 5:
	{
		return re;
	}
	case 4:
	{
		return lo + re;
	}
	case 3:
	{
		return lo + lo + lo;
	}
	case 2:
	{
		return lo + lo;
	}
	case 1:
	{
		return lo;
	}
	case 0:
	{
		return "";
	}
	default:
	{
		cout << "Enter the needed number please" << endl;
		return 0;
	}
	}
}

int Converter::GetArabic()
{
	return arabic;
}

string Converter::GetRoman()
{
	return roman;
}

void Converter::SetArabic(int n)
{
	arabic = n;
}

void Converter::SetRoman(string str)
{
	roman = str;
}

void Converter::ChangeFileDates(ifstream &file)
{
	//ifstream file;
	//file.open("F:\\cpptext.txt");
	Converter obj;
	string s, line, num = "";
	int pos, newnum;
	vector<char> vec = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

	//file.open("F:\\cpptext.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			s += line;
			s += " ";
		}
	}
	file.close();

	/*for (int i = 0; i < s.size(); i++) {
		if ((s[i] == 'I') || (s[i] == 'V') || (s[i] == 'X') || (s[i] == 'L') || (s[i] == 'C') || (s[i] == 'D') || (s[i] == 'M')) {
			if ((s[i + 1] == 'I') || (s[i + 1] == 'V') || (s[i + 1] == 'X') || (s[i + 1] == 'L') || (s[i + 1] == 'C') || (s[i + 1] == 'D') || (s[i + 1] == 'M')) {
				pos = s.find(" ", i + 1);
				num = "";
				num.insert(0, s, i, pos - i);
				newnum = obj.toArabic(num);
				s.erase(i, pos - i);
				s.insert(i, to_string(newnum));
				i += to_string(newnum).size();
			}
		}
	}*/

	for (int i = 0; i < s.size() - 1; i++) {
		if (find(vec.begin(), vec.end(), s[i]) != vec.end()) {
			if (find(vec.begin(), vec.end(), s[i + 1]) != vec.end()) {
				pos = s.find(" ", i);
				if ((s[pos - 1] == ',') || (s[pos - 1] == '.')) {
					num = "";
					num.insert(0, s, i, pos - 1 - i);
					//if (obj.check(num)) {
						newnum = obj.toArabic(num);
						s.erase(i, pos - 1 - i);
						s.insert(i, to_string(newnum));
						i += to_string(newnum).size();
					//}
				}
				else {
					num = "";
					num.insert(0, s, i, pos - i);
					//if (obj.check(num)) {
						newnum = obj.toArabic(num);
						s.erase(i, pos - i);
						s.insert(i, to_string(newnum));
						i += to_string(newnum).size();
					//}
				}
				
				//if (obj.check(num)) {
					/*newnum = obj.toArabic(num);
					s.erase(i, pos - i);
					s.insert(i, to_string(newnum));
					i += to_string(newnum).size();*/
				//}
			}
		}
	}
	cout << s << endl;

	ofstream newfile;
	newfile.open("F:\\cpptextres.txt");
	newfile << s << endl;
}
