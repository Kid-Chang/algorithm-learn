#include <bits/stdc++.h>

using namespace std;

// 별 찍기 - 10

// 조건
// N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
// N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.


// 입력 
// 

// 출력
// 

int N;
char board[2200][2200];

void recursion(int start_x, int start_y, int n){
    
    if(n==1){
        board[start_x][start_y] = '*';
        return;
    }
    n = n/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1&&j==1) continue;
            recursion(i*n + start_x, j*n + start_y, n);   
        }
    }
    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        fill(board[i], board[i]+N, ' ');
  
    
    recursion(0, 0, N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

   
    return 0;
}