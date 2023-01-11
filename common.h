#ifndef COMMON_H
#define COMMON_H

int lineCount(char *csv_file); 
int wordCount(char *csv_file);

int readTextFile(char *txt, char **txtbuf, long &size);

#endif