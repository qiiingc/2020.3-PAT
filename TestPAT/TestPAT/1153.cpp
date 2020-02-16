#include "0.h"
int n,m,k,num=0,total=0;
string s;
struct node{
    string id;
    int value;
};
bool cmp(node &a,node &b){
    return a.value==b.value?a.id<b.id:a.value>b.value;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1153.in","r", stdin);
    scanf("%d %d",&n,&m);
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].id>>v[i].value;
    }
    for(int i=1;i<=m;i++){
        cin>>k>>s;
        printf("Case %d: %d %s\n",i,k,s.c_str());
        vector<node> ans;
        if(k==1){
            for(auto it:v){
                if(it.id.substr(0,1)==s){
                    ans.push_back(it);
                }
            }
            if(ans.size()==0){
                printf("NA\n");
                continue;
            }
            sort(ans.begin(),ans.end(),cmp);
            for(auto j:ans){
                printf("%s %d\n",j.id.c_str(),j.value);
            }
        }else if(k==2){
            num=0;
            total=0;
            for(auto it:v){
                if(it.id.substr(1,3)==s){
                    num++;
                    total+=it.value;
                }
            }
            if(num==0){
                printf("NA\n");
                continue;
            }
            printf("%d %d\n",num,total);
        }else if(k==3){
            unordered_map<string, int> ans3;
            for(auto it:v){
                if(it.id.substr(4,6)==s){
                    ans3[it.id.substr(1,3)]++;
                }
            }
            if(ans3.size()==0){
                printf("NA\n");
                continue;
            }
            for(auto it:ans3){
                ans.push_back({it.first,it.second});
            }
            sort(ans.begin(),ans.end(),cmp);
            for(auto j:ans){
                printf("%s %d\n",j.id.c_str(),j.value);
            }
        }else {
            printf("NA\n");
        }
    }
    return 0;
}



