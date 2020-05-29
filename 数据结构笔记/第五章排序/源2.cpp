//5
不能。因为当U=L+1时，M=L保持不变，U=M或L=M也会一直保持不变，陷入死循环
修改如下：
（1）[初始化]L←1，U←N
（2）[求中点]如果U<L,查找不成功
				否则，M←（L+U)/2
（3）【比较】K<KM，转第四步
	K>KM，转第五步
	K=KM，查找成功		
（4）U←M-1，返回第二步
（5）L←M+1，返回第二步

//9
//（1）算法：
Void  Insert(Records  R, BST& F)
{//插入新节点/构造二叉查找树
	if (F == NULL)
	{
		F = new  CellType;
		F->data = R;
		F->lchild = NULL;
		F->rchild = NULL;
	}
	else  if (R.key < F->data.key)
		Insert(R, F->lchild)
	else  if (R.key >= F->data.key)
		Insert(R, F->rchild)
}
//删除节点
Void  Delete(keytype  k, BST& F)
{
	if (F != NULL)
		if (k < F->data.key)
			Delete(k, f->lchild);
		else if (k > F->data.key)
			Delete(k, f->rchild);
		else
			if (F->rchild == NULL)
				F = F->lchild;
			else if (F->lchild == NULL)
				F = F->rchild;
			else
				F->data = DeleteMin(F->rchild)
}
Records  DeleteMin(F)
{
	records tmp; BST  p;
	if (F->lchild == NULL)
	{
		p = F;
		tmp = F->data;
		F = F->rchild;
		Delete p;
		return tmp;
	}
	else
		return (DeleteMin(F->lchild);
}
(2)树：




//12
（1）算法
unbalanced = TRUE；
void AVLInsert(AVLT & T, ElementType R, int& unbalanced)
{
	if (!T)    //向空二叉树中插入元素
	{
		unbalanced = TRUE;
		T = new Node;
		T->data = R;
		T->lchild = T->rchild = NULL;
		T->bf = 0;
	}
	else if (R.key < T->data.key)          //在左子树上插入
	{
		AVLInser(T->lchild, R, unbalanced);
		if (unbalanced)
			switch (T->bf) {
			case -1:  T->bf = 0;
				unbalanced = FALSE;
				break;
			case 0:   T->bf = 1;
				break;
			case 1:   LeftRotation(T, unbalanced);
			}
	}
	else if (R.key > = T->data.key)     //在右子树上插入
	{
		AVLInsert(T->rchild, R, unbalanced);
		if (unbalanced)
			switch (T->bf) {
			case   1:  T->bf = 0;
				unbalanced = FALSE;
				break;
			case 0:   T->bf = -1;
				break;
			case -1:   RightRotation(T, unbalanced);
			}
	}
	else
		unbalanced = FALSE;
}   //AVLInsert
void   LeftRotation(AVL& T, int& unbalanced)
{
	AVLT  gc, lc;
	lc = T->lchild;
	if (lc->bf == 1)    //LL旋转
	{
		T->lchild = lc->rchild;
		lc->rchild = T;
		T->bf = 0;
		T = lc
	}
	else                               //LR旋转
	{
		gc = lc->rchild;
		lc->rchild = gc->lchild;
		gc->lchild = lc;
		T->lchild = gc->rchild;
		gc->rchild = T;
		switch (gc->bf) {
		case 1: T->bf = -1;
			lc->bf = 0;
			break;
		case 0: T->bf = lc->bf = 0;
			break;
		case -1:T->bf = 0;
			lc->bf = 1;
		}
		T = gc;
	}
	T->bf = 0;
	unbalanced = FALSE;
}
void RightRotation(AVLT*& T)
{
	AVLT* gc, * rc;
	rc = T->rchild;
	if (rc->bf == -1)                   //RR旋转
	{
		T->rchild = rc->lchild;
		rc->lchild = T;
		T->bf = 0;
		T = rc;
	}
	else                                    //RL旋转
	{
		gc = rc->lchild;
		rc->lchild = gc->rchild;
		gc->rchild = rc;
		T->rchild = gc->lchild;
		gc->lchild = T;
		switch (gc->bf) {      //调整平衡因子
		case -1: T->bf = -1;
			rc->bf = 0;
			break;
		case  0: T->bf = rc->bf = 0;
			break;
		case  1: T->bf = 0;
			rc->bf = -1;
		}
		T = gc;
	}
	T->bf = 0;
	unbalanced = FALSE;
}

（2）树：

//21

（1）

（2）假设每次访问磁盘读取一个节点并且每次都读取成功
 第一次：2次
  第二次：2次
	第三次：3次
	第四次：2次
	共9次

（3）


（4）
  2次：一次读，一次写。



