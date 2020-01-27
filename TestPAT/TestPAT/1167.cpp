#include "0.h"
int n,m,k,maxx=0;
vector<int> v;
int t[10000];
void check(int i,int low,int high){
    if(low<0||low>high)return;
    int minn=low;
    for(int j=low;j<=high;j++){
        if(v[minn]>v[j])minn=j;
    }
    if(i>maxx)maxx=i;
    t[i]=v[minn];
    check(2*i,low,minn-1);
    check(2*i+1,minn+1,high);
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1167.in","r", stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        v.push_back(k);
    }
    check(1,0,n-1);
    
    int flag=0;
    for(int i=1;i<=maxx;i++){
        if(t[i]>0){
            if(flag==1)cout<<" ";
            flag=1;
            cout<<t[i];
        }
    }
    return 0;
}

