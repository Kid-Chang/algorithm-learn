#include <bits/stdc++.h>

using namespace std;

// 퇴사

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int T[16], P[16];
int dp[17]; // i번째 날까지 가장 많이 번 돈.


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++)
        cin >> T[i] >> P[i];
    
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i], dp[i-1]); 
        // i번째 날까지 계산된 돈 보다 i-1번째 날까지 계산된 돈이 많으면 i-1번째 날까지 일한 게 더 효율적이니까.

        if(i+T[i]-1 <= n)
            dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
            // 만약 dp[i+T[i]-1] 로 계산하면, 
            // 3 10, 5 20, 1 10 값이 들어갈때, 3일차 경우에 보면 3 10 으로 인해 넘어가져야할 값이 계산되는 오류가 발생한다.
            // 즉 3일치 일한 부분의 정산이 일한날 마지막에 들어가면, 마지막날 하루 일할 때 계산되는 값과 중복으로 들어가진다. 
            
    }
    
    cout << max(dp[n],dp[n+1]); // 마지막날에 하루치 일을 하면 n+1날에 정산이 되므로.
        
    return 0;
}