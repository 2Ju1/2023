package sec01;import java.util.Scanner;
public class StudentTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		String name;
		int score,type;
		//����ڷκ��� �ʿ��� ������ �Է¹ޱ�
		 System.out.print("�л� ���� �Է�(�кλ�=1, ���п���=2)");
		 type=s.nextInt();
		 System.out.print("�̸� �Է�: ");
		 name=s.next();
		 System.out.print("���� �Է�: ");
		 score=s.nextInt();
		 UndergraduateStudent us=new UndergraduateStudent(name);
		 GraduateStudent gs=new GraduateStudent(name);
		 if(type==1) {
			 us.setType(type);
			 us.setScore(score);
			 us.computeGrade();
			 System.out.println(us.showInfo());
		 }else {
			 gs.setType(type);
			 gs.setScore(score);
			 gs.computeGrade();
			 System.out.println(us.showInfo());
		 }
		 s.close();
	}

}
