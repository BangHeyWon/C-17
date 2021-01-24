#include <iostream>
#include <typeinfo>

//C라는 이름의 클래스를 만든다.
class C {
public:
	int x;
};

int i = 1;//출력 순서를 확인하기 위해 만든 전역변수이다.

//함수 템플릿을 만든다. 함수 템플릿은 내부에 인수의 타입을 출력하는 기능을 제공한다.
template<class T> void f(T) {
	std::cout << i++ << ".T타입 : " << typeid(T).name() << std::endl;
}

int main() {
	C a = { 0 };
	const C b = { 0 };
	C& c = a;
	const C& d = b;

	f(a); f(&a); f(b); f(&b); f(c); f(d);
	f(C{ 10 });//무명 변수를 생성하여 함수의 인수로 전달한다. 
}


//참조타입은 '다형성 타입'으로 복사 생성자와 이동 생성자 그리고 대입 연산자의 인수로 사용한다. 
//따라서 반드시 구분이 필요한 타입이다. 