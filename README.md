# Signals & Slots

Signals and slots are a powerful mechanism in Qt for **communication between objects**. They allow objects to interact with each other without needing to know about each other’s existence. This decouples the sender and receiver, making your code more modular and easier to maintain.

## Key Concepts of Signals & Slots

### 1. Signals

- Signals are **declarations** of events or actions that an object can emit.
- They don’t have an implementation; Qt automatically generates the necessary code for them.
- To emit a signal, use the **`emit`** keyword.

    ```cpp
    signals:
        void mySignal(int value); // Signal declaration
    ```

- Example of emitting a signal:

    ```cpp
    emit mySignal(42); // Emit the signal with a value
    ```

### 2. Slots

- Slots are **normal functions** that can be connected to signals.
- They have an implementation and are called when the connected signal is emitted.
- Slots can have the same name as the signal, but they must match the signal’s **parameters**.

    ```cpp
    private slots:
        void mySlot(int value) { // Slot implementation
            qDebug() << "Received value:" << value;
        }
    ```

### 3. Connecting Signals and Slots

- Use the **connect()** function to link a signal from one object to a slot in another object.

- Syntax:

    ```cpp
    connect(sender, &SenderClass::signal, receiver, &ReceiverClass::slot);
    ```

- Example:

    ```cpp
    connect(senderObject, &Sender::mySignal, receiverObject, &Receiver::mySlot);
    ```

### Example of Connecting Signals & Slots

#### Sender Class

The sender class emits a signal when an action occurs.

```cpp
#include <QObject>

class Sender : public QObject {
    Q_OBJECT

public:
    void doSomething() {
        emit mySignal(42); // Emit the signal
    }

signals:
    void mySignal(int value); // Signal declaration
};
```

- **`mySignal(int value)`:** This is the signal declaration. It takes an integer parameter **`value`**.

- **`doSomething()`:** This function triggers the signal by calling **`emit mySignal(42)`**.

#### Receiver Class

The receiver class has a slot that responds to the signal.

```cpp
#include <QObject>
#include <QDebug>

class Receiver : public QObject {
    Q_OBJECT

public slots:
    void mySlot(int value) { // Slot implementation
        qDebug() << "Received value:" << value;
    }
};
```

- **`mySlot(int value)`:** This is the slot implementation. It takes an integer parameter **`value`** and prints it to the console using **`qDebug()`**.

#### Connecting and Using the Classes

```cpp
int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Sender sender;
    Receiver receiver;

    // Connect the signal to the slot
    QObject::connect(&sender, &Sender::mySignal, &receiver, &Receiver::mySlot);

    // Trigger the signal
    sender.doSomething(); // This will call receiver.mySlot(42)

    return app.exec();
}
```

- **`QObject::connect()`:** This function connects the **`mySignal`** signal from the **`sender`** object to the **`mySlot`** slot in the **`receiver`** object.
- **`sender.doSomething()`:** This triggers the signal, which in turn calls the connected slot.

#### Output of Connecting Signals & Slots

```txt
Received value: 42
```

#### Explanation of Connecting Signals & Slots

1. **Signal Emission:**

    - The **`doSomething()`** function in the **`Sender`** class emits the **`mySignal`** signal with a value of **`42`**.

2. **Slot Execution:**

    - The **`mySlot`** slot in the **`Receiver`** class is connected to the **`mySignal`** signal.

    - When the signal is emitted, the slot is automatically called with the value **`42`**.

3. **Output:**

    - The **`mySlot`** slot prints the received value **`42`** to the console using **`qDebug()`**.

### 4. Disconnecting Connections

In Qt, signals and slots are automatically managed to ensure safe and efficient communication between objects. However, there are cases where you might need to **manually disconnect** a signal-slot connection. Let’s explore how and why.

#### Automatic Disconnection

When the **sender** or **receiver** object is destroyed, Qt automatically disconnects the signal-slot connection. This prevents crashes or undefined behavior that could occur if a signal is emitted but the receiver no longer exists.

```cpp
Sender *sender = new Sender();
Receiver *receiver = new Receiver();

QObject::connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot);

delete receiver; // The connection is automatically disconnected
```

- When **`receiver`** is deleted, the connection between **`sender`** and **`receiver`** is automatically removed.
- If **`sender`** emits a signal after **`receiver`** is deleted, nothing happens because the connection no longer exists.

#### Manual Disconnection

In some cases, you might want to **manually disconnect** a signal-slot connection before the sender or receiver is destroyed. This can be useful in scenarios like:

1. **Dynamic Behavior:**
    - You want to temporarily disable communication between objects without destroying them.
2. **Performance Optimization:**
    - You want to avoid unnecessary signal emissions to slots that are no longer needed.

##### How to Disconnect

Use the **`disconnect()`** function to manually remove a connection. The syntax is similar to **`connect()`**:

```cpp
QObject::disconnect(sender, &Sender::mySignal, receiver, &Receiver::mySlot);
```

