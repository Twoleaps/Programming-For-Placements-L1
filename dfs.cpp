#include<bits/stdc++.h>

using namespace std;

void dfs(vector <long int >a[],long int sn,int vi[])
{  vi[sn]=1;
   for(long int i=0;i<a[sn].size();i++)
      {
        if(vi[a[sn][i]]==0)
           {
              dfs(a,a[sn][i],vi);
           }

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
   dfs(a,x,vi);
  return 0; 
  }
