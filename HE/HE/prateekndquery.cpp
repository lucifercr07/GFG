#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];

	sort(vec.begin(),vec.end());
	//for(int i=0;i<n;i++)
	//	cout<<vec[i]<<" ";
	//cout<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		vector<int>::iterator low,up,it;
		low=lower_bound(vec.begin(),vec.end(),a);
		up=upper_bound(vec.begin(),vec.end(),b);
		int count=0;
		if(*low==0&&*up==0)
		{

		}
		else if(*low!=0&&*up==0)
		{
			for(it=low;it!=vec.end();++it)
				count++;
		}
		else
		{
			for(it=low;it<up;++it)
				count++;
		}
		cout<<count<<endl;
		
	}
}