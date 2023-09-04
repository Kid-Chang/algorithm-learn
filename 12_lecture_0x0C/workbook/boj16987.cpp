#include <bits/stdc++.h>

using namespace std;

// 계란으로 계란치기

// 조건
// 

// 입력 
// 

// 출력
// 

int durability[10];
int weight[10];
int n;
int max_break;
int cnt = 0;

void tracking(int distance_from_left){
    if(distance_from_left == n){
        max_break = max(max_break, cnt);
        return;
    }
    
    if(durability[distance_from_left] <=0 || cnt == n-1){
        // distance_from_left 위치의 계란이 깨졌거나, 본인외에 깰 계란이 없는 경우
        tracking(distance_from_left+1);
        return;
    }
    
    for(int i=0; i<n; i++){
        // i 가 칠 계란 위치 (i+1)번째 ㅇㅇ
        if(durability[i] <= 0 || distance_from_left == i) continue;

        durability[i] -= weight[distance_from_left];
        durability[distance_from_left] -= weight[i];
        
        if(durability[i] <= 0) cnt++;
        if(durability[distance_from_left] <= 0) cnt++;
        
        tracking(distance_from_left+1);
        
        if(durability[i] <= 0) cnt--;
        if(durability[distance_from_left] <= 0) cnt--;
        
        durability[i] += weight[distance_from_left];
        durability[distance_from_left] += weight[i];
        

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> durability[i] >> weight[i];
    }
    
    
    tracking(0);
      cout << max_break;  

    return 0;
}