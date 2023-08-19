#include <bits/stdc++.h>

using namespace std;

// 토마토

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x_length, y_length;
    cin >> y_length >> x_length;
    
    int distance[x_length][y_length] = {};
    int board[x_length][y_length], inputValue;
    queue<pair<int,int>> Q;
    
    // 입력
    for(int i=0; i<x_length;i++){
        for(int j=0; j<y_length;j++){
            cin >> inputValue;
            if(inputValue == 1){
                // 만약 토마토가 익은 곳이라면 큐에 추가한다.
                Q.push({i,j});
                board[i][j] = 0;
            }
            if(inputValue == 0){
                board[i][j] = -1; // 아직 지나가지 않은 곳.
            }
            if(inputValue == -1){
                board[i][j] = -99; //지나갈 수 없는 곳.
            }
        }
    }
    
    //for(int i=0; i<x_length;i++){
    //    for(int j=0;j<y_length;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";
    
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) continue;
            if(board[nx][ny] != -1) continue;
            
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    //for(int i=0; i<x_length;i++){
    //    for(int j=0;j<y_length;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";
    
    // 지나간 거리에서 최대값(거리) 찾기
    int day=0;
    for(int i=0; i<x_length;i++){
        for(int j=0;j<y_length;j++){
            if(board[i][j] == -1){
                cout << -1;
                return 0;
            }
            
            day = max(day, board[i][j]);
        }
    }
    
    cout << day;

   
   return 0;
}