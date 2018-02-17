//floyd-warshall  implementataion
#include <bits/stdc++.h>

using namespace std;
int a;

int main()
{
	int n,m,i,j,x,y,we;
	cin>>n>>m;
	a=n;
	int dis[n][n];
	for(i=0;i<n;i++)
	   {
	   	  for(j=0;j<n;j++)
	   	     {
	   	     	if(i==j)
	   	     	  dis[i][j]=0;
	   	     	else
	   	     	  dis[i][j]=INT_MAX;
	   	     }
	   }
	while(m--)
	   {
	   	  cin>>x>>y>>we;
	   	  dis[x-1][y-1]=we;
	   	  dis[y-1][x-1]=we;
	   }

	int k;
	for(k=0;k<n;k++)
	  {
	  	  for(i=0;i<n;i++)
	  	    {
	  	    	  for(j=0;j<n;j++)
	  	    	    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	  	    }
	  }
	return 0;
}
