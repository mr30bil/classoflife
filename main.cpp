
#include <iostream>
#include "Animal.h"
#include <vector>
#include <string>

using namespace std;

string toLower(string s){
    int len = s.length();
    string result;
    for (int i = 0; i < len; i++){
        char current = s[i];
        if (current >= 65 && current <= 90){
            current += 32;
            result.push_back(current);
        } else {
            result.push_back(current);
        }
    }
    return result;
}

string toUpper(string s){
    int len = s.length();
    string result;
    for (int i = 0; i < len; i++){
        char current = s[i];
        if (current >= 97 && current <= 122){
            current -= 32;
            result.push_back(current);
        } else {
            result.push_back(current);
        }
    }
    return result;
}

void clear(){
    system("CLS");
}

bool isCharNum(char c){
    bool result;
    if (c == '0') result = true;
    else if (c == '1') result = true;
    else if (c == '2') result = true;
    else if (c == '3') result = true;
    else if (c == '4') result = true;
    else if (c == '5') result = true;
    else if (c == '6') result = true;
    else if (c == '7') result = true;
    else if (c == '8') result = true;
    else if (c == '9') result = true;
    else result = false;
    return result;
}

bool isStrNum(string s){
    bool result = true;
    for (int i = 0; i < s.length(); i++){
        if (!isCharNum(s[i])){
            result = false;
            break;
        } 
    }
    return result;
}

// menu system
void displayMenu(vector<string> m, bool hasExit = true){
    cout << endl;
    int len = m.size();
    if (hasExit){
        for (int i = 0; i < len - 1; i++) cout << i + 1 << " : " << m[i] << endl;
        cout << 0 << " : " << m[len - 1] << endl;
    } else for (int i = 0; i < len; i++) cout << " " << i + 1 << " : " << m[i] << endl;
}

void displayCells(vector<cell> cells){
    int len = cells.size();
    cout << endl;
    cout << "You have " << len << " cells: " << endl;
    for (int i = 0; i < len; i++) cout << "Cell (" << i << ") : contains " << cells[i].kromCount() << " kromozoms" << endl;
}

void displayKroms(vector<genome> kroms){
    int len = kroms.size();
    cout << endl;
    cout << "You have " << len << " Kromozoms: " << endl;
    for (int i = 0; i < len; i++) cout << "Kromozom (" << i << ") : " << kroms[i].getRnaOfDna(0) << " / " << kroms[i].getRnaOfDna(1) << endl;
}

void displayAnimals(vector<animal> animal_vector){
    int len = animal_vector.size();
    cout << endl;
    cout << "You have " << len << " Animals: " << endl;
    for (int i = 0; i < len; i++) cout << "Animal (" << i << ") : contains " << animal_vector[i].cellKromCount() << " kromozoms" << endl;
}

bool validKrom(string s){
    int len = s.length();
    bool result = true;
    for (int i = 0; i < len; i++){
        if ((s[i] != 'A') && (s[i] != 'T') && (s[i] != 'G') && (s[i] != 'C')){
            result = false;
            break;
        }
    }
    return result;
}

