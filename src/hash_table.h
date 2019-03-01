#define TABLESIZE 59 //This number must be a prime
#define SECONDCONST 53 //This must be smaller than TABLESIZE and is also a prime

typedef struct {
  char* key;
  char* value;
} str_pair;

typedef struct {
  int count;
  int size;
  str_pair** items;
} hash_table; 

void ht_insert(hash_table* ht, const char* key, const char* value);
char* ht_search(hash_table* ht, const char* key);
void ht_delete(hash_table* ht, const char* key);
int ht_const1, ht_const2;
void init_constant();
