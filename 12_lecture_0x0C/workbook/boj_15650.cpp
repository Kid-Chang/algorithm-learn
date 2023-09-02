#include <bits/stdc++.h>

using namespace std;

// N과 M (2)

// 조건
// 

// 입력 
// n m

// 출력
// 1~n까지 m개를 중복없이 오름차순.

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

    // N과 M (1)과의 차이점.
    int start = 1;
    if(cur != 0) start = arr[cur-1] + 1;
    // 시작점이 정해져있다면, 해당 값은 탐색 영역에서 제외되니까.
    // 다음 값은 반드시 전에 선택된 마지막 숫자보다 크도록.
    
    for(int i=start; i<=n; i++){
        if(!isused[i]){
            isused[i] = true;
            arr[cur] = i;
            tracking(cur+1);
            isused[i] = false;
            
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