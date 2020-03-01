/*******************************************************
* Nom ............ : game_controllers.h
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

#ifndef __GAME_CONTROLLERS_H
	#define __GAME_CONTROLLERS_H
	
	// ================================
	// * Define entrer                *
	// ================================
	#define KEYBOARD 0
	#define PORT_1 1
	#define PORT_2 2
	
	
	// ================================
	// * Les procedures               *
	// ================================
	unsigned char get_commande(unsigned char id_entrer);
	
#endif