import java.time.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("#1 - printLandingTime");
        printLandingTime(13, 23, 43, 236785);
        System.out.println("___________________________________________\n#2 - getMax");
        getMax(189, 97513, 68428, 9459, 3135, 967, 121, 15, 989, 2897);
        System.out.println("___________________________________________\n#3 - countSymmetricalNumbers");
        countSymmetricalNumbers(8, 3135, 967, 1234321, 15, 989, 271897, 0);
        System.out.println("___________________________________________\n#4 - getGCD");
        getGCD(252, 105);
        System.out.println("___________________________________________\n#5 - Complex number");
        double[] reals = {2, 3, 2, 2};
        double[] images = {3, 3, 0, -3};
        for (int i = 0; i < reals.length; i++) {
            ComplexNum number = new ComplexNum(reals[i], images[i]);
            System.out.print("Primary complexNum: ");
            number.printComplex();
            System.out.println("The string: " + number.strComplex());
            System.out.print("Other complexNum: ");
            ComplexNum.addComplex(number).printComplex();
            System.out.println("Absolute value: " + number.getAbsolute());
            System.out.println(number.equal(ComplexNum.addComplex(number)));
            System.out.print("\n");
        }

    }

    /*
    * Напишите функцию по имени printLandingTime, которая получает время старта ракеты (часы, минуты,секунды),
    * время полета в секундах и выводит на экран время приземления ракеты (часы, минуты, секунды) .
    * Если время приземления: 23:05:10, функция выведет на экран: 23 hours, 5 minutes, 10 seconds
    * Обратите внимание и проверьте, что функция получает правильное время старта ракеты.
    * Если функция получает не правильное время старта,
    * необходимо вывести на экран соответствующие сообщение и закончить её выполнение.
    * Для вывода на экран также должны обрабатываться следующие случаи:
    * Если минуты или секунды при приземлении равны нулю, не печатайте их. Например: Если время приземления: 23:00:10
    * функция выведет на экран: 23 hours, 10 seconds
    * Если минуты и секунды при приземлении равны нулю, необходимо добавить слово ’exactly’.
    * Если время приземления: 23:00:00 функция выведет на экран: 23 hours exactly
    * Если часы, минуты или секунды при приземлении равны 1, необходимо написать hour вместо hours,
    * minute вместо minutes и second вместо seconds.
    * Если время приземления: 01:01:07 функция выведет на экран: 1 hour, 1 minute, 7 seconds
    * Если час при приземлении больше 24, необходимо добавить к времени количество дней в полете.
    * Если время приземления: 49:20:15 функция выведет на экран: 1 hour, 20 minutes, 15 seconds (+2 days)
    * Если время приземления: 25:20:15 функция выведет на экран: 1 hour, 20 minutes, 15 seconds (+1 day)
    * */
    public static void printLandingTime(int hour, int minute, int second, int flight) {
        hour = hour < 0 || hour > 23 ? 0 : hour;
        minute = minute < 0 || minute > 59 ? 0 : minute;
        second = second < 0 || second > 59 ? 0 : second;
        LocalTime timeStart = LocalTime.of(hour, minute, second);
        LocalTime timeReturn = timeStart.plusSeconds(flight);
        String days = flight / 86400 == 0 ? "" : flight / 86400 > 1 ? "+" + flight / 86400 + " days " : "+" + flight / 86400 + " day ";
        String hours = timeReturn.getHour() > 1 ? " hours " : " hour ";
        String minutes = timeReturn.getMinute() == 0 ? "" : timeReturn.getMinute() > 1 ? " minutes " : " minute ";
        String seconds = timeReturn.getSecond() == 0 ? "" : timeReturn.getSecond() > 1 ? " seconds " : " second ";
        System.out.println( "Time of start: " + timeStart + "\nThe time of flight: " + flight + "\n" + "Time of return: " +
                days +
                timeReturn.getHour() + hours + (timeReturn.getMinute() == 0 & timeReturn.getSecond() == 0 ? "exactly" : "") +
                (timeReturn.getMinute() == 0 ? "" : timeReturn.getMinute()) + minutes +
                (timeReturn.getSecond() == 0 ? "" : timeReturn.getSecond())  + seconds );
    }

    /*
    * Напишите функцию по имени getMax, которая получает от пользователя серию из 10 целых положительных чисел
    * и возвращает максимальное число, которое состоит из четных и нечетных цифр.
    * серия: 189, 97513, 68428, 9459, 3135, 967, 121, 15, 989, 2897
    * функция вернёт: 9459
    * */
    public static void getMax(int ... numbers) {
        int max = 0;
        for (int i = 0; i < 10; i++) {
            int number = numbers[i];
            int odd = 0;
            int even = 0;
            int now = number;
            while (number != 0) {
                even += number % 10 % 2 == 0 ? 1 : 0;
                odd += number % 10 % 2 != 0 ? 1 : 0;
                if (odd > 0 && even > 0)
                    break;
                number /= 10;
            }
            if (odd > 0 && even > 0)
                max = Math.max(max, now);
        }
        System.out.println(max);
    }

    /*
    * Напишите функцию по имени countSymmetricalNumbers, которая которая получает серию целых положительных чисел,
    * значение 0 указывает на конец серии. Функция должна вернуть количество симметричных чисел.
    * серия: 8, 3135, 967, 1234321, 15, 989, 271897, 0
    * функция вернёт: 3
    * */
    public static void countSymmetricalNumbers(int ... numbers) {
        int recovery = 0;
        int save;
        int count = 0;
        for (int j : numbers) {
            if (j == 0)
                break;
            int number = j;
            save = number;
            while (number != 0) {
                recovery = (recovery * 10) + (number % 10);
                number /= 10;
            }
            if (recovery == save)
                count++;
            recovery = 0;
        }
        ;
        System.out.println(count);
    }

    /*
    * Напишите функцию по имени getGCD, которая получает два целых положительных числа и
    * возвращает наибольший общий делитель этих двух целых чисел с помощью Алгоритма Евклида.
    * функция получает: 252, 105
    * функция вернёт: 21
    * */
    public static void getGCD(int number_1, int number_2) {
        int result = 0;
        for (int i = 1; i < Math.max(number_1, number_2); i++) {
            if (number_1 % i == 0 & number_2 % i == 0)
                result = Math.max(result, i);
        }
        System.out.println(result);
    }
}
