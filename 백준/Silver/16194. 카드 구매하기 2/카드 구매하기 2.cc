#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<int> v(n),d(n+1);
	for(int&i:v)cin>>i;
	for(int i=0;i<n;i++){
		d[i]=v[i];
		for(int l=0,r=i-1;l<=r;)
			d[i]=min(d[i],d[l++]+d[r--]);
	}
	cout<<d[n-1];
}