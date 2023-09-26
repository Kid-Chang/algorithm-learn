#include <bits/stdc++.h>

using namespace std;

// 피보나치 함수

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int fibo[41][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
 
    for(int i=2; i<=40;i++){
        fibo[i][0] = fibo[i-1][0]+fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1]+fibo[i-2][1];
    }
    
    cin >> n;
    while(n--){
        int input_value;
        cin >> input_value;
        cout << fibo[input_value][0] << " " << fibo[input_value][1] << "\n";
        
    }

   
    return 0;
}