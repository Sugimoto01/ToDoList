#include <iostream>
#include <fstream>
#include <string>




class Task {

    std::string Name;
    std::string DateBeg;
    std::string DateEnd;
    std::string Description;
    bool isDone = false;


public:Task() {
    
}



public: void AddTask() {
    std::ofstream MyFile("Tasks.txt");
    std::string userInput;


    if (MyFile.is_open()) {
        MyFile << userInput << std::endl;
        MyFile.close();
    }
    else std::cerr << "Error opening file!" << std::endl;


    MyFile.close();
    }

public:void DelTask() {

}
public:void SetTaskDone() {
    isDone = true;
}

public:void ShowTasks() {

    std::ifstream MyFile("Tasks.txt");

    if (MyFile.is_open()) {
        std::string line;
        while (std::getline(MyFile, line)) {
            std::cout << line << std::endl;
        }
    }
    else std::cerr << "Error opening file!" << std::endl;

    MyFile.close();
}
};


void ShowMenu() {
        std::cout << "1.Dodaj Zadanie"<<std::endl;
        std::cout << "2.Usuń Zadanie" << std::endl;
        std::cout << "3.Zobacz swoje zadania Zadanie" << std::endl;
        std::cout << "4.Oznacz zadanie jako wykonane" << std::endl;
        std::cout << "5.Wyjdź\n";
}


int main()
{

    
    Task myTask;
    ShowMenu();

   



   
    return 0;
}


/*
Napisz rozbudowaną aplikację do zarządzania listą zadań (To-Do List). Aplikacja powinna umożliwiać użytkownikowi dodawanie,
usuwanie i oznaczanie zadań jako ukończone. Wykorzystaj klasy i struktury do reprezentowania zadań 
oraz zastosuj operacje na plikach do zapisywania i wczytywania listy zadań.
*/


/*
Uzytkownik włącza program i wybiera co chcę zrobić ze swoją listą

Na początku program musi sprawdzić czy plik z listą isnieje jeżeli tak to go wczytać 
a gdy nie ma takiego pliku to go stworzyć


funkcja dodaj zadanie będzie dodawać tekst do pliku

funkcja usuń zadanie będzie musiała usunąć całą linie bo na każde zadanie przysługuje 1 linia

funkcja zobacz zadanie wyświetli zawartość pliku

funkcja oznacz zadanie jako wykonane doda na końcu tekstu w lini ptazska



*/