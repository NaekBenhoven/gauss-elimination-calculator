#include <stdio.h>
#include <stdlib.h>

int ordo;

void MengkonversiAugmentedKeDiagonal(float Matriks[][ordo + 1]);
void MencetakNilaiVariabel(float Matriks[][ordo + 1]);

int main()
{
    printf("Masukkan jumlah ordo matriks : ");
    scanf("%d", &ordo);
    printf("Jumlah ordo Matriks %d x %d\n", ordo, ordo);
    float matriks[ordo][ordo + 1];
    printf("masukan nilai matriks yang di input ! \n");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + 1; j++)
        {
            if (j == 0)
                printf("Matriks baris ke-%d\n", i + 1);
            printf("Matriks indeks[%d][%d] : ", i + 1, j + 1);
            fflush(stdout);
            scanf("%f", &matriks[i][j]);
        }
    }
    puts("Penginputan awal mula matriks");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo + 1; j++)
        {
            printf("%.f\t", matriks[i][j]);
            if (j == ordo - 1)
                printf("|\t");
        }
        puts("");
    }
    MengkonversiAugmentedKeDiagonal(matriks);
    MencetakNilaiVariabel(matriks);
}

void MengkonversiAugmentedKeDiagonal(float matriks[][ordo + 1])
{
    float skala;
    int perubahan = 0;
    float temp;

    puts("\nPengkonversian Menjadi Matriks Diagonal");
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (j != i)
            {
                // Mengubah isi Matriks
                skala = matriks[j][i] / matriks[i][i];
                perubahan++;
                for (int k = 0; k < ordo + 1; k++)
                {
                    matriks[j][k] -= skala * matriks[i][k];
                }

                // Hasil Perubahan Matriks
                printf("Perubahan ke-%d\n", perubahan);
                for (int x = 0; x < ordo; x++)
                {
                    for (int y = 0; y < ordo + 1; y++)
                    {
                        printf("%.f\t", matriks[x][y]);
                        if (y == ordo - 1)
                            printf("|\t");
                    }
                    puts("\n");
                }
                puts("\n");
            }
        }
    }
}

void MencetakNilaiVariabel(float matriks[][ordo + 1])
{
    puts("Nilai Semua Variabel");
    for (int i = 0; i < ordo; i++)
    {
        printf("Nilai Variabel %d : %g\n", i + 1, matriks[i][ordo] / matriks[i][i]); // %g membaca sebuah data pecahan
    }
}