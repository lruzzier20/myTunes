#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

int main(){
  printf("Linked List Tests\n");
  printf("==========================================\n\n");

  printf("Testing print_list:\n");
  struct song_node* list = insert_front(NULL, "Dreams", "Fleetwood Mac");
  list=insert_front(list, "Free Bird", "Lynyrd Skynyrd");
  list=insert_front(list, "Stairway To Heaven", "Led Zeppelin");
  print_list(list);
  printf("=========================================\n\n");

  printf("Testing structprnt(print_node):\n");
  structprnt(artist_song(list, "Dreams", "Fleetwood Mac"));
  printf("=========================================\n\n");

  printf("Testing artist_song(find_node):\n");
  printf("Looking for Song:Dreams, Artist:Fleetwood Mac\n");
  printf("\tNode found! ");
  structprnt(artist_song(list, "Dreams", "Fleetwood Mac"));
  printf("Looking for Song:Stairway to Heaven, Artist:Led Zeppelin\n");
  printf("\tNode found! ");
  structprnt(artist_song(list, "Stairway To Heaven", "Led Zeppelin"));
  printf("=========================================\n\n");

  printf("Testing first_song(find_artist):\n");
  printf("Looking for  Artist:Fleetwood Mac\n");
  printf("\tArtist found! ");
  structprnt(first_song(list, "Fleetwood Mac"));
  printf("Looing for Artist:Radiohead\n");
  printf("\t");
  first_song(list, "Radiohead");
  printf("\n");
  printf("=========================================\n\n");

  printf("Testing compare_nodes(songcmp):\n");
  printf("Comparing Song:Stairway To Heaven, Artist:Led Zeppelin to Song:Stairway To Heaven, Artist:Led Zeppelin\n");
  printf("\t%d", compare_nodes(list, list));
  printf("\n");
  printf("Comparing Song:Stairway To Heaven, Artist:Led Zeppelin to Song:Dreams, Artist:Fleetwood Mac\n");
  printf("\t%d", compare_nodes(list, (list->next)->next));
  printf("\n");
  printf("=========================================\n\n");

  printf("Testing random_elem(random):\n");
  srand(time(NULL));
  structprnt(random_elem(list));
  structprnt(random_elem(list));
  structprnt(random_elem(list));
  printf("=========================================\n\n");

  printf("Testing remove_node(remove):\n");
  printf("Removing Song:Stairway To Heaven, Artist: Led Zeppelin\n");
  list = remove_node(list, "Stairway To Heaven", "Led Zeppelin");
  print_list(list);
  printf("=========================================\n\n");

  printf("Testing free_list:\n");
  printf("\tFreeing_node: Song:Free Bird, Artist:Lynyrd Skynyrd\n");
  printf("\tFreeing_node: Song:Dreams, Artist:Fleetwood Mac\n");
  list = free_list(list);
  printf("list after free_list:\n");
  print_list(list);
  printf("\n=========================================\n\n");

  printf("Music Library Tests\n");
  printf("=========================================\n\n");

  struct song_node** lib = create();
  lib = add_song(lib, "Time", "Pink Floyd");
  lib = add_song(lib, "Money", "Pink Floyd");
  lib = add_song(lib, "Breathe", "Pink Floyd");
  lib = add_song(lib, "Comfortably Numb", "Pink Floyd");
  lib = add_song(lib, "Another Brick in the Wall (Part Two)", "Pink Floyd");
  lib = add_song(lib, "Runaway", "Kanye West");


  printf("Testing print_letter:\n");
  print_letter(lib, 'P');
  printf("=========================================\n\n");

  printf("Testing print_lib(rary):\n");
  print_lib(lib);
  printf("=========================================\n\n");

  printf("Testing find_track(find):\n");
  printf("Looking for Song:Money, Artist:Pink Floyd\n");
  printf("\tSong found! ");
  structprnt(find_track(lib, "Money", "Pink Floyd"));
  printf("=========================================\n\n");

  printf("Testing find_artist:\n");
  printf("Looking for Artist:Pink Floyd\n");
  printf("Artist found! \n");
  print_artist(lib, "Pink Floyd");
  printf("=========================================\n\n");

  printf("Testing remove_song:\n");
  printf("Removing: Song:Money, Artist:Pink Floyd\n");
  lib = remove_song(lib, "Money", "Pink Floyd");
  print_lib(lib);
  printf("=========================================\n\n");

  printf("Testing shuffle_songs(shuffle):\n");
  shuffle_songs(lib);
  printf("=========================================\n\n");

  printf("Testing remove_all(clear_library):\n");
  printf("\tFreeing_node: Song:Runaway, Artistt:Kanye West\n");
  printf("\tFreeing_node: Song:Another Brick in the Wall (Part Two), Artist:Pink Floyd\n");
  printf("\tFreeing_node: Song:Breathe, Artist:Pink Floyd\n");
  printf("\tFreeing_node: Song:Comfortably Numb, Artist:Pink Floyd\n");
  printf("\tFreeing_node: Song:Time, Artist:Pink Floyd\n");
  remove_all(lib);
  printf("Library after clear:");
  print_lib(lib);
  printf("\n");

  /*struct song_node* list2 = insert_front(NULL, "Back In Black", "AC/DC");
  print_list(list2);
  list2=insert_alph(list2, "ZZZZZ", "ZZZZZ");
  print_list(list2);
  structprnt(random_elem(list2));
  printf("--------\n");
  struct song_node** lib = create();
  lib=add_song(lib, "S", "A");
  print_letter(lib, 'A');
  lib=add_song(lib, "S2", "AB");
  print_letter(lib, 'A');
  lib=add_song(lib, "S3", "AZ");
  lib=add_song(lib, "S3", "AZZ");
  lib=add_song(lib, "S3", "AZZZ");
  structprnt(find_track(lib, "S", "A"));
  print_letter(lib, 'A');
  structprnt(find_artist(lib, "A"));
  print_letter(lib, 'A');
  lib=add_song(lib, "zwaf o", "$");
  lib=add_song(lib, "xwaf t", "$$");
  lib=add_song(lib, "cwaf t", "$$");
  print_letter(lib, '@');
  print_artist(lib, "$$");
  printf("-------------\n");
  print_lib(lib);
  printf("-------------\n");
  shuffle_songs(lib);
  printf("-------------\n");
  lib=remove_song(lib,"S","A");
  print_lib(lib);
  printf("-------------\n");
  remove_all(lib);
  print_lib(lib);*/
  return 0;
}
