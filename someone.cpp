#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,m,k;
  cin>>n>>m>>k;
  long long int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  long long int max=arr[n-1];
  long long int max2=arr[n-2];
  long long int s=arr[n-1];
  int count =1;
  for(int i=2;i<=m;i++)
  {
    
    if(count ==2)
    {
      s+=max2;
      count=0;

    }
    
    else{
      s+=max;
      count++;
    }
  }
  cout<<s;
  

  

    
  
    return 0;
 
}
