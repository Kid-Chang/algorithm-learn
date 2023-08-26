#include <bits/stdc++.h>

using namespace std;

// 별 찍기 - 11

// 조건


// 입력 
// 

// 출력
// 

int N;
char board[3500][7000];

void recursion(int start_x, int start_y, int n){
    if(n==3){
        board[start_x][start_y] = '*';
        board[start_x+1][start_y-1] = '*';
        board[start_x+1][start_y+1] = '*';
        for(int j=start_y-2; j <= start_y+2; j++){
            board[start_x+2][j] = '*';
        }
        return;
    }
    
    n = n/2;
    
    recursion(start_x, start_y, n);
    recursion(start_x+n, start_y - n, n);
    recursion(start_x+n, start_y + n, n);
    
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        fill(board[i], board[i]+2*N, ' ');
  
    
    recursion(0, N-1, N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

   
    return 0;
}