```cpp
Sender sender;
Receiver receiver;

// Connect the signal to the slot
QObject::connect(&sender, &Sender::mySignal, &receiver, &Receiver::mySlot);

// Disconnect the signal from the slot
QObject::disconnect(&sender, &Sender::mySignal, &receiver, &Receiver::mySlot);
```

After calling **`disconnect()`**, the mySignal signal will no longer trigger the mySlot slot.

<!-- ## Connection Types

When connecting signals and slots in Qt, you can specify the type of connection to use. The connection type determines how the signal is delivered to the slot and how the objects are connected. There are three main types of connections

**Syntax:**

```cpp
connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot, connectionType);
```

### 1. Direct Connection

- **Default connection type** in Qt.
- The slot is called immediately when the signal is emitted.
- The slot is executed in the **emitter’s thread**.
- This is the fastest connection type but can lead to issues if the slot takes a long time to execute

    ```cpp
    connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot, Qt::DirectConnection);
    ```

### 2. Queued Connection

- The slot is called **asynchronously** when the event loop processes the signal.
- The slot is executed in the **receiver’s thread**.
- This connection type is useful for **cross-thread communication**.

    ```cpp
    connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot, Qt::QueuedConnection);
    ```

### 3. Auto Connection

- The connection type is determined automatically based on the **thread affinity** of the sender and receiver.
- If the sender and receiver are in the same thread, a **direct connection** is used.
- If they are in different threads, a **queued connection** is used.

    ```cpp
    connect(sender, &Sender::mySignal, receiver, &Receiver::mySlot, Qt::AutoConnection);
    ```

### Choosing the Right Connection Type

- **Direct Connection:**
    - Use for **fast and synchronous** communication.
    - Be cautious with long-running slots to avoid blocking the emitter.

- **Queued Connection:**

    - Use for **asynchronous** communication between threads.
    - Ensure the receiver’s event loop is running to process the signal.

- **Auto Connection:**

    - Let Qt decide the best connection type based on the **thread affinity** of the objects.
    - Useful for **simplified** signal-slot connections. -->

Signals and slots are a powerful mechanism in Qt that enable seamless communication between objects. They allow objects to interact without being tightly coupled, making your code more modular and easier to maintain.

One great example of this is **QTimer**, a class that emits a signal at regular intervals. By connecting this signal to a slot, you can perform periodic tasks, such as updating the UI or checking for new data.

### QTimer Example

**`QTimer`** is a Qt class that triggers a signal **`timeout()`** at specified intervals. You can connect this signal to a slot to execute code periodically. Additionally, you can start and stop the timer as needed.

#### How to Use QTimer with Signals and Slots

1. **Create a QTimer Object**
2. **Set the Interval**
    - Use setInterval(milliseconds) to specify how often the timer should trigger.
3. **Connect the `timeout()` Signal to a Slot**
    - Connect the **`timeout()`** signal to a custom slot that contains the code you want to execute periodically.
4. **Start and Stop the Timer**
    - Use **`start()`** to begin the timer and **`stop()`** to halt it.

```cpp
#include <QTimer>
#include <QDebug>

class TimerExample : public QObject {
    Q_OBJECT

public:
    TimerExample() {
        // Create a QTimer object
        timer = new QTimer(this);

        // Set the interval to 1000 milliseconds (1 second)
        timer->setInterval(1000);

        // Connect the timeout() signal to a slot
        connect(timer, &QTimer::timeout, this, &TimerExample::onTimeout);

        // Start the timer
        timer->start();

        // Stop the timer after 5 seconds
        QTimer::singleShot(5000, this, &TimerExample::stopTimer);
    }

private slots:
    void onTimeout() { // Slot to handle the timeout signal
        qDebug() << "Timer triggered!";
    }

    void stopTimer() { // Slot to stop the timer
        qDebug() << "Stopping timer...";
        timer->stop();
    }

private:
    QTimer *timer; // Pointer to the QTimer object
};
```

```cpp
#include <QCoreApplication>
#include "timerexample.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    TimerExample example; // Create an instance of TimerExample

    return app.exec();
}
```

#### Output of QTimer Example

```txt
Timer triggered!
Timer triggered!
Timer triggered!
Timer triggered!
Timer triggered!
Stopping timer...
```

##### Explanation of QTimer Example

1. **QTimer Setup:**
    - A **`QTimer`** object is created and configured to trigger every **1000 milliseconds (1 second)**.
2. **Signal-Slot Connection:**
    - The **`timeout()`** signal is connected to the **`onTimeout()`** slot.
3. **Slot Implementation:**
    - The **`onTimeout()`** slot contains the code to execute when the timer triggers. In this case, it prints a message to the console.
4. **Start the Timer:**
    - The timer is started with **`timer->start()`**.
5. **Stop the Timer:**
    - After 5 seconds, the **`stopTimer()`** slot is called using **`QTimer::singleShot()`**. This stops the timer by calling **`timer->stop()`**.