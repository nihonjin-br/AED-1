#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRIENDS 100
#define MAX_NAME_LENGTH 51

void insert_friends(char friends[][MAX_NAME_LENGTH], int *friend_count, char new_friends[][MAX_NAME_LENGTH], int new_count, char *target) {
    int position = *friend_count;  
    
    if (strcmp(target, "nao") != 0) {
        for (int i = 0; i < *friend_count; i++) {
            if (strcmp(friends[i], target) == 0) {
                position = i;
                break;
            }
        }
    }

    for (int i = *friend_count - 1; i >= position; i--) {
        strcpy(friends[i + new_count], friends[i]);
    }

    for (int i = 0; i < new_count; i++) {
        strcpy(friends[position + i], new_friends[i]);
    }

    *friend_count += new_count;
}

int main() {
    char friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char new_friends[MAX_FRIENDS][MAX_NAME_LENGTH];
    char target[MAX_NAME_LENGTH];
    int friend_count = 0, new_count = 0;

    char line[5000];
    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(friends[friend_count++], token);
        token = strtok(NULL, " \n");
    }

    fgets(line, sizeof(line), stdin);
    token = strtok(line, " \n");
    while (token != NULL) {
        strcpy(new_friends[new_count++], token);
        token = strtok(NULL, " \n");
    }

    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';  

    insert_friends(friends, &friend_count, new_friends, new_count, target);

    for (int i = 0; i < friend_count; i++) {
        printf("%s", friends[i]);
        if (i < friend_count - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
