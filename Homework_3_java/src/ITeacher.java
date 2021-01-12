/**
 * The interface is implemented by classes, which are presented like a Teacher.
 * */
public interface ITeacher {
    /**
     * The method checks whether a teacher has a course, which is specify.
    * */
    boolean checkTeachCourse(String course);

    /**
     * The method returns a number of teaching hours.
     * */
    int getTeachHours();
}
