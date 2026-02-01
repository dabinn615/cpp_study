#include <iostream>
#include <string>
using namespace std;

class BankAccount{
private:
	int balance;
	string name;

public:

	BankAccount(string n,int b) : name(n), balance(b) {

	}

	void deposit(int amount) {
		if (amount > 0) {
			balance += amount;
			cout << name<<"님의 계좌로 " << amount << "원 입금 완료. " << name << "님의 잔액: " << balance << "원" << endl;
		}
	}

	bool withdraw(int amount) { //반환 타입이 true/false면 bool 사용!!
		if (amount <= balance) {
			balance -= amount;
			cout << name << "님의 계좌에서" << amount << "원 출금 완료." << name << "님의 잔액: " << balance << "원" << endl;
			return true;
		}
		else {
			cout << name << "님의 잔액이 " << amount - balance << "원 부족합니다. 출금 불가합니다." << endl;
			return false;
		}
	}
};

class Person {
public:
	string name;
	BankAccount* myAccount;

	Person(string n, BankAccount* ma ) :name(n), myAccount(ma) {

	}            
	void transfer(Person& to, int amount) { //Person& to: 받는 사람의 진짜 객체를 가져옴 
		if (this->myAccount->withdraw(amount)) { //this->: 나 자신 (보내는 사람)(생략 O)
			to.myAccount->deposit(amount); //to.myAccount: 받는 사람의 계좌, ->deposit(amount): 입금한다는 뜻
			//this->는 자기 자신을 가리키는 것, to는 상대방(받는 사람)을 가리키는 것이라 생각하면 댐
		}
		else {
			cout << "송금 실패" << endl;
		}
	}

};

int main() {
	cout << "돈을 보낼 사람과 받을 사람의 이름을 입력하세요: ";
	string sdname, rcname;
	cin >> sdname >> rcname;
	cout << sdname << "과 " << rcname << "의 계좌 잔액을 입력하세요: ";
	int sdmoney, rcmoney;
	cin >> sdmoney >> rcmoney;

	BankAccount sdacc(sdname,sdmoney); //보내는 사람 계좌 생성
	BankAccount rcacc(rcname,rcmoney); //받는 사람 계좌 생성

	Person sdAccount(sdname, &sdacc); //보내는 사람의 이름과 계좌의 주소 연결
	Person rcAccount(rcname, &rcacc); //받는 사람의 이름과 계좌의 주소 연결

	while (true) {

		cout << "송금할 금액을 입력하세요 (종료하려면 0 입력): ";
		int amount;
		cin >> amount;
		if (amount == 0) {
			cout << "종료합니다." << endl;
			break;
		}
		else {
			cout << sdAccount.name << "님이 " << rcAccount.name << "님에게 " << amount << "원을 송금합니다." << endl;
			sdAccount.transfer(rcAccount, amount);
		}
		
	}


	return 0;
}
