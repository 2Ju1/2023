

public class UndergraduateStudent extends Student{

	public UndergraduateStudent(String name) {
		super(name);
		// TODO Auto-generated constructor stub
		//�߻�Ŭ�������� �����ڸ� ������� �����Ƿ� ����  super �� �ҷ���
	}
	//�θ��� �޼��带 �θ��� ��.  super. 
	//�ڹ���  super�� ���� ������ �� 

	@Override
	public void computeGrade() {
		// TODO Auto-generated method stub
		if(score>=70)
			grade="���";
		else
			grade="����";
	}

}
