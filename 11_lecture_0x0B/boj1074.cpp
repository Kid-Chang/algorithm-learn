#include <bits/stdc++.h>

using namespace std;

// Z

// 조건
// 

// 입력 
// 

// 출력
// 


int recursion(int N, int r, int c){
    if(N == 0) return 0;
    
    int half = 1<<(N-1); // 2^(n-1)
    if(r < half && c < half) return recursion(N-1, r, c);
    if(r < half && c >= half) return half * half + recursion(N-1, r, c-half);
    if(r >= half && c < half) return 2 * half * half + recursion(N-1, r-half, c);
    else return 3 * half * half + recursion(N-1, r-half, c-half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, r, c;
    cin >> N >> r >> c;
    cout << recursion(N, r, c);
    
    
    return 0;
}