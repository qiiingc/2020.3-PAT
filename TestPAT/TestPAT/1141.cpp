#include "0.h"
int n,m;
string si,sn;
struct school{
    string id;
    double score;
    int number;
};
bool cmp(school &a,school &b){
    if(a.score!=b.score)return a.score>b.score;
    else if(a.number!=b.number) return a.number<b.number;
    else return a.id<b.id;
}
int main(){
    freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1141.in","r", stdin);
    scanf("%d",&n);
    map<string,double> m1;
    map<string,int> m2;
    for(int i=0;i<n;i++){
        cin>>si>>m>>sn;
        int j=0;
        while(j<sn.size()){
            sn[j]=tolower(sn[j]);
            j++;
        }
        if(si[0]=='A')m1[sn]+=m*1.0;
        else if(si[0]=='B')m1[sn]+=m*1.0/1.5;
        else if(si[0]=='T')m1[sn]+=m*1.5;
        m2[sn]++;
    }
    vector<school> v;
    for(auto it:m1){
        v.push_back({it.first,it.second,m2[it.first]});
    }
    printf("%d\n",v.size());
    sort(v.begin(),v.end(),cmp);
    int rank=1,total=1,pre=0;
    for(auto it:v){
        if(total==1){
            printf("1 %s %d %d\n",it.id.c_str(),(int)it.score,it.number);
        }else{
            if(it.score==pre){
                printf("%d %s %d %d\n",rank,it.id.c_str(),(int)it.score,it.number);
            }else {
                printf("%d %s %d %d\n",total,it.id.c_str(),(int)it.score,it.number);
                rank=total;
            }
        }
        pre=(int)it.score;
        total++;
    }
    return 0;
}




