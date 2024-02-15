#include "../incs/ft_ssl.h"

char    *read_from_fd(int fd) {
    char *str = ft_strnew(1);
    char *buffer = ft_strnew(BUFFER_SIZE);

    int read_rtn;
    while ((read_rtn = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[read_rtn] = '\0';
        str = ft_strjoin(str, buffer);
        buffer = ft_strnew(BUFFER_SIZE);
    }
    free(buffer);
    return str;
}

void    print_before(char *arg, char *file) {
    (void)arg;
    (void)file;
    // wip
    return ;
}

void    print_after(char *arg, char *file) {
    (void)arg;
    (void)file;
    // wip
    return ;
}