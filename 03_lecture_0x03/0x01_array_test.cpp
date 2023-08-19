#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    // 여기서 왜 int& len을 왜 쓰냐?
    // 그냥 int len을 하면 값을 복사하지만,
    // int&를 이용하면 메모리 주소를 가져오기에, 값을 전역적으로 변경할 수 있다.
    // 즉 배열의 길이를 줄이거나 늘릴때, len을 수정해줘서 배열의 길이를 따로 보관할 수 있다.
    for(int i = len; i > idx; i--){
        arr[i+1]=arr[i];
        // arr[i] = arr[i-1]로도 가능
    }
    // 추가적으로 i > idx를 i >= idx로 변경한다면,  
    // arr[i+1]=arr[i]; 의 경우에선 배열의 끝자리에서 값을 조정시, 
    // 지정된 메모리 주소보다 오른쪽으로 넘어갈 수 있고
    // arr[i] = arr[i-1] 이라면 배열의 맨 첫자리(0)에서 값을 조정시,
    // 지정된 메모리 주소보다 왼쪽으로 넘어갈 수 도 있다.
    // 이렇게되면 런타임 에러가 발생할 수 있으니 주의할 것.
    
    arr[idx]=num;
    len++;
}

void erase(int idx, int arr[], int& len){
    for(int i = idx; i < len; i++){
        arr[i]=arr[i+1];
    }
    len--;
  
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}