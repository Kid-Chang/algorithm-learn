#include <bits/stdc++.h>

using namespace std;

// 미로 탐색

// 조건
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
// 

// 입력 
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
// 각각의 수들은 붙어서 입력으로 주어진다.

// 출력
// 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x_length, y_length;
    cin >> x_length >> y_length;
    
    string board[x_length];
    int distance[x_length][y_length];
    for(int i = 0; i<x_length; i++) {
        cin >> board[i];
        fill(distance[i],distance[i]+y_length,-1);
    }
    
    queue<pair<int,int>> Q;
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
    distance[0][0] = 1;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        //cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        
        for(int dir =0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) continue;
            if(distance[nx][ny]>=0 || board[nx][ny]!='1') continue;

            distance[nx][ny] = distance[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
        
    }
    
    cout << distance[x_length-1][y_length-1];

   return 0;
}