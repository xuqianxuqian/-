//12
struct tree() {
	int lchild;
	int rchild;
	int level;//����
}
typedef struct tree TREE;
TREE Tree[10];
Create(TREE* Tree);//�������
void Level(TERR Tree) {
	int i = 0;
	int height;//�߶�
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
�ڵ����ͣ�n2, n1, n0
n2 = n0 + 1;
n = n2 + n1 + n0 = 2n0 + n1 + 1 < 2 ^ h - 1, 
	��n0 < 2 ^ (h - 1) - 1 < 2 ^ (h - 1);
ǰh-1�㣨��ȥ���һ���Ҷ�ڵ㣩�������2^(h-1)-1���ڵ�
����ڲ��ڵ㣨�����ڵ��Ҷ�ڵ㣩<=2^(h-1)-2,��<2^(h-1)-1

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
			while (pLeft->rChild && pLeft->rChild != p) //�ҵ���pΪ�������������Һ���
				pLeft = pLeft->rChild;
			if (pLeft->rChild == NULL)   //������
			{
				pLeft->rChild = p;
				p = p->lChild;
				continue;
			}
			else                      //���������ѱ�����
			{
				pLeft->rChild = NULL; //�ͷ�ָ����ڵ�(����)��ָ��
			}
		}
		printf("%c ", p->data);       //��ӡ
		p = p->rChild;                //���ϻ��ݻ���ת��������
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
	if (Isempty(T)) { return NULL�� }
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
 


