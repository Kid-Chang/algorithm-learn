#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 애너그램 만들기

// 조건
// 두 개의 영어 단어가 주어졌을 때, 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 
// 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.



// 입력 
// 첫째 줄과 둘째 줄에 영어 단어가 소문자로 주어진다

// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string string1,string2;
    int alphabet[2][26]={};
    
    cin >> string1 >> string2;
    
    for(char c: string1){
        alphabet[0][c-'a']++;
    }
    for(char c: string2){
        alphabet[1][c-'a']++;
    }
    
    // 만약 알파벳의 갯수를 서로 비교했을때, 같은 값이 나오면 이는 문제가 되지않음
    // 하지만, 알파벳 갯수가 다르다면 제거해야함. 그럼 이것들을 카운트하면 됨.
    
    int count=0;
    for(int i=0;i<26;i++){
        count+=abs(alphabet[0][i]-alphabet[1][i]);
    }
    
    cout << count;
    
   
   return 0;
}
