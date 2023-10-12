

public class UndergraduateStudent extends Student{

	public UndergraduateStudent(String name) {
		super(name);
		// TODO Auto-generated constructor stub
		//추상클래스에서 생성자를 상속하지 않으므로 따로  super 로 불러야
	}
	//부모의 메서드를 부르는 것.  super. 
	//자바의  super에 대해 정리할 것 

	@Override
	public void computeGrade() {
		// TODO Auto-generated method stub
		if(score>=70)
			grade="통과";
		else
			grade="과락";
	}

}
