//队列ADT:先进先出
//$1指针实现
//每个节点的型
struct celltype {
	Elementtype element;
	celltype* next;
};
//队列的型
struct QUEUE {
	celltype* front;//指向第一个节点
	celltype* rear;//指向第二个节点
};
void MakeNull(QUEUE& Q) {
	//区分满和空
	Q.front = new celltype;
	Q.front->next = NULL;
	Q.rear = Q.front;
}
boolen Empty(QUEUE & Q) {
	if (Q.front = Q.rear) return true;
	else return false;
}
void EnQueue(Elementtype x, QUEUE& Q) {
	//插入尾部
	Q.rear->next = new celltype;
	Q.rear->next.element = x;
	Q.rear->next->next = NULL;
}
void DeQueue(QUEUE& Q) {
	//删除队列第一个元素
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
//$2循环数组实现※
define maxlength 100
typedef struct {
	int front;
	int rear;
	Elementtype elements[maxlength];
}QUEUE;

int addone(int i) {
	//把位置i按模加1
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
//返回第一个元素
	if (Empty(Q)) return NULL;
	else return(Elementtype[Q.front]);
}

void EnQUEUE(Elementype x, QUEUE& Q) {
	//表尾插入
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



