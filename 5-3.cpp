#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass(const char *label, int id) : label(label), id(id){}
	MyClass() = default;

	void DisplayX() {
		std::cout << "Ŭ���� �� label��" << label.data()
			<< "�̰� id�� " << id << "�̴�.\n";
	}

private:
	std::string label;
	const int id = 3;//C++11���� ��� ����� ���ÿ� ���� �ʱ�ȭ�� �����ϴ�. 
};

int main() {
	MyClass s;
	//s.label = "cc"; ��ȣ ������ ���ݿ� ���� ������ �� ���ٴ� ������ �߻��Ѵ�. 
	s.DisplayX();
}