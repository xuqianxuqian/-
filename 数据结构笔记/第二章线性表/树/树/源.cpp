//12
struct tree() {
	int lchild;
	int rchild;
	int level;//层数
}
typedef struct tree TREE;
TREE Tree[10];
Create(TREE* Tree);//创建完成
void Level(TERR Tree) {
	int i = 0;
	int height;//高度
	Tree[i].level = 1;
	for (i = 1; i <= 9; i++) {
		Tree[Tree[i].lchild].level = Tree[i].level + 1;
		Tree[Tree[i].rchild].lever = Tree[i].level + 1;
	}
	i = 1;
	height = Tree[i].leverl;
	for (i = 2; i <= 9; i++) {
		if(Tree[i].level>height) height = Tree[i].leverl;
	}
	
}

//13
节点类型：n2, n1, n0
n2 = n0 + 1;
n = n2 + n1 + n0 = 2n0 + n1 + 1 < 2 ^ h - 1, 
	故n0 < 2 ^ (h - 1) - 1 < 2 ^ (h - 1);
前h-1层（除去最后一层的叶节点），最多有2^(h-1)-1个节点
因此内部节点（除根节点和叶节点）<=2^(h-1)-2,即<2^(h-1)-1

//14
struct node
{
	int left;
	int right;
	int lw;
	int rw;
	int mw;
};
struct node TREE[10];
int n = 1;

int* MV(struct node TREE[10]) {

	int MV[10];
	for (; n <= 9; n++) {
		MV[n] = Maxway(TREE, n);
	}
	return(MV);
}

int Maxway(struct node* TREE,int n) {
	if (Tree[n].lw = Tree[n].rw = 0)
	{
		Tree[n].mv = 0;
		return(Tree[n].mv);
	}

			if (Tree[n].lw > Tree[n].rw) {
				Tree[n].mv = MAXway(TREE,TREE[n].left) + Tree[n].lw;
			}
			if (Tree[n].lw < Tree[n].rw) {
				Tree[n].mv = MAXway(TREE, TREE[n].right) + Tree[n].rw;
			}
			return(Tree[n].mv);

	}
}

//16

void Inorder(BTree bt)
{
	Position p = bt;
	while (p)
	{
		Position pLeft = p->lChild;
		if (pLeft)
		{
			while (pLeft->rChild && pLeft->rChild != p) //找到以p为根结点的树的最右孩子
				pLeft = pLeft->rChild;
			if (pLeft->rChild == NULL)   //线索化
			{
				pLeft->rChild = p;
				p = p->lChild;
				continue;
			}
			else                      //线索化后已被访问
			{
				pLeft->rChild = NULL; //释放指向根节点(祖先)的指针
			}
		}
		printf("%c ", p->data);       //打印
		p = p->rChild;                //向上回溯或者转向右子树
	}
	printf("\n");
}


//34
struct tree
{
	char date;
	struct tree* lchild, * rchild;
};
struct tree TREE;


void Publish(TREE* T) {
	if (Isempty(T)) { return NULL； }
	if (Issingle(T) {
		printf("(");
		printf("%c", T->date);
		printf(")");
	}
	else {
		printf("(");
		Publish(T->lchild);
		printf(",");
		Publish(T->rchild);
		printf(")") :
	}
}

//35
 


