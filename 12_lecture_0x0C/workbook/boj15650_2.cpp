#include <bits/stdc++.h>

using namespace std;

// N과 M (2)

// 조건
// 

// 입력 
// n m

// 출력
// 1~n까지 m개를 중복없이 오름차순.

int n, m; 
int arr[20];
bool isused[20];
deque<int> a;
void tracking(int cur){
    for(int i = 0; i < n; i++)  a.push_back(i < m ? 0 : 1);

        do{
            for(int i = 0; i < n; ++i)
                if(a[i] == 0) cout << i+1 << ' ';
            cout << '\n';
        }while(next_permutation(a.begin(), a.end()));
        
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    tracking(0);

    
    return 0;
}