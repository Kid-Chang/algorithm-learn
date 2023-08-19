#include <bits/stdc++.h>

using namespace std;

// AC

// 조건
// 두 가지 함수 R(뒤집기)과 D(버리기)
// 함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 
// 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.



// 입력 
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
// 각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
// 다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
// 다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
// 전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.


// 출력
// 각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt, arrCount;
    
    cin >> cnt;
    
    while(cnt--){
        // 배열에 들어있는 수의 개수
        deque<string> DQ;
        string command;
        string numArr="", numArrAndBracket;
        int reverseCount=0, err=0;
        cin >> command >> arrCount >> numArrAndBracket;
        
        // 숫자 배열을 덱에 삽입
        
        string separator = ",";
        int cur_position = 0;
        int position;
        
        for(char s: numArrAndBracket){
            if(s!='[' && s!=']'){
                numArr+=s;
           }
        }

        while ((position = numArr.find(separator, cur_position)) != string::npos) {
            int len = position - cur_position;
            string result = numArr.substr(cur_position, len);
            DQ.push_back(result);
            cur_position = position + 1;
        }

        string result = numArr.substr(cur_position);
        DQ.push_back(result);
        // cout << DQ.size();
  
        for(char c: command){
            //cout << c << " ";
            //commandSet.push_back(c);
            
            if(c=='R'){
                // Reverse 
                reverseCount++;
            }
            else if(c=='D'){

                // Delete, if array is emtpy, return err.
                if(!DQ.size() || DQ.front()==""){
                    cout << "error";
                    err=1;
                    break;
                }
                
                if(reverseCount%2==0)
                    DQ.pop_front();
                else
                    DQ.pop_back();
                
            }
        }        
        if(err==0){
            cout << "[";
            while(DQ.size()){
                if(reverseCount%2==0){
                    cout << DQ.front();
                    DQ.pop_front();
                }else{
                    cout << DQ.back();
                    DQ.pop_back();
                }
                if(DQ.size()>0){
                    cout << ",";
                }
            } 
            cout << "]";
        }   
        
    cout << "\n";

    }
   
   return 0;
}