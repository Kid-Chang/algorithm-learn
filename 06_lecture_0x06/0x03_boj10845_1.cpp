#include <bits/stdc++.h>

using namespace std;

// 큐(STL 이용)

// 조건
// 

// 입력 
// 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.

// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    cin >> count;
    queue<int> Q;
    
    while(count--){
        string command;
        cin >> command;
        
        if(command == "push"){
            int inputValue;
            cin >> inputValue;
            Q.push(inputValue);
        }
        else if(command == "pop"){
            if(!Q.empty()){
                cout << Q.front() << "\n";
                Q.pop();
            }
            else
                cout <<  "-1\n";
        }
        else if(command == "size")
            cout << Q.size() << "\n";
        else if(command == "empty")
            if(Q.empty()) cout << "1\n";
            else cout << "0\n";
        else if(command == "front")
            if(!Q.empty())
                cout << Q.front() << "\n";
            else cout <<  "-1\n";
        else if(command == "back")
            if(!Q.empty())
                cout << Q.back() << "\n";
            else cout <<  "-1\n";

    }
   
   return 0;
}