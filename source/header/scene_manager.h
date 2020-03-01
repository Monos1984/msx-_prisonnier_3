/*******************************************************
* Nom ......... : scene_manager.h
* Role ........ : header Gestion des scenes du jeu
********************************************************/

#ifndef SCENE_MANAGER_H
	#define SCENE_MANAGER_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================
  
	#define SCENE_INIT 0
	#define SCENE_SPLASH 1
  #define SCENE_TITLE_SCREEN 2
	#define SCENE_GAME 10
	#define SCENE_CREDIT 20
  	
	// ================================
	// ** Déclaration des prototypes **
	// ================================
	void scene_set(unsigned char value);
  unsigned char scene_get(void);

#endif
