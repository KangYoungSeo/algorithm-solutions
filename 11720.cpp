#include <iostream>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    if ( N <0 || N > 100) return 0;
    
    char* num = new char[N];
    int sum = 0;
    
    cin >> num;
    for(int i = 0 ; i< N ; i++){
        sum+=(int) num[i] % 48;
    }
    cout << sum << endl;
    
}
