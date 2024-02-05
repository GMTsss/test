#ifndef __TEATOPERATOR_H__
#define __TESTOPERATOR_H__
#include<iostream>
#include<string>
#include <ostream>
#include <istream>

#if 0
operator ����ҵ� �� ���¶���ֻ��ѡ����һ
 ��Ա�����棨����˽�г�Ա���㣩
 ȫ�ֺ�����
1���������������  +-*/%
���ʽ L#R
��Ա������ ���������Ƕ� ��L.operator#(R)-->const ���� operator#(const ����&R)const;
ȫ�ֺ����棺�������Ƕȣ�operator#(L,R) -->friend const ���� operator#(const ����&L,const ����&R);

2����ϵ��������� >�� <�� >=�� <=��==����=
	��Ա������ ->�������Ƕ� L.operator#(R);-->const bool operator#(const ����&R)const;
	ȫ�ֺ����� ->�������Ƕ� operator#(L,R )-->friend const bool operator#(const ����&L,const ����&R);

3����ֵ��������� =  += -=  *=  /=
��Ա������->�������Ƕ� L.operator#(R); --> ���� &operator#(const ���� & R)const;
ȫ�ֺ�����->�������Ƕ� operator#(L, R)-- > friend ���� &operator#( ���� & L, ���� & R);
�� = ��ֻ��ʵ�ֳ�Ա������

4��++a --a  a++ a--
ǰ++ --��Ա������ �������Ƕ� L.operator#()  -->���� operator#(void) 
       ȫ�ֺ����� �������Ƕ�operator#(O) -->friend ����&operator#(���� &O)

��++ --��Ա������ �������Ƕ� L.operator#(int)  -- >const ���� operator#(int)--��Ԫ
       ȫ�ֺ����� �������Ƕ�operator#(O) -- > friend ���� & operator#(���� & O��int)

5��>> <<ֻ��ʵ��ȫ�ֺ�����
<< -- > friend ostream & operator<<(ostream & x, ostream & y)
>> --> friend istream &operatoe>>(istream &x,istream &y)

6��
�������ص������
.ȡ��Ա�����
:: �����������
* ��Աָ�������
?:��Ŀ�����
# Ԥ�������
sizeof()�����
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
	//���������+
	friend const Complex operator+(const Complex& L, const Complex& R);
	//<<
	friend std::ostream& operator<<(std::ostream &cout,const Complex &y);
	// >>
	friend std::istream& operator>>(std::istream& cin, Complex& y);
	// 
	//���������-
	const Complex operator-(const Complex& R)const {
		Complex temp;
		temp.real = this->real - R.real;
		temp.vir = this->vir - R.vir;
		return temp;
	}
	//�Ƚ������>
	const bool operator>(const Complex& R)const {
		if (this->real > R.real && this->vir > R.vir) {
			return true;
		}
		return false;
	}
	//��Ŀ�����-
	const Complex operator-(void)const {
		Complex temp;
		temp.real = -(this->real);
		temp.vir = -(this->vir);
		return temp;
	}
	//��ֵ�����+=
	Complex& operator+=(const Complex& R) {
		this->real = this->real + R.real;
		this->vir += R.vir;
		return *this;
	}
	//ǰ++
	Complex& operator++(void) {
		++(this->real);
		++(this->vir);
		return *this;
	}
	//��++
	const Complex& operator++(int) {//��Ԫ
		Complex temp = *this;
		(this->real)++;
		(this->vir)++;
		return temp;
	}
};



#endif
