//5
���ܡ���Ϊ��U=L+1ʱ��M=L���ֲ��䣬U=M��L=MҲ��һֱ���ֲ��䣬������ѭ��
�޸����£�
��1��[��ʼ��]L��1��U��N
��2��[���е�]���U<L,���Ҳ��ɹ�
				����M����L+U)/2
��3�����Ƚϡ�K<KM��ת���Ĳ�
	K>KM��ת���岽
	K=KM�����ҳɹ�		
��4��U��M-1�����صڶ���
��5��L��M+1�����صڶ���

//9
//��1���㷨��
Void  Insert(Records  R, BST& F)
{//�����½ڵ�/������������
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
//ɾ���ڵ�
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
(2)����




//12
��1���㷨
unbalanced = TRUE��
void AVLInsert(AVLT & T, ElementType R, int& unbalanced)
{
	if (!T)    //��ն������в���Ԫ��
	{
		unbalanced = TRUE;
		T = new Node;
		T->data = R;
		T->lchild = T->rchild = NULL;
		T->bf = 0;
	}
	else if (R.key < T->data.key)          //���������ϲ���
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
	else if (R.key > = T->data.key)     //���������ϲ���
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
	if (lc->bf == 1)    //LL��ת
	{
		T->lchild = lc->rchild;
		lc->rchild = T;
		T->bf = 0;
		T = lc
	}
	else                               //LR��ת
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
	if (rc->bf == -1)                   //RR��ת
	{
		T->rchild = rc->lchild;
		rc->lchild = T;
		T->bf = 0;
		T = rc;
	}
	else                                    //RL��ת
	{
		gc = rc->lchild;
		rc->lchild = gc->rchild;
		gc->rchild = rc;
		T->rchild = gc->lchild;
		gc->lchild = T;
		switch (gc->bf) {      //����ƽ������
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

��2������

//21

��1��

��2������ÿ�η��ʴ��̶�ȡһ���ڵ㲢��ÿ�ζ���ȡ�ɹ�
 ��һ�Σ�2��
  �ڶ��Σ�2��
	�����Σ�3��
	���ĴΣ�2��
	��9��

��3��


��4��
  2�Σ�һ�ζ���һ��д��



