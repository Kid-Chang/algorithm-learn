#include <bits/stdc++.h>

using namespace std;

// 1, 2, 3 더하기 3

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long dp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    dp[1] =1;
    dp[2] =2;
    dp[3] =4;
    dp[4] =7;
    
    for(int i=5;i<=1000000;i++){
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % 1000000009;
    }
    
    while(n--){
        int val;
        cin >> val;
        cout << dp[val] % 1000000009 << "\n";
    }


    return 0;
}