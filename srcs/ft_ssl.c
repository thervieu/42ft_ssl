#include "../incs/ft_ssl.h"

g_hash_type = NULL;
g_flag_p = false;
g_p_seen = false;
g_flag_s = false;
g_flag_r = false;
g_flag_q = false;

void hash(char *str, char *filename) {
    print_before(str, filename);
    if (ft_strequ(g_hash_type, "md5")) {
        md5(str);
    } else if (ft_strequ(g_hash_type, "sha256")) {
        // sha256(str);
    }
    print_after(str, filename);
}

void get_str_and_hash(char *av) {
    int fd;
    char *to_hash;

    if (av == NULL) {
        to_hash = read_from_fd(0);
    } else if (g_flag_s == true) {
        to_hash = ft_strdup(av);
    } else {
        if ((fd = open(av, O_RDONLY)) == -1) {
            print_error(3, av);
            return ;
        }
        to_hash = read_from_fd(fd);
    }
    hash(to_hash, NULL);
}

void ft_ssl(int ac, char **av) {
    init_flags();
    if (set_hash_type(av[1]) == false) {
        print_error(1, av[1]);
        return ;
    }
    
    if (ac == 2) {
        get_str_and_hash(NULL);
    }
    int i = 2;
    while (i < ac) {
        if (set_flag(av[i]) == true) {
            g_flag_p ? get_str_and_hash(NULL) : 0;
        } else {
            get_str_and_hash(av[i]);
        }
        i++;
    }
}

int main(int ac, char **av) {
    if (ac == 1) {
        print_error(0, NULL);
        return 1;
    }
    ft_ssl(ac, av);
    return 0;
}
