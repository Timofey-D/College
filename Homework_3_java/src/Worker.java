/**
 * The class is represented like Worker.
 * A human works somewhere.
 * The class implements the following interface:
 * @see IBuilding
 * The class is a inheritor's Person class.
 * @see Person
 * */
public class Worker extends Person implements IBuilding {
    // the variables of an instance of the class.
    private int hours;
    private String position;

    /**
     * The constructor creates an object of Worker.
     * @param name is a Person name.
     * @param hours is a number of work hours.
     * @param position is a position, which is worked by a Worker.
     * */
    public Worker(String name, int hours, String position) {
        super(name);
        this.hours = hours;
        this.position = position;
    }

    /**
     * The implemented method returns information about Worker.
     * */
    @Override
    public void printInfoWork() {
        System.out.printf("Worker\nwork hours: %d\nposition: %s\n", this.hours, this.position);
    }

    /**
     * The overridden method prints out all information about Worker.
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
        return hours;
    }
}
