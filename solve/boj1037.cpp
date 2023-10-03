#include <bits/stdc++.h>

using namespace std;

// 약수

// 조건
// 

// 입력 
// 

// 출력
// 
int n;
int arr[52];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        int input_value;
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    cout << arr[0] * arr[n-1];
   
    return 0;
}