#ifndef LAB4_1_H
#define LAB4_1_H

unsigned int lineLength(const char *line);/**/
int isLetter(const char character);/**/
int isDigit(const char character);/**/
void swapStrings(char **firstLine, char **secondLine);/**/
int compareStrings(const char *firstLine, const char *secondLine);/**/
char charToLower(const char character);/**/
void stringToLower(char *line);/**/
void textToLower(char **text, unsigned int numberOfLines);/**/

int checkNULL(void *ptr);/**/
char **getTwoDimensionalArray(unsigned int linesNumber);
char **freeArray(char **text, unsigned int *linesNumber);
char **expendText(char **text, unsigned int *linesNumber);
char **resizeText(char **text, unsigned int currentLines,
                               unsigned int *totalLines);
char *resizeLine(char *line);

void getText(char ***text, unsigned int *linesNumber);
void getSeparateWords (char **textToRead, unsigned int linesOfText,
                       char ***arrayToWrite, unsigned int *linesOfArray);
void sortAlphabetically(char **words, unsigned int numberOfWords);
int occursWord(char **words, unsigned int numberOfWords, char *wordToLookFor);
void countAmountOfWords(char **words, unsigned int numberOfWords);
void printArray(char **array, unsigned int size);

#endif