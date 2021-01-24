#include <iostream>
#include <type_traits>
#include <typeinfo>

//PODŬ������ �����.
struct POD {
	int m;
};

//�Ϲ� Ŭ������ �����.
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
	//�ԷµǴ� Ÿ�Կ� ���� �Ʒ� ���ǹ��� ������ ������ ����ȴ�.
	if (std::is_fundamental<T>::value) {
		std::cout << t << "�� �⺻Ÿ���̸�,";
		if(std::is_arithmetic<T>::value){//Ÿ���� ��� ������ ������ Ÿ������ Ȯ���Ѵ�.
			if (std::is_integral<T>::value) {
				std::cout << "����";
			}
			else if (std::is_floating_point<T>::value) {
				std::cout << "�Ǽ�";
			}
		}
	}
	//�μ��� const�����ڰ� �ִ� �� �����Ѵ�.
	if (std::is_const<T>::value) {
		std::cout << "�̸� const���";
	}
	std::cout << "�̴�." << std::endl;
}

//�Ʒ� �Լ��� ��ü�� ���� Ư���� �˾ƺ��� ���� ����ϴ� �Լ��̴�.
template<typename T>
void check_class(const char *c, T& t) {
	std::cout << c;
	if(std::is_class<T>::value){//Ÿ���� Ŭ�������� Ȯ���Ѵ�.
		if (std::is_trivial<T>::value) {
			std::cout << "�����(Trivial Class) ";
		}
		if (std::is_pod<T>::value) {
			std::cout << " POD";
		}
		std::cout << " Ŭ����";
	}
	if (std::is_const<T>::value) {
		std::cout << "�̸� const ���";
	}
	std::cout << "�̴�." << std::endl;
}

int main() {
	int ct = 100;
	check_type(ct);
	const int cref = ct;
	check_type(cref);

	POD pod = { 1 };
	check_class("pod�� ", pod);
	MyClass mc1(10, 20);
	check_class("mc1�� ", mc1);
}