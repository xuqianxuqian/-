//ADT
struct Node{
	Struct Node* lchild;
	Struct Node* rchild;
	datatype data;
};
Typedef struct Node* BTREE;
Empty(BT);
IsEmpty(BT);
CreateBT(V, LT, RT);
Lchild(BT);
Rchild(BT);
Date(BT);
visit(x)://输出x

//先序访问
void PreOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		visit(Date(BT));
		PreOrder(Lchild(BT));
		PreOrder(Rchild(BT));
	}
}

//先序遍历非递归算法：顺序结构栈
struct stack {
	int top;
	struct Node * Elementtype[MAX];
};
void  PreOrder(BTREE* root
	{ BTREE * stack[MAX];
		   int top = 0;
	do {
	   while (root != Null)
		{
			 printf("%c ",Data(root));
				top++;
			if (top > MAX)
			printf("栈满!\n");
			else stack[top] = root;
			root = Lchild(root);
		}
			  if (top != 0)
			{
				root = stack[top];
					   top--;
					   root = Rchild(root);
			}
	} while ((top != 0) || (root != Null));
}


//中序访问
//$1递归
void InOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		InOrder(Lchild(BT));
		visit(Date(BT));
		InOrder(Rchild(BT));
	}
}
//$2栈
//链式结构的栈
struct stack {
	struct tree *T;//！！！保存节点指针
	stack* next;
};
typedef struct stack* STACK;
void SrackInorder(BTREE BT) {
	STACK S;//定义一个栈S
	BTREE T;
	MakeNull(S);
	T = BT;
	if (!IsEmpyt(T)) {
		Push(T,S);
		T = Lchild(T);
	}
	while (!IsEmpty(S)|| !IsEmpty(T)) {
		if (!IsEmpty(T)) {
			Push(T,S);
			T = Lchild(T);//左一步
		}
		else {
			T = Top(S);
			Pop(S);
			visit(Date(T));
			T = Rchild(T);//右一步
		}
	}
}
//顺序（数组）结构的栈
void  InOrder(BTREE* root
	{ BTREE * stack[MAX];
	   int top = 0;
	   do {
		 while (root != Null)
{
top++;
			if (top > MAX)
printf("栈满!\n");
			   else
			  stack[top] = root;
			root = Lchild(root);
		  }
		 if (top != 0)
		 {
				root = stack[top];
				top--;
				printf("%c ",Data(root));
				root = Rchild(root);
}
 } while ((top != 0) || (root != Null));
	}


//后序访问
PostOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		PostOrder(Lchild(BT));
		PostOrder(Rchild(BT));
		visit(Date(BT));
	}
}

//建立
方法一：
BTREE CreateBT(element v, BTREE ltree, BTREE rtree) {
	BTREE root;
	root = New Node;
	root->date = v;
	root->Lchild = ltree;
	toot->Rchild = rtree;
	return root;
}
方法二：
BTREE* Setup3(BTREE* bt, int n)        //交互问答方式创建二叉树
{
	char ch;
	if (n == 0)    printf("根结点:");
	fflush(stdin); scanf("%ch", &ch); fflush(stdin);
	if (ch != '#')
	{
		n = 1;
		bt = New BNODE;
		bt->data = ch;
		bt->lchild = Null;
		bt->rchild = Null;
		printf("%c 的左孩子是:", bt->data);
		bt->lchild = Setup3(bt->lchild, n);
		printf("%c 的右孩子是:", bt->data);
		bt->rchild = Setup3(bt->rchild, n);
	}
	return(bt);
}



//按层序遍历二叉树->队列
Struct QUEUE{
	//建立一个队列，队列元素是树指针
	Struct node * date[maxlength];
	int front;
	int rear;
};
void LeverList(BTREE T) {
	QUEUE Q;
	BTREE p = T;
	MakeNull(Q);
	if (T) {
		EnQueue(p,Q);
		while (!IsEmpty(Q)) {
			p = DeQueue(Q);
			visit(Date(p));
			if (p->Lchild) EnQueue(p->Lchild, Q);
			if (p->Rchild) EnQueue(p->Lchild, Q);
		}
	}
}

