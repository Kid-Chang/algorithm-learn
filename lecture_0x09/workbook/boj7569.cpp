#include <bits/stdc++.h>

using namespace std;

// 토마토 (3차원)

// 조건
// 

// 입력 
// 

// 출력
// 

#define X first
#define Y second

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x_length, y_length, z_length;
    cin >> x_length >> y_length >> z_length;
    
    int board[x_length][y_length][z_length], inputValue;
    queue<tuple<int,int,int>> Q;
    
    // 입력
      
    for(int k=0; k<z_length;k++){
        for(int j=0;j<y_length;j++){
            for(int i=0;i<x_length;i++){
            
                cin >> inputValue;
                if(inputValue == 1){
                    // 만약 토마토가 익은 곳이라면 큐에 추가한다.
                    Q.push({i,j,k});
                    board[i][j][k] = 0;
                }
                if(inputValue == 0){
                    board[i][j][k] = -1; // 아직 지나가지 않은 곳.
                }
                if(inputValue == -1){
                    board[i][j][k] = -99; //지나갈 수 없는 곳.
                }
            }
        }
    }

        
    
    
    while(!Q.empty()){
        tuple<int, int,int> cur = Q.front(); Q.pop();
        // cout << '(' << get<0>(cur) << ", " << get<1>(cur) << ", " << get<2>(cur) << ") -> ";
        
        for(int dir = 0; dir < 6; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];

            
            if(nx < 0 || nx >= x_length || ny < 0 || ny >= y_length || nz < 0 || nz >= z_length) continue;
            if(board[nx][ny][nz] != -1) continue;
            
            board[nx][ny][nz] = board[ get<0>(cur)][get<1>(cur)][ get<2>(cur)] + 1;
            Q.push({nx,ny,nz});
        }
    }
    
    // 지나간 거리에서 최대값(거리) 찾기
    int day=0;
      
    for(int k=0; k<z_length;k++){
        for(int j=0;j<y_length;j++){
            for(int i=0;i<x_length;i++){
                if(board[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                
                day = max(day, board[i][j][k]);
            }
        }
    }
    
    cout << day;

   
   return 0;
}