#include <iostream>

//�Ʒ��� �⺻ Ŭ���� ���ø��̴�. Ŭ���� ���ø��� ��� ������ ȭ�鿡 ����ϴ� ����� �����Ѵ�.
template <class T>
class Form {
	T* _t;

public:
	Form(T* t):_t(t){ }
	void print() {
		std::cout << *_t << std::endl;
	}
};

template <>
class Form<char *> {
	char* _t;

public:
	Form(char* t) :_t(t) { }
	void print() {
		std::cout<<"Form<char *> :  "<< _t << std::endl;
	}
};

int main() {
	int i = 157;
	Form<int> form1(&i);//�⺻ ���ø��� �����Ѵ�.

	char c[10] = "string1";
	//�Ʒ��� ���� char* �μ��� ����Ͽ� ���ø� Ư��ȭ�� Ŭ���� ���ø��� �ν��Ͻ��� �����.
	Form<char*> form2(c);

	form1.print();
	form2.print();
}

