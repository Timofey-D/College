public class Lecturer extends Segel implements ISegel{
    // Constructors
    public Lecturer(String name, String department, int experience) {
        super("Dr. " + name, LECTURER, department, experience, 0, LECTURER_GREETING);
    }
}
