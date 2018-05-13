#include <iostream>

using namespace std;

void mul(int n ,int**adj ,int**alt_adj) // matrix multipication
{
    int i,j,k;
    int mat[n][n];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int sum=0;
            for(k=0;k<n;k++)
            {
                sum=sum+(alt_adj[j][k]*adj[k][j]);
            }
            mat[i][j]=sum;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            alt_adj[i][j]=mat[i][j];
        }
    }
}
   
   int paths(int n,int**adj,int**alt_adj,int sum,int i,int j,int k) // to find number of paths of length less than or equal to k
{
  if(k==0)
    return sum;
    
  mul(n,adj,alt_adj);
  
  sum=sum+alt_adj[i][j];  
  
  paths(n,adj,alt_adj,sum,i,j,k-1);  //using recursion
    
}
int main() 
{
	int n;
	cin>>n;
	
	int** adj = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        adj[i] = new int[n];
    }    
    
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>adj[i][j];
	    }
	}
	
	int** alt_adj = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        alt_adj[i] = new int[n];
    }    
	
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        alt_adj[i][j]=adj[i][j];//initially alt_adj is equal to given adjanency matrix
	    }
 
	}

	int i,j,k;
	cin>>i;//i,j are vertices
	cin>>j;
	cin>>k;//given path length
	
  int sum=adj[i][j];
    
	cout<<paths(n,adj,alt_adj,k,sum,i,j)<<endl;
	
	return 0;
	
} 
    
