#include <bits/stdc++.h>

using namespace std;

// 터렛 

// 조건
// 

// 입력 
// 

// 출력
// 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
   
    for(int i=0; i<n; i++){
        int x1,y1,r1,x2,y2,r2,dist,plus_sqrt,minus_sqrt,num;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        plus_sqrt = pow(r1+r2, 2);
        minus_sqrt = pow(r1-r2, 2);
        
        
        if(dist == 0) {
            // 동일 위치 동일 크기의 원
            if(r1-r2 == 0) cout << "-1\n";
            // 동일 위치 다른 크기의 원
            else cout << "0\n";
        }
        else if(dist == plus_sqrt || dist == minus_sqrt) cout << "1\n";
        else if(minus_sqrt < dist && plus_sqrt > dist) cout << "2\n";
        else cout << "0\n";
    }
    
    
    
   
    return 0;
}