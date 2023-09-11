#include <bits/stdc++.h>

using namespace std;

// 스티커 붙이기

// 조건
// 

// 입력 
// 

// 출력
// 

int board[41][41];
int sticker[11][11];
int sticker_row,sticker_col;
int N,M,K, attach, attached=0;

bool check_and_attach(int x, int y){
    // 모두 돌면서 보드와 스티커의 0과 1 구성 모양이 맞는지 확인
    for(int i=0; i< sticker_row; i++){
        for(int j=0; j< sticker_col; j++){
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
        }
    }
    
    // 모양이 맞다면 보드에 표시
    for(int i=0; i< sticker_row; i++){
        for(int j=0; j< sticker_col; j++){
            if(sticker[i][j] == 1 &&board[x+i][y+j] == 0) board[x+i][y+j] = 1;
        }
    }
    return true;
}

void rotate(){
    // 모양 복제하기
    int tmp[11][11];
    for(int i=0; i< sticker_row; i++){
        for(int j=0; j< sticker_col; j++){
            tmp[i][j] = sticker[i][j];
        }
    }
    
    // 뒤집기
    for(int i=0; i< sticker_col; i++){
        for(int j=0; j< sticker_row; j++){
            sticker[i][j] = tmp[sticker_row-1-j][i];
        }
        
    }
    // sticker_col, sticker_row 값 서로 바꾸기 
    swap(sticker_col, sticker_row);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    while(K--){
        // 스티커 입력 받기
        cin >> sticker_row >> sticker_col;
        
        for(int i=0;i<sticker_row;i++)
            for(int j=0;j<sticker_col;j++)
                cin >> sticker[i][j];
        
        attach = 0;
        // 4방향
        for(int dir=0;dir<4;dir++){
            // 스티커가 종이에 붙는지 확인하고 붙이기
            for(int i=0; i<=N-sticker_row; i++){
                for(int j=0; j<=M-sticker_col; j++){
                    if(attach==0 && check_and_attach(i,j)) {
                        attach=1;
                        break;
                    };
                }
            }
            if(attach) break;

            // 현재모양이 맞지않다면 일단 돌리기
            rotate();
        }

    }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            attached += board[i][j];
    
    cout << attached << '\n';
   
    return 0;
}