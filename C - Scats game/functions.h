#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

typedef struct Cards_s {
    int FaceValue;
    int gameValue;
    char Suit[9];
    struct Cards_s* pt;
    struct Cards_s* prevPt;
}Card;

typedef struct Player_s {
    int totVal,index,dealer;
    int money;
    bool fold;
    char Name[15];
    Card** deck;
    struct Player_s* ptr;
    struct Player_s* prevPtr;
}Player;


//CARDS FUNCTIONS:

Card* ReturnNthNode(Card* HN, int N) {
    //Warning No Error checking
    int i = 1;
    while (i < N) {
        
        HN = HN->pt;
        i++;
    }
    return(HN);
}
void RemovingCard(Card* ON) {
    Card* tmp1;
    Card* tmp2;
    tmp1 = ON->prevPt;
    tmp2 = ON->pt;
    tmp1->pt = tmp2;
    if (tmp2 != NULL) {
        tmp2->prevPt = tmp1;
    }

}
void AddtoHN(Card** ptrHN, Card* ON) {
    Card* tmp;
    tmp = *ptrHN;

    if (tmp != NULL) {
        tmp->prevPt = ON;
        ON->prevPt = NULL;
        ON->pt = tmp;
    }
    *ptrHN = ON;
}
int CountNodes(Card* HN) {
    int i = 0;
    while (HN != NULL) {
        i++;
        HN = HN->pt;
    }
    return(i);
}
Card* BuildLinkedList(int N) {
    int i;
    Card* HN, * tmp,*tmp2;
    HN = (Card*)calloc(sizeof(Card), 1);
    tmp = HN;
    tmp->FaceValue = 1;
    strcpy(&tmp->Suit, "Hearts");
    tmp->prevPt = NULL;
    for (i = 2; i <= N; i++) {
        tmp->pt = (Card*)calloc(sizeof(Card), 1);
        tmp2 = tmp;
        tmp = tmp->pt;

        //Initializing Facevalue
        tmp->FaceValue = (i%13);
        if (i % 13 == 0) {
            tmp->FaceValue = 13;
        }

        //Initializing gamevalue of card
        if ((tmp->FaceValue <= 10) && (tmp->FaceValue >= 2)) {
            tmp->gameValue = tmp->FaceValue;
        }
        else if(tmp->FaceValue==1){
            tmp->gameValue = 11;
        }
        else {
            tmp->gameValue = 10;
        }

        //Initializing suit
        switch ((i - 1) / 13) {
        case 0:
            strcpy(&tmp->Suit, "Hearts");
            break;
        case 1:
            strcpy(&tmp->Suit, "Diamonds");
            break;
        case 2:
            strcpy(&tmp->Suit, "Clubs");
            break;
        case 3:
            strcpy(&tmp->Suit, "Spades");
            break;
        }

        tmp->prevPt = tmp2;
    }
    return(HN);
}
void ShuffleList(Card** ptrHN) {
    int i, j;
    Card* tmp,*HN;
    HN = *ptrHN;
    for (j = 0;j < 5000;j++) {
        i = (rand() % 51) + 2;
        HN = *ptrHN;

        tmp = ReturnNthNode(HN, i);
        RemovingCard(tmp);
        AddtoHN(ptrHN, tmp);
    }
}
Card* RemoveHN(Card** ptrHN) {
    Card* tmp,*tmp1;
    tmp = *ptrHN;
    tmp1 = tmp->pt;
    tmp->pt = NULL;
    if (tmp1 != NULL) {
        tmp1->prevPt = NULL;
    }
    *ptrHN = tmp1;
    return tmp;
}

