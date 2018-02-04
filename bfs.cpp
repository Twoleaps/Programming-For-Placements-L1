#include <bits/stdc++.h>
using namespace std;



int main() {
	int i,n,t,sno,x,y;
	cin>>n>>t;
	vector <int> a[n];
	queue < int > q;
	bool v[n];
	int st[n];
	for(i=0;i<n;i++)
	  {
	  	  v[n]=0;
	  	  st[i]=-1;
	  }
    while(t--)
      {
      	  cin>>x>>y;
      	  a[x].push_back(y);
      	  a[y].push_back(x);
      }
    cin>>sno;
    q.push(sno);
    v[sno]=1;
    st[sno]=0;
    while(q.size()!=0)
       {
       	  for(i=0;i<a[q.front()].size();i++)
       	    {   x=a[q.front()][i];
       	    	 if(st[x]==-1)
       	    	   {
       	    	   	  st[x]=1+st[q.front()];
       	    	   	  q.push(x);
       	    	   }
       	    }
       	   q.pop();
       }
     int  max1=0;
     for(i=0;i<n;i++)
       {
       	max1=max(max1,st[i]);
       }
      cout<<max1<<'\n';
	// your code goes here
	return 0;
}
