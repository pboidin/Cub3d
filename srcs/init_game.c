#include "../includes/cub.h"

void    check_texture(void *texN, void *texS, void *texW, void *texE)
{
        if (texN == NULL || texS == NULL || texW == NULL || texE == NULL )
        {
                printf("Error\nTexture Error\n");
                exit(EXIT_FAILURE);
        }
}

void    color_init(game_t *game, info_t *info)
{
        game->Ceiling_col[0] = info->CE_col[0];
        game->Ceiling_col[1] = info->CE_col[1];
        game->Ceiling_col[2] = info->CE_col[2];
        game->Floor_col[0] = info->FL_col[0];
        game->Floor_col[1] = info->FL_col[1];
        game->Floor_col[2] = info->FL_col[2];
}

void    game_init(game_t *game, info_t *info)
{
        game->img = mlx_new_image(game->mlx_ptr, DIS_WID, DIS_HEI);
        game->hei_tex = 0;
        game->wid_tex = 0;
        game->f_side = 0;
        game->hor_inter = 0;
        game->ver_inter = 0;
        color_init(game, info);
        game->name_tex_NO = info->NO_tex;
        game->name_tex_SO = info->SO_tex;
        game->name_tex_WE = info->WE_tex;
        game->name_tex_EA = info->EA_tex;
        game->texture_NO = mlx_xpm_file_to_image(game->mlx_ptr, game->name_tex_NO, &game->wid_tex, &game->hei_tex);
        game->texture_SO = mlx_xpm_file_to_image(game->mlx_ptr, game->name_tex_SO, &game->wid_tex, &game->hei_tex);
        game->texture_WE = mlx_xpm_file_to_image(game->mlx_ptr, game->name_tex_WE, &game->wid_tex, &game->hei_tex);
        game->texture_EA = mlx_xpm_file_to_image(game->mlx_ptr, game->name_tex_EA, &game->wid_tex, &game->hei_tex);
        check_texture(game->texture_NO, game->texture_SO, game->texture_WE, game->texture_EA);
}
