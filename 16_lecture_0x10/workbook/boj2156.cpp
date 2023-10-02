#include <bits/stdc++.h>

using namespace std;

// 포도주 시식

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int drink[10005][3]; // 현재까지 j개의 포도주를 연속해서 먹고 i번째 포도주를 마셨을때 올라섰을 때 점수 합의 최댓값,
// 단, i번째 포도주는 반드시 먹어야함.
// 계단 문제와 다른 점은 반드시 마지막에 도달할 필요가 없다는 점.
int arr[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    
    drink[1][1] = arr[1];
        
    for(int i=2;i<=n;i++){
        drink[i][0] = max({drink[i-1][0], drink[i-1][1], drink[i-1][2]});
        drink[i][1] = drink[i-1][0] + arr[i];
        drink[i][2] = drink[i-1][1] + arr[i];

    }
    
    cout << max({drink[n][0], drink[n][1], drink[n][2]});
   
    return 0;
}