#include "fonctions.h"

game initialiser(game g){
  g.state=RUNNING;
  g.player=PLAYER1;

  for(int i=0;i<nb_lignes;i++){
    for(int j=0;j<nb_colonnes;j++){
      g.board[i][j]=VIDE;
    }
  }

  g.grille=IMG_Load("image/cadre.png"); //grille
   g.jaune=IMG_Load("image/jaune.png"); //jaune
   g.rouge=IMG_Load("image/rouge.png"); //rouge
  g.pos_grille.x=0;
  g.pos_grille.y=0;

  g.pos_rouge.x=0;
  g.pos_rouge.y=0;

  g.pos_jaune.x=0;
  g.pos_jaune.y=0;
        return g;
}

void afficherGrille(game g,SDL_Surface* screen){
  SDL_BlitSurface(g.grille,NULL,screen,&g.pos_grille);
  for(int i=0;i<nb_lignes;i++){
    for(int j=0;j<nb_colonnes;j++){
      if (g.board[j][i]==ROUGE){
        g.pos_rouge.x=SQUARE_SIZE*i+10; //+10 to move it a bit to the right
        g.pos_rouge.y=SQUARE_SIZE*j+10; // ..
        SDL_BlitSurface(g.rouge,NULL,screen,&g.pos_rouge);
      }
      else if (g.board[j][i]==JAUNE){
        g.pos_jaune.x=SQUARE_SIZE*i+10; // ..
        g.pos_jaune.y=SQUARE_SIZE*j+10; // ..
        SDL_BlitSurface(g.jaune,NULL,screen,&g.pos_jaune);
      }

    }
  }
  //ADD GAME OVER DISPLAY
}
void click(game* g,int j){
int i;

if (g->state==RUNNING){
  for(i=nb_lignes-1;i>=0;i--){
    if(g->board[i][j]==VIDE){
      if (g->player==PLAYER1) g->board[i][j]=ROUGE;
      else if (g->player==PLAYER2) g->board[i][j]=JAUNE;
            break;
 }
}
    GameOver(g);
    SwitchPlayer(g);
  }
}

void GameOver(game* g){
  if (PlayerXWon(*g,ROUGE)==1) g->state=PLAYER1_WON;
  else if (PlayerXWon(*g,JAUNE)==1) g->state=PLAYER2_WON;
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
int i;
int j;
  for(i=0;i<nb_lignes;i++){
    for(j=0;j<nb_colonnes;j++){
        if (g.board[i][j]==player&&g.board[i][j+1]==player&&g.board[i][j+2]==player&&g.board[i][j+3]==player) //check colonne
            return 1;
        if (g.board[i][j]==player&&g.board[i+1][j]==player&&g.board[i+2][j]==player&&g.board[i+3][j]==player) // check ligne
            return 1;
        if (g.board[i][j]==player&&g.board[i+1][j+1]==player&&g.board[i+2][j+2]==player&&g.board[i+3][j+3]==player) //check diagonale1
            return 1;
        if (g.board[i][j]==player&&g.board[i-1][j+1]==player&&g.board[i-2][j+2]==player&&g.board[i-3][j+3]==player) //check diagonale 2
            return 1;
    }
  }
  return 0;
}



void SwitchPlayer(game* g){
  if (g->player==PLAYER1) g->player=PLAYER2;
  else if (g->player==PLAYER2) g->player=PLAYER1;
}


int ia(game g){
  int meilleur[20];
  for (int i=0;i<20;i++){
    meilleur[i]=-1;     //INITIALISATION DU TABLEAU MEILLEUR
  }

for (int j=0;j<nb_colonnes;j++){
  for(int i=0;i<nb_lignes;i++){
    if (g.board[i][j]==VIDE){
      meilleur[j]=1;
    }
  }
} //FINDING ALL POSSIBLE MOVES AND PTTING THEM IN A TABLE

int tmp;
for(int j=0;j<nb_colonnes;j++){
  for (int i=0;i<nb_lignes;i++){
    if (meilleur[j]==1){
      tmp=g.board[i][j];
      g.board[i][j]=ROUGE;
      if (PlayerXWon(*g,ROUGE)==1){
        g.board[i][j]=tmp;
        return j;
      }
    g.board[i][j]=JAUNE;
    if (PlayerXWon(*g,JAUNE)==1){
      g.board[i][j]=tmp;
      return j;
      }
    }
  }

} //BCH NABDEl EL CASE MTAA EL MATRICE, NAAYET L GAMEOVER ncrhouf est ce que el jeu wfet walet, ken el jeu wfet ray heki ahsen move w baaed nrajaa kol chay kima ken

}
