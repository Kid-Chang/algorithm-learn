#include <bits/stdc++.h>

using namespace std;

// 1, 2, 3 더하기

// 조건
// 

// 입력 
// 

// 출력
// 
// D[5] = D[4] + D[3] + D[2]
// 1+1+1+1+1, 3+1+1, 2+1+1, 1+2+1,
// 1+1+1+2, 1+2+1, 3+1
// 1+1+3, 2+3


int case_number, num;
int arr[12]; // 각 자리를 표현할 수 있는 방법의 수
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> case_number;
    arr[1]=1,arr[2]=2,arr[3]=4;
    while(case_number--){
        cin >> num;
        for(int i=4; i<=num;i++){
            if(arr[i]==0)
                arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
        }
        
        cout << arr[num] << "\n";
    }
   
    return 0;
}