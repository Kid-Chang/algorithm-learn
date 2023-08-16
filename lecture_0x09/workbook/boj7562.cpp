#include <bits/stdc++.h>

using namespace std;

// 적록색약 

// 조건
// 

// 입력 
// 

// 출력
// 

#define X first
#define Y second

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int box_size;
int board[301][301];
int visited[301][301];
queue<pair<int, int>> Q;

void bfs(int i, int j){
    visited[i][j] = 0;
    Q.push({i, j});
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0;dir<8;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx > box_size || ny < 0 || ny > box_size) continue;
            if(visited[nx][ny] >= 0) continue;
            
            visited[nx][ny] = visited[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count, night_x, night_y, arrived_x, arrived_y;
    cin >> count;
    
    while(count--){
        cin >> box_size >> night_x >> night_y >> arrived_x >> arrived_y;

        for (int i = 0; i < box_size; i++) fill(visited[i], visited[i] + box_size, -1);
        bfs(night_x,night_y);
        
        cout << visited[arrived_x][arrived_y] << "\n";

    }
   
    return 0;
}