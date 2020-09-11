#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char* read_stdin(void);
static char** tokenize(char* str);

int main(int argc, const char* argv[]) {
	char working_dir[] = "~ ";	
	char username[100]; 
	getlogin_r(username, 100);

	while (1) {
		printf("\x1b[32m%s@%s \x1b[0m> ", username, working_dir);	
		char* buffer = read_stdin();

		//stuff

		free(buffer);

							
	}
	
}

static char* read_stdin(void) {
	size_t cap = 4096, len = 0;
	char* buffer = malloc(cap * sizeof(char));
	int c;

	while ((c = fgetc(stdin)) != '\n' && !feof(stdin)) {
		buffer[len] = c;

		if (++len == cap) {
			buffer = realloc(buffer, (cap *= 2) * sizeof(char));
		}
	}

	buffer[len] = '\0';
	return buffer;
}

static char** tokenize(char* str, int* num_tokens) {
	char* tokens[];
	char* token = strtok(str, " ");
	int n = 0;

	while (token != NULL) {
		token = strtok(NULL, s);

		if () {
			
		}

		n++;
	}

	&num_tokens = n;
}
