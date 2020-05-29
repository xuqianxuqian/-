（1）对称阵！！
Sa[k] 和 aij 的一一对应关系为 :
 k =   i(i – 1) / 2 + j    当 i ≥ j

 or     j(j – 1) / 2 + i    当 i < j

	 ElementType   A(ElementType B[], int i, int j)
 {//下三角阵
	 int k;
	 if (i >= j)
	 {
		 k = i * (i - 1) / 2 + j;
		 return (B[k]);
	 }
	 else
		 return(0);
 }
 ElementType   A(ElementType B[], int i, int j)
 {//上三角阵
	 int k;
	 if (i <= j)
	 {
		 k = i * (i - 1) / 2 + j;
		 return (B[k]);
	 }
	 else
		 return(0);
 }



(2)带状矩阵（了解）
LOC[i，j] = LOC[1，1]
+ [(2s + 1) * (i - 1) + (j - i)] * L
L = 1;
ElementType   A(ElementType B[], int s, int i, int j)
{
	int k;
	if (abs(i - j) <= s)
	{
		k = 1 + (2s + 1) * (i - 1) + (j - i);
		return(B[k]);
	}
	else
		return(0);
}


（3）稀疏矩阵！！
AID
#define  MAXSIZE  12500
typedef  struct {
		int  i，j ；//数组下标
		ElementType  e ；//元素
}  Triple ；
typedef  struct {
		Triple  data[MAXSIZE + 1]；//只储存非零元素
			int  mu，nu，tu；//行数，列数，非零元素总数
	} TSMatrix；

设向量 num[col], 表示矩阵M中第 col 列中非零元素的个
数, cpot[col] 指示M中第 col 列的第一个非零元素在 b 中的恰
当位置。
Cpot[1] = 1 ；
Cpot[col] = cpot[col – 1] + num[col – 1]     2≤ col ≤a.nu

Void  FastTransposMatrix(TSMatrix  M，TSMatrix& T)
		{
			T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
			if (T.tu)
			{
				for (col = 1; col <= M.nu; ++col)  num[col] = 0;
				for (t = 1; t <= M.tu; ++t)  ++num[M.data[t].j];
				cpot[1] = 1 ；
					for (col = 2; col < M.nu; col++)
						cpot[col] = cpot[col –1] + num[col – 1];
				for (p = 1; p <= M.tu; ++p)//遍历非零元素
				{
					col = M.data[p].j;//非零元素所在列下标
					q = cpot[col];//该列第一个元素在T.data[]中的位置
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++cpot[col];//因为第一个元素已经算过了，所以位置应该下移一位
				}
			}
		}