int main(){

    // menu system
    vector<string> mainMenu = {"Add a Cell", "Add a Kromozm to Cell", "View Cells", "View Kromozoms", "Edit a Kromozom", "Operate on Cells", "Operate on Kromzom", "Add Animal", "Animal Operations" "Exit"};
    vector<string> cellOperations = {"Dead Cell", "Big Mutaion", "Reversed Mutation", "Supplement Palindroms", "Back"};
    vector<string> kromOperations = {"Small Mutation", "Big Mutation", "Reversed Mutation", "Back"};
    vector<string> animalOperations = {"Set Cell", "Similarity", "Equall", "NonSexual Reproduction", "Sexual Reproduction", "Dead Kromozom", "Back"};
    
    // input variable
    string input;

    // storing data
    vector<cell> cells;
    vector<animal> animals;

    // first input
    displayMenu(mainMenu);
    cout << "Welcome to the Cell.cpp. How can I help you? : ";
    cin >> input;

    input = toLower(input);

    bool accept = false;
    while (!accept){
        if (isStrNum(input)) accept = true;
        else {
            displayMenu(mainMenu);
            cout << "Invalid input!, Please try again : ";
            cin >> input;
        }
    }
    accept = false;
    clear();

    while (input != "0"){

        if (input == "1"){
            cell newCell;
            cout << "How many Kromozoms do you want to add? : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input)) accept = true;
                else {
                    cout << "How many Kromozoms do you want to add? ";
                    cout << "Invalid input!, Please try again : ";
                    cin >> input;
                }
            }
            accept = false;
            int count = stoi(input);
            for (int i = 0; i < count; i++){
                cout << "Add the Kromozom number " << i + 1 << " : ";
                cin >> input;
                input = toUpper(input);
                accept = false;
                while (!accept){
                    if (validKrom(input)) accept = true;
                    else {
                        cout << "Add the Kromzom number " << i + 1 << " ";
                        cout << "Invalid input!, Please try again : ";
                        cin >> input;
                        input = toUpper(input);
                    }
                }
                accept = false;
                newCell.addKrom(input);
            }
            cells.push_back(newCell);
            clear();
            cout << "New cell successfully added!" << endl;
        }

        else if (input == "2"){
            displayCells(cells);
            cout << "Which cell you want to add kromozom? : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells.size() - 1) accept = true;
                else {
                    cout << "Invalid Input!, Which cell you want to add kromozom? : ";
                    cin >> input;
                }
            }
            accept = false;
            int index = stoi(input);
            cout << "Enter the kromozom you want to add : ";
            cin >> input;
            input = toUpper(input);
            accept = false;
            while (!accept){
                if (validKrom(input)) accept = true;
                else {
                    cout << "Invalid input!, Enter the kromozom you want to add : ";
                    cin >> input;
                }
            }
            accept = false;
            cells[index].addKrom(input);
            clear();
            cout << "New kromozom added successfully!" << endl;
        }

        else if (input == "3") displayCells(cells);

        else if (input == "4"){
            displayCells(cells);
            cout << "Choose the Cell index : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells.size() - 1) accept = true;
                else {
                    cout << "Invalid input!, Choose the Cell index : ";
                    cin >> input;
                }
            }
            accept = false;
            int index = stoi(input);
            clear();
            displayKroms(cells[index].getkroms());
        }

        else if (input == "5"){
            // getting mode
            cout << "Choose the mode (1.Auto : sets the supplement automaticlly / 2.Manuall) : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && (stoi(input) == 1 || stoi(input) == 2)) accept = true;
                else {
                    cout << "Invalid input!, Choose the mode (1.Auto / 2.Manuall) : ";
                    cin >> input;
                }
            }
            accept = false;
            bool autoSet = false;
            if (input == "1") autoSet = true;
            else autoSet = false;
            // getting cell index
            displayCells(cells);
            cout << "Choose the Cell : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells.size()) accept = true;
                else {
                    cout << "Invalid input!, Choose the Cell : ";
                    cin >> input;
                }
            }
            accept = false;
            int index = stoi(input);
            // getting krom index
            displayKroms(cells[index].getkroms());
            cout << "Choose the Kromozom You want to edit : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells[index].kromCount() - 1) accept = true;
                else {
                    cout << "Invalid input!, Choose the Kromozom You want to edit: ";
                    cin >> input;
                }
            }
            accept = false;
            int kromIndex = stoi(input);
            // getting new krom string
            if (autoSet){
                cout << "Enter the new Kromozom : ";
                cin >> input;
                input = toUpper(input);
                accept = false;
                while (!accept){
                    if (validKrom(input)) accept = true;
                    else {
                        cout << "Invalid input!, Enter the new Kromozom : ";
                        cin >> input;
                        input = toUpper(input);
                    }
                }
                accept = false;
                cells[index].editKrom(kromIndex, input);
            } else {
                cout << "Enter the first string for Kromozom : ";
                cin >> input;
                input = toUpper(input);
                accept = false;
                while (!accept){
                    if (validKrom(input)) accept = true;
                    else {
                        cout << "Invalid input!, Enter the first string for Kromozom : ";
                        cin >> input;
                        input = toUpper(input);
                    }
                }
                accept = false;
                string first = input;
                cout << "Enter the second string for Kromozom : ";
                cin >> input;
                input = toUpper(input);
                accept = false;
                while (!accept){
                    if (validKrom(input)) accept = true;
                    else {
                        cout << "Invalid input!, Enter the second string for Kromozom : ";
                        cin >> input;
                        input = toUpper(input);
                    }
                }
                accept = false;
                string second = input;
                cells[index].editKrom(kromIndex, first, second);
            }
            clear();
            cout << "Kromozom editted successfully!" << endl;
        }

        else if (input == "6"){
            displayMenu(cellOperations);
            cout << "Choose the operation : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cellOperations.size()) accept = true;
                else {
                    displayMenu(cellOperations);
                    cout << "Invalid input!, Choose the operation : ";
                    cin >> input;
                } 
            }
            accept = false;
            while (input != "0"){
                if (input == "1"){
                    displayCells(cells);
                    cout << "Choose the Cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Invalid input!, Choose the Cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells[cellIndex].kromCount()) accept = true;
                        else {
                            cout << "Choose the kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    bool result = cells[cellIndex].aliveKrom(kromIndex);
                    if (result){
                        cout << "Cell is Alive!" << endl;
                    } else {
                        cells.erase(cells.begin() + (cellIndex + 1));
                        cout << "Cell is dead and removed!";
                    }
                }
                else if (input == "2"){
                    displayCells(cells);
                    cout << "Choose the cell index you want to operate on : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Invalid input!, Choose the cell index you want to operate on: ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the first Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Invalid input!, Choose the first Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int firstKrom = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the second Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Invalid input!, Choose the first Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int secondKrom = stoi(input);
                    cout << "First Kromozom : " << cells[cellIndex].getKrom(firstKrom).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(firstKrom).getRnaOfDna(1) << endl;
                    cout << "Enter the target string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "First Kromozom : " << cells[cellIndex].getKrom(firstKrom).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(firstKrom).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the target string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string target1 = input;
                    cout << "Second Kromozom : " << cells[cellIndex].getKrom(secondKrom).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(secondKrom).getRnaOfDna(1) << endl;
                    cout << "Enter the target string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Second Kromozom : " << cells[cellIndex].getKrom(secondKrom).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(secondKrom).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the target string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string target2 = input;
                    cells[cellIndex].bigMutationDna(target1, firstKrom, target2, secondKrom);
                    cout << "BigMutation is done!" << endl;
                }
                else if (input == "3"){
                    displayCells(cells);
                    cout << "Choose the cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Choose the cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Invalid input!, Choose the Kromzom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                    cout << "Enter the target string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the target string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string target = input;
                    cells[cellIndex].reversedMutation(target, kromIndex);
                    cout << "ReversedMuatation Done!" << endl;
                }
                else if (input == "4"){
                    displayCells(cells);
                    cout << "Choose the cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Invalid input!, Choose the cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the Kromzom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Invalid input!, Choose the Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    vector<string> results = cells[cellIndex].findSupPalindroms(kromIndex);
                    clear();
                    cout << "The supplement palindroms are : " << endl;
                    for (int i = 0; i < results.size(); i++) cout << results[i] << endl;
                }
            }
        }
        
        else if (input == "7"){
            displayMenu(kromOperations);
            cout << "Choose the Operation : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < kromOperations.size()) accept = true;
                else {
                    displayMenu(kromOperations);
                    cout << "Invalid input!, Choose the Operation : ";
                    cin >> input;
                }
            }
            accept = false;
            while (input != "0"){
                if (input == "1"){
                    displayCells(cells);
                    cout << "Choose the Cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Choose the Cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Choose the Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    cout << "Select the target Nucleotide (A / T / G / C) : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Select the target Nucleotide (A / T / G / C) : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    char target = input[0];
                    cout << "Select the replacment Nucleotide (A / T / G / C) : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Select the replacment Nucleotide (A / T / G / C) : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    char replacment = input[0];
                    cout << "Enter the number of changes : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0) accept = true;
                        else {
                            cout << "Enter the number of changes : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int count = stoi(input);
                    genome currentKrom = cells[cellIndex].getKrom(kromIndex);
                    currentKrom.smallMutationDna(target, replacment, count);
                    cells[cellIndex].editKrom(kromIndex, currentKrom.getRnaOfDna(0), currentKrom.getRnaOfDna(1));
                    cout << "SmallMutation Done!" << endl;
                }
                else if (input == "2"){
                    displayCells(cells);
                    cout << "Choose the Cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Choose the Cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Choose the Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                    cout << "Enter the target string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the target string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string target = input;
                    cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                    cout << "Enter the replacment string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the replacment string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string replacement = input;
                    genome currentKrom = cells[cellIndex].getKrom(kromIndex);
                    currentKrom.bigMutationDna(target, replacement);
                    cells[cellIndex].editKrom(kromIndex, currentKrom.getRnaOfDna(0), currentKrom.getRnaOfDna(1));
                    cout << "BigMutation Done!" << endl;
                }
                else if (input == "3"){
                    displayCells(cells);
                    cout << "Choose the Cell index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Choose the Cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cellIndex = stoi(input);
                    displayKroms(cells[cellIndex].getkroms());
                    cout << "Choose the Kromozom index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells[cellIndex].kromCount()) accept = true;
                        else {
                            displayKroms(cells[cellIndex].getkroms());
                            cout << "Choose the Kromozom index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int kromIndex = stoi(input);
                    cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                    cout << "Enter the target string : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (validKrom(input)) accept = true;
                        else {
                            cout << "Selected Kromozom : " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(0) << " / " << cells[cellIndex].getKrom(kromIndex).getRnaOfDna(1) << endl;
                            cout << "Invalid input!, Enter the target string : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    string target = input;
                    genome currentKrom = cells[cellIndex].getKrom(kromIndex);
                    currentKrom.reversedMutationDna(target);
                    cells[cellIndex].editKrom(kromIndex, currentKrom.getRnaOfDna(0), currentKrom.getRnaOfDna(1));
                    clear();
                    cout << "ReversedMutation Done!";
                }
            }
        } else if (input == "8"){
            animal newAnimal;
            cout << "How many Kromozoms do you want to add? : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input)) accept = true;
                else {
                    cout << "Invalid input!, How many kromozoms do you want to add? : ";
                    cin >> input;
                }
            }
            accept = false;
            int count = stoi(input);
            for (int i = 0; i < count; i++){
                cout << "Enter the Kromozom " << i + 1 << " : ";
                cin >> input;
                accept = false;
                while (!accept){
                    if (validKrom(input)) accept = true;
                    else {
                        cout << "Invalid input!, Enter the Kromozom " << i + 1 << " : ";
                        cin >> input;
                    }
                }
                accept = false;
                genome newKrom;
                newKrom.setRnaForDna(input);
                newAnimal.addKrom(newKrom);
                system("CLS");
                cout << "Kromozom added successfully!" << endl;
            }
            system("CLS");
            animals.push_back(newAnimal);
            cout << "New Animal add successfully!" << endl;
        } else if (input == "9"){ // Animal Operations Menu
            displayMenu(animalOperations);
            cout << "Choose the Operation : ";
            cin >> input;
            accept = false;
            while (!accept){
                if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < animalOperations.size()) accept = true;
                else {
                    displayMenu(animalOperations);
                    cout << "Invalid input!, Choose the Operation : ";
                    cin >> input;
                }
            }
            accept = false;
            while (input != "0"){
                if (input == "1"){
                    displayAnimals(animals);
                    cout << "Choose the Animal index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the Animal index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int aindex = stoi(input);
                    displayCells(cells);
                    cout << "Choose the Cell index : ";
                    cin >> input;
                    accept = false;
                    while(!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < cells.size()) accept = true;
                        else {
                            displayCells(cells);
                            cout << "Invalid input!, Choose the Cell index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int cindex = stoi(input);
                    animals[aindex].setCell(cells[cindex]);
                    system("CLS");
                    cout << "Cell has been set successfully!" << endl;
                } else if (input == "2"){
                    displayAnimals(animals);
                    cout << "Choose the first index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the first index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int findex = stoi(input); // gets the first animal index
                    displayAnimals(animals);
                    cout << "Choose the second index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) < animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the second index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int sindex = stoi(input); // gets the second animal index 
                    system("CLS");
                    cout << "Similarity is : " << animals[findex].similarity(animals[sindex]) << "%" << endl;
                } else if (input == "3"){
                    displayAnimals(animals);
                    cout << "Choose the first index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the first index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int findex = stoi(input);
                    displayAnimals(animals);
                    cout << "Choose the second index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the second index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int sindex = stoi(input);
                    system("CLS");
                    if (animals[findex] == animals[sindex]) cout << "Animals are Equall" << endl;
                    else cout << "Animals are not Equall" << endl;
                } else if (input == "4"){
                    displayAnimals(animals);
                    cout << "Choose the first index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the first index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int index = stoi(input);
                    animal child = animals[index].nonSexualReproduction();
                    animals.push_back(child);
                    system("CLS");
                    cout << "Child has been added to Animals successfully!" << endl;
                } else if (input == "5"){
                    displayAnimals(animals);
                    cout << "Choose the first index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the first index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int findex = stoi(input);
                    displayAnimals(animals);
                    cout << "Choose the second index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the second index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int sindex = stoi(input);
                    animal child = animals[findex] + animals[sindex];
                    system("CLS");
                    if (!child.emptyAnimal()){
                        animals.push_back(child);
                        cout << "Child has been added to Animals successfully!" << endl;
                    } else cout << "Sorry!, Couldn't Make a New Child! :(";
                } else if (input == "6"){
                    displayAnimals(animals);
                    cout << "Choose the first index : ";
                    cin >> input;
                    accept = false;
                    while (!accept){
                        if (isStrNum(input) && stoi(input) >= 0 && stoi(input) <= animals.size()) accept = true;
                        else {
                            displayAnimals(animals);
                            cout << "Invalid input!, Choose the first index : ";
                            cin >> input;
                        }
                    }
                    accept = false;
                    int index = stoi(input);
                    system("CLS");
                    if (animals[index].aliveKrom()) cout << "There were no Dead Kromozom!" << endl;
                    else cout << "All Dead Kromozoms removed!" << endl;
                }

                displayMenu(animalOperations);
                cout << "Choose the Operation : ";
                cin >> input;
            }
        }

        displayMenu(mainMenu);
        cout << "Enter number of the command : ";
        cin >> input;
    }
    
    
    return 0;
}
