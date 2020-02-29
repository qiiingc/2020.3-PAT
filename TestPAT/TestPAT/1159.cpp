#include "0.h"
int post[maxn],in[maxn];
struct node{
    int l,r,depth,parent;
};
map<int,node> tree;
bool fullTree=true;
int build(int pe,int is,int ie,int dpt,int prt){
    if(is>ie)return -1;
    tree[post[pe]].depth=dpt;
    tree[post[pe]].parent=prt;
    int i=is;
    while(i<ie && in[i]!=post[pe])i++;
    tree[post[pe]].l=build(pe-ie+i-1,is,i-1,dpt+1,post[pe]);
    tree[post[pe]].r=build(pe-1,i+1,ie,dpt+1,post[pe]);
    if(tree[post[pe]].l==-1 && tree[post[pe]].r!=-1)fullTree=false;
    if(tree[post[pe]].l!=-1 && tree[post[pe]].r==-1)fullTree=false;
    return post[pe];
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1159.in","r", stdin);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&post[i]);
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    int root=build(n-1, 0, n-1, 0, -1);
    scanf("%d\n",&m);
    string s1,s2,s3,s4,s5,s6,s7;
    for(int i=0;i<m;i++){
        bool yeah=false;
        cin>>s1>>s2;
        if(s2=="and"){
            cin>>s3>>s4>>s5;
            if(s5=="siblings"){
                if(tree[stoi(s1)].parent==tree[stoi(s3)].parent)yeah=true;
            }else{//same level
                if(tree[stoi(s1)].depth==tree[stoi(s3)].depth)yeah=true;
            }
        }else{
            cin>>s3>>s4;
            if(s4=="root"){
                if(root==stoi(s1))yeah=true;
            }else if(s4=="parent"){
                cin>>s5>>s6;
                if(tree[stoi(s6)].parent==stoi(s1))yeah=true;
            }else if(s4=="left"){
                cin>>s5>>s6>>s7;
                if(tree[stoi(s7)].r==stoi(s1))yeah=true;
            }else if(s4=="right"){
                cin>>s5>>s6>>s7;
                if(tree[stoi(s7)].r==stoi(s1))yeah=true;
            }else{//full tree
                if(fullTree)yeah=true;
            }
        }
        if(yeah)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
