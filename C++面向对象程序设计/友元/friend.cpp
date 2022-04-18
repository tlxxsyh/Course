#include<iostream>
using namespace std;
class Fraction
{
	double z;
	double m;
public:
	friend void inputA(Fraction& comp);
	friend Fraction addA(Fraction z, Fraction m);
	friend Fraction subA(Fraction z, Fraction m);
	friend Fraction mulA(Fraction z, Fraction m);
	friend void outputA(Fraction comp);
};
void inputA(Fraction& comp)
{
	cin >> comp.z >> comp.m;

}
Fraction addA(Fraction numbert, Fraction c2) {
	Fraction num;
	num.z = numbert.z * c2.m + c2.z * numbert.m;
	num.m = numbert.m * c2.m;
	return num;
}
Fraction subA(Fraction numbert, Fraction c2) {
	Fraction num;
	num.z = (numbert.z * c2.m) - (c2.z * numbert.m);
	num.m = numbert.m * c2.m;
	return num;
}
Fraction mulA(Fraction numbert, Fraction c2) {
	Fraction num;
	num.z = numbert.z * c2.z;
	num.m = numbert.m * c2.m;
	return num;
}
void outputA(Fraction comp)
{
	cout << comp.z << "/" << comp.m;
}
int main()
{
	Fraction numbert, c2, result;
	cout << "请输入第一个分数的分子和分母:" << endl;
	inputA(numbert);
	cout << "请输入第二个分数的分子和分母:" << endl;
	inputA(c2);
	result = addA(numbert, c2);
	outputA(numbert);
	cout << "+";
	outputA(c2);
	cout << "=";
	outputA(result);

	cout << "\n-------------------------" << endl;
	result = subA(numbert, c2);
	outputA(numbert);
	cout << "-";
	outputA(c2);
	cout << "=";
	outputA(result);
	cout << "\n-------------------------" << endl;
	result = mulA(numbert, c2);
	outputA(numbert);
	cout << "*";
	outputA(c2);
	cout << "=";
	outputA(result);
	cout << endl;
}
