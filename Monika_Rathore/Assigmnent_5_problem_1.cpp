#include<iostream>

using namespace std;

void mult(int n,int **a,int **b);

int path(int n,int **a,int **b,int k,int tpath,int i,int j);

int main(){
	int n;                       //no. of nodes in graph
	int l,m;                       
	cin>>n;
	int **a;
	
  a=new int*[n];             //memory allocation 
	  for(l=0;l<n;l++){
		a[l]=new int[n];
		for(m=0;m<n;m++)
		cin>>a[l][m];            //taking adjacancy matrix as input
	}
	
  int i,j,k;
	cin>>i;                     //i and j are given vertices
	cin>>j;
	cin>>k;                    //k is path length
	
  int **b;
	b=new int*[n];


		for(l=0;l<n;l++){
			 b[l]=new int[n];
		for(m=0;m<n;m++)
		b[l][m]=a[l][m];            
	}
	
  int tpath=a[i][j];
	int h=path(n,a,b,k,tpath,i,j);
	cout<<h;
	return 0;
}


void mult(int n,int **a,int **b){
	int t[n][n],q,p,r;                            //mutliply matrix as we know a to power n will give 
	for(q=0;q<n;q++){                             //no. of path b/w i and j of length n
		
    for(p=0;p<n;p++){
			
      int temp=0;
			for(r=0;r<n;r++){
				temp=temp+(b[p][r])*(a[r][p]);
			}
			t[q][p]=temp;
			
		}
	}
	for(q=0;q<n;q++)
	for(p=0;p<n;p++)
	b[q][p]=t[q][p];
}
int path(int n,int **a,int **b,int k,int tpath,int i,int j){
	if(k==0)
	return tpath;                                           //gave sum of total no. of path
	mult(n,a,b);                                           // whose length is less than or
	tpath=tpath+b[i][j];                                    //equal to k
	path(n,a,b,k-1,tpath,i,j);
}
