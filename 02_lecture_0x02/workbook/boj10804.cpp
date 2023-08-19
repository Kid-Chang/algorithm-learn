#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 카드 역배치

// 조건
// 20장의 카드가 오름차순으로 정렬되어있다.
// a, b라는 범위가 입력되면 해당 숫자를 포함한 구간이 역순으로 뒤집힌다.
// 10개의 구간이 주어진 후, 나오는 결과를 출력하라.

// 입력 
// 10개줄에 걸쳐 "a b" 와 같은 형태로 값이 주어진다.

// 출력
// 마지막까지 정렬을 마친 후 결과를 출력하라.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 카드 자리수와 idx를 동일시하기위해 한칸 더 만듬.
    int card[21], a, b;
    
    //카드 숫자 넣기
    for(int i = 1; i < 21; i++) card[i]=i;

    for(int i = 0; i < 10; i++){
        cin >> a >> b;
        
        // 정렬 진행
        for(int j=0; j<(b-a+1)/2; j++){
            swap(card[a+j], card[b-j]);
        }
    }
    
    for(int i=1; i < 21; i++){
        cout << card[i] << " ";
    }
    
    return 0;
}