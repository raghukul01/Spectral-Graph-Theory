#include <iostream>

using namespace std;
int check_prime(int);
int main() 
{
   int t,n,m,i,j,h;
   cin>>t;
   for(i=0;i<t;i++)
   {
       cin>>n;
       cin>>m;
       for(j=n;j<=m;j++)
       {
           h=check_prime(j);
           if(h==0)
           {
              cout<<j<<endl;
           }
       }
     cout<<endl;
   }
return 0;
}

int check_prime(int j)
{
    int k,q=0;
    if(j==1)
    {
        return j;
    }
    else
    {
        for(k=2;k<=j/2;k++)
        {
            if(j%k==0)
            {
                q=1;
                break;
            }
        }
        return q;
    }
}
