public class Professor extends Segel implements ISegel{
    // variables of instance
    private int numOfPubs;
    // Constructors
    public Professor(String name, String department, int experience, int numOfProjects, int numOfPubs) {
        super("Prof. " + name, PROFESSOR, department, experience, numOfProjects, PROFESSOR_GREETING);
        this.numOfPubs = numOfPubs;
    }
    public Professor(String name, String rank, String department, int experience, int numOfProjects, int numOfPubs, String invite) {
        super(name, rank, department, experience, numOfProjects, PROFESSOR_GREETING);
        this.numOfPubs = numOfPubs;
    };
    // Methods of print
    @Override
    public void introduce() {
        super.introduce();
        System.out.print(" I published " + numOfPubs + (numOfPubs > 1 ? " papers." : " paper."));
    }
}
