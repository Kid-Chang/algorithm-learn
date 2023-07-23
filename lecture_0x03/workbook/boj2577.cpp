#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

// 숫자의 개수

// 조건
// 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하라

// 입력 
// 첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 크거나 같고, 1,000보다 작은 자연수이다.



// 출력
// 첫째 줄에는 결과에 0 이 몇 번 쓰였는지 출력한다. 
// 마찬가지로 둘째 줄부터 열 번째 줄까지 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,c, multi, number[10]={};
    string multiStr;
    cin >> a >> b >> c;
    multi = a*b*c;
    multiStr = to_string(multi);
    
    for(char key: multiStr){
        int keyInt = (int)key - '0';
        number[keyInt]++;
    }
    
     for(int i=0;i<10;i++){
        cout <<  number[i] << "\n";
    }
  
    return 0;
}