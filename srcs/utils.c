#include "../incs/ft_ssl.h"

void init_flags(void) {
    g_hash_type = NULL;
    g_flag_p = false;
    g_p_seen = false;
    g_flag_s = false;
    g_flag_r = false;
    g_flag_q = false;
}

bool set_hash_type(char *hash) {
    if (ft_strequ(hash, "md5")) {
        g_hash_type = "md5";
    } else if (ft_strequ(hash, "sha256")) {
        g_hash_type = "sha256";
    } else {
        return false;
    }
    return true;
}

bool set_flag(char *arg) {
    if (ft_strequ(arg, "-s") && g_flag_s == false) {
        g_flag_s = true;
    } else if (ft_strequ(arg, "-r")) {
        g_flag_r = true;
    } else if (ft_strequ(arg, "-p") && g_p_seen == false) {
        g_flag_p = true;
    } else if (ft_strequ(arg, "-q")) {
        g_flag_q = true;
    } else {
        return false;
    }
    return true;
}

void print_error(int type, char *str) {
    if (type == 0) {
        printf("usage: ft_ssl command [flags] [file/string]\n");
    } else if (type == 1) {
        printf("ft_ssl: Error: '%s' is an invalid command.\nCommands:\nmd5\nsha256\nFlags:\n-p -q -r -s", str);
    } else if (type == 2) {
        printf("ft_ssl: %s: %s: No such file or directory\n", g_hash_type, str);
    }
    return ;
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if ((dest = malloc(sizeof(src[0]) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (s1[i])
		i++;
	while (s2[i2])
	{
		s1[i] = s2[i2];
		i++;
		i2++;
	}
	s1[i] = '\0';
	return (s1);
}


char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}