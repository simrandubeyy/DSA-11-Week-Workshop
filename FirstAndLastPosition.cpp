//https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int first(vector<int>temp,int n,int x)
{
   int left=0, right=temp.size()-1;
   int first_x=-1;
   
   while(left<=right)
   {
   	 int mid=left+(right-left)/2;
   	 
   	 if(temp[mid]==x)
	{
		first_x=mid;
		right=mid-1;	
	}
	else if(temp[mid]>x)
	{
		right=mid-1;	
	}
	else if(temp[mid]<x)
	{
		left=mid+1;
	}
   }
   
   return first_x;
}


last(vector<int>temp,int n,int x)
{
   int left=0, right=temp.size()-1;
   int last_x=-1;
   
   while(left<=right)
   {
   	 int mid=left+(right-left)/2;
   	 
   	 if(temp[mid]==x)
	{
		last_x=mid;
		left=mid+1;	
	}
	else if(temp[mid]>x)
	{
		right=mid-1;	
	}
	else if(temp[mid]<x)
	{
		left=mid+1;
	}
   }
   
   return last_x;	
}

int main()
{
  int n,x;
  vector<int> temp;
  
  cout<<"Enter number of array you want \n";
  cin>>n;
  
  cout<<"Enter the numbers \n";
  
  for(int i=0; i<n; i++)
  {
  	int input;
  	cin>>input;
  	temp.push_back(input);
  }
  
  cout<<"Enter the value for first and last occuernce \n";
  cin>>x;
  
  int f=first(temp,n,x);
  int l=last(temp,n,x);
  
  cout<<"The first occuernce is :"<<" "<<f<<"\n";
  cout<<"The last occuernce is :"<<" "<<l;	
  
	return 0;
}
