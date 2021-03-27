//0(m*n) solution
#include<bits/stdc++.h>
using namespace std;

pair<int,int> count(vector<vector<int> > arr,int r,int c)
{
  	int final_count=INT_MIN, count=0,index=-1;
  	
  	for(int i=0; i<r; i++)
	  {
	  	for(int j=0; j<c; j++)
		  {
		  	if(arr[i][j]==1)
			  {
			  	count++;
			  }
		  }
		  
		  if(count>final_count)
		  {
		  	final_count=count;
		  	index=i;
		  }
		  count=0;
	  }
	
	return {final_count,index};	
}

void print(vector<vector<int> > arr,int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		 cout<<"\n";
	}
}

int main()
{
	  int r,c;
	  vector<int> temp;
	  
	  cout<<"Enter row size of matrix \n";
	  cin>>r;
	  
	  cout<<"Enter row size of matrix \n";
	  cin>>c;
	  
	  vector< vector<int> > arr(r,vector<int>(c));
	  
	  cout<<"Enter the numbers \n";
	  
  	  for(int i=0; i<r; i++)
	  {
	  	for(int j=0; j<c; j++)
		  {
		  	cin>>arr[i][j];
		  }
	  }
 
	  print(arr,r,c);
	  
	  pair<int, int> p = count(arr,r,c);
	  cout<<p.second<<" contains max number of 1 "<<p.first<<endl;
	
	return 0;
}
