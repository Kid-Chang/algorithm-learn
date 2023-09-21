#include <bits/stdc++.h>

using namespace std;

// 먹을 것인가 먹힐 것인가

// 조건
// 두 생명체 A와 B의 크기가 주어졌을 때, A의 크기가 B보다 큰 쌍이 몇 개나 있는지 구하는 프로그램을 작성하시오.


// 입력 
// 

// 출력
// 

int t, n, m;
int a[20001], b[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<m;i++)
            cin >> b[i];
        
        sort(a,a+n);
        sort(b,b+m);
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i] < b[j]) break;
                if(a[i] > b[j]) cnt ++;
            }
        }
        cout << cnt << "\n";
    }

   
    return 0;
}