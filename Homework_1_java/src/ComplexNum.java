import java.util.Objects;

/*
* Класс ComplexNum описывает Комплексные числа вида a+bi, a,b — вещественные числа,
* i - мнимая единица, то есть число, для которого выполняется равенство:
* i^2 = -1
* Описание класса:
* Класс ComplexNum должен иметь следующие атрибуты (свойства):
* double real - вещественная часть.
* double image - мнимая часть.
* Класс ComplexNum должен иметь три конструктора:
* Дефолтный конструктор, который определяет значение атрибутов 0.
* Конструктор, который получает два параметра, которые являются значениями для атрибутов класса.
* Конструктор копирования, который получает объект ComplexNum и копирует его значения.
* */
public class ComplexNum {
    // variable of instance
    private double real;
    private double image;

    // Default constructor
    ComplexNum() {
        this.real = 0;
        this.image = 0;
    }

    /**
     * Constructor with parameters
     * @param real - a fractal part
     * @param image - a
    * */
    ComplexNum(double real, double image) {
        this.real = real;
        this.image = image;
    }

    /**
     * Constructor does a copy complex number.
     */
    ComplexNum(ComplexNum other) {
        this.real = other.real;
        this.image = other.image;
    }

    // Block of getter
    public double getReal() {
        return real;
    }
    public double getImage() {
        return image;
    }

    // Block of setter
    public void setReal(double real) {
        this.real = real;
    }
    public void setImage(double image) {
        this.image = image;
    }

    /**
    * The method prints out a complex number.
    * */
    public void printComplex() {
        if (this.real != 0 & this.image != 0)
            System.out.printf("%,.0f%+,.0fi\n", this.real, this.image);
        else if (this.real == 0)
            System.out.printf("%,.0fi\n", this.image);
        else
            System.out.printf("%,.0f\n", this.real);
    }

    /**
    * The method returns a complex number presented a string.
    * */
    public String strComplex() {
        return String.format("\"%,.0f%+,.0fi\"", this.real, this.image);
    }

    /**
    * The method gets a instance of class and returns a new instance of class.
    * */
    public static ComplexNum addComplex(ComplexNum num) {
        return new ComplexNum(num.real + num.real, num.image + num.image);
    }

    /**
    * The method returns an integer value a square root of addition real^2 and image^2.
    * */
    public int getAbsolute() {
        return (int) Math.sqrt(this.real * this.real + this.image * this.image);
    }

    /**
    * The method compares two complex number and returns a boolean value.
    * */
    public boolean equal(ComplexNum other) {
        if (other == this)
            return true;
        if (other == null || getClass() != other.getClass())
            return false;
        return other.real == real & other.image == image;
    }

    @Override
    public int hashCode() {
        return Objects.hash(real, image);
    }
}
