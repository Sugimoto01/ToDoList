#include <iostream>
#include <vector>





// Funkcja do wyświetlania macierzy
void printMatrix(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}




std::vector<std::vector<int>> adjacencyToIncidence(std::vector<std::vector<int>> adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    int e = 0;
    // Liczenie krawędzi
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                e++;
            }
        }
    }

    std::vector<std::vector<int>> incidenceMatrix(n, std::vector<int>(e, 0));
    int k = 0;
    // Tworzenie macierzy incydencji
    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            if (adjacencyMatrix[i][j] == 1) {
                incidenceMatrix[i][k] = 1;
                incidenceMatrix[j][k] = -1;
                k++;
            }
        }
    }

    return incidenceMatrix;
}


// Funkcja do wczytywania macierzy od użytkownika
std::vector<std::vector<int>> readMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Funkcja do konwersji macierzy incydencji na macierz sąsiedztwa
std::vector<std::vector<int>> incidenceToAdjacency(std::vector<std::vector<int>> incidenceMatrix) {
    int n = incidenceMatrix.size();
    int e = incidenceMatrix[0].size(); // Liczba krawędzi

    std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));

    for (int i = 0; i < e; i++) {
        int u = -1, v = -1;

        for (int j = 0; j < n; j++) {
            if (incidenceMatrix[j][i] == 1 || incidenceMatrix[j][i] == -1) {
                if (u == -1) {
                    u = j;
                }
                else {
                    v = j;
                    break;  // Znaleziono oba wierzchołki, przerwij pętlę
                }
            }
        }

        if (u != -1 && v != -1) {
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1;
        }
        else if (incidenceMatrix[u][i] == 1) {
            // Obsługa krawędzi pętli
            adjacencyMatrix[u][u] = 1;
        }
    }

    return adjacencyMatrix;
}




int main() {
    int choice;
    std::cout << "Wybierz konwersję:\n1. Sąsiedztwa do incydencji\n2. Incydencji do sąsiedztwa\n";
    std::cin >> choice;

    int n;
    std::cout << "Podaj liczbę wierzchołków:\n";
    std::cin >> n;

    if (choice == 1) {
        std::cout << "Podaj macierz sąsiedztwa:\n";
        std::vector<std::vector<int>> adjacencyMatrix = readMatrix(n);
        std::cout << "\nWprowadzona macierz sąsiedztwa:\n";
        printMatrix(adjacencyMatrix);
        std::vector<std::vector<int>> incidenceMatrix = adjacencyToIncidence(adjacencyMatrix);
        std::cout << "\nMacierz incydencji:\n";
        printMatrix(incidenceMatrix);
    }
    else if (choice == 2) {
        std::cout << "Podaj macierz incydencji:\n";
        std::vector<std::vector<int>> incidenceMatrix = readMatrix(n);
        std::cout << "\nWprowadzona macierz incydencji:\n";
        printMatrix(incidenceMatrix);
        std::vector<std::vector<int>> adjacencyMatrix = incidenceToAdjacency(incidenceMatrix);
        std::cout << "\nMacierz sąsiedztwa:\n";
        printMatrix(adjacencyMatrix);
    }
    else {
        std::cout << "Nieznany wybór.\n";
    }

    return 0;
}
