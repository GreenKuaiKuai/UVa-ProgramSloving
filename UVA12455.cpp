#include <stdio.h>

int main() 
{
    int t,n,p,i,j,bar;
    scanf("%d", &t); //���ꪺ���� 
    while(t--) 
	{
        scanf("%d %d", &n, &p); //n �ؼЪ��� p�Τl�ƶq 
        int dp[1005] = {};
        
        dp[0] = 1;
        for(i = 0; i < p; i++) 
		{
            scanf("%d", &bar);
            for(j = n-bar; j >= 0; j--) 
			{
                if(dp[j] && !dp[j+bar])
                    dp[j+bar] = 1;
            }
        }
        if(dp[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
}
