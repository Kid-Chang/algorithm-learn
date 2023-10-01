#include <bits/stdc++.h>

using namespace std;

// 가장 긴 증가하는 부분 수열 4

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int arr[1005];
int dp[1005];
int pos[1005]; // i번째 값보다 작은 값중 가장 큰 값
int reverse_filter_arr[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >>n;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];


    fill(dp+1,dp+n+1, 1);
    
    for(int i=1; i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j]+1;
                pos[i] = j;
            }
        }
    }
    
    int max_count = *max_element(dp+1,dp+n+1);
    cout << max_count << "\n";
    
    int max_value=0;
    int start_pos;
    for(int i=1;i<=n;i++){
        if(dp[i] > max_value){
            start_pos= i;
            max_value=dp[i];
        }
    }
    
    int i=1;
    while(start_pos){
        reverse_filter_arr[i++] = arr[start_pos];
        start_pos = pos[start_pos];
    }
    
    for(int j=i-1;j>=1;j--){
        cout << reverse_filter_arr[j]<< " ";
    }
    return 0;
}