#ifndef Tdate_H
#define Tdate_H
class Tdate	//定义日期类
{
private:
	int year;
	int month;
	int day;
public:
	//置日期值
	void set(int m, int d, int y);
	//判断是否闰年，是则返回1，否则返回0
	int isLeapYear();
	//输出日期值
	void print();
};
#endif
