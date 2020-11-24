/* MEKANUS ROBOTICA EDUCACIONAL
 * TESTE DE DISPLAY LED VERMELHO 4 DÍGITOS DE SETE SEGMENTOS
 * Teste simples usando lógica e diferenca de potencial. Os pinos 1, 4, 5 e 12
 * do display sao catodos, mas o acionamento de um segmento com os quatro catodos
 * conectados ao GND, ocasiona o acendimento daquele segmento em todos os dígitos.
 * 
 * Dessa maneira, a lógica baixo/alto foi usada para o acionamento de um segmento
 * específico conforme a necessidade, dispensando o uso de transitores. A lógica do
 * acionamento do catodo é entao, invertida.
 * 
 * Estes pinos podem ser conectados a um coletor  * de um transistor de uso geral
 * (BC 547, BC 548, BC 550...) de modo a escoar para  * o GND com um sinal positivo
 * na base do transistor, sendo então necessario para o  * acionamento do segmento,
 * o nível alto do pino daquele segmento e o nível alto na  * base do transitor
 * conectado ao catodo.
 */
int Pinos[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int Tempo = 250;

void setup() {
 /*
 * Os segmentos foram mapeados conforme a seguir:
 * Pino 3 - Segmento superior do digito
 * Pino 4 - Segmento superior direito do digito
 * Pino 7 - Segmento superior esquerdo do dígito
 * Pino 12 - Segmento central do dígito
 * Pino 8 - Segmento inferior direito do digito
 * Pino 11 - Segmento inferior esquerdo do digito
 * Pino 9 - Segmento inferior do digito
 * Pino 10 - ponto
 */
 
//Para a variável contador = 2, enquanto contador for menor que 14,
//é incrementado ao executar que os pinos definidos sejam saídas
for (int contador = 2; contador < 14; contador++){ 
  pinMode(Pinos[contador], OUTPUT);
}
  
digitalWrite(2,HIGH);         //1 (Pino catodo do primeiro dígito display LED)
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);         //4 (Pino catodo do segundo dígito display LED
digitalWrite(6,HIGH);         //5 (Pino catodo do terceiro dígito display LED
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);          //12 (Pino catodo do quarto dígito display LED
}

void loop() {
Zero();
Um();
Dois();
Tres();
Quatro();
Cinco();
Seis();
Sete();
Oito();
Nove();
}

void Pontos(){
digitalWrite(2,LOW);
digitalWrite(10,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}

void Zero(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Um(){
digitalWrite(2,LOW);
digitalWrite(7,HIGH);
digitalWrite(11,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Dois(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Tres(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(7,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Quatro(){
digitalWrite(2,LOW);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Cinco(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Seis(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Sete(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(7,HIGH);
digitalWrite(11,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Oito(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}
void Nove(){
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(7,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
delay(Tempo);
digitalWrite(2,HIGH);
digitalWrite(5,LOW);;
delay(Tempo);
digitalWrite(5,HIGH);;
digitalWrite(6,LOW);;
delay(Tempo);
digitalWrite(6,HIGH);;
digitalWrite(13,LOW);;
delay(Tempo);
ApagaTudo();
}

void ApagaTudo(){
digitalWrite(2,HIGH);//1
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);//4
digitalWrite(6,HIGH);//5
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);//12
}
