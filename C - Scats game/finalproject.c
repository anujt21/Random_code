#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include"functions.h"


int main(void) {
  int N,i,j,round,pot,bet,choice,numPlayers,minBet;
  bool end;
  char userChar,name[15];
  Card *HN, *tmp,*stockPile,*discardPile=NULL;
  Player* Winner, * listOfPlayers, * tmpPlayer=NULL,*Dealer;

  stockPile = BuildLinkedList(52);
  ShuffleList(&stockPile);
  
  printf("Enter number of players:\n");
  scanf("%d", &numPlayers);

  while (numPlayers <= 1) {
	  printf("Enter players greater than 1\n");
	  scanf("%d", &numPlayers);
  }

  listOfPlayers = BuildPlayerList(numPlayers);
  DealCards(listOfPlayers, &stockPile, &discardPile);

  round = 1;
  pot = 0;

  RoundStats(&round, &pot, stockPile, discardPile, NULL,listOfPlayers);

  printf("Press any [Enter] to continue\n");
  getchar();
  system("cls");

  Dealer = listOfPlayers;

  round = 1;
  pot = 0;
  minBet = 0;

  while (listOfPlayers!=NextPlayer(listOfPlayers,listOfPlayers)) {
	  PlayRound(listOfPlayers, Dealer, &pot, &minBet, &stockPile, &discardPile, &round);
	  Dealer->dealer = 0;
	  Dealer = NextPlayer(Dealer, listOfPlayers);
	  Dealer->dealer = 1;
  }

  return(0);
}


