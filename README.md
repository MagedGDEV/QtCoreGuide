# Basic Qt Classes

When writing cross-platform applications, one common issue is that the size of basic data types (like **`int`**) can vary between operating systems and hardware architectures. For example, an **`int`** might be 4 bytes on one system and 2 bytes on another. This can lead to bugs and inconsistencies in your program.

To address this, Qt provides a set of **fixed-size integer types** that ensure consistent sizes across all platforms. These types are defined in the **`QtCore`** module and are essential for writing portable and reliable code.

---

## 1. Fixed-Size Integer Types (`qint` Types)

Qt’s fixed-size integer types are aliases for basic types with guaranteed sizes. They are particularly useful for:

- Ensuring consistent behavior across platforms.
- Working with binary data, file I/O, or network protocols.
- Developing for embedded systems where data size constraints are critical.

### List of `qint` Types

| Type       | Description                     | Equivalent Standard Type |
|------------|---------------------------------|--------------------------|
| `qint8`    | 8-bit signed integer            | `signed char`            |
| `qint16`   | 16-bit signed integer           | `short`                  |
| `qint32`   | 32-bit signed integer           | `int`                    |
| `qint64`   | 64-bit signed integer           | `long long`              |
| `quint8`   | 8-bit unsigned integer          | `unsigned char`          |
| `quint16`  | 16-bit unsigned integer         | `unsigned short`         |
| `quint32`  | 32-bit unsigned integer         | `unsigned int`           |
| `quint64`  | 64-bit unsigned integer         | `unsigned long long`     |
| `qintptr`  | Signed integer for holding pointers | Platform-dependent      |
| `quintptr` | Unsigned integer for holding pointers | Platform-dependent      |

---

### How to Use `qint` Types

You can use these types just like regular integers. For example:

```cpp
qint8 a = 10;   // 8-bit signed integer
qint16 b = 20;  // 16-bit signed integer
qint32 c = 30;  // 32-bit signed integer
qint64 d = 40;  // 64-bit signed integer

quint8 e = 50;  // 8-bit unsigned integer
quint16 f = 60; // 16-bit unsigned integer
quint32 g = 70; // 32-bit unsigned integer
quint64 h = 80; // 64-bit unsigned integer
```

These types ensure that the size of the integer is consistent across all platforms. For example, **`qint8`** is always an 8-bit signed integer, regardless of the operating system or hardware.

---

### How It Works

Qt defines these types using the `typedef` keyword. For example:

```cpp
typedef signed char qint8;      // qint8 is an alias for signed char
typedef unsigned char quint8;   // quint8 is an alias for unsigned char
typedef short qint16;           // qint16 is an alias for short
typedef unsigned short quint16; // quint16 is an alias for unsigned short
// ... and so on for other types
```

This means that **`qint8`** is just another name for **`signed char`**, `qint16` is another name for **`short`**, and so on. By using these aliases, you ensure that your code is portable and behaves consistently across different platforms.

---

### Why Use `qint` Types?

1. **Cross-Platform Consistency**:
   - Ensures that your program behaves the same way on all platforms, regardless of the underlying architecture.

2. **Binary Data Handling**:
   - Essential when working with binary data, file formats, or network protocols where data size must be precise.

3. **Embedded Systems**:
   - Critical for embedded systems where memory and data size constraints are strict.

4. **Code Readability**:
   - Makes your code more readable and self-documenting by explicitly specifying the size of integers.

---

### Example: Using `qint` Types in Practice

```cpp
#include <QDebug>

int main() {
    qint8 smallNumber = 127;          // 8-bit signed integer
    quint32 largeNumber = 4294967295; // 32-bit unsigned integer

    qInfo() << "Small number:" << smallNumber;
    qInfo() << "Large number:" << largeNumber;

    return 0;
}
```

#### Output of qint Types

```txt
Small number: 127
Large number: 4294967295
```

## 2. QDate, QTime & QDateTime Classes

Qt provides three powerful classes for working with dates and times:

1. **`QDate`**: Represents a date (year, month, day).
2. **`QTime`**: Represents a time (hour, minute, second, millisecond).
3. **`QDateTime`**: Represents a date and time together.

These classes are part of the **`QtCore`** module and offer a wide range of functionalities for manipulating dates and times. They are designed to be easy to use, portable, and highly customizable.

---

### Common Use Cases for `QDate`, `QTime`, and `QDateTime`

#### 1. **`QDate`**

Represents a date (year, month, day).

##### Example of `QDate`

```cpp
#include <QDate>
#include <QDebug>

int main() {
    QDate currentDate = QDate::currentDate(); // Get the current date

    // Manipulate the date
    currentDate = currentDate.addYears(1);   // Add 1 year
    currentDate = currentDate.addMonths(2);  // Add 2 months
    currentDate = currentDate.addDays(30);   // Add 30 days

    // Format and display the date
    qInfo() << "Formatted Date (dd/MM/yyyy):" << currentDate.toString("dd/MM/yyyy");
    qInfo() << "ISO Format:" << currentDate.toString(Qt::ISODate);

    return 0;
}
```

