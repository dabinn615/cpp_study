#include <iostream> 
#include <string>
using namespace std; 

class Rectangle { //Rectangle 클래스 정의
public:
	int width; //속성
	int height;

	Rectangle(int w, int h) : width(w), height(h){ //생성자
		//초기화! (중괄호 안은 비워둠)
	}

	int getArea() { //함수 (int형으로 값을 반환)
		return width * height;
	}
};

int main() { 
	int width, height;
	cin >> width >> height; //사각형의 가로와 세로의 길이를 입력받음

	Rectangle rect(width, height); //rect이라는 객체 생성
	cout << "Area:" << rect.getArea() << endl; //객체의 넓이를 출력

	return 0;
}
