#include <iostream>
#include <math.h>
using namespace std;
 
 
  void find(long x)
 {
 	long n = long( sqrt(2*x) );
	long plus = (2*x)-(n*n);
	long i;
	if( (plus>=(-1*n)) && (plus<=(n-2)) )
	{
		i = (n-plus)/2;
		printf("%d %d\n",i,n);
	}
	else
	{
		n=n+1;
		plus = (2*x)-(n*n);
		i = (n-plus)/2;
		printf("%d %d\n",i,n);
	}
 }
 
 
 int main()
 {
 	long x ;
	while(cin>>x)
	{
		if(x!=0)
			find(x);
		else
			break;
	}	
 } 
 

 
