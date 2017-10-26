#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "menu.h"





void asking_input_fgets(char* command, char* todostring, char* user_input)
{
    fgets(user_input, 255, stdin);
    strcpy(command, strtok(user_input, " "));
    if (strcmp(command, "exit\n") == 0) {
        printf("The program is exiting now. Goodbye!");
        exit(0);
    } else if (strcmp(command, "clear\n") == 0) {
            system("cls");
            fgets(user_input, 255, stdin);
            strcpy(command, strtok(user_input, " "));
    } else if (strcmp(command, "help\n") == 0) {
            system("cls");
            todo_menu();
            system("cls");
            fgets(user_input, 255, stdin);
            strcpy(command, strtok(user_input, " "));
    }
    strcpy(todostring, strtok(NULL, "\n+1"));
}

void add_new_task(todo_s *task, char* todostring)
{
    strcpy (task[i].description, todostring);
    i++;
}

void write_to_file(todo_s *task)
{
    FILE *fp = fopen("todos.txt", "wb");
    fwrite(task, sizeof(char), sizeof(task), fp);
    fclose(fp);
}
