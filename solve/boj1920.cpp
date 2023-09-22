
#include <bits/stdc++.h>

using namespace std;

// 수 찾기

// 조건
// 

// 입력 
// 

// 출력
// 

int n, m;
int N[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        int input_value;
        cin >> input_value;
        N[i] = input_value;
    }
    
    sort(N, N+n);
    
    cin >> m;
    
    for(int i=0;i<m;i++){
        int input_value;
        cin >> input_value;
        cout << binary_search(N, N+n, input_value) << "\n";
    }
    
   
    return 0;
}





