//disjkstra algo for single source shortest parth
#include <bits/stdc++.h>
using namespace std;

void disj(vector <pair <long int ,long int > >a[],int vi[],long int dis[],long int n,long int sn)
{
	priority_queue<pair <long int ,long int > ,vector< pair <long int ,long int > > ,greater <pair <long int ,long int > > >q;
	q.push({0,sn});
	while(q.size()!=0)
	  {	long int x,b,i;
	  	  x=q.top().first;
	  	  b=q.top().second;
	  	  q.pop();
	  	  if(vi[b]==1)
	  	     continue;
	  	vi[b]=1;     
	  	  for(i=0;i<a[b].size();i++)
	  	     {
	  	     	if(vi[a[b][i].second]==0 && dis[a[b][i].second] > dis[b]+a[b][i].first){    	 
	  	     	    	 dis[a[b][i].second]=dis[b]+a[b][i].first;
	  	     		 q.push({dis[a[b][i].second],a[b][i].second});
	  	     		 //q.push(a[b][i]);
	  	     	}
	  	     }
	  }
}




int main()
{    ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
	 long int n,m,x,y,we,sn,i;
	 cin>>n>>m;
	 vector < pair <long int ,long int > >a[n+1];
	 while(m--)
	   {
	   	  cin>>x>>y>>we;
	   	  a[x].push_back({we,y});
	   	 //a[y].push_back({we,x});
	   }
	 long int dis[n+1];
	 int vi[n+1];
	 for(i=0;i<n+1;i++)
	    {
	    	dis[i]=INT_MAX;
	    	vi[i]=0;
	    }
	 sn=1;
	dis[sn]=0;
	disj(a,vi,dis,n,sn);
	for(i=2;i<n+1;i++)
	   cout<<dis[i]<<" ";
	   return 0;
}
