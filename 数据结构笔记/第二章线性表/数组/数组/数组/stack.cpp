//STACK ADT
//����ʵ��
struct STACK {
	int top;//�α�ָʾ��ǰջ��Ԫ��λ��
	Elementtype(����eg��int�� elements[maxlength];
};
//element[top],element[top+1].......element[maxlength-1]
viod MakeNull(STACK* S) {
	S->top = maxlength;
}

Elementtype Top(STACK* S) {
	if(Empty(S)//�ж��Ƿ�Ϊ��)
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

//ָ��ʵ��
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
	//�ж��Ƿ��ǿձ�
	if (S->next)
		return FALSE;
	else
		return TRUE;
}

//�ж��ַ����Ƿ����ĶԳ�
boolean Judge(LIST* head) {
	STACK S;
	char e;
	MakeNull(S);
	LIST* p = head;//����ʽ���洮
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

