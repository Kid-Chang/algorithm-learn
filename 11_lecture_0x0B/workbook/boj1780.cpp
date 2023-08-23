#include <bits/stdc++.h>

using namespace std;

// 종이의 개수

// 조건
// 

// 입력 
// 

// 출력
// 

int board[2200][2200];
int num_count[3];

bool match(int start_x, int start_y, int N){
    for(int i=start_x; i < start_x+N; i++)
        for(int j=start_y; j < start_y+N; j++)
            if(board[i][j] != board[start_x][start_y]) return false;

    return true;
}

void recursion(int start_x, int start_y, int N){
    //cout << "recursion\n";
    
    if(match(start_x,start_y, N)){
        num_count[board[start_x][start_y] + 1] ++;
        return;
    }
        
        
    int n = N/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            recursion(i*n + start_x, j*n + start_y, n);   
        }
    }
    
    
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i=0; i < N; i++){
        for(int j=0;j < N; j++){
            cin >> board[i][j];
        }
    }
        

    recursion(0, 0, N);
    
    cout << num_count[0] << "\n" << num_count[1] << "\n" << num_count[2];
       
    return 0;
}