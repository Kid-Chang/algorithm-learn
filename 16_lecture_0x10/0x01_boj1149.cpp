#include <bits/stdc++.h>

using namespace std;

// RGB거리

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int house[1002][3]; // 빨강, 초록, 파랑
int min_cost[1002][3]; // i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 0->빨, 1->초, 2->파

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    
    min_cost[1][0] = house[1][0];
    min_cost[1][1] = house[1][1];
    min_cost[1][2] = house[1][2];
    
    for(int i=2;i<=n;i++){
        min_cost[i][0] = min(min_cost[i-1][1], min_cost[i-1][2]) + house[i][0];
        min_cost[i][1] = min(min_cost[i-1][0], min_cost[i-1][2]) + house[i][1];
        min_cost[i][2] = min(min_cost[i-1][0], min_cost[i-1][1]) + house[i][2];
    }
    
    cout << min({min_cost[n][0], min_cost[n][1], min_cost[n][2]});
    
   
    return 0;
}