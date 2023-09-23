#include <bits/stdc++.h>

using namespace std;

// 1로 만들기

// 조건
// 

// 입력 
// 

// 출력
// 

int input_value;
int vis[1000001]; // 특정 수까지 도달하는데 최소 수

void dp(int n){
    if(n==1) return;
    if(n%3==0) {
        vis[n/3] = min(vis[n/3], vis[n]+1);
        dp(n/3);
    }
    if(n%2==0) {
        vis[n/2] = min(vis[n/2], vis[n]+1);
        dp(n/2);
    }
    vis[n-1] = min(vis[n-1], vis[n]+1);
    dp(n-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> input_value;
    fill(vis,vis+1000001,1000001);
    vis[input_value] = 0;
    dp(input_value);
    
    cout << vis[1];
    
    return 0;
}