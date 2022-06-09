#include "functions.h"
#include "menu.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

std::string alphabet = "ABVGDEJZIyKLMNOPRSTYFXC4HmhuieUa";

void FillingIndexArray(
        string word, int WORDSIZE, int NUMBERLETTERS, int* IndexWord)
{
    for (int i = 0; i < WORDSIZE; ++i)
        for (int j = 0; j < NUMBERLETTERS; ++j)
            if (word[i] == alphabet[j])
                IndexWord[i] = j;
}
int CheckLetter(string word, int WORDSIZE, int a)
{
    for (int i = 0; i < WORDSIZE; ++i) {
        if (alphabet[a] == word[i])
            return 1;
    }
    return 0;
}
int SumMistakes(bool* Markers, string word, int NUMBERLETTERS, int WORDSIZE)
{
    int s = -1;
    for (int i = 0; i < NUMBERLETTERS; ++i) {
        if (!CheckLetter(word, WORDSIZE, i))
            s += Markers[i];
    }
    return s;
}
int ManYouRight(bool* Markers, string word, int NUMBERLETTERS, int WORDSIZE)
{
    int s = 0;
    for (int i = 0; i < NUMBERLETTERS; ++i) {
        if (CheckLetter(word, WORDSIZE, i))
            s += Markers[i];
    }
    return s;
}
void Theme_Word(string& tema, string& word)
{
    srand(time(NULL));
    string path[5]
            = {"Words/ARXITEKTYRA.txt",
               "Words/JIVOTNuE.txt",
               "Words/EDA.txt",
               "Words/RASTENIa.txt",
               "Words/TRANSPORT.txt"};
    int k;
    k = rand() % 5;
    switch (k) {
    case 0:
        tema = "ARXITEKTYRA";
        break;
    case 1:
        tema = "JIVOTNuE";
        break;
    case 2:
        tema = "EDA";
        break;
    case 3:
        tema = "RASTENIa";
        break;
    case 4:
        tema = "TRANSPORT";
        break;
    }

    ifstream fin;
    fin.open(path[k]);
    if (!fin.is_open()) {
        cout << "ERROR OPEN FILE!" << endl;
    } else {
        cout << "File is open" << endl;
    }

    string str[11];
    k = rand() % 11;
    int i = 0;
    while (!fin.eof()) {
        fin >> str[i];
        i++;
    }
    fin.close();
    word = str[k];
}
int non_repeating_characters(int WORDSIZE, string word)
{
    int non_repeating = 0;
    string outw; // Слово-контейнер (в него помещаются все неповторяющиеся
                 // символы)
    bool flag = false; // Флаг повтора
    for (int i = 0; i < WORDSIZE; i++) {
        flag = false;
        for (int j = 0; j < non_repeating; j++) {
            if (word[i] == outw[j]) {
                flag = true;
            }
        }
        if (!flag) // Если не было повтора
        {
            outw += word[i];
            non_repeating = outw.length();
        }
    }
    return non_repeating;
}
