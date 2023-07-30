#include <bits/stdc++.h>

using namespace std;

// 스택(스택 스스로 구현해서 사용)

// 조건
// push, pop, size, empty, top 입력시 상황에 따라 작동하도록 구현.

// 입력 
// 첫째 줄에 주어지는 명령의 수 N
// 둘째 줄부터 명령이 하나씩 주어진다.

// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

const int MX = 1000005;
int dat[MX];
int pos;

void push(int i){
    dat[pos++] = i;
}
void pop(){
    pos--;
}
int top(){
    return dat[pos-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int count;
    cin >> count;
    string command;
    
    for(int i;i<count;i++){
        cin >> command;
        if(command == "push"){
            int inputValue;
            cin >> inputValue;
            push(inputValue);
        }
        else if(command == "top"){
            if(pos!=0)
                cout << top()<< "\n";
            else
                cout << "-1\n";
        }
        else if(command == "pop"){
            if(pos!=0){
                cout << top()<< "\n";
                pop();
            }
            else
                cout << "-1\n";
        }
        else if(command == "size"){
            cout << pos << "\n";
        }
        else if(command == "empty"){
            if(pos == 0)
                cout << 1 << "\n";
            else
                cout << "0\n";
        }
    
        
    }
    

   
   return 0;
}