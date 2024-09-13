// 1. �Ű������� ���ȭ (��� �Լ��� ���ؼ�)
// 2. �Ű��Լ��� ���ȭ (��� �޼��忡 ���ؼ���) : Ŭ���� �ȿ��� �ٸ� ��������� ������ ����
// const double PI = 3.14; 
// ����� ������ ���� �����ų �� ����. 

# include <iostream>

using namespace std;

class Account {

public:
	Account() : money(0) {} // �Ű����� ���� ��
	Account(int money) : money(money) {} // �Ű����� ���� ��

	// �Ű� ���� ���ȭ�� ����
	// �Ű� ���� �տ� const 
	void Deposit(const int d) {
		
		// �̷� ��ɾ� ���� �Աݽ� 100���� �� �߰���
		// �ܺο��� ���� ������ �����ϱ� ���� ���ȭ
		// d = money;
		money += d;
		cout << "You've deposited " << d << " dollars." << endl;
	}
	void Withdraw(const int d) {
		// ���¿� �ܱ��� 0 �� �ƴ� ��� ���
		if (money > 0) {
			money -= d;
			cout << "You've withdrawed " << d << " dollars. " << endl;
		}
	}
	// getter
	// ��� �޼��� ���ȭ ��ȣ �ڿ� const
	// const int ViewBalance �ʹ� �ٸ�, �̰� ���ϰ��� const��� ���ε�,
	// ���� ���ϰ��� const �̱� ������ �̷�ǥ���� ��ȿ���� ����.
	int ViewBalance() const {

		// ��� �޼��� ���ȭ ����
		// ViewBalance �Լ� ��ü�� �ܾ��� Ȯ���ϱ� ���� ���ε�,
		// �ܺο��� �̿� �����ؼ� money++ ����� �߰��ϸ� �ܾ� Ȯ�ν� �ܾ��� �þ
		// ���ӿ��� �̷� ���׸� �̿��� ��ŷ ���� �־���.
		// ���� �̷������� �����ϱ� ���� ��� �޼��带 ���ȭ�Ѵ�.
		//money++;
		return money;
	}

private:
	// ��ü������ ����
	// private �� public �� �Լ��� ���ؼ��� ���������� ������ ����
	// ���� public ���� ���� ������ �����ϴٸ� �ܺο��� ���۰����ؼ� ���� 
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