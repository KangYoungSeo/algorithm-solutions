#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> number;
vector<char> sign;
string s;
int MIN;

int compute() {


	return answer;

}



int main(void) {

	cin >> s;
    int temp = 0;

    //parsing
    for(int i = 0; i < s.size(); i++){
        //부호 추가
        if(s[i] == '+' || s[i] == '-'){
            number.push_back(temp);
            sign.push_back(s[i]);
        }
        //숫자 추가
        else{
            temp *= 10;
            temp += s[i];
        }
    }	

    //괄호를 넣었을 때 min 값 추가
    MIN = 1234567890;
    for(int i = 0; i < N; i++){
    }
	return 0;
}