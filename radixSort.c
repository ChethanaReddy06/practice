#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void countSort(int arr[],int n,int place){
	int count[10];
	for(int i=0;i<10;i++){
		count[i]=0;
	}
	
	for(int i=0;i<n;i++){
		count[(arr[i]/place)%10]++;
	}
	//printArray(count,10);
	for(int i=1;i<10;i++){
		count[i]=count[i]+count[i-1];
	}
	int output[n];
	for(int i=0;i<n;i--){
		count[(arr[i]/place)%10]--;
		output[count[(arr[i]/place)%10]]=arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i]=output[i];
	}
}
int maximum(int arr[],int n){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void RadixSort(int arr[],int n){
	int max=maximum(arr,n);
	for(int place=1;max/place>0;place*=10){
		countSort(arr,n,place);
	}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[5]={212,429,519,212,119};
	int n=sizeof(arr)/sizeof(arr[0]);
	RadixSort(arr,n);
	printArray(arr,n);
}
