#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x_champignon;
    int y_champignon;
    int points;
    BITMAP *champignon;
    int clique;
} t_champignon;

int animation_champignon(t_champignon *champignon, BITMAP *buffer, int *compteur,int score) {
    int t = 500; // Temps d'animation initial
    int i = 0;
    BITMAP *champignon_bmp = champignon->champignon;
    BITMAP *decor = load_bitmap("Labitmap2.bmp", NULL);

    int champignon_clicked = 0;

    while (i < 300) {
        if (mouse_x >= champignon->x_champignon && mouse_x < champignon->x_champignon + champignon_bmp->w / 2 &&
            mouse_y >= champignon->y_champignon && mouse_y < champignon->y_champignon + champignon_bmp->h / 2 && mouse_b & 1) {
            int mouse_x = mouse_x;
            int mouse_y = mouse_y;
            champignon_clicked = 1;
            score++;
            break;
        }

        if (i < 50) {
            // Monter
            if (i % 20 == 0) {
                champignon->y_champignon -= 10;
            }
        }
        if (i > 250) {
            // Descendre
            // Effacement de l'image du champignon
            if (i % 20 == 0) {
                // Mise à jour de la position du champignon
                champignon->y_champignon += 10;
            }
        }

        // Effacement de l'ancienne position du champignon sur le tampon
        blit(buffer, screen, champignon->x_champignon, champignon->y_champignon, champignon->x_champignon,
             champignon->y_champignon, champignon_bmp->w, champignon_bmp->h);

        // Mise à jour de la position du champignon sur le tampon
        blit(decor, buffer, 0, 0, 0, 0, decor->w, decor->h);

        // Affichage du champignon à sa nouvelle position sur le tampon
        if (champignon_clicked == 0) {
            stretch_sprite(buffer, champignon_bmp, champignon->x_champignon, champignon->y_champignon,
                           champignon_bmp->w * 1 / 2, champignon_bmp->h * 1 / 2);
        } else {
            break;
        }

        // Copie du tampon sur l'écran
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        i += 2; // Incrément de 2 pour accélérer l'animation

        rest(1);
        printf("%d\n", i);
    }

    // Libération de la mémoire du tampon
    destroy_bitmap(decor);

    return score;
}



