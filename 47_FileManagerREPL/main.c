#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This simple utiliy allows the user to create, remove
 * or rename files in the local directory.
 */
 
void printCommands();
void undefinedCommandMsg();
void runCommand(int, char[][40]);

int main(void) {
	// Variable to save line
	char line[80];
	char tokens[3][40];
	
	// Starting instructions
	printCommands();
	
	// REPL
	while(1) {
		// Show prompt and get command line
		printf("> ");
		gets(line);
		
		// Get blank slots to save commands
		*tokens[0] = '\0';
		*tokens[1] = '\0';
		*tokens[2] = '\0';
		
		// Parse command line
		int tokensCount = sscanf(line, "%39s %39s %39s",
		                         tokens[0], tokens[1], tokens[2]);


		// Execute command
		runCommand(tokensCount, tokens);
	}
	return 0;
}

// Run command with parameters
void runCommand(int tokensCount, char tokens[][40]) {
	if(tokensCount == 1) {
		if(strcmp(tokens[0], "help") == 0) {
			printCommands();
		} else if(strcmp(tokens[0], "quit") == 0) {
			exit(EXIT_SUCCESS);
		} else {
			undefinedCommandMsg();
		}
	} else if(tokensCount == 2) {
		if(strcmp(tokens[0], "remove") == 0) {
			if(remove(tokens[1])) {
				printf("  Error when removing file.\n\n");
			} else {
				printf("  File '%s' removed.\n\n", tokens[1]);
			}
		} else if(strcmp(tokens[0], "create") == 0) {
			FILE *file = fopen(tokens[1], "w");
			
			if(file == NULL) {
				printf("  Error when creating file.\n\n");
			} else {
				printf("  File '%s' created.\n\n", tokens[1]);
			}
			
			fclose(file);
		} else {
			undefinedCommandMsg();
		}
	} else if(tokensCount == 3) {
		if(strcmp(tokens[0], "rename") == 0) {
			if(rename(tokens[1], tokens[2])) {
				printf("  Error when renaming file.\n\n");
			} else {
				printf("  File '%s' was renamed to '%s'.\n\n",
				       tokens[1], tokens[2]);
			}
		} else {
			undefinedCommandMsg();
		}
	} 
}

// Show message for undefined command
void undefinedCommandMsg() {
	printf("  Undefined command.\n\n");
}

// Print all available commands and usage
void printCommands() {
	printf("  Available commands: \n");
	printf("    help\n");
	printf("    quit\n");
	printf("    create <file>\n");
	printf("    remove <file>\n");
	printf("    rename <original_name> <new_name>\n\n");
}
