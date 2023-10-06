#include <stdio.h>
#include <stdlib.h>
void myprintf(int *ary,int n);
int main(){
    int*reary,*cary;
    cary=(int*)calloc(3,sizeof(int));//malloc과 다르게 calloc은 기본값 0으로 들어감
    printf("%p",cary);
    cary[0]=10;
    reary=(int*)realloc(cary,4*sizeof(int));//확장된 곳에는 쓰레기값이 들어감_calloc만 0으로 예쁜것
    myprintf(reary,5);
    free(reary);
    return 0;


}