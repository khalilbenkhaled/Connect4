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


int ia(game g)
{
int indice;
int score[nb_colonnes];
int i,j,x;
int count=1;
int max;
for(int k=0;k<nb_colonnes;k++)
{
score[k]=0;

}

for(j=0;j<nb_colonnes;j++)
{
for(i=nb_lignes-1;i>0;i--)
{
if(g.board[i][j]==VIDE)
{
x=i;
printf("\n%d  xxx",x);
if(x==nb_lignes-1)
{

score[j]=count;
count=0;


break;



}
else
{
do
{
x++;
count++;


}while((g.board[x][j]==g.board[x+1][j])&&(x<8));


score[j]=count;
count=0;


break;










}









}
}

}
max=0;
for(i=0;i<nb_colonnes;i++)
{
if (score[i]>=max)
{
max=score[i];
indice=i;
}

}
for(int k=0;k<nb_colonnes;k++)
{
printf("\n%d\n",score[k]);

}

return indice;
}



/*int minimax(game g,int depth){

  int score[nb_colonnes];
      for (int i=0;i<nb_colonnes;i++){      //initialisation of the table of scores
      score[i]=-100;
    }

    for(int j=0;i<nb_colonnes;j++){
      score[j]=boardscore(g,j);
    }
int max=-1000;
int colonne=-1;
    for(int i=0;i<nb_colonnes;i++){
        if (score[i]>max) {
          max=score[i];
          colonne=i;
        }
    }
    //colonne is the best move of this position
      for (int i=nb_lignes-1;i<=0;i--){         //playing the best found move in the position in order to check again
        if (g.board[i][colonne]=VIDE){
          if (g.player==PLAYER1) g.board[i][colonne]=ROUGE;
          else g.board[i][colonne]=JAUNE;
        }

      }
    //THE TRICKY PART
    if (depth==0)
        return colonne;
    else {
      SwitchPlayer(&g);
      colonne=minimax(g,depth-1);
    }
}
*/
int BestMove(game g){
  int BestScore=-100000;
  int move=-1;
  for(int j=0;j<nb_colonnes;j++){
    for(int i=nb_lignes-1;i>=0;i--){
      if (g.board[i][j]==VIDE){
        g.board[i][j]=JAUNE;
        int score=minimax(g,0);
        if(score>BestScore) {
          BestScore=score;
          move=j;
          //if any bugs undo the move after playing and getting the socre

        }
        break;
      }
    }
  }
  return move;
}
int minimax(game g,int depth){

  GameOver(&g);
  if (g.state!=RUNNING){
    int score;
    if (g.state==PLAYER1_WON) score=10;
    else if (g.state==PLAYER2_WON) score=-10;
    else if (g.state==TIE) score=0;
    return score;
  }
if (g.player==PLAYER2){
  int BestScore=-100000;
  for(int j=0;j<nb_colonnes;j++){
    for(int i=nb_lignes-1;i>=0;i--){
      if (g.board[i][j]==VIDE){
        g.board[i][j]=JAUNE;
         SwitchPlayer(&g);
        int score=minimax(g,depth+1);
        if(score>BestScore) {
          BestScore=score;
          //if any bugs undo the move after playing and getting the socre
        }
        break;
      }
    }
  }
  return BestScore;
}
else{
  int BestScore=100000;
  for(int j=0;j<nb_colonnes;j++){
    for(int i=nb_lignes-1;i>=0;i--){
      if (g.board[i][j]==VIDE){
        g.board[i][j]=ROUGE;
        SwitchPlayer(&g);
        int score=minimax(g,depth+1);
        if(score<BestScore) {
          BestScore=score;
          //if any bugs undo the move after playing and getting the socre
        }
        break;
      }
    }
  }
  return BestScore;
}





}
