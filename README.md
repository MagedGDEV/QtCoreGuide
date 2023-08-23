# First Steps

**Qt** is a cross-platform application framework that is widely used for developing application software with a graphical user interface (GUI) (in which cases Qt is classified as a widget toolkit), and also used for developing non-GUI programs such as command-line tools and consoles for servers.

it is powerful, and useful for many applications, but it is also complex, and getting started with it can be daunting. This guide is intended to help developers get started with Qt for the first time, and to help experienced developers learn more about best practices for working with Qt.

it uses C++ as its primary programming language, and there are bindings available for a number of other languages, including Python, Java, and JavaScript. This guide will focus on C++.

it uses **CMake** as its build system, and there are a number of tools available for working with CMake projects, before they used **qmake** as its build system, but Qt switched to CMake in version 6.0. This guide will focus on using CMake.

To print hello world into the terminal using Qt, you can use the following code:

```cpp
#include <QApplication>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qInfo() << "Hello World";

    return app.exec();
}
```
