/**
 * The class is represented like Student.
 * The class implements the following interface:
 * @see IBuilding
 * @see IStudy
 * The class is a inheritor's Person class.
 * @see Person
 * */
class Student extends Person implements IBuilding, IStudy {
    // the variables of an instance of the class.
    private int hours;
    private String[] course_list;

    /**
     * The constructor creates an object of Student.
     * @param name is a Person name.
     * @param hours is a number of studying hours.
     * @param course_list is a list courses, which is studied by a Student.
     * */
    public Student(String name, int hours, String course_list) {
        super(name);
        this.hours = hours;
        this.course_list = course_list.split(" ");
    }

    /**
     * The implemented method returns a boolean value.
     * @param course is checked a got course, which is studied by Student or not.
     * */
    public boolean checkStudyCourses(String course) {
        for (String crs : this.getCourse_list()) {
            if (crs.equalsIgnoreCase(course))
                return true;
        }
        return false;
    }

    /**
     * The implemented method returns information about Student.
     * */
    @Override
    public void printInfoWork() {
        System.out.print("Student\ncourse list: ");
        for (String course: this.getCourse_list()) {
            System.out.printf("%s ", course);
        }
        System.out.printf("\nstudy hours: %d\n", this.hours);
    }

    /**
     * The overridden method prints out all information about Student.
     * */
    @Override
    public void printPerson() {
        super.printPerson();
        printInfoWork();
    }

    /**
     * The method returns a course array.
     * */
    public String[] getCourse_list() {
        return course_list;
    }

    /**
     * The implemented method returns a common studying hours.
     * */
    public int getGeneralHours() {
        return hours;
    }

}