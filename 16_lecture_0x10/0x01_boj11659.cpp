#include <bits/stdc++.h>

using namespace std;

// 구간 합 구하기 4

// 조건
// 

// 입력 
// 

// 출력
// 

int n, m;
int D[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    // 입력된 값들에 대한 합을 D[i] = D[i-1] + input_value;
    for(int i=1;i<=n;i++){
        int input_value;
        cin >> input_value;
        D[i] =  D[i-1] + input_value;
    }
    
    // i~j까지의 합은 D[j]-D[i]
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << D[b]-D[a-1] << "\n";
    }
    

    return 0;
}