//����ADT:�Ƚ��ȳ�
//$1ָ��ʵ��
//ÿ���ڵ����
struct celltype {
	Elementtype element;
	celltype* next;
};
//���е���
struct QUEUE {
	celltype* front;//ָ���һ���ڵ�
	celltype* rear;//ָ��ڶ����ڵ�
};
void MakeNull(QUEUE& Q) {
	//�������Ϳ�
	Q.front = new celltype;
	Q.front->next = NULL;
	Q.rear = Q.front;
}
boolen Empty(QUEUE & Q) {
	if (Q.front = Q.rear) return true;
	else return false;
}
void EnQueue(Elementtype x, QUEUE& Q) {
	//����β��
	Q.rear->next = new celltype;
	Q.rear->next.element = x;
	Q.rear->next->next = NULL;
}
void DeQueue(QUEUE& Q) {
	//ɾ�����е�һ��Ԫ��
	celltype* p;
	if (Empty(Q)) error("empty!");
	else {
		p = Q.front->next;
		Q.front->next = p->next;
		delete p;
		if (Q.front->next = NULL)
			Q.rear = Q.front;		
	}
}
//$2ѭ������ʵ�֡�
define maxlength 100
typedef struct {
	int front;
	int rear;
	Elementtype elements[maxlength];
}QUEUE;

int addone(int i) {
	//��λ��i��ģ��1
	return((i + 1) % maxlength);
}
void MakeNull(QUEUE& Q) {
	Q.front = 0;
	Q.rear = maxlength - 1;
}
boolean Empty(QUEUE& Q) {
	if (addone(Q.rear) == Q.front) return TRUE;
	else
		return FALSE;
}
boolean Full(QUEUE& Q) {
	if (addone(addone(Q.rear)) == Q.front) return TRUE;
	else return FALSE;
}

Elemenyytpe Front(QUEUE& Q) {
//���ص�һ��Ԫ��
	if (Empty(Q)) return NULL;
	else return(Elementtype[Q.front]);
}

void EnQUEUE(Elementype x, QUEUE& Q) {
	//��β����
	if (Full(Q)) error("full");
	else {
		Q.rear = addone(Q.rear);
		Q.elemrnt[Q.rear] = x;
	}	
}
void DeQUEUE(QUEUE& Q) {
	if (Empty(Q)) error("empty");
	else {
		Q.front = addone(Q.front);
	}
}



