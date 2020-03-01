/*******************************************************
* Programme ...... : Prisonnier III
********************************************************
* Nom ............ : scene_game.c
* Auteur ......... : Monos
********************************************************
* Note ...........  : Le Fichier Scene_Game ne doit pas 
                      contenir de fonction propre
                      au api pour faciliter le portage 
											du jeu !!!
*********************************************************/


// ====================
// * Fichier Includes *
// ====================
#include "header/game.h"

void end_game(unsigned char *id_player_game);

// ====================
// * Variable Externe *
// ====================
extern  unsigned char board_asset[];
extern  unsigned char board_map[];
extern  unsigned char sprite_games[];
extern  unsigned char hud[];

// ===================
// * Variable Global *
// ===================
s_curseur curseur;
s_player player[2];
unsigned char board_chipset[11][11];
unsigned char board_collision[11][11];
static unsigned char turn_player;
static unsigned char etat_partie = 0;
static unsigned char buffer_etat_partie = 0;
static unsigned int boucle=0;
unsigned char draw_text;
unsigned int x;
unsigned int y;
 

TIME tm; // Initiation du temps !
// ==========================
// ** Procedure scene_game **
// ==========================
void scene_game (void)
{
	// -------------------------------------
	// * Déclaration des variables locales *
	// -------------------------------------	
	unsigned char frame;	
  unsigned char random;	
	unsigned char ia_end_turn = 0;
	
	MSX_wait(24);
	// --------------------------------
	// * Initation du son pour le jeu *
	// --------------------------------	
	init_fx_sound("smoved.afb", 204);
	
	
	// ---------------------------- 
	// * Initiation des variables *
	// ----------------------------
	curseur.position_x = 5;
	curseur.position_y = 1;
	player[PLAYER_1].position_x=5;
	player[PLAYER_1].position_y=1;
	player[PLAYER_2].position_x=5;
	player[PLAYER_2].position_y=9;
	player[PLAYER_1].defaite=0;
	player[PLAYER_2].defaite=0;
	curseur.update = 0;
	frame = 0;
	draw_text=0;


	// ===============================
	// * Initation de l'écran du jeu *
	// ===============================
  HideDisplay();
	Cls(); // Effacement de l'écran	
	
	// =================================
	// * Chargement des sprites du jeu *
	// =================================
	msx_load_game_sprite();
	
		
	// ===========================================
	// * Mise en place du plateau et des sprites *
	// ==========================================	
	// -----------------------------------
	// * Mise en place du plateau du jeu *
	// -----------------------------------
	draw_board(11,11);

	// =======================================
	// * Mise en place des sprites de départ *
	// =======================================
	draw_player_sprite();
	draw_curseur_sprite();
		
	// ================================================================
	// * Initiation de l'état de partie pour le placement du joueur 1 *
	// ================================================================
	etat_partie = PLACEMENT_J1;
	turn_player = PLAYER_1;
	
	// ===================================
	// * Création du cadre d'information *
	// ===================================
	create_windows(176,0,10,7,0);
		
	// ========================
	// * Affichage de l'écran *
	// ========================
	ShowDisplay();
	
	// ========================================
	// * Pose aléatoire de block avant partie *
	// ========================================
	draw_random_map(230);	
  SpriteOn();
	
	// ===========================
	// * Boucle de la Scene_Game *
	// ===========================
  while (scene_get() == SCENE_GAME)
	{		
		end_game_test();
									
		// ---------------------------------------
		// * Choix de la case départ du joueur 1 *
		// ---------------------------------------
		// - J1 Humain                           -
		// ---------------------------------------
		if (etat_partie == PLACEMENT_J1  && player[0].id_controle !=3)
		{
			
			// * Affichage du text *
			if (draw_text==0)
			{
				draw_text=1;	
				PutText(184, 16,"PLAYER 1"); 
				PutText(184, 24,"SELECTED");
				PutText(184, 32," START");
			}
					
					
			if (teleporte_player(PLAYER_1) == 1)
			{				
				play_sound(1);
				curseur.position_x=player[PLAYER_2].position_x;
				curseur.position_y=player[PLAYER_2].position_y;
				turn_player=PLAYER_2;
				etat_partie = PLACEMENT_J2;
				draw_text=0;
			}			
		}
		
		// ---------------------------------------
		// * Choix de la case départ du joueur 1 *
		// ---------------------------------------
		// - J1 MSX                              -
		// ---------------------------------------
		else if (etat_partie == PLACEMENT_J1  && player[0].id_controle == 3)
		{
			
			board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y]=1;
			curseur.position_x=player[PLAYER_2].position_x;
			curseur.position_y=player[PLAYER_2].position_y;
			turn_player=PLAYER_2;
			etat_partie = PLACEMENT_J2;
			draw_text=0;
		}
					
		// ---------------------------------------
		// * Choix de la case départ du joueur 2 *
		// ---------------------------------------
		else if (etat_partie == PLACEMENT_J2  && player[1].id_controle !=3)
		{
			if (draw_text==0)
			{
				draw_text=1;
			  PutText(184, 16,"PLAYER 2"); 
				PutText(184, 24,"SELECTED");
				PutText(184, 32," START");
			}
			
			if (teleporte_player(PLAYER_2)==1)
			{
				play_sound(1);
				curseur.position_x=player[PLAYER_1].position_x;
				curseur.position_y=player[PLAYER_1].position_y;
				turn_player=PLAYER_1;
				etat_partie = DEPLACEMENT_J1;
				draw_text=0;				
			}
		
		}
		
		// ------------------
		// * Téléportation *
		// ------------------
		else if (etat_partie == TELEPORTATION)
		{										
			if	(teleporte_player(turn_player) == 1)
			{
				etat_partie = buffer_etat_partie;
			}							
		}
						
		// ========================
		// * Eventement aléatoire *
		// ========================
		else 	if (etat_partie == EVENT)
		{
			draw_random_map(253);
			etat_partie = DEPLACEMENT_J1;
		}
				
		// ---------------------------
		// * Deplacement du joueur 1 *
		// ---------------------------
		// - Joueur Humain           -
		// ---------------------------
		else 	if (etat_partie == DEPLACEMENT_J1 && player[0].id_controle !=3)
		{
			if (draw_text==0)
			{
				draw_text=1;
				PutText(184, 16,"PLAYER 1"); 
				PutText(184, 24," MOVED  ");
				PutText(184, 32,"        ");
			}
			moved_curseur();
					
			if ((curseur.action == 1) && (board_collision[curseur.position_x][curseur.position_y]==0))
			{ 
		    // Test de proximité du curseur !						
				if (get_mvt_player(PLAYER_1)==1)
				{
					play_sound(1);
					update_sound();
					board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y]=0;
					player[PLAYER_1].position_x = curseur.position_x;
					player[PLAYER_1].position_y = curseur.position_y;
					board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y]=1;
					etat_partie = POSE_MUR_J1;
					draw_text=0;								
				}								
				curseur.action = 0;			
			}			
		}
		
		// ---------------------------
		// * Deplacement du joueur 1 *
		// ---------------------------
		// - Joueur MSX  (ia)        -
		// ---------------------------
		else 	if (etat_partie == DEPLACEMENT_J1 && player[0].id_controle ==3)
		{
			  ia_end_turn = 0;
				board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y]=0;
				GetTime(&tm);
				srand (tm.sec);
				
				while (ia_end_turn==0)
				{
					
					random=rand ()%8;
								
					switch (random)
					{
					case 0: // Haut
						if (board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y-1]==0)
						{						
							player[PLAYER_1].position_y = player[PLAYER_1].position_y-1;					 
							ia_end_turn = 1;
						}
					break;
					
					case 1: // Haut-Droite
					
						if (board_collision[player[PLAYER_1].position_x+1][player[PLAYER_1].position_y-1]==0)
						{
							player[PLAYER_1].position_x =  player[PLAYER_1].position_x+1;
							player[PLAYER_1].position_y =  player[PLAYER_1].position_y-1;
							ia_end_turn = 1;
						}
					break;
					
					case 2: // Droite
						
						if (board_collision[player[PLAYER_1].position_x+1][player[PLAYER_1].position_y]==0)
						{
							player[PLAYER_1].position_x = player[PLAYER_1].position_x+1;
							ia_end_turn = 1;

						}
					break;
					
					case 3: // Bas-Droite
						if (board_collision[player[PLAYER_1].position_x+1][player[PLAYER_1].position_y+1]==0)
						{
							player[PLAYER_1].position_x = player[PLAYER_1].position_x+1;
							player[PLAYER_1].position_y = player[PLAYER_1].position_y+1;
							ia_end_turn = 1;
						}
					break;
					
					case 4: // Bas
						if (board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y+1]==0)
						{
							player[PLAYER_1].position_y = player[PLAYER_1].position_y+1;
							ia_end_turn = 1;
						}
					break;
					
					case 5: // Bas-Gauche
						if (board_collision[player[PLAYER_1].position_x-1][player[PLAYER_1].position_y+1]==0)
						{
							player[PLAYER_1].position_x = player[PLAYER_1].position_x-1;
							player[PLAYER_1].position_y = player[PLAYER_1].position_y+1;
							ia_end_turn = 1;
						}
					break;
					
					case 6: // Gauche
						if (board_collision[player[PLAYER_1].position_x-1][player[PLAYER_1].position_y]==0)
						{
							player[PLAYER_1].position_x =  player[PLAYER_1].position_x-1;		
							ia_end_turn = 1;							
						}
					break;
					
					case 7: // Haut-Gauche
						if (board_collision[player[PLAYER_1].position_x-1][player[PLAYER_1].position_y-1]==0)
						{
							player[PLAYER_1].position_x = player[PLAYER_1].position_x-1;
							player[PLAYER_1].position_y = player[PLAYER_1].position_y-1;
							ia_end_turn = 1;
						}
					break;
					
					} // Fin du switch
				} // Fin du while
				
				board_collision[player[PLAYER_1].position_x][player[PLAYER_1].position_y]=1;
				etat_partie = POSE_MUR_J1;
							
		} // Fin du if MSX 1 turn
				
		// ---------------------
		// * Deploiment mur 1 *
		// --------------------
		// - Joueur msx    -
		// --------------------
		
		else 	if (etat_partie == POSE_MUR_J1  && player[0].id_controle ==3)
		{
				ia_end_turn = 0;
				GetTime(&tm);
				srand (tm.sec);
				
				
				while (ia_end_turn==0)
				{
					
					random=rand ()%8;
								
					switch (random)
					{
					case 0: // Haut
						if (board_collision[player[PLAYER_2].position_x][player[PLAYER_2].position_y-1]==0)
						{						
							curseur.position_x = player[PLAYER_2].position_x;
							curseur.position_y = player[PLAYER_2].position_y-1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					case 1: // Haut-Droite
					
						if (board_collision[player[PLAYER_2].position_x+1][player[PLAYER_2].position_y-1]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x+1;
							curseur.position_y = player[PLAYER_2].position_y-1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					case 2: // Droite
						
						if (board_collision[player[PLAYER_2].position_x+1][player[PLAYER_2].position_y]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x+1;
							curseur.position_y = player[PLAYER_2].position_y;
							draw_mur();
							ia_end_turn = 1;

						}
					break;
					
					case 3: // Bas-Droite
						if (board_collision[player[PLAYER_2].position_x+1][player[PLAYER_2].position_y+1]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x+1;
							curseur.position_y = player[PLAYER_2].position_y+1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					case 4: // Bas
						if (board_collision[player[PLAYER_2].position_x][player[PLAYER_2].position_y+1]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x;
							curseur.position_y = player[PLAYER_2].position_y+1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					case 5: // Bas-Gauche
						if (board_collision[player[PLAYER_2].position_x-1][player[PLAYER_2].position_y+1]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x-1;
							curseur.position_y = player[PLAYER_2].position_y+1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					case 6: // Gauche
					if (board_collision[player[PLAYER_2].position_x-1][player[PLAYER_2].position_y]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x-1;
							curseur.position_y = player[PLAYER_2].position_y;
							draw_mur();
							ia_end_turn = 1;							
						}
					break;
					
					case 7: // Haut-Gauche
						if (board_collision[player[PLAYER_2].position_x-1][player[PLAYER_2].position_y-1]==0)
						{
							curseur.position_x = player[PLAYER_2].position_x-1;
							curseur.position_y = player[PLAYER_2].position_y-1;
							draw_mur();
							ia_end_turn = 1;
						}
					break;
					
					} // Fin du switch
				} // Fin du while
				
				set_start(PLAYER_2);						
				etat_partie = DEPLACEMENT_J2;
				end_game_test();
					
		}
			
		// ---------------------
		// * Deploiment mur 1 *
		// --------------------
		// - Joueur Huamin    -
		// --------------------
			
		else 	if (etat_partie == POSE_MUR_J1  && player[0].id_controle !=3)
		{
			if (draw_text==0)
			{
				draw_text=1;
				PutText(184, 16,"PLAYER 1"); 
				PutText(184, 24,"  DRAW  ");
				PutText(184, 32," TRAPS  ");	
			}
			moved_curseur();
				
			if ((curseur.action == 1) && (board_collision[curseur.position_x][curseur.position_y]==0))
			{ 
				draw_mur();
				set_start(PLAYER_2);						
				etat_partie = DEPLACEMENT_J2;
									
			}
			end_game_test();
		}
	
		// ---------------------------
		// * Deplacement du joueur 2 *
		// ---------------------------
		else 	if (etat_partie == DEPLACEMENT_J2  && player[1].id_controle !=3)
		{
			if (draw_text==0)
			{
				draw_text=1;
				PutText(184, 16,"PLAYER 2"); 
				PutText(184, 24,"  MOVED ");
				PutText(184, 32,"        ");	
			}
			moved_curseur();
				
					
			if ((curseur.action == 1) && (board_collision[curseur.position_x][curseur.position_y]==0))
			{ 
		    // Test de proximité du curseur !		
				if (get_mvt_player(PLAYER_2)==1)
				{
					play_sound(1);				
					board_collision[player[PLAYER_2].position_x][player[PLAYER_2].position_y]=0;
					player[PLAYER_2].position_x = curseur.position_x;
					player[PLAYER_2].position_y = curseur.position_y;
					board_collision[player[PLAYER_2].position_x][player[PLAYER_2].position_y]=1;
					etat_partie = POSE_MUR_J2;
					draw_text=0;
							
				}
								
				curseur.action = 0;				
			}			
		}
		
				
		// ---------------------
		// * Deploiment mur 2 *
		// ---------------------
		else 	if (etat_partie == POSE_MUR_J2  && player[1].id_controle !=3)
		{
			if (draw_text==0)
			{
				draw_text=1;
				PutText(184, 16,"PLAYER 2"); 
				PutText(184, 24,"  DRAW  ");
				PutText(184, 32," TRAPS  ");	
			}
			moved_curseur();
				
			if ((curseur.action == 1) && (board_collision[curseur.position_x][curseur.position_y]==0))
			{ 
				draw_mur();
				set_start(PLAYER_1);				
				etat_partie = EVENT;							
			}
			end_game_test();
		}
			
		// Terminer la partie
    if (etat_partie == 99)
		{
		
		player[PLAYER_2].defaite=0;
		player[PLAYER_1].defaite=0;	
		MSX_wait(24);
		free_sound();	
		MSX_wait(24);	
		
		scene_set(SCENE_INIT);	
		// scene_set( SCENE_SPLASH);	
		}
			
		// ------------------------------------------
		// - Compteur de Frame pour les annimations -
		// ------------------------------------------
		frame++;
		
	
		
		// -----------------------------------------
		// - Modification de la couleur du curseur -
		// -----------------------------------------
			
		if (frame > 15)
		{
			
			if (turn_player==PLAYER_1)  
			{					
				SC8SpriteColors(0,palette_player_1);			
			}
			else
			{
				SC8SpriteColors(0,palette_player_2);	
			}
		}
		else
		{
			SC8SpriteColors(0,palette_curseur);			
		}
		
		if (frame>30)
		{
		  frame=0;
		}
		
		// -----------------------------------
		// - Affichage des sprites à l'écran -
		// -----------------------------------

		if (etat_partie < 99)
		{
			draw_curseur_sprite();
			draw_player_sprite();
			boucle++;
		}
		
			
	} // Fin de la boucle Scene_Game
	

	
		
			  
} // Fin de la procedure scene_game


// =======================================
// * Procedure de déplacement du curseur *
// =======================================
void moved_curseur()
{
	// -------------------------------------
	// - Declaration des variables locales -
	// -------------------------------------
	unsigned char commande;
	static unsigned char direction_up;
	curseur.action = 0; 
		
  // -----------------------------------------------------
	// - Récupération de la commande utilisé par le joueur -
	// -----------------------------------------------------
	commande = JoystickRead(player[turn_player].id_controle);
										
	// --------------------------------------
	// - Commande de déplacement du curseur -
	// --------------------------------------
		
    if (commande == 0 && TriggerRead(0) == 0)
	  {
      direction_up = 0;
    }	
	
		if (direction_up == 0)
		{
		
			if (commande == DIRECTION_DROITE && curseur.position_x <9 )
			{
				curseur.position_x++;
				direction_up = 1;		
			}
		
			else 	if (commande == DIRECTION_GAUCHE && curseur.position_x>1)
			{
				curseur.position_x--;
				direction_up = 1;
		
			}
	
			else 	if (commande == DIRECTION_HAUT && curseur.position_y>1)
			{
				curseur.position_y--;
				direction_up = 1;		
			}
	
			else 	if (commande == DIRECTION_BAS && curseur.position_y<9)
			{
				curseur.position_y++;
				direction_up = 1;		
			}
				
			if (TriggerRead(player[turn_player].id_controle) == 255)
			{
				curseur.action= 1;
				direction_up = 1;
			}
	
		}
		
}

// ==================================
// * Fonction curseur / déplacement *
// ==================================
unsigned char get_mvt_player(unsigned char id_player)
{
	
	if (

	// Test curseur Gauche
	((curseur.position_x+1==player[id_player].position_x) &&(curseur.position_y==player[id_player].position_y)) |
					
	// Test Curseur Droite
	((curseur.position_x-1==player[id_player].position_x) &&(curseur.position_y==player[id_player].position_y)) |
					
	// Test curseur Haut
	((curseur.position_x==player[id_player].position_x) &&(curseur.position_y-1==player[id_player].position_y)) |
					
	// Test curseur Bas
	((curseur.position_x==player[id_player].position_x) && (curseur.position_y+1==player[id_player].position_y)) |
					
	// Test curseur Haut/Gauche
	((curseur.position_x+1==player[id_player].position_x) && (curseur.position_y-1==player[id_player].position_y)) |
					
	// Test curseur Haut/Droite
	((curseur.position_x-1==player[id_player].position_x) && (curseur.position_y-1==player[id_player].position_y)) |
					
	// Test curseur Bas/Gauche
	((curseur.position_x+1==player[id_player].position_x) && (curseur.position_y + 1==player[id_player].position_y))  |
					
	// Test curseur Bas/Droite
	((curseur.position_x-1==player[id_player].position_x) && (curseur.position_y+1==player[id_player].position_y))
				
	)
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
}

// ========================
// * Tester la fin du jeu *
// ========================

unsigned char test_end_game(unsigned char id_player)
{
	unsigned char bloc_calcul;
	
	bloc_calcul =  
	// case gauche
	board_collision[player[id_player].position_x-1][player[id_player].position_y] +
	// case droite
	board_collision[player[id_player].position_x+1][player[id_player].position_y] +
	// case haut
	board_collision[player[id_player].position_x][player[id_player].position_y+1] +
	// case_bas
	board_collision[player[id_player].position_x][player[id_player].position_y-1] +
	// Case gauche/haut
	board_collision[player[id_player].position_x-1][player[id_player].position_y+1] +
	// Case droite/haut
	board_collision[player[id_player].position_x+1][player[id_player].position_y+1] +
		// Case gauche/bas
	board_collision[player[id_player].position_x-1][player[id_player].position_y-1] +
	// Case droite/bas
	board_collision[player[id_player].position_x+1][player[id_player].position_y-1] ;
	
	if (bloc_calcul == 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


// *********************************
// * Affichage aléatoire de la map *
// *********************************
void draw_random_map(unsigned char frequence)
{
	// * Variable locale
	unsigned char x;
	unsigned char y;	
	unsigned char random;

	PutText(184, 16,"  DRAW  "); 
	PutText(184, 24,"  MAPS  ");
	PutText(184, 32,"        ");
		
	GetTime(&tm);
  srand (tm.sec);
	MSX_wait(20);
	for (y=0;y<11;y++)
	{
		for (x=0;x<11;x++)
	  {
			
			 random=rand ()%255+1;

			if ((random>=frequence) &  (board_collision[x][y]==0))
			{
				board_chipset[x][y]=4;
				board_collision[x][y]=1;

				draw_tiles(x,y,4);
				play_sound(2);
			
				// Petit temps d'attente à placer. 
				MSX_wait(16);				
				
			}
    }	 
	}

		
}


// Non implémenté ?
unsigned char teleporte_player(unsigned char id_player)
{
	moved_curseur();
	player[id_player].position_x = curseur.position_x;
	player[id_player].position_y = curseur.position_y;
			
	if ((curseur.action == 1) & (board_collision[curseur.position_x][curseur.position_y]==0))
	{ 
		board_collision[player[id_player].position_x][player[id_player].position_y]=1;
		curseur.action = 0;		
		return 1;
	}
	return 0;
}


// Test Bonus non implémenté ?
/*
void test_bonus(void)
{
	// --------------------------------------------------
	// * Si le joueur est sur un bonus de téléportation *
	// --------------------------------------------------
	if (board_chipset[player[turn_player].position_x][player[turn_player].position_y]==5)
	{
		draw_tiles(player[turn_player].position_x, player[turn_player].position_y, tiles_grille);
		board_collision[player[turn_player].position_x][player[turn_player].position_y]=0;
		board_chipset[player[turn_player].position_x][player[turn_player].position_y]=5;
		buffer_etat_partie=etat_partie;
		etat_partie=TELEPORTATION;
    	
	}
		
}
*/

void end_game(unsigned char *id_player_game)
{
	play_sound(3);
	SpriteOff();
	create_windows(0,64,22,6,1);
	PutText(40, 78,id_player_game);

			
	
	PutText(8, 86,"Press Space For Menu");
	while(TriggerRead(0) == 0){};
	etat_partie = 99;

}

void end_game_test()
{
	// =================
	// * Test end game *
	// =================
	
	player[PLAYER_1].defaite=test_end_game(PLAYER_1);
	player[PLAYER_2].defaite=test_end_game(PLAYER_2);
	 
	// -----------
	// * Egalité *
	 // -----------
	if (
		(player[PLAYER_1].defaite==1)&&(player[PLAYER_2].defaite == 1))
				
	{
		// Action d'égalité
		
		end_game("Draw Games");			
	}
		
	// ----------------------
	// * Victoire joueuer 1 *
	// ----------------------
	else if (
				  (player[PLAYER_1].defaite==0) && (player[PLAYER_2].defaite == 1)
				  )
	{
		// Action de victoire du joueur 1
		
		end_game("Player 1 Win");		
	}
			
	// ----------------------
	// * Victoire joueuer 2 *
	// ----------------------
	else if (
				  (player[PLAYER_1].defaite==1) && (player[PLAYER_2].defaite == 0)
				  )
	{
		// Action de victoire du joueur 2
		
		end_game("Player 2 Win");
		
	}
}

void set_start(unsigned char id_player)
{
	curseur.position_x = player[id_player].position_x;
	curseur.position_y = player[id_player].position_y;
	turn_player = id_player;
	curseur.action = 0;	
	play_sound(2);			
	draw_text=0;
}

void draw_mur()
{
	board_collision[curseur.position_x][curseur.position_y]=1;
	board_chipset[curseur.position_x][curseur.position_y]=4;
	draw_tiles(curseur.position_x,curseur.position_y,4);
}