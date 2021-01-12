public class Main {
    public static void main(String[] args) {
        Segel us = new Lecturer("Moshe", "SE", 3);
        us.introduce();
        us.greet();
        System.out.print('\n');
        Segel ms = new SeniorLecturer("Asaf", "CS", 5, 3);
        ms.introduce();
        ms.greet();
        System.out.print('\n');
        Segel ps = new Professor("Eli", "ISE", 10, 5, 50);
        ps.introduce();
        ps.greet();
        System.out.print('\n');
        Professor dc = new DeptChair("Mark", "ISE", 10, 5, 100, "SE");
        dc.introduce();
        dc.greet();
    }
}
