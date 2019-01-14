#include<stdio.h>
#define MAX 64
int cost[MAX][MAX];
int distance[MAX];
int pathx[MAX], pathy[MAX];
int visited[MAX] = {0};
void Dijkstras(int source)
{
	int i, min,v;
	for (i = 0; i < MAX; i++) 
	{
	    	distance[i] = cost[source][i];
		    visited[i] = 0;
	}
    distance[source] = 0;
	visited[source] = 1;
	while (1) 
	{
	    min = 10000;

    
	    for (i = 0; i < MAX; i++) 
		{
	        if (min > distance[i] && visited[i]!=1) 
			{
	            min = distance[i];
	            v = i;
	        }
	    }
    	if (min == 10000) 
	        break;
    	visited[v] = 1;
    	for (i = 0; i<MAX ; i++) 
		{
	        if (distance[i] > distance[v] + cost[v][i] && visited[i]!=1) 
			{
                      	  distance[i] = distance[v] + cost[v][i];
			}
        }
    }

}
void CostGraph(int svertex)
{
	int x, y, i, dvertex;
	y = svertex % 8;
	x = (svertex - y) / 8;
	//printf("x: %d y: %d\n",x,y);
	pathx[0] = x+2 , pathy[0] = y+1;
	pathx[1] = x+2 , pathy[1] = y-1;
	pathx[2] = x-2 , pathy[2] = y+1;
	pathx[3] = x-2 , pathy[3] = y-1;
	pathx[4] = x+1 , pathy[4] = y+2;
	pathx[5] = x+1 , pathy[5] = y-2;
	pathx[6] = x-1 , pathy[6] = y+2;
	pathx[7] = x-1 , pathy[7] = y-2;

	for(i=0;i<8;i++)
	{
		dvertex = pathx[i]*8+pathy[i];
		if(pathx[i]>=0 && pathx[i]<8 && pathy[i]>=0 && pathy[i]<8)
		{	
			cost[svertex][dvertex] = x*pathx[i] + y*pathy[i];
		//	printf("cost[%d][%d]: %d  pathx[%d]: %d pathy[%d]: %d\n",svertex,dvertex,cost[svertex][dvertex],i,pathx[i],i,pathy[i]);
		} 
	}
}
void findCost()
{
	int i,j;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			cost[i][j] = 10000;
	for(i=0;i<64;i++)
	{
		CostGraph(i);	
	}

}

int main()
{
	int a,b,c,d,src,dst;
	while(scanf("%d%d%d%d",&a,&b,&c,&d) != EOF)
	{
		findCost();
		src = a*8+b;
		Dijkstras(src);
		dst = c*8+d;
		printf("%d\n",distance[dst]);
	}
	return 0;
}