#include<stdio.h>
#define MAX 1000
int stack[MAX], top=-1;
void push(int truck);
int pop();
int rearrange(int love_mobiles[],int n);
int main()
{
	int love_mobiles[1000], n=1,i;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&love_mobiles[i]);
		rearrange(love_mobiles,n);
	}
	return 0;
}

int rearrange(int love_mobiles[],int n)
{
	int i=1,k;
	for(k=0;k<n;k++)
	{
		if(love_mobiles[k] != i)
		{
			if(love_mobiles[k]<stack[top] || top==-1 || stack[top]==i)
			{
				while(stack[top]==i)
				{
					pop();
					i++;
				}
				if(love_mobiles[k] != i)
					push(love_mobiles[k]);
				else
					i++;
				
			}
			else
				break;	
		}
		else
			i++;
	}
	
	if(k==n)
		printf("yes\n");
	else
		printf("no\n");

    top=-1;
	return 0;
}
void push(int truck)
{
	if(top==MAX-1)
		printf("Stack Overflow\n");
	else
	{
		stack[++top] = truck;
		//printf("push: %d\n",stack[top]);
	}	
}

int pop()
{
	int y=0;
	if(top==-1)
		printf("Stack Underflow\n");
	else
	{
	    y = stack[top--];
	
	}

	return y;
}