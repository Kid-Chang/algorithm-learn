#include <bits/stdc++.h>

using namespace std;

// 팰린드롬 

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
string word_case[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--){
        int m, count =0;
        cin >> m;
        
        for(int i=0;i<m;i++){
            cin >> word_case[i];
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(count>0) break;
                if(i==j) continue;
                string original_word = word_case[i]+word_case[j];
                string reverse_word = original_word;
                
                reverse(reverse_word.begin(), reverse_word.end());
                if(original_word == reverse_word) {
                    cout << original_word << "\n";
                    count++;
                    break;
                }
            }
        }
        
        
        if (count==0) cout << "0\n";
    }

    
    return 0;
}