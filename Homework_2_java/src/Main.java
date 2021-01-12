public class Main {
    public static void main(String[] args) {
        int[ ] arr1={81,122,3898,15153,5967,264,798};
        Utility.printArray(arr1);
        System.out.println("#Q1");
        Utility.shiftRight(arr1);
        Utility.printArray(arr1);
        System.out.print("#Q2\nMax sum digits number is: ");
        Utility.maxSumDigits(arr1);
        System.out.print("#Q3\nCount even and odd digits number is: ");
        Utility.countEvenOdd(arr1);
        System.out.println("#Q4");
        Utility.sortEvenOdd(arr1);
        Utility.printArray(arr1);
        System.out.println("#Q5");
        MyDate[] arr2 = {
                new MyDate(1,11,2019),new MyDate(2,12,2019),
                new MyDate(12,8,2019), new MyDate(4,12,2019),
                new MyDate(3,12,2019),new MyDate(14,12,2019)};
        Utility.threeDates(arr2).printDate();
        System.out.println("#Q6");
        Location[] arr3 = {
                new Location("Tel-Aviv"),
                new Location("London"),
                new Location("Paris"),
                new Location("Berlin")
        };
        arr3[0].addTemp(12);
        arr3[0].addTemp(14,1,12,2019);
        arr3[0].addTemp(21,28,11,2019);
        arr3[0].addTemp(30,12,9,2019);
        arr3[1].addTemp(25,28,8,2019);
        arr3[1].addTemp(10);
        arr3[1].addTemp(14,10,10,2019);
        arr3[1].addTemp(17,9,11,2019);
        arr3[1].addTemp(14,28,11,2019);
        arr3[1].addTemp(-11,2,12,2019);
        arr3[2].addTemp(27,4,7,2019);
        arr3[2].addTemp(25,2,8,2019);
        System.out.println("Number of locations is: " + Location.getCount());
        for (Location x: arr3)
            x.printLocation();
        System.out.println("\nmax average temp of: ");
        arr3[maxTemp(arr3)].printLocation();
        System.out.println("In " + arr3[maxTemp(arr3)].getName() + " is an average temperature is: " +
                (int)arr3[maxTemp(arr3)].average() + (char)176 + "C\n");
        System.out.print("max temperature of "+ arr3[1].getName()+ ": ");
        arr3[1].max().printTempFull();
        System.out.println("temperatures close to average: " + (int)arr3[1].average() + (char)176 + "C\n");
        arr3[1].printLocation();
    }

    /**
     * The method returns an index of location, where is a max average temperature
     * */
    private static int maxTemp(Location ... array) {
        int index = 0;
        double previous = 0;
        for (int i = 0; i < array.length; i++) {
            double current = 0;
            for (int j = 0; j < array[i].getTemp().length; j++) {
                current += array[i].getTemp()[j].getScale() / array[i].getTemp().length;
            }
            if (current > previous)
                index = i;
            previous = current;
        }
        return index;
    }
}
