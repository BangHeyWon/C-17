#include <iostream>
#include <vector>

template<typename T, size_t size>
constexpr size_t GetArrLength(T(&)[size]) {
	return size;
}

//�Ʒ� �Լ� ���ø� ���� ���� ���������� �Լ��� �μ��� arr�� ó���Ͽ���.
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

int ai[10];//���� ������ �迭�� �����Ѵ�.

int main() {
	int a[] = { 4, 6, 8, 32, 19 };

	//1. �Լ��� ȣ�⸸ �ϴ��� �迭�� ũ�Ⱑ �ڵ����� ���Ǿ� �����ȴ�.
	std::cout << "�迭�� ũ�� : " << GetArrLength(a) << std::endl;
	LinkedList<int>(a);

	//2. �׷��� �������� ���� new �����ڸ� ����Ͽ� �� �޸� �� ������ ��´ٸ� �迭�� ũ�⸦ ������� ���Ѵ�.
	//int* dynamic = new int[5];
	//std::cout << GetArrLength(dynamic);
	
	//3.������ Ÿ���� �迭�� �ƴ� �� �ٸ� Ŭ���� ���ø��� �ν��Ͻ��� ����Ѵٸ� ������ �߻��Ѵ�.
	//std::vector<int> vec(5);
	//std::cout << GetArrLength(vec);

	//4. �Ʒ� ���� �迭�� �����Ͽ� ���� ��ü�� �ѱ�� ó���ϴ� �۾��� ���̴�. 
	for (int i = 0; i < 10; ++i) ai[i] = a[i % 5];
	//���ø� �μ��� �迭�� �ѱ��.
	Array<ai, 10>xi;
	xi.Print();
}