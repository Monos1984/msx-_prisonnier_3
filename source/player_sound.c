/*******************************************************
* Nom ......... : tools.c
* Role ........ : Fonctions divers.
********************************************************/

// =====================
// ** Fichier include **
// =====================
#include "header/game.h"
#include "header/ayfx_player.h"
#include "header/io.h"





// =============================
// * Initation d'un fichier fx *
// =============================
void init_fx_sound(unsigned int* nom_fichier, unsigned int size_file)
{
	 unsigned int id_files;
	 FCBlist *FCB = FCBs();
	 id_files=Open(nom_fichier,O_RDWR);
	 afbdata = MMalloc(size_file); 
	 Read(id_files,afbdata,size_file);
	 Close(id_files);		
	 InitPSG();
   InitFX();
}

// =============================
// * Jouer un son              *
// =============================
void play_sound(unsigned char id)
{
	PlayFX(id);
	update_sound();
}


// =============================
// * Update_sound              *
// =============================
void update_sound()
{
		// ==============
		// * Update Son *
		// ==============			
		while (TestFX()==1)
		{
			if (JIFFY!=0)
			{
				JIFFY=0;
				UpdateFX();
				
			}
		}
	
}

// =============================
// * Free_sound                *
// =============================
void free_sound()
{
	FreeFX;
	
}