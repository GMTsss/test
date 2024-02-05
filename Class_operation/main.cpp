// Class_operation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"testclassfunc.h"
#include "testoperator.h"
using namespace std;
#if 0
ostream& operator<<(ostream& out,const Complex& y) {
	out << y.real << "+" << y.vir << "i";
	return out;
}
istream& operator>>(istream& in, Complex& y) {
	in >> y.real >> y.vir;
	return in;
}
#endif

int main()
{




#if 0
	//运算符重载
	//Complex c1(1, 2);
	//c1.show();
	//Complex c2(3, 4);
	//Complex c3 = c1 + c2;
	//c3.show();
	//c3.operator++();
	//c3.show();
	//Complex c4(5, 6);
	//Complex c5;
	//c4 += c1;
	//c4.show();
	//cout << "------------------------" << endl;
	//cout << c1 << endl;
	//cin >> c5;
	//cout << c5;
#endif
#if 0
	////友元函数  友元类
	//Time t1(10, 20, 30);
	//Date d1(2024, 2, 5);
	//t1.show_date_time(d1);
	//t1.set_year(d1);
	//t1.show_date_time(d1);

#endif

#if 0
	//class 成员函数
	//Student s1("张三", 10, 80);
	//Student s2 = s1;
	//Student s3(s2);
	//s3.show();
	//Student* s4 = new Student("lisi", 20, 100);
	//s4->show();
	//delete s4;
	//Teacher t1("老师", 30, "学生", 20);
	//t1.show();
#endif
}
