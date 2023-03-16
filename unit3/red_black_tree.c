#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    struct tnode* left;
    struct tnode* right;
    int data;
    int color;//red=1,black=0
    struct tnode* parent;
	int level;
};
typedef struct tnode tnode;
struct queue
{
	int front;
	int rear;
	tnode **ptr_s;//even with single can work
	int size;
};
typedef struct queue queue;
void create_queue(queue * ptr_Q)
{
	ptr_Q->front=-1;
	ptr_Q->rear=-1;
	ptr_Q->ptr_s=malloc(sizeof(tnode*)*ptr_Q->size);
}
void insertQ(queue *ptr_Q,tnode *ele)
{
	if(ptr_Q->rear!=ptr_Q->size-1)//queue is not full
	{
		ptr_Q->rear+=1;

		ptr_Q->ptr_s[ptr_Q->rear]=ele;
		if(ptr_Q->front==-1)
		{
			ptr_Q->front+=1;
		}
	}
	else
		printf("Queue full\n");
}
int deleteQ(queue *ptr_Q)
{
	static int count=1;
	tnode* ele;
	if(ptr_Q->front==-1)//reseting option
		return -999;
	else
	{
		ele=ptr_Q->ptr_s[ptr_Q->front];
		ptr_Q->front=ptr_Q->front+1;
		if(ptr_Q->front==ptr_Q->rear+1)//last element deletion
			ptr_Q->front=ptr_Q->rear=-1;
		printf("Level:%d Data:%d Colour:%d\n",ele->level,ele->data,ele->color);
		if(ele->left!=NULL)
		{
			(ele->left)->level=ele->level+1;
			insertQ(ptr_Q,ele->left);
		}
		if(ele->right!=NULL)
		{
			(ele->right)->level=ele->level+1;
			insertQ(ptr_Q,ele->right);
		}
		deleteQ(ptr_Q);
		return 1;
	}
}
void levelorder(tnode* root)
{
	if(root!=NULL)
	{
		queue Q;
		Q.size=100;
		create_queue(&Q);
		insertQ(&Q,root);
		deleteQ(&Q);
	}
}
void destroy(tnode* root)
{
	if(root!=NULL)
	{
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
}
tnode* insert_bst(tnode* root,int ele)
{
    tnode* newnode=malloc(sizeof(tnode));
    if(ele<root->data)
    {
        if(root->left!=NULL)
        {
            newnode=insert_bst(root->left,ele);
        }
        else
        {
            newnode->left=newnode->right=NULL;
            newnode->data=ele;
            newnode->color=1;
            newnode->parent=root;
            root->left=newnode;
        }
    }
    else if(ele>root->data)
    {
        if(root->right!=NULL)
        {
            newnode=insert_bst(root->right,ele);
        }
        else
        {
            newnode->left=newnode->right=NULL;
            newnode->data=ele;
            newnode->color=1;
            newnode->parent=root;
            root->right=newnode;
        }
    }
    return newnode;
}
void postorder(tnode* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void insert_rbt(tnode** root,int ele)
{
    int uncle_color=0;
    tnode* newnode=malloc(sizeof(tnode));
    newnode=insert_bst(*root,ele);
    tnode* x=malloc(sizeof(tnode));
    x=newnode;
    tnode* p=malloc(sizeof(tnode));
    tnode* pp=malloc(sizeof(tnode));
    tnode* gp=malloc(sizeof(tnode));
    tnode* uncle=malloc(sizeof(tnode));
    while(x!=*root && x->parent->color==1)
    {
        newnode=x;
		if(newnode->parent->color==1 && newnode->color==1)
		{
			p=newnode;
			pp=newnode->parent;
			gp=newnode->parent->parent;
			if(pp==gp->left)
				uncle=gp->right;
			else
				uncle=gp->left;
			if(uncle)
				uncle_color=uncle->color;
			if(uncle_color==1)
			{   if(uncle)
					uncle->color=0;
				pp->color=0;
				gp->color=1;
				x=gp;
			}
			else if(uncle_color==0)
			{
				tnode* t=malloc(sizeof(tnode));
				if(pp==gp->left)
				{
					if(p==pp->right)
					{
						pp->right=p->left;
						p->left=pp;
						pp->parent=p;
						p->parent=gp;
						t=pp;
						pp=p;
						p=t;
					}
					gp->left=pp->right;
					pp->right=gp;
					if(gp->parent==gp)
					{
						*root=pp;
						(*root)->parent=*root;
						(*root)->parent->color=0;
					}
					else if(gp==gp->parent->left)
					{
						gp->parent->left=pp;
						pp->parent=gp->parent;
						gp->parent=pp;
					}
					else if(gp==gp->parent->right)
					{
						gp->parent->right=pp;
						pp->parent=gp->parent;
						gp->parent=pp;
					}
				}
				else
				{
					if(p==pp->left)
					{
						pp->left=p->right;
						p->right=pp;
						pp->parent=p;
						p->parent=gp;
						t=pp;
						pp=p;
						p=t;
					}
					gp->right=pp->left;
					pp->left=gp;
					if(gp->parent==gp)
					{
						//printf("aa%d",(*root)->data);
						*root=pp;
						(*root)->parent=*root;
						(*root)->parent->color=0;
					}
					else if(gp==gp->parent->left)
					{
						gp->parent->left=pp;
						pp->parent=gp->parent;
						gp->parent=pp;
					}
					else if(gp==gp->parent->right)
					{
						gp->parent->right=pp;
						pp->parent=gp->parent;
						gp->parent=pp;
					}  
				}
				x=pp;
				pp->color=1-pp->color;
				gp->color=1-gp->color;
				(*root)->color=0;
			}
		}
		else
			break;
   }

}
int  find_black_height(tnode* root)
{
    int count=0;
    if(root!=NULL)
    {
        if(root->color==0)
            count++;
        count+=find_black_height(root->left);
    }
    return count;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int ele;
    scanf("%d",&ele);
    tnode* root=malloc(sizeof(tnode));
    root->data=ele;
    root->left=NULL;
    root->right=NULL;
    root->color=0;
    root->parent=root;
    root->parent->color=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&ele);
        insert_rbt(&root,ele);
    }
	printf("Postorder traversal\n");
    postorder(root);
    printf("\b\n");
    printf("Level Order Traversal\n");
	levelorder(root);
	int h=find_black_height(root);
    printf("Black height of tree=%d\n",h);
    return 0;
}
