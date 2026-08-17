# Rating Tracker

A command-line tool that maintains user-item ratings in memory using a
singly linked list. Ratings are read as line-based commands from standard
input and results are printed to standard output.

## Features

- **INSERT** a rating for a (user, item) pair, or update it if it already
  exists.
- **REMOVE** a rating for a (user, item) pair.
- **RATING** look up the rating a user gave a specific item.
- **AVERAGE** compute the average rating of an item across all users.

## Technologies

- C (C11 standard)
- GCC
- Make

## Project Structure

```
.
├── src/
│   ├── main.c          # Command-line input parsing and dispatch loop
│   ├── rating_list.c    # Linked-list rating store implementation
│   └── rating_list.h    # Public API and data structure definitions
├── Makefile
└── README.md
```

## Building

```bash
make
```

This produces an executable named `rating_tracker`.

## Running

The program reads commands line by line from standard input until EOF.

```bash
./rating_tracker
```

### Command Format

| Command | Syntax                        | Description                          |
|---------|-------------------------------|---------------------------------------|
| INSERT  | `INSERT <userId> <itemId> <rating>` | Add or update a rating          |
| REMOVE  | `REMOVE <userId> <itemId>`    | Remove a rating                       |
| RATING  | `RATING <userId> <itemId>`    | Print a user's rating for an item     |
| AVERAGE | `AVERAGE <itemId>`            | Print the average rating for an item  |

### Example

```bash
$ ./rating_tracker
INSERT 1 100 4.5
INSERT 2 100 3.0
RATING 1 100
AVERAGE 100
REMOVE 1 100
```

```
Customer rating (1, 100) is added successful
Customer rating (2, 100) is added successful
Customer rating (1, 100) is: 4.5
Average rating (100) is: 3.8
Customer rating (1, 100) is removed successful
```

## Cleaning Build Artifacts

```bash
make clean
```
