#include <stdio.h>
struct tree
{
	int data;
	struct tree *left,*right;
};
struct tree *root;

int insert(struct tree *d , int inp)
{
	if(d->data > inp)
	{
		if(d->left == NULL)
		{
			struct tree *r;
			r = malloc(sizeof(struct tree));
			r->data = inp;
			r->left = NULL;
			r->right = NULL;
			
			d->left = r;
		}
		else
		{
			insert(d->left , inp);
		}
	}
	else
	{
		if(d->right == NULL)
		{
			struct tree *r;
			r = malloc(sizeof(struct tree));
			r->data = inp;
			r->left = NULL;
			r->right = NULL;
			
			d->right = r;
		}
		else
		{
			insert(d->right , inp);
		}
	}
	return ;
}


int print(struct tree *r)
{
	if(r==NULL)
	return;	
	printf("%d ",r->data);
	print(r->left);
	print(r->right);
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		int i,f=1;
		for(i=0;i<n;i++)
		{
			int inp;
			scanf("%d",&inp);
			if(f==1)
			{
				struct tree *r;
				r = malloc(sizeof(struct tree));
				r -> data = inp;
				r -> left = NULL;
				r -> right = NULL;
				root = r;
				f=0;
			}
			else
			{
				insert(root,inp);
			}
		}
		print(root);
		printf("\n");
	}
	return 0;
 } 
