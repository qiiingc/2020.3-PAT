#include "0.h"
struct node{
    int id,data,next;
};
node a[1000005];
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1161.in","r", stdin);
    int ba,bb,n,s,d,e;
    scanf("%d %d %d\n",&ba,&bb,&n);
    vector<node> va,vb,ans;
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&s,&d,&e);
        a[s]={s,d,e};
    }
    for(;ba!=-1;ba=a[ba].next){
        va.push_back(a[ba]);
    }
    for(;bb!=-1;bb=a[bb].next){
        vb.push_back(a[bb]);
    }
    if(va.size()>vb.size()){
        int j=(int)vb.size()-1;
        for(int i=0;i<va.size();i++){
            if(i>0 && i%2==0 && j>=0){
                ans.push_back(vb[j]);
                j--;
            }
            ans.push_back(va[i]);
            if(i==va.size()-1 && j==0){
                ans.push_back(vb[j]);
            }
        }
    }else {
        int j=(int)va.size()-1;
        for(int i=0;i<vb.size();i++){
            if(i>0 && i%2==0 && j>=0){
                ans.push_back(va[j]);
                j--;
            }
            ans.push_back(vb[i]);
            if(i==vb.size()-1 && j==0){
                ans.push_back(va[j]);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1)printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
        else printf("%05d %d -1",ans[i].id,ans[i].data);
    }
    return 0;
}
