#include <stdio.h>
#include <string.h>

int indeks_HP;
int max_HP;
int indeks_ATK;
int max_ATK;
int indeks_DEF;
int max_DEF;


typedef struct
{
    int ID;
    char name[51];
    char tipe[102];
    char type1[51];
    char type2[51];
    int level;
    int stat[3];
}data_pokemon;

data_pokemon masukan_data()
{
    data_pokemon var;
    scanf ("%d", &var.ID);
    scanf ("%s", var.name);
    scanf ("%s", var.tipe);
    int len = strlen (var.tipe);
    int poin = 0;
    int indeks;
    for (int k = 0; k <= len; k++)
    {
        if (var.tipe[k] == ',')
        {
            poin = 1;
            indeks = k;
            break;
        }
    }

    if (poin == 1)
    {
        strncpy (var.type1, var.tipe, indeks);
        var.type1[indeks] = '\0';
        sprintf (var.type2, "%s", var.tipe+indeks+1);
    }
    else
    {
        strcpy (var.type1, var.tipe);
        strcpy (var.type2, "");
    }

    scanf ("%d", &var.level);

    for (int i = 0; i < 3; i++)
    {
        scanf ("%d", &var.stat[i]);
    }
    // printf ("%s dan %s", var.type1, var.type2);
    return var;
}

void banding_HP (data_pokemon var[])
{
    max_HP = 0;
    indeks_HP = 0;

    for (int i = 0; i < 6; i++)
    {
        if (max_HP < var[i].stat[0])
        {
            max_HP = var[i].stat[0];
            indeks_HP = i;
        }
    }
}

void banding_ATK (data_pokemon var[])
{
    max_ATK = 0;
    indeks_ATK = 0;

    for (int i = 0; i < 6; i++)
    {
        if (max_ATK < var[i].stat[1])
        {
            max_ATK = var[i].stat[1];
            indeks_ATK = i;
        }
    }
}

void banding_DEF (data_pokemon var[])
{
    max_DEF = 0;
    indeks_DEF = 0;

    for (int i = 0; i < 6; i++)
    {
        if (max_DEF < var[i].stat[2])
        {
            max_DEF = var[i].stat[2];
            indeks_DEF = i;
        }
    }
}

void samaan_HP (data_pokemon var[])
{
    for (int i = 0; i < 6; i++)
    {
        if (var[i].stat[0] == max_HP && i != indeks_HP)
        {
            int jumlah_stat1 = var[indeks_HP].stat[0] + var[indeks_HP].stat[1] + var[indeks_HP].stat[2];
            int jumlah_stat2 = var[i].stat[0] + var[i].stat[1] + var[i].stat[2];
            
            if (jumlah_stat1 == jumlah_stat2)
            {
                if (var[i].ID > var[indeks_HP].ID)
                {
                    indeks_HP = i;
                }
            }
            else if (jumlah_stat1 < jumlah_stat2)
            {
                indeks_HP = i;
            }
        }
    }
}

void samaan_ATK (data_pokemon var[])
{
    for (int i = 0; i < 6; i++)
    {
        if (var[i].stat[1] == max_ATK && i != indeks_ATK)
        {
            int jumlah_stat1 = var[indeks_ATK].stat[0] + var[indeks_ATK].stat[1] + var[indeks_ATK].stat[2];
            int jumlah_stat2 = var[i].stat[0] + var[i].stat[1] + var[i].stat[2];
            
            if (jumlah_stat1 == jumlah_stat2)
            {
                if (var[i].ID > var[indeks_ATK].ID)
                {
                    indeks_ATK = i;
                }
            }
            else if (jumlah_stat1 < jumlah_stat2)
            {
                indeks_ATK = i;
            }
        }
    }
}

void samaan_DEF (data_pokemon var[])
{
    for (int i = 0; i < 6; i++)
    {
        if (var[i].stat[2] == max_DEF && i != indeks_DEF)
        {
            int jumlah_stat1 = var[indeks_DEF].stat[0] + var[indeks_DEF].stat[1] + var[indeks_DEF].stat[2];
            int jumlah_stat2 = var[i].stat[0] + var[i].stat[1] + var[i].stat[2];
            
            if (jumlah_stat1 == jumlah_stat2)
            {
                if (var[i].ID > var[indeks_DEF].ID)
                {
                    indeks_DEF = i;
                }
            }
            else if (jumlah_stat1 < jumlah_stat2)
            {
                indeks_DEF = i;
            }
        }
    }
}

int main()
{
    // Your code goes here
    data_pokemon jenis_pokemon[7];
    for (int i = 0; i < 6; i++)
    {
        jenis_pokemon[i] = masukan_data();
    }

    banding_HP(jenis_pokemon);
    banding_ATK(jenis_pokemon);
    banding_DEF(jenis_pokemon);

    samaan_HP(jenis_pokemon);
    samaan_ATK(jenis_pokemon);
    samaan_DEF(jenis_pokemon);

    printf ("Best Pokemon for HP is:\n%d\n%s\n%s\n%d\n%d %d %d\n", jenis_pokemon[indeks_HP].ID, jenis_pokemon[indeks_HP].name, jenis_pokemon[indeks_HP].tipe, jenis_pokemon[indeks_HP].level, jenis_pokemon[indeks_HP].stat[0], jenis_pokemon[indeks_HP].stat[1], jenis_pokemon[indeks_HP].stat[2]);
    printf ("Best Pokemon for ATK is:\n%d\n%s\n%s\n%d\n%d %d %d\n", jenis_pokemon[indeks_ATK].ID, jenis_pokemon[indeks_ATK].name, jenis_pokemon[indeks_ATK].tipe, jenis_pokemon[indeks_ATK].level, jenis_pokemon[indeks_ATK].stat[0], jenis_pokemon[indeks_ATK].stat[1], jenis_pokemon[indeks_ATK].stat[2]);
    printf ("Best Pokemon for DEF is:\n%d\n%s\n%s\n%d\n%d %d %d\n", jenis_pokemon[indeks_DEF].ID, jenis_pokemon[indeks_DEF].name, jenis_pokemon[indeks_DEF].tipe, jenis_pokemon[indeks_DEF].level, jenis_pokemon[indeks_DEF].stat[0], jenis_pokemon[indeks_DEF].stat[1], jenis_pokemon[indeks_DEF].stat[2]);
    // char tes[17];
    // char kedua[17];

    // scanf (" %[^,]%*c %s", &tes, &kedua);

    // printf ("%s\n%s", tes, kedua);
    return 0;
}