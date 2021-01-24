#include <iostream>
#include <string>

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCTION__
#endif 

//1. �Ʒ��� �⺻ Ŭ���� ���ø��̴�.
template <typename Key, typename Value>
class KeyValuePair{
public:
	//__PRETTY_FUNCTION__ ��ũ�δ� ȣ���� �Լ��� Ÿ���� ����ϴ� ����� �����Ѵ�.
	KeyValuePair(Key k, Value v) :key(k), value(v) {
		std::cout << "1 " << __PRETTY_FUNCTION__ << ':' << "original\n";
	}
private:
	Key key;
	Value value;
};

//2. �Ʒ��� ���� ���ø� �μ� ��ο� ���� ����� ���ø� Ư��ȭ�� �����Ѵ�.
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

//3. �Ʒ��� ���� ���ø� �μ� ��� Value �μ��� ���� �κ� ���ø� Ư��ȭ�� �����Ѵ�.
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

//���� Ŭ���� �������� ���ø� Ư��ȭ�� Ŭ���� ���ø��� ȣ���ϴ� ���� ������ ����.
int main() {
	//1. �⺻ Ŭ���� ���ø��� �����ڸ� ȣ���Ѵ�.
	KeyValuePair<int, int> kvp1(100, 100);
	//3. template<typename Key> class KeyValuePair<Key, std::string>
	//Ŭ���� ���ø��� �����ڸ� ȣ���Ѵ�.
	KeyValuePair<long, std::string> kvp2(100, "���ø� Ư��ȭ");
	//2. template <> class KeyValuePair<int, std::string> Ŭ���� ���ø��� �����ڸ� ȣ���Ѵ�.
	KeyValuePair<int , std::string> kvp3(100, "���ø� Ư��ȭ");
}