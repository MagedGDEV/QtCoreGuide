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

