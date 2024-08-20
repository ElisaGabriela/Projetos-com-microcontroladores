## Aula 06
Faça um projeto que gere um sinal PWM “na mão”,
utilizando as funções delay ou milis do arduino. Utilize
este sinal para controlar o brilho de um LED. Inclua no
projeto um potenciômetro para controlar o brilho do LED.
Varie a frequência do sinal PWM e observe o resultado.

```C
void setup() {
 pinMode(A0,INPUT);
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
 Serial.begin(9600);
}
int frequencia=100; 
float pot;
void loop() {
 pot = map(analogRead(A0),0,1023,0,100);
 digitalWrite(13,HIGH);
 delay((1000/frequencia)*pot/100);
 digitalWrite(13,LOW);

delay((1000/frequencia)*(1-pot/100));
}
```

Faça um projeto que gere um sinal PWM usando o
comando analogWrite() para controlar o brilho de um
LED. Inclua no projeto um potenciômetro para controlar o
brilho do LED (lembre de usar uma das portas com ~ para
analogWrite()).

```C
const int ledPin = 9; 
const int potPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
}
```
## Miniprojeto
Usar o buzzer com PWM pra fazer música. Seu programa
deve ter um vetor com as notas da música, incluindo
pausas, e outro vetor do mesmo tamanho com a duração
de cada nota (vetor de inteiros, onde 1 é a duração de um
tempo de música, 2 o dobro, e assim por diante). Utilize
comandos tone() e delays. Lembre-se de dar uma pausa
pequena entre duas notas quaisquer.
