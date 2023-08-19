#include <bits/stdc++.h>

using namespace std;

// 유기농 배추

// 조건
// 

// 입력 
// 

// 출력
// 

// define 할때 ; 붙이면 안된다...! 이거때매 시간 날려먹음...ㅠ

#define Y first
#define X second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[51][51];
bool visited[51][51];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 사이클이 몇번 돌았는지를 확인하는게 핵심?
    int case_count;
    cin >> case_count;
    
    
    while(case_count--){
        queue<pair<int,int>> Q;
        int m, n, k, bug_count=0;
        cin >> m >> n >> k;

        int x,y;
        for(int i=0;i<k;i++){
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                
                if(!visited[y][x] && board[y][x]==1){
                    bug_count++;
                    
                    //bfs 작동해서 해당위치에서 이어지는 좌표들을 모두 true로 변경
                    visited[y][x] = true;
                    Q.push({y,x});
                    
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            
                            if(nx < 0 || nx > m || ny < 0 || ny > n) continue;
                            if(visited[ny][nx] || board[ny][nx] != 1) continue;
                            
                            visited[ny][nx] = true;
                            Q.push({ny,nx});
                        }
                    }
                   
                }
            }
        }
        cout << bug_count << "\n";
        for(int i = 0; i < n; i++){
            fill(board[i], board[i]+m, 0);
            fill(visited[i], visited[i]+m, false);
        }
    }
    
    return 0;
}