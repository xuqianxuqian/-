��1���Գ��󣡣�
Sa[k] �� aij ��һһ��Ӧ��ϵΪ :
 k =   i(i �C 1) / 2 + j    �� i �� j

 or     j(j �C 1) / 2 + i    �� i < j

	 ElementType   A(ElementType B[], int i, int j)
 {//��������
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
 {//��������
	 int k;
	 if (i <= j)
	 {
		 k = i * (i - 1) / 2 + j;
		 return (B[k]);
	 }
	 else
		 return(0);
 }



(2)��״�����˽⣩
LOC[i��j] = LOC[1��1]
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


��3��ϡ����󣡣�
AID
#define  MAXSIZE  12500
typedef  struct {
		int  i��j ��//�����±�
		ElementType  e ��//Ԫ��
}  Triple ��
typedef  struct {
		Triple  data[MAXSIZE + 1]��//ֻ�������Ԫ��
			int  mu��nu��tu��//����������������Ԫ������
	} TSMatrix��

������ num[col], ��ʾ����M�е� col ���з���Ԫ�صĸ�
��, cpot[col] ָʾM�е� col �еĵ�һ������Ԫ���� b �е�ǡ
��λ�á�
Cpot[1] = 1 ��
Cpot[col] = cpot[col �C 1] + num[col �C 1]     2�� col ��a.nu

Void  FastTransposMatrix(TSMatrix  M��TSMatrix& T)
		{
			T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
			if (T.tu)
			{
				for (col = 1; col <= M.nu; ++col)  num[col] = 0;
				for (t = 1; t <= M.tu; ++t)  ++num[M.data[t].j];
				cpot[1] = 1 ��
					for (col = 2; col < M.nu; col++)
						cpot[col] = cpot[col �C1] + num[col �C 1];
				for (p = 1; p <= M.tu; ++p)//��������Ԫ��
				{
					col = M.data[p].j;//����Ԫ���������±�
					q = cpot[col];//���е�һ��Ԫ����T.data[]�е�λ��
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++cpot[col];//��Ϊ��һ��Ԫ���Ѿ�����ˣ�����λ��Ӧ������һλ
				}
			}
		}






