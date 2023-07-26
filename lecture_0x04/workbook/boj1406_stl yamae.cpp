#include <bits/stdc++.h>

using namespace std;

// 에디터(야매 연결 리스트 이용)

// 조건
// 

// 입력 
// 첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
// 이 문자열은 길이가 N이고, 영어 소문자로만, 길이는 100,000을 넘지 않는다. 
// 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 
// 셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.
// 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

// 출력
// 첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.


const int MX = 1000005;
int pre[MX], nxt[MX];
char dat[MX];
int unused = 1; // 현재 사용되지 않는 인덱스

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  nxt[pre[addr]] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

void commandP(char c){
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 초기설정
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    
    int cur;
    // 초기 문자열 받기
    string text;
    cin >> text;
    for(char c:text){
        insert(unused - 1, c);
        cur = unused - 1;
    }
    
    int commandCount;
    cin >> commandCount;
    
    for(int i=0; i<commandCount; i++){
        char command, inputValue;
        cin >> command;
        
        if(command == 'L'){
            if(pre[cur]!=-1){
                cur=pre[cur];
            }
        }
        
        if(command == 'D'){
            if(nxt[cur]!=-1){
                cur=nxt[cur];
            }
        }
        
        if(command == 'B'){
            if(pre[cur]!=-1){
              erase(cur);
              cur=pre[cur];
            }
        }

        if(command == 'P'){
            cin >> inputValue;
            insert(cur, inputValue);
            cur = unused - 1;

        }
        
    }
    traverse();
    
    
    
   
   return 0;
}