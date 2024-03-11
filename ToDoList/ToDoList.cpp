#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <limits>



const auto TimeStamp = std::chrono::system_clock::now(); // create time stamp of actual time from system

class Task {
private:
    std::string id;
    std::string  Name;
    std::string DateBeg;
    std::string DateEnd;
    std::string Description;
    bool isDone;


public:
    Task() : id(""), Name(""), DateBeg(""), DateEnd(""), Description(""), isDone(false) {}



public: void AddTask() {
    std::ofstream MyFile("Tasks.txt", std::ios::app);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Wpisz nazwe zadania : ";
    std::getline(std::cin, Name);
    std::cout << "Wpisz Date rozpoczecia: : ";
    std::getline(std::cin, DateBeg);
    std::cout << "Wpisz Date zakonczenia: : ";
    std::getline(std::cin, DateEnd);
    std::cout << "Dodaj opis zadania: ";
    std::getline(std::cin, Description);


    if (MyFile.is_open()) {
        MyFile << Name <<" " << DateBeg << " " << DateEnd<<" " << Description << " " << std::chrono::duration_cast<std::chrono::seconds>(TimeStamp.time_since_epoch()).count() << std::endl;
        MyFile.close();
    }
    else std::cerr << "Error opening file!" << std::endl;


    MyFile.close();
    }

public:void DelTask() {

    std::ifstream Myfile("Tasks.txt");
    std::ofstream outputFile("Modified.txt");

    if (Myfile.is_open() && outputFile.is_open()) {
        std::vector<std::string> linesToDelete = { "Line to delete 1", "Line to delete 2" };

        std::string line;
        while (getline(Myfile, line)) {
          
            if (std::find(linesToDelete.begin(), linesToDelete.end(), line) == linesToDelete.end()) {
            
                outputFile << line << std::endl;
            }
        }

        Myfile.close();
        outputFile.close();

       
        std::remove("Task.txt"); 
        std::rename("modified.txt", "Task.txt"); 
    }
    else {
        std::cerr << "Error opening files!" << std::endl;
    }

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
    int choose;
    while (true) {
        Task myTask;
        ShowMenu();

        std::cout << "Co chcesz zrobić:";
        if (std::cin >> choose) {
            break;
        }
        else {
            std::cout << "To nie jest liczba całkowita. Spróbuj ponownie.\n";
            std::cin.clear(); // Czyścimy błąd strumienia.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorujemy błędne dane do końca linii.
        }
        

        switch (choose)
        {
        case 1: myTask.AddTask(); break;
        case 2: myTask.DelTask(); break;
        case 3: myTask.ShowTasks(); break;
        case 4: myTask.SetTaskDone(); break;
        case 5: return 0; break;
        default:std::cout << "Nieprawidlowy wybor."; return 0;
            break;
        }

    }
   
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




funkcja usuń zadanie będzie musiała usunąć całą linie bo na każde zadanie przysługuje 1 linia

funkcja oznacz zadanie jako wykonane doda na końcu tekstu w lini ptazska




*/