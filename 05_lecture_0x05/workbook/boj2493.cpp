#include <bits/stdc++.h>

using namespace std;

// 탑

// 조건
// 모든 탑에서는 주어진 탑 순서의 반대 방향(왼쪽 방향)으로 동시에 레이저 신호를 발사.

// 입력 
// 

// 출력
// 

int n;
stack<pair<int,int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    s.push({0, 100000001});
    
    for(int i=1;i<=n;i++){
        
        int height;
        cin >> height;
        while(s.top().second < height){
            s.pop();
        }
        cout << s.top().first << ' ';
        s.push({i, height});
    }
    
    
    

    return 0;
}