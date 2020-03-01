/*******************************************************
* Nom ............ : load_asset.c
* Role ........... : Fichier de donnée
* Auteur ......... : Monos
*******************************************************/

// ====================
// * Fichier Includes *
// ====================
#include "header\game.h"



// ========================
// * msx2_load_game_sprite *
// ========================

// * Chargement et initiation des sprites sur msx_load_game_sprite ! *
void msx_load_game_sprite()
{
	// -------------------------
	// * Initiation des sprites * 
	// -------------------------
	
	SpriteReset();
	Sprite16();
	SpriteSmall();
	
	// ------------------------------
	// * Mermprisation des paternes * 
	// ------------------------------
	SetSpritePattern(0,Sprite32Bytes( curseur_1 ),32);
 
 
 
 
	SetSpritePattern(4, player_contour,32);
	SetSpritePattern(8, player_color,32);

	// -------------------------
	// * Couleur du curseur * 
	// -------------------------
	SC8SpriteColors(0,palette_curseur);

	// -------------------------
	// * Couleur du joueur 1   * 
	// -------------------------
  SC8SpriteColors(1,palette_player_contour);
  SC8SpriteColors(2,palette_player_1);	
	SC8SpriteColors(16,palette_player_contour);
	// -------------------------
	// * Couleur du joueur 2   * 
	// -------------------------
	SC8SpriteColors(3,palette_player_contour);
  SC8SpriteColors(4,palette_player_2);
	

}