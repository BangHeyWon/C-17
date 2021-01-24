#include <iostream>

//아래는 기본 클래스 템플릿이다. 클래스 템플릿은 멤버 변수를 화면에 출력하는 기능을 수행한다.
template <class T>
class Form {
	T* _t;

public:
	Form(T* t):_t(t){ }
	void print() {
		std::cout << *_t << std::endl;
	}
};

template <>
class Form<char *> {
	char* _t;

public:
	Form(char* t) :_t(t) { }
	void print() {
		std::cout<<"Form<char *> :  "<< _t << std::endl;
	}
};

int main() {
	int i = 157;
	Form<int> form1(&i);//기본 템플릿을 적용한다.

	char c[10] = "string1";
	//아래와 같이 char* 인수를 사용하여 템플릿 특수화된 클래스 템플릿의 인스턴스를 만든다.
	Form<char*> form2(c);

	form1.print();
	form2.print();
}

