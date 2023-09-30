#include <bits/stdc++.h>

using namespace std;

// 쉬운 계단 수

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long long dp[105][10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    fill(dp[1]+1, dp[1]+10, 1);
    
    for(int i=2; i<=n;i++){
        // 길이가 i인 계단수는 길이가 i-1 인 계단수에 첫자리수와 한글자 차이나는 것들에 대해 더하면 된다.
        for(int j=0;j<=9;j++){
            if(j!=0)
                dp[i][j] += dp[i-1][j-1];
            if(j!=9)
                dp[i][j] += dp[i-1][j+1];
            
            dp[i][j] %= 1000000000;
        }
    }
    
    long long ans=0;
    for(int i=0;i<=9;i++){
        ans+=dp[n][i];
        ans%= 1000000000;
    }
    cout << ans;
    return 0;
}