#include <iostream>
#include <typeinfo>
#include <type_traits>

/*
1. 템플릿 변환 과정에서 T1인수와 T2인수가 같은 타입이라면 true를 제공하기 때문에 enable_if 구조체 내 type을 사용 할 수 있다. 
그러나 만약 서로 타입이 다르다면 false를 반환한다. 그에 따라 enable_if 구조체는 type이 존재하지 않으므로 에러발생과 함께 해당
함수 템플릿은 비활성화 된다. 
*/
template<typename T1, typename T2>
typename std::enable_if<std::is_same<T1,T2>::value, bool>::type
check_type(const T1& t1, const T2& t2) {
	std::cout << t1 << "과 " << t2 << "은 같은 타입이다." << std::endl;
	return true;
}

//2. 아래 함수의 인수가 서로 다른 타입이라면 활성화 된다.
template<typename T1, typename T2>
typename std::enable_if<!std::is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2) {
	std::cout << t1 << "과 " << t2 << "은 서로 다른 타입이다." << std::endl;
	return false;
}

int main() {
	check_type(10, 40);
	check_type(10, 40.56);
	check_type(10, "Test 타입");
}
