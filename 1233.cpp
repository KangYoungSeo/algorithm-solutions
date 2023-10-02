#include <iostream>
#include <cmath>

using namespace std;

int S1,S2,S3;

int sum[81];

int main() {
	//input
	cin >> S1 >> S2 >> S3;
	
	int total = 0;
	
	for(int i = 1; i < S1 + 1; i++){
	    
	    total += i;
	    
	    for(int j = 1; j < S2 + 1; j++){
	        
	        total += j;
	        
	        for(int k = 1; k < S3 + 1; k++){
	            total += k;
	            
	            sum[total]++;
	            
	            total -= k;
	            
	        }
	        
	        total -= j;
	    }
	    
	    total -= i;
	}
	
	
	//탐색
	int max = -1;
	int totalMax = 0;
	for(int i=3; i < 81; i++){
	    
	    if(max < sum[i]){
	        max = sum[i];
	        totalMax = i;
	    }
	}
	
	//결과 출력
	cout << totalMax << endl;
	
	return 0;
}
