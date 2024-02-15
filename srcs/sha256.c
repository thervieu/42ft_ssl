#include "../incs/ft_ssl.h"

void init_struct(t_sha256 *t, char *str, int length) {
    t->a = A;
    t->b = B;
    t->c = C;
    t->d = D;

    t->set = ft_strnew(length);
    ft_strcpy(t->set, str);
    t->set[ft_strlen(str)] = 1 << 7;

    long long len = ft_strlen(str) * 8;
    int i = 0;
    while (i < 8) {
        t->set[length - 8 + i] = (&len)[i];
        i++;
    }
}

void set_struct(t_sha256 *t, int i) {
    t->a = g_a;
    t->b = g_b;
    t->c = g_c;
    t->d = g_d;

    int j = 0;
    while (j < 16) {
        g_chunk[j] = (t->set[i * 64 + j * 4 + 0]) +
            (t->set[i * 64 + j * 4 + 1] << 8) +
            (t->set[i * 64 + j * 4 + 2] << 16) +
            (t->set[i * 64 + j * 4 + 3] << 24);
        j++;
    }
}


void do_calc_and_rot(t_sha256 *t, int j) {
    int index, func;
    if (j < 16) {
        func = F(t->b, t->c, t->d);
        index = j;
    } else if (j < 32) {
        func = G(t->b, t->c, t->d);
        index = ((j * 5) + 1) % 16;
    } else if (j < 48) {
        func = H(t->b, t->c, t->d);
        index = ((j * 3) + 1) % 16;
    } else {
        func = I(t->b, t->c, t->d);
        index = ((j * 7) + 1) % 16;
    }
    unsigned int temp = t->d;
    t->d = t->c;
    t->c = t->b;
    t->b = t->b + RotLeft(t->a + func + + g_sin_abs_pow[j] + g_chunk[index], g_rot[j]);
    t->a = temp;
}

void sha256(unsigned char *str) {
    t_sha256 t;
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
        g_a += t.a;
        g_b += t.b;
        g_c += t.c;
        g_d += t.d;
        i++;
    }
    printf("%x%x%x%x", g_a, g_b, g_c, g_d);
    free(t.set);
}
