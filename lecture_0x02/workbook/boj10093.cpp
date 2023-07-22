#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 대표값2

// 조건
// 

// 입력 
// 첫째 줄에 두 정수 A와 B가 주어진다.


// 출력
// 첫째 줄에 두 수 사이에 있는 수의 개수를 출력한다.
// 둘째 줄에 두 수 사이에 있는 수를 오름차순으로 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 주의. a,b 에 대한 순서가 없음. a가 더 크다면 스왑해줘야함.
    // 주의. a, b 가 같은 경우의 수를 생각해야함.
    long long a, b;
    cin >> a >> b;
    
    
    if(a==b || b-a==1) {
        cout<< 0;
        return 0;
    }

    if(a>b) swap(a, b);
    
    cout << (b-a-1) << "\n";
        
    for(long long i = a+1; i < b-1; i ++){
        cout << i << " ";
    }
    cout << b-1;
   
   return 0;
}