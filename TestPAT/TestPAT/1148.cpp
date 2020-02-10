#include "0.h"
int a[105],n;
bool f(int x,int y){
    int liar = 0;
    for(int i = 1;i <= n;i++){
        int z = abs(a[i]);
        if(i == x){
            if(z != x && z != y){
                if(a[i] > 0)return false;
            }else if(z == x || z == y){
                if(a[i] < 0)return false;
            }
        }else if(i == y){
            if(z != x && z != y){
                if(a[i] < 0)return false;
            }else if(z ==x || z == y){
                if(a[i] > 0)return false;
            }
        }else{
            if(z != x && z != y){
                if(liar < 2 && a[i] < 0)liar++;
                if(liar >= 2)return false;
            }else if(z == x || z == y){
                if(liar < 2 && a[i] > 0)liar++;
                if(liar >= 2)return false;
            }
        }
    }
    return true;
}

int main(){
freopen("/Users/ching_shing/Documents/SJTU/ky/PAT顶级/PAT-GitHub/2020.3-PAT/TestPAT/TestPAT/1148.in","r", stdin);
    scanf("%d\n",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n-1;i++){
        for(int j = i+1;j <= n;j++){
            if(f(i,j) || f(j,i)){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
