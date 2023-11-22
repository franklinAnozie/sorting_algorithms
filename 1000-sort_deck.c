#include "deck.h"

/**
 * sort_deck - a function that sorts a deck of cards
 * @deck: the deck of cards to be sorted
**/
void sort_deck(deck_node_t **deck)
{
	int i = 0;
	deck_node_t *current = *deck, **array_of_cards;

	if (deck == NULL || *deck == NULL)
		return;

	current = *deck;
	array_of_cards = malloc(sizeof(deck_node_t *) * 52);
	if (array_of_cards == NULL)
		return;

	while (current != NULL)
	{
		array_of_cards[i] = current;
		current = current->next;
		i++;
	}
	qsort(array_of_cards, 52, sizeof(deck_node_t *), compare_cards);

	i = 0;
	while (i < 52)
	{
		if (i == 0)
			array_of_cards[i]->prev = NULL;
		else
			array_of_cards[i]->prev = array_of_cards[i - 1];

		if (i == 51)
			array_of_cards[i]->next = NULL;
		else
			array_of_cards[i]->next = array_of_cards[i + 1];

		i++;
	}

	*deck = array_of_cards[0];
	free(array_of_cards);
}

/**
 * compare_cards - a function that compares two cards
 * @a: first card
 * @b: second card
 * Return: 1 if a > b, 0 if a == b, -1 if a < b
**/
int compare_cards(const void *a, const void *b)
{
	int first_card_order, second_card_order;
	const card_t *first_card = (*(deck_node_t **)a)->card;
	const card_t *second_card = (*(deck_node_t **)b)->card;

	if (first_card->kind == second_card->kind)
	{
		first_card_order = retOrder(first_card->value);
		second_card_order = retOrder(second_card->value);

		if (first_card_order == -1 || second_card_order == -1)
			exit(EXIT_FAILURE);

		return (first_card_order - second_card_order);
	}

	return (first_card->kind - second_card->kind);
}

/**
 * retOrder - a function that returns the order of a card
 * @value: the value of the card
 * Return: the order of the card
**/
int retOrder(const char *value)
{
	int i = 0;
	char *arr[13] = {"Ace", "2", "3", "4", "5", "6",
					"7", "8", "9", "10", "Jack", "Queen", "King"};

	while (i < 13)
	{
		if (strcmp(arr[i], value) == 0)
			return (i);
		i++;
	}

	return (-1);
}
