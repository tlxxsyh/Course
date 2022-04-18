//============================================================================  
// Name        : square.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.12.12
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : 第六章习题10：用虚函数和多态对各种图形求面积
//============================================================================

#include<iostream>
using namespace std;

class Shape {
public:
    virtual void set() = 0;
    virtual double getArea() = 0;
};
class Triangle : public Shape {
    double a=1, b=1, c=1;
public:
    virtual void set() {
        cin >> a >> b >> c;
    }
    virtual double getArea() {
        double p = (a + b + c) / 2;
        cout << "三角形面积: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
class Rectangle : public Shape {
    double a=1, b=1;
public:
    virtual void set() {
        cin >> a >> b;
    }
    virtual double getArea() {
        cout << "长方形面积： " << a * b << endl;
        return a * b;
    }
};
class Square : public Shape {
    double a=1;
public:
    void set() {
        cin >> a;
    }
    double getArea() {
        cout << "正方形面积: " << a * a << endl;
        return a * a;
    }
};
class Circle : public Shape {
    double const pi = 3.14;
    double radius=1;
public:
    void set() {
        cin >> radius;
    }
    double getArea() {
        cout << "圆的面积: " << pi * radius * radius << endl;
        return pi * radius * radius;
    }
};
int main() {
    Square square;
    Rectangle rectangle;
    Triangle triangle;
    Circle circle;
    Shape* s[4] = { &square, &rectangle, &triangle, &circle };
    double sum=0;
    cout << "请输入各个边长（正方形，长方形，三角形，圆）：" << endl;
    for (int i = 0; i < 4; i++) {
        s[i]->set();
        sum += s[i]->getArea();
    }
    cout << "The sum area: " << sum << endl;
}
