#include <bits/stdc++.h>

using namespace std;

// 빙산

// 조건
// 지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 
// 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 
// 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.
// 빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 
// 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다
// 한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오
// 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

// 입력 
// 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다.
// N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 
// 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

// 출력
// 첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

#define X first
#define Y second

int n, m, year;
int area[301][301];
int vis[301][301];
int zeroCount[301][301];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void melting(){
    // bfs 이용하여 특정 지점에서의 0의 갯수를 카운트한다.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(area[i][j]==0) continue;
            for(int dir=0;dir<4;dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(area[nx][ny] != 0) continue; 
                zeroCount[i][j]++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            area[i][j] = max(0, area[i][j] - zeroCount[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++) fill(zeroCount[i], zeroCount[i] + m, 0);
}

int separation(){
    queue<pair<int,int>> Q;
    int ice_count = 0;
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<m ;j++){
            if(vis[i][j] == 0 && area[i][j] > 0){
                ice_count++;
                vis[i][j] = 1;
                Q.push({i,j});
                
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] == 1 || area[nx][ny] == 0) continue;
                        
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);

    return ice_count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> area[i][j];
            
            
    // 얼음을 녹이는 변수와 덩어리를 계산하는 함수를 나눈다.
    while(1){
        year++;
        melting();
        int ice_count = separation();
        if(ice_count == 0) {
            cout << 0;
            return 0;
        }
        if(ice_count > 1) break;
    }
    
    cout << year;
    return 0;
}