//============================================================================  
// Name        : Tdate.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.12.12
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : 实验1：Tdate类的实现
//============================================================================

#include <iostream>
#include "Tdate.h"
using namespace std;


void Tdate::set(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
int Tdate::isLeapYear()
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void Tdate::print()
{
	cout << "你输入的是：" << year << "年" << month << "月" << day << "日" << endl;
	if (isLeapYear())
		cout << year << "年是闰年" << endl;
	else
		cout << year << "年不是闰年" << endl;
}
int main()
{
	int y, m, d;
	cout << "请依次输入：年 月 日：" << endl;
	cin >> y >> m >> d;
	Tdate date;
	date.set(m,d,y);
	date.print();
	return 0;
}

