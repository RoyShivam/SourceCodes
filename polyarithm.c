#include"lib.c"
struct node
{
	int coeff,exp;
	struct node *next;
};
struct node* createnode(int coeff,int exp)
{
	struct node *n=malloc(sizeof(struct node));
	n->coeff=coeff;
	n->exp=exp;
	n->next=NULL;
}
void del(struct node* head)
{
	while(head)
	{
		struct node* next=head->next;
		free(head);
		head=head->next;
	}
}
struct node *createeq()
{
	struct node* head=NULL;
	int exp=0,coeff=0;
	while(getch()=='e')
	{
		printf("enter coefficient:");
		scanf("%d",&coeff);
		printf("enter exponent:");
		scanf("%d",&exp);
		struct node *newNode=createnode(coeff,exp);
		newNode->next=head;
		head=newNode;
	}
	return head;
}
void printeq(struct node *head)
{
	while(head)
	{
		printf("(%dx^[%d])",head->coeff,head->exp);
		head=head->next;
		if(head)printf("+");
	}
	printf("\n");
}
struct node *add(struct node* head1,struct node* head2)
{
	struct node* head3=NULL;
	while(head1&&head2)
	{
		int diff=head2->exp-head1->exp;
		struct node *newNode=createnode(0,0);
		newNode->next=head3;
		head3=newNode;
		if(diff==0)
		{
			newNode->coeff=head1->coeff+head2->coeff;
			newNode->exp=head1->exp;
			head1=head1->next;
			head2=head2->next;
		}
		else if(diff<0)
		{
			newNode->coeff=head2->coeff;
			newNode->exp=head2->exp;
			head2=head2->next;
		}
		else
		{
			newNode->coeff=head1->coeff;
			newNode->exp=head1->exp;
			head1=head1->next;
		}
	}
	while(head1)
	{
		struct node *newNode=createnode(head1->coeff,head1->exp);
		newNode->next=head3;
		head3=newNode;
		head1=head1->next;
	}
	while(head2)
	{
		struct node *newNode=createnode(head2->coeff,head2->exp);
		newNode->next=head3;
		head3=newNode;
		head2=head2->next;
	}
	return head3;
}
struct node *sub(struct node* head1,struct node* head2)
{
	struct node* head3=NULL;
	while(head1&&head2)
	{
		int diff=head2->exp-head1->exp;
		struct node *newNode=createnode(0,0);
		newNode->next=head3;
		head3=newNode;
		if(diff==0)
		{
			newNode->coeff=head2->coeff-head1->coeff;
			newNode->exp=head1->exp;
			head1=head1->next;
			head2=head2->next;
		}
		else if(diff<0)
		{
			newNode->coeff=-head2->coeff;
			newNode->exp=head2->exp;
			head2=head2->next;
		}
		else
		{
			newNode->coeff=-head1->coeff;
			newNode->exp=head1->exp;
			head1=head1->next;
		}
	}
	while(head1)
	{
		struct node *newNode=createnode(-head1->coeff,head1->exp);
		newNode->next=head3;
		head3=newNode;
		head1=head1->next;
	}
	while(head2)
	{
		struct node *newNode=createnode(head2->coeff,head2->exp);
		newNode->next=head3;
		head3=newNode;
		head2=head2->next;
	}
	return head3;
}