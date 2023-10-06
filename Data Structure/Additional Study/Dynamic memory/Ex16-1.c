//malloc()을 이용하여 int형 저장공간을 확보하여 처리
#include <stdio.h>
#include <stdlib.h>
int main(){
    int* pi=NULL;
    pi=(int*)malloc(sizeof(int));//함수 malloc()으로 동적 메모리 할당 후 int형 포인터에 저장하기 위해
                                //자료형 변환(int*i가 필요)
    *pi=7;//동적 메모리에 내용 값 7 저장
    printf("주소값: *pi=%p, 저장값: p=%d\n",pi,*pi);
    free(pi)//동적 메모리 해제-연결했던 관계를 풀어준다고 생각. 
    
    }