#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task2.h"

int task2() {
	int n = 0;
	int** r = 0;
	scanf("%d", &n);
	r = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		r[i] = malloc(n * sizeof(int));
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			scanf("%d", &r[i][j]);
		}
	}
	//假设已经有r[i][j]，r[i][j]代表从i到j的最小代价，下标从0开始
	//在优化r[i][j]的过程中，求出r[1-1][n-1]
	//保证r[1-1][p-1]最优，对于r[1-1][p-1+1]，只有两种情况，是r[1-1][p-1]或r[1-1][p]

	for (int p = 2; p < n; p++) {
		for (int z = 1; z < n; z++) {
			if (r[0][z] + r[z][p] < r[0][p]) {
				r[0][p] = r[0][z] + r[z][p];
			}

		}
	}
	printf("%d", r[0][n - 1]);


	return 0;
}



