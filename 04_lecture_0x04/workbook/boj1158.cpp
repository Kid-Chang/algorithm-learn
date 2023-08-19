#include <bits/stdc++.h>

using namespace std;

// 요세푸스 문제

// 조건
// 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고
// 순서대로 K번째 사람을 제거한다.

// 입력 
// 첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

// 출력
// <3, 6, 2, 7, 5, 1, 4>
// 와 같은 형태로 순요세푸스 순열을 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    list<int> sequence = {};
    
    for(int i=1;i<=N;i++)
        sequence.push_back(i);

   
    cout << "<";

    auto cursor = sequence.begin();
    
    int eraseCount=0, listCount=0;;

    for(int count=0;count<N;count++){        
        string caseText;
        for(int i=1; i<K; i++){
            cursor++;
            listCount++;

            if(listCount == N-eraseCount){
                cursor = sequence.begin();
                listCount=0;
            }
        }

        cout << *cursor;
        cursor = sequence.erase(cursor);
        eraseCount++;
        
        if(!sequence.empty())
           cout << ", ";


        if(listCount == N-eraseCount){
                cursor = sequence.begin();
                listCount=0;
        }
       
      
    }    
    
    
    cout << ">";
    
   return 0;
}