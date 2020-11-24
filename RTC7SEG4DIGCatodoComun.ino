/*
 * MEKANUS ROBÓTICA EDUCACIONAL
 * RELÓGIO RTC COM DISPLAY 7 SEGMENTOS 4 DÍGITOS
 * 
 * Ligação:
 * O display 7Seg4Dig CATODO COMUM é conectado ao Arduino da seguinte maneira:
 * Os pinos 1, 2, 3, 4, 5, 7, 10 e 11 recebem um limitador de corrente. Um resistor
 * de 220R, 330R, 470R ou 560R podem ser usados. Nunca ligados diretamente. Os pinos
 * Display-Arduino é conectado conforme a relação abaixo:
 * 
 * Display    Arduino
 *      1     6
 *      2     5
 *      3     9
 *      4     4
 *      5     8
 *      6     17*
 *      7     3
 *      8     16*
 *      9     15*
 *      10    7
 *      11    2
 *      12    14*
 *      
 * O RTC é conectado via I2C
 * Os funcionamentos dos segmentos são baseados em diferença de nível lógico
 */

#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
char hora[30];

int DigHora, Dig2H, Dig1Ha, Dig1H;
int Tempo = 5;
int DigMin, Dig2M, Dig1Ma, Dig1M;

void setup () {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(14,OUTPUT);
pinMode(15,OUTPUT);
pinMode(16,OUTPUT);
pinMode(17,OUTPUT);

digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);

Serial.begin(9600);
#ifdef AVR
Wire.begin();
#else
Wire1.begin(); // I2C 
#endif
rtc.begin();// aciona a função RTC

if (! rtc.isrunning()) {// se a função RTC não foi acionada
Serial.println("RTC não esta funcionando"); //
rtc.adjust(DateTime(__DATE__, __TIME__)); //caso rtc não esta funcionando ajusta a hora sincronizando com o PC
}
}

void loop () {

DateTime now = rtc.now();
sprintf( hora, "%02d:%02d:%02d", now.hour(), now.minute(), now.second() );

 DigHora = now.hour();
 Dig2H = DigHora%10;
 Dig1Ha = (DigHora-Dig2H);
 Dig1H = (Dig1Ha/10);

 DigMin = now.minute();
 Dig2M = DigMin%10;
 Dig1Ma = (DigMin-Dig2M);
 Dig1M = (Dig1Ma/10);

if (Dig1H == 0){
Numero0Pos1();delay(Tempo);
}
if (Dig1H == 1){
Numero1Pos1();delay(Tempo);
}
if (Dig1H == 2){
Numero2Pos1();delay(Tempo);
}
if (Dig2H == 0){
Numero0Pos2();delay(Tempo);
}
if (Dig2H == 1){
Numero1Pos2();delay(Tempo);
}
if (Dig2H == 2){
Numero2Pos2();delay(Tempo);
}
if (Dig2H == 3){
Numero3Pos2();delay(Tempo);
}
if (Dig2H == 4){
Numero4Pos2();delay(Tempo);
}
if (Dig2H == 5){
Numero5Pos2();delay(Tempo);
}
if (Dig2H == 6){
Numero6Pos2();delay(Tempo);
}
if (Dig2H == 7){
Numero7Pos2();delay(Tempo);
}
if (Dig2H == 8){
Numero8Pos2();delay(Tempo);
}
if (Dig2H == 9){
Numero9Pos2();delay(Tempo);
}

//MINUTOS
if (Dig1M == 0){
Numero0Pos3();delay(Tempo);
}
if (Dig1M == 1){
Numero1Pos3();delay(Tempo);
}
if (Dig1M == 2){
Numero2Pos3();delay(Tempo);
}
if (Dig1M == 3){
Numero3Pos3();delay(Tempo);
}
if (Dig1M == 4){
Numero4Pos3();delay(Tempo);
}
if (Dig1M == 5){
Numero5Pos3();delay(Tempo);
}
if (Dig2M == 0){
Numero0Pos4();delay(Tempo);
}
if (Dig2M == 1){
Numero1Pos4();delay(Tempo);
}
if (Dig2M == 2){
Numero2Pos4();delay(Tempo);
}
if (Dig2M == 3){
Numero3Pos4();delay(Tempo);
}
if (Dig2M == 4){
Numero4Pos4();delay(Tempo);
}
if (Dig2M == 5){
Numero5Pos4();delay(Tempo);
}
if (Dig2M == 6){
Numero6Pos4();delay(Tempo);
}
if (Dig2M == 7){
Numero7Pos4();delay(Tempo);
}
if (Dig2M == 8){
Numero8Pos4();delay(Tempo);
}
if (Dig2M == 9){
Numero9Pos4();delay(Tempo);
}
}

void Numero0Pos1(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,LOW);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);

}
void Numero0Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero0Pos3(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero0Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero1Pos1(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,LOW);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero1Pos2(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero1Pos3(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero1Pos4(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero2Pos1(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,LOW);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero2Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero2Pos3(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero2Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero3Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero3Pos3(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero3Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero4Pos2(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero4Pos3(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero4Pos4(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero5Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero5Pos3(){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,LOW);
digitalWrite(17,HIGH);
}
void Numero5Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero6Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero6Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero7Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero7Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero8Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero8Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
void Numero9Pos2(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,LOW);
digitalWrite(16,HIGH);
digitalWrite(17,HIGH);
}
void Numero9Pos4(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(14,HIGH);
digitalWrite(15,HIGH);
digitalWrite(16,HIGH);
digitalWrite(17,LOW);
}
