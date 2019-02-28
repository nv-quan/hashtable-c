#define TABLESIZE 59 //This number must be a prime

typedef struct {
  char* key;
  char* value;
} pair;

typedef struct {
  int count;
  int size;
  pair** items;
} table; 

