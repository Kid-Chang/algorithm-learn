#include <bits/stdc++.h>

using namespace std;

// 역원소 정렬

// 조건
// 

// 입력 
// 

// 출력
// 
int n;
long long arr[10000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        string num;
        
        cin >> num;
        
        reverse(num.begin(), num.end());
        
        arr[i] = stoll(num);
        
    }
    
    sort(arr,arr+n);
    
    
    for(int i=0;i<n;i++){
        cout <<  arr[i] << "\n";
    }

   
    return 0;
}