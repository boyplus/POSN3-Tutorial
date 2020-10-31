#include <iostream>
void merge(int* arr,int L,int M,int R){
	int t[500001] = {0};
	int i = L, j = M+1;
	for(int k=L;k<=R;k++){
		if(i > M){
			t[k] = arr[j++];
			continue;
		}
		if(j > R){
			t[k] = arr[i++];
			continue;
		}
		if(arr[i] < arr[j]){
			t[k] = arr[i++];
		} else{
			t[k] = arr[j++];
		}
	}
	//copy answer to original array
	for(int k=L;k<=R;k++){
		arr[k] = t[k];
	}
}
void mergeSort(int* arr,int L,int R){
	//base case
	if(L >= R){
		return;
	}
	int M = (L+R)/2;
	mergeSort(arr,L,M);
	mergeSort(arr,M+1,R);
	merge(arr,L,M,R);
}
int main() {
	int arr[7] = {38,27,43,3,9,82,10};
	mergeSort(arr,0,6);
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
