#include <iostream>
#include <string>

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif 

//1. 아래는 기본 클래스 템플릿이다.
template <typename Key, typename Value>
class KeyValuePair{
public:
	//__PRETTY_FUNCTION__ 매크로는 호출한 함수와 타입을 출력하는 기능을 수행한다.
	KeyValuePair(Key k, Value v) :key(k), value(v) {
		std::cout << "1 " << __PRETTY_FUNCTION__ << ':' << "original\n";
	}
private:
	Key key;
	Value value;
};

//2. 아래는 위의 템플릿 인수 모두에 대해 명시적 템플릿 특수화를 적용한다.
template<>
class KeyValuePair<int, std::string> {
public:
	KeyValuePair(int k, std::string v) : key(k), value(v) {
		std::cout << "2 " << __PRETTY_FUNCTION__ << ':' << "explicit full specialized\n";
	}

private:
	int key;
	std::string value;
};

//3. 아래는 위의 템플릿 인수 가운데 Value 인수에 대해 부분 템플릿 특수화를 적용한다.
template<typename Key>
class KeyValuePair<Key, std::string> {
public:
	KeyValuePair(Key k, std::string v) : key(k), value(v) {
		std::cout << "3 " << __PRETTY_FUNCTION__ << ':' << "specialized\n";
	}
private:
	Key key;
	std::string value;
};

//위의 클래스 템프릿과 템플릿 특수화된 클래스 템플릿을 호출하는 예는 다음과 같다.
int main() {
	//1. 기본 클래스 템플릿의 생성자를 호출한다.
	KeyValuePair<int, int> kvp1(100, 100);
	//3. template<typename Key> class KeyValuePair<Key, std::string>
	//클래스 템플릿의 생성자를 호출한다.
	KeyValuePair<long, std::string> kvp2(100, "템플릿 특수화");
	//2. template <> class KeyValuePair<int, std::string> 클래스 템플릿의 생성자를 호출한다.
	KeyValuePair<int , std::string> kvp3(100, "템플릿 특수화");
}