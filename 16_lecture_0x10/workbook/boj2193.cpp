#include <bits/stdc++.h>

using namespace std;

// 이친수

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long arr[92];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    arr[1]=1;
    arr[2]=1;
    
    for(int i=3;i<=n;i++){
        arr[i]= arr[i-1] + arr[i-2];
    }
    
    cout << arr[n];
   
    return 0;
}