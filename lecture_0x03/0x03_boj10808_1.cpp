#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 알파벳 개수

// 조건
// 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는

// 입력 
// 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다

// 출력
// 단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string word;
    cin >> word;
    
    for(char standard = 'a'; standard <= 'z'; standard++){
        int cnt=0;
        for(char key : word){
            if(standard==key)
                cnt++;
        }
        cout << cnt << " ";
    }
    
   
   return 0;
}