#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 1000
int set[MAX];
class segment
{
	int x1,x2,y1,y2,minx,miny,maxx,maxy;
	public:
		segment(){}
		void getdata(int a,int b,int c, int d)
		{
			x1 = a;
			y1 = b;
			x2 = c;
			y2 = d;
			if(x1<x2)
			{
				minx = x1;
				maxx = x2;
			}
			else
			{
				minx = x2;
				maxx = x1;
			}
			if(y1<y2)
			{
				miny = y1;
				maxy = y2;
			}
			else
			{
				miny = y2;
				maxy = y1;
			} 
		}
		friend int do_intersect(segment s1, segment s2);
		friend int orient(int a1, int b1, int a2, int b2, int a3,int b3);
		friend bool on_seg(int p, int q, int xmin, int xmax, int ymin, int ymax);
};

int find(int obj)
{	
	return set[obj];
}

void unionSet(int obj1, int obj2, int n)
{
		int s1 = set[obj1];
		int s2 = set[obj2];

		for(int i=1; i<=n; i++)
		{
			if(set[i]==s2)
				set[i] = s1;
		}
}

bool on_seg(int p, int q, int xmin, int xmax, int ymin, int ymax)
{	
	if((xmin<=p)&&(p<=xmax)&&(ymin<=q)&&(q<=ymax))
		return true;
	return false;
}

int orient(int a1, int b1, int a2, int b2, int a3,int b3)
{
	int k;
	k = (b2 - b1)*(a3 - a2) - (a2 - a1)*(b3 - b2);
	if(k==0)
		return 0;
	if(k>0)
		return 1;
	else
		return 2;
}
int do_intersect(segment s1, segment s2)
{
	int o1,o2,o3,o4; 
	o1 = orient(s1.x1,s1.y1,s1.x2,s1.y2,s2.x1,s2.y1);
	o2 = orient(s1.x1,s1.y1,s1.x2,s1.y2,s2.x2,s2.y2);
	o3 = orient(s2.x1,s2.y1,s2.x2,s2.y2,s1.x1,s1.y1);
	o4 = orient(s2.x1,s2.y1,s2.x2,s2.y2,s1.x2,s1.y2);

	if(o1!=o2 && o3!=o4)
		return 1;
	if(o1==0)
	{
		if(on_seg(s2.x1,s2.y1,s1.minx,s1.maxx,s1.miny,s1.maxy))
		{	
			return 1;
		}
	}	
	
	if(o2==0)
	{
		if(on_seg(s2.x2,s2.y2,s1.minx,s1.maxx,s1.miny,s1.maxy))
		{
			return 1;
		}
	}

	if(o3==0)
	{
		if(on_seg(s1.x1,s1.y1,s2.minx,s2.maxx,s2.miny,s2.maxy))
		{
			return 1;
		}
	}

	if(o4==0)
	{
		if(on_seg(s1.x2,s1.y2,s2.minx,s2.maxx,s2.miny,s2.maxy))
		{	
			return 1;
		}
	}

	return 0;
}


int main()
{
	int t=1, n, m, cord[4],test=0,k=1,f1,f2,a=0;
	segment sticks[1000];
	scanf("%d",&t);
	if(t<=100)
	{
		while(a<t)
		{
			scanf("%d%d",&n,&m);
			//initialize(n);
			if(1<=n && 1<=m && n<=1000 && m<=1000)
			{
				for(int i=1; i<=n; i++)
				{
					set[i] = i;
					for(int j=0; j<4; j++)
						scanf("%d",&cord[j]);
					sticks[i].getdata(cord[0],cord[1],cord[2],cord[3]);
					if(i>1)
					{
						while(k<=i)
						{
							//cout<<k<<" "<<i<<endl;
							if(find(i)!=find(k))
								test = do_intersect(sticks[i],sticks[k]);
							if(test==1)
								unionSet(i,k,n);
							k++;
							test=0;
						}
					//	cout<<"test: "<<test<<endl;
					//k = k-1;
					//	cout<<"i:"<<i<<"k: "<<k<<endl;
						
						k=1;
					}					
				}
				//cout << set[1] <<" "<< set[2] << endl;
				for(int i=0;i<m;i++)
				{
					scanf("%d%d",&f1,&f2);
					f1 = find(f1);
					f2 = find(f2);
					if(f1==f2)
						printf("YES\n");
					else
						printf("NO\n");	
				}	
			}
			a++;
		}
		
	}
	return 0;
}