#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
int n, k;

/**
�����ʽ����һ��Ϊ����n���ڶ�������n�����֣��������������k
�����ʽ��һ�����֣������kС������ 
**/ 
 
int partition(int left, int right){  // �������� 
	int pivot =  arr[right];  // �����ұߵ�ֵ��Ϊ��׼ֵ 
	int i = left;
	
	for (int j=left; j<right; j++){  // ��С��/���ڻ�׼ֵ�ķֱ��ŵ���׼ֵ���/�ұ� 
		if (arr[j]<=pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[right]);
	return i;  // ���ػ�׼ֵ��λ�ã�ͬʱҲ�Ǵ��������������е�iС��Ԫ�أ� 
}

int select(int left, int right, int k){
	if (left == right) return arr[left];
	int pivotIndex = partition(left, right);  // ѡ���׼ֵ������ 
	if (k == pivotIndex) return arr[pivotIndex];  // �����׼ֵ�Ĵ�С��ŵ���Ҫ���k������ 
	if (k < pivotIndex) return select(left, pivotIndex-1, k);  // ��������߲��ҵ�kС��Ԫ�� 
	else return select (pivotIndex+1, right, k);  // �������ұ��� 
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	printf("%d", select(0, n-1, k-1));  // ��Ϊ�б���Ŵ�0��ʼ������Ҫk-1 
}
