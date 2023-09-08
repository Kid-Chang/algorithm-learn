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
char answer_board[10][10];
int min_value=999, total_camera=0;
queue<tuple<int,int,int>> q;

int number_of_cases(int camera_type){
    if(camera_type == 1) return 4;
    if(camera_type == 2) return 2;
    if(camera_type == 3) return 4;
    if(camera_type == 4) return 4;
    // type = 5
    return 1;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void fill_board(int x, int y, int dir){
    dir %= 4; //가능한 감시방향 right, up, left, down (0 ~ 3)

    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx > N || ny > M)return;
        if (board[nx][ny] == '6') return;
        if (board[nx][ny] != '0') continue;
        board[nx][ny] = '#';
    }
};

void empty_board(int x, int y, int dir){
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)return;
        if (board[nx][ny] == '6') return;
        if (board[nx][ny] != '#') continue;
        board[nx][ny] = '0';
    }
};

void print_board(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
}

void tracking(int camera_count){
    if(camera_count  == total_camera){
        // print_board();
        int this_min=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == '0') this_min++;
            }
        }
        if(min_value > this_min){
            min_value = this_min;
            //copy(&board[0][0], &board[0][0] + M * N, &answer_board[0][0]);
            memcpy(answer_board, board, sizeof(board));
        }
        
        
        
        // 비교 후 더 작은 값이면 min에 저장
    //    cout << "마지막 카메라에 도달\n";
        return;
    }
    
    int backup[8][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            backup[i][j] = board[i][j];
        }
    }
    
    int x,y,type;
    x= get<0>(q.front());
    y= get<1>(q.front());
    type= get<2>(q.front());
       // cout << x <<" " << y <<" " << type << "\n";


    // tie(x,y,type) =  q.front();
    int number_of_case = number_of_cases(type);

    q.pop();
    // 각 위치별로 돌아가도록.
    for(int dir=0; dir < number_of_case; dir++){
        //cout << x <<" " << y <<" " << type <<" " << dir << "\n";
        // 채우기
        if(type == 1){
            fill_board(x,y,dir);
        }
        else if(type ==2){
            fill_board(x,y,dir);
            fill_board(x,y,dir+2);
        }
        else if(type ==3){
            fill_board(x,y,dir);
            fill_board(x,y,dir+1);
        }
        else if(type ==4){
            fill_board(x,y,dir);
            fill_board(x,y,dir+1);
            fill_board(x,y,dir+2);
        }
        else if(type ==5){
            fill_board(x,y,dir);
            fill_board(x,y,dir+1);
            fill_board(x,y,dir+2);
            fill_board(x,y,dir+3);
        }

        
        //print_board();
        // cout << "\n";

        // 재귀
        tracking(camera_count+1);
        
        // 빼기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = backup[i][j];
            }
        }
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