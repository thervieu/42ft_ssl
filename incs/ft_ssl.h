#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>

# define BUFFER_SIZE 4096

extern char    *g_hash_type;
extern bool    g_flag_p;
extern bool    g_p_seen;
extern bool    g_flag_s;
extern bool    g_flag_r;
extern bool    g_flag_q;

// 
# define A 0x67452301
# define B 0xefcdab89
# define C 0x98badcfe
# define D 0x10325476

unsigned int g_a;
unsigned int g_b;
unsigned int g_c;
unsigned int g_d;

unsigned int g_chunk[16];

typedef struct s_md5 {
    int a;
    int b;
    int c;
    int d;
    int e;
    int func;
    char *set;
}               t_md5;



// hash functions
void md5(char *str);
void sha256(char *str);

// in out functions
char    *read_from_fd(int fd);

void    print_before(char *arg, char *file);
void    print_after(char *arg, char *file);

// flags and parsing functions

void    init_flags(void);
bool     set_flag(char *input);
bool     set_hash_type(char *input);
char    *util_hash_name(int type);
void    util_error(int err, char *str);
void    print_error(int type, char *str);

// utils functions

char	*ft_strnew(size_t size);
char	*ft_strdup(const char *src);
char    *ft_strjoin(char *str1, char *str2);
int		ft_strequ(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);

# endif