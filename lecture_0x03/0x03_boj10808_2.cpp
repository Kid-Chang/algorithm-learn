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
    
    // 전역변수(int main 과 같은 스코프)에 선언하면 알아서 0으로 초기화되지만, 
    // 지역변수로 사용하면 수동으로 초기화해줘야함.
    int alphabetCount[26]={};
    string word;
    cin >> word;
    
    for(char key: word){
        alphabetCount[key-'a']++;
    }
    
    for(int freq: alphabetCount)
        cout << freq << " ";
    
    
   
   return 0;
}