//PRINT FUCNTIONS:
void ClearScreen() {
    printf("Press [Enter] to continue\n");
    getchar();
    getchar();
    system("cls");
}
void PrintEmptyCard(void) {
    printf(" _____\n");
    printf("|     |\n");
    printf("|     |\n");
    printf("|     |\n");
    printf("|     |\n");
    printf("|_____|\n");
    printf("\n");
}
void PrintCard(Card* ON) {
    if (ON != NULL) {
        if (ON->FaceValue == 10) {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  %d |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  %d |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  %d |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  %d |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
        else if (ON->FaceValue == 11) {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  J  |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  J  |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  J  |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  J  |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
        else if (ON->FaceValue == 12) {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  Q  |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  Q  |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  Q  |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  Q  |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
        else if (ON->FaceValue == 13) {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  K  |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  K  |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  K  |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  K  |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
        else if (ON->FaceValue == 1) {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  A  |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  A  |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  A  |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  A  |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
        else {
            if (!strcmp(ON->Suit, "Hearts")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x03    |\n");
                printf("|  %d  |\n", ON->FaceValue);
                printf("|    \x03|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Diamonds")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x04    |\n");
                printf("|  %d  |\n", ON->FaceValue);
                printf("|    \x04|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Clubs")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x05    |\n");
                printf("|  %d  |\n", ON->FaceValue);
                printf("|    \x05|\n");
                printf("|_____|\n");
            }
            else if (!strcmp(ON->Suit, "Spades")) {
                printf(" _____\n");
                printf("|     |\n");
                printf("|\x06    |\n");
                printf("|  %d  |\n", ON->FaceValue);
                printf("|    \x06|\n");
                printf("|_____|\n");
            }
        }
    }
    else {
        PrintEmptyCard();
    }
}
void PrintPlayerDeck(Player* X) {
    Card* tmp;
    tmp = *X->deck;
    printf("Player: %d\n", X->index);
    printf("Name: %s\n", X->Name);
    printf("Remaining Money: %d\n", X->money);
    printf("Hand value: %d\n", X->totVal);

    while (tmp != NULL) {
        PrintCard(tmp);
        tmp = tmp->pt;
    }
    printf("\n");
}
void PrintList(Card* HN) {
    Card* tmp;
    tmp = HN;
    while (tmp != NULL) {
        printf("%p **** Facevalue is %d\n", tmp, tmp->FaceValue);
        printf("%p **** suit is %s\n", tmp, tmp->Suit);
        tmp = tmp->pt;
    }

}
void PrintPlayerList(Player* List) {
    Player* tmp = NULL;
    tmp = List;
    while (tmp->ptr != NULL) {
        PrintPlayerDeck(tmp);
        tmp = tmp->ptr;
    }
    PrintPlayerDeck(tmp);

}
void RoundStats(int* round, int* pot, Card* stock, Card* discard, Player* X, Player* listOfPlayers)
{
    Player* tmp;

    printf("Round:%d\tpot:%d\n\n", *round, *pot);
    printf("Discard Pile:\n");
    PrintCard(discard);

    printf("Stock Pile:\n");
    PrintEmptyCard();

    if (X == NULL) {
        PrintPlayerList(listOfPlayers);
    }
    else {
        tmp = listOfPlayers;
        if (tmp == X) {
            PrintPlayerDeck(tmp);
        }
        else {
            printf("Player: %d\n", tmp->index);
            printf("Name: %s\n", tmp->Name);
            printf("Remaining Money: %d\n", tmp->money);
            printf("Hand value: -\n");
            PrintEmptyCard();
        }
        while (tmp->ptr != NULL) {
            tmp = tmp->ptr;
            if (tmp == X) {
                PrintPlayerDeck(tmp);
            }
            else {
                printf("Player %d:\n", tmp->index);
                printf("Name: %s\n", tmp->Name);
                printf("Remaining Money: %d\n", tmp->money);
                printf("Hand value: -\n");
                PrintEmptyCard();
            }
        }
    }
    printf("\n");
}

//PLAYER FUNCTIONS:
Player* ReturnNthPlayer(Player* HN, int N) {
    //Warning No Error checking
    int i = 1;
    while (i < N) {

        HN = HN->ptr;
        i++;
    }
    return HN;
}
Player* NextPlayer(Player* X, Player* ListOfPlayers) {
    Player* tmp;
    if (X->ptr == NULL) {
        X = ListOfPlayers;
    }
    else {
        X = X->ptr;
    }
    if (X->fold == 1) {
        if (X->ptr == NULL) {
            X = ListOfPlayers;
        }
        else {
            X = X->ptr;
        }
    }

    return X;
}
void AssignWinner(Player* list, int* pot, int* numWinners,int* winArr) {
    int i,tmp,share,rem;
    Player* P;

    if (*numWinners == 1) {
        tmp = winArr[0];
        P = ReturnNthPlayer(list, tmp);
        P->money = P->money + *pot;
        printf("Winner of the round is:\n");
        printf("Player %d: %s\n", P->index, P->Name);
    }
    else {
        share = (*pot) / (*numWinners);
        rem = *pot % (*numWinners);
        printf("Winners of the round are:\n");
        for (i = 0;i < *numWinners;i++) {
            tmp = winArr[i];
            P = ReturnNthPlayer(list, tmp);
            P->money = P->money + share;
            printf("Player %d: %s\n", P->index, P->Name);
        }
        i = 0;
        P = list;
        while (P->dealer != 1) {
            P = NextPlayer(P, list);
        }
        P = NextPlayer(P, list);
        while (rem != 0) {
            P->money++;
            rem = rem - 1;
            P = NextPlayer(P, list);
        }
    }
    ClearScreen();
}
Player* BuildPlayerList(int n) {
    int i;
    Player* HN, * tmp, * tmp2;
    char name[50];
    HN = (Player*)calloc(sizeof(Player), 1);
    tmp = HN;
    tmp->money = 100;
    tmp->totVal = 0;
    tmp->index = 1;
    tmp->dealer = 1;
    tmp->fold = 0;
    tmp->prevPtr = NULL;
    tmp->deck = (Player**)calloc(sizeof(Player*), 1);
    *tmp->deck = NULL;
    printf("Enter your name player %d:\n", tmp->index);
    scanf("%d");
    fgets(name, 50, stdin);
    while (strlen(name) == 1) {
        printf("Please enter a valid name:\n");
        fgets(name, 50, stdin);
    }
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    strcpy(tmp->Name, name);

    for (i = 2;i <= n;i++) {
        tmp->ptr = (Player*)calloc(sizeof(Player), 1);
        tmp2 = tmp;
        tmp = tmp->ptr;
        tmp->money = 100;
        tmp->totVal = 0;
        tmp->index = i;
        tmp->dealer = 0;
        tmp->fold = 0;
        tmp->prevPtr = tmp2;
        tmp->deck = (Player**)calloc(sizeof(Player*), 1);
        *tmp->deck = NULL;
        printf("Enter your name player %d:\n", tmp->index);
        scanf("%d");
        fgets(name, 50, stdin);
        while (strlen(name) == 1) {
            printf("Please enter a valid name:\n");
            fgets(name, 50, stdin);
        }
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }
        strcpy(tmp->Name, name);
    }
    return HN;
}
void HandVal(Player* X) {
    int t1, t2, t3, f1, f2, f3;
    int sum1=0, sum2=0, sum3=0, sum = 0;
    char c1[9], c2[9], c3[9];
    Card* tmp;

    tmp = *X->deck;
    t1 = tmp->gameValue;
    f1 = tmp->FaceValue;
    strcpy(c1, tmp->Suit);
    tmp = tmp->pt;
    t2 = tmp->gameValue;
    f2 = tmp->FaceValue;
    strcpy(c2, tmp->Suit);
    tmp = tmp->pt;
    t3 = tmp->gameValue;
    f3 = tmp->FaceValue;
    strcpy(c3, tmp->Suit);

    sum1 = t1;
    if (!strcmp(c1, c2)) {
        sum1 = sum1 + t2;
    }
    if (!strcmp(c1, c3)) {
        sum1 = sum1 + t3;
    }

    if (strcmp(c1, c2) != 0) {
        sum2 = t2;
        if (!strcmp(c2, c3)) {
            sum2 = sum2 + t3;
        }
    }

    if ((strcmp(c1, c2) != 0) && (!strcmp(c1, c3))) {
        sum3 = t3;
    }

    if (sum1 >= sum2) {
        sum = sum1;
        if (sum3 > sum1) {
            sum = sum3;
        }
    }
    else {
        sum = sum2;
        if (sum3 > sum2) {
            sum = sum3;
        }
    }

    if ((f1 == f2) && (f1 == f3)) {
        sum = 30;
    }

    X->totVal = sum;

}
//Min bet condition placed, fold option added
void PlayerBetRound(Player* X, int* pot, int* minbet) {
    int bet;


    printf("Place your bet greater than %d, or 0 for fold: ", *minbet);
    scanf("%d", &bet);
    while ((bet < *minbet)&&(bet!=0)) {
        printf("Please enter a valid bet:\n");
        scanf("%d", &bet);
    }

    if (bet == 0) {
        X->fold = 1;
    }
    X->money = X->money - bet;
    *pot = *pot + bet;
    if (bet > *minbet) {
        *minbet = bet;
    }
    
    ClearScreen();
}
Card* PlayerDrawRound(Player* X, Card** stock, Card** discard) {
    int choice;
    Card* tmpCard;
    Card* discardCard;
    printf("Choose: 1.Draw from Stock\t 2.Draw from Discard\n");

    scanf("%d", &choice);
    while (1) {
        if (choice == 1) {
            tmpCard = RemoveHN(stock);
            AddtoHN(X->deck, tmpCard);
            discardCard = NULL;
            break;
        }
        else if (choice == 2) {
            tmpCard = RemoveHN(discard);
            AddtoHN(X->deck, tmpCard);
            discardCard = tmpCard;
            break;
        }
        else {
            printf("Invalid choice. Please select again.\n");
            scanf("%d", &choice);
        }
        
    }

    if (*stock == NULL) {
        *stock = *discard;
        *discard = NULL;
        tmpCard = RemoveHN(stock);
        AddtoHN(discard, tmpCard);

        printf("Stock reshuffled from the cards in discard pile.\n");
    }

    ClearScreen();
    
    return discardCard;
}
//Restriction on discard added, knock option added
void PlayerDiscardRound(Player* X, Card** discard, Card* discardCard) {
    int choice;
    bool b;
    char c;
    Card* tmpCard;
    printf("Choose the card you want to discard (1 is the leftmost card and 4 is the rightmost:\n");
    scanf("%d", &choice);
    while (1) {
        if ((choice >= 1) && (choice <= 4)) {
            break;
        }
        else {
            printf("Please select a valid card.\n");
            scanf("%d", &choice);
        }
    }

    while (1) {
        if (choice == 1) {
            tmpCard = *X->deck;
            if (tmpCard == discardCard) {
                printf("You cannot discard the card picked up from discard pile.\n");
            }
            else {
                tmpCard = RemoveHN(X->deck);
                AddtoHN(discard, tmpCard);
                X->totVal = X->totVal + tmpCard->gameValue;
                break;
            }
        }
        else {
            tmpCard = ReturnNthNode(*X->deck, choice);
            if (tmpCard == discardCard) {
                printf("You cannot discard the card picked up from discard pile.\n");
            }
            else {
                RemovingCard(tmpCard);
                X->totVal = X->totVal + tmpCard->gameValue;
                AddtoHN(discard, tmpCard);
                break;
            }
        }

        printf("Please select a valid card.\n");
        scanf("%d", &choice);
    }
    HandVal(X);

    ClearScreen();

}
Player* PlayerWinCheck(Player* X, int* round, int* pot) {
    Player* tmp = NULL;
    bool b = 0;
    if (X->totVal == 31) {
        *round++;
        X->money = X->money + (*pot);
        pot = 0;
        b = 1;
        tmp = X;
    }
    return tmp;
} 
void DealCards(Player* ListOfPlayers, Card** stock, Card** discard) {
    int i;
    Player* tmpP, * dealer;
    Card* tmp;
    tmpP = ListOfPlayers;
    while (tmpP->dealer != 1) {
        tmpP = tmpP->ptr;
    }
    dealer = tmpP;
    if (tmpP->ptr == NULL) {
        tmpP = ListOfPlayers;
    }
    else {
        tmpP = tmpP->ptr;
    }

    for (i = 0;i < 3;i++) {
        tmp = RemoveHN(stock);
        AddtoHN(tmpP->deck, tmp);
    }
    HandVal(tmpP);

    while (tmpP->dealer != 1) {
        if (tmpP->ptr == NULL) {
            tmpP = ListOfPlayers;
        }
        else {
            tmpP = tmpP->ptr;
        }

        for (i = 0;i < 3;i++) {
            tmp = RemoveHN(stock);
            AddtoHN(tmpP->deck, tmp);
            tmpP->totVal = tmpP->totVal + tmp->gameValue;
        }
        HandVal(tmpP);
    }

    if (tmpP->ptr == NULL) {
        tmpP = ListOfPlayers;
    }
    else {
        tmpP = tmpP->ptr;
    }
    tmpP->dealer = 1;
    dealer->dealer = 0;

    AddtoHN(discard, RemoveHN(stock));

}
void EmptyHands(Player* listOfPlayers, Card** stock, Card** discard) {
    Player* tmp;
    int i;
    tmp = listOfPlayers;
    for (i = 0;i < 3;i++) {
        AddtoHN(stock, RemoveHN(tmp->deck));
    }
    while (tmp->ptr != NULL) {
        tmp = tmp->ptr;
        for (i = 0;i < 3;i++) {
            AddtoHN(stock, RemoveHN(tmp->deck));
        }
    }

    while (*discard != NULL) {
        AddtoHN(stock, RemoveHN(discard));
    }
}
void EliminatePlayers(Player** list) {
    Player* tmp, * tmp1;
    tmp = *list;

    while (tmp->ptr != NULL) {
        tmp = tmp->ptr;
        if (tmp->money == 0) {
            tmp1 = tmp->prevPtr;
            tmp1->ptr = tmp->ptr;
            tmp1 = tmp->ptr;
            tmp1->prevPtr = tmp->prevPtr;
            tmp->ptr = NULL;
            tmp->prevPtr = NULL;
        }
    }

    tmp = *list;
    if (tmp->money == 0) {
        *list = tmp->ptr;
        tmp->ptr = NULL;
        tmp1 = *list;
        tmp1->prevPtr = NULL;
    }

}
void PlayRound(Player* listOfPlayers, Player* Dealer, int* pot, int* minBet, Card** stockPile, Card** discardPile, int* round) {
    Player* tmp, * tmp1;
    Card* tmpCard;
    int* winIndexArr;
    winIndexArr = (int*)calloc(sizeof(int), 1);
    int maxVal, numWinners=0,i;
    char c;
    int knock = 0;
    tmp = NextPlayer(Dealer,listOfPlayers);
    
    while (tmp != Dealer) {
        RoundStats(round, pot, *stockPile, *discardPile, tmp, listOfPlayers);//displays cards of the player
        PlayerBetRound(tmp, pot, minBet);//plays bet round, may fold
        tmp = NextPlayer(tmp, listOfPlayers);
    }

    RoundStats(round, pot, *stockPile, *discardPile, tmp, listOfPlayers);//displays cards of the player
    PlayerBetRound(tmp, pot, minBet);
    tmp = NextPlayer(tmp, listOfPlayers);

    if (tmp == NextPlayer(tmp, listOfPlayers)) {
        numWinners = 1;
        winIndexArr[0] = tmp->index;
        AssignWinner(listOfPlayers, pot, &numWinners, winIndexArr);
    }
    else {
        while (1) {
            if (tmp->fold == 0) {
                RoundStats(round, pot, *stockPile, *discardPile, tmp, listOfPlayers);
                tmpCard = PlayerDrawRound(tmp, stockPile, discardPile);//player draws round
                RoundStats(round, pot, *stockPile, *discardPile, tmp, listOfPlayers);
                //Place restriction on discard
                PlayerDiscardRound(tmp, discardPile, tmpCard);//plays discard round, here check for 31, and condition for knock
                RoundStats(round, pot, *stockPile, *discardPile, tmp, listOfPlayers);

                if (tmp->totVal == 31) {
                    numWinners = 1;
                    winIndexArr[0] = tmp->index;
                    break;
                }

                printf("Are you comfortable with your hand and want to knock?(y/n)\n");
                scanf("%c", &c);
                while ((c != 'y') && (c != 'n')) {
                    printf("Please enter a valid response.\n");
                    scanf("%c", &c);
                }
                if (c == 'y') {
                    knock = 1;
                    ClearScreen();
                    break;
                }
                ClearScreen();
            }
            tmp = NextPlayer(tmp, listOfPlayers);
        }
    }

    if (knock==1) {
        maxVal = tmp->totVal;
        winIndexArr[0] = tmp->index;
        numWinners = 1;
        tmp1 = NextPlayer(tmp, listOfPlayers);
        while (tmp1 != tmp) {
            RoundStats(round, pot, *stockPile, *discardPile, tmp1, listOfPlayers);
            tmpCard = PlayerDrawRound(tmp1, stockPile, discardPile);
            //add code for empty stock
            RoundStats(round, pot, *stockPile, *discardPile, tmp1, listOfPlayers);
            PlayerDiscardRound(tmp1, discardPile,tmpCard);//plays discard round
            RoundStats(round, pot, *stockPile, *discardPile, tmp1, listOfPlayers);

            if (tmp1->totVal == 31) {
                winIndexArr = (int*)realloc(winIndexArr, sizeof(int));
                winIndexArr[0] = tmp1->index;
                numWinners = 1;
                break;
            }
            
            if (tmp1->totVal > maxVal) {
                winIndexArr = (int*)realloc(winIndexArr, sizeof(int));
                winIndexArr[0] = tmp1->index;
                numWinners = 1;
            }
            else if (tmp1->totVal == maxVal) {
                numWinners++;
                winIndexArr = (int*)realloc(winIndexArr, (numWinners)*sizeof(int));
                winIndexArr[numWinners - 1] = tmp1->index;
            }

            tmp1 = NextPlayer(tmp1, listOfPlayers);
        }
        AssignWinner(listOfPlayers, pot, &numWinners, winIndexArr);
    }
    
    //incremetn round
    *round++;
    *pot = 0;
    //empty the hands of players and discard
    EmptyHands(listOfPlayers, stockPile, discardPile);
    //reshuffle deck
    ShuffleList(stockPile);
    //check if any player has 0 money
    EliminatePlayers(&listOfPlayers);
    //reset fold attribute
    tmp = listOfPlayers;
    tmp->fold = 0;
    while (tmp->ptr != NULL) {
        tmp = tmp->ptr;
        tmp->fold = 0;
    }   
}


