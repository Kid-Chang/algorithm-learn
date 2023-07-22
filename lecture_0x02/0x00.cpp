#include <iostream>
#include <vector> // 백터 stl 사용
using namespace std; // std::cout  와 같은 잡일 제거



//
// 기본 이론.

// 1. 출력 0
// 값을 복사함
void func(int a){
    a = 5;
}
int main(void) {
    int t = 0;
    func(t);
    cout << t;
}

// 2. 배열의 경우 메모리 주소를 기반으로 인자로 넘겨주기에,
// 값이 변함
void func(int arr[]){
    arr[0] = 10;
}

int main(void){
  int arr[3] = {1,2,3};
  func(arr);
  std::cout << arr[0];
}


// 3. 구조체도 int와 마찬가지로 값을 copy함.
struct pt{
int x,y;
};

void func(pt a){
  a.x = 10;
  
}

int main(void){
  pt tmp ={0,0};
  func(tmp);
  std::cout << tmp.x;
}


//
// 참조자

// 1. 아래코드는 의미가 없다.
// swap 함수를 실행함에 따라 즉각 받은 인자값이 
// a, b 값으로 복사되기때문.

void swap1(int a, int b){
  int tmp =a;
  a=b;
  b=tmp;
}

// 2. 아래코드는 작동할 것이다.
// 주소값을 복사했기에, 복사한 주소값을 찾아가 값을 바꾸기때문.
void swap2(int* a, int* b){
  int tmp=*a;
  *a = *b;
  *b = tmp;
}

// 3. 아래값은 c++에서 이용하는 reference(참조자)이다.
void swap3(int& a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}


//
// 2. 복사본의 함정과 & 

// cmp1
// 그럼 아래의 코드가 작동하는데 시간복잡도는 어떻게 될까?
// O(N)이다. 왜냐? vector를 카피하기 때문.
// v1카피에 n, v2카피에 n 총 2n이 소요된다.
bool cmp1(vector<int> v1, vector<int> v2, int idx){
  return v1[idx] > v2[idx];
}

// &(참조) 연산자.
// 이 친구는 복사본을 만드는 것이 아닌, 참조 대상의 주소정보만을 넘겨보낸다.

//  cmp2.
bool cmp2(vector<int>& v1, vector<int>& v2, int idx){
  return v1[idx] > v2[idx];
}
// 위 코드는 시간복잡도가 얼마나 걸릴것 같나?
// O(1)이다. 왜냐? 복사본을 만들지 않고, 참조해서 처리하기 때문.

