abstract class Segel implements ISegel {
    // variable of instance
    private String name;
    private String rank;
    private String department;
    private int experience;
    private int numOfProjects;
    private String invite;
    // Default constructor
    public Segel() {
        this("Unknown", "Unknown", "Unknown", 0, "unknown");
    };
    // Constructor is for Lecturer, Senior lecturer and Professor
    public Segel(String name, String rank, String department, int experience, String invite) {
        this(name, rank, department, experience, 0, "");
    }
    public Segel(String name, String rank, String department, int experience, int numOfProjects, String invite) {
        this.name = name;
        this.department = department;
        this.experience = experience;
        this.rank = rank;
        this.numOfProjects = numOfProjects;
        this.invite = invite;
    }
    // Methods are of print
    public void introduce() {
        System.out.print("I am " + name + ", a " + rank + " in the department " + department + ". I teach " +
                experience + (experience > 1 ? " years." : " year.") +
                (numOfProjects == 0 ? "" : " I manage " + numOfProjects +
                        (numOfProjects > 1 ? " projects. It's cool!" : " project. It's cool!" )));
    }
    public void greet() {
        System.out.print('\n');
        System.out.println("I'd like to greet you with the successful completing the course and invite you " + invite);
    }
}