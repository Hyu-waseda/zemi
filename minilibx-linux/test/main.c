
#include	"mlx.h"
#include	"mlx_int.h"
#include	<math.h>
#include	"fractol.h"


void 	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static double	ft_abs_complex(t_complex *z);
static double	ft_sqrt(double x);
static void		validate_argv(int argc, char **argv);
static void	draw_mandelbrot(t_coord *coord, t_plot *plot, t_fractol *fractol);
static void	draw_julia(t_coord *coord, t_plot *plot, t_fractol *fractol);
static void	draw_ship(t_coord *coord, t_plot *plot, t_fractol *fractol);
static void	set_complex(t_complex *z, double a, double b);
static t_complex	*new_complex(double a, double b);
static t_complex	*cal_add(t_complex **z1, t_complex **z2);
static t_complex	*cal_multi(t_complex **z1, t_complex **z2);
static double	cal_multi_re(t_complex *z1, t_complex *z2);
static double	cal_multi_im(t_complex *z1, t_complex *z2);
static double	ft_abs_complex(t_complex *z);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
static int	is_valid_param(char *x_str, char *y_str);
static double	ft_atof(char *str);
static int	key_hook(int key_code, t_fractol *fractol);
static int	mouse_hook(int button, int x, int y, t_fractol *fractol);
static void	draw_fractol(t_fractol *fractol);
static void	do_draw(t_fractol *fractol, t_plot *plot, t_coord *coord);
static void	init_fractol(t_fractol **fractol, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	validate_argv(argc, argv);
	init_fractol(&fractol, argc, argv);
	draw_fractol(fractol);
	mlx_hook(fractol->win, 2, 1L<<0, key_hook, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_loop(fractol->mlx);
	exit(0);
}

static void	init_fractol(t_fractol **fractol, int argc, char **argv)
{
	(*fractol) = (t_fractol *)malloc(sizeof(t_fractol) * 1);
	if (argc == 4)
	{
		(*fractol)->julia_a = ft_atof(argv[2]);
		(*fractol)->julia_b = ft_atof(argv[3]);
	}
	else
	{
		(*fractol)->julia_a = 0.32;
		(*fractol)->julia_b = 0.043;
	}
	(*fractol)->name = argv[1];
	(*fractol)->argc = argc;
	(*fractol)->mlx = mlx_init();
	(*fractol)->win = mlx_new_window((*fractol)->mlx, WIDTH, HEIGHT, "(*fractol)");
	(*fractol)->roop = 100;
	(*fractol)->color = 5000;
	(*fractol)->horizontal_move = 0;
	(*fractol)->vertical_move = 0;
	(*fractol)->zoom = 1;
	(*fractol)->img.img = mlx_new_image((*fractol)->mlx, WIDTH, HEIGHT);
	(*fractol)->img.addr = mlx_get_data_addr((*fractol)->img.img, &((*fractol)->img.bits_per_pixel), &((*fractol)->img.line_length), &((*fractol)->img.endian));
}

static void	draw_fractol(t_fractol *fractol)
{
	t_plot	*plot;
	t_coord	*coord;

	plot = (t_plot *)malloc(sizeof(t_plot) * 1);
	coord = (t_coord *)malloc(sizeof(t_coord) * 1);
	plot->x = 0;
	while (plot->x < HEIGHT)
	{
		coord->x = (plot->x * 4 / HEIGHT - 4 / 2) * fractol->zoom + fractol->horizontal_move;
		plot->y = 0;
		while (plot->y < WIDTH)
		{
			coord->y = (plot->y * 4 / WIDTH - 4 / 2) * fractol->zoom + fractol->vertical_move;
			do_draw(fractol, plot, coord);
			plot->y++;
		}
		(plot->x)++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

static void	do_draw(t_fractol *fractol, t_plot *plot, t_coord *coord)
{
	if (ft_strncmp(fractol->name, "Mandelbrot", 11) == 0)
		draw_mandelbrot(coord, plot, fractol);
	else if (ft_strncmp(fractol->name, "Julia", 6) == 0)
		draw_julia(coord, plot, fractol);
	else if (ft_strncmp(fractol->name, "Burningship", 11) == 0)
		draw_ship(coord, plot, fractol);
}

static int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == 65307)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	else if (key_code == 65363)
		fractol->horizontal_move += 0.2 * fractol->zoom;
	else if (key_code == 65361)
		fractol->horizontal_move -= 0.2 * fractol->zoom;
	else if (key_code == 65362)
		fractol->vertical_move -= 0.2 * fractol->zoom;
	else if (key_code == 65364)
		fractol->vertical_move += 0.2 * fractol->zoom;
	else if (key_code == 59)
	{
		fractol->zoom *= 0.9;
		fractol->roop += 4;
	}
	else if (key_code == 45)
	{
		fractol->zoom *= 1.1;
		fractol->roop -= 4;
	}
	else if (key_code == 109)
		fractol->color *= 2;
	else if (key_code == 110)
		fractol->color *= 0.50;
	draw_fractol(fractol);
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->zoom *= 0.96;
		fractol->roop += 2;
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.04;
		fractol->roop -= 2;
	}
	draw_fractol(fractol);
	return (0);
}

