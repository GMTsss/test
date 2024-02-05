#ifndef __TEATOPERATOR_H__
#define __TESTOPERATOR_H__
#include<iostream>
#include<string>
#include <ostream>
#include <istream>

#if 0
operator 左参右调 ， 以下二者只能选择其一
 成员函数版（访问私有成员方便）
 全局函数版
1、算数运算符重载  +-*/%
表达式 L#R
成员函数版 ：编译器角度 ：L.operator#(R)-->const 类名 operator#(const 类名&R)const;
全局函数版：编译器角度：operator#(L,R) -->friend const 类名 operator#(const 类名&L,const 类名&R);

2、关系运算符重载 >、 <、 >=、 <=、==、！=
	成员函数版 ->编译器角度 L.operator#(R);-->const bool operator#(const 类名&R)const;
	全局函数版 ->编译器角度 operator#(L,R )-->friend const bool operator#(const 类名&L,const 类名&R);

3、赋值运算符重载 =  += -=  *=  /=
成员函数版->编译器角度 L.operator#(R); --> 类名 &operator#(const 类名 & R)const;
全局函数版->编译器角度 operator#(L, R)-- > friend 类名 &operator#( 类名 & L, 类名 & R);
“ = ”只能实现成员函数版

4、++a --a  a++ a--
前++ --成员函数版 编译器角度 L.operator#()  -->类名 operator#(void) 
       全局函数版 编译器角度operator#(O) -->friend 类名&operator#(类名 &O)

后++ --成员函数版 编译器角度 L.operator#(int)  -- >const 类名 operator#(int)--哑元
       全局函数版 编译器角度operator#(O) -- > friend 类名 & operator#(类名 & O，int)

5、>> <<只能实现全局函数版
<< -- > friend ostream & operator<<(ostream & x, ostream & y)
>> --> friend istream &operatoe>>(istream &x,istream &y)

6、
不能重载的运算符
.取成员运算符
:: 作用域运算符
* 成员指针运算符
?:三目运算符
# 预处理符号
sizeof()运算符
#endif
class Complex {
private:
	int real;
	int vir;
public:
	Complex();
	Complex(int r, int v) :real(r), vir(v) {}
	~Complex() {}
	void show()const {
		//std::cout << "real=" << real << " vir=" << vir << std::endl;
		std::cout << real << "+" << vir << "i" << std::endl;
	}
	//算数运算符+
	friend const Complex operator+(const Complex& L, const Complex& R);
	//<<
	friend std::ostream& operator<<(std::ostream &cout,const Complex &y);
	// >>
	friend std::istream& operator>>(std::istream& cin, Complex& y);
	// 
	//算数运算符-
	const Complex operator-(const Complex& R)const {
		Complex temp;
		temp.real = this->real - R.real;
		temp.vir = this->vir - R.vir;
		return temp;
	}
	//比较运算符>
	const bool operator>(const Complex& R)const {
		if (this->real > R.real && this->vir > R.vir) {
			return true;
		}
		return false;
	}
	//单目运算符-
	const Complex operator-(void)const {
		Complex temp;
		temp.real = -(this->real);
		temp.vir = -(this->vir);
		return temp;
	}
	//赋值运算符+=
	Complex& operator+=(const Complex& R) {
		this->real = this->real + R.real;
		this->vir += R.vir;
		return *this;
	}
	//前++
	Complex& operator++(void) {
		++(this->real);
		++(this->vir);
		return *this;
	}
	//后++
	const Complex& operator++(int) {//哑元
		Complex temp = *this;
		(this->real)++;
		(this->vir)++;
		return temp;
	}
};



#endif
