#include <bits/stdc++.h>

using namespace std;

// N과 M (4)

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
    
    int start = 1;
    if(cur != 0) start = arr[cur-1];
    for(int i=start; i<=n; i++){
        if(!isused[i]){
            // isused[i] = true;
            arr[cur] = i;
            tracking(cur+1);
            // isused[i] = false;
            
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