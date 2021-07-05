#include <cstdio>

/*
 * This lesson is on References, and Pointers.
 * We will deal with pointers, how they work,
 * references, the symbols used for them
 * some cool OS specific things. Also this will
 * be the basis for Memory Management
*/

int main() {

    //A pointer is basically a variable. This variables job is to hold a memory address
    //To declare a pointer, you have to do type + * then name of the variable
    int* pointerUno; //This declares a int pointer. You can have other kinds of pointers

    //Unlike one line var declaration, this is not possible with pointers
    int* p1, *p2; //Declares pointers p1 and p2

    int* p3, p4; //Declares pointer p3 and a variable p4 of type int

    //To print a pointer using printf you use the %p symbol
    printf("The value of my_ptr is %p.\n", pointerUno); // <--- might not change if you do it on the same machine

    //One cool thing is, if you were to compile and run this program on another computer, the memory address would be
    //different. This is a thing that all major OS will do to prevent memory exploitation and cause unwanted issues

    //Lets declare a variable called gettysburg
    int gettysburg = 0;
    printf("gettysburg: %d\n", gettysburg);


    /*
        * When we do type *, we are telling the compiler
        * hey I wanna declare this variable as a pointer variable.
        * This tells the compiler, that this variable's job is to point to memory
        * However, let's say you have a regular variable, but you wanted to use a
        * pointer as a means of passing the variable around. How would you do this?
        * Using the the &, you get a reference to that variable's memory address
    */
    int* gettysburg_address = &gettysburg;
    printf("&gettysburg: %p\n", gettysburg_address);

    //De-referencing a pointer refers to you modifying the reference's value
    //For example, let's say I want to change gettysburg to a different value, I could do it
    // my changing the variable itself, however, a situation may arise where I only have a pointer
    // this is where de-referencing comes in

    *gettysburg_address = 100; //This will change the value of gettysburg
    //Value has changed, address hasn't
    printf("gettysburg: %d\n", gettysburg);
    printf("&gettysburg: %p\n\n", gettysburg_address);

    /*
         * One source of issue is with *. This is used for making pointers
         * de-referencing, and multiplication.
         *
         * The way I use it is this:
         * Pointers : type* name;
         * De-reference: *name
         * Multiplication: number * number
         *
         * Of course you may have your own way
     */


    /*
         * The arrow operator is important for pointers, and using them to access data
         * The arrow operator is similar to the dot operator found in other languages
         * and C++. However, the difference is, it is used with pointers
     */

    //Lets say I make an class called whatYear
    struct whatYear {
        whatYear(int year_in){
            year = year_in;
        }

        int get_year() {
            return year;
        }

        int printFunny = 69420;
    private:
        int year;
    };

    whatYear year (2020);
    printf("It is the year: %d\n", year.get_year());

    //Just like other types, we can have a pointer point to our year variable
    //We use the same syntax as before. Type* name = a reference of a variable
    whatYear* year_ptr = &year;

    /*
        * The issue now is, what if I want to access the get_year() method? How would I do that??
        * The answer to that is the arrow operator
     */

    printf("It is the year: %d\n", year_ptr -> get_year());
    printf("Funny number: %d\n", year_ptr -> printFunny); //You can also use it to get class attributes

    //As with all things in C++, there is another way to get methods and attributes without arrow operator
    //But it is more verbose. It however does use the dot operator. However this mainly to show why
    // using the arrow is a better idea
    printf("It is the year: %d\n", (*year_ptr).get_year());
    printf("Funny number: %d\n", (*year_ptr).printFunny);

    

    return 0;
}
