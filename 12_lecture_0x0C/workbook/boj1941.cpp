#include <bits/stdc++.h>

using namespace std;

// 소문난 칠공주

// 조건
// 

// 입력 
// 

// 출력
// 

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[5];
bool vis[5][5];
bool combination[25]; // 조합 진행할 거.
bool selected_position[5][5];
int people_count, som;
int case_count =0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<5;i++)
        cin >> board[i];
        
    
    // fill 을 이용해서 7개의 항목에만 true 설정
    fill(combination,combination+7,true);
    

    // 25개 중 특정 7개의 좌표를 선택하는 기능을 permutation으로 구현
    do{
        // bfs를 위한 queue 생성.
        queue<pair<int,int>> q;
        // 선택된 좌표 false로 초기화
        for(int i=0;i<5;i++){
            fill(selected_position[i], selected_position[i]+5, false);
            fill(vis[i], vis[i]+5, false);
        }
            
        
        // 25개 중 선택된 7개의 좌표를 x y로 전환한 후
        for(int i=0; i<25; i++){
            if(combination[i]){
                int x=i/5, y=i%5;
                selected_position[x][y] = true;
                
                // bfs 시작전이라면 queue에 쌓기
                if(q.empty()){
                    q.push({x,y});
                    vis[x][y] = true;
                }
            }
          
        }
        // bfs를 이용해서 해당 값들이 연결되어 있는지 확인
        people_count=0;
        som = 0;
        
        while(!q.empty()){
            int x,y;
            tie(x, y) = q.front(); q.pop();
            
            people_count++;
            if(board[x][y] == 'S') som++;

            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !selected_position[nx][ny]) continue;
                
                q.push({nx,ny});
                vis[nx][ny] = true;
                
            }
            
        }
        // 확인 후 이다솜파가 4명이상인지 확인.
        if(people_count ==7 && som >=4) case_count++;
        
    } while(prev_permutation(combination,combination+25));
    
    cout << case_count;
    
    
    return 0;
}
