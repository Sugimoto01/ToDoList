#include <iostream> //for input and output stream operations.
#include <fstream> //for file input/output operations.
#include <string> //for string operations.
#include <chrono> //for time-related operations.
#include <vector> //for working with vectors.
#include <limits> //for handling data type limits.
#include <iomanip> //for stream formatting manipulations.
#include <regex> //for regular expression operations.
#include <sstream> //for string stream operations.



const auto TimeStamp = std::chrono::system_clock::now(); // create time stamp of actual time from system

class Task {
private:
    std::string id;
    std::string Name;
    std::string DateBeg;
    std::string DateEnd;
    std::string Description;
    bool isDone;


public:
    Task() : id(generateUniqueId()), Name(""), DateBeg(""), DateEnd(""), Description(""), isDone(false) {}
         //Generates a unique identifier for the task based on the current date and time.



public:std::string readValidatedDate() { //Reads and validates a date input by the user, ensuring it's in the correct format.
        std::string date;
        do {
            std::getline(std::cin, date);
            if (checkDate(date)) {
                break; // Data jest poprawna, wychodzimy z pętli
            }
            else {
                std::cout << "Date is in invalid format please use DD-MM-YYYY format"<<std::endl;
            }
        } while (true);
        return date;
    }

public: std::string generateUniqueId() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::stringstream ss;
    std::tm tm_buf;
    localtime_s(&tm_buf, &now_c); // Użyj localtime_s zamiast localtime
    ss << std::put_time(&tm_buf, "%Y%m%d%H%M%S") << std::setfill('0') << std::setw(3) << now_ms.count();
    return ss.str();
}




public: bool checkDate(const std::string& data) {
    std::regex example("^\\d{2}-\\d{2}-\\d{4}$");
    return std::regex_match(data, example);
}
public: void AddTask() {
    std::ofstream MyFile("Tasks.txt", std::ios::app);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter task name : ";
    std::getline(std::cin, Name);
    if (!Name.empty())
    {
       
    }
    else  std::cout << "Task name is invalid. Please try again. " << std::endl;

    std::cout << "Enter begin date (DD-MM-YYYY): ";
    DateBeg = readValidatedDate();
   
    if (checkDate(DateEnd)) {

    }
    else std::cout << "Data is in wrong format please use DD-MM-YYYY format."<<std::endl;
    std::cout << "Enter your tasks description: ";
    std::getline(std::cin, Description);
    if (!Name.empty())
    {

    }
    else  std::cout << "Description can't be empty" << std::endl;


    if (MyFile.is_open()) {
        MyFile << Name <<" " << DateBeg << " " << DateEnd<<" " << Description << " " << std::chrono::duration_cast<std::chrono::seconds>(TimeStamp.time_since_epoch()).count() << std::endl;
        MyFile.close();
    }
    else std::cerr << "Error opening file!" << std::endl;


    MyFile.close();
    }

      void DelTask() {
          std::ifstream inputFile("Tasks.txt");
          std::ofstream tempFile("Tasks_temp.txt", std::ios::app);
          std::string idToDelete;
          std::cout << "Enter Id of the task: ";
          std::cin >> idToDelete;
          std::string line;

          if (inputFile.is_open() && tempFile.is_open()) {
              while (getline(inputFile, line)) {
                  // Sprawdzanie, czy linia zawiera ID zadania do usunięcia
                  if (line.find(idToDelete) == std::string::npos) {
                      // Jeśli linia nie zawiera ID, kopiujemy ją do pliku tymczasowego
                      tempFile << line << std::endl;
                  }
              }
              inputFile.close();
              tempFile.close();

              // Usuwanie oryginalnego pliku i zmiana nazwy pliku tymczasowego
              std::remove("Tasks.txt");
              std::rename("Tasks_temp.txt", "Tasks.txt");
          }
          else {
              std::cerr << "Can't open file." << std::endl;
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
            // ID is on firs line
            std::istringstream iss(line);
            std::string id, restOfLine;
            if (std::getline(iss, id, ' ')) { // use space a separator
                std::getline(iss, restOfLine); // rest of the line
                std::cout << "ID: " << id << " | " << restOfLine << std::endl;
            }
        }
    }
    else std::cerr << "Error opening file!" << std::endl;
    MyFile.close();
}

};


