#include <iostream>
//#include <stack>

using namespace std;

int top();
int stack[100000];
void pop();
void push(int);
int head=-1;
int main()
{
	int n;
	cin>>n;
	int num;
	//stack<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		if(num==1)
		{
			if(head==-1)
				cout<<"No Food"<<endl;
			else
				{
					cout<<top()<<endl;
					pop();
				}
		}
		else if(num==2)
		{
			int c;
			cin>>c;
			push(c);
		}
		else
			cout<<"Error"<<endl;
	}
}

int top()
{
	if(head==-1)
		cout<<"ERROR";
	else
		return stack[head];

}

void push(int x)
{
	if(head==-1)
	{
		head=0;
		stack[head]=x;
	}
	else
	{
		stack[++head]=x;
	}
}

void pop()
{
	if(head==-1)
		cout<<"ERROR";
	else
		head--;
}