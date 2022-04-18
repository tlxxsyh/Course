//============================================================================  
// Name        : file.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.12.12
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : 第七章习题五：学生类的文本和二进制文件读写
//============================================================================

#include <iostream>
using namespace std;
#include <fstream>

class student {
public:
	char m_Name[64]; //姓名
	int m_Age;  //年龄 
};

//写文件 
void test01()
{
	ofstream ofs;
	ofs.open("C:/Users/Shangyuhang/Desktop/student.txt", ios::out | ios::binary); //以写文件的方式打开 
	student p = { "syh", 19 };
	ofs.write((const char*)&p, sizeof(student));
	ofs.close();
}

//读文件
void test02()
{
	ifstream ifs;
	ifs.open("C:/Users/Shangyuhang/Desktop/student.txt", ios::in | ios::binary); //以读文件的方式打开
	if (!ifs.is_open()) //判断文件是否为空 
	{
		cout << "文件打开失败" << endl;
		return;
	}
	student p;
	ifs.read((char*)&p, sizeof(student));
	cout << "姓名：" << p.m_Name << " " << "年龄：" << p.m_Age << endl;
	ifs.close();
}

int main()
{
	//学生类的读写
	test01();
	test02();
	//写二进制文件
	std::ofstream fout("C:/Users/Shangyuhang/Desktop/a.dat", std::ios::binary);
	int nNum = 20;
	std::string str("Hello, world");
	fout.write((char*)&nNum, sizeof(int));
	fout.write(str.c_str(), sizeof(char) * (str.size()));
	fout.close();
	//读二进制文件
	std::ifstream fin("C:/Users/Shangyuhang/Desktop/a.dat", std::ios::binary);
	char szBuf[256] = { 0 };
	fin.read((char*)&nNum, sizeof(int));
	fin.read(szBuf, sizeof(char) * 256);
	std::cout << "int = " << nNum << std::endl;
	std::cout << "str = " << szBuf << std::endl;
	fin.close();
	return 0;
}
