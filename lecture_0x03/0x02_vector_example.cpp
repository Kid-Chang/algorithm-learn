#include <bits/stdc++.h>
using namespace std;


int main(void){
    vector<int> v1(3,5); // {5,5,5};
    // vector를 선언할 때 인자 뒤에 (a,b)를 입력하면 
    // b로 초기화된 원소 a개가 들어있는 백터를 선언하는 것.
    // (a)와 같이 하나의 인자만 넣으면 0으로 초기화된 원소 a가 들어있는 백터 선언.
    cout << v1.size() <<"\n"; // 3
    v1.push_back(7); // {5,5,5,7};
    // .push_back(a) 메서드는 해당 배열의 맨뒷자리에 a를 삽입함.

    vector<int> v2(2);
    v2.insert(v2.begin()+1,3); // {0,3,0};
    // v2의 배열에 insert 메서드를 실행한다.
    // .insert(메모리 위치, 넣을 값)
    // v2.begin()+a는 시작위치에서 a칸 오른쪽으로 이동한 위치를 의미한다.
    
    vector<int> v3 = {1,2,3,4};
    v3.erase(v3.begin()+2); // {1,2,4};
    // .erase(메모리 위치)

    vector<int> v4; //{}
    v4 = v3; // {1,2,4};
    // 단, 백터끼리 = 연산자를 이용해 복사하면, 메모리 주소를 가져가는 것이 아닌,
    // 해당 값 전체를 deep copy한다.

    cout << v4[0] << v4[1] << v4[2] << "\n";
    v4.pop_back(); // {1,2};
    v4.clear(); // {};
    // .clear 메서드는 해당 백터의 내용물을 비우고 껍데기만 남긴다. 
    // 즉, 메모리 공간은 차지하고 있으나, 값들은 비워진 상태.


}