#include <stdio.h>
#include <stdlib.h>
#include "rating_list.h"

// Finds the node matching (userId, itemId), or NULL if none exists.
static RatingNode* findNode(RatingNode* head, int userId, int itemId) {
    RatingNode* current = head;
    while (current != NULL) {
        if (current->userId == userId && current->itemId == itemId) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertRating(RatingNode** head, int userId, int itemId, float rating) {
    RatingNode* existing = findNode(*head, userId, itemId);

    if (existing != NULL) {
        existing->rating = rating;
        printf("Customer rating (%d, %d) is updated\n", userId, itemId);
        return;
    }

    RatingNode* newNode = (RatingNode*)malloc(sizeof(RatingNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: out of memory while inserting rating (%d, %d)\n", userId, itemId);
        return;
    }

    newNode->userId = userId;
    newNode->itemId = itemId;
    newNode->rating = rating;
    newNode->next = *head;
    *head = newNode;

    printf("Customer rating (%d, %d) is added successful\n", userId, itemId);
}

void removeRating(RatingNode** head, int userId, int itemId) {
    RatingNode* current = *head;
    RatingNode* prev = NULL;

    while (current != NULL) {
        if (current->userId == userId && current->itemId == itemId) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Customer rating (%d, %d) is removed successful\n", userId, itemId);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Customer rating (%d, %d) does not exit\n", userId, itemId);
}

void printRating(const RatingNode* head, int userId, int itemId) {
    const RatingNode* current = head;
    while (current != NULL) {
        if (current->userId == userId && current->itemId == itemId) {
            printf("Customer rating (%d, %d) is: %.1f\n", userId, itemId, current->rating);
            return;
        }
        current = current->next;
    }
    printf("Customer rating (%d, %d) is: %.1f\n", userId, itemId, 0.0);
}

void printAverageRating(const RatingNode* head, int itemId) {
    const RatingNode* current = head;
    float sum = 0.0f;
    int count = 0;

    while (current != NULL) {
        if (current->itemId == itemId) {
            sum += current->rating;
            count++;
        }
        current = current->next;
    }

    float average = (count > 0) ? (sum / (float)count) : 0.0f;
    printf("Average rating (%d) is: %.1f\n", itemId, average);
}

void freeRatingList(RatingNode* head) {
    RatingNode* current = head;
    while (current != NULL) {
        RatingNode* next = current->next;
        free(current);
        current = next;
    }
}