##### Output of `QDate` Example

```txt
Formatted Date (dd/MM/yyyy): "30/05/2024"
ISO Format: "2024-05-30"
```

---

#### 2. **`QTime`**

Represents a time (hour, minute, second, millisecond).

##### Example of `QTime`

```cpp
#include <QTime>
#include <QDebug>

int main() {
    QTime now = QTime::currentTime(); // Get the current time

    // Manipulate the time
    now = now.addSecs(3600);  // Add 1 hour (3600 seconds)
    now = now.addMSecs(1000); // Add 1 second (1000 milliseconds)

    // Format and display the time
    qInfo() << "Formatted Time (hh:mm:ss.zzz):" << now.toString("hh:mm:ss.zzz");

    return 0;
}
```

##### Output of `QTime` Example

```txt
Formatted Time (hh:mm:ss.zzz): "14:30:45.000"
```

---

#### 3. **`QDateTime`**

Represents a date and time together.

##### Example of `QDateTime`

```cpp
#include <QDateTime>
#include <QDebug>

int main() {
    QDateTime currentDateTime = QDateTime::currentDateTime(); // Get the current date and time

    // Manipulate the date and time
    currentDateTime = currentDateTime.addDays(1); // Add 1 day

    // Format and display the date and time
    qInfo() << "Formatted DateTime:" << currentDateTime.toString("dd/MM/yyyy hh:mm:ss");

    return 0;
}
```

#### Output of `QDateTime` Example

```txt
Formatted DateTime: "31/05/2023 14:30:45"
```

---

### Practical Example: Checking for an Expired Date

You can use **`QDate`** to check if a date has expired (e.g., for license validation or subscription checks).

```cpp
#include <QDate>
#include <QDebug>

int main() {
    QDate expirationDate(2025, 12, 31); // Set expiration date
    QDate currentDate = QDate::currentDate(); // Get current date

    if (currentDate > expirationDate) {
        qInfo() << "License has expired!";
    } else {
        qInfo() << "License is valid.";
    }

    return 0;
}
```

#### Output (if current date is after December 31, 2025)

```txt
License has expired!
```

#### Output (if current date is before or on December 31, 2025)

```txt
License is valid.
```

