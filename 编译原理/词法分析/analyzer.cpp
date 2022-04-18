#include <iostream>
#include <stdio.h>

using namespace std;

//index是扫描指针,c是种别编码,j是符号表的添加入口位置
int index = 0,c,j=5;
//character是当前单词字符
char character;
//token暂时存放
char token[50];
string keyword[50] = { "while","if","else","switch","case" };

//清空character空白字符
void getbe();
//判断character中的字符是否为字母,是则返回true,否则返回false
bool letter();
//判断character中的字符是否为数字,是则返回true,否则返回false
bool digit();
//将token中的字符串与character中的字符连接并作为token中的新字符串
void concatenation();
//清空token数组，并且保留上次获取的字符（即书上的扫描指针退一位）
void retract();
//判断是不是保留字
int reserve();
//添加进表
void buildlist();
//报错函数
void error();
//词法分析主体
void analyzer();

int main()
{
	while ((character = getchar()) != EOF) {
		analyzer();
	}
	return 0;
}

void buildlist() {
	//j++每次自动往下一个符号表填
	keyword[j++] = token;
}
void retract() {
	index = 0;//index返回开头，重新录入token数组
	memset(token, '\0', sizeof(token));
	analyzer();
}
void analyzer() {
	getbe();//清空空白字符
	//如果是字母开头
	if ((character >= 97 && character <= 122) || (character >= 65 && character <= 90)) {
		while (letter() || digit()) {
			concatenation();
			character = getchar();
		}
		//本来在这一行的
		c = reserve();
		if (c == 0) {
			buildlist();
			cout << "(6," << token << ")" << endl;
		}
		else {
			cout << "(" << c << ",_)" << endl;
		}
		retract();//清空数组，回退的目的是为了读到这个循环里已经读入的字符（这个字符要参与下次的判断）
	}
	//如果是数字开头
	else if (character >= 48 && character <= 57) {
		while (digit()) {
			concatenation();
			character = getchar();
		}
		buildlist();
		cout << "(7," << token << ")" << endl;
		retract();
	}
	//+
	else if (character == '+') {
		cout << "(+,_)" << endl;
	}
	//-
	else if (character == '-') {
		cout << "(-,_)" << endl;
	}
	//*
	else if (character == '*') {
		cout << "(*,_)" << endl;
	}
	//<
	else if (character == '<') {
		character = getchar();
		if (character == '=')
			cout << "(relop,LE)" << endl;
		else
			cout << "(relop,LT)" << endl;
	}
	//=
	else if (character == '=') {
		character = getchar();
		if (character == '=')
			cout << "(relop,EQ)" << endl;
		else
			cout << "(=,_)" << endl;
		retract();
	}
	//;
	else if (character == ';') {
		cout << "(;,_)" << endl;
	}
	//避免换行符报错
	else if (character == '\n') {

	}
	else
		error();

}
void error() {
	cout << "ERROR:" << character << "是不能辨认的字符" << endl;
}
int reserve() {
	if (token == keyword[0]) {
		return 1;
	}
	else if (token == keyword[1]) {
		return 2;
	}
	else if (token == keyword[2]) {
		return 3;
	}
	else if (token == keyword[3]) {
		return 4;
	}
	else if (token == keyword[4]) {
		return 5;
	}
	else
		return 0;
}
bool digit() {
	if ((character >= 48 && character <= 57))
		return true;
	else
		return false;
}
void concatenation() {
	token[index++] = character;//!!此处修改index位置
}
bool letter() {
	if ((character >= 97 && character <= 122) || (character >= 65 && character <= 90))
		return true;
	else
		return false;
}
void getbe() {
	if (character == ' ') {
		character = getchar();
	}
}
