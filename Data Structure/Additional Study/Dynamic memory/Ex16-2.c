//malloc()을 이용하여 동일한 저장공간 여러 개를 확보하여 처리_배열로 확장했다고 생각
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0;
    printf("입력할 점수의 개수를 입력>>");
    scanf("%d",&n);

    int*ary=NULL;
    ary=(int*)molloc(sizeof(int)*n);

printf("%d개의 정수를 입력>>",n);
int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",ary+i);
        sum+=ary[i];
    }
    printf("\n");
    printf("합: %d 평균: %.1f",sum,(double)sum/n);
    free(ary);
}
