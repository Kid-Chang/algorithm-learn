#include <bits/stdc++.h>

using namespace std;

// 큐(큐 구현해서 이용)

// 조건
// 

// 입력 
// 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.

// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    cin >> count;

    while(count--){
        string command;
        cin >> command;
        
        if(command == "push"){
            int inputValue;
            cin >> inputValue;
            push(inputValue);
        }
        else if(command == "pop"){
            if(tail-head!=0){
                cout << front() << "\n";
                pop();
            }
            else
                cout <<  "-1\n";
        }
        else if(command == "size")
            cout << tail-head << "\n";
        else if(command == "empty")
            if(tail-head==0) cout << "1\n";
            else cout << "0\n";
        else if(command == "front")
            if(tail-head!=0)
                cout << front() << "\n";
            else cout <<  "-1\n";
        else if(command == "back")
            if(tail-head!=0)
                cout << back() << "\n";
            else cout <<  "-1\n";
    }
   
   return 0;
}