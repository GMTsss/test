#include "testclassfunc.h"

//����ʹ�ó�ʼ���б����������������Ͳ�������ͬ������������������ int &age;��������const���� const int age;
// ��һ�������͵ı�����Ϊ����һ����ĳ�Ա��Teacher�е�Student stu��
Student::Student():m_name(""),m_age(new int(0)),score(0)
{
	std::cout<<"Student�޲ι��캯��" << std::endl;
}

Student::Student(std::string name, int score):m_name(name),score(score)
{
	std::cout << "Student(std::string name, int score) ���������ι��캯��" << std::endl;
}

Student::Student(std::string name, int age, int score):m_name(name),m_age(new int(age))
{
	this->score = score;
	std::cout << "Student �������ι��캯��" << std::endl;
}

Student::Student(const Student& stu):m_name(stu.m_name),m_age(new int(*(stu.m_age))),score(stu.score)
{
	std::cout << "Student �������캯��" << std::endl;
}

Student& Student::operator=(const Student& stu)
{
	std::cout << "Student::operator=(const Student& stu)������ֵ" << std::endl;
	if (this != &stu) {
		this->m_name = stu.m_name;
		delete m_age;
		m_age = new int(*(stu.m_age));
		this->score = score;
	}
	return *this;
}

Student::~Student()
{
	if (m_age != nullptr) {
		delete m_age;
		m_age = nullptr;
	}
	std::cout << "Student��������" << std::endl;
}

void Student::show()
{
	std::cout << m_name << " " << *m_age << " " << score << std::endl;
}

void Student::show2()
{
	std::cout << m_name << "  " << score << std::endl;

}

Teacher::Teacher():t_name(""),t_age(0),stu("",0)
{
	std::cout << "Teacher�޲ι��캯��" << std::endl;

}

Teacher::Teacher(std::string name, int age, std::string stuname, int stuage):t_name(name),t_age(age),stu(stuname,stuage)
{
	std::cout << "Teacher(std::string name, int age, std::string stuname, int stuage)���캯��" << std :: endl;
}

Teacher::~Teacher()
{
	std::cout << "Teacher ��������" << std::endl;
}

void Teacher::show()
{
	std::cout << t_name << "  " << t_age << std::endl;
	stu.show2();
}

Time::Time(int hour, int min, int sec):m_hour(hour),m_min(min),m_sec(sec){

	std::cout << "Time(int hour, int min, int sec)���캯��" << std::endl;
}

void Time::show_date_time(Date& date)
{
	std::cout << date.m_year << "/" << date.m_mon << "/" << date.m_day << " ";
	std::cout << m_hour << ":" << m_min << ":" << m_sec << ":" << std::endl;
}

void Time::set_year(Date& date)
{
	date.m_year=2025;
}


Date::Date(int year, int mon, int day) :m_year(year), m_mon(mon), m_day(day) {
	std::cout << "Date(int year, int mon, int day)���캯��" << std::endl;

}

