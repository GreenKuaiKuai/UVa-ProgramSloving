#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int main()
{
	long long a,b;
	int cases=1;
	while(cin>>a>>b)
	{
		if(a==0&&b==0)
			break;
		else
		{
			long count=0;
			for(long long i=a;i<=b;i++)
			{
				long long t=i;
				while(t != 1)
				{
					count=count+(t%2);
					t=t/2;
				}
				count=count+1;
			}
			printf("case %d: %ld\n",cases,count);
		}
		cases++;
	}
}

