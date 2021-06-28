#include <cstdio>
#include <cstdint>

int main() {
    bool t = true;
    bool f = false;
    printf("!true: %d\n", !t);
    printf("true && false: %d\n", t && f);
    printf("true && !false: %d\n", t && !f);
    printf("true || false: %d\n", t || f);
    printf("false || false: %d\n", f || f);

    //Arrays
    int arr[] = {1, 2, 3, 4};
    printf("The third element is %d.\n", arr[2]);
    arr[2] = 100;
    printf("The third element is %d.\n", arr[2]);

    unsigned long maximum = 0;
    unsigned long values[] = {10, 50, 20, 40, 0};

//    for(size_t i=0; i < 5; i++) {
//        printf("Current value is %d\n", values[i]);
//        if (values[i] > maximum) {
//            maximum = values[i];
//        };
//    }

    //Better way to loop
    for (unsigned long value : values) {
        if (value > maximum) maximum = value;
    }
    printf("The maximum value is %lu\n", maximum);

    short array[] = { 104, 105, 32, 98, 105, 108, 108, 0 };
    size_t n_elements = sizeof(array)/sizeof(short);

    //C Style Strings
    char english[] = "A book holds a house of gold.";
    char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

    //Example of using them
    char house[] = "a house of gold.";
    printf("A book holds %s\n ", house);

    //White space is ignored
    char house_with_whitespace[] = "a "
                   "house "
                   "of " "gold.";
    printf("A book holds %s\n ", house_with_whitespace);

    /*
     * Three forms of user defined types
     * -Enums:
     *      The simplest of the user-defined types. The values
            that an enumeration can take are restricted to a set of possible values.
            Enumerations are excellent for modeling categorical concepts.
     * -Classes:
     *      More fully featured types that give you flexibility to pair data
            and functions. Classes that only contain data are called plain-old-data
            classes; you’ll learn about them in this section.
     * -Unions:
     *      A boutique user-defined type. All members share the same
            memory location. Unions are dangerous and easy to misuse.
     */

    //Enums
    enum class race {
        Dinan,
        Teklan,
        Ivyn,
        Moiran,
        Camite,
        Julian,
        Aidan
    };

    //Example of usage
    race me = race::Aidan;

    //There are two types of enums, scoped and unscoped. Use scoped like above, as other is unsafe

    //Union
    /*
     * The union Variant can be interpreted as a char[10], an int, or a double.
     * It takes up only as much memory as its largest member
     *
    */
    union Variant {
        char string[10];
        int integer;
        double floating_point;
    };

    // Plain old data classses. They are a type of class

    struct Book {
        char name[256];
        int year;
        int pages;
        bool hardcover;
    };

    Book neuromancer;
    neuromancer.pages = 271;
    printf("Neuromancer has %d pages.", neuromancer.pages);

    //Classes that we are normally used to in C++ with struct keyword
    /*
     * All classes made with the keyword struct have members set to public
    */
    struct ClockOfTheLongNow {
        ClockOfTheLongNow(int year_in){
            if(!set_year(year_in)){
                year = 2019;
            }
        }
        void add_year() {
            year++;
        }

        bool set_year(int new_year) {
            if (new_year < 2019) return false;
            year = new_year;
            return true;
        }

        int get_year() {
            return year;
        }

    private:
        int year;
    };

    ClockOfTheLongNow clock{ 2020 };
    printf("Year: %d", clock.get_year());

    struct PodStruct {
        uint64_t a;
        char b[256];
        bool c;
    };

    PodStruct initialized_pod1{}; // All fields zeroed
    PodStruct initialized_pod2 = {}; // All fields zeroed
    PodStruct initialized_pod3{ 42, "Hello" }; // Fields a & b set; c = 0
    PodStruct initialized_pod4{ 42, "Hello", true }; // All fields set

    //However this wouldn't compile
    //PodStruct initialized_pod(42, "Hello", true);

    struct Earth {
        ~Earth() { // Earth's destructor. This used when an object gets destroyed
            printf("Making way for hyperspace bypass");
        }
    };

    return 0;
}
