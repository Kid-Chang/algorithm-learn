#include <bits/stdc++.h>

using namespace std;

// 가장 큰 증가하는 부분 수열

// 조건
// 

// 입력 
// 

// 출력
// 
int arr[1002];
int dp[1002];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1; i<=n;i++){
        int input_value;
        cin >> input_value;
        arr[i]=dp[i] = input_value;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                //dp[i]+=arr[j];
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }
    
    
    cout << *max_element(dp+1, dp+n+1);
    return 0;
}