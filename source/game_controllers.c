/*******************************************************
* Nom ............ : game_controllers.c
* Auteur ......... : Monos
* Version ........ : V 0.0.0.0
* Modification ... : 28/11/2018
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

// ====================
// * Variable Externe *
// ====================

// =============================
// ** Procedure get_commande  **
// =============================
unsigned char get_commande(unsigned char id_entrer)
{


	return JoystickRead(id_entrer);	
}




