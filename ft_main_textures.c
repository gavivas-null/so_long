#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define TILE 64
#define WIN_W (TILE * 4)
#define WIN_H (TILE * 4)

int main(void)
{
	void *mlx;
	void *win;
	void *img;
	int w, h;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_W, WIN_H, "Test XPM individual");

	// 🏠 Salida
	// img = mlx_xpm_file_to_image(mlx, "textures/casa_ok.xpm", &w, &h);

	// 🍗 Comida
	// img = mlx_xpm_file_to_image(mlx, "textures/comida1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/comida2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/comida3_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/comida4_ok.xpm", &w, &h);

	// 🌿 Suelo y pared
	// img = mlx_xpm_file_to_image(mlx, "textures/grass0_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/tronco_ok.xpm", &w, &h);

	// 🐱 Protagonista - derecha
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_derecha1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_derecha2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_derecha3_ok.xpm", &w, &h);

	// 🐱 Protagonista - frontal
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_frontal1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_frontal2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_frontal3_ok.xpm", &w, &h);

	// 🐱 Protagonista - izquierda
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_izquierda1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_izquierda2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_izquierda3_ok.xpm", &w, &h);

	// 🐱 Protagonista - trasera
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_trasero1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_trasero2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/prota_trasero3_ok.xpm", &w, &h);

	// 😼 Villano - derecha
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_derecha1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_derecha2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_derecha3_ok.xpm", &w, &h);

	// 😼 Villano - frontal
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_frontal1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_frontal2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_frontal3_ok.xpm", &w, &h);

	// 😼 Villano - izquierda
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_izquierda1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_izquierda2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_izquierda3_ok.xpm", &w, &h);

	// 😼 Villano - trasera
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_trasera1_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_trasera2_ok.xpm", &w, &h);
	// img = mlx_xpm_file_to_image(mlx, "textures/villano_trasera3_ok.xpm", &w, &h);

	// ✅ ACTIVA SOLO UNO A LA VEZ:
	// img = mlx_xpm_file_to_image(mlx, "textures/casa_ok.xpm", &w, &h);

	if (!img)
	{
		printf("❌ Error al cargar la imagen\n");
		return (1);
	}

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}