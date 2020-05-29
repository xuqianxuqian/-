//6


//26
中心点为1
（1）调用Floyd算法，求每一对顶点间的最短路径矩阵D；
0 19 15 34 29 25
2 0  17 25 10 27
6 4  0  14 14 10
0 0  0  0  0  0
0 0  0  15 0  0
0 0  0  4  10 0
（2）求每列的最大值
6 19 17 34 29 27
（3）求（2）序列最小值6
因此，中心点为1

//30
void myBFS(LIST L,int n) {
	//n个顶点
	STACK S;//建立一个辅助栈
	int w;//节点的标号
	int visited[n];
	for (i = 0; i < n; i++) {
		visited[i] = 0;
	}
	i = 0;
	visited[i] = 1;
	visit(i);//访问根节点
	for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
		Push(w, S);//将根节点的所有邻接点压栈
	while (!IsEmpty(S))
	{
		i = Top(S);
		if (visited[i] == 0) {
			visit(i);
			visited[i] = 1;
			Pop(S);
			for (w = FirstAdjVex(G, i); w; w = NextAdjVex(G, i, w))
				Push(w, S);//将该节点的所有邻接点压栈
		}
		if(visited[i]==1)
			Pop(S);
		
	}


}
