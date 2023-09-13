#include <bits/stdc++.h>

using namespace std;

// 모든 순열

// 조건
// 

// 입력 
// 

// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    
    do{
        for(int i=0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }while(next_permutation(arr,arr+n));

   
    return 0;
}