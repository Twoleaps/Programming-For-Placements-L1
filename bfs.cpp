#include<bits/stdc++.h>

using namespace std;

void bfs(vector <long int >a[],long int sn,int vi[])
{     queue <long int >q;
	q.push(sn);
	vi[sn]=1;
    while(q.size()!=0)
      {
      	 long int x=q.front();
      	 for(long int i=0;i<a[x].size();i++)
      	   {
      	     if(vi[a[x][i]]==0)
      	       {
      	       	vi[a[x][i]]=1;
      	       	q.push(a[x][i]);
      	       }
      	   }
      	  q.pop(); 
      }
} 

int main()
{
  long int n,m,x,y,i;
  cin>>n>>m;
  vector <long int >a[n+1];
  while(m--)
    {
      cin>>x>>y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    int vi[n+1];
   for(i=1;i<n+1;i++)
     vi[i]=0;
   bfs(a,x,vi);
  return 0; 
  }
