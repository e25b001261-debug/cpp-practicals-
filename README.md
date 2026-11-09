# C++ Practical Manual — Fatemeh sahranvard

12 C++17 practical programs covering fundamentals, classes, constructors, smart pointers, inheritance, polymorphism, overloading, design patterns, templates, exceptions, file I/O, and a Library Management mini project.

## Compile and run
Use a C++17 compiler (for example, g++). From this folder:

```bash
g++ -std=c++17 -Wall -Wextra practical01.cpp -o practical01
./practical01
```

Repeat with `practical02.cpp` through `practical12.cpp` and the matching executable name. Practical 01 asks for a radius; enter `5` to reproduce the sample output. Practical 11 creates `students.csv`; Practical 12 creates `books.txt`.

## GitHub submission
Create an empty GitHub repository named `cpp-practicals`, then run from this folder:

```bash
git init
git add .
git commit -m "Add C++ practical programs and mini project"
git branch -M main
git remote add origin YOUR_REPOSITORY_URL
git push -u origin main
```

Replace `YOUR_REPOSITORY_URL` with the repository URL supplied by GitHub. A real repository URL, commit history, and GitHub screenshots can only be supplied after the student signs in and pushes the files.

## Mini project
`practical12.cpp` is a console-based Library Management System. It adds and lists books, issues and returns books, handles invalid operations with exceptions, and saves/reloads records in `books.txt`.
