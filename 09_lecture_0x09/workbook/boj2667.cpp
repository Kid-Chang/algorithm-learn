#include <bits/stdc++.h>

using namespace std;

// 단지번호붙이기

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
int n;
string board[30];
bool vis[30][30];
queue<pair<int,int>> q;
vector<int> apt;
int apt_num=0;

void bfs(int i, int j){
    apt_num++;
    int count=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx<0 || nx >= n || ny<0 || ny >= n) continue;
            if(vis[nx][ny]==1 || board[nx][ny] == '0') continue;
            
            vis[nx][ny]=1;
            count++;
            q.push({nx,ny});
        }
    }
    apt.push_back(count);
}

int compare(int i, int j){
    return i > j;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++) cin >> board[i];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // 방문한 적 없는 1 일때
            if(board[i][j]== '1' && vis[i][j] == false){
                vis[i][j] = true;
                q.push({i,j});
                bfs(i,j);
            }
        }
    }
    cout << apt_num << "\n";
    sort(apt.begin(), apt.end(), compare);
    while(!apt.empty()){
        cout << apt.back() << "\n";
        apt.pop_back();
    }
   
    return 0;
}