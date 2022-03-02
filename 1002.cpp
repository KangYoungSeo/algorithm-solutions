#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int main()
{
	int t, x1, y1, r1, x2, y2, r2, result; scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		int distance = pow(x1 - x2, 2)+ pow(y1 - y2, 2);
		int minus = (r1 - r2)*(r1 - r2);
		int plus = (r1 + r2)*(r1 + r2);
		
		if (distance == 0) {
			if (minus == 0) result = -1;
			else result = 0;
		}
		else if (distance == minus || distance == plus) result = 1;
		else if (minus < distance && distance < plus) result = 2;
		else result = 0;
	
		printf("%d\n", result);
	}
	return 0;

}
