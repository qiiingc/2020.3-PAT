#include "0.h"
struct node{
    string data;
    int l,r;
};
vector<node> v;
string f(int x){
    if(v[x].l==-1 && v[x].r==-1){
        return "("+v[x].data+")";
    }
    if(v[x].l==-1 && v[x].r!=-1){
        return "("+v[x].data+f(v[x].r)+")";
    }
    return "("+f(v[x].l)+f(v[x].r)+v[x].data+")";
    
}
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1162.in","r", stdin);
    int n;
    scanf("%d\n",&n);
    v.resize(n+1);
    vector<int> a(n+1);
    a.clear();
    for(int i=1;i<=n;i++){
        cin>>v[i].data>>v[i].l>>v[i].r;
        if(v[i].l!=-1)a[v[i].l]=1;
        if(v[i].r!=-1)a[v[i].r]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cout<<f(i);
            break;
        }
    }
    
    return 0;
}




