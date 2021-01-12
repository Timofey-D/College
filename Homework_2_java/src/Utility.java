public class Utility {
    /**
     * printArray, которая получает массив целых чисел и распечатывает его
     * на экран для проверки следующих четырех функций:
     */
    public static void printArray(MyDate ... array) {
        for (MyDate date: array) {
            date.printDate();
        }
        System.out.print('\n');
    }

    /**
    * printArray, которая получает массив целых чисел и распечатывает его
    * на экран для проверки следующих четырех функций:
    */
    public static void printArray(int ... array) {
        for (int number: array) {
            System.out.print(number + " ");
        }
        System.out.print('\n');
    }

    /**
    * Напишите статическую функцию по имени shiftRight, которая получает массив целых чисел
    * и сдвигает числа в массиве по кругу на одно место в правую сторону. void shiftRight(int[ ])
    * массив: 1,2,3,4,5
    * результат: 5,1,2,3,4
    * */
    public static int[] shiftRight(int ... array) {
        for (int i = array.length - 1; i > 0; i--) {
            int current = array[i];
            array[i] = array[i - 1];
            array[i - 1] = current;
        }
        return array;
    }

    /**
    * Напишите статическую функцию по имени maxSumDigits, которая получает массив целых положительных чисел
     * и возвращает то число из массива у которого наибольшая сумма цифр.
     * массив: 81,122,3898,15153,5967,264,798
     * функция вернёт: 3898
    * */
    public static void maxSumDigits(int ... array)     {
        int sum = 0;
        int max = 0;
        int result = 0;
        for (int value : array) {
            int save = value;
            while (save != 0) {
                sum += save % 10;
                save /= 10;
            }
            if (sum >= max) {
                max = sum;
                result = value;
            }
            sum = 0;
        }
        System.out.println(result);
    }

    /**
     * Напишите статическую функцию по имени countEvenOdd, которая получает массив целых положительных чисел
     * и возвращает количество чисел у которых есть четные и нечетные цифры.
     * массив: 81,122,3898,15153,5967,264,798
     * функция вернёт: 5
     * */
    public static void countEvenOdd(int ... array) {
        int count = 0;
        for (int value : array) {
            int save = value;
            int odd = 0;
            int even = 0;
            while (save != 0) {
                even += (save % 10) % 2 == 0 ? 1 : 0;
                odd += (save % 10) % 2 != 0 ? 1 : 0;
                if (even > 0 && odd > 0) {
                    count++;
                    break;
                }
                save /= 10;
            }
        }
        System.out.println(count);
    }

    /**
    * Напишите статическую функцию по имени sortEvenOdd, которая получает массив целых чисел и упорядочивает числа так,
     * чтобы нечетные числа были с начала а четные в конце.
     * Например:
     * массив: 798, 81, 122, 3898, 15153, 5967, 264
     * результат: 81 15153 5967 798 122 3898 264
    * */
    public static int[] sortEvenOdd(int ... array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - 1; j++) {
                if (array[j] % 2 == 0) {
                    int change = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = change;
                }
            }
        }
        return array;
    }

    /**
     * The method sorts an array, which contains ane dates
     * */
    public static void sortMyDateArray(MyDate ... array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - 1; j++) {
                if (array[j].getQuantityDays() >= array[j + 1].getQuantityDays()) {
                    MyDate change = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = change;
                }
            }
        }
    }

    /**
     * Напишите статическую функцию по имени threeDates, которая получает массив календарных чисел ищет
     * и возвращает то календарное число, для которого в массиве есть еще два календарных числа составляющиее серию
     * из трех последовательных календарных чисел. Если такого календарного числа в массив нет функция возвращает текущее календарное число.
     * массив: 01/11/2019, 02/12/2019, 12/08/2019, 04/12/2019, 03/12/2019, 14/12/2019
     * функция вернёт: 02/12/2019
     * */
    public static MyDate threeDates(MyDate ... array) {
        sortMyDateArray(array);
        for (int current = array.length - 1; current >= 0; current--) {
            for (int compare = array.length - 2; compare >= 0; compare--) {
                if ( array[current].getQuantityDays() - array[compare].getQuantityDays() == 2 &&
                        array[current].getQuantityDays() - array[compare + 1].getQuantityDays() == 1 )
                    return array[compare];
            }
        }
        return new MyDate();
    }
}