/**
 * The class is represented Instructor.
 * A human teaches somebody.
 * The class implements the following interface:
 * @see IBuilding
 * @see ITeacher
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class Instructor extends Person implements IBuilding, ITeacher {
    // variables of an instance of the class
    private int hours;
    private String[] course_list;

    /**
     * The constructor creates a object of instructor
     * @param name is a name of person
     * @param hours is a number of teaching hours
     * @param course_list is courses, which are taught by a Instructor, it has to entre through whitespace.
     * */
    public Instructor(String name, int hours, String course_list) {
        super(name);
        this.hours = hours;
        this.course_list = course_list.split(" ");
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked a got course, which is taught by a Instructor or not.
     * */
    public boolean checkTeachCourse(String course) {
        for (String crs : this.getCourse_list()) {
            if (crs.equalsIgnoreCase(course))
                return true;
        }
        return false;
    }

    /**
     * The implemented method returns a number of teaching hours.
     * */
    @Override
    public int getTeachHours() {
        return this.getGeneralHours();
    }

    /**
     * The implemented method returns information about instructor.
     * */
    @Override
    public void printInfoWork() {
        System.out.print("Instructor\ncourse list: ");
        for (String course: this.getCourse_list())
            System.out.printf("%s ", course);
        System.out.printf("\nteaching hours: %d\n", this.hours);
    }

    /**
     * The overridden method prints out all information about instructor.
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
        return hours;
    }

    /**
     * The method returns a course array.
     * */
    public String[] getCourse_list() {
        return course_list;
    }
}
