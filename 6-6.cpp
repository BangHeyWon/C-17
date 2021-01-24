#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	Shape(std::string n) :name(n) {}

	void GetArea() {
		std::cout << "���� �̸� : " << GetName()
			<< ",\t ���� ũ�� : " << Area() << std::endl;
	}

	//�Լ��� ���� �Լ��� �����Ѵ�.
	virtual double Area() { return 0; }
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//���簢�� Ŭ������ �����. 
class Rectangle : public Shape {
public:
	Rectangle(std::string n, float w = 0, float h = 0) : Shape(n), width(w), height(h) {}
	
	//���� �Լ��� ���� Ŭ������ �����ϴ� ����� ����Ͽ� �Ʒ��� ���� �����Ѵ�. 
	double Area() {
		return (width * height);
	}


protected:
	float width;
	float height;
};

//���簢�� Ŭ������ ��ӹ޴� �ﰢ�� Ŭ������ �����.
class Triangle : public Rectangle {
public:
	Triangle(float w = 0, float h = 0) : Rectangle("�ﰢ��", w, h) {};

	//���̻� �����Լ��� ��ӵ��� �ʵ��� ���� �� final�̶� �����ڸ� ����Ѵ�.
	virtual double Area() final{ return (Rectangle::Area() / 2); }
};


const double PI = 3.14159;

//�� Ŭ������ �����.
class Circle : public Shape {
public:
	Circle(double r = 0):Shape("��"),radius(r){}

	//C++���� �ֱ� ��� �ٸ� ��ü ���� ���ó�� ������ �Բ� �������̵��̶� ������ ���ԵǾ�����
	//���������� override �����ھ��� ����� �����Ͽ��� ������ ���� �� ������ ������ �����ϰ� �ִ�.
	double Area() override{ return (PI*(radius * radius)); }

protected:
	double radius;
};

int main() {
	/*
	�����Լ��� ȣ�� �۾��� ���� �ݵ�� 
	��ü�� ������ �Ǵ� ������ ����ؾ��Ѵ�.
	*/
	Shape *shape[] = {
		new Rectangle("���簢��",10,5),
		new Triangle(10,5),
		new Circle(10)
	};

	for (Shape *s : shape)
		s->GetArea();

	/*
	���� �����Ͱ� �ƴ� �Ϲ� ������ ����Ѵٸ� ���� �ٸ�
	����� ��Եȴ�. �Ϲ� ������ C���κ��� ����
	���� �������� ��ü ������ ������ �������� �ʴ´�. 
	*/
	Rectangle r("���簢��-2", 10, 15);
	Shape s = r;

	//Shape ��ü�� GetArea() �Լ��� ȣ��Ǿ� ũ�⸦ ���� �� �� ����.
	s.GetArea();

	//�޸𸮸� �Ҵ�޴� ��ü ��� �޸𸮸� ��ȯ�Ѵ�.
	for (Shape *s : shape)
		delete s;
}