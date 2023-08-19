#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 대표값2

// 조건
// 

// 입력 
// 첫째 줄부터 다섯 번째 줄까지 한 줄에 하나씩 자연수가 주어진다. 주어지는 자연수는 100 보다 작은 10의 배수이다.


// 출력
// 첫째 줄에는 평균을 출력하고, 둘째 줄에는 중앙값을 출력. 이 값들은 모두 자연수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int number[5], max=0, middle=0;
    
    for(int i =0; i < 5; i++){
        cin >> number[i];
    }
    
    // 평균 구하기
    for(int i =0; i < 5; i++){
        max += number[i];
    }
    
    // 중앙값 구하기
    for(int i =0; i < 5; i++){
        sort(number,number+5);
    }
    
    cout << (max/5) << "\n" << number[2];
    
    
   
   return 0;
}