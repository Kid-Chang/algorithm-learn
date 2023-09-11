#include <bits/stdc++.h>

using namespace std;

// 영역 구하기

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

int M, N, K;
int board[101][101];
int pos=0;
int vis[101][101];
int box_count=0;
queue<pair<int,int>> q;
int space;


void bfs(int x, int y){
    q.push({x,y});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int dir=0; dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
            
            vis[nx][ny]=1;
            space++;
            q.push({nx,ny});
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> M >> N >> K;
    vector<int> ans;
    
    for(int cnt=0;cnt<K;cnt++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=y1; i < y2; i++){
            for(int j=x1; j < x2; j++){
                board[i][j] = 1;
            }
        }
    }
    
    // bfs로 영역 구하기
    for(int i=0; i < M; i++){
        for(int j=0; j < N; j++){
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            space=1;
            vis[i][j] = 1;
            box_count++;
            bfs(i,j);
            ans.push_back(space);
            
        }
    }
    
    
    sort(ans.begin(), ans.end());
    
    
    cout << box_count << "\n";
    for(int i : ans) cout << i << " ";
   
    return 0;
}