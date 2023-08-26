#include <bits/stdc++.h>

using namespace std;

// 쿼드트리

// 조건
// 주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 
// 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다.

// 입력 
// 

// 출력
// 

string board[65];
int N;

bool check(int start_x, int start_y, int n){
    for(int i=start_x; i<start_x+n; i++){
        for(int j=start_y; j<start_y+n; j++){
            if(board[start_x][start_y] != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void recursion(int start_x, int start_y, int n){
    if(check(start_x,start_y,n)){
        // 
        cout << board[start_x][start_y];
    }
    
    else{
        cout << "(";

        n = n/2;
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                recursion(i*n + start_x, j*n + start_y, n);   
            }
        }
        cout << ")";
    }

    

    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> board[i];
    }
    
    
    
    recursion(0, 0, N);

   
    return 0;
}