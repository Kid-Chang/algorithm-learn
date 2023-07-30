#include <bits/stdc++.h>

using namespace std;

// 제로

// 조건
// 0 부르면 삭제

// 입력 
// 첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
// 이후 K개의 줄에 정수가 1개씩 주어진다

// 출력
// 적어 낸 수의 합을 출력


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    int count, inputValue;
    cin >> count;

    for(int i;i<count;i++){
        cin >> inputValue;
        
        if(inputValue == 0){
            if(S.size()!=0)
                S.pop();
        }else
            S.push(inputValue);
    }
    
    int total=0;
    while(!S.empty()){
        total += S.top();
        S.pop();
  }
    cout << total;
   return 0;
}