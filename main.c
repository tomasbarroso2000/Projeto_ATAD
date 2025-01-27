﻿/* PROJETO  ATAD 2019-20
* Identificacao dos Alunos:
*
*      Numero: 190221068 | Nome: André Dias
*      Numero: 190221029 | Nome: Tomás Barroso
*      Turma: EI-01
* Professora PL:
*
*       Patrícia Macedo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "commandsImpl.h"

typedef char String[255];

int main(int argc, char** argv){
    String command;
	int quit = 0;
	PtList patients = NULL;
	PtMap regions = NULL;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		
		menu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = commandQuit(&patients, &regions); /* vai provocar a saída do interpretador */				
		}
		else if (equalsStringIgnoreCase(command, "LOADP")) {
			commandLoadP(&patients);
			
		}
		else if (equalsStringIgnoreCase(command, "LOADR")) {
			commandLoadR(&regions);

		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			commandClear(patients, regions);
		}
		else if (equalsStringIgnoreCase(command, "AVERAGE")) {
			commandAverage(patients);
		}
		else if (equalsStringIgnoreCase(command, "FOLLOW")) {
			String id;
            printf("\nChoose the id of the patient you want to follow > ");
			fgets(id, sizeof(id), stdin);
			command[strlen(command) - 1] = '\0';

            commandFollow(patients,atol(id));
		}
		else if (equalsStringIgnoreCase(command, "SEX")) {
			commandSex(patients);
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {
			String id;
            printf("\nChoose the id of the patient you want to show > ");
			fgets(id, sizeof(id), stdin);
			command[strlen(command) - 1] = '\0';

			commandShow(patients,atol(id));
		}
		else if (equalsStringIgnoreCase(command, "TOP5")) {
			commandTop5(patients);
		}
		else if (equalsStringIgnoreCase(command, "OLDEST")) {
			commandOldest(patients);
		}
		else if (equalsStringIgnoreCase(command, "GROWTH")) {
			String date;
			printf("\nInsert the date you want to compare > ");
			fgets(date, sizeof(date), stdin);
			command[strlen(command) - 1] = '\0';
			commandGrowth(patients, date);
		}	
		else if (equalsStringIgnoreCase(command, "MATRIX")) {
			commandMatrix(patients);
		}
		else if (equalsStringIgnoreCase(command, "REGIONS")) {
			commandRegions(patients, regions);
		}	
		else if (equalsStringIgnoreCase(command, "REPORT")) {
			commandReport(regions, patients);
		}
		else {
			printf("%s : Comando não encontrado.\n", command);
		}
	}
	return (EXIT_SUCCESS);
}
