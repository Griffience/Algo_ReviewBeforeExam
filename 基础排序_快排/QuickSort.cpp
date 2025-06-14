//快排本质上其实也是属于递归分治 
//相比于冒泡这些，个人更喜欢快排，所以本代码只写快排的
//若是生涩难懂看不懂鄙人的代码，请自行到acwing/CSDN/洛谷/牛客/力扣/... 上查看快排思路 

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010;
int sequence[N];
int n;

void quickSort(int L,int R,int *se){
	if(L>=R)return;
	int i = L-1,j = R+1;
	int mid = se[i+j>>1];   //令pivot数 = sequence[i+j 整除2] 也就是找序列中间的作为pivot 
	
	//core method
	while(i<j){
		do i++; while(se[i]<mid);
		do j--; while(se[j]>mid);
		if(i<j)swap(se[i],se[j]);
	}
	//递归(快排相比于归并排序，是后递归分治，二归并则是先递归分治) 
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
