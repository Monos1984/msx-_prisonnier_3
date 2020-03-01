/*******************************************************
* Nom ............ : main.c
* Role ........... : Fichier de départ de tout programme C
* Auteur ......... : Monos
* Version ........ : V1.0 du 27/01/2018
* Modification ... : 28/01/2018
* Licence ........ : ....
* Compilateur .... : SDCC
* Version Devkit.. : 
* Cible .......... : MSX 2 et plus
********************************************************
* Programme ...... : Prisonnier
* Auteur ......... : Jean Monos, Capitaine Caverne
* Programmeur .... : Jean Monos
* Graphiste ...... :
* Musicien ....... :
* Divers ......... :  (Fusion C),
********************************************************
* Le Fichier Main du programme qui à pour but de lancer
* le programme.
*******************************************************/

// =====================
// ** Fichier include **
// =====================
#include "header/game.h"


void MSX_wait(int cicles)
{
  int i;
  for(i=0;i<cicles;i++) 
    {
      Halt();
    }
}

// ====================
// ** Procedure main **
// ====================
void main(void) 
{
	// * Initation des variables main * //
	int seconde_a=0;
	int seconde_b=0;	
	TIME tm; 
	

	// ---------------------------
	// * Initiation du programme *
	// ---------------------------
	scene_set(SCENE_INIT);
	
	while(1)
	{
		// ---------------------------
		// * Initiation du programme *
		// ---------------------------
	  if (scene_get() == SCENE_INIT)
		{
						
			// Passer le CPU sur le Z-80 si c'est un msx Turbo_R
			if(ReadMSXtype()==3)  
			{
				ChangeCPU(0);
			}
			
			Screen(8); 
			
      HideDisplay(); 
			KeySound(0); 
			VDP50Hz(); 
			SetColors(C_ECRITURE,C_FOND,C_BORDURE); 
			Cls(); 
		scene_set( SCENE_TITLE_SCREEN);
				// scene_set( SCENE_SPLASH);	
		 	
		}
		
		// ---------------------
		// * Ecran Splash...   *
		// ---------------------
	  else if (scene_get() == SCENE_SPLASH)
		{
		  ShowDisplay();	
		  HMMC (logo, 64, 84, 128, 24 );
		  GetTime(&tm);
		  seconde_a=tm.sec;
			
			while (scene_get() == SCENE_SPLASH)
			{
				GetTime(&tm);
				seconde_b=tm.sec;
				// (seconde_a+1)<seconde_b || 
				if(TriggerRead(0)==255)
				{
					 scene_set( SCENE_TITLE_SCREEN);
				}
								
			}
			
		}
		
		// ---------------------
		// * Ecran Titre...    *
		// ---------------------
	  else if (scene_get() == SCENE_TITLE_SCREEN)
		{
		
			title_screen();
		
		}
		
		// ---------------------
		// * Jeu ...           *
		// ---------------------
	  else if (scene_get() == SCENE_GAME)
		{
			scene_game();
			
		}
		
		// ---------------------
		// * Credit ...           *
		// ---------------------
	  else if (scene_get() == SCENE_CREDIT)
		{
			scene_credit();
		}
		
		
	} // Fin de la boucle du jeu !
	
}

void wait_vbl()
 {
	while(IsVsync()==0){}	 
 }
 


 
 
 