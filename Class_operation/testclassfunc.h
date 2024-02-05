#ifndef __TESTCLASSFUNC_H__
#define __TESTCLASSFNC_H__
#include <iostream>
#include<string>

class Student {
private:
	std::string m_name;
	int* m_age;
	int score=10;
public:
	// 静态成员变量存在为了使成员变量不依赖于类
	// 静态成员函数的存在为了使 函数逻辑的执行不依赖于类
	// 
	//静态成员变量：类内声明，类外初始化;
	// 构造函数不能初始化静态变量，因为静态成员变量属于类，不属于类对象
	// 调用方法：①类名.静态成员变量（Student.flag）②类对象.静态成员变量（Student s1;  s1.flag;）
	//注意：由于静态成员变量属于类，所以一个类将flag修改后，其他类再次访问时访问的时修改过后的flag;
	static int flag;

	Student();
	Student(std::string name,  int score);

	Student(std::string name, int age, int score);
	Student(const Student& stu);
	Student& operator=(const Student& stu);

	//静态成员函数：函数前加static关键字；属于类，不属于对象
	// 静态成员函数没有this指针（this指针属于类对象，类型为: 类型 *const this）,
	// 不能访问普通成员变量，只能访问静态成员变量
	//调用方式：①类名.show();②类实例对象.show();
	static void show1() {
		std::cout << "flag=" << flag << std::endl;
	}

	~Student();

	void show();
	void show2();

};
int Student::flag = 0;

class Teacher {
private:
	std::string t_name;
	int t_age;
	Student stu;
public:
	Teacher();
	Teacher(std::string name, int age, std::string stuname, int stuage);
	~Teacher();
	void show();

};


//友元函数   友元类
class Date;
class Time {
private:
	int m_hour=0;
	int m_min=0;
	int m_sec=0;
public:
	Time(int hour, int min, int sec);
	~Time() {
		std::cout << "Time析构函数" << std::endl;
	}
	void show_date_time(Date& date);
	void set_year(Date& date);
};

class Date {
private:
	int m_year=0;
	int m_mon=0;
	int m_day=0;
public:
	Date(int year, int mon, int day);
	~Date() {
		std::cout << "Date析构函数" << std::endl;
	}
	//friend void Time::show_date_time(Date& date);//友元函数
	friend class Time; //友元类
};
#endif


