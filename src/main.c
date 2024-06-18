#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
#include <unistd.h>
#define windowHeight 500
#define windowWidth 700
float num_of_player;
list push(list li, int x, int index)
{
    listelement *element;
    element = malloc(sizeof(*element));
    if (element == NULL)
    {
        fprintf(stderr, "Failed to allocate dynamic memory\n");
        exit(1);
    }
    element->value = x;
    element->next = NULL;

    if (is_empty_list(li))
    {
        if (index != 0)
        {
            fprintf(stderr, "Invalid index for an empty list\n");
            exit(1);
        }
        return element;
    }
    listelement *temp;
    temp = li;

    for (int i = 0; i < index - 1; i++)
    {
        if (temp->next == NULL)
        {
            fprintf(stderr, "Invalid index\n");
            exit(1);
        }
        temp = temp->next;
    }

    element->next = temp->next;
    temp->next = element;
    return li;
}
int player_play_mod(int player_play)
{
    if(num_of_player<=player_play)
        player_play=1;
    else
        player_play++;
    return player_play;
}
int main(void)
{
    printf("number of player: \n");
    scanf("%f", &num_of_player);
    if (num_of_player != 2 && num_of_player != 3 && num_of_player != 4) 
    {
        printf("number of players are not valid");
        exit(1);
    }
    list card_player1 = NULL;
    list card_player2 = NULL;
    list card_player3 = NULL;
    list card_player4 = NULL;
    int point_of_player1 = 0, point_of_player2 = 0, point_of_player3 = 0, point_of_player4 = 0;
    if (num_of_player == 2) 
    {
        card_player1 = new_list();
        card_player2 = new_list();
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        printf("struct of data of card player 1:\n[%d] [%d]\n", card_player1->value, card_player1->next->value);
        printf("struct of data of card player 2:\n[%d] [%d]\n", card_player2->value, card_player2->next->value);
    } 
    else if (num_of_player == 3) 
    {
        card_player1 = new_list();
        card_player2 = new_list();
        card_player3 = new_list();
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        printf("struct of data of card player 1:\n[%d] [%d]\n", card_player1->value, card_player1->next->value);
        printf("struct of data of card player 2:\n[%d] [%d]\n", card_player2->value, card_player2->next->value);
        printf("struct of data of card player 3:\n[%d] [%d]\n", card_player3->value, card_player3->next->value);
    }
    else if (num_of_player == 4) 
    {
        card_player1 = new_list();
        card_player2 = new_list();
        card_player3 = new_list();
        card_player4 = new_list();
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player1 = push_back_list(card_player1, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player2 = push_back_list(card_player2, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player3 = push_back_list(card_player3, random_card());
        card_player4 = push_back_list(card_player4, random_card());
        card_player4 = push_back_list(card_player4, random_card());
        card_player4 = push_back_list(card_player4, random_card());
        card_player4 = push_back_list(card_player4, random_card());
        printf("struct of data of card player 1:\n[%d] [%d]\n", card_player1->value, card_player1->next->value);
        printf("struct of data of card player 2:\n[%d] [%d]\n", card_player2->value, card_player2->next->value);
        printf("struct of data of card player 3:\n[%d] [%d]\n", card_player3->value, card_player3->next->value);
        printf("struct of data of card player 4:\n[%d] [%d]\n", card_player4->value, card_player4->next->value);
    }
    int midle_card = random_card(), drop_card, temp, replace_emplacement, player_play = 1, pickaxe=0, next_card = random_card(), player_view_card, jack_change_card=0, recive_emplacement=0, output_emplacement=0, use_queen=0, queen_change_card=6, queen_give_card, queen_take_card, player_give_card, player_take_card, use_king=0, king_change_card=0, replace_emplacement1;
    while(1)
    {
        
        printf("player %d play\n", player_play);
        printf("on the midle the card value are : %d.", midle_card);
        printf(" you want to pickaxe(0-no 1-yes)? \n");
        scanf("%d", &pickaxe);
        if(pickaxe==1)
        {
            printf("the crad value you pickaxe are: %d. ", next_card);
            printf(" you want to drop_card?(0=no, 1-yes): \n");
            scanf("%d", &drop_card);
            if (drop_card == 0)
            {
                printf("where you want remplace(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)? \n");
                scanf("%d", &replace_emplacement);
                if (replace_emplacement == 0)
                {
                    if (player_play == 1)
                    {
                        midle_card=card_player1->value;
                        card_player1->value = next_card;
                    }
                    if (player_play == 2)
                    {
                        midle_card=card_player2->value;
                        card_player2->value = next_card;
                    }
                    if (player_play == 3)
                    {
                        midle_card=card_player3->value;
                        card_player3->value = next_card;
                    }
                    if (player_play == 4)
                    {
                        midle_card=card_player4->value;
                        card_player1->value = next_card;
                    }
                }
                if (replace_emplacement == 1)
                {
                    if (player_play == 1)
                    {
                        midle_card=card_player1->next->value;
                        card_player1->next->value = next_card;
                    }
                    if (player_play == 2)
                    {
                        midle_card=card_player2->next->value;
                        card_player2->next->value = next_card;
                    }
                    if (player_play == 3)
                    {                       midle_card=card_player1->next->value;
                        midle_card=card_player3->next->value;
                        card_player3->next->value = next_card;
                    }
                    if (player_play == 4)
                    {
                        midle_card=card_player4->next->value;
                        card_player4->next->value = next_card;
                    }
                }
                if (replace_emplacement == 2)
                {
                    if (player_play == 1)
                    {
                        midle_card=card_player1->next->next->value;
                        card_player1->next->next->value = next_card;
                    }
                    if (player_play == 2)
                    {
                        midle_card=card_player2->next->next->value;
                        card_player2->next->next->value = next_card;
                    }
                    if (player_play == 3)
                    {
                        midle_card=card_player3->next->next->value;
                        card_player3->next->next->value = next_card;
                    }
                    if (player_play == 4)
                    {
                        midle_card=card_player4->next->next->value;
                        card_player4->next->next->value = next_card;
                    }
                }
                if (replace_emplacement == 3)
                {
                    if (player_play == 1)
                    {
                        midle_card=card_player1->next->next->next->value;
                        card_player1->next->next->next->value = next_card;
                    }
                    if (player_play == 2)
                    {
                        midle_card=card_player1->next->next->next->value;
                        card_player2->next->next->next->value = next_card;
                    }
                    if (player_play == 3)
                    {
                        midle_card=card_player3->next->next->next->value;
                        card_player3->next->next->next->value = next_card;
                    }
                    if (player_play == 4)
                    {
                        midle_card=card_player4->next->next->next->value;
                        card_player4->next->next->next->value = next_card;
                    }
                }
            }
            if(drop_card==1)
            {
                midle_card=next_card;
                next_card=random_card();
                if(midle_card==7 || midle_card==8)
                {
                    printf("what the crad you want to view?(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                    scanf("%d", &replace_emplacement);
                    if(player_play == 1)
                        printf("%d", print_element_list(card_player1, replace_emplacement));
                    else if(player_play == 2)
                        printf("%d", print_element_list(card_player2, replace_emplacement));
                    else if(player_play == 3)
                        printf("%d", print_element_list(card_player3, replace_emplacement));
                    else if(player_play == 4)
                        printf("%d", print_element_list(card_player4, replace_emplacement));
                }
                if(midle_card==9 || midle_card==10)
                {
                    printf("who player you want to view the crad?(1-player 1, 2-player2, 3-player3, 4-player4)\n");
                    scanf("%d", &player_view_card);
                    printf("what the crad you want to view?(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                    scanf("%d", &replace_emplacement);
                    if(player_play!=player_view_card)
                    {
                        if(player_view_card == 1)
                            printf("%d", print_element_list(card_player1, replace_emplacement));
                        if(player_view_card == 2)
                            printf("%d", print_element_list(card_player2, replace_emplacement));
                        if(player_view_card == 3)
                            printf("%d", print_element_list(card_player3, replace_emplacement));
                        if(player_view_card == 4)
                            printf("%d", print_element_list(card_player4, replace_emplacement));
                    }
                    else
                        printf("you can not view your card.\n");
                }
                if (midle_card==11) 
                {
                    printf("player %d play\n", player_play);
                    printf("You want to change one of your cards with another player? (1-yes 0-no)\n");
                    scanf("%d", &jack_change_card);
                    if (jack_change_card == 0)
                    {
                        printf("Fine, you are not using your jack.\n");
                        break;
                    }
                    else if(jack_change_card == 1) 
                    {

                        printf("Which player do you want to change your card with? (1-player 1, 2-player 2, 3-player 3, 4-player 4)\n");
                        scanf("%d", &player_view_card);
                        printf("Where do you want to receive your card (0-3)?\n");
                        scanf("%d", &recive_emplacement);
                        printf("Where do you want to take your card (0-3)?\n");
                        scanf("%d", &output_emplacement);
                        if(player_play==1)
                        {
                            if (player_view_card == 2)
                                swap_cards(card_player1, card_player2, recive_emplacement, output_emplacement);
                            else if (player_view_card == 3)
                                swap_cards(card_player1, card_player3, recive_emplacement, output_emplacement);
                            else if (player_view_card == 4)
                                swap_cards(card_player1, card_player4, recive_emplacement, output_emplacement);
                        }
                        if(player_play==2)
                        {
                            if (player_view_card == 1)
                                swap_cards(card_player2, card_player1, recive_emplacement, output_emplacement);
                            else if (player_view_card == 3) 
                                swap_cards(card_player2, card_player3, recive_emplacement, output_emplacement);
                            else if (player_view_card == 4)
                                swap_cards(card_player2, card_player4, recive_emplacement, output_emplacement);
                        }
                        if(player_play==3)
                        {
                            if (player_view_card == 1)
                                swap_cards(card_player3, card_player1, recive_emplacement, output_emplacement);
                            else if (player_view_card == 2)
                                swap_cards(card_player3, card_player2, recive_emplacement, output_emplacement);
                            else if (player_view_card == 4)
                                swap_cards(card_player3, card_player4, recive_emplacement, output_emplacement);
                        }
                        if(player_play==4)
                        {
                            if (player_view_card == 1)
                                swap_cards(card_player4, card_player1, recive_emplacement, output_emplacement);
                            else if (player_view_card == 2)
                                swap_cards(card_player4, card_player2, recive_emplacement, output_emplacement);
                            else if (player_view_card == 3)
                                swap_cards(card_player4, card_player3, recive_emplacement, output_emplacement);
                        }
                        printf("struct of data of card player 1:\n[%d] [%d]\n", card_player1->value, card_player1->next->value);
                        printf("struct of data of card player 2:\n[%d] [%d]\n", card_player2->value, card_player2->next->value);
                        printf("struct of data of card player 3:\n[%d] [%d]\n", card_player3->value, card_player3->next->value);
                    } 
                    else
                        break;

                }
                if(midle_card==12&&num_of_player>2)
                {
                    printf("you want to use you queen?\n");
                    scanf("%d", &use_queen);
                    if(use_queen==0)
                        break;
                    else if(use_queen==1)
                    {
                        printf("which first player you want to swap card 2 or 3 or 4?\n");
                        scanf("%d", &player_take_card);
                        printf("which two player you want to swap card 2 or 3 or 4?\n");
                        scanf("%d", &player_give_card);
                        printf("what the card of first player you want to swap(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                        scanf("%d", &queen_take_card);
                        printf("what the card of the two  player you want to swap?(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                        scanf("%d", &queen_give_card);
                        if(num_of_player==4)
                        {
                            if(player_play==1)
                            {

                                if(player_take_card==2&&player_give_card==3)
                                    swap_cards(card_player2, card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==2&&player_give_card==4)
                                    swap_cards(card_player2, card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==2)
                                    swap_cards(card_player3, card_player2, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==4)
                                    swap_cards(card_player3, card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==2)
                                    swap_cards(card_player4,  card_player2, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==3)
                                    swap_cards(card_player4,card_player3, queen_take_card, queen_give_card);
                            }
                            else if(player_play==2)
                            {
                                if(player_take_card==1&&player_give_card==3)
                                    swap_cards(card_player1,card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==1&&player_give_card==4)
                                    swap_cards(card_player1,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==2)
                                    swap_cards(card_player3,  card_player2, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==4)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==2)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==3)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                            }
                            else if(player_play==3)
                            {
                                if(player_take_card==1&&player_give_card==3)
                                    swap_cards(card_player1,card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==1&&player_give_card==4)
                                    swap_cards(card_player1,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==2&&player_give_card==3)
                                    swap_cards(card_player2,  card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==2&&player_give_card==4)
                                    swap_cards(card_player2,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==2)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==4&&player_give_card==3)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                            }
                            else if(player_play==4)
                            {
                                if(player_take_card==1&&player_give_card==3)
                                    swap_cards(card_player1,card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==1&&player_give_card==4)
                                    swap_cards(card_player1,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==2&&player_give_card==3)
                                    swap_cards(card_player2,  card_player3, queen_take_card, queen_give_card);
                                else if(player_take_card==2&&player_give_card==4)
                                    swap_cards(card_player2,  card_player4, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==2)
                                    swap_cards(card_player3,  card_player2, queen_take_card, queen_give_card);
                                else if(player_take_card==3&&player_give_card==4)
                                    swap_cards(card_player3,  card_player4, queen_take_card, queen_give_card);
                                
                            }
                        }
                        else if(num_of_player==3)
                        {
                            if(player_play==1)
                                swap_cards(card_player2,  card_player3, queen_take_card, queen_give_card);
                            else if(player_play==2)
                                swap_cards(card_player1,  card_player3, queen_take_card, queen_give_card);
                            else if(player_play==3)
                                swap_cards(card_player1,  card_player2, queen_take_card, queen_give_card);
                        }
                    }
                    else
                    {
                        printf("you dont use your queen\n");
                        break;
                    }
                }
                if(midle_card==13||midle_card==-1)
                {
                    printf("you want to use your king?(0-no 1-yes)\n");
                    scanf("%d", &use_king);
                    if(use_king==1)
                    {
                        printf("who person you want to view card?(1-player 1, 2-player 2, 3-player 3, 4-player 4)\n");
                        scanf("%d", &player_view_card);
                        printf("what the crad you want to view?(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                        scanf("%d", &replace_emplacement1);
                        if(player_view_card == 1)
                            printf("%d", print_element_list(card_player1, replace_emplacement1));
                        else if(player_view_card == 2)
                            printf("%d", print_element_list(card_player2, replace_emplacement1));
                        else if(player_view_card == 3)
                            printf("%d", print_element_list(card_player3, replace_emplacement1));
                        else if(player_view_card == 4)
                        printf("%d", print_element_list(card_player4, replace_emplacement1));
                        printf("what the crad(of your card) else you want to view?(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)\n");
                        scanf("%d", &replace_emplacement);
                        if(player_play == 1)
                            printf("%d", print_element_list(card_player1, replace_emplacement));
                        else if(player_play == 2)
                            printf("%d", print_element_list(card_player2, replace_emplacement));
                        else if(player_play == 3)
                            printf("%d", print_element_list(card_player3, replace_emplacement));
                        else if(player_play == 4)
                            printf("%d", print_element_list(card_player4, replace_emplacement));
                        printf("you want to swap cards?(1-yes 0-no)\n");
                        scanf("%d", &king_change_card);
                        if(king_change_card==1)
                        {
                            if(num_of_player==2)
                            {
                                if(player_play==1&&player_view_card==2)
                                    swap_cards(card_player1, card_player2, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==1)
                                    swap_cards(card_player2, card_player1, replace_emplacement1, replace_emplacement);
                            }
                            if(num_of_player==3)
                            {
                                if(player_play==1&&player_view_card==2)
                                    swap_cards(card_player1, card_player2, replace_emplacement1, replace_emplacement);
                                if(player_play==1&&player_view_card==3)
                                    swap_cards(card_player1, card_player3, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==1)
                                    swap_cards(card_player2, card_player1, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==3)
                                    swap_cards(card_player2, card_player3, replace_emplacement1, replace_emplacement);
                                if(player_play==3&&player_view_card==1)
                                    swap_cards(card_player3, card_player1, replace_emplacement1, replace_emplacement);
                                if(player_play==3&&player_view_card==2)
                                    swap_cards(card_player3, card_player2, replace_emplacement1, replace_emplacement);
                            }
                            if(num_of_player==4)
                            {
                                if(player_play==1&&player_view_card==2)
                                    swap_cards(card_player1, card_player2, replace_emplacement1, replace_emplacement);
                                if(player_play==1&&player_view_card==3)
                                    swap_cards(card_player1, card_player3, replace_emplacement1, replace_emplacement);
                                if(player_play==1&&player_view_card==4)
                                    swap_cards(card_player1, card_player4, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==1)
                                    swap_cards(card_player2, card_player1, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==3)
                                    swap_cards(card_player2, card_player3, replace_emplacement1, replace_emplacement);
                                if(player_play==2&&player_view_card==4)
                                    swap_cards(card_player2, card_player4, replace_emplacement1, replace_emplacement);
                                if(player_play==3&&player_view_card==1)
                                    swap_cards(card_player3, card_player1, replace_emplacement1, replace_emplacement);
                                if(player_play==3&&player_view_card==2)
                                    swap_cards(card_player3, card_player2, replace_emplacement1, replace_emplacement);
                                if(player_play==3&&player_view_card==4)
                                    swap_cards(card_player3, card_player4, replace_emplacement1, replace_emplacement);
                            }
                        }
                    }
                    else
                    {
                        printf("you don't use your king\n");
                        break;
                    }
                }
            }
            player_play=player_play_mod(player_play);
        }
        else if(pickaxe==0)
        {
            printf("where you want remplace(enter 0 to left-down, 1 to rightr-down 2 to left-up and 3 to right-up)? \n");
            scanf("%d", &replace_emplacement);
            printf("------------------------------------------------------------------------------------------------------\n");
            if (replace_emplacement == 0)
            {
                if (player_play == 1)
                {
                    temp=midle_card;
                    midle_card=card_player1->value;
                    card_player1->value = temp;
                }
                if (player_play == 2)
                {
                    temp=midle_card;
                    midle_card=card_player2->value;
                    card_player2->value = temp;
                }
                if (player_play == 3)
                {
                    temp=midle_card;
                    midle_card=card_player3->value;
                    card_player3->value = temp;
                }
                if (player_play == 4)
                {
                    temp=midle_card;
                    midle_card=card_player4->value;
                    card_player1->value = temp;
                }
            }
            if (replace_emplacement == 1)
            {
                if (player_play == 1)
                {
                    temp=midle_card;
                    midle_card=card_player1->next->value;
                    card_player1->next->value = temp;
                }
                if (player_play == 2)
                {
                    temp=midle_card;
                    midle_card=card_player2->next->value;
                    card_player2->next->value = temp;
                }
                if (player_play == 3)
                {
                    temp=midle_card;
                    midle_card=card_player3->next->value;
                    card_player3->next->value = temp;
                }
                if (player_play == 4)
                {
                    temp=midle_card;
                    midle_card=card_player4->next->value;
                    card_player4->next->value = temp;
                }
            }
            if (replace_emplacement == 2)
            {
                if (player_play == 1)
                {
                    temp=midle_card;
                    midle_card=card_player1->next->next->value;
                    card_player1->next->next->value = temp;
                }
                if (player_play == 2)
                {
                    temp=midle_card;
                    midle_card=card_player2->next->next->value;
                    card_player2->next->next->value = temp;
                }
                if (player_play == 3)
                {
                    temp=midle_card;
                    midle_card=card_player3->next->next->value;
                    card_player3->next->next->value = temp;
                }
                if (player_play == 4)
                {
                    temp=midle_card;
                    midle_card=card_player4->next->next->value;
                    card_player4->next->next->value = temp;
                }
            }
            if (replace_emplacement == 3)
            {
                if (player_play == 1)
                {
                    temp=midle_card;
                    midle_card=card_player1->next->next->next->value;
                    card_player1->next->next->next->value = temp;
                }
                if (player_play == 2)
                {
                    temp=midle_card;
                    midle_card=card_player2->next->next->next->value;
                    card_player2->next->next->next->value = temp;
                }
                if (player_play == 3)
                {
                    temp=midle_card;
                    midle_card=card_player3->next->next->next->value;
                    card_player3->next->next->next->value = temp;
                }
                if (player_play == 4)
                {
                    temp=midle_card;
                    midle_card=card_player4->next->next->next->value;
                    card_player4->next->next->next->value = temp;
                }
            }
            player_play=player_play_mod(player_play);
        }
    }
    return 0;

}
//gcc src/*.c -o bin/CABU.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2