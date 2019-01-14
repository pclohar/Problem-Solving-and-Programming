#include<stdio.h>
#define MAX 1000
int maxr,maxc;
char mat[MAX][MAX];
//int check[MAX][MAX] ={0};
int visited[MAX][MAX]={0};
int count = 0;
char array[10] = {'A','L','L','I','Z','Z','W','E','L','L'};
int solve( int row, int col)
{
	int i,j,posr,posc,flag=0;
	char temp;
	int curState = mat[row][col];
	int nextState = array[count+1];
	//printf("curState: %c nextState: %c ROW: %d  COL: %d COUNT: %d\n",curState,nextState,row,col,count);
	if(count==9 && curState == 'L')
		return 1;
	
	
	for(i=row-1;i<maxr && i<=row+1;i++)
	{	
		
		for(j=col-1;j<maxc && j<=col+1;j++)
		{
			
			if(i>=0 && j>=0)
			{
				//printf("cur: %c  adj:%c i: %d j: %d CHECK: %d VISITED: %d\n",curState,mat[i][j],i,j,check[i][j],visited[i][j]);
				if(mat[i][j]==nextState && !(i==row && j==col) && visited[i][j]!=1)
				{
					flag=1;
					visited[i][j]=1;
				//	temp = mat[i][j];
					posr = i;
					posc = j;
					//printf("temp: %c  i:%d  j:%d\n",temp,posr,posc);
					count++;
					
					//printf("Inner loop count %d\n",count);
					if(solve(posr,posc)==1)
					{
						return 1;
					}		
	
					else	
					{
						count--;
						visited[posr][posc]=0;	
						
						curState = mat[row][col];
					
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	int test,row,col,flag=0,i,j,w,q;
	char temp;
	
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&row,&col);
		
		for(i=0;i<row;i++)
		{	
			for(j=0;j<col;j++)
			{	
				scanf("%s",mat[i]);				
			}
		//	scanf("%c",&temp);
		}
	
		/*for(i=0;i<row;i++)
		{	
			for(j=0;j<col;j++)
			{	
			//	getchar();
				printf("%c\t",mat[i][j]);
			//	scanf("%c",&mat[i][j]);
				
			}
			printf("\n");
		}*/
		maxr = row;
		maxc = col;		

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(mat[i][j] == 'A')
				{
					if(solve(i,j)==1)
					{
						printf("YES\n");
						flag=1;
						break;
					}
					for(w=0;w<row;w++)
						for(q=0;q<col;q++)
							visited[w][q]=0;
						
					count=0;
				}
			}	
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
		
		flag=0;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
			{
				visited[i][j]=0;
			}
		count=0;				
	}
}
