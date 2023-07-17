#include <iostream>
#include <vector> // 백터 stl 사용
using namespace std; // std::cout  와 같은 잡일 제거

//
// 입출력

// 1. 입력
// 기존 c에서 하는 방법
int main(void){
  char a[10];
   scanf("%s", a);
  printf("a is %s\n", a);
}
// c++ 문법
int main(void){
  string s;
  cout << "input : ";
  cin >> s;
  cout << "s is " << s;
}
// 참고로 이 코드를 보면 알수 있듯, << 은 오른쪽 값을 왼쪽으로, >> 은 왼쪽값을 오른쪽으로 넘긴다고 이해하면 편할 듯하다.

// 둘다 결과는 같다.
// hi hello 라고 입력하면
// s is hi 로 출력된다. 즉 공백부터는 짤린다.

// 이를 해결하기위해서 아래와 같이 작성한다.

// 1. \n이 나오기 전까지 받으라고 명시.
char a1[10];
scanf("%[^\n]", a1);
// 2. getline
string s;
getline(cin, s);
cout << s;
// getline의 단점은 입력타입이  c++ string이어야 한다는 점이다.

// 즉 1, 2번 방법중 취사선택.


// 아무튼 공백이 포함된 문자열을 받아야 할 때 단순히 scanf나 cin을 쓰면 안된다는걸 꼭 기억


