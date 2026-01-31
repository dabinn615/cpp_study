#include <iostream>
#include <string>
using namespace std;

class Coffee {
public:
	string name;

	Coffee(string n) :name(n) {

	}
	virtual void taste() { //함수가 void 타입이면 아무것도 반환하지 않음
		cout << name << "는 씁쓸한 커피 맛입니다." << endl;
	}

};

class Latte :public Coffee {
public:
	Latte(string n) : Coffee(n) {

	}

	void taste() override {
		cout << name << "는 우유가 들어가 부드러운 맛입니다." << endl;
	}
};

int main() {
	Coffee coffee1("아메리카노");
	coffee1.taste(); // Coffee 클래스의 taste() 함수 호출 (이미 함수에 출력코드가 있으므로 호출만 함!!)
	Latte latte1("카페라떼");
	latte1.taste(); // Latte 클래스의 taste() 함수 호출 (이미 함수에 출력코드가 있으므로 호출만 함!!)

	return 0;
}
