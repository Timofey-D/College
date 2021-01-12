/**
 * The class is represented like Professor.
 * A human teaches somebody.
 * The class implements the following interface:
 * @see IBuilding
 * @see ITeacher
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class Professor extends Person implements IBuilding, ITeacher {
    // The variables of an instance of the class.
    private int hours;
    private String[] course_list;

    /**
     * The constructor creates an object of a Professor.
     * @param name is a Person name.
     * @param hours is a number of teaching hours.
     * @param course_list is a list courses, which is taught by a Professor.
     * */
    public Professor(String name, int hours, String course_list) {
        super(name);
        this.hours = hours;
        this.course_list = course_list.split(" ");
    }

    /**
     * The implemented method returns a number of teaching hours.
     * */
    @Override
    public int getTeachHours() {
        return this.hours;
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is specify course, which must be about specify teacher.
     * */
    @Override
    public boolean checkTeachCourse(String course) {
        for (String crs : this.getCourse_list()) {
            if (crs.equalsIgnoreCase(course))
                return true;
        }
        return false;
    }

    /**
     * The implemented method returns information about professor.
     * */
    @Override
    public void printInfoWork() {
        System.out.print("Professor\ncourse list: ");
        for (String course: this.getCourse_list())
            System.out.printf("%s ", course);
        System.out.printf("\nteaching hours: %d\n", this.hours);
    }

    /**
     * The overridden method prints out all information about professor.
     * */
    @Override
    public void printPerson() {
        super.printPerson();
        System.out.printf("%s: ", "course_list");
        for (String course : this.course_list)
            System.out.printf("%s ", course);
        System.out.printf("\nteaching hours: %s\n", this.hours);
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
