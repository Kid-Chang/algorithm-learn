#include <bits/stdc++.h>

using namespace std;

// 1로 만들기 (재귀, 시간초과)

// 조건
// 

// 입력 
// 

// 출력
// 

int input_value;
int mxmin = 99999;

void recursion(int n, int cnt){
    if(n == 1) {
        mxmin = min(cnt, mxmin);
        return;
    }
    
    if(n%2==0) bfs(n/2, cnt+1);
    if(n%3==0) bfs(n/3, cnt+1);
    bfs(n-1, cnt+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> input_value;
    
    recursion(input_value, 0);
    
    cout << mxmin;

   
    return 0;
}