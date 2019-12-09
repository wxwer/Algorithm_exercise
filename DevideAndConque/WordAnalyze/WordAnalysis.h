#ifndef WORDANALYSIS_H_INCLUDED
#define WORDANALYSIS_H_INCLUDED
#include <string.h>

class WordAnalysis{
private:
    char *instr,*token,*wordList[16];
    int i,j,n;
    char ch;
    void getChar();
    void getNBC();
    void cat();
    bool isLetter(char ch);
    bool isDigit(char ch);
    void unGetChar();
    bool isReserve();
    int str2Int(char *s);
    void error();
    bool isEnd();
public:
    WordAnalysis();
    void analyze(char *word);
    void analyzeSentence(char *s);
    ~WordAnalysis();
};

#endif // WORDANALYSIS_H_INCLUDED