static void	print_param(void)
{
	printf("parameter error\n");
	printf("---------------\n");
	printf("Mandelbrot\n");
	printf("Julia\n");
	printf("Julia <x> <y>\n");
	printf("Burningship\n");
	exit (1);
}

static void	validate_argv(int argc, char **argv)
{
	if (argc == 1)
		print_param();
	else if ((ft_strncmp(argv[1], "Mandelbrot", 11) != 0)
		&& (ft_strncmp(argv[1], "Julia", 6) != 0)
		&& (ft_strncmp(argv[1], "Burningship", 13) != 0))
		print_param();
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc != 2)
		print_param();
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		if (argc != 2 && argc != 4)
			print_param();
		else if (argc == 4)
		{
			if (!is_valid_param(argv[2], argv[3]))
				print_param();
		}
	}
	else if (ft_strncmp(argv[1], "Burningship", 13) == 0 && argc != 2)
		print_param();
}

static int	is_fraction(const char *str);

static int	is_valid_param(char *x_str, char *y_str)
{
	double	x;

	if (!is_fraction(x_str) || !is_fraction(y_str)
		|| ft_strlen(x_str) > 16 || ft_strlen(y_str) > 16)
		return (0);
	x = ft_atof(x_str);
	printf("%f\n", x);
	return (1);
}

static int	is_fraction(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || str[i] == '.')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '.')
		i++;
	if (str[i] == '\0')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (i == ft_strlen(str) && str[i] == '\0')
		return (1);
	return (0);
}

static double	get_integer_part(char **str);
static double	get_fractional_part(char **str);

static double	ft_atof(char *str)
{
	double	x;
	double	sign;
	double	digit;
	size_t	i;

	i = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	x = get_integer_part(&str);
	x += get_fractional_part(&str);
	return (sign * x);
}

static double	get_integer_part(char **str)
{
	double	n;

	while (ft_isdigit(**str))
	{
		n = n * 10 + **str - '0';
		(*str)++;
	}
	return (n);
}

static double	get_fractional_part(char **str)
{
	double	n;
	double	digit;

	if (**str == '.')
		(*str)++;
	n = 0;
	digit = 0.1;
	while (ft_isdigit(**str))
	{
		n += (**str - '0') * digit;
		digit *= 0.1;
		(*str)++;
	}
	return (n);
}

static void	set_complex(t_complex *z, double a, double b)
{
	z->re = a;
	z->im = b;
}

static void	draw_mandelbrot(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(0, 0);
	c = new_complex(0, 0);
	k = 1;
	while (k < fmax(fractol->roop, 50))
	{
		z = cal_multi(&z, &z);
		c = new_complex(coord->x, coord->y);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	if (k == fractol->roop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}

static void	draw_julia(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(coord->x, coord->y);
	k = 1;
	while (k < fmax(fractol->roop, 50))
	{
		z = cal_multi(&z, &z);
		c = new_complex(fractol->julia_a, fractol->julia_b);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	if (k == fractol->roop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}

static void	draw_ship(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(coord->x, coord->y);
	c = new_complex(0, 0);
	k = 1;
	while (k < fmax(fractol->roop, 50))
	{
		set_complex(z, fabs(z->re), fabs(z->im));
		z = cal_multi(&z, &z);
		c = new_complex(coord->x, coord->y);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	if (k == fractol->roop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}

static t_complex	*new_complex(double a, double b)
{
	t_complex	*z;

	z = (t_complex *)malloc(sizeof(t_complex) * 1);
	z->re = a;
	z->im = b;
	return (z);
}

static t_complex	*cal_add(t_complex **z1, t_complex **z2)
{
	t_complex	*z;

	z = (t_complex *)malloc(sizeof(t_complex) * 1);
	z->re = (*z1)->re + (*z2)->re;
	z->im = (*z1)->im + (*z2)->im;
	free(*z1);
	*z1 = NULL;
	free(*z2);
	*z2 = NULL;
	return (z);
}

static t_complex	*cal_multi(t_complex **z1, t_complex **z2)
{
	t_complex	*z;

	z = (t_complex *)malloc(sizeof(t_complex) * 1);
	z->re = cal_multi_re(*z1, *z2);
	z->im = cal_multi_im(*z1, *z2);
	free(*z1);
	*z1 = NULL;
	free(*z2);
	*z2 = NULL;
	return (z);
}

static double	cal_multi_re(t_complex *z1, t_complex *z2)
{
	return (z1->re * z2->re - z1->im * z2->im);
}

static double	cal_multi_im(t_complex *z1, t_complex *z2)
{
	return (z1->re * z2->im + z1->im * z2->re);
}

static double	ft_abs_complex(t_complex *z)
{
	return (sqrt(pow(z->re, 2) + pow(z->im, 2)));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
