#include <stdio.h>
#include<vector>

#define vi std::vector<int>

vi prime;

int binarysearch( int , int , int );

int main() {
	int t;
	scanf("%d",&t);
	while(t--)                                                                     
	{
	    int a,b;
	    scanf("%d%d",&a,&b);
	    vi check(100001,1);
	    check[0]=0;                                                                                   
	    check[1]=0;
	    for(int i=2; i*i<=100000; ++i)
	    {
	        if( check[i] )
	        {
	            for(int j=i+i; j<=100000; j+=i )
	            {
	                check[j] = 0;
	            }
	        }
	    }
	    for(int k=2; k<=100000; ++k)
	    {
	        if( check[k] )
	            prime.push_back(k);
	    }
	    vi sol(b-a+1,1);
	    if( b <= 100000 )               
	    {
	        int i1 = binarysearch( a , 0 , prime.size()-1);
	        int i2 = binarysearch( b , 0 , prime.size()-1);
	        if( prime[i2]>b )
	            i2--;
	        for(int j=i1; j<=i2; ++j)
	        {
	            printf("%d\n",prime[j]);
	        }
        }
        else
        {
            for(int j=0; j<prime.size(); ++j)
            {
                int x = prime[j];
                int y = (a/x)*x;
                if(a%x != 0)
                    y+=x;
                while(y<=b)
                {
                    if(y != x)
                        sol[y-a]=0;
                    y+=x;
                }
            }
            for(int j=a; j<=b; ++j)
            {
                if(a==1)
                    continue;
                if( sol[j-a] )
                    printf("%d\n",j);
            }
        }
        printf("\n");
	}
	return 0;
}

int binarysearch( int key , int start , int end)
{
    while( start < end )
    {
        int mid = (end + start)/2;
        if( key == prime[mid] )                                                            
            return mid;
        if( key < prime[mid] )                                                            
            end = mid;
        else
            start = mid+1;
    }
    return start ;
}
