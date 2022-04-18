//============================================================================  
// Name        : student.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.12.12
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : P75，T6 设计一个学生类
//============================================================================

#include <iostream>

using namespace std;

class student
{
private:
	string id;                //注册号
	char name[10];            //姓名
	int score_math=0;         //数学成绩
	int score_english=0;      //英语成绩
	int score_computer=0;     //计算机成绩
public:
	int sum();              //求三门课总成绩
	float average();        //求三门课平均成绩
	void print();           //显示学生信息
	string get_reg_num();   //获取学生注册号
	void set_stu_inf();     //设置学生信息
};

int main()
{
	student students[100];         //初步设为最多100个学生
	int n,score_max,sum_all;       //学生数，最高分
	float score_avg_all;           //全班学生总均分
	string id_search;              //供搜索的id
	//初始化
	sum_all = 0;
	score_max = 0;
	score_avg_all = 0;
	cout << "请输入学生总数：" << endl;
	cin >> n;
	//读取n个学生信息
	for (int i = 0; i < n; i++)
	{
		cout << "请增添第"<<i+1<<"个学生信息：";
		students[i].set_stu_inf();
		
	}
	//获取全班最高分,平均分
	for (int i = 0; i < n; i++)
	{
		//置最高分初值为第一个人的分
		if (i == 0)
			score_max = students[0].sum();
		//如果更高，则替换
		if (students[i].sum() > score_max)
			score_max = students[i].sum();
		sum_all += students[i].sum();
	}
	score_avg_all = sum_all / n;
	cout << "全班最高分为：" << score_max << endl;
	cout << "全班平均分为：" << score_avg_all << endl;
	cout << "请输入你想要查找的学生信息（因为是为了演示，所以只提供一次查找）：";
	cin >> id_search;
	//遍历所有学生注册号来寻找
	int isfind = 0;
	for (int i = 0; i < n; i++)
	{
		if (students[i].get_reg_num() == id_search)
		{
			students[i].print();
			isfind = 1;
			break;
		}
	}
	if (isfind = 0)
	{
		cout << "查无此生！" << endl;
	}
	return 0;
}

int student::sum()
{
	return score_math + score_english + score_computer;
}

float student::average()
{
	return (score_math + score_english + score_computer) / 3;
}

void student::print()
{
	cout << "下列是该生信息：" << endl;
	cout << "姓名：" << name << endl;
	cout << "注册号：" << id << endl;
	cout << "数学成绩：" << score_math << endl;
	cout << "英语成绩：" << score_english << endl;
	cout << "计算机成绩：" << score_computer << endl;
	cout << "总分：" << sum() << endl;
	cout << "平均分：" << average() << endl;
}

string student::get_reg_num()
{
	return id;
}

void student::set_stu_inf()
{
	int cmd;
	cout << "请输入你想要设置的信息：" << endl;
	cout << "1.姓名" << endl;
	cout << "2.注册号" << endl;
	cout << "3.数学成绩" << endl;
	cout << "4.英语成绩" << endl;
	cout << "5.计算机成绩" << endl;
	cout << "6.退出" << endl;
	cin >> cmd;
	while (cmd)
	{
		if (cmd == 1)
		{
			cin >> name;
			cout << "修改成功！请继续输入要进行的操作：";
			cin >> cmd;
		}
		else if (cmd == 2)
		{
			cin >> id;
			cout << "修改成功！请继续输入要进行的操作：";
			cin >> cmd;
		}
		else if (cmd == 3)
		{
			cin >> score_math;
			cout << "修改成功！请继续输入要进行的操作：";
			cin >> cmd;
		}
		else if (cmd == 4)
		{
			cin >> score_english;
			cout << "修改成功！请继续输入要进行的操作：";
			cin >> cmd;
		}
		else if (cmd == 5)
		{
			cin >> score_computer;
			cout << "修改成功！请继续输入要进行的操作：";
			cin >> cmd;
		}
		else
		{
			break;
		}
		
		

	}
}

/*示例数据

4
1
syh
2
001
3
10
4
10
5
10
6
1
hhf
2
002
3
9
4
8
5
7
6
1
cyj
2
003
3
8
4
8
5
8
6
1
fgk
2
004
3
6
4
6
5
6
6
001

*/
