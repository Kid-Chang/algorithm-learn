#include <bits/stdc++.h>

using namespace std;

// 시리얼 번호

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
string serial_number[51];

int compare(string& a, string& b){ // 복사하지 마라!
    // A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(a.length() != b.length()){
        return a.length() < b.length();
    }

    
    else{
        // 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
        int a_num=0, b_num=0;
        for(char s: a){
            if(isdigit(s)) a_num+=s-'0';
        }
        for(char s: b){
            if(isdigit(s)) b_num+=s-'0';
        }
        if(a_num!=b_num) return a_num < b_num;
        
        
        // 만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.    
        // 즉 숫자의 합이 0일 경우
        return a < b;
        
    }
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> serial_number[i];
    }
    
    sort(serial_number,serial_number+n, compare);
    
    for(int i=0;i<n;i++) cout << serial_number[i] << "\n";
    
    return 0;
}