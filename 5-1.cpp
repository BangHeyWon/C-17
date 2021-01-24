#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>

struct Account {
	//구조체는 디폴트가 public이다. 아래 생성자는 다른 함수로부터 호출이 가능하다.
	Account(const char *id, const char *name, int bal) {
		strcpy(this->account, id);
		strcpy(this->name, name);
		this->balance = bal;
	}
	void Print() {
		printf("계 좌 : %s, 소유자 : %s", account, name);
		printf(", 잔 액 : %i\n", balance);
	}
	void Deposit(int money) {
		balance += money;
	}
	void Withdraw(int money) {
		balance -= money;
	}

private:
	char account[20];
	char name[20];
	int balance;
};

int main() {
	//문자열을 배열로 선언하여 사용한다면 const 지정자가 없어도 사용이 가능하다. 
	char id[] = "120-345-129099";
	char name[] = "홍길동";
	Account hong = Account(id, name, 60000);
	hong.Print();

	//printf("계 좌 : %s, 소유자 : %s", hong.account, hong.name);
	//printf(", 잔 액 : %i\n", balance);
	/*
	위의 함수  내 hong.account 멤버와 hong.name 멤버는 외부로부터 접근 제한이 걸려있는 멤버이다.
	따라서 위의 경우 컴파일하는 과정에서 모두 에러가 발생한다. Account 클래스 입장에서 보면 main() 함수는 영역밖에 존재하는 함수이다.
	*/
	return 0;
}