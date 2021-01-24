#include <iostream>
#include <string>

class Person {
public:
	Person():Person(""){}
	Person(std::string n):name(n){}

	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//Student클래스는 Person 클래스로부터 상속을 받는다.
class Student : public Person {
public:
	/*
	아래 name 변수는 자체 클래스 내 존재하는 name 변수이다. 만약 기본
	클래스(Person) 내 name 변수를 초기화하려면 Person(n) 생성자를 호
	출해 주어야 한다. 따라서 아래 생성자는 별도 언급이 없으므로 Person
	클래스의 인스턴스를 생성하기 위해 디폴트 생성자를 호출한다. 
	*/
	Student(std::string n):name(n){}
	
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

int main() {
	Student s1("홍길동");
	std::cout << "Student : " << s1.GetName() << std::endl;//아래 GetName 함수의 경우 'Student::'가 생략되어 있다.
	//정규 클래스 이름을 사용하여 호출할 수 있다.
	std::cout << "Person : " << s1.Person::GetName() << std::endl;//Person클래스의 GetName()함수를 호출하는 방법이다.
	return 0;
}