#include "0.h"
struct node{
    int id,data,next;
};
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1133.in","r", stdin);
    
    int begin, n, k, s, d, e;
    cin>>begin>>n>>k;
    node a[100010];
    vector<node> v,ans;
    for(int i=0;i<n;i++){
        scanf("%d%d%d\n",&s,&d,&e);
        a[s]={s,d,e};
        
    }
    for(;begin!=-1;begin=a[begin].next){
        v.push_back(a[begin]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data<0)ans.push_back(v[i]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data>=0 && v[i].data<=k)ans.push_back(v[i]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i].data>k)ans.push_back(v[i]);
    }
    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1)printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
        else printf("%05d %d -1",ans[i].id,ans[i].data);
    }
    return 0;
}
