#include <bits/stdc++.h>

using namespace std;

// 1로 만들기


// 조건
// 

// 입력 
// 

// 출력
// 

int input_value;
int vis[1000001]; // 특정 수까지 도달하는데 최소 수


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> input_value;
    vis[1] = 0;
    
    for(int n=2;n<=input_value;n++){
        vis[n] = vis[n-1]+1;
        if(n%3==0) {
            vis[n] = min(vis[n/3]+1, vis[n]);
        }
        if(n%2==0) {
            vis[n] = min(vis[n/2]+1, vis[n]);
        }
    }
    
    cout << vis[input_value];
    
    return 0;
}