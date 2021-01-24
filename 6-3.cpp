#include <iostream>
#include <string>

class Person {
public:
	Person():Person(""){}
	Person(std::string n):name(n){}

	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//StudentŬ������ Person Ŭ�����κ��� ����� �޴´�.
class Student : public Person {
public:
	/*
	�Ʒ� name ������ ��ü Ŭ���� �� �����ϴ� name �����̴�. ���� �⺻
	Ŭ����(Person) �� name ������ �ʱ�ȭ�Ϸ��� Person(n) �����ڸ� ȣ
	���� �־�� �Ѵ�. ���� �Ʒ� �����ڴ� ���� ����� �����Ƿ� Person
	Ŭ������ �ν��Ͻ��� �����ϱ� ���� ����Ʈ �����ڸ� ȣ���Ѵ�. 
	*/
	Student(std::string n):name(n){}
	
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

int main() {
	Student s1("ȫ�浿");
	std::cout << "Student : " << s1.GetName() << std::endl;//�Ʒ� GetName �Լ��� ��� 'Student::'�� �����Ǿ� �ִ�.
	//���� Ŭ���� �̸��� ����Ͽ� ȣ���� �� �ִ�.
	std::cout << "Person : " << s1.Person::GetName() << std::endl;//PersonŬ������ GetName()�Լ��� ȣ���ϴ� ����̴�.
	return 0;
}