int Width(BTREE* T)
{     //求二叉树的宽度 
	int i, n = 0, front = 0, rear = 0, max = 0, lev = 1, maxlev[10] = { 0 };
	struct W {
		BTREE* Node;
		int Nodelev;
	} Q[50];
	Q[front].Node = T;       Q[front].Nodelev = 1;
	while (front <= rear)
	{
		if (Q[front].Node->lchild)
		{
			Q[++rear].Node = Q[front].Node->lchild;
			Q[rear].Nodelev = Q[front].Nodelev + 1;
		}
		if (Q[front].Node->rchild)
		{
			Q[++rear].Node = Q[front].Node->rchild;
			Q[rear].Nodelev = Q[front].Nodelev + 1;
		}
		front++;
	}
	for (i = 0; i <= rear; i++)     maxlev[Q[i].Nodelev]++;
	for (i = 0; i < 10; i++)
		if (max < maxlev[i])            max = maxlev[i];
	return(max);
}

//二叉树的三叉链表
struct BiTPNode {
	ElementType date;
	struct BiTPNode* parent.*Lchild, * Rchild;
};

void InOrder(TriTree PT, void (*visit)(TElemType))
{
	TriTree p = PT, pr;
	while (p)
	{
		if (p->lchild)   p = p->lchild;  //找最左结点
		else {
			visit(p->data);              //访问最左节点
			if (p->rchild)   p = p->rchild; //若有右子树，找右子树最左结点                              
			else {
				pr = p;             //否则返回其父亲
				p = p->parent;
				while (p && (p->lchild != pr || !p->rchild))
				{
					if (p->lchild == pr)    visit(p->data);
					pr = p; //父亲已被访问，故返回上一级
					p = p->parent;
				}
				if (p) {
					visit(p->data);
					p = p->rchild;
				}
			}
		}
	}
}

//线索二叉树
struct LNode {
	Elementtype date;
	Struct LNode* lchild, * rchild;
	int ltag, rtag;//为1，指向左右孩子，为0，指向前驱后继（中序）
};
typedef struct LNode* THTREE;

//初始化,有一个头结点
head->lchild = T;
head->rchild = head;
head->ltage = 1;
head->rtage = 1;

//线索树为空
head->lchild = head;
head->rchild = head;
head->ltag = 0;
head->rtag = 1;

//中序线索化算法
Status   InOrderThreading(THTREE& Thrt, THTREE  T)
{
	if (!(Thrt = (THTREE)malloc(Sizeof(LNode))))  exit(OVERFLOW); //头结点
	Thrt->ltag = 1; Thrt->rtag = 1;
	Thrt->rchild = Thrt;                                               //右指针回指
	if (!T) { Thrt->lchild = Thrt; Thrt->ltag = 0; }    //若二叉树空则左指针回指
	else {
		Thrt->lchild = T;      pre = Thrt;
		InThreading(T);                                       //中序线索化
		Pre->rchild = Thrt;   pre->rtag = 0;      //最后结点线索化
		Thrt->rchild = pre;     //另外一种定义方式                                          
	}
	return OK;
}
Void InThreading(THTREE p)
{
	if (p)
	{
		InThreading(p->lchild);                                                //左子树线索化
		if (!p->lchild) { p->ltag = 0;  p->lchild = pre; }     //左线索
		if (!pre->rchild) { pre->rtag = 0; pre->rchild = p; }  //右线索
		pre = p;                                                   //pre 指向 p 的前驱
		InThreading(p->rchild);                                               //右子树线索化
	}
}

//求中序后继

THTREE InNext(THTREE p) {
	THTREE Q;
	Q = p->rchild;
	if (p->rtag == 1) {
		while (Q->ltag == 1)
			Q = Q->lchild;   //右子树的最左节点
		return(Q);
	}
}

THTREE InPre(THTREE p) {
	//前驱
	THTREE Q;
	Q = p->lchild;
	if (p->ltag == 1) {
		while (Q->rtag == 1)
			Q = Q->rchild;   //左子树的最右节点
		return(Q);
	}
}

//用InNext中序遍历线索二叉树
void THInorder(THTREE HEAD/*头结点*/) {
	THTREE temp;
	temp = InNext(HEAD);
	while (temp != HEAD) {
		visit(Date(temp));
		temp = InNext(temp);
	}

	/*
	temp = HEAD ;
     do {
             temp = InNext ( temp ) ;
             if ( temp != HEAD )
                 visit ( temp -> data ) ;
      } while ( temp != HEAD ) ;

	*/

}

