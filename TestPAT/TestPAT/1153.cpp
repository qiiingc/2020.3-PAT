#include "0.h"
int n,m,k,u,w;
string s;
map<string,int> mp;
struct node{
    string id;
    int score;
};
bool cmp(node &a,node &b){
    return a.score==b.score?a.id<b.id:a.score>b.score;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1153.in","r", stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>s>>k;
        mp[s]=k;
    }
    for(int i=1;i<=m;i++){
        cin>>k>>s;
        printf("Case %d: %d %s\n",i,k,s.c_str());
        map<string,int>::iterator it;
        if(k==1){
            vector<node> v;
            for(it=mp.begin();it!=mp.end();it++){
                string x=it->first;
                if(x.substr(0,1)==s){
                    v.push_back({x,it->second});
                }
            }
            if(v.size()==0){
                printf("NA\n");
                continue;
            }
            sort(v.begin(),v.end(),cmp);
            for(auto j:v){
                printf("%s %d\n",j.id.c_str(),j.score);
            }
        }else if(k==2){
            int num=0,total=0;
            for(it=mp.begin();it!=mp.end();it++){
                string x=it->first;
                if(x.substr(1,3)==s){
                    num++;
                    total+=it->second;
                }
            }
            if(num==0){
                printf("NA\n");
                continue;
            }
            printf("%d %d\n",num,total);
        }else if(k==3){
            vector<node> v;
            for(it=mp.begin();it!=mp.end();it++){
                string x=it->first;
                bool f=false;
                if(x.substr(4,6)==s){
                    for(auto j:v){
                        if(j.id==x.substr(1,3)){
                            it->second++;
                            f=true;
                        }
                    }
                    if(!f)v.push_back({x.substr(1,3),1});
                }
            }
            if(v.size()==0){
                printf("NA\n");
                continue;
            }
            sort(v.begin(),v.end(),cmp);
            for(auto j:v){
                printf("%s %d\n",j.id.c_str(),j.score);
            }
        }else {
            printf("NA\n");
        }
    }
    return 0;
}



