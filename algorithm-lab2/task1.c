#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include "task1.h"

int task1() {
	int n;//数字位数
	char* l;//数字
	int** dp;//前i位数切割为j段所能得到的最大乘积
	int k;//分割段数

	//输入
	scanf("%d", &n);
	scanf("%d", &k);

	l = malloc(n * sizeof(char));
	scanf("%s", l);

	//分配空间，dp[n][k]
	dp = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		dp[i] = malloc(k * sizeof(int));
		memset(dp[i], 0, k * sizeof(int));
	}

	//初始化dp边界值
	for (int i = 0; i < n; i++) {
		dp[i][0] = get_num(l, 0, i);
	}

	//层
	for (int i = 1; i < n; i++) {
		//列
		for (int j = 1; j <= i; j++) {
			//选p
			for (int p = 0; p < i; p++) {
				if (dp[i][j] < dp[p][j - 1] * get_num(l, p + 1, i)) {
					dp[i][j] = dp[p][j - 1] * get_num(l, p + 1, i);
				}
			}
		}
	}


	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < k; j++) {
	// 			printf("%d ", dp[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	printf("%d", dp[n - 1][k - 1]);
	return 0;
}

int get_num(char* l, int start, int end) {
	//n位数
	//l数字字符数组
	int result = 0;
	while (start <= end) {
		result = result * 10 + l[start] - '0';
		start++;
	}
	return result;
}

