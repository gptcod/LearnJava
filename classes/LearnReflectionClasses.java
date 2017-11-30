package reflection;


class Candy{
	public void p() {
		System.out.println("good");}
}

public class LearnReflectionClasses {
	public static void main(String[] args) {
		try {
			Class myObjectClass = Class.forName("reflection.Candy");
			String className = myObjectClass.getName();
			System.out.println(className);
		} 
		catch(ClassNotFoundException e) {
			System.out.println("Couldn't find Candy");
		}
		
	}
}