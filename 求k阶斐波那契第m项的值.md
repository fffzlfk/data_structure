### 题目
已知k阶斐波那契序列的定义为
$$f_0 = 0, f_1 = 0, ...,f_{k-2}=0,f_{k-1}=1;$$
$$f_n = f_{n-1}+f_{n-2}+...+f_{n-k},n=k,k+1,...$$
试编写求k阶斐波那契数列第m项值的算法，k和m均以值调用的形式在函数列表出现。
### 代码实现
```c
#include <stdio.h>
const int MAXN = 10000;
long long fib(int k, int m) {
	long long a[MAXN];
	for (int i = 0; i < k - 1; i++) {
		a[i] = 0;
	}
	a[k - 1] = 1;
	for (int i = k; i <= m; i++) {
		long long s = 0;
		for (int j = i - 1; j > i - 1 - k; j--) {
			s += a[j];
		}
		a[i] = s;
	}
	return a[m];
}
int main() {
	int k, m;
	while (scanf("%d%d", &k, &m) == 2) {
		printf("%lld\n", fib(k, m));
	}
	return 0;
}
```
### 注释
该题目出现在数据结构（C语言版）题集中的1.17
