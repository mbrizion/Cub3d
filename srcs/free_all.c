#include "cub3d.h"

int free_all(t_game *game)
{
    int i = game->info.map_len;
    free(game->info.north_path);
    free(game->info.south_path);
    free(game->info.weast_path);
    free(game->info.east_path);
    free(game->info.sprite.sprite_path);
    while (i >= 0)
    {
        free(game->info.map[i]);
        i--;
    }
}