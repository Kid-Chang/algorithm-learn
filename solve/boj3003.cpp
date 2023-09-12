#include <bits/stdc++.h>

using namespace std;

// 문제제목

// 조건
// 

// 입력 
// 

// 출력
// 

int piece[6] = {1,1,2,2,2,8};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<6;i++){
        int a;
        cin >> a;
        cout << piece[i] - a << " ";
    }


    return 0;
}