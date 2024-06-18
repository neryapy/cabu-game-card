#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
#include <unistd.h>
#include "list.h"
list new_list(void)
{
	return NULL;
}
bool is_empty_list(list li)
{
	if(li==NULL)
		return true;
	return false;
}
int list_lengh(list li)
{
	int size=0;
	if(!is_empty_list(li))
	{	while(li!=NULL)
		{	
			size++;
			li=li->next;
		}
	}
	return size;
}
void print_list(list li)
{
	if(is_empty_list(li))
	{
		printf("list is empty unable to print\n");
		return;
	}
	while(li!=NULL)
	{
		printf("[%d]", li->value);
		li=li->next;
	}
	printf("\n");
}
int print_element_list(list li, int element)
{
	int r;
	if(is_empty_list(li))
	{
		printf("list is empty unable to print\n");
		return 400;
	}
	for(int i=0; i<element; i++)
	{
		r=li->value;
		li=li->next;
	}
	return r;
}

list push_back_list(list li, int x)
{
	listelement *element;
	element=malloc(sizeof(*element));
	if(element==NULL)
	{
		fprintf(stderr, "fail alocate dinamic of memory\n");
		exit(1);
	}
	element->value=x;
	element->next=NULL;
	if(is_empty_list(li))
		return element;
	listelement *temp;
	temp=li;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=element;
	return li;

}
list push_front_list(list li,int x)
{
	listelement *element;
	element=malloc(sizeof(*element));
	if(element==NULL)
	{
		fprintf(stderr, "fail alocate dinamic of memory\n");
		exit(1);
	}
	element->value=x;

	if(is_empty_list(li))
	{
		element->next=NULL;
	}
	else
		element->next=li;
	return element;
}
list pop_back_list(list li)
{
	if(is_empty_list(li))
		return new_list();
	if(li->next==NULL)
	{
		free(li);
		li=NULL;
		return new_list();
	}
	listelement *temp=li;
	listelement *before=li;
	while(temp->next!=NULL)
	{
		before=temp;
		temp=temp->next;
	}
	before->next=NULL;
	free(temp);
	temp=NULL;
	return li;

}
list pop_front_list(list li)
{
	if(is_empty_list(li))
		return li;
	listelement *element;
	element=malloc(sizeof(*element));
	if(element==NULL)
	{
		fprintf(stderr, "fail alocate dinamic of memory\n");
		exit(1);
	}
	element=li->next;
	free(li);
	li=NULL;
	return element;
}
int emplacement(list li, int x)
{
    if(x==0)
        return li->value;
    if(x==1)
        return li->next->value;
    if(x==2)
        return li->next->next->value;
    if(x==3)
        return li->next->next->next->value;
}

int cards_chosen[13] = {0};
int deck[54]; // Array to represent the deck of cards
void swap_cards(list card_player1, list card_player2, int recive_emplacement, int output_emplacement) 
{
    int temp = emplacement(card_player1, recive_emplacement);
    if (output_emplacement == 0) {
        card_player1->value = card_player2->value;
        card_player2->value = temp;
    } else if (output_emplacement == 1) {
        card_player1->next->value = card_player2->value;
        card_player2->value = temp;
    } else if (output_emplacement == 2) {
        card_player1->next->next->value = card_player2->value;
        card_player2->value = temp;
    } else if (output_emplacement == 3) {
        card_player1->next->next->next->value = card_player2->value;
        card_player2->value = temp;
    }
}
int random_card() {
    unsigned int seed = (unsigned int)(time(NULL)) ^ (unsigned int)getpid();
    for (int i = 0; i < 10; i++)
        seed = seed * rand();
    srand(seed);
    int i;
    for (i = 0; i < 54; i++)
        deck[i] = i;
    int remaining_cards = 54;
    while (remaining_cards > 0) {
        int index = rand() % remaining_cards;
        int card_value = deck[index] % 13;
        if (cards_chosen[card_value] >= 2 || deck[index] == 52 || deck[index] == 53) { // Exclude jokers
            int temp = deck[index];
            deck[index] = deck[remaining_cards - 1];
            deck[remaining_cards - 1] = temp;
            remaining_cards--;
            continue;
        }
        cards_chosen[card_value]++;
        int temp = deck[index];
        deck[index] = deck[remaining_cards - 1];
        deck[remaining_cards - 1] = temp;
        remaining_cards--;
        return card_value;
    }
    return -1;
}