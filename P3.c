#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define string_eq(str1, str2) strcmp(str1, str2) == 0

static char* read_stdin(void);


int main(int argc, const char* argv[]) {
	char working_dir[] = "~ ";
	char* user_env_name;
	char* hostname_env_name;

	//check if WSL
	if (getenv("WSL_DISTRO_NAME") != NULL) {
		user_env_name = "USER";
		hostname_env_name = "NAME";	
	} else {
		printf("\x1b[31mYOU NEED TO SET THIS UP REMEMBER!!!");
	}

	char* username = getenv(user_env_name);
	char* hostname = getenv(hostname_env_name);

	bool display_exec_status = false;
	int exec_status = 0;

	while (1) {
		if (!display_exec_status) {
			printf("\x1b[32m%s@%s:%s \x1b[0m> ", username, hostname, working_dir);	
		} else {
			printf("\x1b[32m%s@%s: %s %s[%d] \x1b[0m> ", username, hostname, working_dir, exec_status != -1 ? "\x1b[36m" : "\x1b[31m", exec_status);	
		}
		char* buffer = read_stdin();

		if (string_eq(buffer, "myclear")) {
			exec_status = system("clear");
		} else if (string_eq(buffer, "myenviron")) {
			extern char **environ;
			char* curr;

			for (int i = 0; (curr = environ[i]) != NULL; i++) {
				printf("%s\n", curr);
			}

			printf("\n");
		} else {
			exec_status = system(buffer);
		}

		display_exec_status = true;
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
	char buf[4096];
	char** tokens;
	char current_char;
	int current_token_len = 0;


	for (int i = 0; (current_char = str[i]) != '\0'; i++) {
		if (current_char == ' ') {
			
		} else {
			current_token_len++;
		}
	}
}
