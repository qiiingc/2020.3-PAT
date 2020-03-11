#include "0.h"
int pre[35];
struct tree{
    int val;
    struct tree *l,*r;
};
tree *build(tree *root,int data){
    if(root==NULL){
        root=new tree;
        root->val=data;
        root->l=root->r=NULL;
    }else if(abs(root->val)>=abs(data)){
        root->l=build(root->l,data);
    }else{
        root->r=build(root->r,data);
    }
    return root;
}
bool judge1(tree *root){
    if(root==NULL)return true;
    if(root->val<0){
        if(root->l!=NULL && root->l->val<0)return false;
        if(root->r!=NULL && root->r->val<0)return false;
    }
    return judge1(root->l) && judge1(root->r);
}
int getNum(tree *root){
    if(root==NULL)return 0;
    int lh=getNum(root->l);
    int rh=getNum(root->r);
    return root->val>0?max(lh,rh)+1:max(lh,rh);
}
bool judge2(tree *root){
    if(root==NULL)return true;
    if(getNum(root->l)!=getNum(root->r))return false;
    return judge2(root->l) && judge2(root->r);
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1135.in","r", stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        tree *T=NULL;
        for(int i=0;i<m;i++){
            scanf("%d",&pre[i]);
            T=build(T, pre[i]);
        }
        if(pre[0]<0 || !judge1(T) || !judge2(T)){
            printf("No\n");
        }else printf("Yes\n");
    }
    return 0;
}
