#include <stdio.h>
#include <string.h>
#include "rating_list.h"

#define COMMAND_MAX_LEN 20
#define LINE_MAX_LEN 256

// Parses one line of input and dispatches it to the matching list operation.
static void processLine(const char* line, RatingNode** head) {
    char command[COMMAND_MAX_LEN];
    int userId, itemId;
    float rating;

    // Width limit (COMMAND_MAX_LEN - 1) prevents writing past the command buffer.
    if (sscanf(line, "%19s", command) != 1) {
        return;
    }

    if (strcmp(command, "INSERT") == 0) {
        // %*s skips the already-parsed command word.
        if (sscanf(line, "%*s %d %d %f", &userId, &itemId, &rating) == 3) {
            insertRating(head, userId, itemId, rating);
        }
    } else if (strcmp(command, "REMOVE") == 0) {
        if (sscanf(line, "%*s %d %d", &userId, &itemId) == 2) {
            removeRating(head, userId, itemId);
        }
    } else if (strcmp(command, "RATING") == 0) {
        if (sscanf(line, "%*s %d %d", &userId, &itemId) == 2) {
            printRating(*head, userId, itemId);
        }
    } else if (strcmp(command, "AVERAGE") == 0) {
        if (sscanf(line, "%*s %d", &itemId) == 1) {
            printAverageRating(*head, itemId);
        }
    }
}

int main(void) {
    RatingNode* head = NULL;
    char line[LINE_MAX_LEN];

    while (fgets(line, sizeof(line), stdin)) {
        processLine(line, &head);
    }

    freeRatingList(head);
    return 0;
}
