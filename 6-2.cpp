#include <iostream>
#include <string>

class Person {
public:
	Person(std::string n) :name(n) {}

	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//클래스의 상속은 클래스가 아닌 구조체라도 상속이 가능하다. 
class Student : public Person {
public:
	Student(std::string i, std::string n) : Person(n), id(i) {}

	std::string GetID() {
		return id;
	}

private:
	std::string id;
};

int main() {
	Student s1("16-31-001", "홍길동");
	//학생 내 name이란 멤버가 존재하지 않지만 학생은 사람으로부터 상속을 받으므로 사용이 가능하다.
	std::cout << "학생 ID :" << s1.GetID()
		<< ", 이름 : " << s1.GetName() << std::endl;
}