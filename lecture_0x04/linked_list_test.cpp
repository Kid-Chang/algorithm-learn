#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; // 현재 사용되지 않는 인덱스

//  addr = 2가 의미하는 것이 연결 리스트 상에서 2번째 원소라는 것이 아니라, 
// 해당 원소의 "주소"가 2번지라는 점을 꼭 헷갈리면 안됩니다.
void insert(int addr, int num){
    dat[unused]=num;
    pre[unused]=addr;
    nxt[unused]=nxt[addr];
    
    // 맨 마지막 원소(배열 말하는거 아님. traverse하는 "리스트"의 끝을 말하는 거임)의 뒤에 
    // 새 원소를 추가하는 상황이라면 "삽입할 위치의 다음 원소"가 존재하지 않습니다. 즉, 다음 "배열"의 pre, nxt가 -1로 채워진 것!
    // 그런데도 pre[nxt[addr]] = unused; 로 써버리면 pre[-1]에 접근할 수 있습니다. 
    // 주소를 -1로 초기화(fill)해놨기 때문.
    // 그래서 nxt[addr]가 -1이 아닐 때에만 pre[nxt[addr]]에 unused를 대입하도록 했습니다.
    // pre[nxt[addr]]=unused;
    if(nxt[addr] != -1) pre[nxt[addr]]=unused;
    // 순서 주의. nxt[addr]=unused가 먼저나오면 if문이 정상적으로 동작하지 못함.
    nxt[addr]=unused;
    
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; // 즉 지우는 원소의 뒤에 이어지는 원소가 있다면!
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}