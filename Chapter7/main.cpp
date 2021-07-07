#include <cstdio>

//Operators

/*
 * We have seen operators before. +, -, * (which is used for multiple things).
 * There are other operators,
*/

int main() {

    //Uniary Arithmetic Operators. They take a variable and promote it to an int type.
    // If it is a negative sign, then the int is a negative int
    char l = 10;
    printf("%d\n", +l);
    printf("%d\n", -l);

    //You have regular arithmetic operators like 1 + 1. Which don't need explaining.
    //Assignments can also use operators so if y = 5, x = 10, then for example x += y, x is now 15
    //You also have bitwise operators

    //Increment and Decrement Operators
    //These are the x++ you might see in for loops.
    //There are four types, ++x, --x, x++, x--
    //If it is in front, then the value is changed before being evaluated,
    // if it's in the back then it's changed after

    //comparision operators, basically do a comparision, and outputs a boolean value

    //Ternary operators is basically x ? y : z, which is if x is true do y, if not do z
    bool isten = true;
    printf("%d\n", (isten ? 10 : 1));
    isten = false;
    printf("%d\n", (isten ? 10 : 1));

    return 0;
}
