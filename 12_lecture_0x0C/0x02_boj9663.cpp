#include <bits/stdc++.h>

using namespace std;

// N-Queen

// 조건
// 

// 입력 
// 

// 출력
// 

int n, cnt=0;
bool isUsed1[60]; // 열에 대응되는 값, (x, y)에 퀸이 있으면 isUsed1[y]를 true로.
bool isUsed2[60]; // 좌측 하단과 우측 상단을 연결하는 대각선. (x, y)에 퀸이 있으면 isUsed2[x+y]를 true로.
bool isUsed3[60]; // 좌측 상단과 우측 하단을 연결하는 대각선. (x, y)에 퀸이 있으면 isUsed3[x-y+n-1]를 true로.
// n-1를 붙이는 이유는 인덱스를 음수로 보내지 않기위해서.


void tracking(int cur_row){
    if(cur_row == n){
        cnt++;
        return;
    }
    
    for(int cur_col = 0; cur_col < n; cur_col++){
        if(isUsed1[cur_col] || isUsed2[cur_col+cur_row] || isUsed3[cur_row-cur_col+n-1]){
            continue;
        }
        isUsed1[cur_col] = true;
        isUsed2[cur_row+cur_col] = true;
        isUsed3[cur_row-cur_col+n-1] = true;
        tracking(cur_row+1);
        isUsed1[cur_col] = false;
        isUsed2[cur_row+cur_col] = false;
        isUsed3[cur_row-cur_col+n-1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    tracking(0);
   
    cout << cnt;
    return 0;
}