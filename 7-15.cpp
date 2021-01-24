#include <iostream>
#include <type_traits>
#include <typeinfo>

//POD클래스를 만든다.
struct POD {
	int m;
};

//일반 클래스를 만든다.
class MyClass {
public:
	MyClass(int i, int j) {
		x = i;
		y = j;
	}

private:
	int x;
	int y;
};

template<typename T>
void check_type(T& t) {
	//입력되는 타입에 따라 아래 조건문의 조건이 맞으면 실행된다.
	if (std::is_fundamental<T>::value) {
		std::cout << t << "는 기본타입이며,";
		if(std::is_arithmetic<T>::value){//타입이 산술 연산이 가능한 타입인지 확인한다.
			if (std::is_integral<T>::value) {
				std::cout << "정수";
			}
			else if (std::is_floating_point<T>::value) {
				std::cout << "실수";
			}
		}
	}
	//인수에 const지정자가 있는 지 점검한다.
	if (std::is_const<T>::value) {
		std::cout << "이며 const상수";
	}
	std::cout << "이다." << std::endl;
}

//아래 함수는 객체에 대한 특성을 알아보기 위해 사용하는 함수이다.
template<typename T>
void check_class(const char *c, T& t) {
	std::cout << c;
	if(std::is_class<T>::value){//타입이 클래스인지 확인한다.
		if (std::is_trivial<T>::value) {
			std::cout << "평범한(Trivial Class) ";
		}
		if (std::is_pod<T>::value) {
			std::cout << " POD";
		}
		std::cout << " 클래스";
	}
	if (std::is_const<T>::value) {
		std::cout << "이며 const 상수";
	}
	std::cout << "이다." << std::endl;
}

int main() {
	int ct = 100;
	check_type(ct);
	const int cref = ct;
	check_type(cref);

	POD pod = { 1 };
	check_class("pod는 ", pod);
	MyClass mc1(10, 20);
	check_class("mc1은 ", mc1);
}