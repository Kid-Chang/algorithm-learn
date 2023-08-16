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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int box_size;
string board[101];
int visited[101][101];
queue<pair<int, int>> Q;

void bfs(int i, int j){
    Q.push({i, j});
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx > box_size || ny < 0 || ny > box_size) continue;
            if(visited[nx][ny] == 1 || board[nx][ny]!=board[i][j]) continue;
            
            visited[nx][ny] = 1;
            Q.push({nx,ny});
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> box_size;
    
    for(int i=0;i<box_size;i++){
        cin >> board[i];
    }
    
    int count=0;

     // 정상일 때.
    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'R' && visited[i][j] == 0){         
                count++;
                bfs(i,j);
            }
        }
    }
    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'G' && visited[i][j] == 0){
                count++;
                bfs(i,j);            
            }
        }
    }
    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'B' && visited[i][j] == 0){
                count++;
                bfs(i,j);            
            }
        }
    }
    
    cout << count << " ";
    
    count = 0;
    
    for(int i=0;i<box_size;i++)
        fill(visited[i],visited[i]+box_size,0);
    
    // 색약일 때.
    // G -> R로 변환
    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'R' && visited[i][j] == 0){         
                count++;
                bfs(i,j);
            }
        }
    }
    for(int i=0;i < box_size;i++){
        for(int j=0;j < box_size;j++){
            if(board[i][j] == 'B' && visited[i][j] == 0){
                count++;
                bfs(i,j);            
            }
        }
    }
    
    cout << count;
    
   
    return 0;
}