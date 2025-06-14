//���ű�������ʵҲ�����ڵݹ���� 
//�����ð����Щ�����˸�ϲ�����ţ����Ա�����ֻд���ŵ�
//������ɬ�Ѷ����������˵Ĵ��룬�����е�acwing/CSDN/���/ţ��/����/... �ϲ鿴����˼· 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int sequence[N];
int n;

void quickSort(int L,int R,int *se){
	if(L>=R)return;
	int i = L-1,j = R+1;
	int mid = se[i+j>>1];   //��pivot�� = sequence[i+j ����2] Ҳ�����������м����Ϊpivot 
	
	//core method
	while(i<j){
		do i++; while(se[i]<mid);
		do j--; while(se[j]>mid);
		if(i<j)swap(se[i],se[j]);
	}
	//�ݹ�(��������ڹ鲢�����Ǻ�ݹ���Σ����鲢�����ȵݹ����) 
	quickSort(L,j,se),quickSort(j+1,R,se);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>sequence[i];
	quickSort(0,n-1,sequence);
	//output result
	for(int i=0;i<n;i++)cout<<sequence[i]<<" ";
	cout<<endl;
	return 0;
} 
