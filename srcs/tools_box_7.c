#include "../includes/cub.h"

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