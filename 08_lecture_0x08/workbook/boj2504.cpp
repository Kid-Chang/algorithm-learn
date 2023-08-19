#include <bits/stdc++.h>

using namespace std;

// 괄호의 값

// 조건
// 

// 입력 
// 

// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string inputValue;
    cin >> inputValue;
    stack<char> s;
    
    int tmp=1, ans=0;
    for(int i = 0 ; i < inputValue.length(); i++){
        if(inputValue[i]=='('){
            s.push(inputValue[i]);
            tmp *=2;
        }
        else if(inputValue[i]=='['){
            s.push(inputValue[i]);
            tmp *=3;
        }
        
        else{
            // 괄호 입력값이 올바르지 못한 경우.
            if(inputValue[i] == ')'){
                if(s.empty() || s.top() != '(') {
                    ans = 0;
                    break;
                }
            }
            else if( inputValue[i] == ']'){
                if(s.empty() || s.top() != '[') {
                    ans = 0;
                    break;
                }
            }
        
        
            // 바로 닫혔을 때
            if(inputValue[i]==')'){
                if(inputValue[i-1]=='(') 
                    ans += tmp;
                tmp/=2;
                s.pop();
            }
            else if(inputValue[i]==']'){
                if(inputValue[i-1]=='[') 
                    ans += tmp;
                tmp/=3;
                s.pop();
            }
        }

    }
    
    if(s.empty()) cout << ans;
    else cout << 0;    

   
   return 0;
}

// (()[[]])=22     ([])
// () = 2
// (()) = 4
// (a) = 2*a
// []=3
// [[]]=9
// [a]= 3*a
// ([]) = 6
// (ㅁ)=2 ㅁ-> [] = 1*3


// (()[[]])
// ( -> 1*2=2
// (( -> 2*2=4
// (() -> ans + 4 =4 , tmp = 4/2
// (()[ -> tmp = 2 * 3
// (()[[ -> tmp = 6 * 3
// (()[[] -> ans + 18 = 22, tmp = 18/3
// (()[[]] -> 
// (()[[]]) - >
//  tmp를 가지는 이유는 겉의 괄호곱을 기억하는 방식을 아래 처럼 활용하기 위함.
// (()[[]]) 이라면
// (()) + ([[]]) 으로 나눠짐.
// 2*2 + 2*3*3 = 4 + 18 = 22
