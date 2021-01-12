public class SeniorLecturer extends Segel implements ISegel{
    // Constructors
    public SeniorLecturer(String name, String department, int experience, int numOfProjects) {
        super("Dr. " + name, SENIOR_LECTURER, department, experience, numOfProjects, SENIOR_LECTURER_GREETING);
    }
}
