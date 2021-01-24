#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	Shape(std::string n) :name(n) {}

	void GetArea() {
		std::cout << "도형 이름 : " << GetName()
			<< ",\t 도형 크기 : " << Area() << std::endl;
	}

	//함수를 가상 함수로 선언한다.
	virtual double Area() { return 0; }
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//직사각형 클래스를 만든다. 
class Rectangle : public Shape {
public:
	Rectangle(std::string n, float w = 0, float h = 0) : Shape(n), width(w), height(h) {}
	
	//가상 함수는 하위 클래스가 제공하는 멤버를 사용하여 아래와 같이 구현한다. 
	double Area() {
		return (width * height);
	}


protected:
	float width;
	float height;
};

//직사각형 클래스를 상속받는 삼각형 클래스를 만든다.
class Triangle : public Rectangle {
public:
	Triangle(float w = 0, float h = 0) : Rectangle("삼각형", w, h) {};

	//더이상 가상함수로 상속되지 않도록 막을 때 final이란 지정자를 사용한다.
	virtual double Area() final{ return (Rectangle::Area() / 2); }
};


const double PI = 3.14159;

//원 클래스를 만든다.
class Circle : public Shape {
public:
	Circle(double r = 0):Shape("원"),radius(r){}

	//C++언어는 최근 들어 다른 객체 지향 언어처럼 지문과 함께 오버라이딩이란 개념이 도입되었지만
	//오래전부터 override 지정자없이 사용이 가능하였기 때문에 현재 두 종류의 문법이 공존하고 있다.
	double Area() override{ return (PI*(radius * radius)); }

protected:
	double radius;
};

int main() {
	/*
	가상함수의 호출 작업을 위해 반드시 
	객체를 포인터 또는 참조로 사용해야한다.
	*/
	Shape *shape[] = {
		new Rectangle("직사각형",10,5),
		new Triangle(10,5),
		new Circle(10)
	};

	for (Shape *s : shape)
		s->GetArea();

	/*
	만약 포인터가 아닌 일반 변수를 사용한다면 전혀 다른
	결과를 얻게된다. 일반 변수는 C언어로부터 물려
	받은 유산으로 객체 지향의 개념을 지원하지 않는다. 
	*/
	Rectangle r("직사각형-2", 10, 15);
	Shape s = r;

	//Shape 객체의 GetArea() 함수가 호출되어 크기를 전혀 알 수 없다.
	s.GetArea();

	//메모리를 할당받는 객체 모두 메모리를 반환한다.
	for (Shape *s : shape)
		delete s;
}