#include<stdio.h>
#define MAX 9
int mat[MAX][MAX];

int InRow(int r, int n)
{
	int c;
	for(c=0;c<9;c++)
	{
		if(mat[r][c] == n)
			return 1;
	}
	return 0;
}

int InCol(int c, int n)
{
	int r;
	for(r=0;r<9;r++)
	{
		if(mat[r][c] == n)
			return 1;
	}
	return 0;
}

int InGrid(int r,int c, int n)
{
	int i,j;
	r = r - r%3;
	c = c - c%3;
	for(i=r;i<r+3;i++)
	{
		for(j=c;j<c+3;j++)
		{
			if(mat[i][j] == n)
			return 1;		
		}
	}
	return 0;
}

Solve()
{
	int i,j,count,row,col,flag;

	flag = 0;

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(mat[i][j] == 0)
			{
				row = i;	
				col = j;
				flag = 1;
				//printf("row: %d  col:%d\n",row,col);
				break;
			}
		}
		if(flag == 1)
			break;
	}	

	if(flag==0)
		return 1;

	for(count=1;count<=9;count++)
	{
		if(!InRow(row,count) && !InCol(col,count) && !InGrid(row,col,count))
		{
			mat[row][col] = count;

			if(Solve() == 1)
				return 1;

			else
			{
				//printf("mat[%d][%d]: %d count: %d]\n",row,col,mat[row][col],count);
				mat[row][col] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	int test,i,j;
	char temp[81];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",temp);
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(temp[i*9 +j] == '.')
					mat[i][j] = 0;
				else
					mat[i][j] = temp[i*9+j] - '0';
			}
		}

		if(Solve()==1)
		{
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					printf("%d",mat[i][j]);
				}

//				printf("\n");
			}
//			printf("\n\n");
		}
	}
	return 0; 
}
