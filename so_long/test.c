#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	t_data	image2;
	int width = 0;
	int length = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hellow World!");
	if (win_ptr == NULL)
	{
		printf("error\n");
		return (0);
	}
	image.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/woodtile.xpm", &width, &length);
	image2.img = mlx_xpm_file_to_image(mlx_ptr, "./asset/wall.xpm", &width, &length);
	printf("%d %d\n", width, length);
	//image.img = mlx_new_image(mlx_ptr, 500, 500); // 이미지 객체 생성
	//image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	// for (int i = 0 ; i < 500 ; i++)
	// {
	// 	for (int j = 0 ; j < 500 ; j++)
	// 	{
	// 	//	mlx_pixel_put (mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
	// 		my_mlx_pixel_put(&image, i, j, 0x00FFFFFF);
	// 	}	
	// }
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image2.img, 32, 0);
	mlx_loop(mlx_ptr);
	return (0);
}