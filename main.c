#include "fonctions.h"
int main()
{


//init screen
 SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("\n erreur init du video: %s",SDL_GetError());
        SDL_Quit();
        return 1;
    }

//declaration du screen
  SDL_Surface *screen=NULL;
screen= SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen==NULL)
    {
        printf("\n erreur init du screen: %s",SDL_GetError());
        return 1;
    }


game g;

int h;
g=initialiser(g);

int loop=1; //(gameloop)

//boucle du jeu
while(loop)
{

afficherGrille(g,screen);

//events
SDL_Event event;


if(SDL_PollEvent(&event))
{
switch(event.type)
{
//quiter
case SDL_QUIT:
loop=0;


//click
case SDL_MOUSEBUTTONDOWN:
if (g.player==PLAYER1) click(&g,event.button.x/SQUARE_SIZE);
break;

}//end switch
}//end events
if (g.player==PLAYER2){
  int j;
  j=ia(g);
  click(&g,j);
} 


 SDL_Flip(screen);
}//fin boucle

 SDL_Quit;

     //on quitte la SDL
    return 0;
}
