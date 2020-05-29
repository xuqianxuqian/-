//���Բ���
//�۰����
//��������������������˳���źã�
//�ֿ����
Keytype k; int last, blocks; index ix; LIST F; int L;
int index_search(k, last, blocks, ix, F, L)
{
	int i, j;
	int i = 0;
	while (k > ix[i] && i < blocks) i++;
	if (k>ix[i]) {
		j = i * L
			while (k != F[j].key && j <= (i + 1) * L - 1 && j < last) {
				j++;
				if (k == F[j].key) return j;
			}
	}
	return -1;
 }

//���������
struct celltype {
	records data;
	celltype* lchild, * rchild;
};
typdef celltype* BST;
//&����
BST search(keytype k, BST F)
{
	BST p;
	p = F;
	if (p == NULL)
		return NULL;
	if (p->date.key == k)
		return p;
	else if (K < p->date.key)
		return(search(k, p->lchild));
	else if (k > p->date.key)
		return(search(k, p->rchild));
}

//���룺����һ���ǲ�����Ҷ��λ
void In(keytype k, BST F)
{
	if (F == NULL)
	{
		F = new celltype;
		F->date = k;
		F->lchild = NULL;
		F->rchild = NULL;
	}
	else if (k < F->date)
		In(k, F->lchild);
	else if (k >= F->date)
		In(k, F->rchild);
}

//ɾ��
void delete(keytype k, BST F)
{
	//������������ڵ��滻ɾ���ڵ�
	if (F != NULL)
	{
		if (k < F->date.key)
			delete(k, f->lchild);
		else if (k>F->date.key)
			delete(k, f->rchild);
		//�ҵ���k�Ľڵ�
		else {
			if (F->rchild == NULL)
				F = F->lchild;
			if (F->lchild == NULL)
				F = F->rchild;
			else
				F->date = DeleteMin(F->rchild);
		}
	}
}

records DeleteMin(F)
{
	records tmp;
	BFS p,q;
	p = F;
	if (p->lchild != NULL)
	{
		p = p->lchild;
	}
	tmp = p->date;
	q = p;
	p = p->rchild;
	delete q;
	return tmp;
}

//AVL��
int unbalanced = FALSE;
struct Node {
	Elementtype data;
	int bf;//ƽ�����ӣ�-1,0,1λl�������߶ȼ�ȥ�������߶�
	struct Node* lchild, * rchild;
};
typedef Node* AVLT;

unbalanced = TRUE;
void AVLInsert(AVLT T, Elementtype R, int &unbalanced) {
	if (T == NULL) {
		unbalanced = TRUE;
		T = new Node;
		T->date = r;
		T->lchild = NULL;
		T->rchild = NULL;
		T->bf = 0;
	}
	else if (R.key < T->date.key)
	{
		ALVInsert(T->lchild, r, &unblanced);
		if(unbalanced)//����bf
			switch (T->bf) {
			case -1:T->bf = 0;
				unbalanced = FALSE;//�����жϵݹ��ȥ�Ƿ���Ҫ�ı�bf�������FALSE���������������������߶�<��������bfȡ����������
				break;
			case 0:T->bf = 1;
				break;
			case 1:
				LeftRotation(T, &unbalanced);
			}
	}
	else if (R.key > = T->data.key)     //���������ϲ���
	{
		AVLInsert(T->rchild, R,&unbalanced);
		if (unbalanced)//����bf
			switch (T->bf) {
			case   1:  T->bf = 0;
				unbalanced = FALSE;//����ͬ�ϡ��ж�bfȡ����������������������������˵ݹ��ȥbf���øı�
				break;
			case 0:   T->bf = -1;
				break;
			case -1:   RightRotation(T, &unbalanced);
			}
	}
	else
		unbalanced = FALSE;
}   //AVLInsert

void   LeftRotation(AVLT T, int& unbalanced)
{
	AVLT gc, lc;
	lc = T->lchild;//��ʱֻ�������������lc->bfΪ-1��1
	if (lc->bf == 1)//LL��ת�����Ϊ1������������������������ɲ�ƽ��
	{
		T->lchild = lc->rchild;
		lc->rchild = T;
		T->bf = 0;
		T = lc;
	}
	else
	{
		gc = lc->rchild;  
		lc->rchild = gc->lchild;
		gc->lchild = lc;
		T->lchild = gc->rchild;
		gc->rchild = T;
		switch (gc->bf) {
		case 1:
			T->bf = -1;
			lc->bf = 0;
			break;
		case 0:
			T->bf = 0;
			lc->bf = 0;
		case -1:
			T->bf = 0;
			lc->bf = 1;
		}
		T = gc;

	}
	T->bf = 0;
	unbalanced = FALSE;
}

void RightRotation(AVLT T, &unbalanced) {
	AVLT rc, gc;
	rc = T->rchild;//Ҳ��ֻ��Ϊ1.-1
	if (rc->bf == -1)//RR��ת
	{
		T->rchild = lc->lchild;
		rc->lchild = T;
		T->bf = 0;
		T = rc;
	}
	else
	{
		gc = rc->lchild;
		rc->lchild = gc->rchild;
		gc->rchild = rc;
		T->lchild = gc->lchild;
		gc->lchild = T;
		switch (gc->bf) {
			case -1:
				T->bf = 1;
				rc->bf = 0;
				break;
			case 0:
				T->bf = 0;
				rc->bf = 0;
				break;
			case 1:
				T->bf = 0;
				rc->bf = -1;
		}
		T = gc;
	}
	T->bf = 0;
	unbalanced = FALSE;

}


//�ж϶������Ƿ�Ϊƽ�������
int isAVL(AVLT* T) {
	int hl, hr;
	if (T == NULL)
	{
		return(1);
	}
	else {
		hl = Depth(T->lchild);
		h2 = Depth(T->rchild);
		if (abs(h1 - h2) <= 1) {
			isAVL(T->lchild);
			if (isAVL(T->lchild))
				return(isAVL(T->rchild));
		}
		else return(0);
	}
}

int Depth(AVLT* bt) {
	int ldepth, rdepth;
	if (bt == NULL) {
		return(0);
	}
	else
	{
		ldepth = Depth(bt->lchild);
		rdepth = Depth(bt->rchild);
		if (ldepth > rdepth)
			return(ldepth + 1);
		else
			return(rdepth + 1);
	}
}
//B��API
#define MAX 1000
#define MIN 500
typdef int KeyType;
typedef struct node {
	int keynum;//�ؼ��ָ���
	KenType key[MAX + 1];//�ؼ�������key[1...keynum],key[0]����
	struct node* parent;
	struct node* son[MAX+1];
};
typdef struct node* BTree;

//����
BTreeNode* SearchBTree(Btree T, KeyType K, int* pos) {
	int i;
	T->key[0] = k;
	for (i = T->keynum; K < T->key[i]; i--) {
		if (i > 0 && T->key[i] == K) {
			pos = i;//λ��
			return(T);
		}
		if (!T->son[i]) {
			return NULL;
		}
		DiskRead(T->son[i]);//�ڴ����϶�����һ���ҵ����ڵ㵽�ڴ���
		return SearchBTree(T->son[i], k, &pos);
	}
}