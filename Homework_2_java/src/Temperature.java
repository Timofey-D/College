public class Temperature {
    // variable of instance
    private double scale;
    private MyDate scale_date;

    /**
    * The constructor is default.
    * The constructor returns a temperature equals 0 and a current day.
    * */
    public Temperature() {
        this.scale = 0;
        this.scale_date = new MyDate();
    }

    /**
    * The constructor gets one parameter, which is a scale.
    * The constructor returns a specify temperature and a current day.
    * */
    public Temperature(double scale) {
        this.scale = scale;
        this.scale_date = new MyDate();
    }

    /**
     * The constructor gets the following parameter:
     * @param scale is a temperature.
     * @param day is a specify a current day.
     * @param month is a specify a current month.
     * @param year is a specify a current year.
    * */
    public Temperature(double scale, int day, int month, int year) {
        this.scale = scale;
        this.scale_date = new MyDate(day, month, year);
    }

    /**
     * The constructor gets the following parameter:
     * @param scale is a temperature.
     * @param date is a specify data.
     * */
    public Temperature(double scale, MyDate date) {
        this.scale = scale;
        this.scale_date = new MyDate();
    }

    // Block of getter
    public double getScale() {
        return scale;
    }
    public MyDate getScale_date() {
        return scale_date;
    }

    /**
    * The method prints out only a temperature.
    * */
    public void printTemp() {
        System.out.printf("%+,.1f\u2103\32", scale);
        System.out.print('\n');
    }

    /**
    * The method prints out a temperature and date of a measurement.
    * */
    public void printTempFull() {
        System.out.printf("%+,.1f\u2103\32", scale);
        scale_date.printDate();
    }

    @Override
    public String toString() {
        return (scale > 0 ? "+" : "") + scale + "°C" + " " + scale_date.getDateFormat("dd.mm.yyyy");
    }
}
