#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int n, k;

/**
输入格式：第一行为个数n，第二行输入n个数字，第三行输入序号k
输出格式：一个数字，输出第k小的数字 
**/ 
 
int partition(int left, int right){  // 分区函数 
	int pivot =  arr[right];  // 把最右边的值作为基准值 
	int i = left;
	
	for (int j=left; j<right; j++){  // 将小于/大于基准值的分别排到基准值左边/右边 
		if (arr[j]<=pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[right]);
	return i;  // 返回基准值的位置（同时也是代表这是整列数中第i小的元素） 
}

int select(int left, int right, int k){
	if (left == right) return arr[left];
	int pivotIndex = partition(left, right);  // 选择基准值并分区 
	if (k == pivotIndex) return arr[pivotIndex];  // 如果基准值的大小序号等于要求的k，返回 
	if (k < pivotIndex) return select(left, pivotIndex-1, k);  // 否则在左边查找第k小的元素 
	else return select (pivotIndex+1, right, k);  // 否则在右边找 
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	printf("%d", select(0, n-1, k-1));  // 因为列表序号从0开始所以需要k-1 
}
