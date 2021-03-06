//O(n) time complexity


#include<iostream>
#include<stack>

using namespace std;

void printNGE(int arr[],int n)
{
	stack<int> s;
	s.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		int next=arr[i];
		if(!s.empty())
		{
			int element=s.top();
			s.pop();
			while(element < next)
			{
				cout<<next<<" ";
				if(s.empty())
					break;
				else
				{	
					element=s.top();
					s.pop();
				}
			}
			if(element>next)
			s.push(element);
		}
		s.push(next);
		
	}
	while(!s.empty())
	{
			s.pop();
			cout<<"-1"<<" ";
	}

}

int main()
{
	int arr[]= {21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    //getchar();
    return 0;
	

}