void ShowMenu() {
        std::cout << "1.Add Task"<<std::endl;
        std::cout << "2.Delete Task" << std::endl;
        std::cout << "3.Show your tasks" << std::endl;
        std::cout << "4.Mark task as completed" << std::endl;
        std::cout << "5.Exit"<<std::endl;
}


int main()
{
    int choose;
    while (true) {
        Task myTask;
        ShowMenu();

        std::cout << "Co chcesz zrobić:";
        if (std::cin >> choose) {
              
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
        else {
            std::cout << "Nieprawidłowe dane spróbuj jeszcze raz";
            ShowMenu();
        }


     

    }
   
    return 0;
}

/*
* EN
* 
* This C++ program is designed to manage tasks within a simple task management system. It offers functionalities for adding, deleting, showing tasks, and marking tasks as completed. The program employs file I/O for persistent storage and management of tasks. Here's a technical description of its components and functionalities:
Header Files

The program includes several header files essential for its functionalities:

  
    f
File Handling

The program uses files to store task data. Standard std::ifstream and std::ofstream streams are used for file operations. 
Tasks are saved in the "Tasks.txt" file in a format that allows easy reading and modification.
Data Validation

The program uses regular expressions to validate the format of dates entered by the user, ensuring they are in the DD-MM-YYYY format. 
Additionally, it checks for other data validity conditions like the non-emptiness of the task name and description.
Error Handling

The program includes simple error handling mechanisms, 
such as informing the user about a failed file opening or input in an incorrect format.
* 
* 
* 
* 
* 
*  PL  
    Ten program w języku C++ służy do zarządzania zadaniami w prostym systemie zarządzania zadaniami. 
    Program zapewnia funkcjonalności takie jak dodawanie, usuwanie, wyświetlanie zadań oraz oznaczanie zadań jako zakończone. Używa operacji na plikach do trwałego przechowywania i zarządzania zadaniami. Oto techniczny opis jego składników i funkcjonalności:
Pliki nagłówkowe

Program zawiera kilka plików nagłówkowych niezbędnych do realizacji funkcjonalności:

   
Główne składniki
Klasa Task

Reprezentuje pojedyncze zadanie z atrybutami takimi jak identyfikator, nazwa, data rozpoczęcia, 
data zakończenia, opis i flaga oznaczająca, czy zadanie zostało zakończone.

    Metody:
        Task(): Konstruktor domyślny, który inicjalizuje zadanie z unikalnym identyfikatorem i pustymi wartościami pozostałych atrybutów.
        generateUniqueId(): Generuje unikalny identyfikator dla zadania na podstawie bieżącej daty i czasu.
        readValidatedDate(): Wczytuje i waliduje datę wprowadzoną przez użytkownika, upewniając się, że jest ona w odpowiednim formacie.
        checkDate(): Sprawdza, czy podana data jest w prawidłowym formacie DD-MM-YYYY przy użyciu wyrażeń regularnych.
        AddTask(): Pozwala użytkownikowi dodać nowe zadanie, wczytując jego szczegóły i zapisując do pliku.
        DelTask(): Usuwa zadanie o podanym identyfikatorze, modyfikując plik z zadaniami.
        SetTaskDone(): Oznacza zadanie jako zakończone.
        ShowTasks(): Wyświetla listę wszystkich zadań.

Funkcje pomocnicze

    ShowMenu(): Wyświetla menu opcji programu.
    main(): Główna funkcja programu, obsługuje pętlę menu i wybór opcji przez użytkownika.

Obsługa plików

Program używa plików do przechowywania danych o zadaniach. 
Do operacji na plikach używane są standardowe strumienie std::ifstream i std::ofstream. 
Zadania są zapisywane do pliku "Tasks.txt" w formacie, który umożliwia ich łatwe wczytanie i modyfikację.

Walidacja danych

Program wykorzystuje wyrażenia regularne do walidacji formatu dat wprowadzanych przez użytkownika, 
zapewniając, że są one w formacie DD-MM-YYYY. Dodatkowo, sprawdzane są inne warunki poprawności danych, 
jak niepustość nazwy zadania i opisu.
Obsługa błędów

Program zawiera proste mechanizmy obsługi błędów, 
takie jak informowanie użytkownika o nieudanym otwarciu pliku czy wprowadzeniu danych w nieprawidłowym formacie.






*/
