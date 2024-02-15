#include "../incs/ft_ssl.h"

void init_struct(t_md5 *t, char *str, int length) {
    (void)t;
    (void)str;
    (void)length;
    t->a = A;
    t->b = B;
    t->c = C;
    t->d = D;

    // set set_str with len stuff
}

void set_struct(t_md5 *t, int i) {
    (void)t;
    (void)i;
    // define t.a, b, ...
    // set chunk[16]
}


void do_calc_and_rot(t_md5 *t, int j) {
    (void)t;
    (void)j;
    // generate function and index
    // apply it to b ?
}

void md5(char *str) {
    t_md5 t;
    unsigned int length = (ft_strlen((char *)str) + 8) / 64 * 64 + 64;
    init_struct(&t, str, length);

    unsigned int i;
    unsigned int j;

    i = 0;
    while (i < (length * 8) / 512) {
        set_struct(&t, i);
        j = 0;
        while (j < 64) {
            do_calc_and_rot(&t, j);
        }
        // global += calc
        i++;
    }
    printf("%x%x%x%x", g_a, g_b, g_c, g_d);
    free(t.set);
}
