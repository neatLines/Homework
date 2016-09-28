#include <stdio.h>
int Fibonacci(int k, int m)
{
	if (m < k - 1) {
		return 0;
	}
	else if (m == k - 1) {
		return 1;
	}
	else {
		int pre = 1;
		int next = 1;
		m = m - k;
		while (m > 0) {
			next += pre;
			pre = next - pre;
			m--;
		}
		return next;
	}
}

int main()
{
	printf("%d",Fibonacci(2,10));
	return 0;
}
