#include <iostream>
#include <cstdio>
#include<vector>
using namespace std;

vector<bool> hasMail;
vector<int> addr;
vector<bool> done;

int trace(int m)
{
	hasMail[m] = true;
	if(hasMail[addr[m]]==true) //����H�����L�H 
		return 0;
	else
	{
		done[m]=true;
		return 1+trace(addr[m]);
	}
}

int main()
{
	int T,N;
	int u,v;
	int CASE = 1;
	cin>>T; //�D�ؼƶq
	while(T--)
	{
		cin>>N; //���P�H���ƶq
		addr.assign(N, -1); //�ֱH����
		for(int i=0;i<N;i++) 
		{
			cin>>u>>v;
			addr[u-1] = v-1;
		}

		done.assign(N, false);
		int MAX = 1;
		int firstMan = 1;
		for(int j=0;j<N;j++)
		{
			if(done[j]) //���L�F
				continue; 
			hasMail.assign(N, false); 
			int NEW = trace(j);
			if( NEW > MAX )
			{
				firstMan = j;
				MAX = NEW;
			}
		} 
		printf("Case %d: %d\n",CASE,firstMan+1);
		CASE++;
	} 
}
