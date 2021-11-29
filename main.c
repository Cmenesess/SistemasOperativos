
#define STDIN 0
#define STDOUT 1
#include "header.h"

int main()
{
    char *comando;
    char **tokens;
    char copy[MAX_SIZE];
    pid_t pid;
    int fd[2];
    int st;
    while (1){
        pipe(fd);
        size_t valor = 0;
    	printf(">>");
    	ssize_t numeroCaracteres =getline(&comando, &valor, stdin);
        memset(comando + numeroCaracteres-1, '\0', 1*sizeof(char));
        if (strcmp(comando, "exit") == 0)
        {
            printf("Finalizar shell!\n");
            return 0;
        }
        else
        {
            strcpy(copy,comando);
            tokens = separar_tokens(copy, " ");
            if (tokens[0] != NULL)
            {
                pid = fork();
                if (pid < 0)
                {
                    fprintf(stderr, "Erro al intentar hacer el fork\n");
                    exit(1);
                }
                else if (pid == 0)
                {
                    close(STDOUT);
                    dup(fd[1]);
                    close(fd[0]);
                    close(fd[1]);
                    execvp(tokens[0], tokens);
                    exit(0);
                }

                else
                {
                    while (wait(&st) != pid);
                    dup(fd[0]);
                    close(fd[1]);
                    char buff[MAX_SIZE]={0};
                    read(fd[0],buff,MAX_SIZE);
                    printf("%s\n",buff);
                }
            }
            free(tokens);
            free(comando);
        }
    }
}
