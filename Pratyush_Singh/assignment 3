#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class graph{
 int n;
 list<int> *preq;
 public:
 int arr[10000];
void topsort_help(int v,int visited[],stack<int> &Stack);

 graph(int n);
void topsort(int arr[]);
void make(int v,int w);
};
 
graph::graph(int n)
{
    this->n = n;
    preq = new list<int>[n];
}
 
void graph::make(int v, int w)
{if(v==-1)
  return;
    preq[v].push_back(w);
}
 

void graph::topsort_help(int v,int visited[],stack<int> &Stack)
                                
{
    
    visited[v] = 1;

    list<int>::iterator i;
    for (i = preq[v].begin(); i != preq[v].end(); i++)
        if (!visited[*i])
            topsort_help(*i, visited, Stack);
 

    Stack.push(v);
}
 
int getind(char c[],char** courses)
{ 
   int j=0,k=0,flag;
   
   if(c[0]=='N')
      if(c[1]=='U')
         if(c[2]=='L')
            return -1;
    while(1)
    { flag=1;
       k=0;
         while(k!=5)
         {if(courses[j][k]!=c[k])
              {
                 flag=0;
                 break;
              }
              k++;
         }
         
        if(flag==0)
            j++;
            
       else if(flag==1)
            break;
    }
    return j;
}
void graph::topsort(int arr[])
{int j=0;
    stack<int> Stack;
 
 
    int *visited = new int[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
      if (visited[i] == 0)
            topsort_help(i, visited, Stack);

    while (Stack.empty() == 0)
    {   
        arr[j]=Stack.top();
        Stack.pop();
        j++;
    }
}

int main() {
int n;
char** courses;

cin>>n;

courses = new char*[n];

for(int l=0;l<n;l++)
   courses[l]=new char[100];
   
for(int l=0;l<n;l++)   
  cin>>courses[l];

 graph g(n);
 int k=-1;
 char num[100];
   
 string str;
    while(getline(cin, str)) 
    {
        istringstream ss(str);
        char num[100];
        while(ss >> num)
        {
          g.make(getind(num,courses),k);
        }
       k++;
    }
    
     g.topsort(g.arr);
 
    for(int x=0;x<n;x++)
     cout<<courses[g.arr[x]]<<" ";
	return 0;
}
