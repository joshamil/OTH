#include "ParseInput.h"
#include "Commands.h"

void parseInput(char *fileName, char **commands, int **data, int *commandCount, const int MAX_COMMANDS) {
    FILE *file;
	char command[3];
	int adrOrVal;

	int i,j = 0;

	file = fopen(fileName, "r");
	if (!file)
    {
        printf("Cannot open file %s!", fileName);
        return;
    }
    for(i=0; i<MAX_COMMANDS; i++)
    {
        (*commands)[i] = '\0';
        (*data)[i] = -1;
    }

    i=0;
    do
    {
        j = fscanf(file, "%s %d", command, &adrOrVal);
        printf("%s %d", command, adrOrVal);
        if(j==2)
        {
            (*commands)[i] = command[0];
            (*commands)[i] = command[1];
            (*commands)[i] = command[2];
            (*data)[i] = adrOrVal;
            i++;
            (*commandCount)++;
            command[0] = '\0';
            adrOrVal = -1;
        }
        else break;
    } while ((*commandCount) <= MAX_COMMANDS);

    if ( (*commandCount) > MAX_COMMANDS)
    {
        printf("Too many commands in file %s! MAX_COMMANDS is %d", fileName, MAX_COMMANDS);
    }
    fclose(file);
    return;
}
