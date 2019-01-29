#include<bits/stdc++.h>
using namespace std;
struct process{
    int id,at,bt,ct,tat,wt,rt;
    bool done,qdone;
};
// bool check(struct process a[],int n)
// {
// 	bool com=true;
// 	for(int i=1;i<=n;++i)
// 		com=com&&(a[i].done);
// 	return com;
// }
void cal_res(struct process a[],int n,int t,int m){
    queue<struct process>q;
    vector<struct process>v;
    int curr_time=m;
    int count=0;
    while(count!=n)
    {
        for(int i=1;i<=n;i++)
        {
            if((a[i].at<=curr_time)&&(a[i].done==false)&&a[i].rt>0&&(a[i].qdone==false))
            {
                q.push(a[i]);
                a[i].qdone=true;
            }
        }
        struct process b= q.front();
        q.pop();
        
        if(b.rt>t){
            cout<<"b.rt="<<b.rt<<endl;
            b.rt-=t;
            curr_time+=t;
            q.push(b);
        }
        else if(b.rt==t){
            cout<<"b.rt="<<b.rt<<endl;
            b.done=true;
            b.rt-=t;
            curr_time+=t;
            b.ct=curr_time;
            b.tat=b.ct-b.at;
            b.wt=b.tat-b.bt;
            cout<<"b.id="<<b.id<<"b.ct="<<b.ct<<"b.tat="<<b.tat<<"b.wt"<<b.wt<<endl;
            count++;
            v.push_back(b);
        }
        else{
            cout<<"p.id="<<b.id<<"b.rt="<<b.rt<<endl;
            b.done=true;
            curr_time+=b.rt;
            b.rt=0;
            
        b.ct=curr_time;
            b.tat=b.ct-b.at;
            b.wt=b.tat-b.bt;
            cout<<"b.ct="<<b.ct<<"b.tat="<<b.tat<<"b.wt"<<b.wt<<endl;
            count++;
            v.push_back(b);
        }
    }
    cout<<"process no\t"<<"arrival no\t"<<"burst time\t"<<"completion time\t\t"<<"turn around time\t"<<"waiting time\n";
	for(int i=0;i<=n-1;++i)
	{
		cout<<v[i].id<<"\t\t"<<v[i].at<<"\t\t"<<v[i].bt<<"\t\t"<<v[i].ct<<"\t\t\t"<<v[i].tat<<"\t\t\t"<<v[i].wt<<"\n";
	}
}
int main(){
     int n,at,bt;
     cout<<"Enter no. of processes:"<<endl;
     cin>>n;
     struct process a[n+1];
     cout<<"Enter arrival time and burst times:"<<endl;
     int mi= INT_MAX;
     for(int i=1;i<=n;i++)
     {
         cin>>at>>bt;
         a[i].id=i;
         a[i].at=at;
         a[i].bt=bt;
         a[i].rt=bt;
         a[i].done=false;
         a[i].qdone=false;
         if(mi>at)
            mi=at;
     }
     cout<<"Enter quantum time:"<<endl;
     int t;
     cin>>t;
     if(mi!=0)
     {
         cout<<"Cpu is idle from"<<0<<"to"<<mi<<"seconds"<<endl;
     }
     cal_res(a,n,t,mi);
     
}
