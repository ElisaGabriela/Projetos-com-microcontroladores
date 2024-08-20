## Aula 4
Implemente um projeto que detecte o pressionar de um botão e envie, via comunicação serial, quantas vezes o botão foi apertado
```C
const int botaoPin = 13;
int contador = 0;
bool estadoAtual = 0;

void setup() {
  pinMode(botaoPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  switch (estadoAtual) {
    case 0:
      if (digitalRead(botaoPin) == HIGH) {
        delay(50);
        estadoAtual = 1;
      }
      break;
    case 1:
      if (digitalRead(botaoPin) == LOW) {
        contador++; 
        Serial.print("vc apertou o botao ");
        Serial.print(contador);
        Serial.println(" vezes");
        delay(50);
        estadoAtual = 0;
      }
      break;
  }
}
```
Faça um projeto que recebe um dado serial e acende ou apaga um LED de acordo com o dado recebido. Envie de volta alguma informação se está acendendo ou apagando o LED.
```C
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  digitalWrite(13, LOW);
  delay(1000);
  Serial.println("Use L para ligar e D para desligar");
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();

    if (comando == 'L' || comando == 'l') {
      digitalWrite(13, HIGH);
      Serial.println("LED ligado");
    } else if (comando == 'D' || comando == 'd') {
      digitalWrite(13, LOW);
      Serial.println("LED desligado");
    } 
  }
}
```
Faça um projeto que mostre o valor lido de um potenciômetro via serial
```C
const int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);

  Serial.println(potValue);

  delay(1000);
}
```
Em seguida utilize a função map para imprimir valores de 0 a 255.
```C
const int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor_lido = analogRead(potPin);
  int valor_escrito = map(valor_lido, 0, 1023, 0, 255);

  Serial.println(valor_escrito);

  delay(1000);
}
```
Faça um projeto que altere a intensidade de um LED, usando pwm, baseado em valores enviados pelo potenciômetro, lidos utilizando uma porta analógica. Inclua na montagem um botão “offset” que, ao ser pressionado, torna a tensão lida no momento equivalente a uma intensidade de LED igual a zero (apagado). Apresente o valor de “offset” na serial quando o botão
for pressionado. Inclua no seu código a possibilidade de reiniciar o offset enviando “r” ou “R” a partir da serial do computador.
```C
const int ledPin = 9; 
const int potPin = A0; 
const int buttonPin = 7; 

int offset = 0; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  int valor_lido = analogRead(potPin);
  int valor_escrito = map(valor_lido, 0, 1023, 0, 255);
  
  int Estado = digitalRead(buttonPin);

  if (Estado == 0) {
    offset = valor_escrito;
    Serial.print("offset: ");
    Serial.println(offset);
    delay(50);
  }

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'r' || command == 'R') {
      offset = 0;
      Serial.println("Offset reiniciado");
    }
  }

  int valor_led = valor_escrito - offset;

  if (valor_escrito < offset) {
    valor_led = 0;
  }

  analogWrite(ledPin, valor_led);
  
}
```
