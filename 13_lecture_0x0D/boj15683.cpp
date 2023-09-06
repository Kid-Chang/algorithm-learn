#include <bits/stdc++.h>

using namespace std;

// 감시

// 조건
// 

// 입력 
// 

// 출력
// 

int N, M;
char board[10][10];
int min_value, total_camera;
queue<tuple<int,int,int>> q;

int number_of_cases(int camera_type){
    if(camera_type == 1) return 4;
    if(camera_type == 2) return 2;
    if(camera_type == 3) return 4;
    if(camera_type == 4) return 4;
    return 1;
}

int fill_board(int x, int y, int type, int dir){
    if(type == 1){
            cout << x <<y << type << dir << "working\n";

        // 12시부터 시계 방향
        if(dir == 0)
            for(int i=x; i >= 0; i--) if(board[i][y]=='0') board[i][y] = '#';
        if(dir == 1)
            for(int i=y; i >= 0; i--) if(board[x][i]=='0') board[x][i] = '#';
        if(dir == 2)
            for(int i=x; i <=N-x; i++) if(board[i][y]=='0') board[i][y] = '#';
        if(dir == 3)
            for(int i=x; i <=M-y; i++) if(board[x][i]=='0') board[x][i] = '#';
    }
};

void print_board(){
    // 남은 공간 확인
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
}

void tracking(int camera_count){
    if(camera_count == total_camera){

        print_board();
        
        
        // 비교 후 더 작은 값이면 min에 저장
    //    cout << "마지막 카메라에 도달\n";
        return;
    }
    
    int x,y,type;
    x= get<0>(q.front());
    y= get<1>(q.front());
    type= get<2>(q.front());
        cout << x <<" " << y <<" " << type << "\n";


    // tie(x,y,type) =  q.front();
    int number_of_case = number_of_cases(type);

    q.pop();
    // 각 위치별로 돌아가도록.
    for(int dir=0; dir < number_of_case; dir++){
        //cout << x <<" " << y <<" " << type <<" " << dir << "\n";

        // 채우기
        fill_board(x,y,type,dir);
        
        print_board();

        // 재귀
        //tracking(camera_count+1);
        // 빼기
        //empty(type,dir);
    
    }
    
    q.push({x,y,type});
    
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j=0; j < M; j++){
            char inputValue;
            cin >> inputValue;
            board[i][j] = inputValue;
            if(inputValue != '6' && inputValue != '0'){
                total_camera++;

                inputValue =  inputValue - '0';

                q.push({i,j,inputValue});
            }
        }
    }
    
    
    // 백트래킹으로 모든 경우의 수 탐색?
    tracking(0);
    
    cout << min_value;
    
    return 0;
}