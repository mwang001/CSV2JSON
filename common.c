#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int lineCount(char *csv_file) 
{
	FILE *instream = fopen(csv_file, "r");
  	if (instream == NULL) {
    		return -1;
  	}

	// read the file, line by line
  	char tempBuffer[1024];
  	int lc = 0;
  	int size;
 	
  	while (fgets(tempBuffer, 1024, instream) != NULL) {
  		lc++;
  	}
  	
  	fclose(instream);
  	
  	return lc;  
}

int wordCount(char *csv_file)
{
	FILE *instream = fopen(csv_file, "r");
  	if (instream == NULL) {
    		return -1;
  	}

	// read the file, line by line
  	char tempBuffer[1024];
	char *pch;
  	int wc = 0;
 	
  	while (fgets(tempBuffer, 1024, instream) != NULL) {
  		
			pch = strtok (tempBuffer," ");

			while (pch != NULL)
			{	
				pch = strtok (NULL, " ");
				wc++;
			}
  	}
  	
  	fclose(instream);
  	
  	return wc;
}

int readTextFile(char *txt, char **txtbuf, long &size)
{
	FILE *pFile;
  	long lSize;
  	char *buffer;
  	size_t result;

  	pFile = fopen(txt, "rb" );
  	if (pFile == NULL) {
		fputs ("File error",stderr); 
		return 1;
	}

  	// obtain file size:
  	fseek(pFile, 0, SEEK_END);
 	lSize = ftell(pFile);
  	rewind(pFile);

  	// allocate memory to contain the whole file:
  	buffer = (char*) malloc(sizeof(char)*lSize);
  	if (buffer == NULL) {
		fputs ("Memory error",stderr); 
		return 2;
	}

 	// copy the file into the buffer:
  	result = fread(buffer,1,lSize,pFile);
  	if (result != lSize) {
		fputs ("Reading error",stderr); 
		return 3;
	}

  	// the whole file is now loaded in the memory buffer.

	// terminate
  	fclose(pFile);

	// return file buffer and file size
	size = lSize;
	*txtbuf = buffer;

  	return 0;
}