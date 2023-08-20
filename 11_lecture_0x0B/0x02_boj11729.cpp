#include <bits/stdc++.h>

using namespace std;

// 하노이 탑 이동 순서
// 주의 사항: pow함수는 결과값이 100만이 넘어가면 지수표기법으로 출력하기 때문에 위험하다. 
//따라서 (1<<n)과 같이 쉬프트 연산을 통해 2의 N제곱을 표현해준다. (이진수이기 때문에 2의 제곱배가 되는것.)
// 틀린 이유가 이거때문임.

// 조건
// 

// 입력 
// 

// 출력
// 

void recursion(int a, int b, int n){
    if(n == 1){
        cout << a << " " << b << "\n";
        return;
    }
    recursion(a, 6-a-b, n-1);
    cout << a << " " << b << "\n";
    recursion(6-a-b, b, n-1);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int number;
    cin >> number;
    
    cout << (1<<number) - 1 << "\n";
    recursion(1, 3, number);
    
    return 0;
}