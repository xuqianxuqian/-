���Ա�����ʵ��ADT
#define maxlength 100
struct IST {
	Elementtype element[maxlength];
	int last;
};


//��ͥ��ҵ2
//4
struct celltype {
	Elementtype element;
	celltype* next;
};
typedef celltype* LIST;
typedef celltype* position;
LIST ADD(LIST a, LIST b) {
	position p, q;
	p = a->next;
	q = b->next;
	while (p != NULL && q != NULL) {
		switch (Compare(p->element, q->element))
		{
		case '=':
			p = p->next;
			q = q->next;
		case '>':
			p = p->next;
		case '<':
			Insert(q->elemnet, q, a);
			q = q->next;
		}
	}
	while (q != NULL) {
		Attach(q->element, a);
	}
	return a;
}
char Compare(Elementtype x, Elementtype y) {
	if (x == y) return('=');
	if (x < y) return('<');
	if (x > y) return('>');
}

//8
 XSXXXSSSXXSXXSXXSSSS


//15
struct cycl_dou_celltype {
	 //˫��������
	 Elementtype element;
	 cycl_dou_celltype* previous, * next;//ָ��ǰһ�ڵ��ָ�룬ָ���һ�ڵ��ָ��
 };
 typedef cycl_dou_celltype* position;
 typedef cycl_dou_celltype* LIST;

 void Visit(LIST& R) {
	 if (R == NULL)
		 error("list is empty!");
	 else
	 {
		 position p;
		 p = R;
		 while (p->next != R)
		 {
			 p = p->next;
		 }
	 }
 }


 //18
 struct celltype {
	 Elementtype element;
	 celltype* next;
 };
 typedef celltype* LIST;
 typedef celltype* position;
 void Search(Elementtype x, LIST l) {
	 position q;
	 int sum = 0;//��¼���
	 q = l;
	 while (q ->next!= NULL && q->element != x)
	 {
		 q = q->next;
		 sum++;
	 }
	 if (q != NULL) printf("%d\n", sum);
	 else {
		 //��Ԫ��x���ڱ�β
		 position ptr;
		 ptr = new celltype;
		 ptr->element = x;
		 q->next = ptr;
		 ptr->next = NULL;
	 }
 }

 //19
 struct cycl_celltype {
	 Elementtype element;
	 cycl_dou_celltype * next;
 };
 typedef cycl_dou_celltype* position;
 typedef cycl_dou_celltype* LIST;
 LIST& R1 = NULL;//ָ��ͷ���
 LIST& R2 = NULL;
 viod Create(LIST& R1, LIST& R2, LIST L) {
	 position p, m, n;
	 int sum = 1, sum1 = 0;
	 p = L->next;
	 while (p != NULL) {
		 if (sum % 2 != 0)
		 {
			 Linsert(p->element, &R1);
			 sum1++;
		 }
		 else
		 {
			 Linsert(p->element, &R2);
		 }
		 sum++;
	 }
	 R1->element = sum1;
	 R2->element = sum - sum1;
 }
 void Linsert(Elementtype x, LIST& R) {
	 cycl_celltype* p;
	 p = new cycl_celltype;
	 p->element = x;
	 if (R == NULL) {
		 p->next = p;
		 R = P;
	 }
	 else {
		 p->next = R->next;
		 R->next = p;
	 }
 }

 //22
 struct node {
	 char date;
	 node* next;
 };

 typedef node* STRING;
 typedef node* position;


 node* Substr(STRING S, int m, int n) {
	 int sum=0;
	 STRING Q;
	 Q = new node;
	 position p;
	 p = S;
	 while (sum < m)
	 {
		 p = p->next;
		 sum++;
	 }
	 while (P != NULL && sum <= n) {
		 In(Q, p->date)��//���ַ�p->date����Qĩβ
		 p = p->next;
		 sum++;
	 }
	 return Q;
 }



