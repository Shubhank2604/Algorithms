/*Max Heap Sort*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
int parent(int i)
{
	return ((i-1)/2);
}
int left_child(int i)
{
	return (2*i+1);
}
int right_child(int i)
{
	return (2*i+2);
}
void heapify(int v[], int n,int i)
{
	int left=left_child(i);
	int right=right_child(i);
	int smallest=i;
	if(left<n && v[left]<v[smallest])
		smallest=left;
	if(right<n && v[right]<v[smallest])
		smallest=right;
	if(smallest != i)
	{
		int temp=v[smallest];
		v[smallest]=v[i];
		v[i]=temp;
		heapify(v,n,smallest);
	}
}

void build_heap(int v[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(v,n,i);
	for(int i=n-1;i>0;i--)
	{
		int temp=v[0];
		v[0]=v[i];
		v[i]=temp;
		heapify(v,i,0);
	}
}
int main ()
{
	#ifndef ONLINE_JUDGE
		freopen("ip.txt", "r" , stdin);
		freopen("op.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		int v[k*k];
		for (int i = 0; i < k*k; ++i)
			cin>>v[i];
		build_heap(v,k*k);
		for (int i = 0; i < k*k; ++i)
			cout<<v[i]<<" ";
		cout<<"\n";
	}
}
