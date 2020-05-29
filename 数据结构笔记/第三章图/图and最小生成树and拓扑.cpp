//$1图的顺序存储——邻接矩阵

#define    INFINITY    INT_MAX
#define    MAX_VERTEX_NUM   20
Typedef   enum { DG, DN, AG, AN }  GraphKind;
Typedef   struct  ArcCell {
	VRType  adj;//顶点i，j间的邻接关系。取1或0.
	InfoType* info;//边的附加信息，为一个指针
}  ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

Typedef   struct {
	VertexType     vex[MAX_VERTEX_NUM];//顶点信息
	AdjMatrix      arcs;//一个结构体二维数组
	int            vexnum, arcnum;//顶点个数，边个数
	GraphKind       kind;
}  Mgraph;

int FirstAdjVex(MGraph G, VertexType v)
{  //返回值为图G中与顶点v邻接的第一个邻接点，0为没有邻接点
	VertexType  w = 0;
	while ((w < G.vexnum) && !G.arcs[v][w].adj)    w++;
	if ((w < G.vexnum) && G.arcs[v][w])     return(w);
	else    return(0);
}

int NextAdjVex(MGraph G, VertexType v, VertexType w)
{  //返回值为图G中与顶点v邻接的w之后的邻接点，0为无下一个邻接点
	w = v + 1;
	while ((w < G.vexnum) && !G.arcs[v][w].adj)     w++;
	if ((w < G.vexnum) && G.arcs[v][w])      return(w);
	else     return(0);
}

//$图的链式存储——邻接表
#define   MAX_VERTEX_NUM   20
Typedef   struct   ArcNode {
	int      adjvex;   //在头节点中的下标   
	struct   ArcNode* nextarc;//指向的下一节点
	InfoType* info; 
}  ArcNode;//表节点

Typedef   struct  Vnode {
	//头结点
	VertexType     data;   //节点数据
	ArcNode* firstarc;//头结点的下一个节点，即找到的与其相邻的节点
}  Vnode, AdjList[MAX_VERTEX_NUM];

Typedef   struct {
	AdjList     vertices;
	Int              vexnum;
	Int              kind;
}  ALGraph;

//顶点 i 的第一个邻接点 :
G.vertices[i].firstarc->adjvex；
G.vertices[G.vertices[i].firstarc->adjvex].data；
G.vertices[i].firstarc->info；

int FirstAdjVex(ALGraph G, VertexType v)
{      //返回值为图G中与顶点v邻接的第一个邻接点，0为没有邻接点
	if (G.vertices[v].firstarc)      return(G.vertices[v].firstarc->adjvex);
	else      return(0);
}
int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{      //返回值为图G中与顶点v邻接的w之后的邻接点，0为无下一个邻接点
	ArcNode* p;
	p = G.vertices[v].firstarc;
	while (p != NULL && p->adjvex != w)   p = p->nextarc;
	if (p)   return(0);
	else
		if (p->nextarc)	   return(p->nextarc->adjvex);
		else     return(0);
}

//￥深度优先遍历
void DFSTravers(GRAPH G,int v) {
	for (v = 0; v < G.vexnum; v++) visited[v] = FALSE;//标记节点被访问
	for (v = 0; v < G.vexnum; v++) if (!visit[v]) DFS(G, v);//如果有节点没被访问，换下个节点，使每个节点都被访问过
}
void DFS(GRAPH G, int v) {
	visited[v] = TRUE;
	visitfunc(v);
	for (w = First(G, v); w; w = NextAdjVex(G, v, w))//遍历每个邻接点
	{
		if (!visit[w]) DFS(G, w);//深度优先遍历每个相邻节点
	} 

}

