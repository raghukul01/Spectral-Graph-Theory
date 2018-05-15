#include <iostream>

using namespace std;

int prime (int a)
{
    int ans,k;
    if(a==1)
    {
        return 0;
    }
    else
    {
        for(k=2;k<=a/2;k++)
        {
            if((a%k)==0)
            {
                ans=0;
                break;
            }
            else
            {
                ans=1;
            }
        }
        return ans;
    }
    
    
}
int main()
{
    int t,m,n,b,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
      cin>>m;
      cin>>n;
      for(j=m;j<=n;j++)
      {
        b=prime(j);
        if(b==1)
        {
            cout << j << endl;
        }
      }
      cout<<endl;
    }

    return 0;
}
