#include <iostream>
#include <vector>
using namespace std;
void filling(int,int);
int space[10]={0}; //十個可預約小時  0:未預約 1:已預約 
int meeting=0;//能舉行的會議數量 

int main()
{
	int tests; //紀錄有幾筆測資 
	vector<int> vInt; //想預約的時段
	int x,y;
	cin>>tests;
	
	for(int test=0;test<tests;test++)
	{
		while(cin>>x>>y) //將預約資料傳入陣列 
		{
			if(x==0 && y==0)
				break;
			else
				{
					vInt.push_back(x);
					vInt.push_back(y);
				}
		}
		
		for(int hour_selector=1;hour_selector<10;hour_selector++) //從需要最少時間的會議開始  1->10
		{
			for(int k=1;k<vInt.size();k=k+2)
			{
				if((vInt[k]-vInt[k-1])==hour_selector) //計算該會議需要幾小時 
					filling(vInt[k-1],vInt[k]);
			} 
		}
		
		cout<<meeting<<"\n"; //印出答案 
		for(int m=0;m<10;m++) //清空陣列 
			space[m]=0;
		vInt.clear(); 
		meeting=0;
	}
	

}

void filling(int start,int end) //將1填入可被預約時段 
{
	for(int i=start;i<end;i++)  
	{
		if(space[i]!=0) //有時段已被預約就跳出 
			break;
			
		if(i==end-1) //沒有任何時段已被預約
		{ 
			meeting = meeting+1;
			for(int j=start;j<end;j++)  
				space[j]=1;
		} 
	} 
}





