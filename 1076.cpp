#include <iostream>
#include <string>

using namespace std;
/*
black	0	1
brown	1	10
red	2	100
orange	3	1,000
yellow	4	10,000
green	5	100,000
blue	6	1,000,000
violet	7	10,000,000
grey	8	100,000,000
white	9	1,000,000,000
*/


int main()
{
    string temp;
    long long result = 0.1;
    
    
    //덧셈 2개
    for(int i = 0; i < 2; i++){
        
        cin >> temp;
        result *= 10;
        
        if (temp == "black") { 
            if(i == 0) result = 0.1;
        }
        else if (temp == "brown") result += 1;	//1	10
        else if (temp == "red") result += 2;	//2	100
        else if (temp == "orange") result += 3;	//3	1,000
        else if (temp == "yellow") result += 4; //4	10,000
        else if (temp == "green") result += 5; //	5	100,000
        else if (temp == "blue") result += 6;//	6	1,000,000
        else if (temp == "violet") result += 7;//	7	10,000,000
        else if (temp == "grey") result += 8;//	8	100,000,000
        else if (temp == "white")result += 9;//	9	1,000,000,000
    }
    
    //곱셈 1개
    cin >> temp;
    if (temp == "brown") result *= 10;
    else if (temp == "red")result *= 100;//2	100
    else if (temp == "orange") result *= 1000;//3	1,000
    else if (temp == "yellow") result *= 10000;	//4	10,000
    else if (temp == "green") result *= 100000;//	5	100,000
    else if (temp == "blue") result *= 1000000;//	6	1,000,000
    else if (temp == "violet") result *= 10000000;//	7	10,000,000
    else if (temp == "grey") result *= 100000000;//	8	100,000,000
    else if (temp == "white")result *= 1000000000;//	9	1,000,000,000
        
    cout << result << endl;
    
    return 0;
}
