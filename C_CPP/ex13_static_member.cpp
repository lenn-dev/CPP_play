// static 정적 멤버 메서드
// 구조체의 멤버는 모두 동적멤버와 같음 : 
// 즉 붕어빵 틀에서 붕어빵을 찍어낼때마다 객체에 포함되는 멤버
// 정적멤버는 붕어빵 틀에 해당되는 멤버로 클래스 하나당 정적멤버는 하나만 부여됨.

# include <iostream>

using namespace std;

// 색을 저장하는 프로그램 작성
// float으로 0-1 사이의 수를 부여해 RGB 저장해볼것


class Color {
public:
	// Color 객체 생성될 때마다 번호를 부여하고 싶음
	// 전에 만들어진 객체의 아이디 값에 1을 저장한 후 id에 1을 저장 : 후위증가
	// 초기화 목록에 넣어줌. ++ 이런 표현 들어가도 됨
	Color() : r(0), g(0), b(0), id(idCounter++) { } // rgb 모두 0일 때 블랙
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) { }

	// getter setter 만들어야 하는데 상식적으로 색을 저장하니까 
	// 개별변수 밸류를 변경하는 것 보다는 아예 새로운 객체 만들어서 대입하는게 나으므로
	// setter는 만들지 않고 getter 만 만들 예정

	float getR() { return r; }
	float getG() { return g; }
	float getB() { return b; }

	int GetId() { return id; }

	// static 메서드는 전역함수로 쓰고 싶고, class 와 밀접한 연관이 있으면서도
	// 클래스 안에 private 변수에 접근하고 싶을때 클래스에 넣고 사용함.
	// 그럼으로 인해서 객체 찍어낼때마다 그 객체에 포함되는 것이 아니라
	// 클래스에 포함된 하나뿐인 메서드가 되는 것임
	// 
	// 
	// MixColor 함수를 Color 안에 넣었을 때, main함수에서 호출하기 애매해짐.
	// purple 색을 만들때 red.MixColor, blue.MixColor등의 표현이 어색함
	// 그나마 purple.MixColor 가 제일 적당하지만 여전히 어색한 표현
	// 이 때 Color 클래스 멤버변수가 된 MixColors 함수 앞에 static 을 써주면 정적멤버가됨
	// 호출방식은 네임스페이스처럼 :: 사용, Color 클래스 안에 MixColors 함수 이런식
	/*static Color MixColors(Color a, Color b) {
		Color result = Color((a.getR() + b.getR()) / 2, (a.getG() + b.getG()) / 2, (a.getB() + b.getB()) / 2);
		return result;
	}*/
	
	
	// 여기서 MixColors를 구지 Class 안에 넣어서 썼을때 편한점을 말하자면
	// 클래스 안에 들어왔기 때문에 private 멤버 접근이 가능해지기 때문에
	// 코드를 아래와 같이 바꿔줄 수 있음
	// 즉 setter함수를 호출하지 않고 r,g,b 를 접근해서 사용
	static Color MixColors(Color a, Color b) {
		Color result = Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
		return result;
	}


	// Color 객체 생성될 때마다 번호를 부여하고 싶음
	// static 으로 클래스 안에서 초기값을 줄 수 없고, 
	// 클래스 바깥에서 초기값 주어야 함
	//static int idCounter = 1;
	static int idCounter;

private:
	float r;
	float g;
	float b;

	// 만들어지는 객체에 번호를 부여
	int id;

};

// 전역변수 형태로 선언된 것을 클래스 안에 정적형태로 집어 넣은 후에
// 클래스 밖에서 네임스페이스 쓰듯이 해서 선언과 정의를 분리한 방법으로 초기값 줌
int Color::idCounter = 1;

// 두가지 색을 받아 섞는 함수
// 반환 형태는 Color (class 로 지정한것을 자료형태로 쓸 수 있나?)
// a 가 가진 rgb 값, b 가 가진 rgb 값 이라고 하는 것을 보니 class를 자료형값으로 보는 것 같음.
// 즉 rgb값을 가지는 두개의 컬러를 섞는다고 하면 
// r,g,b 값을 각각 더해 평균 낸 값을 반환하면 섞은 색깔이 됨.
//Color MixColors(Color a, Color b) {
	// 클래스 Color 객체 result만들어 생성자 바로 호출 
	//Color result = Color((a.getR() + b.getR())/ 2, (a.getG() + b.getG())/ 2, (a.getB() + b.getB())/ 2);
	//같은 표현
	//Color result((a.getR() + b.getR()) / 2, (a.getG() + b.getG()) / 2, (a.getB() + b.getB()) / 2);
	//return result;
//}


int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);

	// static 멤버 불러내는 방법 
	Color purple = Color:: MixColors(blue, red);
	
	// Color purple = blue.MixColors(blue, red);
	// 이런식으로 해도 동작하는데 static 메서드는 어떤 객체에 포함된 형태로도 사용됨
	// 이런점 때문에 동적멤버보다는 표현이 좀 더 편함


	cout << " r = " << purple.getR() << " g = " << purple.getG() << " b = " << purple.getB() << endl;

	
	cout << "blue.GetId() = " << blue.GetId() << endl;
	cout << "red.GetId() = " << red.GetId() << endl;
	cout << "purple.GetId() = " << purple.GetId() << endl;
}