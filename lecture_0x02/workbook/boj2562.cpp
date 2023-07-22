#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 최댓값

// 조건
// 9개의 서로다른 자연수 제공. 최댓값과 최댓값이 몇번쨰 순서인지 찾기. 

// 입력 
// 9개의 서로다른 자연수를 한줄에 한개씩

// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int number[9], max=0, idx;
    
    for(int i =0; i < 9; i++){
        cin >> number[i];
    }
    
    for(int i =0; i < 9; i++){
        if(number[i]> max ){
            max = number[i];
            idx = i;
        }
    }
    cout << max << "\n" << idx+1;
    
    
   
   return 0;
}