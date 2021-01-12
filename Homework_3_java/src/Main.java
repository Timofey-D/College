/*
 * Author: Timofey Dankevich
 * Date: 03.12.2020
 * The beginning of the development: 01.12.2020
 * The challenge is a college task, which was solved the first course by me.
 * */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String ... args) {
        System.out.println("#1\n" +
                sortString("bdcs aab aaa aaaad aaaaz abcd") +
                "\n__________________________________________\n#2");
        System.out.println(checkPassword("abcd"));
        System.out.println("__________________________________________");
        System.out.println(checkPassword("A1b@cdCD"));
        System.out.println("__________________________________________");
        System.out.println(checkPassword("A1b@cdC*"));
        System.out.println("__________________________________________");
        System.out.println(checkPassword("A1b@cdC"));
        System.out.println("__________________________________________");
        System.out.println("#3\n" + addLongInt("143753453223445734", "76543322334487238"));
        System.out.println(addLongInt("12345","49265"));
        System.out.println(addLongInt("12345","999999"));
        System.out.println(addLongInt("657348", "2347895"));
        System.out.println("__________________________________________\n#4");
        printAnagram("AngereD Table Pat eNraged letter taP ATP atpk");
        printAnagram("Table stRing letter");
        printAnagram("Table stRing eblta");
        printAnagram("asd dhw hcuwei bcsdk bhkb dsa");
        System.out.println("__________________________________________\n#5");
        System.out.println(selectCorrectEmails("aaa@bbb.com aaaa aaa@bbb.ccc.tmp aaa@aaa.temp aaa@bbb test@gmail.com", "tmp aaa.temp"));
        System.out.println(selectCorrectEmails(
                "aaa@bbb.com aaaa aa@bbb.ccc.tp aaa@aaa.temp aaa@bbb test@gmail.com Timofey.Dankevich@gmail.com Dankevich.te@gmail.com db999d@yandex.ru",
                "tmp aaa.temp Dankevich "));
        System.out.println("__________________________________________\n#6");
        Person[] array={
                new Student("David",18,"java ppl c# db"),
                new StudentInstructor("Avi",12,"java ppl db",2,"c#"),
                new Student("Moty",20,"ppl c# db math"),
                new Student("Tali",12,"java db"),
                new StudentInstructor("Nensi",18,"ppl c# db",4,"java"),
                new Student("Ronit",24,"ppl db java math c#"),
                new Worker("Natan",42,"electrician"),
                new Worker("Fima",40,"worker"),
                new Professor("Alona",18,"java db network"),
                new Professor("Marina",12,"ppl"),
                new WorkerInstructor("Vlad",40,"it_project_manager",8,"testing db"),
                new WorkerInstructor("Guy",20,"engineer",8,"testing c#"),
                new Instructor("Yael",6,"logics c#"),
                new ProfessorInstructor("Michael",3,"c#",7,"java ppl")
        };
        printCourse(array, "java");
        print2MaxHoursPresent(array);
        System.out.println("_____________________________");
        System.out.println("max teaching hours:");
        returnMaxTeachHours(array).printPerson();
        System.out.println("_____________________________");
        System.out.println("Course Teach hours: " + sumCourseTeachHours(array,"java"));
        System.out.println("Course Students amount: " + countCourseStudents(array,"java"));
    }

    /**
     * The method returns a number of students, who has specify course.
     * @param array is a Person array.
     * @param course is a course, which must be about Student.
     * @Return sumStudents is a number of student, who has specify course.
     * */
    public static int countCourseStudents(Person[] array, String course) {
        int sumStudents = 0;
        for (Person person : array) {
            if (person instanceof IStudy) {
                if (((IStudy) person).checkStudyCourses(course))
                    sumStudents++;
            }
        }
        return sumStudents;
    }

    /**
     * The method returns a common teaching hours, where there is specify course.
     * @param array is a Person array.
     * @param course is a course, which must be about Teacher.
     * @Return sumHours is a common teaching hours in specify course.
     * */
    public static int sumCourseTeachHours(Person[] array, String course) {
        int sumHours = 0;
        for (Person person : array) {
            if (person instanceof ITeacher) {
                if (((ITeacher) person).checkTeachCourse(course))
                    sumHours += ((ITeacher) person).getTeachHours();
            }
        }
        return sumHours;
    }

    /**
     * The method returns a teacher, whose teaching time is more than other teachers.
     * @param array is a Person array.
     * @Return result is a teacher, who teaches the most time than others.
     * */
    public static Person returnMaxTeachHours(Person ... array) {
        int current;
        int previous = 0;
        int max = 0;
        Person result = null;
        for (Person person : array) {
            if (person instanceof ITeacher) {
                current = ((ITeacher) person).getTeachHours();
                if (current > previous && current > max) {
                    max = current;
                    result = person;
                }
                previous = current;
            }
        }
        if (result == null)
            return new Person("Unknown");
        return result;
    }

    /**
    * The method gets a Person array and prints out 2 persons, whose time is more than other persons.
     * @param array is a Person array.
    * */
    public static void print2MaxHoursPresent(Person ... array) {
        System.out.println("Max hours present:");
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - 1; j++) {
                if (array[j] instanceof IBuilding) {
                    if (((IBuilding) array[j]).getGeneralHours() <= ((IBuilding) array[j + 1]).getGeneralHours()) {
                        Person change = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = change;
                    }
                }
            }
        }
        array[0].printPerson();
        System.out.println("_____________________________");
        array[1].printPerson();
    }

    /**
    * The method gets a Person array and a name course.
     * The method prints out those persons, who have a course, which is got by method.
     * @param persons is an array, which contains different persons.
     * @param course is course, which must be about person in the teaching courses or studying courses.
    * */
    public static void printCourse(Person[] persons, String course) {
        System.out.println("Teachers");
        for (Person person : persons) {
            if (person instanceof ITeacher) {
                if (((ITeacher) person).checkTeachCourse(course)) {
                    person.printPerson();
                    System.out.println("_____________________________");
                }
            }
        }
        System.out.println("Student");
        for (Person person : persons) {
            if (person instanceof IStudy) {
                if (((IStudy) person).checkStudyCourses(course)) {
                    person.printPerson();
                    System.out.println("_____________________________");
                }
            }
        }
    }

    /**
     * Напишите статическую функцию по имени sortString,
     * которая получает строку в виде слов из маленьких букв,
     * разделенных пробелом и возвращает новую строку из этих же слов упорядоченных по длинне слова.
     * Если есть несколько слов одинаковой длинны их нужно упорядочить по Лексикографическому порядку.
     * строка: "bdcs aab aaa aaaad aaaaz abcd"
     * функция вернёт: "aaa aab abcd bdcs aaaad aaaaz"
     * */
    public static String sortString(String str) {
        String result = "";
        String[] array = str.split(" ");
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - 1; j++) {
                if (array[j].compareToIgnoreCase(array[j + 1]) == 1) {
                    String change = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = change;
                }
            }
        }
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - 1; j++) {
                if (array[j].length() >= array[j + 1].length()) {
                    String change = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = change;
                }
            }
        }
        for (int i = 0; i < array.length; i++) {
            result += array[i];
            if (i != array.length - 1)
                result += " ";
        }
        return result;
    }

    /**
    * Напишите статическую функцию по имени checkPassw, которая получает строку,
     * проверяет если её можно использовать в виде пароля и возвращает true или false.
     * Паролем может быть строка длинной больше 7 символов состоящая из: больших и маленьких букв,
     * цифр и одним из четырех символов-!@#$ и не содержащая любых других знаков.
     * строка: "A1b@cdCD"
     * функция вернёт: true
     * строка: "A1b@cdC*"
     * функция вернёт: false
     * have other symbols
     * строка: "abcd"
     * функция вернёт: false
     * short password
     * no capital letters no digits
     * no symbols
     * */
    public static boolean checkPassword(String password) {
        // LETTERS 65 to 90
        // letters 97 to 122
        // ! = 33, @ = 64, # = 35, $ = 36
        // To check 1 time
        boolean bigLetters = false;
        boolean smallLetters = false;
        boolean symbols = false;
        boolean otherSymbols = false;
        boolean numbers = false;
        String[] warnings = new String[6];
        for (int i = 0; i < password.length(); i++) {
            boolean capital = password.charAt(i) >= 65 && password.charAt(i) <= 90;
            boolean small = password.charAt(i) >= 97 && password.charAt(i) <= 122;
            boolean symbol = password.charAt(i) == 33 || password.charAt(i) == 64 || password.charAt(i) == 35 || password.charAt(i) == 36;
            boolean number = password.charAt(i) >= 48 && password.charAt(i) <= 57;
            if (number && !numbers)
                numbers = true;
            if (capital && !bigLetters)
                bigLetters = true;
            if (small && !smallLetters)
                smallLetters = true;
            if (symbol && !symbols)
                symbols = true;
            if ( !capital && !small && !symbol && !number && !otherSymbols )
                otherSymbols = true;
        }
        System.out.println("Password: " + password);
        warnings[0] = password.length() <= 7 ? "short password" : "Length: OK";
        warnings[1] = !bigLetters ? "no capital letters" : "Capital letter: OK";
        warnings[2] = !smallLetters ? "no small letters" : "Small letter: OK";
        warnings[3] = !symbols ? "no symbols" : "Special symbol: OK";
        warnings[4] = otherSymbols ? "Have other symbols" : "Other symbol: OK";
        warnings[5] = !numbers ? "no digits" : "Digits: OK";
        if (!bigLetters || !smallLetters || !symbols || otherSymbols || !numbers) {
            for (String warning : warnings) {
                if (!warning.contains("OK"))
                    System.out.println(warning);
            }
        }
        return bigLetters && smallLetters && symbols && !otherSymbols;
    }

    /**
     * Напишите статическую функцию по имени addLongInt,
     * которая получает два целых числа любой длины в виде двух отдельных строк
     * и возвращает сумму этих чисел в виде строки.
     * два целых числа: "143753453223445734","76543322334487238"
     * функция вернёт: "220296775557932972"
     * */
    public static String addLongInt(String number_1, String number_2) {
        String result = "";
        int sum = 0;
        int zero = number_1.length() > number_2.length() ? number_1.length() - number_2.length() : number_2.length() - number_1.length();
        if (number_1.length() > number_2.length())
            number_2 = addZero(number_2, zero);
        else
            number_1 = addZero(number_1, zero);
        for (int i = number_1.length() - 1; i >= 0; i--) {
            int digit_1 = number_1.charAt(i) - 48;
            if (sum / 10 > 0)
                digit_1 += (sum / 10);
            int digit_2 = number_2.charAt(i) - 48;
            sum = digit_1 + digit_2;
            result = (sum % 10) + result;
        }
        if (sum / 10 > 0)
            result = (sum / 10) + result;
        return result;
    }

    /**
    * The method adds specify number of 0s to a got string
    * */
    private static String addZero(String string, int number) {
        return "0".repeat(number) + string;
    }

    /**
    * Напишите статическую функцию по имени printAnagram,
     * которая получает строку в виде слов из маленьких и больших букв,
     * разделенных пробелом, находит и печатает слова Анаграммы (слова, состоящие из одинаковых букв)
     * или сообщение, что такие слова не найдены.
     * строка: "AngereD Table Pat eNraged letter taP ATP atpk"
     * функция распечатает: AngereD eNraged, Pat taP ATP
    * */
    public static void printAnagram(String string) {
        string = sortString(string);
        String[] check = string.split(" ");
        ArrayList<String> result = new ArrayList<>();
        for (int i = 0; i < check.length; i++) {
            for (int j = 0; j < check.length - 1; j++) {
                if (sortLetter(check[j].toLowerCase()).equals(sortLetter(check[j + 1].toLowerCase()))) {
                    if (!result.contains(check[j]))
                        result.add(check[j]);
                    if (!result.contains(check[j + 1]))
                        result.add(check[j + 1]);
                }
            }
        }
        while (!result.isEmpty()) {
            System.out.print(result.remove(result.size() - 1) +
                    (result.size() - 1 == -1 ? "\n" : " "));
        }
    }

    /*
    * The method sorts the letters to a got string.
    * */
    private static String sortLetter(String str) {
        char[] symbol = str.toCharArray();
        Arrays.sort(symbol);
        str = "";
        for (char c : symbol)
            str += String.valueOf(c);
        return str;
    }

    /**
     *
     * Напишите статическую функцию по имени selectCorrectEmails,
     * которая получает строку состоящую из электронных почтовых адресов, разделенных пробелом,
     * и строку запрещенных доменных имен, разделенных пробелом.
     * Функция должна создать и вернуть новую строку, состоящую из законных электронных адресов:
     *  в адресе есть знак @ и минимум одна точка в суффиксе.
     *  суффикс или его часть не должны находиться в черном списке запрещенных доменных имен.
     * адресa: "aaa@bbb.com aaaa aaa@bbb.ccc.tmp aaa@aaa.temp aaa@bbb test@gmail.com"
     * черный списк: "tmp aaa.temp"
     * функция вернёт: "aaa@bbb.com test@gmail.com"
     * */
    public static String selectCorrectEmails(String emails, String blackList) {
        Pattern pattern = Pattern.compile("[a-zA-Z0-9.]*@[a-zA-Z]*\\.[a-zA-Z]{2,3}");
        String[] listEmails = emails.split(" ");
        String[] black = blackList.split(" ");
        ArrayList<String> result = new ArrayList<>();
        for (String listEmail : listEmails) {
            Matcher matcher = pattern.matcher(listEmail);
            if (matcher.matches())
                result.add(listEmail);
        }
        for (String undesired : black) {
            for (int j = 0; j < result.size(); j++) {
                if (result.get(j).toLowerCase().contains(undesired.toLowerCase())) {
                    result.remove(j);
                    break;
                }
            }
        }
        StringBuilder results = new StringBuilder();
        for (String s : result)
            results.append(s).append(" ");
        return results.toString().trim();
    }
}
