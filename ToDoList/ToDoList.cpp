#include <iostream>


class Task {

    std::string Name;
    std::string DateBeg;
    std::string DateEnd;
    std::string Description;
    bool isDone = false;


public:Task() {

}



public: void AddTask() {

    }

public:void DelTask() {

}
public:void SetTaskDone() {
    isDone = true;
}

public:void ShowTasks() {

}



};

int main()
{
    Task myTask;


    std::cout << "1.Dodaj Zadanie\n";
    std::cout << "2.Usuń Zadanie\n";
    std::cout << "3.Zobacz swoje zadania Zadanie\n";
    std::cout << "4.Oznacz zadanie jako wykonane\n";
    std::cout << "5.Wyjdź\n";
}


/*
Napisz rozbudowaną aplikację do zarządzania listą zadań (To-Do List). Aplikacja powinna umożliwiać użytkownikowi dodawanie,
usuwanie i oznaczanie zadań jako ukończone. Wykorzystaj klasy i struktury do reprezentowania zadań 
oraz zastosuj operacje na plikach do zapisywania i wczytywania listy zadań.
*/