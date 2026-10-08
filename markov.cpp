#include "markov.h"
#include <iostream>
#include <fstream>

using namespace std;

string joinWords(const string words[], int startIndex, int count){

    string result = "";

    for(int i = 0; i < count; i++){
        result += words[startIndex + i]

        if(i != count - 1){
            result += " ";
        }

        return result;
    }

}

int readWordsFromFile(string filename, string words[], int maxWords){

    ifstream inputfile;

    inputFile.open(filename);

    if(!inputFile.is_open()){
        return -1;
    }

    int counter = 0;

    whille (counter < maxWords && inoutFile >> words[counter]){
        counter++;
    }

    inoutFile.close();

    return counter;

}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[],
int maxChainSize){
    if(order < 1 || order > 3 || numWords <= order || maxChainsize <= 0){
        return 0;
    }

    int count = 0;

    for(int i = 0; i < numWords - order && count < maxChainSize; i++){

        string prefix = joinWords(words, i, order);

        string suffix = words[ i + order ];

        prefixes[count] = prefix;

        suffixes[count] =suffix;

        count++;

        }

        return count;

}

string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix){

    int count = 0;

    for (int i = 0; i < chainSize; i++) {
        if (prefixes[i] == currentPrefix) {
            count++
        }
    }

    if (count == 0) {
        return "";
    }

    int choice = rand() % (count + 1 );
    count = 0;

    for (int i = 0; i < chainSize; i++) {
        if (prefixes[i] = currentPrefix) {
            if (count == choice) {
                return suffixes[i];
            }
            count++;
        }
    }

    return "";

}

string getRandomPrefix(const string prefixes[], int chainSize){

}

string generateText(const string prefixes[], const string suffixes[], int chainSize, int order, int numWords){

}