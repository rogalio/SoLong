/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:14:53 by codespace         #+#    #+#             */
/*   Updated: 2023/07/31 19:01:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>


# include "./mlx_linux/mlx.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define TILE_SIZE 64

/*
** @struct: s_map
** @desciption: Structure pour stocker la carte du jeu
** @member: map (char **): La carte du jeu sous forme de tableau 2D de caractères
** @member: width (int): Le nombre de colonnes dans la carte
** @member: height (int): Le nombre de lignes dans la carte
*/
typedef struct s_map
{
    char	**map;
    int		width;
    int		height;
}				t_map;

/*
** @struct: s_img
** @description: Structure pour manipuler des images avec la MiniLibX
** @member: img (void *): Pointeur vers l'image dans la mémoire de la MiniLibX
** @member: addr (char *): Pointeur vers le premier pixel de l'image
** @member: bits_per_pixel (int): Nombre de bits utilisés pour la couleur d'un pixel
** @member: line_length (int): Nombre d'octets pour stocker une ligne de l'image
** @member: endian (int): Ordre des octets pour le stockage des entiers
*/
typedef struct s_img
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_img;

/*
** @struct: s_mlx
** @desc: Structure pour gérer la fenêtre du jeu avec la MiniLibX
** @member: mlx (void *): Pointeur vers la connexion avec le serveur graphique
** @member: win (void *): Pointeur vers la fenêtre du jeu
** @member: img (t_img): L'image actuellement affichée dans la fenêtre du jeu
*/

// remplacer window , pas pertinent
typedef struct s_mlx
{
    void	*mlx;
    void	*win;
    t_img	img;
}				t_mlx;

/*
** @struct: s_game
** @desc: Structure pour regrouper toutes les informations du jeu
** @member: mlx (t_mlx): Gestionnaire de la fenêtre du jeu
** @member: map (t_map): La carte du jeu
** @member: player_x (int): Coordonnée x du joueur sur la carte
** @member: player_y (int): Coordonnée y du joueur sur la carte
** @member: collectibles (int): Nombre d'objets collectables restants sur la carte
** @member: moves (int): Nombre de mouvements effectués par le joueur
*/
typedef struct s_game
{
    t_mlx	mlx;
    t_map	map;
    int		player_x;
    int		player_y;
    int		collectibles;
    int		moves;
}				t_game;

// Fonctions de gestion des erreurs et de fin de programme
/* Ces fonctions sont dédiées à la gestion des erreurs, à l'arrêt du programme et à la libération des ressources. */
int		ft_close(t_game *game);
int		ft_exit(t_game *game);
int		ft_error(char *str, t_game *game);

// Fonctions de gestion des entrées utilisateur
/* Ces fonctions gèrent les interactions de l'utilisateur avec le jeu, notamment les entrées clavier. */
int		ft_keypress(int keycode, t_game *game);
int		ft_keyrelease(int keycode, t_game *game);

// Fonctions d'initialisation du jeu
/* Ces fonctions sont responsables de la mise en place initiale du jeu, y compris le chargement de la carte et l'initialisation de la bibliothèque graphique. */
int		ft_init_game(t_game *game);
int		ft_init_map(t_game *game, char *file);
int		ft_init_mlx(t_game *game);
int		ft_init_img(t_game *game, t_img *img, char *path);
int		ft_check_map(t_game *game);

// Fonctions de rendu graphique
/* Ces fonctions sont responsables du dessin des différents éléments du jeu sur l'écran. */
int		ft_draw_map(t_game *game);
int		ft_draw_tile(t_game *game, int x, int y, char c);
int		ft_draw_player(t_game *game, int x, int y);
int		ft_draw_collectible(t_game *game, int x, int y);
int		ft_draw_exit(t_game *game, int x, int y);

// Fonctions de gestion de la logique du jeu
/* Ces fonctions gèrent la logique du jeu, comme le mouvement du joueur, la collecte d'objets et la vérification de la sortie. */
int		ft_move_player(t_game *game, int x, int y);
int		ft_collect(t_game *game, int x, int y);
int		ft_check_exit(t_game *game, int x, int y);


#endif


/// a faire




