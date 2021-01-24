#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass(const char *label, int id) : label(label), id(id){}
	MyClass() = default;

	void DisplayX() {
		std::cout << "클래스 내 label은" << label.data()
			<< "이고 id는 " << id << "이다.\n";
	}

private:
	std::string label;
	const int id = 3;//C++11부터 상수 선언과 동시에 직접 초기화가 가능하다. 
};

int main() {
	MyClass s;
	//s.label = "cc"; 보호 수준의 위반에 따라 접근할 수 없다는 에러가 발생한다. 
	s.DisplayX();
}