#include <iostream>
#include <string>

using namespace std;

int general(int i) {
	return i >= 0 ? i : -i;
}
//C언어에서 제공하는 매크로 함수이다.
#define unsafe(i)((i)>=0?(i):-(i))

//인라인 함수이다.
inline int safe(int i) {
	return i >= 0 ? i : -i;
}

//상수 표현식이다.
constexpr int expr(int i) {
	return i >= 0 ? i : -i;
}

int main() {
	int ans, x = 0;

	//1. 일반 함수를 호출하여 실행시킨 예이다.
	ans = general(x++);
	std::cout << "general(x++) = " << ans << "," << x << std::endl;

	//2. C언어의 매크로를 실행시킨 예이다.
	x = 0;
	ans = unsafe(x++);
	std::cout << "unsafe(x++) = " << ans << "," << x << std::endl;

	//3. 인라인 함수를 실행시킨 예이다.
	ans = safe(x++);
	std::cout << "safe(x++) = " << ans << "," << x << std::endl;
	x = 0;

	//4. 상수 표현식을 실행시킨 예이다.
	x = 0;
	ans = expr(x++);
	std::cout << "expr(x++) = " << ans << "," << x << std::endl;
	return 0;
}