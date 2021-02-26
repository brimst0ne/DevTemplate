#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//struct roman {
//	std::string var;
//};
//
//struct arabic {
//	int value;
//};

//----------------------------------------------------

class Converter {
public:
	Converter();
	Converter(int val, string v);
	Converter(const Converter& obj);
	~Converter();
	friend ostream& operator <<(ostream& out, const Converter& obj) {
		out << "Arabic number: " << obj.arabic << "\n" << "Roman number: " << obj.roman <<endl;
		return out;
	}
	friend istream& operator >>(istream& in, Converter& obj) {
		in >> obj.arabic >> obj.roman;
		return in;
	}


	int toArabic(string d);
	string toRoman(int d);

	bool check(string d);
	string make(int num, string hi, string re, string lo);

	int GetArabic();
	string GetRoman();

	void SetArabic(int n);
	void SetRoman(string str);

	void ChangeFileDates(ifstream &file);

private:
	int arabic;
	string roman;
};


