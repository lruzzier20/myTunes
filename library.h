struct song_node** create();
struct song_node** add_song(struct song_node** lib, char* s, char* a);
void print_letter(struct song_node** lib, char l);
int ind(char* a);
struct song_node* find_track(struct song_node** lib, char* s, char* a);
