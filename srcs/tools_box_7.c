#include "../includes/cub.h"

void	ft_draw_circle(t_circle *circle, int *img, int reso_wid)
{
	double	angle;
	double	x;
	double	y;
	int		x_tmp;
	int		y_tmp;

	angle = 0;
	while (angle <= 360)
	{
		x = circle->rad * cos(deg_transform(angle));
		y = circle->rad * sin(deg_transform(angle));
		x_tmp = circle->x + (int)x;
		y_tmp = circle->y + (int)y;
		img[y_tmp * reso_wid + x_tmp] = circle->col;
		angle += 0.1;
	}
}

void	ft_draw_line(t_line *line, int *img, int reso_wid)
{
	double	x_diff;
	double	y_diff;
	int		pix;
	double	x_pix;
	double	y_pix;

	x_diff = line->end_x - line->beg_x;
	y_diff = line->end_y - line->beg_y;
	pix = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
	x_diff /= pix;
	y_diff /= pix;
	x_pix = line->beg_x;
	y_pix = line->beg_y;
	while (pix)
	{
		img[(int)y_pix * reso_wid + (int)x_pix] = line->col;
		x_pix += x_diff;
		y_pix += y_diff;
		pix--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*sav_dst;
	void	*sav_src;

	sav_dst = dst;
	sav_src = (void *)src;
	if (dst < src && dst + n >= src)
	{
		while (n--)
			*(char *)sav_dst++ = *(char *)src++;
	}
	else if (src < dst && src + n > dst)
	{
		sav_src += n;
		sav_dst += n;
		while (n--)
			*(char *)--sav_dst = *(char *)--sav_src;
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

void	ft_realloc_protec(void **p, size_t old_s, size_t new_s)
{
	*p = ft_realloc(*p, old_s, new_s);
	if (*p == 0)
		exit(EXIT_SUCCESS);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*sav_dst;

	sav_dst = dst;
	while (n-- && dst != src)
		*(char *)sav_dst++ = *(char *)src++;
	return (dst);
}