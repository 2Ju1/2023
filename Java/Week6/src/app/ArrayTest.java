//2276242 ���ֿ�
package app;
import java.util.Scanner;
import java.util.Arrays;

public class ArrayTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		int max,num;
		System.out.println("�Է��� ���ϴ� ������ ������ �Է��ϼ���: ");
		max=s.nextInt();
		int[] arr=new int[max];
		System.out.println("���ڸ� �Է��ϼ���:");
		for(int i=0;i<max;i++) {
			arr[i]=s.nextInt();
		}
		//���İ� �˻� �˰��� ���� �߿�_���� ���ϴ� �����͸� �������� ��� ��������? ��� ���� ã�� �� ����?
		System.out.println("���� ��:");
		show(arr);//static�� static�� �θ� �� �ִ�????
		
		/*//�˻�: �����˻�, �̺а˻�
		System.out.println(Arrays.binarySearch(arr, 60));
		//���� �ƴ϶� �ε����� ã����. 
		// ������ �ٸ��� �̺� �˻��� ���ĵ� �����Ϳ��� ������ �����ϴ�.*/
		
		Arrays.sort(arr);//�⺻�� ��������//���������� ��� �ɱ�?(gptã�ƺ���_������ �� ����)
		System.out.println("\n���� ��:");
		show(arr);
		System.out.println("������ ���ϴ� ���ڸ� �Է��ϼ���");
		num=s.nextInt();
		if(Arrays.binarySearch(arr, num)<0) {
			System.out.println("�˻� ����");
		}else {
			System.out.println("�˻��� �ε���: "+Arrays.binarySearch(arr, num));
		}
		//�˻�: �����˻�, �̺а˻�
		System.out.println("\n"+Arrays.binarySearch(arr, 6));
		//���� �ƴ϶� �ε����� ã����. 
		//������ -1�� ��

	}
//�迭 ��Ҹ� ����� �� �ִ�
	 static void show(int[] arr) {
		 for(int i:arr) {
			 System.out.print(i+" ");
		 }
	 }
}

//calender �� �̹� �߻����� Ȥ�� ��ü�� �޼��� �߿�  getInstance �޼ҵ�� ���� ������ �� �� ����? ��ü ���� ���̵� ���� �����ϴ� ������ ���� �� ����
