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
