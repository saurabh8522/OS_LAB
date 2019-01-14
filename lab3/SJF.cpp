#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)

using namespace std;


void printall(int n, vector< pair<int,int> > burstArrival)
{
	sort(burstArrival.begin(),burstArrival.end());
	int wait[n],completion[n],wait1[n];
	completion[0] = burstArrival[0].first;
	int tat[n];
	wait1[0] = burstArrival[0].second;
	tat[0]=completion[0] - burstArrival[0].second;
	int twt=0,ttat=tat[0];
	f(i,1,n)
	{	
		if(burstArrival[i].second <= completion[i-1])
		completion[i] = completion[i-1] + burstArrival[i].first;
		else 
			completion[i] = completion[i-1] + burstArrival[i].second +burstArrival[i].first;
		tat[i] = completion[i]-burstArrival[i].second;
		wait1[i] = tat[i]-burstArrival[i].first;
		ttat += tat[i];
		twt += wait1[i];

	}
	ttat /=n;
	twt /=n;
	cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";	
	
	f(i,0,n)
		cout<<i<<"\t\t"<<burstArrival[i].second<<"\t\t"<<burstArrival[i].first<<"\t\t"<<completion[i]<<"\t\t\t"<<tat[i]<<"\t\t\t"<<wait1[i]<<"\n";
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
	vector< pair<int ,int> > burstArrival(n);
	f(i,0,n)
	{
		cin>>temp1>>temp2;
		burstArrival[i].first = temp2;
		burstArrival[i].second = temp1;
	}
	printall(n,burstArrival);
}
