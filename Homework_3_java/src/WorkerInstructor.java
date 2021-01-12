/**
 * The class is represented like Professor and Instructor.
 * A human teaches somebody.
 * The class implements the following interface:
 * @see IBuilding
 * @see ITeacher
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class WorkerInstructor extends Person implements IBuilding, ITeacher {
    // variables of an instance of the class
    private Worker worker;
    private Instructor instructor;

    /**
     * The constructor creates an object of StudentInstructor.
     * @param name is a Person name.
     * @param hours_work is a number of studying hours, which are taught by a WorkerInstructor like a Worker.
     * @param position is a position, which is worked by a WorkerInstructor like a Worker.
     * @param hours_inst s a number of teaching hours, which are taught by a WorkerInstructor like a Instructor.
     * @param course_list_inst is a list courses, which are taught by a WorkerInstructor like a Instructor.
     * */
    public WorkerInstructor(String name, int hours_work, String position, int hours_inst, String course_list_inst) {
        super(name);
        this.worker = new Worker(name, hours_work, position);
        this.instructor = new Instructor(name, hours_inst, course_list_inst);
    }

    /**
     * The overridden method prints out all information about WorkerInstructor.
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
        return worker.getGeneralHours() + instructor.getGeneralHours();
    }

    /**
     * The implemented method returns information about WorkerInstructor.
     * */
    @Override
    public void printInfoWork() {
        worker.printInfoWork();
        instructor.printInfoWork();
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked a got course, which is taught by a WorkerInstructor like a Instructor or not.
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
