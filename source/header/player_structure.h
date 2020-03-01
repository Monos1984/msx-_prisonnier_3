/*******************************************************
* Nom ............ : player_structure.h
* Auteur ......... : Monos
* Modification ... : 29/11/2018
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

#ifndef __PLAYER_STRUCTURE_H
	#define __PLAYER_STRUCTURE_H
	
	// ====================================
	// * Structure du curseur de position *
	// ====================================
	typedef struct
	{
		unsigned char position_x;
		unsigned char position_y;
		unsigned char active;	
		unsigned char update;
		unsigned char action;
	
	} s_curseur;
	
	// =======================
  // * Structure du joueur *
	// =======================
	typedef struct
	{
		unsigned char position_x;
		unsigned char position_y;
		unsigned char id_controle;	
		unsigned char defaite;		
	} s_player;
	
		

#endif