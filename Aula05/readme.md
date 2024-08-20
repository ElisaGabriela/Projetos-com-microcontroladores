Faça um programa para acender e apagar o LED de forma que reproduza
os pulsos longos (0.6 segundos) e curtos (0.2 segundos) que compõem a
letra “A” ou “a” do código Morse. Entre um pulso e outro espere 0.4
segundos
```C
const int ledPin = 8;

void acenderLED(int tempo) {
  digitalWrite(ledPin, HIGH);
  delay(tempo);
}

void apagarLED(int tempo) {
  digitalWrite(ledPin, LOW);
  delay(tempo);
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  acenderLED(600);
  apagarLED(400); 
  acenderLED(200);
  apagarLED(400); 
  acenderLED(200);
  apagarLED(400); 

  delay(1000);
}
```
Altere o programa anterior para reproduzir a letra em código “A” apenas
quando a letra “A” do teclado for pressionada.
```C
const int ledPin = 8;

void acenderLED(int tempo) {
  digitalWrite(ledPin, HIGH);
  delay(tempo);
}

void apagarLED(int tempo) {
  digitalWrite(ledPin, LOW);
  delay(tempo);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char caractere = Serial.read();
    if (caractere == 'A' || caractere == 'a') {
      //'A' em código Morse: .- (ponto-tracinho)
      acenderLED(600); // .
      apagarLED(400);
      acenderLED(200); // -
      apagarLED(400);
      acenderLED(200); // -
      apagarLED(400);  
    }
  }
}
```
 Altere o programa anterior para que seja capaz de reproduzir todas as
vogais, quando cada uma delas for pressionada no teclado. Entre uma
letra e outra espere o tempo de 1 segundo.

```C
const int ledPin = 8;

void acenderLED(int tempo) {
  digitalWrite(ledPin, HIGH);
  delay(tempo);
}

void apagarLED(int tempo) {
  digitalWrite(ledPin, LOW);
  delay(tempo);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char caractere = Serial.read();
    if (caractere == 'A' || caractere == 'a') {
      acenderLED(600); // .
      apagarLED(400);  // espaço
      acenderLED(200); // -
      apagarLED(400);  // espaço
      acenderLED(200); // -
      apagarLED(400);  // espaço
    } else if (caractere == 'E' || caractere == 'e') {
      acenderLED(200); // .
      apagarLED(400);  // espaço
    } else if (caractere == 'I' || caractere == 'i') {
      acenderLED(200); // .
      apagarLED(200);  // espaço
      acenderLED(200); // .
      apagarLED(400);  // espaço
    } else if (caractere == 'O' || caractere == 'o') {
      acenderLED(600); // -
      apagarLED(400);  // espaço
      acenderLED(600); // -
      apagarLED(400);  // espaço
      acenderLED(600); // -
      apagarLED(400);  // espaço
    } else if (caractere == 'U' || caractere == 'u') {
      acenderLED(200); // .
      apagarLED(200);  // espaço
      acenderLED(600); // -
      apagarLED(400);  // espaço
    }
    
    delay(1000);
  }
}
```
Finalmente, modifique o programa para armazenar em um “buffer”
(máximo 100 caracteres) as vogais digitadas e apenas as reproduza em
código Morse, acendendo e apagando o LED, quando um botão for
pressionado. Reinicie a apresentação das letras no momento o botão for
pressionado.

```C
const int ledPin = 8;
const int buttonPin = 5;

char buffer[100];
int bufferIndex = 0;

void acenderLED(int tempo) {
  digitalWrite(ledPin, HIGH);
  delay(tempo);
}

void apagarLED(int tempo) {
  digitalWrite(ledPin, LOW);
  delay(tempo);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    bufferIndex = 0;
    memset(buffer, 0, sizeof(buffer));
    delay(50); 
  }
  
  if (Serial.available() > 0) {
    char caractere = Serial.read();
    if ((caractere == 'A' || caractere == 'a' || caractere == 'E' || caractere == 'e' || caractere == 'I' || caractere == 'i' || caractere == 'O' || caractere == 'o' || caractere == 'U' || caractere == 'u') && bufferIndex < 100) {
      buffer[bufferIndex++] = caractere;
    }
  }

  if (digitalRead(buttonPin) == LOW && bufferIndex > 0) {
    for (int i = 0; i < bufferIndex; i++) {
      char caractere = buffer[i];
      if (caractere == 'A' || caractere == 'a') {
        acenderLED(600); // .
        apagarLED(400);  // espaço
        acenderLED(200); // -
        apagarLED(400);  // espaço
        acenderLED(200); // -
        apagarLED(400);  // espaço
      } else if (caractere == 'E' || caractere == 'e') {
        acenderLED(200); // .
        apagarLED(400);  // espaço
      } else if (caractere == 'I' || caractere == 'i') {
        acenderLED(200); // .
        apagarLED(200);  // espaço
        acenderLED(200); // .
        apagarLED(400);  // espaço
      } else if (caractere == 'O' || caractere == 'o') {
        acenderLED(600); // -
        apagarLED(400);  // espaço
        acenderLED(600); // -
        apagarLED(400);  // espaço
        acenderLED(600); // -
        apagarLED(400);  // espaço
      } else if (caractere == 'U' || caractere == 'u') {
        acenderLED(200); // .
        apagarLED(200);  // espaço
        acenderLED(600); // -
        apagarLED(400);  // espaço
      }
      delay(1000);
    }
    bufferIndex = 0;
    memset(buffer, 0, sizeof(buffer));
  }
}
```
Faça um programa para contar o tempo durante o qual um botão foi pressionado
(função millis).

