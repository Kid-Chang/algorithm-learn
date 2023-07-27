#include <bits/stdc++.h>

using namespace std;

// 키로거

// 조건
// 강산이는 키보드로 입력한 키는 알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표이다.

// 입력 
// 첫째 줄에 테스트 케이스의 개수
// 백스페이스를 입력했다면, '-'가 주어진다. 이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다. 화살표의 입력은 '<'와 '>'로 주어진다. 이때는 커서의 위치를 움직일 수 있다면, 왼쪽 또는 오른쪽으로 1만큼 움직인다. 나머지 문자는 비밀번호의 일부이다. 물론, 나중에 백스페이스를 통해서 지울 수는 있다. 
// 만약 커서의 위치가 줄의 마지막이 아니라면, 커서 및 커서 오른쪽에 있는 모든 문자는 오른쪽으로 한 칸 이동한다.

// 출력
// 각 테스트 케이스에 대해서, 강산이의 비밀번호를 출력한다. 비밀번호의 길이는 항상 0보다 크다.


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tryCount;
    cin >> tryCount;
    
    for(int i=0;i<tryCount;i++){
        list<char> keyLogger = {};
        string inputString;
        auto cursor = keyLogger.begin();
        cin >> inputString;
        
        for(auto inputChar: inputString){
            if(inputChar == '<'){
                if(cursor!=keyLogger.begin())
                    cursor--;
            }
            else if(inputChar == '>'){
                if(cursor!=keyLogger.end())
                    cursor++;
            }
            else if(inputChar == '-'){
                if(cursor!=keyLogger.begin()){
                    cursor--;
                    cursor = keyLogger.erase(cursor);
                }
            }
            else{
                // 입력할 떄.
                keyLogger.insert(cursor,inputChar);
                
            }
        }
        for(auto c: keyLogger)
            cout << c;
        cout << '\n';
    }
    
    
   return 0;
}