#include<stdio.h>
#define MAX 10000
int Queue[MAX];
int front =-1, rear =-1;
int seive[MAX]={0};
int visited[MAX]={0};
int height[MAX]={0};
void EnQueue(int x)
{
	if(front==-1)
	{
		front++;
		
	}
	rear++;
	Queue[rear] = x;
	//printf("Enqueue: %dfront: %d rear: %d\n",Queue[rear],front,rear);
}

int DeQueue()
{
	if(front>=0 && front!=rear+1)
	{
		//printf("Dequeue: %d front:%d \n",Queue[front],front);
		return Queue[front++];
	}
}

void prime()
{
	int i,j;
    for(i=2;i<=100;i++)
    {
        if(seive[i]==0)
        {
            for(j=i*2;j<=10000;j=j+i)
                seive[j] = 1;
        }
    }
}

int BFS(int initial, int final)
{
	int array[4],i,j,temp,curState,temp1;
	
	EnQueue(initial);
	visited[initial] = 1;
	while(front!=-1 && front<rear+1)
	{
		temp=0;
		curState = DeQueue();
		temp = curState;
		if(curState==final)	
		{	
//			printf("height: %d\n",height[final]);
			return height[final];
		}

		for(j=3;j>=0;j--)
		{
			temp = curState;
			for(i=3;i>=0;i--)
			{
				array[i] = temp%10;
			//	printf("%d",array[i]);
				temp = temp/10;
			}	
		//	printf("\n");
			for(i=0;i<10;i++)
			{
				array[j] = i;
				temp1 = array[0]*1000+array[1]*100+array[2]*10+array[3];
			//	printf("temp: %d\n",temp1);
				if(seive[temp1]!=1 && temp1>999 && visited[temp1]!=1)
				{
					visited[temp1]=1;
					height[temp1] = height[curState]+1;
	//				printf("height: %d\n",height[temp1]);					
					EnQueue(temp1);
				}
			}

		}
	}

	return -1;
}
int main()
{
	int test,initial,final,i,ans=-1;
	scanf("%d",&test);
	prime();
	while(test--)
	{
		scanf("%d%d",&initial,&final);
		ans = BFS(initial,final);
		if(ans>=0)
			printf("%d\n",ans);
		else
			printf("Impossible\n");
		ans=0;
		front =-1;
		rear = -1;
		for(i=0;i<10000;i++)
		{
			height[i] =0;
			visited[i] =0;
		}
	}
	return 0;
}
