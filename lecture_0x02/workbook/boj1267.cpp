#include <iostream>

using namespace std;

// 핸드폰 요금

// 조건
//  영식 요금제는 30초마다 10원씩 청구된다. 
// 이 말은 만약 29초 또는 그 보다 적은 시간 통화를 했으면 10원이 청구된다. 만약 30초부터 59초 사이로 통화를 했으면 20원이 청구된다.
// 민식 요금제는 60초마다 15원씩 청구된다. 
// 이 말은 만약 59초 또는 그 보다 적은 시간 통화를 했으면 15원이 청구된다. 만약 60초부터 119초 사이로 통화를 했으면 30원이 청구된다.

// 동호가 저번 달에 새악대로 T 통신사를 이용할 때 통화 시간 목록이 주어지면 어느 요금제를 사용 하는 것이 저렴한지 출력하는 프로그램을 작성하시오.

// 입력 
// 통화의 개수 N
// 통화 시간(sec) N개

// 출력
// 첫째 줄에 싼 요금제의 이름을 출력한다. 
// 그 후에 공백을 사이에 두고 요금이 몇 원 나오는지 출력한다. 
// 만약 두 요금제의 요금이 모두 같으면 영식을 먼저 쓰고 민식을 그 다음에 쓴다.
// 영식은 Y로, 민식은 M으로 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int callcount, callSec, Y=0, M=0;
    cin >> callcount;
    for(int i = 0; i < callcount; i ++) {
        cin >> callSec;
        Y += ((callSec / 30)+1) * 10;
        // 민식
        M += ((callSec / 60)+1) * 15;
    }
    
    // 영식
    if( Y < M ){
        cout << "Y " << Y; 
    }
    else if( Y > M ){
        cout << "M " << M; 
    }
    else if( Y == M ){
        cout << "Y M " << Y; 
    }
    
    return 0;
}