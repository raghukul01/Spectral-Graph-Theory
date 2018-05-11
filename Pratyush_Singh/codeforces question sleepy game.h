#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> v[100010];
int  st[100010], p=0,flag=0;
int n,m,vis[100010];
vector<int> path;
void dfs(int a, int step ){

	vis[a]++;
	st[a]=1;
	path.push_back(a);
	if(v[a].size() == 0 && (step%2) ){
		printf("Win\n");
		for(auto el : path){
			cout << el << " ";
		}
		cout << "\n";
		exit(0);
		flag=1;
		return;
	}
	for(auto el : v[a]){
		if(st[el]){
			p=1;
		}
		if(vis[el]<2)dfs(el,step+1);
	}
	path.pop_back();
	st[a]=0;
}

int main(){
   
   for(int i=0;i<100010;i++)
         st[i]=0;
    for(int i=0;i<100010;i++)
         vis[i]=0;     
    
    
	scanf("%d%d",&n,&m);
	for(int i=1 ; i<=n ; ++i){
		int t;scanf("%d",&t);
		while(t--){
			int a;scanf("%d",&a);
			v[i].push_back(a);
		}
	}
	int s; scanf("%d",&s);
	dfs(s,0);
	
//	if(flag==1)
    //   return 0;
		if(p==1)
			printf("Draw\n");
		else
			printf("Lose\n");
	
}