//广度优先算法
Void   BFSTravers(GRAPH  G, v)
{
	For(v = 0; v < G.vexnum; ++v)  visited[v] = FALSE;
	InitQueue(Q);
	For(v = 0; v < G.vexnum; ++v)
		if (!visited[v])
		{
			visit(v);
			visited[v] = TRUE;
			EnQueue(Q, v);
			while (!QueueEmpty(Q))
			{
				DeQueue(Q, u);
				for (w = FirstAdjVex(G, u); w;
					w = NextAdjVex(G, u, w)
					if (!visited[w]) {
						visited[w] = TRUE;
							visit(w);
							EnQueue(Q, w);
					}
			}
		}
}

、、

//判断是否存在从u到v的路径，返回1或0
int ExistPathDfs1(ALGraph G, int* visited, int u, int v) {
	//递归：对u每个节点，看是否能找到到v的路
	ArcNode* p;
	int w;
	if (u == v) return(1);
	else
	{
		visited[u] = 1;
		for (p = G.vertices[u].firstarc; p = p->nextarc) {//遍历u的每个邻接点
			w = p->adjvex;
			if (!visited[w] && ExistPathDfs1(G, visited, w, v))//当w没有被访问过并且存在w到v的一条路径，如果没有找到在回退到u的下一个节点
				return(1);
		}
	}
	return(0);

}

//最小生成树
//prime算法
Cossttype C[n + 1][n + 1];//其中没有的边设为一个无穷大的数INFINITY1（和下面的无穷大的数不同）
void Prime(C) {
	//默认从1开始
int CLOSEST[n + 1];
costtype LOWCOST[n + 1];
int i, j, k;
costtype min;
for (i = 2; i <= n; i += ) {
	//初始化
	LOWCOST[i] = C[1][i];
	CLOSEST[i] = 1;
}

for (i = 2; i <= n; i++) {
	//一共有n-1条
	min = LOWCOST[i];
	k = i;
	for (j = 2; j <= nj++) {
		if (LOWCOST[j] < min) {
			min = LOWCOST[j];
			k = j;
		}
		Cout << “(” << k << “, ” << CloseST[k] << “)” << end1;
		LOWCOST[k] = INFINITY;
		for (j = 2; j <= n; j++) {
			if (C[k][j] < LOWCOST[j] && LOWCOST[j] != INFINITY) {
				LOCOST[j] = C[k][j];//一定是相邻两个之间最小的权，因此是U集合到该点最小的，再循环比较到这些点的路径
				CLOSEST[j] = k;//U中那ge点到改点权最小
			}
		}
	}
}
//Kruskal算法

Void   Kruskal(V, T)
{
	T = V;
	ncomp = n;    /*结点个数*/
	while (ncomp > 1)
	{
		从E中取出删除权最小的边（v, u）;
		if (v 和 u 属于T中不同的连通分量）
			{ T = T∪{ (v, u) }
								ncomp--;
			}
	}
}



//求关节点
Biconnected_Component(G) {
	T = ¢;
	count = 1;
	for (all v∈V) make v “new”;
	searchB(v0);//以任意顶点v构建深度优先生成树
}
Void searchB(v)
{
	(1)  make v “old”;
		(2)  dfn[v] = count;
	(3)  count++;
	(4)  low[v] = dfn[v];
	(5)  for (each w ∈ L[v])
		(6)      if (w is marked”new”)
		(7) {
		              add(v, w) to T;
		(8)           father[w] = v;       // 记下w的父亲v，用于回退边判断
		(9)           searchB(w);
		(10)           if (low[w] >= dfn[v])
			A biconnected component has been found;
		(11)           low[v] = min(low[v], low[w]);
	}
	(12)     else if (w is not father[v])    // (v ,w ) 是回退边
		(13)           low[v] = min(low[v], dfn[w]);//每次比较回退边顶点的dfn，获得最小值
}

//拓扑算法！！！
Status   Topologicalsort(ALGRAPH  G){
	FindInDegree(G, InDegree);//每个节点的入度
	MakeNull(S);
	for (v = 0; v < n; v++) {
		if (InDgree[v] == 0) Push(v, S);
	}
	count == 0;//记录输出节点个数
	while (!Empty(S)) {
		v = Pop(S);
		printf(v);
		count++;

		for (邻接于v的所每个顶点w) {
			InDgree(w)--;
			if (InDgree == 0) Push(w, S);
		}
	}
	if (count < n) cout << "图中有环路"
	else return OK;




}

Status   Topologicalsort(L)
//应用队列,顺序和栈的正好相反
{
	QUEUE  Q;
	MakeNull(Q);
	for (v = 1; v <= n; ++v)
		if (InDegree[v] = 0)  EnQueue(v, Q);
	nodes = 0;
	while (!Empty(Q))
	{
		v = Front(Q);
		DeQueue(Q);
		cout << v;   nodes++;
		for (邻接于 v 的每个顶点 w)
			if (!(--InDegree[w])) EnQueue(w, Q);
	}
	if (nodes < n)  cout << “图中有环路”;
}

//DFS深度遍历生成拓扑序列，生产的是拓扑序列倒序
Void  dfs - topo(GRAPH  L)
{
	MakeNull(S);
	for (u = 1; u <= n; u++)
		make[u] = FALSE;
	for (u = 1; u <= n; u++)
		if (!mark[u])
			topodfs(u);
}
Void topodfs(v)
{
	Push(v, S);//将遇到的顶点压栈
	mark[v] = TRUE;
	for (L[v] 中的每一个顶点w)  do
		if (mark[w] = FALSE)
			topodfs(w);
	printf(top(S));
	POP(S);//当该顶点的所有邻接点都找遍后，出栈输出
}


//单源最短路径
//Dijkstra算法
void Dijkstra(G, costtype D[MAXVEX + 1]) {
	int  S[MAXVEX + 1], P[MAXVEX + 1];//S表示已经找到的边集，最初只有1
	for (i = 1; i <= n; i++) {
		D[i] = G[1][i];
		S[i] = 0;
	}
	s[1] = 1;
	for (i = 2; i <= n; i++) {
		w = mincost(D, S);//找到D中最小的且没有在S中的
		s[w] = 1;
		for (j = 2; j <= n; j++) {
			if (s[j] == 0) {
				sum = s[w] + G[w][j];
				if (sum < D[j]) {
					D[j] = sum;
					P[j] = w;
				}
			}
		}
	}
}
void Display(int *P,int v){
	//输出v的最短路径
	if (P[v] != 1) {
		Display(P, P[v]);
		printf("%d--", p[v]);
	}


//Floyd算法，求任意两点之间最短路径
	void Floyd(A, C, n) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				A[i][j] = G[i][j];
				P[i][j] = 0;//用于输出最小路径，为零表示不用插入中间点
			}
		}
		for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++) {
				for (j = i; j <= n; j++) {
					sum = A[i][k] + A[k][j];
					if (sum < A[i][j]) {
						A[i][j] = sum;
						P[i][j] = k;
					}
				}
			}
		}//关键在于都是从小到大循环k，i,j，则保证A[i][k],A[j][k]都是最小的
	}
	void Path(i, j) {
		k = P[i][j];
		if (k != 0) {
			Path(i, k);
			count << k << endl;
			Path(k, j);
		}
	}

//求有向图中心点：
/*	算法步骤：
		第一步：调用Floyd算法，求每一对顶点间的最短路径矩阵D；
		第二步：对矩阵D的每一列求最大值，即为各顶点j的偏心度；
		第三步：求具有最小偏心度的顶点k，即为中心点。

*/




