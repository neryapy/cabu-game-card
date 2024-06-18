#ifndef __list__h__
#define __list__h__
typedef enum
{
	false,
	true
}bool;
typedef struct listelement
{
	int value;
	struct listelement *next;
}listelement, *list;
list new_list(void);
bool is_empty_list(list li);
int list_lengh(list li);
void print_list(list li);
int print_element_list(list li, int element);
list push_back_list(list li, int x);
list push_front_list(list li,int x);
list pop_back_list(list li);
list pop_front_list(list li);
int random_card();
void swap_cards(list card_player1, list card_player2, int recive_emplacement, int output_emplacement);
int emplacement(list li, int x);
#endif