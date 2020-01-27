#include "0.h"
int n,m,k;
vector<int> v;
struct tree{
    int data;
    tree *l,*r;
}*T;
tree* check(int low,int high){
    if(low<0||low>high)return NULL;
    tree *t=new tree;
    int minn=low;
    for(int j=low;j<=high;j++){
        if(v[minn]>v[j])minn=j;
    }
    t->data=v[minn];
    t->l=check(low,minn-1);
    t->r=check(minn+1,high);
    return t;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1167.in","r", stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        v.push_back(k);
    }
    T=check(0,n-1);
    int flag=0;
    queue<tree*> q;
    q.push(T);
    while(!q.empty()){
        tree *t=q.front();
        if(flag==1)cout<<" ";
        else flag=1;
        cout<<t->data;
        if(t->l)q.push(t->l);
        if(t->r)q.push(t->r);
        q.pop();
    }
    return 0;
}

