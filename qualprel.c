#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int par(int* arr,int start,int end){
    int piv = arr[end];
    int p = start;
    for(int i=start;i<end;i++){
        if(arr[i]>=piv){
            if(i!=p)
                swap(&arr[i],&arr[p]);
            p++;
        }
    }
    swap(&arr[p],&arr[end]);
    return p;
}
void q(int* arr,int start,int end){
    if(start<=end){
        int p = par(arr,start,end);
        q(arr,start,p-1);
        q(arr,p+1,end);
    }
}

/*
this is newC branch*/
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int* arr = malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",arr+i);
        int c = 0;
        unsigned char* frq = calloc(100000,sizeof(unsigned char));

        for(int i=0;i<n;i++){
            if(frq[arr[i]]==0)
                arr[c++]=arr[i];
            frq[arr[i]]++;
        }
        q(arr,0,c-1);
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=frq[arr[i]];
        }
        free(frq);
        free(arr);
        printf("%d\n",sum );
    }
}
