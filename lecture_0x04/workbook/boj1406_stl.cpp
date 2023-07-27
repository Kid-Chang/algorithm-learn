#include <bits/stdc++.h>

using namespace std;

// 에디터(STL list 이용)

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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    list<char> editor = {};
    
    
    string initalValue;
    cin >> initalValue;
    for(auto c: initalValue){
        editor.push_back(c);
    }

    auto cursor = editor.end();


    int commandCount;
    cin >> commandCount;
    
    for(int i=0; i<commandCount; i++){
        char command;
        cin >> command;
        
        if(command == 'L'){
            if(cursor != editor.begin())
                cursor--;
            
        }
        if(command == 'D'){
            if(cursor != editor.end())
                cursor++;
            
        }
        if(command == 'B'){
            if (cursor != editor.begin()) {
                cursor--;
                cursor = editor.erase(cursor);
            }
      
      
        }
        if(command == 'P'){
            char input;
            cin >> input;
            editor.insert(cursor,input);
            
        }
    }
    
    for(auto c: editor)
        cout << c;
   return 0;
}