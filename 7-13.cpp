#include<iostream>
#include <limits>
#include <typeinfo>

int i = 1;
template<class T>
void max() {
	//제공하는 데이터 타입에 따라 최대 값을 출력한다.
	std::cout << i++ << ". " << typeid(T).name() << " : " << std::numeric_limits<T>::max() << std::endl;
}

int main() {
	std::cout << "최대값" << std::endl;
	max<int>();
	max<unsigned int>();
	max<double>();
	max<float>();

	std::cout << std::boolalpha << "is_signed(int): "
		<< std::numeric_limits<int>::is_signed << std::endl;

	return 0;
}