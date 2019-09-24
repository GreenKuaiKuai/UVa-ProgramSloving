#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void trace(int m,bool hasM[],int addr[],vector<int> result[])
{
	if( result[m].empty()==false ) //�i�H���o�L�h������
	{
		for(int i=0;i<result[m].size();i++)
		{
			if(hasM[result[m].at(i)] = false)
			{
				result[m].push_back(i);
			}	
		}
		return;
	}
	
	//�S���L�h���� 
	hasM[m] = true;
	result[m].push_back(m);
	if(hasM[addr[m]]==true) //����H�����L�H 
		return;
	else
	{
		trace(addr[m],hasM,addr,result);
		for(int j=0;j<result[addr[m]].size();j++)
		{
			result[m].push_back(result[addr[m]].at(j));
		}
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
		//Ū������ 
		cin>>N; //���P�H���ƶq
		int addr[N+1]; //�ֱH����
		for(int i=0;i<N;i++) 
		{
			cin>>u>>v;
			addr[u] = v;
		}
		
		vector<int> result[N+1]; //���L������
		for(int j=1;j<=N;j++)
		{	
			if(result[j].empty()==false)
			{
				continue;
			}
			else
			{
				bool hasMail[N+1] = {false}; 
				trace(j,hasMail,addr,result);
				
				for(int y=1;y<result[j].size();y++)
				{
					for(int x=0;x<result[addr[result[result[j].at(y)].back()]].size();x++)
					{
						vector<int>::iterator it = find(result[result[j].at(y)].begin(), 
														result[result[j].at(y)].end(),
														result[addr[result[result[j].at(y)].back()]].at(x) );
						if(it == result[j].end()) //�S���
							 result[result[j].at(y)].push_back( result[addr[result[result[j].at(y)].back()]].at(x) );
					}
				}
			}	
		} 
		
		int MAX = 1;
		int firstMan = 1;
		for(int k=1;k<=N;k++)
		{
			if(result[k].size()>MAX)
			{
				firstMan = k;
				MAX = result[k].size();
			}
				
		}
		
		printf("Case %d: %d\n",CASE,firstMan);
		/*for(int z=0;z<result[firstMan].size();z++)
		{
			printf("%d ",result[firstMan].at(z));
		}
		printf("\n");*/
		CASE++;
	} 
}
