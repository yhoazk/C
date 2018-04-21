/*
Yazar: Fırat DEVECİ
Konu : Goerzel Algoritması
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fs              4000            // Örnekleme frekansımız, izleyeceğimiz en yüksek frekans değerinin en az iki katı olmalı
#define BINS            3               // 8 temel frekans izlenecek
#define Pi              3.141592654     // Pi sayısı tanımlanıyor
#define GOERTZEL_N      128             // 128 örnek alınacak
#define Level_Segment   8

const int   freqs    [BINS] = {220, 440, 880};
float       samples  [GOERTZEL_N];

float       coeffs   [BINS];
float       prev1    [BINS];
float       prev2    [BINS];
float       magnitude[BINS];
int         levels   [BINS];
float       n        [GOERTZEL_N];

unsigned char sample_counter    = 0;
unsigned char sample_complete   = 0;

// Goertzel için katsayılar hesaplanıyor

void coefficient(void)
{
    unsigned int k, i;
    for(i=0;i < BINS;i++)
    {
        k           =(unsigned int)(0.5 + (float)GOERTZEL_N * freqs[i] / Fs);
        coeffs[i]   = 2.0 * cos(2.0 * Pi * ((float)k/GOERTZEL_N));
    }

}

int goertzel(void)
{
    int big =0,
        i   =0;
    float val = 0,
          max = 0;

    // Geçici dizilerin içerisi temizleniyor
    for(i=0;i < BINS;i++)
    {
        prev2[i]=0;
        prev1[i]=0;
    }

    // GOERTZEL Algoritması run
    for(sample_counter=0;sample_counter < GOERTZEL_N; sample_counter++)
    {
        for(i=0;i < BINS;i++)
        {
            val     = coeffs[i] * prev1[i] - prev2[i] + (float)samples[sample_counter];
            prev2[i]= prev1[i];
            prev1[i]= val;
        }
    }

    // amplitudes are determined
    for(i=0;i < BINS;i++)
    {
        magnitude[i] = (prev1[i] * prev1[i]) + (prev2[i] * prev2[i]) - (coeffs[i] * prev1[i] * prev2[i]);
        if(magnitude[i] > max)
        {
            max=magnitude[i];
            big=i;
        }
    }

    for(i=0;i < BINS;i++)
    {
        levels[i]=(int)(Level_Segment*(float)(magnitude[i]/max));
    }

    return (big);
}

int main()
{
    int i,buyuk;
    float a;
    coefficient();

    for(i=0;i < GOERTZEL_N;i++)
    	//samples[i]=sin(2*Pi*5550*i/4000)+sin(2*Pi*11477*i/4000);
    	samples[i]=sin(2*Pi*11477*i/4000);

    buyuk=goertzel();

    printf("Yazar: Firat DEVECI\n");
    printf("Konu : Goertzel Algoritmasi\n\n");
    printf("The largest aplitude: %d\n\n",buyuk);
    printf("frecuencies      coefficient      Goertzel results\n");

    for(i=0;i < BINS;i++)
    {
        if(i==buyuk)
            printf("%d\tHz -    %f\t -  %d*\n",freqs[i],coeffs[i],levels[i]);
        else
            printf("%d\tHz -    %f\t -  %d\n",freqs[i],coeffs[i],levels[i]);

    }
    return(0);
//        getch();
}
