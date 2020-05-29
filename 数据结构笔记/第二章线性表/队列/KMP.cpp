//查找：暴力搜索：时间复杂度O（m*n）
//      KMP：O（m+n)

next函数：
(1)next[0] = -1，任何串的第一个字符的模式值规定为 - 1
(2)next[j] = -1，模式串t中下标为j的字符，如果与首字符相同，且j的前面的
1—k 个字符与开头的1..k 个字符不等(或者相等但t[k] == t[j]),
1≤k < j
如：t = ”abCabCad” 则 next[6] = -1，因t[3] = t[6]
(3)next[j] = k，模式串t中下标为j的字符，如果j的前面k个字符与开头的k个
字符相等，且tj ≠ tk, 1≤k < j，即
“t0t1t2…, …, tk - 1 ” = “ tj - ktj - k + 1tj - k + 2…tj - 1”
且 tj ≠tk，1≤k < j
(4)next[j] = 0，除(1)、(2)、(3)的其他情况。

/*
myself,根据出现可能性从大到小
(1)模式串t中下标为j的字符，如果j的前面k个字符与开头的k个
字符相等，且tj ≠ tk, 1≤k < j,next[j]=k;
(2)模式串t中下标为j的字符，如果j的前面k个字符与开头的k个
字符相等：①tk=tj≠t0，next[j]=0;
          ②tk=tj=t0,next[j]=-1;
(3)模式串t中下标为j的字符，如果j的前面任何k个字符与开头的k个
字符都不相等：①tk≠t0,next[j]=0；
              ②tk=t0,next[j]=-1;
(4)next[0]=-1
*/

void GetNext(const char* T, int next[])
{     // 求模式串T的next函数值
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
}  // GetNext　

//?????????不清楚
void GetNext(const char* T, int next[])
{     // 求模式串T的next函数值
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
}  // GetNext　

int  KMP(char* s, char* t, int  next[])
{
	int  index = 0, i = 0, j = 0;
	if (!s || !t || t[0] == '\0' || s[0] == '\0')
		return -1; //空指针或空串，返回-1
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			++i; ++j;
		} // 继续比较后继字符
		else
		{
			index += j - next[j];//记录右移位数
			if (next[j] != -1)   j = next[j]; // 模式串右移
			else { j = 0; ++i; }
		}
	}//while
	return((t[j] == '\0') ? Index : -1);  // 匹配失败
}  //KMP

