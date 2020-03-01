/*******************************************************
* Nom ............ : scene_game.h
* Auteur ......... : Monos
* Version ........ : V 0.0.0.6
* Modification ... : 16/11/2018
* Licence ........ : Creative Commons by-sa
* Compilateur .... : cc65
********************************************************
* Programme ...... : Prisonnier
* Auteur ......... : Jean Monos 
* Programmeur .... : Jean Monos
* Graphiste ...... :
* Musicien ....... :
* Divers ......... : 
********************************************************/

#ifndef __SCENE_GAME_H
	#define __SCENE_GAME_H
	
	// =============================================
	// * Define des types de ressources du plateau *
	// =============================================
	#define tiles_mur 1
	#define tiles_mur_lateral 2
	#define tiles_grille 0
	
	
	// ================================
	// * Les procedures               *
	// ================================
	void scene_game (void);
	void draw_board(unsigned char largeur,unsigned char hauteur);
	void draw_tiles(unsigned char px, unsigned char py, unsigned char id);
	void moved_curseur(void);
	void draw_random_map(unsigned char frequence);
	void draw_hud(void);
	void test_bonus(void);
	void draw_mega_tiles(unsigned char px, unsigned char py,unsigned char id_a,unsigned char id_b,unsigned char id_c,unsigned char id_d,unsigned char id_color);
	unsigned char teleporte_player(unsigned char id_player);
	void end_game_test();
	void set_start(unsigned char id_player);
	void draw_mur();
	
	// =================
	// * Les fonctions *
	// =================
	unsigned char get_mvt_player(unsigned char id_player);
	unsigned char test_end_game(unsigned char id_player);
	
#endif