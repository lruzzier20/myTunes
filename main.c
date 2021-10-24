#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main(){
  struct song_node* list = insert_front(NULL, "Dreams", "Fleetwood Mac");
  print_list(list);
  list=insert_front(list, "Free Bird", "Lynyrd Skynyrd");
  list=insert_front(list, "Stairway To Heaven", "Led Zeppelin");
  print_list(list);
  list=remove_node(list, "Stairway To Heaven", "Led Zeppelin");
  print_list(list);
  structprnt(artist_song(list, "Dreams", "Fleetwood Mac"));
  structprnt(first_song(list, "Lynyrd Skynyrd"));
  printf("--------\n");
  struct song_node* list2 = insert_front(NULL, "Back In Black", "AC/DC");
  print_list(list2);
  list2=insert_alph(list2, "ZZZZZ", "ZZZZZ");
  print_list(list2);
  structprnt(random_elem(list2));
  printf("--------\n");
  struct song_node** lib = create();
  lib=add_song(lib, "S", "A");
  lib=add_song(lib, "S2", "AB");
  print_letter(lib, 'A');
  return 0;
}
