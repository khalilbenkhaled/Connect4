#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define SQUARE_SIZE 55

#define nb_colonnes 8
#define nb_lignes 7
#define PLAYER1 0
#define PLAYER2 1


#define RUNNING 0
#define PLAYER1_WON 1
#define PLAYER2_WON 2
#define TIE 3


#define ROUGE 1
#define JAUNE 2
#define VIDE 0
/*
typedef enum {
  ROUGE, JAUNE, VIDE
}case;
*/
typedef struct {
  int state;
  int player;
  int board[nb_lignes][nb_colonnes];
  SDL_Surface* grille;
  SDL_Surface* rouge;
  SDL_Surface* jaune;

  SDL_Rect pos_grille;
  SDL_Rect pos_jaune;
  SDL_Rect pos_rouge;
}game;


game initialiser(game g);
void afficherGrille(game g,SDL_Surface* screen);
void click(game* g,int j);
int PlayerXWon(game g,int player);
void GameOver(game* g);
void SwitchPlayer(game* g);
int ia(game g);



int BestMove(game g);
int minimax(game g);