//判断两个树是否等价
int   Equal(firstbt, secondbt)
BTREE  firstbt, secondbt;
{  int  x;
x = 0;
if (IsEmpty(firstbt) && IsEmpty(secondbt))
x = 1;
else if (!IsEmpty(firstbt) && !IsEmpty(secondbt))
if (Data(firstbt) == Data(secondbt))
if (Equal(Lchild(firstbt), Lchild(secondbt)))
x = Equal(Rchild(firstbt), Rchild(secondbt))
return(x);
} /* Equal */

//二叉树的复制
BTREE   Copy(BTREE   oldtree)
{
	BTREE   temp;
	if (oldtree != Null)
	{
		temp = New  Node;
		temp->lchild = Copy(oldtree->lchild);
		temp->rchild = Copy(oldtree->rchild);
		temp->data = oldtree->data;
		return (temp);
	}
	return (Null);
}  /* Copy*/


//堆
define Maxsize 200
typedef struct {
	int key;
}ElemenType;
typedef struct {
	ElementType elements[MaxSize];//一个元素为结构体的数组
	int n;//指示元素的位置
}HEAP;
void MaxHeap(HEAP heap) {
	//创建一个空堆
	heap.n = 0;
} 
bool HeapFulls(HEAP heap) {
	//判断堆是否满
	return(heap.n == = MaxSize - 1);
}

