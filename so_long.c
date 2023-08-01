#include "so_long.h"


int main()
{
	void	*mlx;
    void	*img;
    void    *win;


	mlx = mlx_init();
	img = mlx_new_image(mlx, 200, 1080);
    win = mlx_new_window(mlx, 200, 1080, "so_long");
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return (0);
}