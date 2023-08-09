#include <bits/stdc++.h>

using namespace std;

// 그림

// 조건
// 어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 
// 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 
// 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
// 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 
// 그림의 넓이란 그림에 포함된 1의 개수이다.

// 입력 
// 첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다.
// 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
// (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)


// 출력
// 첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장. 칸 위에 올리던 동그라미를 코드 상에서는 vis 값을 1로 변경함으로써 처리

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int max_x, max_y;
    cin >> max_x >> max_y;
    
    int img_size=0;
    
    int board[max_x][max_y];
    
    for(int x=0; x < max_x; x++){
        for(int y = 0; y< max_y;y++){
            cin >> board[x][y];
        }
    }
    
    
    
           
   int img_count=0;
   
    for(int x=0; x < max_x; x++){
        for(int y = 0; y < max_y;y++){
           
            if(board[x][y]==0 || vis[x][y]==1) continue;
           
            vis[x][y] = 1; // (x, y)를 방문했다고 명시

            queue<pair<int,int>> Q;
            int tmp_picture_size=0;
            img_count++;
           
            Q.push({x,y}); // 큐에 시작점인 (0, 0)을 삽입.
           

            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop(); 
                tmp_picture_size++;
               // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        
                // x가 행을, y가 열을 의미합니다.
                // 여기부터 
                for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
                  int nx = cur.X + dx[dir];
                  int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                  if(nx < 0 || nx >= max_x || ny < 0 || ny >= max_y) continue; // 범위 밖일 경우 넘어감
                  if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                  vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                  Q.push({nx,ny});
                }
            // 여기까지가 핵심
            }
           
        if (img_size < tmp_picture_size) img_size = tmp_picture_size;

        }
    }
    
    
    cout << img_count << "\n" << img_size; 

   
   return 0;
}