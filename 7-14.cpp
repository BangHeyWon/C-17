#include <iostream>
#include <typeinfo>
#include <type_traits>

/*
1. ���ø� ��ȯ �������� T1�μ��� T2�μ��� ���� Ÿ���̶�� true�� �����ϱ� ������ enable_if ����ü �� type�� ��� �� �� �ִ�. 
�׷��� ���� ���� Ÿ���� �ٸ��ٸ� false�� ��ȯ�Ѵ�. �׿� ���� enable_if ����ü�� type�� �������� �����Ƿ� �����߻��� �Բ� �ش�
�Լ� ���ø��� ��Ȱ��ȭ �ȴ�. 
*/
template<typename T1, typename T2>
typename std::enable_if<std::is_same<T1,T2>::value, bool>::type
check_type(const T1& t1, const T2& t2) {
	std::cout << t1 << "�� " << t2 << "�� ���� Ÿ���̴�." << std::endl;
	return true;
}

//2. �Ʒ� �Լ��� �μ��� ���� �ٸ� Ÿ���̶�� Ȱ��ȭ �ȴ�.
template<typename T1, typename T2>
typename std::enable_if<!std::is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2) {
	std::cout << t1 << "�� " << t2 << "�� ���� �ٸ� Ÿ���̴�." << std::endl;
	return false;
}

int main() {
	check_type(10, 40);
	check_type(10, 40.56);
	check_type(10, "Test Ÿ��");
}
