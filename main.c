
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

#include "common.h"

void txt2upper();

int main(int argc, char **argv) {

    /*
    if (argc != 2) {
        printf("Missing input csv file\n");
        exit(0);
    }

    char *csv = argv[1];
    */

   char *csv = "sample1.txt";

    // get line count
    printf("%s\n", csv);   

    // line count
    int lc = lineCount(csv);
    printf("    line count: %d\n", lc);

    // word count
    int wc = wordCount(csv);
    printf("    word count: %d\n", wc);    

    // load file to a buffer
    char *txtbuf;
    long size;
    int ret;
    int i;

    ret = readTextFile(csv, &txtbuf, size);
        
    // failed to load file
    if (ret) {
        exit(1);
    }

    // print file
    printf("    file size: %ld\n", size);   
    printf("    Text:\n%s\n", txtbuf);

    // assignment 1: convert the text file to all upper case and print it out
        // initializing the file pointer
    txt2upper(); 
  
    // assignment 2: conver the text file to all lower case and print it out
    FILE* f;
  
    // name of the file as sample.txt
    char fileLower[500] = { "sample1.txt" };
    char ch1;
  
    // opening the file in read mode
        
    // f = fopen(fileLower, "r");
    // ch1 = fgetc(f);
  
    // // converting into upper case
    // while (ch1 != EOF) {
  
    //     // converting char to upper case
    //     ch1 = tolower(ch1);
    //     printf("%c", ch1);
    //     ch1 = fgetc(f);
    // }

    // closing the file
    // fclose(f);
  
    printf("------------------------------------\n");

    for (i = 0; i < size; i++) {
       if ((txtbuf[i] >= 'A') && (txtbuf[i] <= 'Z')) {
            txtbuf[i] = txtbuf[i] + 32;
       }
    }

    for (int i=0; i < size; i++) {
        printf("%c", txtbuf[i]);
    }

    // assignment 3: find if the text file include the word 'the'
    char *ch2;

    if(ch2 = strstr(txtbuf, "the")){
        printf("true\n");
    }
    
    // assignment 4: find how many the word 'the' included in the file
    char *pch = txtbuf;
    char *ptr = txtbuf;
    int count = 0;

    while (ptr && (ptr < (pch+size))) {
        ptr = strstr(ptr, "the");

        if (ptr) {
            count++;
            ptr = ptr + strlen("the");
        } 
    }
    
    printf("Number of occurance of 'the' = %d \n", count);
    
    
    // assignment 5: replace thew word 'the' using 'THE"
    ptr = pch;

    while (ptr && (ptr < (pch+size))) {
        ptr = strstr(ptr, "the");

        if (ptr) {
            strncpy(ptr, "THE", 3);
            // strcpy(ptr, "THE");
            ptr = ptr + strlen("the");
        } 
    }

    for (int i=0; i < size; i++) {
        printf("%c", txtbuf[i]);
    }

    printf("String length = %d\n", strlen("the"));


    // release allocate memory
    if (txtbuf) free(txtbuf);
}


void txt2upper()
{
    FILE* fptr;
  
    // name of the file as sample.txt
    char file[500] = { "sample1.txt" };
    char ch;
  
    // opening the file in read mode
    fptr = fopen(file, "r");
    ch = fgetc(fptr);
  
    // converting into upper case
    while (ch != EOF) {
  
        // converting char to upper case
        ch = toupper(ch);
        printf("%c", ch);
        ch = fgetc(fptr);
    }
  
    // closing the file
    fclose(fptr);    
}

