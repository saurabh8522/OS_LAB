#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)

using namespace std;


void printall(int n, vector< pair<int,int> > arrivalBurst)
{
	sort(arrivalBurst.begin(),arrivalBurst.end());
	int wait[n],completion[n],wait1[n];
	completion[0] = arrivalBurst[0].second;
	int tat[n];
	wait1[0] = arrivalBurst[0].first;
	tat[0]=arrivalBurst[0].second;
	int twt=0,ttat=tat[0];
	completion[0] = arrivalBurst[0].second;
	f(i,1,n)
	{	
		if(arrivalBurst[i].first <= completion[i-1])
		completion[i] = completion[i-1] + arrivalBurst[i].second;
		else 
			completion[i] = completion[i-1] + arrivalBurst[i].first +arrivalBurst[i].second;
		tat[i] = completion[i]-arrivalBurst[i].first;
		wait1[i] = tat[i]-arrivalBurst[i].second;
		ttat += tat[i];
		twt += wait1[i];

	}
	ttat /=n;
	twt /=n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";	
	
	f(i,0,n)
		cout<<i<<"\t\t"<<arrivalBurst[i].first<<"\t\t"<<arrivalBurst[i].second<<"\t\t"<<completion[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait1[i]<<"\n";
	cout<<"average waiting time is:"<<twt<<"\n average turn around time is:"<<ttat<<"\n";
}
int main()
{
	int n,temp1,temp2;
	cout<<"Enter number of processes:";
	cin>>n;
	int processes[n];
	f(i,0,n)
	{
		processes[i] = i+1;
	}
	cout<<"Enter arrival time and burst time\n";
	int burst[n];
	int arrival[n];
	vector< pair<int ,int> > arrivalBurst(n);
	f(i,0,n)
	{
		cin>>temp1>>temp2;
		arrivalBurst[i].first = temp1;
		arrivalBurst[i].second = temp2;
	}
	printall(n,arrivalBurst);
}
