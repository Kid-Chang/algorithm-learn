#include <bits/stdc++.h>

using namespace std;

// 연속합

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long arr[100002], dp[100002];

// 테이블 정의하기
// dp 테이블에 i번 이전에 연속된 값들의 합+i번째 값과 i번째 값을 비교했을때의 큰 값을 저장한다.
// 이렇게 해도 되는 이유
// i번째 값과, 본인 이전의 값들의 합+i번째 값을 비교해서 dp테이블에 저장하면 몇개의 수를 연속선택하여 합한 값이든, 
// i번째 값보다 작으면 거기서 끝나는 것이고, 그렇다면 i-1이든 i-2이든 어디선가 i번째 단일 값보다 크든 작든 앞선 값들의 합중에선
// 가장 큰 값이 저장되어있기때문이다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        int input_value;
        cin >> input_value;
        arr[i] = dp[i] = input_value;
    }
    
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
    }
    
    cout << *max_element(dp+1,dp+n+1);
    
    

    return 0;
}