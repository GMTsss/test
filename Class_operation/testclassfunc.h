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
	// ��̬��Ա��������Ϊ��ʹ��Ա��������������
	// ��̬��Ա�����Ĵ���Ϊ��ʹ �����߼���ִ�в���������
	// 
	//��̬��Ա���������������������ʼ��;
	// ���캯�����ܳ�ʼ����̬��������Ϊ��̬��Ա���������࣬�����������
	// ���÷�����������.��̬��Ա������Student.flag���������.��̬��Ա������Student s1;  s1.flag;��
	//ע�⣺���ھ�̬��Ա���������࣬����һ���ཫflag�޸ĺ��������ٴη���ʱ���ʵ�ʱ�޸Ĺ����flag;
	static int flag;

	Student();
	Student(std::string name,  int score);

	Student(std::string name, int age, int score);
	Student(const Student& stu);
	Student& operator=(const Student& stu);

	//��̬��Ա����������ǰ��static�ؼ��֣������࣬�����ڶ���
	// ��̬��Ա����û��thisָ�루thisָ���������������Ϊ: ���� *const this��,
	// ���ܷ�����ͨ��Ա������ֻ�ܷ��ʾ�̬��Ա����
	//���÷�ʽ��������.show();����ʵ������.show();
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


//��Ԫ����   ��Ԫ��
class Date;
class Time {
private:
	int m_hour=0;
	int m_min=0;
	int m_sec=0;
public:
	Time(int hour, int min, int sec);
	~Time() {
		std::cout << "Time��������" << std::endl;
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
		std::cout << "Date��������" << std::endl;
	}
	//friend void Time::show_date_time(Date& date);//��Ԫ����
	friend class Time; //��Ԫ��
};
#endif


