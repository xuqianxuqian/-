//STACK ADT
//数组实现
struct STACK {
	int top;//游标指示当前栈顶元素位置
	Elementtype(类型eg：int） elements[maxlength];
};
//element[top],element[top+1].......element[maxlength-1]
viod MakeNull(STACK* S) {
	S->top = maxlength;
}

Elementtype Top(STACK* S) {
	if(Empty(S)//判断是否为空)
		return NULL;
	else
		return(S.elements[S.top]);
}

void Pop(STACK& S) {
	if(Empty(S))
		error("empty");
	else
		s.top+=1;
}
void Push(Elementtype x, STACK& S) {
	if (S.top == 0)
		error("full");
	else
	{
		S.top = S.top - 1; 
		S.Elementtype[S.top] = x;
	}
}

//指针实现
struct node {
	Elementtype val;
	node* next;
};
typedef node* STACK;
void MakeNull()
{
	STACK S;
	S = new node;
	s->next = NULL;

}
void Push(Elementtype x, STACK S) {
	STACK ptr;
	ptr = new node;
	ptr->val = x;
	ptr->next = S->next;
	S->next = ptr;
}
void Pop(STACK S) {
	STACK p;
	if (S->next) {
		p= S->next;
		S->next = p->next;
		free p;
	}
}
Elementtype Top(STACK S) {
	if (S->next)
		return(S->next->val);
	else
		return NULL;
}
boolean Empty(STACK S) {
	//判断是否是空表
	if (S->next)
		return FALSE;
	else
		return TRUE;
}

//判断字符串是否中心对称
boolean Judge(LIST* head) {
	STACK S;
	char e;
	MakeNull(S);
	LIST* p = head;//链表方式储存串
	while (p != NULL) {
		Push(S, p->date);
		p = p->next;
	}
	p = head;
	while (p != NULL) {
		e = Top(S); Pop(S);
		if (p->date == e)
			p = p->next;
		else
			break;
	}
	if (p = NULL)
		return TRUE;
	else return FALSE;

}

