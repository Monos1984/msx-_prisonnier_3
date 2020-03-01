/*******************************************************
* Nom ............ : sprite_update.c
* Auteur ......... : Monos
********************************************************/

// ====================
// * Fichier Includes *
// ====================
#include "header\game.h"

// ===================
// * Variable Global *
// ===================
extern s_curseur curseur;
extern s_player player[2];
	
// ===============
// * Draw_Player *
// ===============
void draw_player_sprite(void)
{
	// ....................................................
	// * Afficher le sprite du joueur 1 sur le plateau    *
	// ....................................................
	PutSprite(2,8,((player[PLAYER_1].position_x)<<4),(player[PLAYER_1].position_y<<4)-1,0);
	PutSprite(16,4,((player[PLAYER_1].position_x)<<4),(player[PLAYER_1].position_y<<4)-1,0);
  
	 
	// ....................................................
	// * Afficher le sprite du joueur 2 sur le plateau    *
	// ....................................................
	  
PutSprite(3,4,((player[PLAYER_2].position_x)<<4),(player[PLAYER_2].position_y<<4)-1,0);
PutSprite(4,8,((player[PLAYER_2].position_x)<<4),(player[PLAYER_2].position_y<<4)-1,0); 
}

// ==================================
// * void draw_curseur_sprite(void) *
// ==================================
void draw_curseur_sprite(void)
{
		 PutSprite(0,0,(curseur.position_x<<4),(curseur.position_y<<4)-1,0);			
}
