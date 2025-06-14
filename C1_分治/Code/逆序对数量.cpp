//逆序对的数量(归并排序的应用) 
//给定一个长度为 n的整数数列，请你计算数列中的逆序对的数量。

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int n; //input
int sequence[N];
int tmp[N];

int result = 0;

void mergeSort(int l,int r,int *se){
	if(l>=r)return;
	int mid = l+r>>1;
	//注意与快排的区别 
	mergeSort(l,mid,se),mergeSort(mid+1,r,se);
	int i = l,j = mid+1,k = 0;
	while(i<=mid && j<=r){
		if(se[i]<=se[j]){
			tmp[k++] = se[i++];
		}
		else{
			tmp[k++] = se[j++];
			result+=mid+1-i;  //mid+1-i 也就是当前分治情况下所有的逆序对数量 
		}
	}
	//防止有没操作完对的数
	while(i<=mid)tmp[k++] = se[i++];
	while(j<=r)tmp[k++] = se[j++];
	//扫尾，load sequence 2 the "sequence"array from tmp
	for(int i=l,j=0;i<=r;i++,j++)se[i] = tmp[j];
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>sequence[i];
	mergeSort(0,n-1,sequence);
//	for(int i = 0;i<n;i++)cout<<sequence[i]<<" ";
//	cout<<endl;
	cout<<result<<endl;
	return 0;
}
