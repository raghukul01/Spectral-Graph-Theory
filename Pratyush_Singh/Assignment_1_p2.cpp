#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n);
bool prime(int j,int* a,int l);



bool prime(int j,int* a,int l)
{
    
    int i,flag=0;
    
    for(i=0;i<l-1;i++)
    {
       if((j%a[i])==0) 
        {  // cout<<a[i]<<endl;
            flag=1;
            break;
        }
    }
    
return !flag;
    
}
bool isprime(int n)
{if(n==1)
 return 0;
   int i,flag=0,k=floor(sqrt(n)); 
    
    for(i=2;i<=k;i++)
    {
        if((n%i)==0)
        {flag=1;
        break;
        }
       // cout<<"boom"<<endl;
    }
  return !flag;  
}
int main()
{
   int t,m,n;
   
   cin>>t;
 int sq=floor(sqrt(1000000000)) ; 
 int arp[sq];
 
 //cout<<sq<<endl;
 
 int p,l=0;
 
 
 for(p=2;p<=sq;p++)
{
  if(isprime(p))
   {arp[l]=p;
    l++;
   //cout<<arp[l-1]<<endl;
   }
    
}  
 
//cout<<prime(33333,arp,l)<<endl;

   while(t--)
   {
   
      cin>>m>>n;   
   
   
    int i,j,k;
     
   
   
  if(m>sq)
   { for(j=m;j<=n;j++)
    {
       if(prime(j,arp,l))
     {
       cout<<j<<endl;  
     }
    }
   }   
      
      
      
   else
   { for(j=m;j<=n;j++)
    {
       if(isprime(j))
     {
       cout<<j<<endl;  
     }
    } 
   }   
      
      
      
      
   
   cout<<endl;
  } 
     return 0;  
}

