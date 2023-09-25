#include <iostream>
using namespace std;

int MIN;
int N;
int Red[1001];
int Green[1001];
int Blue[1001];

//DP로 이전 값 저장
int total[1001][3];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> Red[i] >> Green[i] >> Blue[i];
    
    total[0][0] = Red[0];
    total[0][1] = Green[0];
    total[0][2] = Blue[0];
    //search 
    
    
    for(int i = 1; i < N; i++){
        
        total[i][0] = total[i-1][1] < total[i-1][2] ? total[i-1][1] : total[i-1][2];
        total[i][0] += Red[i];
        
        total[i][1] = total[i-1][0] < total[i-1][2] ? total[i-1][0] : total[i-1][2];
        total[i][1] += Green[i];
        
        total[i][2] = total[i-1][0] < total[i-1][1] ? total[i-1][0] : total[i-1][1];
        total[i][2] += Blue[i];
    }

    MIN = total[N-1][0] < total[N-1][1] ? total[N-1][0] : total[N-1][1];
    MIN = total[N-1][2] < MIN ? total[N-1][2] : MIN;
    
    //output
    cout << MIN << endl;

    return 0;
}
