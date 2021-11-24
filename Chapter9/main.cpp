#include <cstdio>
#include <cstdint>
#include <cstdarg>

/*
 * Functions
 * */

//For using auto in templates, you also need to use decltype
template<typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
    return x + y;
}

int oldSum(size_t n, ...) {
    va_list args;
            va_start(args, n);
    int result{};
    while (n--) {
        auto next_element = va_arg(args, int);
        result += next_element;
    }

            va_end(args);
    return result;
}

template<typename T>
constexpr T sum(T x) {
    return x;
}

template<typename T, typename... Args>
constexpr T sum(T x, Args... args);

template<typename T, typename... Args>
constexpr T sum(T x, Args... args) {
    return x + sum(args...);
}

//ASCII for A-Z and a-z
constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };
constexpr bool within_AZ(char x) { return pos_A <= x && pos_Z >= x; }
constexpr bool within_az(char x) { return pos_a <= x && pos_z >= x; }

struct Histogram {
    void push(const char* x);
    void print() const;

private:
    size_t counts[26]{};
};

void Histogram::push(const char *x) {
    size_t index{};
    while(const auto c = x[index]) {
        if (within_AZ(c)) counts[c - pos_A]++;
        else if (within_az(c)) counts[c - pos_a]++;
        index++;
    }
}

void Histogram::print() const {
    for(auto index{ pos_A }; index <= pos_Z; index++) {
        printf("%c: ", index);
        auto n_asterisks = counts[index - pos_A];
        while (n_asterisks--) printf("*");
        printf("\n");
    }
}

int main(int argc, char** argv) {

    //The auto keyword is used to make the compiler figure out the type
    //But with conversion rules, it's not really needed. However, it's useful
    // in template programming

    //Functions have prefix and suffix modifiers. Figure out when it's need

    auto x = add(1, 2);
    auto y = add(-1, -2);

    printf("%d %d\n", x, y);

    //Overloading means the compiler will look for something that matches the requirements exactly
    //Variadic functions are functions that limitless amount of args. printf is an example of that
    //You have to include cstdarg to use the things below
    /*
        * va_list : Used to declare a local variable representing the variadic arguments
        * va_start : Enables access to the variadic arguments
        * va_end : Used to end iteration over the variadic arguments
        * va_arg : Used to iterate over each element in the variadic arguments
        * va_copy : Makes a copy of the variadic arguments
    */

    //oldSum is an example of that.
    printf("The answer is %d.\n", oldSum(6, 2, 4, 6, 8, 10, 12));

    //Variadic functions are unsafe, and not worth using. It's better to use polymorphism or overloading
    printf("The answer is %d.\n", sum(6, 2, 4, 6, 8, 10, 12));

    //Functions pointers. Functions occupy space in memory, so you can point to a function and pass that as an arg

    //    printf("Arguments: %d\n", argc);
    //
    //    for (size_t i{}; i < argc; i++) {
    //        printf("%zd: %s\n", i, argv[i]);
    //    }

    Histogram hist;

    for(size_t i{ 1 }; i<argc; i++) {
        hist.push(argv[i]);
    }

    hist.print();

    return 0;
}
