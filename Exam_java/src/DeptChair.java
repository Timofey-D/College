import java.time.LocalDate;

public class DeptChair extends Professor implements ISegel{
    // variable of instance
    private int manageSince;
    private String manageDept;
    public DeptChair(String name, String department, int experience, int numOfProjects, int numOfPubs, String manageDept) {
        super("Prof. " + name, DEPT_CHAIR, department, experience, numOfProjects, numOfPubs, DEPT_CHAIR_GREETING);
        this.manageDept = manageDept;
        this.manageSince = manageSince == 0 ? LocalDate.now().getYear() - 10 : manageSince;
    }
    public DeptChair() {
        super("Prof. " + "Unknown", DEPT_CHAIR, "Unknown", 0, 0, 0, DEPT_CHAIR_GREETING);
        this.manageDept = "Unknown";
        this.manageSince = manageSince == 0 ? LocalDate.now().getYear() : manageSince;
    }
    // Method is for print
    @Override
    public void introduce() {
        super.introduce();
        System.out.print(" I manage my department since " + manageSince + ".");
    }
}
