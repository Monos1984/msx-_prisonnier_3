/*******************************************************
* Nom ............ : game.h
* Role ........... : Header général du jeu
* Auteur ......... : Monos
*******************************************************/


#ifndef GAME_H
	#define GAME_H
	

	// ============================
	// ** Header de la librairie **
	// ============================
	#include "STDLIB.h"
	
	#include "msx_fusion.h"
	#include "vdp_sprites.h"
	#include "vdp_graph2.h"

	// #include "vars_msxSystem.h"
	


	// ======================
	// ** Header des datas **
	// ======================
	#include "data.h"
	
	// ==========================
	// ** Header deu programme **
	// ==========================
	#include "scene_manager.h"
	#include "configuration.h"
	#include "scene_game.h"
	#include "player_structure.h"
	#include "game_controllers.h"
	#include "sprite_update.h"
	#include "title_screen.h"
	#include "load_asset.h"
	#include "windows.h"
	#include "scene_credit.h"
	#include "player_sound.h"


	
	// ==================
	// * Define general *
	// ==================
	
	// - Correction de placement des tiles
	#define CORRECTION_TILES_X 1
	#define CORRECTION_TILES_Y 1
	
	// - Correction de placement des sprites -
	#define CORRECTION_X CORRECTION_TILES_X
	#define CORRECTION_Y CORRECTION_TILES_Y

  // - Direction -
  #define DIRECTION_DROITE 3	
	#define DIRECTION_GAUCHE 7
	#define DIRECTION_HAUT 1
	#define DIRECTION_BAS 5
	#define FIRE 10
	
	// - Bloc tour -
	#define PLACEMENT_J1 1
	#define PLACEMENT_J2 2
	#define DEPLACEMENT_J1 10
	#define DEPLACEMENT_J2 15
	#define POSE_MUR_J1 30
	#define POSE_MUR_J2 35
	#define EVENT 40
	#define TELEPORTATION 60
	
	
	// - Define joueur -
	#define PLAYER_1 0
	#define PLAYER_2 1
	
	// - id sprite -
	#define SPRITE_CURSEUR 1
	#define SPRITE_J1 2
	#define SPRITE_J2 3
	
  void MSX_wait(int cicles);
	void tiles_vram_copy(unsigned char DX,unsigned char DY);

	
	
#endif