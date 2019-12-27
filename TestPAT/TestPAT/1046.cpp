#include "0.h"
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1046.in","r", stdin);
    int n,m,s=0,v,w;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        a[i]=s;
        cin>>v;
        s+=v;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>v>>w;
        if(v>w){
            swap(v, w);
        }
        if(a[w]-a[v]>s/2){
            cout<<s-a[w]+a[v]<<endl;
        }else{
            cout<<a[w]-a[v]<<endl;
        }
    }
    return 0;
}
