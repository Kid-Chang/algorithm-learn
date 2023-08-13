#include <bits/stdc++.h>

using namespace std;

// 불!

// 조건
// 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
// 불은 각 지점에서 네 방향으로 확산된다.
// 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
// 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

// 입력
// 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
// #: 벽
// .: 지나갈 수 있는 공간
// J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
// F: 불이 난 공간

// 출력
// 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
// 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q_fire;
    queue<pair<int,int>> Q_jihon;
   
    int x_length, y_length;
    cin >> x_length >> y_length;
    
    int distance_fire[x_length][y_length];
    int distance_jihon[x_length][y_length];
    
    string board[x_length];
   
    for(int i=0; i<x_length; i++){
        cin >> board[i];
        for(int j = 0; j<y_length;j++){
            if(board[i][j] == 'F') {
                distance_fire[i][j] = 0;    
                distance_jihon[i][j] = -99;                  
                Q_fire.push({i,j});
            }
           
            else if(board[i][j] == 'J') {
                distance_jihon[i][j] = 0;  
                Q_jihon.push({i,j});
            }
            else if(board[i][j] == '#') {
                distance_jihon[i][j] = -99;
                distance_fire[i][j] = -99;
            }
            else{ // 지나갈 수 있는 곳
                distance_jihon[i][j] = -1;
                distance_fire[i][j] = -1;
            }
        }
    }


    // 우선 불의 전파를 구하자.
    while(!Q_fire.empty()){
        auto cur = Q_fire.front(); Q_fire.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) continue;
            if(distance_fire[nx][ny] !=-1) continue;
            
            distance_fire[nx][ny] = distance_fire[cur.X][cur.Y] + 1;
            Q_fire.push({nx,ny});
        }
    }
   
    // 지훈이의 전파를 구하자.
    while(!Q_jihon.empty()){
        auto cur = Q_jihon.front(); Q_jihon.pop();
        // cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= x_length || ny < 0 || ny >= y_length) {
                cout <<  distance_jihon[cur.X][cur.Y] + 1;
                return 0;
            }
                
            if(distance_jihon[nx][ny] !=-1) continue;
            if(distance_fire[nx][ny] != -1 && distance_fire[nx][ny] <=  distance_jihon[cur.X][cur.Y] + 1) continue;
            
            distance_jihon[nx][ny] = distance_jihon[cur.X][cur.Y] + 1;
            Q_jihon.push({nx,ny});
        }
    }   
    cout << "IMPOSSIBLE";
   
   
    
    //cout << "\n";
    //for(int i=0;i<x_length;i++){
    //    for(int j=0;j<y_length;j++){
    //        cout << distance_fire[i][j]<< " ";
    //    }
    //    cout << "\n";
    //}
    //    cout << "\n";
    //for(int i=0;i<x_length;i++){
    //    for(int j=0;j<y_length;j++){
    //        cout << distance_jihon[i][j]<< " ";
    //    }
    //   cout << "\n";
    //}
    
    
    
   return 0;
}