#include <iostream>
#include <vector>
using namespace std;
void filling(int,int);
int space[10]={0}; //�Q�ӥi�w���p��  0:���w�� 1:�w�w�� 
int meeting=0;//���|�檺�|ĳ�ƶq 

int main()
{
	int tests; //�������X������ 
	vector<int> vInt; //�Q�w�����ɬq
	int x,y;
	cin>>tests;
	
	for(int test=0;test<tests;test++)
	{
		while(cin>>x>>y) //�N�w����ƶǤJ�}�C 
		{
			if(x==0 && y==0)
				break;
			else
				{
					vInt.push_back(x);
					vInt.push_back(y);
				}
		}
		
		for(int hour_selector=1;hour_selector<10;hour_selector++) //�q�ݭn�̤֮ɶ����|ĳ�}�l  1->10
		{
			for(int k=1;k<vInt.size();k=k+2)
			{
				if((vInt[k]-vInt[k-1])==hour_selector) //�p��ӷ|ĳ�ݭn�X�p�� 
					filling(vInt[k-1],vInt[k]);
			} 
		}
		
		cout<<meeting<<"\n"; //�L�X���� 
		for(int m=0;m<10;m++) //�M�Ű}�C 
			space[m]=0;
		vInt.clear(); 
		meeting=0;
	}
	

}

void filling(int start,int end) //�N1��J�i�Q�w���ɬq 
{
	for(int i=start;i<end;i++)  
	{
		if(space[i]!=0) //���ɬq�w�Q�w���N���X 
			break;
			
		if(i==end-1) //�S������ɬq�w�Q�w��
		{ 
			meeting = meeting+1;
			for(int j=start;j<end;j++)  
				space[j]=1;
		} 
	} 
}





