/**
 * The class is represented like Professor and Instructor.
 * A human studies a main time, but one can teach somebody.
 * The class implements the following interface:
 * @see IBuilding
 * @see ITeacher
 * @see IStudy
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class StudentInstructor extends Person implements IBuilding, IStudy, ITeacher {
    // the variables of an instance of the class.
    private Student student;
    private Instructor instructor;

    /**
     * The constructor creates an object of StudentInstructor.
     * @param name is a Person name.
     * @param hours_st is a number of studying hours, which are taught by a StudentInstructor like a Student.
     * @param course_list_st is a list courses, which are studied by a StudentInstructor like a Student.
     * @param hours_inst s a number of teaching hours, which are taught by a StudentInstructor like a Instructor.
     * @param course_list_inst is a list courses, which are taught by a StudentInstructor like a Instructor.
     * */
    public StudentInstructor(String name, int hours_st, String course_list_st, int hours_inst, String course_list_inst) {
        super(name);
        this.student = new Student(name, hours_st, course_list_st);
        this.instructor = new Instructor(name, hours_inst, course_list_inst);
    }

    /**
     * The overridden method prints out all information about a StudentInstructor.
     * */
    @Override
    public void printPerson() {
        super.printPerson();
        printInfoWork();
    }

    /**
     * The implemented method returns a common hours.
     * */
    public int getGeneralHours() {
        return student.getGeneralHours() + instructor.getGeneralHours();
    }

    /**
     * The implemented method returns information about StudentInstructor.
     * */
    @Override
    public void printInfoWork() {
        instructor.printInfoWork();
        student.printInfoWork();
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked a got course, which is studied by StudentInstructor like Student or not.
     * */
    @Override
    public boolean checkStudyCourses(String course) {
        return student.checkStudyCourses(course);
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked a got course, which is taught by StudentInstructor like Instructor or not.
     * */
    @Override
    public boolean checkTeachCourse(String course) {
        return instructor.checkTeachCourse(course);
    }

    /**
     * The implemented method returns a number of teaching hours.
     * */
    @Override
    public int getTeachHours() {
        return instructor.getGeneralHours();
    }
}
