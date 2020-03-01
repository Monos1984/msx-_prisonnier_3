/*******************************************************
* Programme ...... : Prisonnier III
********************************************************
* Nom ............ : scene_credit.c
* Auteur ......... : Monos
********************************************************
* Note ...........  : Le Fichier Scene_Game ne doit pas 
                      contenir de fonction propre
                      au api pour faciliter le portage 
											du jeu !!!
*********************************************************/


// ====================
// * Fichier Includes *
// ====================
#include "header\game.h"

// ==========================
// ** Procedure scene_game **
// ==========================
void scene_credit (void)
{
	// -------------------------------------
	// * Déclaration des variables locales *
	// -------------------------------------
	unsigned char i=0;
	
	HideDisplay();
	Cls();
		
		create_windows(0,0,32,26,0);
		PutText(72, 8,"PRISONNIER III");
		PutText(8, 16,"------------------------------");
		PutText(8, 24,"AUTEUR.......: Emmanuel Lorand");
		PutText(8, 32,"STUDIO.......: Offgame");
		PutText(8, 40,"EDITEUR......: Offgame");
		PutText(8, 48,"PROGRAMMEUR..: Jean Monos");
		PutText(8, 56,"GRAPHISMES...: Monos,Stuart");
		PutText(8, 64,"MUSIQUES.....: ...............");
		PutText(8, 72,"------------------------------");
		PutText(8, 80,"SDK..........: FUSION C");
		PutText(8, 88,".............: Eric Boez");
		PutText(8, 96,".............: Fernando Garcia");
		PutText(8,104,"------------------------------");
		
	 ShowDisplay();
   while (scene_get() == SCENE_CREDIT)
	{
		i++;
		if (i<6)
		{
			PutText(8, 180,"..... Space for Menu .....");
		}
		
		else if (i>6 && i<12)
		{
			PutText(8, 180,"                          ");
		}
		
		if (i>11)
		{
		 i=0;
		}
		
		if (TriggerRead(0) == 255)
		{
			HideDisplay();
			scene_set( SCENE_TITLE_SCREEN);
		}
	
	}
		
}