#include <stdio.h>
#include <math.h>

void dfs(int,long long int);
int T,p,q;
long long int max,min,target;

int main()
{
	scanf("%d", &T); //測資的筆數 
	int cases=0;
    while(T--) 
	{
		cases=cases+1;
		scanf("%d%d", &p, &q);
		max=0;
		min=1e17; //10的17次方
		target=pow(2, q); //2的q次方
		dfs(0,0);
		
		printf("Case %d: ",cases);
		if(max==0 && min==1e17) //表示沒有找到任何符合的數
			printf("impossible");
		else
		{
			if(min==max)
				printf("%lld",min);
			else
				printf("%lld %lld",min,max);
		}
		printf("\n");
	}
}

void dfs(int level,long long int num)
{
	if(level==p)
	{
		if(num%target==0)
		{
			if(num>max)
				max=num;
			if(num<min)
				min=num;
		}	
		return;
	}

	dfs(level+1,num*10+1);
	dfs(level+1,num*10+2);
}



