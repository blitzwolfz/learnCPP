#include <cstdio>

/*
 * While the previous chapter dealt with runtime polymorphism
 * this one deals with compile time polymorphism. This is achieved using
 * Templates.
*/

//To declare a template class
//template <typename X, typename Y, typename Z>
//struct MyTemplateClass {
//    X foo(Y&);
//
//private:
//    Z* member;
//};

//To declare a template function
//template<typename X, typename Y, typename Z>
//X my_template_function(Y& arg1, const Z* arg2) {
//
//}

// Say we have a mean function, that is to calculate the mean
// We could either make a function for every number type
// or we can use templates

template<typename T>
T mean(T* values, size_t length){
    T result = {};

    for(size_t i = {}; i<length; i++) {
        result += values[i];
    }
    return result / length;
}

int main() {
    printf("Hello World\n");
    double nums_d[] { 1.0, 2.0, 3.0, 4.0 };
    auto result1 = mean(nums_d, 4);
    printf("double: %f\n", result1);

    float nums_f[] { 1.0f, 2.0f, 3.0f, 4.0f };
    auto result2 = mean<float>(nums_f, 4);
    printf("float: %f\n", result2);

    size_t nums_c[] { 1, 2, 3, 4 };
    auto result3 = mean<size_t>(nums_c, 4);
    printf("size_t: %zd\n", result3);

    return 0;
}
