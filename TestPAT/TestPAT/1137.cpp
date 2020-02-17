#include "0.h"
int n,m,j,k,num=0;
string sn;
struct node{
    string id;
    int gp,gm=-1,gf=-1,g;
};
bool cmp(node &a,node &b){
    if(a.g!=b.g)return a.g>b.g;
    else return a.id<b.id;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1137.in","r", stdin);
    scanf("%d %d %d",&n,&j,&k);
    vector<node> v;
    unordered_map<string,int> m1;
    for(int i=0;i<n;i++){
        cin>>sn>>m;
        if(m>=200){
            m1[sn]=num;
            v.push_back({sn,m,-1,-1});
            num++;
        }
    }
    for(int i=1;i<=j;i++){
        cin>>sn>>m;
        if(m1[sn]!=0){
            v[m1[sn]].gm=m;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>sn>>m;
        if(m1[sn]!=0){
            v[m1[sn]].gf=m;
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i].gm<v[i].gf){
            v[i].g=v[i].gf;
        }else{
            v[i].g=(int)floor(v[i].gf*0.6+v[i].gm*0.4+0.5);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(v[i].g>=60){
            printf("%s %d %d %d %d\n",v[i].id.c_str(),v[i].gp,v[i].gm,v[i].gf,v[i].g);
        }
    }
    return 0;
}





