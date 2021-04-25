#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#define SQUARE_SIZE 50

#define nb_colonnes 7
#define nb_lignes 6
#define PLAYER1 0
#define PLAYER2 1


#define RUNNING 0
#define PLAYER1_WON 1
#define PLAYER2_WON 2
#define TIE 3


typedef enum {
  ROUGE, JAUNE, VIDE
}case;

typedef struct {
  int state;
  int player;
  int board[nb_colonnes][nb_lignes];
  SDL_Surface* grille;
  SDL_Surface* rouge;
  SDL_Surface* jaune;

  SDL_Rect pos_grille;
  SDL_Rect pos_jaune;
  SDL_Rect pos_rouge;
}game;


game initialiser(game g);
void afficherGrille(game g,SDL_Surface* screen);
void click(game* g,int i,int j);
int PlayerXWon(game g,int player);
void GameOver(game* g);
void SwitchPlayer(game* g);
