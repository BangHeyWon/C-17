#include <iostream>

using namespace std;

struct complex {
	constexpr complex(double r, double i) : re(r), im(i){}
	constexpr double real() const { return re; }
	constexpr double imag() const { return im; }

private:
	double re;
	double im;
};

constexpr double square(double x) { return x * x; }

int main() {
	//1.�μ��� ���ͷ��� ����Ͽ����Ƿ� ����� �����ϴ�. comp ������ ����� ���ȴ�.
	constexpr complex comp(0.0, 1.0);
	const double x = 1.0;

	//2. constexpr �����ڷ� ������ ������ ����� �ǹ��Ѵ�. ���� �������� �μ���
	//������ ����Ѵٸ� x������ ���� �� �� �ִ��ϴ��� ������ �߻��Ѵ�.
	//constexpr complex cx1(x, 0); //���� �߻�!

	//3. ���� cx1 ������ ���ȴ�. ��� ǥ�������� ����� �����ڴ� �ζ��� �Լ��� �νĵǹǷ� 
	//�Ϲ� ��ü�� �����ϴ� �� ����ϴ��� ���� ������ ���� �ʴ´�. 
	complex cx1(x, 10);//OK
	std::cout << "�Ǽ� : " << cx1.real() << ", ��� : " << cx1.imag() << std::endl;

	//cx2 ������ const ����� ����Ǿ� �ֱ� ������ ���ȴ�.
	const complex cx2(x, 1);

	//5. comp ������ constexpr �����ڷ� ����� ����Ǿ� �����Ƿ� ���� ��� ���� ���� ���
	//����� �νĵǹǷ� ���ȴ�.
	constexpr double cr = comp.real(); //OK
	constexpr double ci = comp.imag(); //OK
	std::cout << "�Ǽ� : " << cr << ", ��� : " << ci << std::endl;

	//6. ���� 3�� ���� ������ ���ȴ�. constexpr �����ڴ� ��� ��� ������ �ʱ�ȭ ���� �����Ѵ�. 
	complex cx3(2, 4.6);
	const int dmv = 17; //dmv�� ����̴�.
	int var = 17;

	//7. square(17)�Լ��� const ����� �μ��� ����ϹǷ� ���ȴ�.
	constexpr double max1 = 1.4 * square(dmv);

	//8. constexpr �����ڷ� ������ ������ ����� �ǹ��Ѵ�. ���� �տ��� ������ ������ ����
	//"�Լ��� �μ��� ������ ����Ѵٸ� x ������ ���� �� �� �ִ�. "�ϴ��� ������ �߻��Ѵ�.
	//constexpr double max2 = 1.4 * square(var); //����!

	//9.const ����� ������ ����ϴ��� ������ �ʱ�ȭ�Ǿ� �ִٸ� ���ȴ�.
	double max2 = 1.4 * square(var);
	const double max3 = 1.4 * square(var);
	std::cout << "���� : " << max3 << std::endl;
}