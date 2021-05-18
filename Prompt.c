/*
 ============================================================================
 Name        : Prompt.c
 Author      : Jonathas Kerber
 Version     : 1
 Copyright   : 
 Description : Kryptus Technical Challenge
 ============================================================================
 */

#include "desguise_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);

		operate_list(input);
	}

	return EXIT_SUCCESS;
}
