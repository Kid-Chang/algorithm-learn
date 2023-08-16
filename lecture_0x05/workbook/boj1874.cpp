#include <bits/stdc++.h>

using namespace std;

// 스택 수열


// 조건
// 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
// -> 넣는 건 신경안쓰겠단 말.
// 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.

// 입력


// 출력



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    int count, number;
    cin >> count;
    int sequence = 1;
    string answer = "";
    while(count--){
        cin >> number;
        while(sequence <= number){
            S.push(sequence++);
            answer += "+\n";
        }
        if(S.top() != number){
            cout << "NO";
            return 0;
        }
        S.pop();
        answer +=  "-\n";
    }
    cout << answer;
    
    
    return 0;
}