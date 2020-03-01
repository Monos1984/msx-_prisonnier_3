/*******************************************************
* Nom ......... : scene_manager.c
* Role ........ : Gestion des scenes du jeu
********************************************************/
// =======================
// ** Fichier d'include **
// =======================
#include "header/game.h"

// ===============================
// ** Déclaration des variables **
// ===============================
unsigned char scene;

// =================
// ** scene_set() **
// =================
void scene_set(unsigned char value)
{
    scene = value;
}

// =================
// ** scene_get() **
// =================
unsigned char scene_get()
{
    return scene;
}
