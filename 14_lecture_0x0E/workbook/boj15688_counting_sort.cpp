#include <bits/stdc++.h>

using namespace std;

// 수 정렬하기 5

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int freq[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int input_value;
        cin >> input_value;
        
        freq[1000000+input_value]++; 
    }
    
    for(int i=0;i<2000001;i++){
        while(freq[i]--) cout << i - 1000000 << "\n";
    }

    return 0;
}