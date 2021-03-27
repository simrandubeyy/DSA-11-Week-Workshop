//O(M*logN) solution
#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int low, int high)
{
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		
		if((mid==0 || arr[mid-1]==0) && arr[mid]==1)
		{
			return mid;
		}
		else if(arr[mid]==0)
		{
			return BinarySearch(arr,mid+1,high);
		}
		else if(arr[mid]==1 && arr[mid-1]==1)
		{
			return BinarySearch(arr,low,mid-1);
		}
	}
	return -1;
}

pair<int,int> count(vector<vector<int> > arr,int r,int c)
{
  	int final_count=INT_MIN, count=0, max_index=-1;
  	
  	for(int i=0; i<r; i++)
	  {
	  	int index=BinarySearch(arr[i],0,c-1);
	  	
	  	if(index!=-1)
		  {
		  	if((c-index)>final_count)
			  {
			  	final_count=c-index;
			  	max_index=i;
			  } 
		  }
	  }
  		
	return {final_count,max_index};	
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
