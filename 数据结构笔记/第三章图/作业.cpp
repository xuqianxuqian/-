//6


//26
���ĵ�Ϊ1
��1������Floyd�㷨����ÿһ�Զ��������·������D��
0 19 15 34 29 25
2 0  17 25 10 27
6 4  0  14 14 10
0 0  0  0  0  0
0 0  0  15 0  0
0 0  0  4  10 0
��2����ÿ�е����ֵ
6 19 17 34 29 27
��3����2��������Сֵ6
��ˣ����ĵ�Ϊ1

//30
void myBFS(LIST L,int n) {
	//n������
	STACK S;//����һ������ջ
	int w;//�ڵ�ı��
	int visited[n];
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	i = 0;
	visited[i] = 1;
	visit(i);//���ʸ��ڵ�
	for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
		Push(w, S);//�����ڵ�������ڽӵ�ѹջ
	while (!IsEmpty(S))
	{
		i = Top(S);
		if (visited[i] == 0) {
			visit(i);
			visited[i] = 1;
			Pop(S);
			for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
				Push(w, S);//���ýڵ�������ڽӵ�ѹջ
		}
		if(visited[i]==1)
			Pop(S);
		
	}


}
