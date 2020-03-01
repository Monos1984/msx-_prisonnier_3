/*******************************************************
* Nom ......... : windows.c
* Role ........ : Gestion de la boite de dialogue
********************************************************/

// =====================
// ** Fichier include **
// =====================
#include "header/game.h"



// =============================
// ** Procedure creat windows **
// =============================
void create_windows(unsigned char px,unsigned char py,unsigned char tx,unsigned char ty,unsigned char background)
{
	unsigned char i;
	unsigned char j;
	;
	tx--;
	ty--;
	
		// * Création des coins *
			HMMC (windows_up_left, px, py, 8,8);
			HMMC (windows_down_left, px, py+(ty<<3), 8,8);
			HMMC (windows_up_right, px+(tx<<3),py, 8,8);
			HMMC (windows_down_right, px+(tx<<3),py+(ty<<3), 8,8);
	
	
	  // * Création des bordures latéral Gauche et Droite
		for (i=1;i<ty;i++)
		{
			HMMC (windows_left, px,(i<<3)+py, 8,8);
			HMMC (windows_right, (tx<<3)+px,(i<<3)+py, 8,8);
		}
		
		// * Création des bordures horizontales
		for(i=1;i<tx;i++)
		{
				HMMC (windows_up, (i<<3)+px, py, 8,8);
				HMMC (windows_down,(i<<3)+px,(ty<<3)+py, 8,8);
		}

		if (background==1)
		{
			for(j=1;j<ty;j++)
			{
				for(i=1;i<tx;i++)
				{
					HMMC (windows_background, (i<<3)+px, (j<<3)+py, 8,8);
				}
			}
		
		}
			
		
			
		
			
		
	
	
	
	
	
	
	

	
	
	
	
	
}