int main() {
    srand(time(NULL));// on utilise le hasard pour faire apparaitre les champignons
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 366, 0, 0) != 0)
    {
        allegro_message("Erreur lors du changement de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *decor = load_bitmap("Labitmap2.bmp", NULL);
    if (!decor)
    {
        allegro_message("Erreur lors du chargement de l'image LAbitmap222.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    blit(decor, screen, 0, 0, (SCREEN_W - decor->w) / 2, (SCREEN_H - decor->h) / 2, decor->w, decor->h);

    // Affichage du sprite

    show_mouse(screen);

// Dessine la bitmap modifiée sur l'écran en utilisant la masque de transparence
    // Détruit la bitmap d'origine

    t_champignon champignon1;
    champignon1.x_champignon = 75;
    champignon1.y_champignon = 276;
    champignon1.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon1.clique=0;
    if (!champignon1.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon2;
    champignon2.x_champignon = 316;
    champignon2.y_champignon = 220;
    champignon2.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon2.clique=0;
    if (!champignon2.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon3;
    champignon3.x_champignon = 545;
    champignon3.y_champignon = 310;
    champignon3.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon3.clique=0;
    if (!champignon3.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon4;
    champignon4.x_champignon = 214;
    champignon4.y_champignon = 200;
    champignon4.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon4.clique=0;
    if (!champignon4.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon5;
    champignon5.x_champignon = 217;
    champignon5.y_champignon = 70;
    champignon5.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon5.clique=0;
    if (!champignon5.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    t_champignon champignon_aleatoire;
    champignon_aleatoire.x_champignon = 0;
    champignon_aleatoire.y_champignon = 0;
    champignon_aleatoire.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon_aleatoire.clique = 0;
    if (!champignon_aleatoire.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int score = 0; // Ajout d'une variable pour stocker le score

    while (!key[KEY_ESC])
    {
        int compteur_frames = 0;

        clear_bitmap(screen); // Efface le contenu de l'écran

        textprintf_ex(screen, font, 100, 100, makecol(255, 255, 255), -1, "Score: %d", score); // Affiche le score

        for (int i = 0; i < 30; ++i) {
            int nombre_aleatoire = rand() % 5;
            textprintf_ex(screen, font, 100, 100, makecol(255, 255, 255), -1, "Score: %d", score); // Affiche le score

            if (nombre_aleatoire == 0) {
                champignon_aleatoire = champignon1;
                score += animation_champignon(&champignon_aleatoire, decor, &compteur_frames, score); // Ajoute le score retourné par la fonction à la variable score
            } else if (nombre_aleatoire == 1) {
                champignon_aleatoire = champignon2;
                score += animation_champignon(&champignon_aleatoire, decor, &compteur_frames, score);
            } else if (nombre_aleatoire == 2) {
                champignon_aleatoire = champignon3;
                score += animation_champignon(&champignon_aleatoire, decor, &compteur_frames, score);
            } else if (nombre_aleatoire == 3) {
                champignon_aleatoire = champignon4;
                score += animation_champignon(&champignon_aleatoire, decor, &compteur_frames, score);
            } else {
                champignon_aleatoire = champignon5;
                score += animation_champignon(&champignon_aleatoire, decor, &compteur_frames, score);
            }
            textprintf_ex(screen, font, 100, 100, makecol(255, 255, 255), -1, "Score: %d", score);

        }


        // Libérer la mémoire

    }

    // Libération de la mémoire allouée
    destroy_bitmap(champignon1.champignon);
    destroy_bitmap(champignon2.champignon);
    destroy_bitmap(champignon3.champignon);
    destroy_bitmap(champignon4.champignon);
    destroy_bitmap(champignon5.champignon);
    destroy_bitmap(champignon_aleatoire.champignon);
    destroy_bitmap(decor);
    allegro_exit();

    return 0;
}

END_OF_MAIN();












/*
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x_champignon;
    int y_champignon;
    int points;
    BITMAP *champignon;
    int clique;
} t_champignon;



#include <time.h>

int animation_champignon(t_champignon *champignon, BITMAP *decor) {
    int t=1000;
    BITMAP *champignon_bmp = champignon->champignon;

    for (int i = 0; i < 3; i++)

    {
        // Effacement de l'ancienne position du champignon

        blit(decor, screen, champignon->x_champignon, champignon->y_champignon, champignon->x_champignon, champignon->y_champignon, champignon_bmp->w, champignon_bmp->h);
// Mise à jour de la position du champignon
        BITMAP* tuyau = load_bitmap("Labitmap2.bmp", NULL);
        blit(tuyau, screen, 0, 0, 0, 0, tuyau->w, tuyau->h);
        champignon->y_champignon -= 10;

        // Affichage du champignon à sa nouvelle position
        stretch_sprite(screen, champignon_bmp, champignon->x_champignon, champignon->y_champignon, champignon_bmp->w * 1 / 2, champignon_bmp->h * 1 / 2);
        // Pause de 50 millisecondes pour limiter la vitesse d'affichage
        rest(100);
    }



    float tps = t;

// Effacement de l
    rest(tps);

// Effacement de l'image du champignon
    for (int i = 0; i < 3; ++i) {
        blit(decor, screen, champignon->x_champignon, champignon->y_champignon, champignon->x_champignon, champignon->y_champignon, champignon_bmp->w, champignon_bmp->h);
// Mise à jour de la position du champignon
        BITMAP* tuyau = load_bitmap("Labitmap2.bmp", NULL);
        champignon->y_champignon += 10;

        // Affichage du champignon à sa nouvelle position
        stretch_sprite(screen, champignon_bmp, champignon->x_champignon, champignon->y_champignon, champignon_bmp->w * 1 / 2, champignon_bmp->h * 1 / 2);
        blit(tuyau, screen, 0, 0, 0, 0, tuyau->w, tuyau->h);
        rest (100);

    }





//liberation de la memoire

    // Effacement de l'image du champignon
//liberation de la memoire
}

int main() {
    srand(time(NULL));// on utilise le hasar pour faire apparaitre les champignons
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 366, 0, 0) != 0)
    {
        allegro_message("Erreur lors du changement de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *decor = load_bitmap("Labitmap2.bmp", NULL);
    if (!decor)
    {
        allegro_message("Erreur lors du chargement de l'image LAbitmap222.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    blit(decor, screen, 0, 0, (SCREEN_W - decor->w) / 2, (SCREEN_H - decor->h) / 2, decor->w, decor->h);

    // Affichage du sprite

    show_mouse(screen);

// Dessine la bitmap modifiée sur l'écran en utilisant la masque de transparence
    // Détruit la bitmap d'origine

    t_champignon champignon1;
    champignon1.x_champignon = 75;
    champignon1.y_champignon = 276;
    champignon1.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon1.clique=0;
    if (!champignon1.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon2;
    champignon2.x_champignon = 316;
    champignon2.y_champignon = 220;
    champignon2.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon2.clique=0;
    if (!champignon2.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon3;
    champignon3.x_champignon = 545;
    champignon3.y_champignon = 310;
    champignon3.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon3.clique=0;
    if (!champignon3.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon4;
    champignon4.x_champignon = 214;
    champignon4.y_champignon = 200;
    champignon4.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon4.clique=0;
    if (!champignon4.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    t_champignon champignon5;
    champignon5.x_champignon = 217;
    champignon5.y_champignon = 70;
    champignon5.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon5.clique=0;
    if (!champignon5.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    t_champignon champignon_aleatoire;
    champignon_aleatoire.x_champignon = 0;
    champignon_aleatoire.y_champignon = 0;
    champignon_aleatoire.champignon = load_bitmap("champignonnn.bmp", NULL);
    champignon_aleatoire.clique = 0;
    if (!champignon_aleatoire.champignon)
    {
        allegro_message("Erreur lors du chargement de l'image champignonnn.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while (!key[KEY_ESC])
    {


        for (int i = 0; i < 30; ++i)
        {
            int nombre_aleatoire = rand() % 5;

            if (nombre_aleatoire == 0)
            {
                champignon_aleatoire = champignon1;
                animation_champignon(&champignon_aleatoire, decor, compteur_frames);
            }
            else if (nombre_aleatoire == 1)
            {
                champignon_aleatoire = champignon2;
                animation_champignon(&champignon_aleatoire, decor, compteur_frames);
            }
            else if (nombre_aleatoire == 2)
            {
                champignon_aleatoire = champignon3;
                animation_champignon(&champignon_aleatoire, decor, compteur_frames);
            }
            else if (nombre_aleatoire == 3)
            {
                champignon_aleatoire = champignon4;
                animation_champignon(&champignon_aleatoire, decor, compteur_frames);
            }
            else
            {
                champignon_aleatoire = champignon5;
                animation_champignon(&champignon_aleatoire, decor, compteur_frames);
            }




        }
    }
// Libération de la mémoire allouée
    destroy_bitmap(champignon_aleatoire.champignon);
    destroy_bitmap(decor);
    allegro_exit();
    return 0;
}

END_OF_MAIN();*/