#include <iostream>
#include "WordAnalysis.h"
using namespace std;

int main()
{
    char *s1="00143223",*s2="BE2GIN",*s3="BEGIN: rea :=b+237*cds  ";
    WordAnalysis ws;
    ws.analyzeSentence(s3);
    return 0;
}
