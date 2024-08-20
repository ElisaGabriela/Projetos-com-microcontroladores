## Aula 7
Primeira Montagem: Descubra a variação de tensão causada pelo
variação de luminosidade sobre o LDR (use um divisor de tensão).

- Coloque 5V no Vin e substitua o R1 pelo LDR. A tensão de
saída deve ser lida pela porta analógica. Variando a
luminosidade do sensor, descubra a tensão lida pela porta
analógica com e sem luz (cobrindo o com o dedo LDR).
- A variação lida pela porta analógica deve ser no mínimo 80.
Se esse valor não corresponder, ajuste o R2 para que isto
ocorra.

```C
const int ldrPin = A0; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int ldrValue = analogRead(ldrPin); 
 
  Serial.println(ldrValue);

  delay(1000); 
}

```
* Com luz: 800

* Sem luz: 400

Segunda montagem: Faça o brilho da luz variar de
acordo com a luminosidade sobre o LDR.

Utilize o mapeamento do exercício anterior para fazer um
LED acender na intensidade máxima quando está escuro
e apagar quando está claro.

```C
const int ldrPin = A0; 
const int ledPin = 9;  

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);     
}

void loop() {
  int ldrValue = analogRead(ldrPin); 
 
  //Serial.println(ldrValue);
  
  int luz = map(ldrValue, 430, 800, 255, 0);

  //Serial.println(luz);

  if (luz < 0.0){
    luz = 0.0; 
  }
  if (luz > 255){
    luz = 255; 
  }
  
  analogWrite(ledPin, luz); 
  
  delay(1000); 
}

```
Controle um servomotor “na mão”, utilizando delays.
Faça com que o servo comece no ângulo zero graus (pulso
de 1ms alto seguido de 20 baixo) e vá girando até atingir
180 graus, quando deve retornar a zero e começar tudo
novamente. Obs: o servo usado por nós recebe pulsos de
0.5 a 2.5 ms

```C
#include <Servo.h>

Servo myServo; 

void setup() {
  myServo.attach(9); 
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) { 
    myServo.write(angle);  
    delay(15); 
  }
  
  delay(1000);  
  
  for (int angle = 180; angle >= 0; angle--) { 
    myServo.write(angle);  
    delay(15);  
  }
  
  delay(1000);  
}

```
Controle um servomotor, utilizando a biblioteca Servo, de
acordo com a entrada do usuário (potenciômetro, serial,
etc...)
```C
#include <Servo.h>
Servo servo;
int posicao; 
void setup()
{
  servo.attach(9);
}

void loop()
{
  int input = analogRead(A0);
  posicao = mapf(input, 0, 1024, 180, 0);
  servo.write(posicao);
}

float mapf(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x-in_min)*(out_max-out_min)/(float)(in_max-in_min)+out_min;
}
```
