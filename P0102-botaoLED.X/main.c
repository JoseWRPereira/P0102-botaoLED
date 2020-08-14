/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 23 de Setembro de 2019, 13:03
 * 
 * IDE:         MPLAB X IDE v3.15
 * Compiler:    XC8 v1.45
 * OS:          Deepin 15.11 X86_64
 * Kernel:      4.15.0-30deepin-generic
 * 
 * Objetivo: 
 *      Acionar um LED através do estado lógico de um botão
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD0     |19     |LED (source)
 *  RD3     |22     |Botão
 */

#include <xc.h>
#include "config.h"

#define LED             PORTDbits.RD0
#define BOTAO           PORTDbits.RD3

void main(void)
{
    LED = 0;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD3 = 1;
    
    while( 1 )
    {
        LED = !BOTAO;
    }
    return;
}

void main2(void)
{
    LED = 0;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD3 = 1;
    
    while( 1 )
    {
        if( BOTAO )
            LED = 1;
        else
            LED = 0;
    }
    return;
}

void main1(void)
{
    LED = 0;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD3 = 1;
    
    while( 1 )
    {
        if( BOTAO == 1 )
            LED = 1;
        else
            LED = 0;
    }
    return;
}

void main0(void)                 // Função principal = main.
{                               // Início do bloco da função main.
    PORTDbits.RD0 = 0;          // Inicia RD0 com o valor 0.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Saída.
    TRISDbits.TRISD3 = 1;       // Configura RD3 como Entrada;
                                // Não precisa inicialização do valor do pino.
    
    while( 1 )                  // Laço de repetição infinito.
    {                           // Inicio do laço de repetição.
        if( PORTDbits.RD3 == 1 )// Condição: Se o botão estiver pressionado.
            PORTDbits.RD0 = 1;  // Liga RD0.
        else                    // Senão.
            PORTDbits.RD0 = 0;  // Desliga RD0.
    }                           // Fim do laço de repetição.
    return;                     // Caracteriza main como uma função sem retorno.
}                               // Fim do bloco da função main.
