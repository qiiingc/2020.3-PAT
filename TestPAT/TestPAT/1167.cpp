#include "0.h"
int n,m,k,maxx=0;
vector<int> v;
int t[10000];
int findmin(int s,int e){
    if(s<0||s>e)return -1;
    int minn=s;
    for(int i=s;i<=e;i++){
        if(v[minn]>v[i])minn=i;
    }
    //cout<<v[minn]<<endl;
    return minn;
}
void check(int i,int low,int high){
    int mid=findmin(low,high);
    if(mid!=-1){
        if(i>maxx)maxx=i;
        t[i]=v[mid];
    }
    if(low<=mid-1)check(2*i,low,mid-1);
    if(mid+1<=high)check(2*i+1,mid+1,high);
}
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1167.in","r", stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        v.push_back(k);
    }
    check(1,0,n-1);
    
    int cnt=n,flag=0;
    for(int i=1;i<=maxx;i++){
        if(t[i]>0){
            if(flag==1)cout<<" ";
            flag=1;
            cout<<t[i];
            cnt--;
        }
    }
    return 0;
}

