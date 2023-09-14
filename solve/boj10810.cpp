#include <bits/stdc++.h>

using namespace std;

// 공 넣기

// 조건
// 

// 입력 
// 

// 출력
// 

int n,m;
int arr[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--){
        int i,j,k;
        cin >> i >> j >> k;
        for(int a=i;a<=j;a++){
            arr[a] = k;
        }
    }
    
    for(int i=1; i<=n;i++)
        cout << arr[i] << " ";
   
    return 0;
}