#include <bits/stdc++.h>

using namespace std;

// 균형잡힌 세상

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
    while(true){
        string inputString;
        getline(cin, inputString);
        if(inputString == ".") break;
        
        stack<char> s;
        bool isValid = true;

        for(char c : inputString){
          if(c == '(' || c == '[') {
              s.push(c);
          }
          else if(c == ')'){
            if(s.size() > 0 && s.top() == '('){
                s.pop();
            }
            else{
                isValid=false;
                break;
            }
          }
          else if(c == ']'){
               if(s.size() > 0 && s.top() == '['){
                s.pop();
            }
            else{
                isValid=false;
                break;
            }
          }
        }
        if(!s.empty()) isValid = false;
        
        if(isValid) cout << "yes\n";
        else cout << "no\n";
      }
   
   return 0;
}