void Insert(HEAP heap, Elementtype element) {
	int i;
	if (!HeapFull(heap)) {
		i = heap.n + 1;
		while ((i != 1) && (element > heap->elements[i / 2]) {
			heap->elements[i] = heap->elements[i / 2];
		}
		heap->elements[i] = element;
	}
}
void DeleteMax(HEAP heap) {
	int parent = 1, child = 2;
	Elementtype element, tmp;
		if (!HeadEmpty(heap)) {
			element = heap.elements[1];
			temp = heap.elements[n];//保留最后一个元素的值
			heap.n--;//删除了最后一个元素
			while ((child <= heap.n) && (heap.element[child] < heap.element[child + 1])
				child++;
			if (tmp > heap.element[child]) break;
			head. element[parent] = head.element[child];
			parent = child;
			child = child * 2;
		}
		head.element[parent] = tmp;
		return element;
}

//树
//$1数组表示
struct node {
	int parent;
	char date;
};


typedef struct node TREE[maxlnodes];
TREE T;

node LeftMostChild(int n, TREE T) {
	int i;
	for (i = n + 1; i < maxnodes - 1; i++) {
		if (T[i].parent == n)
			return i;
		retirn 0;
	}
}
//邻接表表示
typedef int node;
struct celltype {
	node elemnet;
	celltype* next;
};
//一个链表，储存该节点的标号，指向下一节点，按照升序构成其儿子节点链
typedef celltype* LIST;
typedef celltype* position;
struct TREE {
	LIST header[maxnodes];
	datatype data[maxnodes];
	node root;
};
//一个结构体，有两个数组域，一个数组元素为节点标号，另一数组元素为每个节点的数据
node LeftMostChild(node n, TREE T) {
	//n为该节点标号，T为一个结构体
	LIST L;
	L = T.header[n];
	if (Empty(L))
		return 0;
	else
		return(Retrieve(First(L), L));
}


//树的应用
//$1集合表示
#define n 元素个数
typedef int MFSET[n + 1];//定义一个数组表示树（数组/父亲表示法），数组每个元素为int
void Union(i, j, parent) {
	//合并
	parent[i] = j;
}

int Find(int i, MFSET parent) {
	//寻找
	int temp;
	temp = i;
	while (parent[temp] > 0)
		temp = parent[temp];
	return temp;
}

//避免产生退化树，合并时将节点少的合并到节点多的上
struct node {
	int parent;
	int count;
};

typedef node MFSET[n + 1];
void Union(int A, int B, MFSET C) {
	//将AB集合合并
	if (C[A].count > C[B].conut) {
		C[B].parent = A;
		C[A].count += C[B].count;
	}
	else {
		C[A].parent = B;
		C[B].count += C[A].count;
	}
}
int Find(int x, MFSET C) {
	int f;
	f = x;
	while (C[f].parent > 0)
		f = C[f].parent;
	return(f);
}
void Initial(int A, MFSET C) {
	//使集合A只包含一个元素A
	C[A].parent = 0;
	C[A].count = 1;
}

//等价分类算法
void E(MFSET S) {
	int i, j, m, k;
	for (i = 1; i <= n + 1; i++)
		Initial(i, S)
	cin >> i; cin >> j;//读入第一个等价对
	while (!(i == 0 && j == 0)) {
		k = Find(i, S);
		m = Find(j, S);
		if (k != m)
			Union(i, j, S);
		cin >> i; cin >> j;
	}

}


//哈夫曼树
//&1数组
#define n 100
#define m 2*n -1 //n个叶子的哈夫曼树共这些节点
typedef struct {
	//节点型
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNODE;
typedef HTYODE Huffman T[m];
viod SelectMin(Huffman T, int n, int& p1, int& p2) {
	int i, j;
	for (i = 0; i <= n; i++) if (T[i].parent == -1) {*p1 = i; break; }
	for(j=i+1;j<n;j++) 
		if (T[j].parent == -1) { *p2 = j; break; }
	for (i = 0; i <= n; i++)
		if ((T[i].weight < T[*p1].weight) && T[i].parent == -1 && *p2 != i) *p1 = i;
	for (j = 0; j <= n; j++)
		if ((T[j].weight < T[*p2].weight) && T[j].weight == -1 && *p1 != j) *p2 = j;
}
void CreatHT(Huffman T) {
	int i, p1, p2;
	InitHT(T);//输入数据，其中parent，lchild，rchild=-1,0~n-1
	for (i = n; i < m; i++)
	{
		SelectMin(T, i - 1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].weight = T[p1].weight + T[p2].weight;
		T[i].lchild = p1;
		T[i].rchild = p2;
	}
}

//$2 链表实现
先建立完成一个链表H，权重升序排列
void Huffman(HTREE* H) {
	THTREE* p, * q, * r
		while (H->next->next != NULL) {
			p = H->next;
			q = H->next;
			r = (HTREE*)malloc(sizeof(struct HNODE));
			if (!r) { printf("***内存错误!\n");    exit(0); }
			r->data = p->data + q->data;
			r->lev = (p->lev > q->lev ? p->lev + 1 : q->lev + 1);
			p->lev = q->lev = r->lev - 1;
			r->lchild = p;
			r->rchild = q;
			Insert(H, r);
       //哈夫曼树中序是正好升序排列
		}
}

void Insert(HTREE*& H, HTREE* q)
//向哈夫曼树中插入一个结点，保持权的和有序
{
	HTREE* p;
	p = H;
	while ((p->next != Null) && (p->next->data <= q->data))
		p = p->next;
	q->next = p->next;
	p->next = q;
}

void DelRoot(Huffman T) {
	HTNODE* p.*q;
	p=T;
	while (p != NULL) {
		p->date = RcLchild(p)->date;
		p = p->rchild;
	}
}

//二叉排列树
Struct CellType{
	int date;
celltype* lchild,* rchild;   
}
typedef CellType* BST;
BST search(keytype k, BST F) {
	p = F;
	if (p == NULL)
		return NULL;
	if (k == p->data)
		return p;
	if (k < p->date)
		return(search(k, p->lchild));
	else if (kp - < date)
		return(search(k, p->rchild));

}

void Insert(keytype k, BST* F) {
	BST* p;
	p = F;
	if (p == NULL) {
		p = Nem CellType;
		p->date = k;
		p->lchild = NULL;
		p->rchild = NULL;
	}
	else if (k < p->date)
		Insert(k, p->lchild);
	else if (k > p - < date)
		Insert(k, p->rchild);
}

//判断树
void EightCoins() {
	int a, b, c, d, e, f, g, h;
	switch (Compare(a + b + c, d + e + f)) {
	case '=':if (g > h)Com(g, h, a);
			else Com(h, g, a);
		break;
	case '>':
		switch (Compare(a + d, b + e)) {
		case '=':Com(c, f, a); break;
		case '>':Com(a, e, b); break;
		case '<':Com(d, b, a); break;
		}
		break;
	case '<':
		switch (Compare(a + d, b + e)) {
		case '=':Com(f,c, a); break;
		case '>':Com(d, b, a); break;
		case '<':Com(e, a, b); break;
		}
		break;
	}
}
char Compare(int a, int b)
{
	if (a < b) return('<');
	else if (a == b)
		return('=');
	else
		return('>');
}

void Comp(int x, int y, int z)
//将x与标准硬币z进行比较
{
	if (x > z)
		cout << x << "Heavy!";
	else
		cout << y << "Light!";
}//Comp















