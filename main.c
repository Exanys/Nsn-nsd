/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vojta
 *
 * Created on September 17, 2020, 10:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "cisla.txt"
#define VYSTUP "vystup.txt"

int nsn(int cislo1, int cislo2){
    int max = (cislo1 > cislo2) ? cislo1 : cislo2;
    while(!(max % cislo1 == 0 && max % cislo2 == 0)){
        max++;
    }
    return max;
}
int nsd(int cislo1, int cislo2){
    int i = 1;
    int delitel;
    while(i <= cislo1 && i <= cislo2){
        if(cislo1 % i == 0 && cislo2 % i ==0){
            delitel = i;
        }
    i++;
    }
    return delitel;
}


int main(int argc, char** argv) {
    
    FILE * vstup;
    FILE *vystup;
    int cislo1;
    int cislo2;
    int poradi = 0;
    int poradiS = 0;
    float pocet;
    float pocetS;
    int nasobek;
    int del;
    
    if((vstup = fopen(VSTUP, "r"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VSTUP);
    if((vystup = fopen(VYSTUP, "w"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VYSTUP);
    
    printf("Vypis cisel ze souboru %s\n", VSTUP);
    printf("--------------------------------\n");
    printf("poradi cislo1 cislo2    nsn    nsd\n");
    fprintf(vystup, "Vypis delitelnych cisel ze souboru %s\n", VSTUP);
    fprintf(vystup, "--------------------------------------------\n");
    fprintf(vystup, "poradi cislo1 cislo2    nsn    nsd\n"); 
    while((fscanf(vstup,"%d %d", &cislo1, &cislo2)) != EOF){
        poradi++;
        pocet += cislo1;
        nasobek = nsn(cislo1, cislo2);
        del = nsd(cislo1, cislo2);
        printf("%5d. %6d %6d %6d %6d\n", poradi, cislo1, cislo2, nasobek, del);
        if(del > 1){
            poradiS++;
            pocetS += cislo1;
            fprintf(vystup,"%5d. %6d %6d %6d %6d\n", poradiS, cislo1, cislo2, nasobek, del);
            
        }
    }
    
    printf("Prumer cisel v prvnim sloupci je %.2f\n\n", pocet / (float)poradi);
    fprintf(vystup, "Prumer cisel v prvnim sloupci je %.2f\n\n", pocetS / (float)poradiS);
    printf("Soubor %s obsahuje %d dvojic cisel.\n\n", VSTUP, poradi);
    fprintf(vystup,"Soubor %s obsahuje %d dvojic cisel.\n", VYSTUP, poradiS);
    
    if((fclose(vstup))==EOF)
        printf("Soubor %s se nepodarilo zavrit.", VSTUP);
    if((fclose(vystup))==EOF)
        printf("Soubor %s se nepodarilo zavrit.", VYSTUP);
    else
        printf("Byl vytvoren soubor delitelnych dvojic %s.", VYSTUP);
    
    return (EXIT_SUCCESS);
}

