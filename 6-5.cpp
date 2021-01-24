#include <iostream>
#include <string>

using namespace std;

//Shape Ŭ������ ������ ����(���̳� ���簢�� �Ǵ� �ﰢ��)�� �̸��� ������ ǥ���ϱ� ���� ����Ѵ�.
class Shape {
public:
	Shape(std::string n):name(n){}

	void GetArea() {
		std::cout << "Shape->���� �̸� : " << GetName()
			<< ",\t ���� ũ�� : " << Area() << std::endl;
	}

	//������ �������� �ٸ��Ƿ� ������ ���� ����Ʈ�� 0�� ��ȯ�Ѵ�.
	double Area() { return 0; }
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//���簢���� Shape Ŭ������ �⺻ Ŭ������ �Ͽ� ��� ����� ��ӹ޴´�.
class Rectangle : public Shape {
public:
	Rectangle(std::string n, float w = 0, float h = 0) : Shape(n), width(w), height(h){}
	//���� �������� ���� ������ ���� �����Ƿ� �Ʒ��� ���� �ٽ� �����Ѵ�.
	//�Ʒ� �Ѽ��� ���簢���� ������ ����Ͽ� ��ȯ�Ѵ�.
	double Area()const {
		return (width * height);
	}

	//���簢���� �̸��� ������ ����Ѵ�.
	void GetArea() {
		std::cout << "Rectangle-> ���� �̸� : " << GetName()
			<< ", ���� ũ�� : " << Area() << std::endl;
	}

protected:
	float width;
	float height;
};

int main() {
	//���� Ŭ������ �ν��Ͻ��� �����Ͽ� ���� Ŭ���� Ÿ���� ������ �Ҵ��Ѵ�.
	/*
	���� �ν��Ͻ��� �����Ͽ� ���� Ŭ���� Ÿ���� �����Ϳ� �Ҵ��ϰ� 
	GetArea() �Լ��� ȣ���Ѵٸ�, Rectangle Ŭ������ GetArea() �Լ��� ȣ���ϴ� 
	���� �ƴ϶� Shape Ŭ���� �� �����ϴ� GetArea() �Լ��� ȣ���ϰ� �ȴ�. 
	*/
	Shape *s = new Rectangle("���簢��", 10, 5);
	s->GetArea();

	//�ٽ� ������ Rectangle Ŭ���� Ÿ������ ��ȯ�Ͽ� ��½�Ų��.
	Rectangle *r = (Rectangle *)s;
	r->GetArea();
	delete s;
}