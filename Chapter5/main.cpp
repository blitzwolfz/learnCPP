// Chapter5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>

/*
	The way to deal with polymorphism in C++ is to use interfaces.
	However the language does not have an interface keyword
	So you have to use a superclass to define it
*/

struct Logger {
    //A way to allow derived classes to override our methods is to use the virtual keyword
    //This allows
    virtual  ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[Console] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

/*
 * One way to use an interface is by doing constructor injection.
 * Basically, you insert the the interface when you make the object
*/
struct BankWithConst {
    BankWithConst(Logger& logger) : logger{ logger } { }
    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
    }
private:
    Logger& logger;
};

struct BankWithProp {
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }
private:
    Logger* logger{};
};

struct Bank {
    Bank(Logger* logger) : logger{ logger } { }
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }
private:
    Logger* logger{};
};

int main() {

    ConsoleLogger logger;
    BankWithConst bankWithConst{ logger };
    bankWithConst.make_transfer(1000, 2000, 49.95);
    bankWithConst.make_transfer(2000, 4000, 20.00);
    printf("^This is with object injection\n\n");

    //The issue with going this is that, we are giving a refernce to a logger.
    // References can't be reset, so we choose the logger when we make the object
    //The other way, is to use property injection



    ConsoleLogger console_logger;
    FileLogger file_logger;
    BankWithProp bankWithProp;

    bankWithProp.set_logger(&console_logger);
    bankWithProp.make_transfer(1000, 2000, 49.95);

    bankWithProp.set_logger(&file_logger);
    bankWithProp.make_transfer(2000, 4000, 20.00);
    printf("^This is with property injection\n");

    //Both uses come with some form of drawback. With obj injection, you aren't able to switch loggers throughout it's
    // life cycle, and with pointer injection, you may add a nullptr. The best practice is to use both, so that you
    // don't cause a memory issue
    printf("\n\n");

    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    Bank bank{ &consoleLogger };

    bank.make_transfer(1000, 2000, 49.95);

    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);

}

