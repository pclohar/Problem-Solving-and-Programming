#include<stdio.h>
void merge_sort(unsigned long int height[],int low,int high);
void merge(unsigned long int height[],int lb,int mid,int ub);
unsigned long int compute(unsigned long int height[],int k,int n);
int main()
{
    int a,n,k,i,j;
    unsigned long int height[20000],minimum;
    scanf("%d",&a);
    for(i=0;i<a;i++)
	{
		scanf("%d%d",&n,&k);
		if(k<=n)
		{
			for(j=0;j<n;j++)
			    scanf("%lu",&height[j]);
			merge_sort(height,0,n-1);
			minimum = compute(height,k,n);
			printf("%lu\n",minimum);
		}
	}
	return 0;
	
		
}

void merge_sort(unsigned long int height[],int low,int high)
{
	int mid, i;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(height,low,mid);
		merge_sort(height,mid+1,high);
		merge(height,low,mid,high);
	}
 	
}

void merge(unsigned long int height[],int lb,int mid,int ub)
{
	int temp[20000],low,up,i,j,k=0;
    low = mid;
	j = mid+1;
	i = lb;
	up = ub;
	while((i<=low) && (j<=ub))
	{
		if(height[i] < height[j])
			{
				temp[k++] = height[i++];
			}
		else
			{
				temp[k++] = height[j++];
			}
	}
	while(i<=low)
		temp[k++] = height[i++];
	while(j<=up)
		temp[k++] = height[j++];

	i = 0;
	j = lb;
	while(i<k)
	{
		height[j++] = temp[i++]; 
	}
}

unsigned long int compute(unsigned long int height[],int k,int n)
{
	int i=0,j;
	unsigned long int min=0,sub;
	
	for(j=k-1;j<n;j++)
	{
		sub = height[j] - height[i];
		if(j==k-1)
			min = sub;
		if(sub<min)
			min = sub;
		if(min==0)
			break;
		i++;
	}
	return min;
}