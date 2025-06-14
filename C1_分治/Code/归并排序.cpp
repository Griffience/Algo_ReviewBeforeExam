//�鲢(�ϲ�)����
//���˸о�����ڿ����̣�������ĸ��ʴ�һ�㣬��Ϊ������д�����ʱ��Ҫ�̺ܶ࣬����ģ��ñ�

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int n; //input
int sequence[N];
int tmp[N];

void mergeSort(int l,int r,int *se){
	if(l>=r)return;
	int mid = l+r>>1;
	//ע������ŵ����� 
	mergeSort(l,mid,se),mergeSort(mid+1,r,se);
	int i = l,j = mid+1,k = 0;
	while(i<=mid && j<=r){
		if(se[i]<=se[j]){
			tmp[k++] = se[i++];
		}
		else{
			tmp[k++] = se[j++];
		}
	}
	//��ֹ��û������Ե���
	while(i<=mid)tmp[k++] = se[i++];
	while(j<=r)tmp[k++] = se[j++];
	//ɨβ��load sequence 2 the "sequence"array from tmp
	for(int i=l,j=0;i<=r;i++,j++)se[i] = tmp[j];
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>sequence[i];
	mergeSort(0,n-1,sequence);
	for(int i = 0;i<n;i++)cout<<sequence[i]<<" ";
	cout<<endl;
	return 0;
}
