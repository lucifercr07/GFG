#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	vector<long long> vec(n);
	for(long long i=0;i<n;i++)
		cin>>vec[i];

	long long flag=0,sum1=0,sum2=0;
	for(long long i=0;i<n;i++)
	{
		if(i%2==0)
			sum1+=vec[i];
		if(i%2!=0)
			sum2+=vec[i];
		
	}

	if(sum1==sum2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}