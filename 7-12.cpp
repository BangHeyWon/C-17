#include <iostream>
#include <typeinfo>

int m = 1;
template<class T> class A{ };

template<int i> class B{ };
 
class C {
public:
	int x;
};

template<class T> void f(T&) {//참조 타입을 인수로 사용한다.
	std::cout << m++ << ". T&, 타입 : " << typeid(T).name() << std::endl;
}

template<class T> void f(T*) { // 포인터 타입을 인수로 사용한다.
	std::cout << m++ << ". T*, 타입 : " << typeid(T).name() << std::endl;
}

template<class T> void f(const T&) {//상수 참조 타입을 인수로 사용한다. 
	std::cout << m++ << ". const T&, 타입 : " << typeid(T).name() << std::endl;
}

template<class T> void f(A<T>) {//A<T> 클래스를 인수로 사용한다.
	std::cout << m++ << ". A<T>, 타입 : " << typeid(T).name() << std::endl;
}

template<int i> void f(C[10][i]) {//배열 타입을 인수로 사용한다.
	std::cout << m++ << ". C[10][i] "<< std::endl;
}

template<int i> void f(B<i>) {//B<i>클래스를 인수로 사용한다.
	std::cout << m++ << ". B<i>" << std::endl;
}

template<class T, class U> void f(T(*)(U)) {//함수 포인터를 인수로 사용한다.
	std::cout << m++ << ". T(*) (U), T 타입 : " << typeid(T).name() << ". U타입 : " << typeid(U).name()<< std::endl;
}

void f(int x) {
	std::cout << "void f(int) = " << x << std::endl;
}

int main() {
	//다음과 같이 다양한 타입의 변수를 만들어 함수를 호출한다.
	C a = { 0 };
	const C b = { 0 };
	A<char> c;
	C& d = a;
	const C& e = b;
	C array[10][20];
	B<20> b2;

	//9개의 함수를 호출한다.
	f(a); f(&a); f(b); f(&b); f(C{ 10 });  f(c); f(d); f(e); f(C{ 11 });

	f(array);
	f(b2);

	std::cout << std::endl << "멤버 변수----------------------------------" << std::endl;
	f(&a.x);

	std::cout << std::endl << "함수 포인터--------------------------------" << std::endl;
	void(*c_pfunct1)(int) = &f;
	f(c_pfunct1);
}