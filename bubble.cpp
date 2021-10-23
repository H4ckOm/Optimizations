#include<stdio.h>

int main()
{
	int n,i,j,temp,arr[50];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
    }
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("Jai mata di , Mandir vahi banege ")
	printf("ullahu akbhar")
	return 0;
}
