//第六章内部分类
//冒泡
//插入分类
void Insert(n, A)
int n; LIST A;
{
	int i, j;
	A[0].key = BIG;//一个无穷大的数
	for (i = 1; i < n; i++) {
		j = i;
		temp = A[j];
		while (temp.key < A[j - 1].key && j>0) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}
//选择分类
void  SelectSort(n, A)
int  n; LIST  A;
{    int  i, j，lowindex;
keytype lowkey;
for (i = 1; i < n; i++)
{
	lowindex = i;
	for (j = i + 1; j <= n; j++)
		if (A[j].key < A[lowindex].key)
			lowindex = j;
	swap(A[i], A[lowindex]);
}
}

//希尔排序
void shellsort(LIST& A, int n) {
	for (k = n / 2; k <= 1; k = k / 2) {
		for (i = k + 1; i < n; i++) {
			x = A[i]; j = i - k;
			while ((j > 0) && (x.key < A[j].key)) {
				A[j + k] = A[j];
				j = j - k;
			}
			A[j + k] = x;

		}
	}
}

void myself_shellsort(LIST& A, int n) {
	for (k = n / 2; k = 1; k = k / 2) {
		for (i = 1; i <= n - k; i++) {
			x = A[i]; j = i + k;
			while (j <= n && A[j].key < X.key) {
				A[j - k] = A[j];
				j = j + k;
			}
			A[j - k] = x;
		}
	}
}

//快排
//要点：中间值的选择
中间值 v 的选择，其位置确定在 A[k]
设findpivot(i, j), 求A[i].key, …, A[j].key的中间值v。
ⅰ v = (A[i].key，A[(i + j) / 2].key, A[j].key的中值)
ⅱ v = 从A[i].key 到  A[j].key 最先找到的两个不同关键字
中的最大的。

int   FindPivot(int  i, int  j)
{//中间值
	keytype   firstkey;   int  k;
	firstkey = A[i].key;
	for (k = i; k <= j; k++)
		if (A[k].key > firstkey)
			return k;
		else  if (A[k].key < firstkey)
			return  i;
	return  0;
}

Int  Partion(i, j, pivot)//分割
Int i, j;  keytype  pivot;
{   int   L, R;
L = i;   R = j;
do {
	swap(A[L], A[R]);
	while (A[L].key < pivot)
		L = L + 1;
	while (A[R].key >= pivot)
		R = R - 1;
} while (L <= R);
return L;
}

void quicksort(int i, int j) {
	keytype pivot;
	int piovtindex, k;
	pivotindex = FindPivot(i, j);
	if (pivotindex)
	{
		pivot = A[piovtindex].key;
		k = Partion(i, j, pivot);
		quicksort(i, k - 1);//递归
		quicksort(k, j);//递归
	}
}
//归并分类：
//合并两个有序序列
void Merge(l, m, n, A, B) 
	int l, m, n; LIST A, & B;
{
	int i, j, k, t;
	i = l; k = l; j = m + 1;
	while ((i <= m) && (j <= n)) {
		if (A[i].key <= A[j].key)
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= m) B[k++] = A[i++];
	while (j <= n) B[k++] = A[j++];
}


void T_W_SORT(n, A)
int n; LIST& A;//n个元素
{
	int l;
	LIST B;
	l = 1;
	while (l < n)
	{
		Mpass(n, l, A, B);
		l = l * 2;
		Mpass(n, l, B, A);
		l = l * 2;
	}
}
void Mpass(n, l, A, B)
int i, t;
{
	i = 1;
	while (i <= n - 2 * l + 1)//存在2*l长的两个归并段
	{
		Merge(i, i + l - 1; i + 2 * l - 1, A, B);
			i = i + 2 * l;
	}
	if ((i + l - 1) < n)
		Merge(i, i + l - 1, n, A, B);
	else
		for (t = i; t <= n; t++) B[t] = A[t];
}


