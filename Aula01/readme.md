# Aula 01

Fazer um LED externo piscar, ao invés do LED on-board:

``` C
void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(1000); 
  digitalWrite(12, LOW);
  delay(1000); 
}
```
Fazer os dois LEDs piscarem simultaneamente:
``` C
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(1000); 
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1000); 
 
}
```
Fazer os dois LEDs piscarem alternadamente:

``` C
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(1000); 
  digitalWrite(12, LOW);
  delay(1000); 
  digitalWrite(11, HIGH);
  delay(1000); 
  digitalWrite(11, LOW);
  delay(1000); 
}
```
Fazer o LED externo piscar no padrão “batida de coração”:
``` C
void setup()
{
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(100); 
  digitalWrite(12, LOW);
  delay(100); 
  digitalWrite(12, HIGH);
  delay(100); 
  digitalWrite(12, LOW);
  delay(1000); 
}
```
Fazer o LED externo piscar cada vez mais lentamente com o
passar do tempo. Utilizar o botão “reset” para verificar o
retorno ao início do programa:
``` C
void setup() {
  pinMode(12, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 60000; i += 10) {
    digitalWrite(12, HIGH);
    delay(i); 
    digitalWrite(12, LOW); 
    delay(i); 
  }

}
```
Fazer o LED Externo piscar com o auxílio de duas funções extras
as quais devem ser criadas por você: ligaled(), apagaled():
``` C
void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void ligaled(int i){
  digitalWrite(i, HIGH);
}

void apagaled(int i){
  digitalWrite(i, LOW);
}

void loop() {
  ligaled(12);
  ligaled(11);
  delay(500);
  apagaled(11);
  apagaled(12);
  delay(500);

}
```
