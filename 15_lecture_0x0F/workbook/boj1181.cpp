#include <bits/stdc++.h>

using namespace std;

// 단어 정렬

// 조건
// 

// 입력 
// 

// 출력
// 
int n;

bool lengthSort(string a, string b){
    if (a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        return a<b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), lengthSort);
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for(string val : arr){
        cout << val << "\n";
    }
    
   
    return 0;
}