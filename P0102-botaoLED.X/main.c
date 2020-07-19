/*
 * File:   main.c
 * Author: curtaeletronica
 *
 * Created on 23 de Setembro de 2019, 13:03
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Acionar um LED atrav�s do estado l�gico de um bot�o
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 *  RD0     |19     |LED
 *  RD3     |22     |Bot�o
 */


#include <xc.h>                 // Inclui biblioteca padr�o do compilador XC8 
                                // para microcontroladores Microchip.
#include "config.h"             // Inclui arq. de config. (biblioteca) local.

void main(void)                 // Fun��o principal = main.
{                               // In�cio do bloco da fun��o main.
    PORTDbits.RD0 = 0;          // Inicia RD0 com o valor 0.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Sa�da.
    TRISDbits.TRISD3 = 1;       // Configura RD3 como Entrada;
                                // N�o precisa inicializa��o do valor do pino.
    
    while( 1 )                  // La�o de repeti��o infinito.
    {                           // Inicio do la�o de repeti��o.
        if( PORTDbits.RD3 == 1 )// Condi��o: Se o bot�o estiver pressionado.
            PORTDbits.RD0 = 1;  // Liga RD0.
        else                    // Sen�o.
            PORTDbits.RD0 = 0;  // Desliga RD0.
    }                           // Fim do la�o de repeti��o.
    return;                     // Caracteriza main como uma fun��o sem retorno.
}                               // Fim do bloco da fun��o main.
