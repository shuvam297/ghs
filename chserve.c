#include <stdio.h>
int main(void){
    int t;
    scanf("%d",&t);
    int a,b,k;
    while(t--){
        scanf("%d %d %d",&a,&b,&k);
        int s = a+b;
        int d = s - (s%k);
        if((d/k)%2)
            printf("COOK\n");
        else
            printf("CHEF\n");
    }
}
