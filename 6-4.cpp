#include <iostream>
#include <string>

class Person {
public:
	Person() :Person("") {}
	Person(std::string n) :name(n) {}

	std::string GetName() {
		return name;
	}

protected:
	std::string degree;//최종 학력을 나타낸다.
private:
	std::string name;//사람이름을 나타낸다.
};

//Student클래스는 Person 클래스로부터 상속을 받는다.
class Student : public Person {
public:
	//Person 클래스의 name 멤버변수는 private이지만 다음과 같이 Person 클래스의 생성자와
	//함수를 호출하여 읽고 쓸 수 있다. 
	Student(std::string n) : Person(n), total(0) {}

	int GetTotal() {
		return total;
	}

	void AddTotal(int i) {
		total += i;
	}
	//학생은 자신의 학력을 입력시킬 수 있다.
	void SetDegree(std::string d) {
		degree = d;//기본 클래스로부터 상속받는 멤버 변수이다. 
	}
	//자신의 최종 학력을 반환받는다.
	std::string GetDegree() {
		return degree;
	}

private://현재 모든 과목에 대한 전체 점수를 입력한다.
	int total;
};

int main() {
	Student s1("홍길동");
	s1.SetDegree("초등학교 졸업");
	s1.AddTotal(95);
	std::cout << "이름 : " << s1.GetName(); 
	std::cout << ", 학력 : " << s1.GetDegree() << ", 졸업점수 : "<< s1.GetTotal() 
		<< std::endl;
	return 0;
}