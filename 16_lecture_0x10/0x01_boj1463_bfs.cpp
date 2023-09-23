#include <bits/stdc++.h>

using namespace std;

// 1로 만들기


// 조건
// 

// 입력 
// 

// 출력
// 

int input_value;
int vis[1000001]; // 특정 수까지 도달하는데 최소 수

void bfs(int n){
    queue<int> q;
    q.push(n);
    vis[n] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur < 1) break;
        
        if(cur%3 == 0 && vis[cur/3] == 0){
            // 3으로 나눠떨어지고, 아직 방문한적 없는 경우 
            // (이 사이클이 돌기전에 방문했으면 이미 작은 수에서 멀어짐.)
            q.push(cur/3);
            vis[cur/3] = vis[cur] + 1;
        }
        if(cur%2 == 0 && vis[cur/2] == 0){
            // 3으로 나눠떨어지고, 아직 방문한적 없는 경우
            q.push(cur/2);
            vis[cur/2] = vis[cur] + 1;
        }
        if(vis[cur-1] == 0){
            q.push(cur-1);
            vis[cur-1] = vis[cur] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> input_value;
    
    bfs(input_value);
    
    cout << vis[1];
    
    return 0;
}