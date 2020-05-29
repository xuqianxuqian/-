//���ң�����������ʱ�临�Ӷ�O��m*n��
//      KMP��O��m+n)

next������
(1)next[0] = -1���κδ��ĵ�һ���ַ���ģʽֵ�涨Ϊ - 1
(2)next[j] = -1��ģʽ��t���±�Ϊj���ַ�����������ַ���ͬ����j��ǰ���
1��k ���ַ��뿪ͷ��1..k ���ַ�����(������ȵ�t[k] == t[j]),
1��k < j
�磺t = ��abCabCad�� �� next[6] = -1����t[3] = t[6]
(3)next[j] = k��ģʽ��t���±�Ϊj���ַ������j��ǰ��k���ַ��뿪ͷ��k��
�ַ���ȣ���tj �� tk, 1��k < j����
��t0t1t2��, ��, tk - 1 �� = �� tj - ktj - k + 1tj - k + 2��tj - 1��
�� tj ��tk��1��k < j
(4)next[j] = 0����(1)��(2)��(3)�����������

/*
myself,���ݳ��ֿ����ԴӴ�С
(1)ģʽ��t���±�Ϊj���ַ������j��ǰ��k���ַ��뿪ͷ��k��
�ַ���ȣ���tj �� tk, 1��k < j,next[j]=k;
(2)ģʽ��t���±�Ϊj���ַ������j��ǰ��k���ַ��뿪ͷ��k��
�ַ���ȣ���tk=tj��t0��next[j]=0;
          ��tk=tj=t0,next[j]=-1;
(3)ģʽ��t���±�Ϊj���ַ������j��ǰ���κ�k���ַ��뿪ͷ��k��
�ַ�������ȣ���tk��t0,next[j]=0��
              ��tk=t0,next[j]=-1;
(4)next[0]=-1
*/

void GetNext(const char* T, int next[])
{     // ��ģʽ��T��next����ֵ
	int j = 0, k = -1;
	next[0] = -1;
	while (T[j] != '\0')
	{
		if (k == -1 || T[j] == T[k])
		{
			++j; ++k;
			if (T[j] != T[k])
				next[j] = k;
			else
				next[j] = next[k];
		}// if
		else
			k = next[k];
	}// while
}  // GetNext��

//?????????�����
void GetNext(const char* T, int next[])
{     // ��ģʽ��T��next����ֵ
	int j = 0, k = -1;
	next[0] = -1;
	while (T[j] != '\0')
	{
		if (k == -1 || T[j] == T[k])
		{
			++j; ++k;
			if (T[j] != T[k])
				next[j] = k;
			else
				next[j] = next[k];
		}// if
		else
			k = next[k];
	}// while
}  // GetNext��

int  KMP(char* s, char* t, int  next[])
{
	int  index = 0, i = 0, j = 0;
	if (!s || !t || t[0] == '\0' || s[0] == '\0')
		return -1; //��ָ���մ�������-1
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			++i; ++j;
		} // �����ȽϺ���ַ�
		else
		{
			index += j - next[j];//��¼����λ��
			if (next[j] != -1)   j = next[j]; // ģʽ������
			else { j = 0; ++i; }
		}
	}//while
	return((t[j] == '\0') ? Index : -1);  // ƥ��ʧ��
}  //KMP