```C
const int buttonPin = 5;
const int ledPin = 8;

int buttonState = 0;      
int lastButtonState = 0;
unsigned long startTime;
unsigned long pressDuration;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      startTime = millis();
    } else { 
      pressDuration = millis() - startTime;
      Serial.print("O botao foi pressionado por ");
      Serial.print(pressDuration);
      Serial.println(" milissegundos.");

      digitalWrite(ledPin, HIGH);
      delay(pressDuration);
      digitalWrite(ledPin, LOW);
    }
  }

  lastButtonState = buttonState;
}
```
Altere o programa anterior para identificar se o tempo pressionado foi curto
(entre 0,05 e 0,5 segundos), longo (entre 0,5 e 1 segundos) ou inválido (maior do
que 1 segundos). Imprima o tipo de pulso via serial monitor. Dica: use a máquina
de estados

```C
const int buttonPin = 5;
const int ledPin = 8;

int buttonState = 0;         
int lastButtonState = 0;      
unsigned long startTime = 0;  
unsigned long pressDuration = 0;

enum State {
  WAITING,
  PRESS_DETECTED,
  SHORT_PULSE,
  LONG_PULSE,
  INVALID_PULSE
};

State state = WAITING;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  switch (state) {
    case WAITING:
      if (buttonState != lastButtonState) {
        if (buttonState == LOW) {
          startTime = millis();
          state = PRESS_DETECTED;
        }
      }
      break;

    case PRESS_DETECTED:
      if (buttonState == HIGH) {
        pressDuration = millis() - startTime;
        if (pressDuration >= 50 && pressDuration < 500) {
          Serial.println("Pulso curto");
          delay(100);
          state = SHORT_PULSE;
        } else{ //if (pressDuration >= 500 && pressDuration < 1000) {
          Serial.println("Pulso longo");
          delay(100);
          state = LONG_PULSE;
        } 
      }
      break;

    case SHORT_PULSE:
    case LONG_PULSE:
    case INVALID_PULSE:
      if (buttonState == HIGH) {
        state = WAITING;
      }
      break;
  }

  lastButtonState = buttonState;
}

```

Altere o programa anterior para detectar quando o código Morse da letra “R” for
inserido e apresente esta letra no monitor serial. Se for detectado um pulso
inválido ou o usuário passar mais de um segundo sem pressionar o botão,
voltamos para o início do reconhecimento. Dica: use outra máquina de estados

```C
const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;        
int lastButtonState = 0;     
unsigned long startTime = 0; 
unsigned long pressDuration = 0; 

enum ButtonState {
  WAITING_BUTTON_PRESS,
  BUTTON_PRESS_DETECTED,
  BUTTON_RELEASE_DETECTED
};

ButtonState buttonStateEnum = WAITING_BUTTON_PRESS;

enum LetterRState {
  WAITING_R,
  DOT_R,
  DASH_R,
  COMPLETED_R
};

LetterRState letterRState = WAITING_R;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  switch (buttonStateEnum) {
    case WAITING_BUTTON_PRESS:
      if (buttonState != lastButtonState) {
        if (buttonState == LOW) {
          startTime = millis();
          buttonStateEnum = BUTTON_PRESS_DETECTED;
        }
      }
      break;

    case BUTTON_PRESS_DETECTED:
      if (buttonState == HIGH) {
        pressDuration = millis() - startTime;
        if (pressDuration >= 50 && pressDuration < 1000) {
          buttonStateEnum = BUTTON_RELEASE_DETECTED;
        } else {
          letterRState = WAITING_R;
          buttonStateEnum = WAITING_BUTTON_PRESS;
        }
      }
      break;

    case BUTTON_RELEASE_DETECTED:
      if (buttonState == HIGH) {
        switch (letterRState) {
          case WAITING_R:
            if (pressDuration >= 50 && pressDuration < 500) {
              letterRState = DOT_R;
            } else {
              letterRState = WAITING_R;
              buttonStateEnum = WAITING_BUTTON_PRESS;
            }
            break;

          case DOT_R:
            if (pressDuration >= 50 && pressDuration < 1000) {
              letterRState = DASH_R;
            } else {
              letterRState = WAITING_R;
              buttonStateEnum = WAITING_BUTTON_PRESS;
            }
            break;

          case DASH_R:
            if (pressDuration >= 50 && pressDuration < 1000) {
              letterRState = DOT_R;
            } else {
              letterRState = WAITING_R;
              buttonStateEnum = WAITING_BUTTON_PRESS;
            }
            break;

          case COMPLETED_R:
            Serial.println("Letra R detectada");
            letterRState = WAITING_R;
            buttonStateEnum = WAITING_BUTTON_PRESS;
            break;
        }
      }
      break;
  }

  lastButtonState = buttonState;
}

```
