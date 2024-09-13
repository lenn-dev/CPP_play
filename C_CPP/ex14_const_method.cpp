// 1. 매개변수의 상수화 (모든 함수에 대해서)
// 2. 매개함수의 상수화 (멤버 메서드에 대해서만) : 클래스 안에서 다른 멤버변수의 접근을 막는
// const double PI = 3.14; 
// 상수형 변수는 값을 변경시킬 수 없다. 

# include <iostream>

using namespace std;

class Account {

public:
	Account() : money(0) {} // 매개변수 없을 때
	Account(int money) : money(money) {} // 매개변수 있을 때

	// 매개 변수 상수화의 예시
	// 매개 변수 앞에 const 
	void Deposit(const int d) {
		
		// 이런 명령어 쓰면 입금시 100원이 더 추가됨
		// 외부에서 변수 접근을 방지하기 위해 상수화
		// d = money;
		money += d;
		cout << "You've deposited " << d << " dollars." << endl;
	}
	void Withdraw(const int d) {
		// 계좌에 잔금이 0 이 아닌 경우 출금
		if (money > 0) {
			money -= d;
			cout << "You've withdrawed " << d << " dollars. " << endl;
		}
	}
	// getter
	// 멤버 메서드 상수화 괄호 뒤에 const
	// const int ViewBalance 와는 다름, 이건 리턴값이 const라는 것인데,
	// 원래 리턴값은 const 이기 때문에 이런표현이 유효하지 않음.
	int ViewBalance() const {

		// 멤버 메서드 상수화 예시
		// ViewBalance 함수 자체는 잔액을 확인하기 위한 것인데,
		// 외부에서 이에 접근해서 money++ 명령을 추가하면 잔액 확인시 잔액이 늘어남
		// 게임에서 이런 버그를 이용해 해킹 문제 있었음.
		// 따라서 이런문제를 방지하기 위해 멤버 메서드를 상수화한다.
		//money++;
		return money;
	}

private:
	// 객체지향의 장점
	// private 은 public 의 함수에 의해서만 간접적으로 접근이 가능
	// 만일 public 으로 직접 접근이 가능하다면 외부에서 조작가능해서 위험 
	// e.g. money * 2
	
	int money; 

};
int main_banking() {
	Account len(200);
	
	len.Deposit(100);
	len.Withdraw(20);

	cout << "Your balance is  " << len.ViewBalance() << endl;

	return 0;
}