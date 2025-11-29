#include "mlx.h"

int main()
{
    void *mlx = mlx_init();
    if (!mlx)
        return 1;
    void *win = mlx_new_window(mlx, 200, 100, (char *)"OK");
    mlx_loop(mlx);
}
