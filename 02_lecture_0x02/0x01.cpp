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

//
// 내용 날라감 하핫. 그냥 핵심 복붙한다.


// scanf/printf 등에서 쓰는 C stream과 cin/cout 등에서 쓰는 C++ stream은 분리가 되어있습니다
// 코드의 흐름과 실제 출력이 동일하기 위해서 기본적으로 프로그램에서는 C++ stream과 C stream을 동기화하고 있습니다.
// 대신 동기화를 끊었으면 절대 cout과 printf를 섞어쓰면 안됩니다. 섞어쓰면 순서가 꼬이게 됩니다.

// scanf/printf와 다르게 cin/cout은 입출력으로 인한 시간초과를 막기 위해서 ios::sync_with_stdio(0), cin.tie(0)이라는 두 명령을 실행시켜야 합니다.
// cin 명령을 수행하기 전에 cout 버퍼를 비우지 않도록 하는 코드가 cin.tie(nullptr) 

// endl은 개행문자("\n")를 출력하고 출력 버퍼를 비워라는 명령입니다. 앞에서도 얘기했지만 어차피 저지는 프로그램이 종료될 때 출력이 어떻게 생겼는지를 가지고 채점을 진행하니까 중간 중간 버퍼를 비우라고 명령을 줄 필요가 전혀 없습니다.




// 구체적인 팁인데 출력 맨 마지막에 공백 혹은 줄바꿈이 추가로 있어도 상관이 없습니다. 당장 앞의 문제도 엄밀하게 말을 하면 답이 1 4 2 3일 때 3 다음에 공백 1개가 추가로 출력되었습니다. 그래도 아무 문제 없이 정답 처리가 됐습니다.
//공백이랑 비슷하게 줄바꿈 또한 출력 맨 마지막에 추가로 있어도 정답 처리가 됩니다. 그래서 이 부분을 별도로 예외처리를 할 필요가 없습니다.



