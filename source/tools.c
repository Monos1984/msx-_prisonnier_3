/*******************************************************
* Nom ......... : tools.c
* Role ........ : Fonctions divers.
********************************************************/

// =====================
// ** Fichier include **
// =====================
#include "header/game.h"
#include "header/ayfx_player.h"
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
}



// =======================
// * Procedure halt_wait *
// =======================
void halt_wait(int cicles)
{
  int i;
  for(i=0;i<cicles;i++) 
  {
    EnableInterupt()
    Halt();
  }  
}


