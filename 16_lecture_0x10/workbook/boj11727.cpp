#include <bits/stdc++.h>

using namespace std;

// 2×n 타일링 2

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int D[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    D[1]=1;
    D[2]=3;

    for(int i=3; i<=n;i++){
        D[i] = (D[i-1] + D[i-2]*2) % 10007;
    }
    // 주의사항
    // 코드에서 별다른건 없는데 이런 문제에서 간혹 가다가 d[i] = d[i-1] + d[i-2]라고만 써놓고 제일 마지막에 d[i] % mod 를 출력하는 식으로 짜는 분이 있습니다. 그렇게 되면 계산 중간에 int overflow가 생겨서 틀리게 되니 
    // 지금 이 코드처럼 계산 중간 중간에 계속 10007로 나눈 나머지만을 가져가도록 해야합니다.
    
    cout << D[n];
    

    return 0;
}