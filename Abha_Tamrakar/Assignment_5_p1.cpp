#include <iostream>

using namespace std;
void multiplymatrix(int n,int**adj,int**muladj)//multiply matrix
{
    int i,j,k;
    int temp[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int sum=0;
            for(k=0;k<n;k++)
            {
                sum+=(muladj[i][k])*(adj[k][j]);
            }
            temp[i][j]=sum;
        }
    }
    for(i=0;i<n;i++)
    {
          for(j=0;j<n;j++)
          {
                muladj[i][j]=temp[i][j];
              
          }
    }
}
int numpath(int n,int**adj,int**muladj,int k,int num,int i,int j)//to giv num of total path less than or equal to length k
{
  if(k==0)
    return num;
    
  multiplymatrix(n,adj,muladj);
  
  num=num+muladj[i][j];
  
  numpath(n,adj,muladj,k-1,num,i,j);
    
}


int main() {
	int n;
	cin>>n;
	
	int**adj;
	int**muladj;
	
	adj=(int**)malloc(n * sizeof(int*));
	for(int i=0;i<n;i++)
	{
	    adj[i]=(int*)malloc(n * sizeof(int));
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>adj[i][j];
	    }
	}
	
	muladj=(int**)malloc(n * sizeof(int*));
	for(int i=0;i<n;i++)
	{
	    muladj[i]=(int*)malloc(n * sizeof(int));
	}
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        muladj[i][j]=adj[i][j];//initially muladj is = given adjanency matrix
	    }
 
	}
	int i,j,k;
	cin>>i;//i,j are vertices
	cin>>j;
	cin>>k;//given path length
	
	int num=adj[i][j];
	
	int ans=numpath(n,adj,muladj,k,num,i,j);
	
	
	cout<<ans<<endl;
	

	

	
}
