#include "0.h"
struct node{
    int id,data,next;
}a[1000005];
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1165.in","r", stdin);
    
    int begin,n,k,s,d,e;
    cin>>begin>>n>>k;
    vector<node> v,ans;
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&s,&d,&e);
        a[s]={s,d,e};
    }
    for(;begin!=-1;begin=a[begin].next){
        v.push_back(a[begin]);
    }
    int len=v.size(),j=0;
    int m;
    int remain=len%k;
    ans.resize(len);
    for(int i=0;i<len;i++){
        if(i<len-remain){
            m=len/k-i/k-1;
            ans[k*m+j+remain]=v[i];
            j=(j+1)%k;
        }else{
            ans[i%k]=v[i];
        }
    }
    for(int i=0;i<len;i++){
        if(i!=len-1){
            printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
        }else{
            printf("%05d %d -1",ans[i].id,ans[i].data);
        }
    }
    return 0;
}
