package app;

import lib.Calculator;//�츮�� ���� ��Ű���� �������ֱ�
//�θ��� ���� ������ �ڽ��� ���� �� ����.?�� �ݴ� �ƴ�?
public class GoodCalc extends Calculator{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GoodCalc c=new GoodCalc();
		int arr[]= {10,20,30};
		System.out.println(c.add(10,20));

		System.out.println(c.sub(10,20));

		System.out.println(c.avg(arr));

	}

	@Override
	public int add(int a, int b) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int sub(int a, int b) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public double avg(int[] arr) {
		// TODO Auto-generated method stub
		int sum=0;
		double avg;
		for(int i:arr) {
			sum+=arr[i];
		
		}
		avg=(double)sum/arr.length;
	
		return avg;
	}

}
