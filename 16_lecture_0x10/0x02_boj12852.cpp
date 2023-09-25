#include <bits/stdc++.h>

using namespace std;

// 1로 만들기 2

// 조건
// 

// 입력 
// 

// 출력
// 

int input_value;
int vis[1000005]; // 특정 수까지 도달하는데 최소 수
int optimum_root[1000005]; // 특정 수 idx일때 3가지 경우의 수 중 최적의 값으로 이동한 데이터. 
// ex) root_vis[4] = 2, 4이면 -> 2로 값이 변경되는게 최적 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> input_value;
    
    vis[1] = 0;
    optimum_root[1] = 0;
    
    for(int i=2;i<=input_value;i++){
        vis[i] = vis[i-1] + 1; // 1을 빼는 경우의 수
        optimum_root[i] = i-1;
        if(i%2==0) {
            if(vis[i] > vis[i/2]+1){
                vis[i] = vis[i/2]+1;
                optimum_root[i] = i / 2;
            }
           
        }
        if(i%3==0) {
            if(vis[i] > vis[i/3]+1){
                vis[i] = vis[i/3]+1;
                optimum_root[i] = i / 3;
            }
        };
    }
    
    cout << vis[input_value] << "\n";
    
    int cur = input_value;
    while(1){
        cout << cur << " ";
        if(cur == 1) break;
        cur = optimum_root[cur];
    }


    
    return 0;
}