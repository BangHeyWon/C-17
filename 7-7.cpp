#include <iostream>
#include <vector>

template<typename T, size_t size>
constexpr size_t GetArrLength(T(&)[size]) {
	return size;
}

//아래 함수 템플릿 역시 위와 동일하지만 함수의 인수를 arr로 처리하였다.
template<class T, int N>
void LinkedList(T(&arr)[N]) {
	for (int i(0); i < N; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

template<const int*pci, size_t size>
struct Array {
	void Print() {
		for (int i(0); i < size; ++i) {
			std::cout << pci[i] << ' ';
		}
		std::cout << std::endl;
	}
};

int ai[10];//전역 변수로 배열을 선언한다.

int main() {
	int a[] = { 4, 6, 8, 32, 19 };

	//1. 함수를 호출만 하더라도 배열의 크기가 자동으로 계산되어 제공된다.
	std::cout << "배열의 크기 : " << GetArrLength(a) << std::endl;
	LinkedList<int>(a);

	//2. 그러나 ㅏㅇ래와 같이 new 연산자를 사용하여 힙 메모리 내 영역을 잡는다면 배열의 크기를 계산하지 못한다.
	//int* dynamic = new int[5];
	//std::cout << GetArrLength(dynamic);
	
	//3.데이터 타입의 배열이 아닌 또 다른 클래스 템플릿의 인스턴스를 사용한다면 에러가 발생한다.
	//std::vector<int> vec(5);
	//std::cout << GetArrLength(vec);

	//4. 아래 예는 배열을 생성하여 직접 객체에 넘기고 처리하는 작업의 예이다. 
	for (int i = 0; i < 10; ++i) ai[i] = a[i % 5];
	//템플릿 인수로 배열을 넘긴다.
	Array<ai, 10>xi;
	xi.Print();
}