/*******************************************************
* Nom ......... : title_screen.c
* Role ........ : Gestion de l'écran titre et option
********************************************************/

// =====================
// ** Fichier include **
// =====================
#include "header/game.h"

// * Define de placement de texte *
#define CADRE_X 0
#define CADRE_Y 120-8


#define OPTION_PY CADRE_Y+8

#define TP1_PX CADRE_X+8
#define TP1_PY CADRE_Y+24

#define TP2_PX TP1_PY 
#define TP2_PY TP1_PY+8


extern s_player player[2];
void draw_text_ecran(unsigned char C1, unsigned char C2,unsigned char sound);




// ============================
// ** Procedure Title screen **
// ============================
void title_screen()
{
	static unsigned char c1=0; // Paramètrage des commandes du joueur 1
	static unsigned char c2=1; // Paramètrage des commandes du joueur 2

	
	

  SpriteOff();
	free_sound();

	// ==================================
	// * Chargement du fichier sound fx *
	// ==================================

  init_fx_sound("scurseur.afb", 40);
		MSX_wait(24);
	// ==========================
	// * Préparation de l'écran *
	// ==========================
	 Cls();
	PutText(62, 0 ,"PRISONNIER III");

	create_windows(CADRE_X,CADRE_Y,32,8,0);
	
	PutText(80, OPTION_PY,"GAME OPTION"); 	
	PutText(8, CADRE_Y+40,"(3) Credit");
	PutText(8, CADRE_Y+48,"(Space) Start the Game");
	
	PutText(160,192-8,"Offgame 2019");
	PutText(0,192-8,"V D0.0.4");
	draw_text_ecran(c1,c2,0);
		
	ShowDisplay();
	// -----------------------------------
	// * Boucle de la scene Title Screen *
	// ------------------------------------
	while(scene_get() == SCENE_TITLE_SCREEN)
	{

		// ======================
		// * Gestion du clavier * 
		// ======================
		switch(Inkey())
		{						
			// ---------------------
			// * Touche (1) ou (&) *
			// ---------------------
			case (49):
			case (38):
				c1++;
				if (c1>3)
				{
					
					c1=0;
				}
				// play_sound(1);
				draw_text_ecran(c1,c2,1);
				
			break;
			
			// ---------------------
			// * Touche (2) ou (é) *
			// ---------------------
			case (50):					
			case (130):
				
				c2++;
				if (c2>3)
				{
					c2=0;
				}
			// 	play_sound(1);
				draw_text_ecran(c1,c2,1);	 
			
			break;
			
			// ---------------------
			// * Touche (3) ou (") *
			// ---------------------
			case (51):					
			case (34):
				
				play_sound(1);
				scene_set( SCENE_CREDIT);
			break;
		}	// Fin du switch option	
	
		
		// ==========================
    // * Lancement de la partie *			
		// ==========================
		if (TriggerRead(0)==255)
		{	
			play_sound(2);
			
			player[0].id_controle = c1;
			player[1].id_controle = c2;
		  scene_set( SCENE_GAME);
	  }
				

		
				
	}// Boucle principale principale de l'écran titre.
	
} // Fin de fonction de l'écran titre

void draw_text_ecran(unsigned char c1, unsigned char c2,unsigned char sound)
{
	if (sound == 1)
	{  
		play_sound(1);
	}
	// ============
	// * Player 1 *
	// ============
		
	switch(c1)
	{
	
		case 0:
			PutText(CADRE_X+8, CADRE_Y+24,"(1)Player 1 :...Keyboard");
		break;
		
		case 1:
			PutText(CADRE_X+8, CADRE_Y+24,"(1)Player 1 :.....Port 1");
		break;
		
		case 2:
			PutText(CADRE_X+8, CADRE_Y+24,"(1)Player 1 :.....Port 2");
		break;
			
		case 3:
			PutText(CADRE_X+8, CADRE_Y+24,"(1)Player 1 :...Computer");
		break;
	}
		
	// ============
	// * Player 2 *
	// ============
	switch(c2)
	{
		case 0:
			PutText(CADRE_X+8, CADRE_Y+32,"(2)Player 2 :...Keyboard");
		break;
		
		case 1:
			PutText(CADRE_X+8, CADRE_Y+32,"(2)Player 2 :.....Port 1");
		break;
		
		case 2:
			PutText(CADRE_X+8, CADRE_Y+32,"(2)Player 2 :.....Port 2");
		break;
			
		case 3:
			PutText(CADRE_X+8, CADRE_Y+32,"(2)Player 2 :...Computer");
		break; 
	}
	
	
	
	
}

