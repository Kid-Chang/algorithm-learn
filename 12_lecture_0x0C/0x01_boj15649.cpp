#include <bits/stdc++.h>

using namespace std;

// N과 M (1)

// 조건
// 

// 입력 
// 

// 출력
// 

int n,m;
int arr[10];
bool isUsed[10];

void tracking(int value){
    if(value == m){
        for(int i=0; i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!isUsed[i]){
            arr[value] = i;
            isUsed[i] = true;
            tracking(value+1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    tracking(0);
   
    return 0;
}