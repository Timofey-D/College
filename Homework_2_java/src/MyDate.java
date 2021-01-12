import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Locale;

public class MyDate {
    private int day;
    private int month;
    private int year;

    // Internal the variables of the class
    private static final int LEAP_YEAR = 366;
    private static final int USUAL_YEAR = 365;

    // Internal the arrays of the class
    private static final int[] MONTHS_OF_LEAP_YEAR = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final int[] MONTHS_OF_USUAL_YEAR = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    private static final String[] MONTHS = {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
    };


    /**
    * The constructor is a default, which creates current date.
    * */
    public MyDate() {
        LocalDate today = LocalDate.now();
        this.day = today.getDayOfMonth();
        this.month = today.getMonthValue();
        this.year = today.getYear();
    }

    /**
    * The constructor is with parameters, which create the specify date.
     * @param day is a specify day.
     * @param month is a specify month.
     * @param year is a specify year.
    * */
    public MyDate(int day, int month, int year) {
        LocalDate today = LocalDate.now();
        this.day = day;
        this.month = month;
        this.year = year;
        this.day = day < 1 || day > 31 ? today.getDayOfMonth() : day;
        this.month = month < 1 || month > 12 ? today.getMonthValue() : month;
        this.year = year < 1900 || year > 2100 ? today.getYear() : year;
        if (isIsLeapYear(year) & month == 2 & day > 29)
            this.day = 29;
        if (!isIsLeapYear(year) & month == 2 & day > 28)
            this.day = 28;
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) & day > 31)
            this.day = 31;
        if ((month == 4 || month == 6 || month == 9 || month == 11) & day > 30)
            this.day = 30;
    }

    /**
    * The constructor creates a copy of a date is brought.
     * @param other is brought a date.
    * */
    public MyDate(MyDate other) {
        this.day = other.day;
        this.month = other.month;
        this.year = other.year;
    }

    // Block of getter
    public int getDay() {
        return this.day;
    }
    public int getMonth() {
        return this.month;
    }
    public int getYear() {
        return this.year;
    }

    // Block of setter
    public void setDay(int day) {
        this.day = day;
    }
    public void setMonth(int month) {
        this.month = month;
    }
    public void setYear(int year) {
        this.year = year;
    }

    /*
    * The method prints out an current instance of the class.
    * */
    public void printDate() {
        System.out.printf("%02d/%02d/%02d%n", this.day, this.month, this.year);
    }

    /*
    * The method prints out a reduced name of a month.
    * */
    public void printMonthName() {
        for (int i = 0; i < MONTHS.length; i++) {
            if ((this.month - 1) == i)
                System.out.printf("%02d %s %02d%n", this.day, MONTHS[i].substring(0,3), this.year);
        }
    }

    /**
    * The method returns a specify format of a date.
    * */
    public String getDateFormat(String dateFormat) {
        LocalDate date = LocalDate.of(this.year, this.month, this.day);
        switch (dateFormat) {
            case "ddmmyy":
                return date.format(DateTimeFormatter.ofPattern("dd/MM/yy"));
            case "mmddyyyy":
                return date.format(DateTimeFormatter.ofPattern("MM/dd/yyyy"));
            case "yyyymmdd":
                return date.format(DateTimeFormatter.ofPattern("yyyy/MM/dd"));
            case "ddMMyyyy":
                return date.format(DateTimeFormatter.ofPattern("dd MMM yyyy", Locale.ENGLISH));
            case "dd.mm.yyyy":
                return date.format(DateTimeFormatter.ofPattern("dd.MM.yy"));
            case "mm.dd.yyyy":
                return date.format(DateTimeFormatter.ofPattern("dd.MM.yyyy"));
            case "yyyy.mm.dd":
                return date.format(DateTimeFormatter.ofPattern("yyyy.MM.dd"));
            case "dd.MM.yyyy":
                return date.format(DateTimeFormatter.ofPattern("dd.MMM.yyyy", Locale.ENGLISH));
            case "MM.dd.yyyy":
                return date.format(DateTimeFormatter.ofPattern("MM.dd.yyyy", Locale.ENGLISH));

            default:
                return date.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        }
    }

    /**
     * The method prints out a specify format of a date.
     * */
    public void printFormatDate(String dateFormat) {
        LocalDate date = LocalDate.of(this.year,this.month,this.day);
        switch (dateFormat) {
            case "ddmmyy":
                String date_finish = date.format(DateTimeFormatter.ofPattern("dd/MM/yy"));
                System.out.println(date_finish);
                break;
            case "mmddyyyy":
                date_finish = date.format(DateTimeFormatter.ofPattern("MM/dd/yyyy"));
                System.out.println(date_finish);
                break;
            case "yyyymmdd":
                date_finish = date.format(DateTimeFormatter.ofPattern("yyyy/MM/dd"));
                System.out.println(date_finish);
                break;
            case "ddMMyyyy":
                date_finish = date.format(DateTimeFormatter.ofPattern("dd MMM yyyy", Locale.ENGLISH));
                System.out.println(date_finish);
                break;
            case "dd.mm.yy":
                date_finish = date.format(DateTimeFormatter.ofPattern("dd.MM.yy"));
                System.out.println(date_finish);
                break;
            case "mm.dd.yyyy":
                date_finish = date.format(DateTimeFormatter.ofPattern("MM.dd.yyyy"));
                System.out.println(date_finish);
                break;
            case "yyyy.mm.dd":
                date_finish = date.format(DateTimeFormatter.ofPattern("yyyy.MM.dd"));
                System.out.println(date_finish);
                break;
            case "dd.MM.yyyy":
                date_finish = date.format(DateTimeFormatter.ofPattern("dd.MMM.yyyy", Locale.ENGLISH));
                System.out.println(date_finish);
                break;
            case "MM.dd.yyyy":
                date_finish = date.format(DateTimeFormatter.ofPattern("MM.dd.yyyy", Locale.ENGLISH));
                System.out.println(date_finish);
                break;
            default:
                date_finish = date.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
                System.out.println(date_finish);
        }
    }

    /**
    * The method prints out a number of days the specify date.
    * */
    public void printMonthDay() {
        if (isIsLeapYear(this.year)) {
            for (int i = 0; i < MONTHS_OF_LEAP_YEAR.length; i++) {
                if (this.month - 1 == i)
                    System.out.println(MONTHS_OF_LEAP_YEAR[i]);
            }
        } else {
            for (int i = 0; i < MONTHS_OF_USUAL_YEAR.length; i++) {
                if (this.month - 1 == i)
                    System.out.println(MONTHS_OF_USUAL_YEAR[i]);
            }
        }
    }

    /**
    * The method checks whether it is a leap year a got date.
    * */
    public boolean isIsLeapYear(int year) {
        return (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0));
    }

    /*
    * The method prints out the next date after a got date.
    * */
    public void printNextDate() {
        LocalDate date = LocalDate.of(this.year,this.month,this.day);
        date = date.plusDays(1);
        String fDate = date.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        System.out.println(fDate);
    }

    /**
     * The method returns out the next date after a got date.
     * */
    public MyDate getNextDate() {
        LocalDate date = LocalDate.of(this.year,this.month,this.day).plusDays(1);
        return new MyDate(date.getDayOfMonth(), date.getMonthValue(), date.getYear());
    }

    /**
     * The method prints out a difference between two dates
     * */
    public void printDifferenceDates(MyDate other) {
        System.out.println(this.getQuantityDays() - other.getQuantityDays());
    }

    /**
     * The method returns a difference between two dates
     * */
    public int getDifferenceDates(MyDate other) {
        return this.getQuantityDays() - other.getQuantityDays();
    }

    /**
     * The method returns a number of a days the specify date.
     * */
    public int getQuantityDays() {
        int NUMBER_OF_DATES = 0;
        int yearSave = this.year;
        while (yearSave != 0) {
            NUMBER_OF_DATES += isIsLeapYear(this.year) ? LEAP_YEAR : USUAL_YEAR;
            yearSave--;
        }
        if (isIsLeapYear(this.year)) {
            for (int month = 0; month < this.month; month++)
                    NUMBER_OF_DATES += MONTHS_OF_LEAP_YEAR[month];
        }
        else {
            for (int i = 1; i < this.month; i++)
                    NUMBER_OF_DATES += MONTHS_OF_USUAL_YEAR[i];
        }
        NUMBER_OF_DATES += this.day;
        return NUMBER_OF_DATES;
    }

    public boolean equals(MyDate other) {
        if (other == this)
            return  true;
        if (other == null || other.getClass() != this.getClass())
            return false;
        return this.day == other.day && this.month == other.month & this.year == other.year;
    }
}

