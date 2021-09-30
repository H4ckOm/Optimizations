#include<iostream>
#include<vector>
using namespace std;
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include <set>
#define ll long long int
#define ull unsigned long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mods 1000000007

knapsack(int a[],int n,int sum){
	int t[n+1][sum+1];
	
		
		for(int i=0;i<n+1;i++){
			  
				t[i][0]=1;
			
		}
		for(int i=1;i<sum+1;i++){
		
				t[0][i]=0;
			
		}
		
		for(int i=1;i<n+1;i++){
			for(int j=1;j<sum+1;j++){
				if(a[i-1]<=j){
					t[i][j]= (t[i-1][j - a [i-1]]) + t[i-1][j];
					
				}
				else{
					t[i][j]=t[i-1][j];
				}
			}
		}
		return (t[n][sum]);
	}

int main(){
	int t=1;
//	cin>>t;
	while(t--){
		int n,sum=0,sum1,s=0;
		cin>>n>>sum1;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			s=s+arr[i];
		}
		sum=((s+sum1)/2);
		//cout<<sum;
		sort(arr,arr+n);
		int p=knapsack(arr ,n ,sum);
		cout<<p<<"\n";
			
	}
}
