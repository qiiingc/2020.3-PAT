#include "0.h"
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
bool isPrime(int n){
    if(n<3)return false;
    int x=(int)sqrt(n);
    for(int i=2;i<=x;i++){
        if(n%i==0)return false;
    }
    return true;
}
int sum(int n){
    return n==0?0:sum(n/10)+n%10;
}
struct node{
    int id,data;
};
bool cmp(node a,node b){
    return a.id==b.id?a.data<b.data:a.id<b.id;
}
int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1160.in","r", stdin);
    int n,k,m;
    scanf("%d\n",&n);
    for(int j=1;j<=n;j++){
        scanf("%d %d\n",&k,&m);
        printf("Case %d\n",j);
        int a=pow(10,k-3),b=pow(10,k-2);
        vector<node> v;
        for(int p=a;p<b;p++){
            int d=p*100+99;
            if(sum(d)==m){
                int c=sum(d+1);
                if(isPrime(gcd(m, c))){
                    v.push_back({c,d});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(int q=0;q<v.size();q++){
            printf("%d %d\n",v[q].id,v[q].data);
        }
        if(v.size()==0){
            printf("No Solution\n");
        }
        k++;
    }
    return 0;
}



