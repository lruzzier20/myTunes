struct song_node{
  char song[50];
  char artist[50];
  struct song_node* next;
};
void structprnt(struct song_node *f);
void print_list(struct song_node *g);
struct song_node* insert_front(struct song_node* top, char* s, char* a);
struct song_node* free_list(struct song_node* start);
struct song_node* remove_node(struct song_node *front, char* s, char* a);
struct song_node* artist_song(struct song_node *front, char* s, char* a);
struct song_node* first_song(struct song_node *front, char *a);
int compare_nodes(struct *song_node first, struct *song_node second);
struct song_node* insert_alph(struct song_node* top, char* s, char* a);
int num_elems(struct song_node* top);
struct song_node* random_elem(struct song_node* top); 
