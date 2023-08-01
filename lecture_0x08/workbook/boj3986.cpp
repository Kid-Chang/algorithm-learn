#include <bits/stdc++.h>

using namespace std;

// 좋은 단어

// 조건
// 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다.
// 만약 선끼리 교차하지 않으면서 각 글자를 
// 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다.

// 입력 
// 첫째 줄에 단어의 수 N
// N개 줄에는 A와 B로만 이루어진 단어가 한 줄에 하나씩 주어진다. 

// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count, ans=0;
    cin >> count;
    while(count--){
        string word;
        cin >> word;
        stack<char> S;
        bool isValid = true;
        
        for(char c: word){
            if(!S.empty()){
                // 비어있지 않다면, 전값과 비교해서 지우거나 push
                if(S.top() == c){
                    S.pop();
                }
                else{
                    S.push(c);    
                }
            }
            else{
                S.push(c);
            }
        }
        
        if(S.empty()) ans++;
    }
    
    cout << ans;
   
   return 0;
}