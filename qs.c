#include <stdio.h>
#include <stdlib.h>
#define tt float

void swap(tt *a,tt *b){
    tt x=*a;
    *a=*b;
    *b=x;
}

int cmp(tt i,tt j){
    return i<j;
}

void qs(tt*v,int l,int r,int (*fcmp)(tt,tt)){
    if(r<l)return;
    int i=l-1,j=l;
    while(j<r){
        if(fcmp(v[j],v[r])){
            ++i;
            if(i!=j)swap(v+i,v+j);
            ++j;
        }
        else{
            ++j;
        }
    }
    swap(v+i+1,v+r);
    qs(v,l,i,fcmp);
    qs(v,i+2,r,fcmp);
}

int main(int argc,char*argv[]){
    int n=atoi(argv[1]);
    tt *v=(tt*)malloc(n*sizeof(tt));
    for(int i=0;i<n;++i){
        scanf("%f",v+i);
    }
    qs(v,0,n-1,cmp);
    for(int i=0;i<n;++i)
        printf("%0.2f ",v[i]);
    return 0;
}