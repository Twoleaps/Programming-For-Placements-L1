#include <bits/stdc++.h>
using namespace std;

long long int prim(long int sn,vector <pair <long int ,long int > >a[],long int n)
{   long int i,pa,temp;
	priority_queue <pair <long int ,long int >,vector <pair <long int ,long int > >,greater <pair <long int ,long int > > >q;
	q.push({0,sn});
	int mar[n+1];
	for(i=1;i<n+1;i++)
	  mar[i]=0;
	//mar[sn]=1;
	long long int min1=0;
	while(q.size()!=0)
	  {	//pair <long int ,long int >pa;

	  	  pa=q.top().second;
	  	  temp=q.top().first;
	  	  q.pop();
	  	  if(mar[pa]==1)
	  	    continue;
	  	  mar[pa]=1;
	  	  min1+=temp;
	  	  for(i=0;i<a[pa].size();i++)
	  	    {
	  	    	if(mar[a[pa][i].second]==0)
	  	    	  {
	  	    	  	 q.push(a[pa][i]);
	  	    	  }
	  	    }
	  }
	return min1;
}
int main() {
    long int n,m,x,y,we;
	cin>>n>>m;
	vector <pair<long int ,long int > >a[n+1];
	while(m--)
	{
		 cin>>x>>y>>we;
		 a[x].push_back({we,y});
		 a[y].push_back({we,x});
	}
	cout<<prim(1,a,n)<<"\n";
	// your code goes here
	return 0;
}
