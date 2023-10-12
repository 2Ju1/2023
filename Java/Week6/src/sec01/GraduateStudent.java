

public class GraduateStudent extends Student{

	public GraduateStudent(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void computeGrade() {
		// TODO Auto-generated method stub
		if(score>=80)
			grade="통과";
		else
			grade="과락";
	}

}
