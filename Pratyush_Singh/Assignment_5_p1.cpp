#include <iostream>
using namespace std;
void mult(int n,int**adj,int**new_adj);
int path(int n,int**adj,int**new_adj,int k,int sum,int i,int j);

void mult(int n,int**adj,int**new_adj)
{
   int p,q,r;
   int temp1[n][n];
   
   
   // multiply ajd and new_adj and store it in temp matrix
   
   for(p=0;p<n;p++)
      {
          for(q=0;q<n;q++)
           {
              int temp=0;
              
               for(r=0;r<n;r++)
                  {
                    temp=temp+new_adj[q][r]*adj[r][q]; 
                  }
                  
              temp1[p][q]=temp;      
           }
          
          
      }
    
   //now copy temp1 back to new_adj 
   for(p=0;p<n;p++)
          for(q=0;q<n;q++)
                new_adj[p][q]=temp1[p][q];
    
}

int path(int n,int**adj,int**new_adj,int k,int sum,int i,int j)
{
  if(k==0)
    return sum;// stop after k length path
    
  mult(n,adj,new_adj);// function for matrix multiplication
  
  sum=sum+new_adj[i][j];// sum will keep on increasing k times
  
  path(n,adj,new_adj,k-1,sum,i,j);
    
}



int main() {

int n;    // number of vertices

int** adj;// adjacancy matrix
int** new_adj; // matrix which will store k times multiplication

adj = new int*[n];
for(int i = 0; i < n ;i++)    // memory allocation
{
    adj[i] = new int[n];
}


new_adj = new int*[n];
for(int i = 0; i < n; i++)    // memory allocation
{
    new_adj[i] = new int[n];
}




for(int i = 0; i < n; i++)
   for(int j = 0; j < n; j++)// initially for 1st itme both matrices are same
        new_adj[i][j]=adj[i][j];// copy the matrix
        

int i,j,k;
int sum=adj[i][j];


// i,j are given verticces and k is length of path given 
// this code is written assuming we already have adjacancy matrix
// and new_adj is initially same as adj. it will change during matrix multiplication 

int p=path(n,adj,new_adj,k,sum,i,j);

cout<<p<<endl;

	return 0;
}