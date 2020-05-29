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
visit(x)://���x

//�������
void PreOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		visit(Date(BT));
		PreOrder(Lchild(BT));
		PreOrder(Rchild(BT));
	}
}

//��������ǵݹ��㷨��˳��ṹջ
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
			printf("ջ��!\n");
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


//�������
//$1�ݹ�
void InOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		InOrder(Lchild(BT));
		visit(Date(BT));
		InOrder(Rchild(BT));
	}
}
//$2ջ
//��ʽ�ṹ��ջ
struct stack {
	struct tree *T;//����������ڵ�ָ��
	stack* next;
};
typedef struct stack* STACK;
void SrackInorder(BTREE BT) {
	STACK S;//����һ��ջS
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
			T = Lchild(T);//��һ��
		}
		else {
			T = Top(S);
			Pop(S);
			visit(Date(T));
			T = Rchild(T);//��һ��
		}
	}
}
//˳�����飩�ṹ��ջ
void  InOrder(BTREE* root
	{ BTREE * stack[MAX];
	   int top = 0;
	   do {
		 while (root != Null)
{
top++;
			if (top > MAX)
printf("ջ��!\n");
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


//�������
PostOrder(BTREE BT) {
	if (!IsEmpty(BT)) {
		PostOrder(Lchild(BT));
		PostOrder(Rchild(BT));
		visit(Date(BT));
	}
}

//����
����һ��
BTREE CreateBT(element v, BTREE ltree, BTREE rtree) {
	BTREE root;
	root = New Node;
	root->date = v;
	root->Lchild = ltree;
	toot->Rchild = rtree;
	return root;
}
��������
BTREE* Setup3(BTREE* bt, int n)        //�����ʴ�ʽ����������
{
	char ch;
	if (n == 0)    printf("�����:");
	fflush(stdin); scanf("%ch", &ch); fflush(stdin);
	if (ch != '#')
	{
		n = 1;
		bt = New BNODE;
		bt->data = ch;
		bt->lchild = Null;
		bt->rchild = Null;
		printf("%c ��������:", bt->data);
		bt->lchild = Setup3(bt->lchild, n);
		printf("%c ���Һ�����:", bt->data);
		bt->rchild = Setup3(bt->rchild, n);
	}
	return(bt);
}



//���������������->����
Struct QUEUE{
	//����һ�����У�����Ԫ������ָ��
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
{     //��������Ŀ�� 
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

//����������������
struct BiTPNode {
	ElementType date;
	struct BiTPNode* parent.*Lchild, * Rchild;
};

void InOrder(TriTree PT, void (*visit)(TElemType))
{
	TriTree p = PT, pr;
	while (p)
	{
		if (p->lchild)   p = p->lchild;  //��������
		else {
			visit(p->data);              //��������ڵ�
			if (p->rchild)   p = p->rchild; //��������������������������                              
			else {
				pr = p;             //���򷵻��丸��
				p = p->parent;
				while (p && (p->lchild != pr || !p->rchild))
				{
					if (p->lchild == pr)    visit(p->data);
					pr = p; //�����ѱ����ʣ��ʷ�����һ��
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

//����������
struct LNode {
	Elementtype date;
	Struct LNode* lchild, * rchild;
	int ltag, rtag;//Ϊ1��ָ�����Һ��ӣ�Ϊ0��ָ��ǰ����̣�����
};
typedef struct LNode* THTREE;

//��ʼ��,��һ��ͷ���
head->lchild = T;
head->rchild = head;
head->ltage = 1;
head->rtage = 1;

//������Ϊ��
head->lchild = head;
head->rchild = head;
head->ltag = 0;
head->rtag = 1;

//�����������㷨
Status   InOrderThreading(THTREE& Thrt, THTREE  T)
{
	if (!(Thrt = (THTREE)malloc(Sizeof(LNode))))  exit(OVERFLOW); //ͷ���
	Thrt->ltag = 1; Thrt->rtag = 1;
	Thrt->rchild = Thrt;                                               //��ָ���ָ
	if (!T) { Thrt->lchild = Thrt; Thrt->ltag = 0; }    //��������������ָ���ָ
	else {
		Thrt->lchild = T;      pre = Thrt;
		InThreading(T);                                       //����������
		Pre->rchild = Thrt;   pre->rtag = 0;      //�����������
		Thrt->rchild = pre;     //����һ�ֶ��巽ʽ                                          
	}
	return OK;
}
Void InThreading(THTREE p)
{
	if (p)
	{
		InThreading(p->lchild);                                                //������������
		if (!p->lchild) { p->ltag = 0;  p->lchild = pre; }     //������
		if (!pre->rchild) { pre->rtag = 0; pre->rchild = p; }  //������
		pre = p;                                                   //pre ָ�� p ��ǰ��
		InThreading(p->rchild);                                               //������������
	}
}

//��������

THTREE InNext(THTREE p) {
	THTREE Q;
	Q = p->rchild;
	if (p->rtag == 1) {
		while (Q->ltag == 1)
			Q = Q->lchild;   //������������ڵ�
		return(Q);
	}
}

THTREE InPre(THTREE p) {
	//ǰ��
	THTREE Q;
	Q = p->lchild;
	if (p->ltag == 1) {
		while (Q->rtag == 1)
			Q = Q->rchild;   //�����������ҽڵ�
		return(Q);
	}
}

//��InNext�����������������
void THInorder(THTREE HEAD/*ͷ���*/) {
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

//�ж��������Ƿ�ȼ�
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

//�������ĸ���
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


//��
define Maxsize 200
typedef struct {
	int key;
}ElemenType;
typedef struct {
	ElementType elements[MaxSize];//һ��Ԫ��Ϊ�ṹ�������
	int n;//ָʾԪ�ص�λ��
}HEAP;
void MaxHeap(HEAP heap) {
	//����һ���ն�
	heap.n = 0;
} 
bool HeapFulls(HEAP heap) {
	//�ж϶��Ƿ���
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
			temp = heap.elements[n];//�������һ��Ԫ�ص�ֵ
			heap.n--;//ɾ�������һ��Ԫ��
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

//��
//$1�����ʾ
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
//�ڽӱ��ʾ
typedef int node;
struct celltype {
	node elemnet;
	celltype* next;
};
//һ����������ýڵ�ı�ţ�ָ����һ�ڵ㣬�������򹹳�����ӽڵ���
typedef celltype* LIST;
typedef celltype* position;
struct TREE {
	LIST header[maxnodes];
	datatype data[maxnodes];
	node root;
};
//һ���ṹ�壬������������һ������Ԫ��Ϊ�ڵ��ţ���һ����Ԫ��Ϊÿ���ڵ������
node LeftMostChild(node n, TREE T) {
	//nΪ�ýڵ��ţ�TΪһ���ṹ��
	LIST L;
	L = T.header[n];
	if (Empty(L))
		return 0;
	else
		return(Retrieve(First(L), L));
}


//����Ӧ��
//$1���ϱ�ʾ
#define n Ԫ�ظ���
typedef int MFSET[n + 1];//����һ�������ʾ��������/���ױ�ʾ����������ÿ��Ԫ��Ϊint
void Union(i, j, parent) {
	//�ϲ�
	parent[i] = j;
}

int Find(int i, MFSET parent) {
	//Ѱ��
	int temp;
	temp = i;
	while (parent[temp] > 0)
		temp = parent[temp];
	return temp;
}

//��������˻������ϲ�ʱ���ڵ��ٵĺϲ����ڵ�����
struct node {
	int parent;
	int count;
};

typedef node MFSET[n + 1];
void Union(int A, int B, MFSET C) {
	//��AB���Ϻϲ�
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
	//ʹ����Aֻ����һ��Ԫ��A
	C[A].parent = 0;
	C[A].count = 1;
}

//�ȼ۷����㷨
void E(MFSET S) {
	int i, j, m, k;
	for (i = 1; i <= n + 1; i++)
		Initial(i, S)
	cin >> i; cin >> j;//�����һ���ȼ۶�
	while (!(i == 0 && j == 0)) {
		k = Find(i, S);
		m = Find(j, S);
		if (k != m)
			Union(i, j, S);
		cin >> i; cin >> j;
	}

}


//��������
//&1����
#define n 100
#define m 2*n -1 //n��Ҷ�ӵĹ�����������Щ�ڵ�
typedef struct {
	//�ڵ���
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
	InitHT(T);//�������ݣ�����parent��lchild��rchild=-1,0~n-1
	for (i = n; i < m; i++)
	{
		SelectMin(T, i - 1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].weight = T[p1].weight + T[p2].weight;
		T[i].lchild = p1;
		T[i].rchild = p2;
	}
}

//$2 ����ʵ��
�Ƚ������һ������H��Ȩ����������
void Huffman(HTREE* H) {
	THTREE* p, * q, * r
		while (H->next->next != NULL) {
			p = H->next;
			q = H->next;
			r = (HTREE*)malloc(sizeof(struct HNODE));
			if (!r) { printf("***�ڴ����!\n");    exit(0); }
			r->data = p->data + q->data;
			r->lev = (p->lev > q->lev ? p->lev + 1 : q->lev + 1);
			p->lev = q->lev = r->lev - 1;
			r->lchild = p;
			r->rchild = q;
			Insert(H, r);
       //��������������������������
		}
}

void Insert(HTREE*& H, HTREE* q)
//����������в���һ����㣬����Ȩ�ĺ�����
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

//����������
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

//�ж���
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
//��x���׼Ӳ��z���бȽ�
{
	if (x > z)
		cout << x << "Heavy!";
	else
		cout << y << "Light!";
}//Comp















