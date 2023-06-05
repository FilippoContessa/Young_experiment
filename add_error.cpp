#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void AddColumnToDataFile(const std::string& inputFileName, const std::string& outputFileName, const std::string& col3Value) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string col1, col2;
        if (!(iss >> col1 >> col2)) {
            break;
        }
        std::string newLine = col1 + "\t" + col2 + "\t" + col3Value + "\n";
        outputFile << newLine;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFileName = "Data5_100x.txt";      // Nome del file di input
    std::string outputFileName = "Data5_100xR.txt";    // Nome del file di output
    std::string col3Value = "0.003";        // Valore da aggiungere nella terza colonna

    AddColumnToDataFile(inputFileName, outputFileName, col3Value);

    return 0;
}
