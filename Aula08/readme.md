## Aula 08
Utilize um botão para alternar entre ligar e desligar um
motor utilizando o relé. Ou seja, ligar o motor quando
pressionado uma vez e desligar o motor quando for
pressionado uma segunda vez, repetindo o procedimento
ao botão ser pressionado (Use máquina de estados).

```C
const int buttonPin = 2;
const int rele = 3;   

bool motor = false;
bool estado0 = LOW;
bool estado1;  

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);
}

void loop() {
  estado1 = digitalRead(buttonPin);
  
  if (estado1 == HIGH && estado0 == LOW) {
    motor = !motor;
    
    if (motor) {
      digitalWrite(rele, HIGH);
    } else {
      digitalWrite(rele, LOW); 
    }
  }
  
  estado0 = estado1;
  
  delay(50);
}

```
