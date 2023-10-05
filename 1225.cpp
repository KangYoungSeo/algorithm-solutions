#include <iostream>
#define ll long long
using namespace std;
ll answer;
string A, B; 
int main(){
    
    cin >> A >> B;
    
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < B.size(); j++)
            answer += (A[i] -'0') * (B[j] - '0');
  
    cout << answer << endl;
    return 0;
}