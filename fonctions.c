#include "fonctions.h"

game initialiser(game g){
  g.state=RUNNING;
  g.player=PLAYER1.
  for(int i=0;i<nb_lignes;i++){
    for(int j=0;i<nb_colonnes;j++){
      g.board[i][j]=Vide;
    }
  }

  g.grille=IMG_Load("DESTINATION"); //CHANGE LATER WITH IMAGE
  g.pos_grille.x=0;
  g.pos_grille.y=0;
        return g;
}

void afficherGrille(game g,SDL_Surface* screen){
  SDL_BlitSurface(g.grille,NULL,screen,&g.pos_grille);
  for(int i=0;i<nb_lignes;i++){
    for(int j=0;j<nb_colonnes<j++){
      if (g.board[i][j]==ROUGE){
        g.pos_rouge.x=SQUARE_SIZE*i;
        g.pos_jaune.y=SQUARE_SIZE*j;
        SDL_BlitSurface(g.rouge,NULL,screen,&g.pos_rouge);
      }
      else if (g.board[i][j]==JAUNE){
        g.pos_jaune.x=SQUARE_SIZE*i;
        g.pos_jaune.y=SQUARE_SIZE*j;
        SDL_BlitSurface(g.rouge,NULL,screen,&g.pos_jaune);
      }

    }
  }
  //ADD GAME OVER DISPLAY
}
void click(game* g,int i,int j){
if (g->state==RUNNING){
  if (g->board[i][j]==VIDE){
    if (g->player==PLAYER1) g->board[i][j]=ROUGE;
    else if (g->player==PLAYER2) g->board[i][j]=jaune;
    SwitchPlayer(g);
    GameOver(g);
    }
  }
}





void GameOver(game* g){
  if (PlayerXWon(*g,PLAYER1)==1) g->state=PLAYER1_WON;
  else if (PlayerXWon(*g,PLAYER2)==1) g->state=PLAYER2_WON;
  //not enough cells
  int count=0;
  for(int i=0;i<nb_lignes;i++){
    for (int j=0;j<nb_colonnes;j++){
      if (g->board[i][j]!=VIDE) count++;
    }
  }
  if (count==nb_lignes*nb_colonnes) g->state=TIE;
}

int PlayerXWon(game g,int player){
  for(i=0;i<nb_lignes;i++){
    for(j=0;j<nb_colonnes;j++){
        if (g.board[i][j]==player&&g.boar[i][j+1]==player&&g.boar[i][j+2]==player&&g.boar[i][j+3]==player) //check colonne
            return 1;
        if (g.boar[i][j]==player&&g.boar[i+1][j]==player&&g.boar[i+2][j]==player&&g.boar[i+3][j]==player) // check ligne
            return 1;
        if (g.boar[i][j]==player&&g.boar[i+1][j+1]==player&&g.boar[i+2][j+2]==player&&g.boar[i+3][j+3]==player) //check diagonale1
            return 1;
        if (g.boar[i][j]==player&&g.boar[i-1][j+1]==player&&g.boar[i-2][j+2]==player&&g.boar[i-3][j+3]==player) //check diagonale 2
            return 1;
    }
  }
  return 0;
}



void SwitchPlayer(game* g){
  if (g->player==PLAYER1) g->player=PLAYER2;
  else if (g->player==PLAYER2) g->player=PLAYER1;

}
