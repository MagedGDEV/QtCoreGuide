# Introduction

**Qt** is a powerful, cross-platform framework written in **C++** that allows developers to create anything from basic applications to high-performance, multi-threaded software.

What makes Qt unique is its **singular codebase**, which can run on a wide range of platforms, including:

- **Desktop:** Windows, macOS, Linux
- **Mobile:** Android, iOS
- **Embedded Devices:** Smart home systems, industrial controllers
- **Dashboards:** Automotive interfaces, kiosks

## Why Qt?

- **Write Once, Run Anywhere:** A single codebase supports multiple platforms with minimal modifications.
- **Versatile Applications:** From simple command-line tools to complex GUI-based software, Qt offers the tools you need.
- **Core Strength:** Qt excels in **multi-threading**, **networking**, **data handling**, and **file manipulation** with its robust libraries.
- **Scalability:** Designed to handle both lightweight tasks and resource-intensive applications.

## What You'll Learn in This Guide

In this guide, we’ll explore the **Qt Core module**, which forms the backbone of Qt development. Instead of starting with GUI-based apps, we’ll focus on **console applications**, where you’ll discover the fundamental building blocks of Qt.

## C++ Qt Build Process

When building a Qt application, the process is slightly different from standard C++ projects because Qt introduces additional tools to extend the language's capabilities. Here's an overview of the key steps in the Qt build process:

### 1. Preprocessor

The standard C++ preprocessor handles macros, header inclusions, and conditional compilation. This ensures the source code is ready for the next steps in the build process.

### 2. Qt Meta-Object Compiler (MOC)

This is where **Qt shines**. The **Meta-Object Compiler (MOC)** is a tool unique to Qt that enables advanced features like:

- **Signals and Slots:** Qt's powerful mechanism for event handling.
- **Dynamic Object Properties:** Adding properties at runtime.
- **Reflection:** Querying object types and properties during runtime.

**How MOC Works:**

- The MOC scans your source files for **Qt-specific macros**.
- It generates **additional C++** code behind the scenes. This code provides the functionality you need without requiring changes to the core C++ language.
- The generated code is then compiled alongside your source files, enabling features like event handling and runtime introspection.

Think of MOC as the engine that extends C++'s capabilities to support **Qt’s declarative and dynamic programming model**. Without it, features like signals and slots wouldn’t be possible.

### 3. Compiler

Once the preprocessor and MOC have done their work, the standard **C++ compiler** compiles the source files and the MOC-generated files. This step translates the code into machine language.

### 4. Linker

The compiled object files are linked together, along with the required Qt libraries (e.g., QtCore, QtGui). This step resolves dependencies and creates a complete binary.

### 5. Finished Binary

The final executable includes your application logic along with Qt's runtime functionality, ready to run on your target platform.
