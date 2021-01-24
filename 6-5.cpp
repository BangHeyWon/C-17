#include <iostream>
#include <string>

using namespace std;

//Shape 클래스는 앞으로 도형(원이나 직사각형 또는 삼각형)의 이름과 면적을 표현하기 위해 사용한다.
class Shape {
public:
	Shape(std::string n):name(n){}

	void GetArea() {
		std::cout << "Shape->도형 이름 : " << GetName()
			<< ",\t 도형 크기 : " << Area() << std::endl;
	}

	//면적은 도형별로 다르므로 다음과 같이 디폴트로 0을 반환한다.
	double Area() { return 0; }
	std::string GetName() {
		return name;
	}

private:
	std::string name;
};

//직사각형은 Shape 클래스를 기본 클래스로 하여 모든 멤버를 상속받는다.
class Rectangle : public Shape {
public:
	Rectangle(std::string n, float w = 0, float h = 0) : Shape(n), width(w), height(h){}
	//위의 도형에서 구한 면적은 맞지 않으므로 아래와 같이 다시 구현한다.
	//아래 한수는 직사각형의 면적을 계산하여 반환한다.
	double Area()const {
		return (width * height);
	}

	//직사각형의 이름과 면적을 출력한다.
	void GetArea() {
		std::cout << "Rectangle-> 도형 이름 : " << GetName()
			<< ", 도형 크기 : " << Area() << std::endl;
	}

protected:
	float width;
	float height;
};

int main() {
	//하위 클래스의 인스턴스를 생성하여 상위 클래스 타입의 변수에 할당한다.
	/*
	하위 인스턴스를 생성하여 상위 클래스 타입의 포인터에 할당하고 
	GetArea() 함수를 호출한다면, Rectangle 클래스의 GetArea() 함수를 호출하는 
	것이 아니라 Shape 클래스 내 존재하는 GetArea() 함수를 호출하게 된다. 
	*/
	Shape *s = new Rectangle("직사각형", 10, 5);
	s->GetArea();

	//다시 본래의 Rectangle 클래스 타입으로 변환하여 출력시킨다.
	Rectangle *r = (Rectangle *)s;
	r->GetArea();
	delete s;
}