#include <bits/stdc++.h>

using namespace std;

// 가장 긴 증가하는 부분 수열

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int arr[1002];
int dp[1002]; // i번째 위치일때 증가하는 부분수열의 길이


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1; i<=n;i++){
        cin >> arr[i];
    }
    fill(dp+1,dp+n+1, 1);
    
    for(int i=1; i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    cout << *max_element(dp+1, dp+n+1);
   
    return 0;
}