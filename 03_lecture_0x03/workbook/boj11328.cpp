#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Strfry

// 조건
// 

// 입력 
// 입력의 첫 번째 줄은 테스트 케이스의 수 0 < N < 1001 이다.
// 각각의 테스트 케이스는 하나의 줄에 영어 소문자들로만 이루어진 두 개의 문자열이 한 개의 공백으로 구분

// 출력
// 2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 
// 얻어질 수 있는지의 여부를 "Impossible"(불가능) 또는 "Possible"(가능)으로 나타내시오

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        string originalWord, strfryWord;
        int originalAlphabet[26]={}, strfryAlphabet[26]={}; // a=0~z=25
        cin >> originalWord >> strfryWord;
        
        // 문자열을 한글짜식 alphabet에 넣고
        // 각 자리수를 비교해서 틀리면 바로 Impossible;
        
        for(int alphabet: originalWord)
            originalAlphabet[alphabet-'a']++;
        for(int alphabet: strfryWord)
            strfryAlphabet[alphabet-'a']++;
            
        int errCount=0;
        for(int j=0;j<26;j++){
            if(originalAlphabet[j]!=strfryAlphabet[j]){
                errCount++;
             
            }
        }
        
        if(errCount >0){
           cout << "Impossible\n";
        }else{
            cout << "Possible\n";
        }
    }
    
   
   return 0;
}
