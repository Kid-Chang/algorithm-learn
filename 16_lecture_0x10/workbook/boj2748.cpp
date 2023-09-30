#include <bits/stdc++.h>

using namespace std;

// 피보나치 수 2

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long long dp[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i=3;i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n];
    return 0;
}