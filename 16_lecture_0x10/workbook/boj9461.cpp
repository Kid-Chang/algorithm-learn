#include <bits/stdc++.h>

using namespace std;

// 파도반 수열

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long dp[102]; // 파도반 수열


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    
    dp[1] = dp[2] = dp[3] = 1;
    
    for(int i=4;i<=100;i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    
    while(n--){
        int input_value;
        cin >> input_value;
        cout << dp[input_value]<<"\n";
        
    }
   
    return 0;
}