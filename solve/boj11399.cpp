#include <bits/stdc++.h>

using namespace std;

// ATM

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int arr[1001];
int sum = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        int input_value;
        cin >> arr[i];
    }
    
    sort(arr,arr+n);
    
    for(int i=1;i<n;i++){
        arr[i] = arr[i-1]+arr[i];
    }
    
    for(int i=0;i<n;i++){
        sum +=arr[i];
    }
    
    cout << sum;
    
    return 0;
}