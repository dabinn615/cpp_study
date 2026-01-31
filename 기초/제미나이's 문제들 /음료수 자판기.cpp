#include <iostream>
#include <string>
using namespace std;

class VendingMachine {
public:
	int drinkcount;
	int price;

	VendingMachine(int dk, int pr) :drinkcount(dk), price(pr) {
	
	}
	
	string Buy(int money) {
		if (money < price) {
			return "잔액이 부족합니다.";
		}
		else if (drinkcount == 0) {
			return "품절입니다.";
		}
		else {
			drinkcount--;
			int change = money - price;
			cout << "음료가 나옵니다. 잔돈: " << change << endl;
			return "성공";
		}
	}

};

int main() {

	int dc, pr;
	cout << "초기 음료수 자판기의 음료수 개수와 음료수 가격을 입력하세요: ";
	cin >> dc >> pr;
	VendingMachine vm(dc, pr);

	while (true) {
		int money;
		cout << "돈을 넣어주세요: ";
		cin >> money;

		string result = vm.Buy(money);

		if (result == "품절입니다.") {
			cout << result <<  endl;
			break;
		}
		else if (result == "잔액이 부족합니다.") {
			cout << result << endl;
			cout << "돈을 다시 넣어주세요." << endl;
			continue;
		}
		else {
			cout << "남은 재고: " << vm.drinkcount << endl;
			continue;
		} 
	}
	return 0;
}
