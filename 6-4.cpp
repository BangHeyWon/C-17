#include <iostream>
#include <string>

class Person {
public:
	Person() :Person("") {}
	Person(std::string n) :name(n) {}

	std::string GetName() {
		return name;
	}

protected:
	std::string degree;//���� �з��� ��Ÿ����.
private:
	std::string name;//����̸��� ��Ÿ����.
};

//StudentŬ������ Person Ŭ�����κ��� ����� �޴´�.
class Student : public Person {
public:
	//Person Ŭ������ name ��������� private������ ������ ���� Person Ŭ������ �����ڿ�
	//�Լ��� ȣ���Ͽ� �а� �� �� �ִ�. 
	Student(std::string n) : Person(n), total(0) {}

	int GetTotal() {
		return total;
	}

	void AddTotal(int i) {
		total += i;
	}
	//�л��� �ڽ��� �з��� �Է½�ų �� �ִ�.
	void SetDegree(std::string d) {
		degree = d;//�⺻ Ŭ�����κ��� ��ӹ޴� ��� �����̴�. 
	}
	//�ڽ��� ���� �з��� ��ȯ�޴´�.
	std::string GetDegree() {
		return degree;
	}

private://���� ��� ���� ���� ��ü ������ �Է��Ѵ�.
	int total;
};

int main() {
	Student s1("ȫ�浿");
	s1.SetDegree("�ʵ��б� ����");
	s1.AddTotal(95);
	std::cout << "�̸� : " << s1.GetName(); 
	std::cout << ", �з� : " << s1.GetDegree() << ", �������� : "<< s1.GetTotal() 
		<< std::endl;
	return 0;
}