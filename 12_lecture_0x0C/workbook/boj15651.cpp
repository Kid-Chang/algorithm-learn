#include <bits/stdc++.h>

using namespace std;

// N과 M (3)

// 조건
// 

// 입력 
// n m

// 출력
//

int n, m; 
int arr[20];
bool isused[20];

void tracking(int cur){
    if(cur == m){
        for(int j=0;j<m;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(!isused[i]){
            arr[cur] = i;
            tracking(cur+1);
            
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