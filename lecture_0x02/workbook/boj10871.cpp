#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, X, inputValue;
    
    cin >> N >> X;
    
    while (N--){
        cin >> inputValue;
        if(inputValue < X)
        {
        cout << inputValue << " ";
        }
    }

    return 0;
}