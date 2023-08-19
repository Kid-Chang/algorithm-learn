#include <bits/stdc++.h>

using namespace std;

// 스택(STL stack 사용)

// 조건
// push, pop, size, empty, top 입력시 상황에 따라 작동하도록 구현.

// 입력 
// 첫째 줄에 주어지는 명령의 수 N
// 둘째 줄부터 명령이 하나씩 주어진다.

// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    int count;
    cin >> count;
    string command;
    
    for(int i;i<count;i++){
        cin >> command;
        if(command == "push"){
            int inputValue;
            cin >> inputValue;
            S.push(inputValue);
        }
        else if(command == "top"){
            if(!S.empty())
                cout << S.top()<< "\n";
            else
                cout << "-1\n";
        }
        else if(command == "pop"){
            if(!S.empty()){
                cout << S.top()<< "\n";
                S.pop();
            }
            else
                cout << "-1\n";
        }
        else if(command == "size"){
            cout << S.size()<< "\n";
        }
        else if(command == "empty"){
            cout << S.empty()<< "\n";
        }
    
        
    }

   
   return 0;
}