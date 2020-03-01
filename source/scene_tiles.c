/*******************************************************
* Nom ............ : scene_tiles.c
* Auteur ......... : Monos
* Version ........ : V 0.0.0.0
* Modification ... : 2/12/2018
* Licence ........ : Propriétaire
* Compilateur .... : cc65
********************************************************
* Programme ...... : Prisonnier
* Auteur ......... : Jean Monos et Emanuel Lorand 
* Programmeur .... : Jean Monos
* Graphiste ...... :
* Musicien ....... :
* Divers ......... : 
********************************************************/

// ====================
// * Fichier Includes *
// ====================
#include "header\game.h"

extern unsigned char board_chipset[11][11];
extern unsigned char board_collision[11][11];
extern unsigned char board_map[];



// ========================
// * Procedure draw_board *
// ========================
void draw_board(unsigned char largeur,unsigned char hauteur)
{
	// -------------------------------------
	// * Declaration des variables locales *
	// -------------------------------------
	unsigned char x,y,position,buffer_position_y;
	
	// ------------------------------------------
	// * Boucle pour poser les tiles du plateau *
	// ------------------------------------------
	for (y=0;y<hauteur;y++)
	{
		//buffer_position_y = y*11;
	  buffer_position_y = (y<<3)+(y<<1)+y;
		
		for(x=0;x<largeur;x++)
		{			
	
	     position=buffer_position_y+x;
	    // ----------------------------- 
	    // * Poser le tiles du plateau *
	    // -----------------------------
	    draw_tiles(x,y,board_map[ position]);
		
	    // -------------------------------------
	    // - Memorisation des id tiles         -
	    // -------------------------------------
	    board_chipset[x][y]=board_map[ position];
	
	    // -------------------------------------
	    // - Memorisation des bloc de colision -
	    // -------------------------------------
	    if (
			(board_map[ position]==tiles_grille) |
			(board_map[ position]==5)
		  )
	    {
	      board_collision[x][y]=0;
	    }
	   
		  else if ( board_map[ position]==tiles_mur | board_map[ position]==tiles_mur_lateral | board_map[ position]==4| board_map[ position]==10 || board_map[ position]==11 )
	    {
	      board_collision[x][y]=1;
	    }
			
	
			
			
	  }  
	}
		
}



// ========================
// * Procedure draw_tiles *
// ========================
void draw_tiles(unsigned char px, unsigned char py, unsigned char id)
{
	px=px<<4;
	py=py<<4;
	
		switch (id)
		{
		  
			// ----------------
			// * Tiles du mur *
			// ----------------
			case tiles_mur:
				HMMC (data_mur, px, py, 16, 16 );
			break;
			
			case 10:
			    HMMC (data_mur_b, px, py, 16, 16 );
			break;
			
			case 11:
			    HMMC (data_mur_c, px, py, 16, 16 );
			break;
			
			case 12:
			    HMMC (data_mur_d, px, py, 16, 16 );
			break;
			// ----------------
			// * Tiles sol *
			// ----------------
			case tiles_grille:
			  HMMC (data_grille, px, py, 16, 16 );		
			break;
			
			
			// ----------------
			// * Tiles trapes *
			// ----------------
			case 4:
			    HMMC (data_trapes, px, py, 16, 16 );	
			break;
			
			
			// --------------------------
			// * Tiles de téléportation *
			// ---------------------------
			case 5:						
			    HMMC (data_mur, px, py, 16, 16 );						
			break;
			
		}
	
	
}





