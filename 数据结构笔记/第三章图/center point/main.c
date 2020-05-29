#include <stdio.h>
#include <stdlib.h>

void Floyd(A, C, n) {
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			A[i][j] = G[i][j];
			P[i][j] = 0;//用于输出最小路径，为零表示不用插入中间点
		}
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = i; j <= n; j++) {
				sum = A[i][k] + A[k][j];
				if (sum < A[i][j]) {
					A[i][j] = sum;
					P[i][j] = k;
				}
			}
		}
	}//关键在于都是从小到大循环k，i,j，则保证A[i][k],A[j][k]都是最小的
}
void Path(i, j) {
	k = P[i][j];
	if (k != 0) {
		Path(i, k);
		count << k << endl;
		Path(k, j);
	}
}

int main()
{
    G[]
}
