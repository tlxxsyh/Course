//============================================================================  
// Name        : Fraction.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.12.12
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : 第六章实验：分数加减乘除的运算符重载，包括友元和成员函数的两种实现方式
//============================================================================
#include<iostream>
#include <cstring>

using namespace std;

class Fraction {
private:
	int numerator, denominator;
	int common_divisor() {	};
	int contracted() {	};
public:
	Fraction(int a = 1, int b = 2) {
		numerator = a;
		denominator = b;
	}
	Fraction(Fraction& f) {
		numerator = f.numerator;
		denominator = f.denominator;
	}
	Fraction operator+(Fraction& f) {
		Fraction temp;
		temp.numerator = numerator * f.denominator + f.numerator * denominator;
		temp.denominator = denominator * f.denominator;
		return temp;
	}
	Fraction operator-(Fraction& f) {
		Fraction temp;
		temp.numerator = numerator * f.denominator - f.numerator * denominator;
		temp.denominator = denominator * f.denominator;
		return temp;
	}
	Fraction operator*(Fraction& f) {
		Fraction temp;
		temp.numerator = numerator * f.numerator;
		temp.denominator = denominator * f.denominator;
		return temp;
	}
	Fraction operator/(Fraction& f) {
		Fraction temp;
		temp.numerator = numerator * f.denominator;
		temp.denominator = denominator * f.numerator;
		return temp;
	}
	void Set(int a, int b) {
		numerator = a;
		denominator = b;
	}
	void disp() {
		cout << "fraction=" << numerator << "/" << denominator << endl;
	}
};

int main() {
	int a, b;
	cout << "请输入第一个分数：";
	cin >> a >> b;
	Fraction f1(a, b);
	cout << "请输入第二个分数：";
	cin >> a >> b;
	Fraction f2(a, b);
	Fraction f3;
	cout << "加：" << endl;
	f3 = f1 + f2;
	f3.disp();
	cout << "减：" << endl;
	f3 = f1 - f2;
	f3.disp();
	cout << "乘：" << endl;
	f3 = f1 * f2;
	f3.disp();
	cout << "除：" << endl;
	f3 = f1 / f2;
	f3.disp();
}
