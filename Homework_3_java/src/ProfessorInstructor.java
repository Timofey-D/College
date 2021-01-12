/**
 * The class is represented like Professor and Instructor.
 * A human teaches somebody.
 * The class implements the following interface:
 * @see IBuilding
 * @see ITeacher
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class ProfessorInstructor extends Person implements IBuilding, ITeacher {
    // The variables of an instance of the class.
    private Professor professor;
    private Instructor instructor;

    /**
     * The constructor creates an object of ProfessorInstructor.
     * @param name is a Person name.
     * @param hours_prof is a number of teaching hours, which are taught by a ProfessorInstructor like a Professor.
     * @param course_list_prof is a list courses, which are taught by a ProfessorInstructor like a Professor.
     * @param hours_inst s a number of teaching hours, which are taught by a ProfessorInstructor like a Instructor.
     * @param course_list_inst is a list courses, which are taught by a ProfessorInstructor like a Instructor.
     * */
    public ProfessorInstructor(String name, int hours_prof, String course_list_prof,
                               int hours_inst, String course_list_inst) {
        super(name);
        this.professor = new Professor(name, hours_prof, course_list_prof);
        this.instructor = new Instructor(name, hours_inst, course_list_inst);
    }

    /**
     * The implemented method returns a number of teaching hours.
     * */
    @Override
    public int getTeachHours() {
        return professor.getGeneralHours() + instructor.getGeneralHours();
    }

    /**
     * The overridden method prints out all information about ProfessorInstructor.
     * */
    @Override
    public void printPerson() {
        super.printPerson();
        printInfoWork();
    }

    /**
     * The implemented method returns a common teaching hours.
     * */
    public int getGeneralHours() {
        return professor.getGeneralHours() + instructor.getGeneralHours();
    }

    /**
     * The implemented method returns information about ProfessorInstructor.
     * */
    @Override
    public void printInfoWork() {
        professor.printInfoWork();
        instructor.printInfoWork();
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked course, which is taught by ProfessorInstructor or not.
     * */
    @Override
    public boolean checkTeachCourse(String course) {
        return professor.checkTeachCourse(course) || instructor.checkTeachCourse(course);
    }
}
