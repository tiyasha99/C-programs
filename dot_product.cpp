#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int max_dot_prod(vector<int> a,vector<int> b,int n)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i]*b[i];
    }
    return s;
}
int main()
{
  vector<int> a;
  vector<int> b;
  int n;
  cin>>n;
  int input;
  for(int i=0;i<n;i++)
  {
  	   cin>>input;
  	   
	   a.push_back(input);
  	 
  }
     
  for(int i=0;i<n;i++)
  {
  	   cin>>input;
  	   
	   b.push_back(input);
  	 
  }
  int ans=max_dot_prod(a,b,n);
  cout<<ans;


}