> [!NOTE]
> The code examples provided are written for **Qt 6**. If you are using **Qt 5**, you may need to make slight adjustments to the syntax. Additionally, the **`QDate`**, **`QTime`**, and **`QDateTime`** classes offer a wide range of functionalities beyond what is shown here. For a comprehensive list of features and methods, refer to the official [Qt Documentation](https://doc.qt.io/).

## 3. QString Class

In Qt, the **`QString`** class is used to store and manipulate strings. It provides a wide range of functionalities for working with text, making it more powerful and flexible than standard C++ strings **`std::string`**. **`QString`** is part of the **`QtCore`** module and is designed to handle Unicode text seamlessly.

---

### Common Use Cases of `QString`

#### 1. **Extracting Substrings**

- Use **`mid()`** to extract a substring from a string.

   ```cpp
   QString str = "Hello, World!";
   QString subStr = str.mid(1, 3); // Extract 3 characters starting from index 1
   qInfo() << subStr; // Output: "ell"
   ```

- If the string is shorter than the requested length, `mid()` returns as many characters as possible without causing an error.

---

#### 2. **Inserting Text**

- Use **`insert()`** to insert text at a specific position.

   ```cpp
   QString str = "Maged Elesseily";
   str.insert(0, "Eng. "); // Insert "Eng. " at the beginning
   qInfo() << str; // Output: "Eng. Maged Elesseily"
   ```

---

#### 3. **Splitting Strings**

- Use **`split()`** to divide a string into a list of substrings based on a separator.

   ```cpp
   QString str = "Apple Banana Cherry";
   QStringList fruits = str.split(" "); // Split by space
   for (const QString& fruit : fruits) {
       qInfo() << fruit;
   }
   ```

##### Output of `split()` Example

```txt
"Apple"
"Banana"
"Cherry"
```

---

#### 4. **Finding Substrings**

- Use `indexOf()` to find the position of a substring.

   ```cpp
   QString str = "Hello, World!";
   int index = str.indexOf("World"); // Find the position of "World"
   qInfo() << "Index of 'World':" << index; // Output: 7
   ```

---

#### 5. **Other Useful Functions**

- **`toUpper()`** / **`toLower()`**: Convert the string to uppercase or lowercase.
- **`trimmed()`**: Remove leading and trailing whitespace.
- **`replace()`**: Replace occurrences of a substring with another string.
- **`startsWith()`** / **`endsWith()`**: Check if the string starts or ends with a specific substring.
- **`contains()`**: Check if the string contains a specific substring.
- ... and many more!

## 4. QByteArray Class

The **`QByteArray`** class in Qt is a container for storing and manipulating raw data, including binary data and 8-bit strings (e.g., ASCII or UTF-8). It is part of the **`QtCore`** module and is particularly useful for:

- **Storing binary data** (e.g., images, audio, serialized objects).
- **Working with 8-bit strings** (e.g., ASCII or UTF-8 encoded text).
- **Reading and writing files**.
- **Network communication**.

### Key Features of `QByteArray`

- **Dynamic Size**: Automatically resizes to accommodate new data.
- **Efficient Memory Management**: Uses implicit sharing to reduce memory usage.
- **Rich API**: Provides methods for appending, inserting, replacing, and searching data.

### Example of Using `QByteArray`

```cpp
#include <QByteArray>
#include <QDebug>

int main() {
    QByteArray data = "Hello";
    data.append(", World!"); // Append data
    qInfo() << data; // Output: "Hello, World!"
    return 0;
}
```

## 5. QVariant Class

The **`QVariant`** class in Qt is a versatile container that can store values of different types. It is part of the **`QtCore`** module and is particularly useful when you need to handle data of unknown or varying types. **`QVariant`** is widely used in Qt, especially in conjunction with **QML** and model-view programming.

### Key Features of `QVariant`

- **Type Flexibility**: Can store values of many types, including **`int`, `QString`, `QDate`, `QByteArray`**, and even custom types.
- **Type Detection**: Can determine the type of the stored value at runtime.
- **Implicit Sharing**: Efficiently manages memory by sharing data between copies.

### Common Use Cases of `QVariant`

1. **Storing and Retrieving Values**:
   - Store a value of any type in a **`QVariant`**.
   - Retrieve the value by converting it back to its original type.

2. **Type Checking**:
   - Check the type of the stored value using **`type()`** or **`canConvert<T>()`**.

3. **Working with QML**:
   - **`QVariant`** is heavily used in QML to pass data between C++ and QML.

---

### Example: Using `QVariant`

```cpp
#include <QVariant>
#include <QDebug>

int main() {
    // Store different types in QVariant
    QVariant v1 = 42;              // int
    QVariant v2 = "Hello, World!"; // QString
    QVariant v3 = 3.14;            // double

    // Retrieve and print values
    qInfo() << "v1:" << v1.toInt();       // Output: 42
    qInfo() << "v2:" << v2.toString();    // Output: "Hello, World!"
    qInfo() << "v3:" << v3.toDouble();    // Output: 3.14

    // Check if a QVariant can be converted to a specific type
    if (v1.canConvert<int>()) {
        qInfo() << "v1 is an int:" << v1.toInt();
    } else {
        qInfo() << "v1 is not an int.";
    }

    if (v2.canConvert<QString>()) {
        qInfo() << "v2 is a QString:" << v2.toString();
    } else {
        qInfo() << "v2 is not a QString.";
    }

    // Attempt to convert a QVariant to an incompatible type
    if (v3.canConvert<QString>()) {
        qInfo() << "v3 as QString:" << v3.toString();
    } else {
        qInfo() << "v3 cannot be converted to QString.";
    }

    return 0;
}
```

#### Output of Using `QVariant`

```txt
v1: 42
v2: "Hello, World!"
v3: 3.14
v1 is an int: 42
v2 is a QString: "Hello, World!"
v3 cannot be converted to QString.
```

#### Explanation of the Example

1. **Storing Values**:
   - **`QVariant`** can store values of different types, such as **`int`**, **`QString`**, and **`double`**.

2. **Retrieving Values**:
   - Use methods like **`toInt()`**, **`toString()`**, and **`toDouble()`** to retrieve the stored value.

3. **Type Checking**:
   - Use **`canConvert<T>()`** to check if the **`QVariant`** can be converted to a specific type.

4. **Handling Incompatible Types**:
   - If a **`QVariant`** cannot be converted to the requested type, the conversion methods return a default value (e.g., **`0`** for **`toInt()`** or an empty string for **`toString()`**).

## 6. QStringList

The **`QStringList`** class in Qt is a specialized container for storing and manipulating lists of strings **`QString`**. It is part of the **`QtCore`** module and provides a rich set of methods for working with string collections. **`QStringList`** is essentially a subclass of **`QList<QString>`**, optimized for string operations.

## Key Features of `QStringList`

- **String-Specific Operations**: Provides methods for sorting, filtering, joining, and splitting strings.
- **Compatibility**: Inherits all the functionality of `QList<QString>`.
- **Ease of Use**: Simplifies common tasks like splitting a string into a list or joining a list into a single string.

---

## Example: Using `QStringList`

```cpp
#include <QStringList>
#include <QDebug>

int main() {
    // Create a QStringList
    QStringList fruits = {"Apple", "Banana", "Cherry"};

    // Join the list into a single string
    QString joined = fruits.join(", ");
    qInfo() << "Joined String:" << joined; // Output: "Apple, Banana, Cherry"

    // Filter the list
    QStringList filtered = fruits.filter("an");
    qInfo() << "Filtered List:" << filtered; // Output: ("Banana")

    // Sort the list
    fruits.sort();
    qInfo() << "Sorted List:" << fruits; // Output: ("Apple", "Banana", "Cherry")

    return 0;
}
```
