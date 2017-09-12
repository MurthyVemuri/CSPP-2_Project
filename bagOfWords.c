#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

void getFrequencies(char *);
int word_freq(const char *, struct wordFrequency words[]);
char* strlwr(char*);
void readingFromFile(char*);


int MAXCHAR = 100;

struct wordFrequency {
	char str[100];
	int count;
};


int word_freq(const char *str, struct wordFrequency words[]){
	char punct_str [] =" .,;:!?'\"";
	char *tmp_str;
	char *wptr;
	int i,nword = 0;
	tmp_str = strdup(str);

	wptr = strtok(tmp_str, punct_str);
	while (wptr != NULL) {
		for(i = 0; i < nword; i++) {
			if (strcmp(wptr, words[i].str) == 0)
				break;
		}
		if (i < nword)
			words[i].count++;
		else {
			strcpy(words[nword].str, wptr);
			words[nword].count= 1;
			nword++;
		}
		wptr = strtok(NULL, punct_str);
	}
	return nword;
}

void getFrequencies(char *fileContent){
	struct wordFrequency *words = (struct wordFrequency*)malloc(sizeof(struct wordFrequency) * 100);
	int nword;
	int i;
	nword = word_freq(fileContent, words);
	for(i = 0; i < nword; i++)
		printf("%s: %d\n", words[i].str, words[i] .count);
}


char* strlwr(char* s) {
    char* tmp = s;
    for (;*tmp;++tmp) {
        *tmp = tolower((unsigned char) *tmp);
    }
    return s;
}

void readingFromFile(char* filename) {
    char *fileContent = (char *)malloc(sizeof(char) * 100);
    char *str = (char *)malloc(sizeof(char) * 100);
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Could not open file %s",filename);
	}
	while (fgets(str, MAXCHAR, fp) != NULL) {
		fileContent = strlwr(str);
	}
	printf("------File Content------ \n");
	printf("%s\n",fileContent );
	getFrequencies(fileContent);
	fclose(fp);
}



int main(int argc, char const *argv[]) {
    int len;
    struct dirent *pDirent;
    DIR *pDir;

    if (argc < 2) {
        printf ("Usage: bagOfWords <dirname>\n");
        return 1;
    }
    pDir = opendir (argv[1]);
    printf("%s\n",argv[1] );
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", argv[1]);
        return 1;
    }

    while ((pDirent = readdir(pDir)) != NULL) {
        if (strlen(pDirent->d_name) > 2) {
            //printf ("%s\n", pDirent->d_name);
            readingFromFile(pDirent->d_name);
        }

    }
    closedir(pDir);
    return 0;
}