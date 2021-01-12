/*
* Создайте класс Location, который описывает замеры температур в географическом месте.
* Класс Location должен иметь следующие атрибуты (свойства):
* private int id - номер места(порядковый номер должен быть реализован статической переменной).
* private String name - название географического места.
* private Temperature temp[ ] - список замеров температур.
* */

public class Location {
    // variable of instance
    private static int id = 0;
    private int number = 0;
    private String name;
    private Temperature[] temp;

    // Constructor with parameters
    Location(String name) {
        this(name, null);
        id++;
        number = id;
    }

    Location(String name, Temperature[] temp) {
        this.name = name;
        this.temp = null;
    }

    /**
     * The method prints out a location and the temperature measurements in this location.
     * */
    public void printLocation() {
        System.out.printf("%d) %s ", number, this.name);
        if (this.temp != null) {
            sortedTempArray();
            System.out.print("{");
            for (int i = 0; i < temp.length; i++) {
                System.out.print(temp[i]);
                if (i != temp.length - 1)
                    System.out.print(" : ");
                else
                    System.out.print("}");
            }
        }
        else {
            System.out.print("doesn't have temperature measurements");
        }
        System.out.print("\n");
    }

    /**
    * The method returns number of locations.
    * */
    public static int getCount() {
        return id;
    }

    /**
    * The method returns the temperature measurements array.
    * */
    public Temperature[] getTemp() {
        if (this.temp == null)
            return new Temperature[] {};
        return temp;
    }

    /**
     * The method returns a name location.
    * */
    public String getName() {
        return name;
    }

    /**
     * The method adds a temperature measurement the specify date in the temperature measurement array.
     * */
    public void addTemp(double scale, int day, int month, int year) {
        extendTempArray();
        this.temp[this.temp.length - 1] = new Temperature(scale, day, month, year);
    }

    /**
     * The method adds a temperature measurement in the temperature measurement array.
    * */
    public void addTemp(double scale) {
        extendTempArray();
        this.temp[this.temp.length - 1] = new Temperature(scale, new MyDate());
    }

    /**
    * The method extends the temperature measurement array.
    * */
    private void extendTempArray() {
        Temperature[] saver = this.temp;
        if (this.temp == null)
            this.temp = new Temperature[1];
        else {
            int length = this.temp.length;
            this.temp = new Temperature[length + 1];
            for (int i = 0; i < this.temp.length; i++) {
                if (saver.length - 1 >= i)
                    this.temp[i] = saver[i];
            }
        }
    }

    /**
    * The method sorts by increase a date the temperature measurements.
    * */
    private void sortedTempArray() {
        for (int i = 0; i < this.temp.length; i++) {
            for (int j = 0; j < this.temp.length - 1; j++) {
                if ( this.temp[j].getScale_date().getQuantityDays() >= this.temp[j + 1].getScale_date().getQuantityDays()) {
                    Temperature change = this.temp[j];
                    this.temp[j] = this.temp[j + 1];
                    this.temp[j + 1] = change;
                }
            }
        }
    }

    /*
    * The method returns a max temperature.
    * */
    public Temperature max() {
        int length = this.getTemp().length;
        double previous = 0;
        Temperature max = new Temperature();
        for (int i = 0; i < length; i++) {
            double current = this.getTemp()[i].getScale();
            if (current > previous)
                max = this.getTemp()[i];
            previous = current;
        }
        return max;
    }

    /**
     * The method returns amn average value of temperature
     * */
    public double average() {
        int length = this.temp.length;
        double average = 0;
        for (int i = 0; i < length; i++)
            average += this.temp[i].getScale();
        return average / length;
    }
}
