#include <cstdio>

/*
 * Statements
*/

struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s constructed.\n", name);
    }
    ~Tracer() {
        printf("%s destructed.\n", name);
    }
private:
    const char* const name;
};

enum class Color {
    Red,
    Blue,
    Green,
};

void printNumber(int x);

int main() {

    //Expression Statements are basically things that end with a ;
    int x{};
    ++x;
    42;
    printf("The %d True Morty\n", x);

    //Compound Statements are basically things enclosed by {}

    Tracer main{ "main" };
    {
        printf("Block a\n");
        Tracer a1{ "a1" };
        Tracer a2{ "a2" };
    }

    {
        printf("Block b\n");
        Tracer b1{ "b1" };
        Tracer b2{ "b2" };
    }

    //Declaration Function, basically when you declare things like functions and what not
    //A cool thing you can do with functions is that you can declare them above main, but then define them below
    //For example

    printNumber(42);

    //Namespaces are basically std:: ykyk

    //Selection statements, most famous use case is control flow
    //For example
    int y = 100; //Try changing this to a negative

    if(y <= 0) {
        printf("It's less than 0\n");
    }

    else {
        printf("It's greater than 0\n");
    }

    //We also have switch statements

    Color color = Color::Blue;

    switch (color) {
        case Color::Red: {
            printf("It's red\n");
            break;
        }

        case Color::Blue: {
            printf("Blue\n");
            break;
        }

        case Color::Green: {
            printf("Green\n");
            break;
        }
    }

    //Iteration statements: do while, while, range, and for

    for(int i = 0; i < 10; i++){
        printf("In for loop, currently at: %d\n", i);
    }

    const int z[]{ 1, 1, 2, 3, 5, 8 };

    for(const auto element : z){
        printf("Z array, current element is: %d\n", element);
    }

    int u = 10;

    while (u != 0){
        printf("In while loop, current value of u is: %d\n", u);
        u--;
    }

    do {
        printf("In do while loop, current value of u is: %d\n", u);
        u--;
    } while(u > 0);

    //The difference between do and regular while is that do while loop at least once before checking the condition

    //We also have break, and continue. Those are similar to other languages
    //Goto is not something one should use in modern C++.

//    printf("Hello World\n");
    return 0;
}

void printNumber(int x){
    printf("\nThe number used to invoke printNumber function is: %d\n\n", x);
}

