//2276242 이주원
package app;
import java.util.Scanner;
import java.util.Arrays;

public class ArrayTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		int max,num;
		System.out.println("입력을 원하는 숫자의 개수를 입력하세요: ");
		max=s.nextInt();
		int[] arr=new int[max];
		System.out.println("숫자를 입력하세요:");
		for(int i=0;i<max;i++) {
			arr[i]=s.nextInt();
		}
		//정렬과 검색 알고리즘 많이 중요_내가 원하는 데이터를 내림차순 어떻게 정렬하지? 어떻게 빨리 찾을 수 있지?
		System.out.println("정렬 전:");
		show(arr);//static은 static만 부를 수 있다????
		
		/*//검색: 선형검색, 이분검색
		System.out.println(Arrays.binarySearch(arr, 60));
		//값이 아니라 인덱스를 찾아줌. 
		// 선형과 다르게 이분 검색은 정렬된 데이터에만 적용이 가능하다.*/
		
		Arrays.sort(arr);//기본이 오름차순//내림차순은 어떻게 될까?(gpt찾아보기_시험은 안 나옴)
		System.out.println("\n정렬 후:");
		show(arr);
		System.out.println("차지를 원하는 숫자를 입력하세요");
		num=s.nextInt();
		if(Arrays.binarySearch(arr, num)<0) {
			System.out.println("검색 실패");
		}else {
			System.out.println("검색된 인덱스: "+Arrays.binarySearch(arr, num));
		}
		//검색: 선형검색, 이분검색
		System.out.println("\n"+Arrays.binarySearch(arr, 6));
		//값이 아니라 인덱스를 찾아줌. 
		//없으면 -1을 줌

	}
//배열 요소를 출력할 수 있는
	 static void show(int[] arr) {
		 for(int i:arr) {
			 System.out.print(i+" ");
		 }
	 }
}

//calender 는 이미 추상으로 혹은 객체가 메서드 중에  getInstance 메소드는 정보 갖오게 할 수 있음? 객체 생성 없이도 직접 접근하는 것으로 보일 수 있음
