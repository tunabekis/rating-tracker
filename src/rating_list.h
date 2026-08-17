#ifndef RATING_LIST_H
#define RATING_LIST_H

// A single user-item rating entry in the singly linked list.
typedef struct RatingNode {
    int userId;
    int itemId;
    float rating;
    struct RatingNode* next;
} RatingNode;

// Inserts a new (userId, itemId) rating, or updates the rating value if the
// pair already exists in the list.
void insertRating(RatingNode** head, int userId, int itemId, float rating);

// Removes the rating entry matching (userId, itemId), if one exists.
void removeRating(RatingNode** head, int userId, int itemId);

// Prints the rating for the given (userId, itemId) pair, or 0.0 if not found.
void printRating(const RatingNode* head, int userId, int itemId);

// Prints the average rating of an item across all users who rated it.
void printAverageRating(const RatingNode* head, int itemId);

// Frees every node in the list.
void freeRatingList(RatingNode* head);

#endif // RATING_LIST_H
