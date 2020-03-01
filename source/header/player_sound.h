/*******************************************************
* Nom ............ : game.h
* Role ........... : Header général du jeu
* Auteur ......... : Monos
*******************************************************/


#ifndef PLAYER_SOUND_H
	#define PLAYER_SOUND_H
	

	// ============================
	// ** Header de la librairie **
	// ============================



void init_fx_sound(unsigned int* nom_fichier, unsigned int size_file);
void play_sound(unsigned char id);
void update_sound();
void free_sound();


	


	
	
#endif