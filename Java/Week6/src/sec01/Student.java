

public abstract class Student {
	protected int type;//학부생(1), 대학원생 (2)
	protected String name;
	protected int score;//점수
	protected String grade;//학점
	//생성자 정의
	public Student(String name) {
		this.name=name;
	}
	//멤버변수에 대한  getter/setter 메소드 정의
	
	public int getType() {
		return type;
	}
	public void setType(int type) {
		this.type = type;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
	public String getGrade() {
		return grade;
	}
	public void setGrade(String grade) {
		this.grade = grade;
	}
	//추상메솓: 학점 계산하기
	//반환값이 있는 것으로 바꾸기 _이 자체를  String으로 반환_통과 과락 둘 중 하나를 받는 것으로 받는다면
	abstract public void computeGrade();
	//객체 현 상태 반환
	public String showInfo() {
		String result="소솟\t이름\t점수\t학점\n";
			if(type==1)
				result+="학부생";
			else
				result+="대학원생";
		result+="\t"+getName();
		result+="\t"+getScore();
		result+="\t"+getGrade();
		return result;
	}
}
