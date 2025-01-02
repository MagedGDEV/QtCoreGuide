# First Steps

When starting a new project with Qt, your application typically begins with a simple console program that enters an event loop and waits for events to process. Here's an example of a basic Qt application:

```cpp

#include <QCoreApplication>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    return a.exec();
}
```

## Setting Up CMake for Your Qt Project

CMake is the tool used to configure and manage the build process for your Qt project. It helps you define how the code should be compiled, linked, and packaged.

In this section, we will introduce just a few lines of **CMake configuration** that are needed to set up the project. **CMake will be explained in detail later** in the repository.

1. **Declaring the Project**

    ```cmake
    project(nameofproject LANGUAGES CXX)
    ```

    - This line declares your project to CMake and specifies the programming language being used, which is C++ in this case.
    - Replace **`nameofproject`** with the actual name of your project.

2. **Setting the C++ Standard**

    ```cmake
    set(CMAKE_CXX_STANDARD 17)
    ```

    - This line specifies the version of the C++ standard to use for compiling the project.

3. **Finding the Qt Package**

    ```cmake
    find_package(Qt6 REQUIRED COMPONENTS Core)
    ```

    - This line instructs CMake to search for the **Qt6 package**. The **`REQUIRED`** flag means that if Qt6 is not found, the build process will fail.
    - **`Core`** specifies that you want to use the **Qt Core** module, which provides essential Qt functionality like event handling and file management.

4. **Creating the Executable**

```cmake
add_executable(nameofproject main.cpp)
```

- This line tells CMake to create an executable named **`nameofproject`** from the source file **`main.cpp`**.
- You can add more source files to this list if your project grows and you have additional files to compile.

## Hello World in Qt

The first thing every programmer does when learning a new technology is to print "Hello World" to the console. This is a simple and effective way to get started with any programming environment, and with Qt, it’s no different.

Here’s a minimal example of a Qt console application that prints "Hello World":

```cpp
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qInfo() << "Hello World!";
    return a.exec();
}
```

- **`qInfo()`** is a Qt-specific function that writes output to the console. It's similar to the standard **`std::cout`** in C++, but it provides additional features for logging and formatting output in Qt applications.
- This function prints the message **`"Hello World!"`** to the console.
- The **`<<`** operator is used to pass the string to **`qInfo()`**, just like you would use **`std::cout`** in standard C++.
