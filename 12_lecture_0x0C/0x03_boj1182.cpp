#include <bits/stdc++.h>

using namespace std;

// 부분수열의 합

// 조건
// 

// 입력 
// 

// 출력
// 

int n, s;
int arr[30];
int cnt = 0;

void tracking(int cur, int total){
    if(cur == n){
        if(total == s) cnt++;
        return;
    }
    
    tracking(cur+1, total); // 현재 위치(cur idx)에 해당하는 값을 합하지 않을 때.
    tracking(cur+1, total + arr[cur]); // 현재 위치(cur idx)에 해당하는 값을 합할 때. 짜피 n번 까지만 동작하므로 추가적인 조건문은 필요없음.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i< n; i++)
        cin >> arr[i];
    
    tracking(0, 0);
    
    if(s==0) cnt--;
    cout << cnt;
    return 0;
}