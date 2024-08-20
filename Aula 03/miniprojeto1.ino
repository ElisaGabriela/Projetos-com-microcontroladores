const int botaoPin = A0;       
const int ledPin_VERDE = 13;  
const int ledPin_VERMELHO = 8; 

int botaoEstado = 0;     
int ultimoEstado = 0;    
int estado = 0; 

void setup() {
  pinMode(botaoPin, INPUT_PULLUP); 
  pinMode(ledPin_VERDE, OUTPUT);   
  pinMode(ledPin_VERMELHO, OUTPUT);
}

void loop() {
  botaoEstado = digitalRead(botaoPin); 

 
  if (botaoEstado == LOW && ultimoEstado == HIGH) {
    delay(100); 
    estado++; 

    
    if (estado == 1) {
      digitalWrite(ledPin_VERDE, HIGH); 
      digitalWrite(ledPin_VERMELHO, LOW); 
    } else if (estado == 2) {
      digitalWrite(ledPin_VERDE, LOW);  
      digitalWrite(ledPin_VERMELHO, HIGH); 
    } else if (estado == 3) {
      digitalWrite(ledPin_VERDE, LOW);  
      digitalWrite(ledPin_VERMELHO, LOW); 
    } else if (estado == 4) {
      digitalWrite(ledPin_VERDE, HIGH); 
      digitalWrite(ledPin_VERMELHO, HIGH); 
    } else if (estado == 5) {
      digitalWrite(ledPin_VERDE, LOW);  
      digitalWrite(ledPin_VERMELHO, LOW); 
      estado = 0; 
    }
  }

  ultimoEstado = botaoEstado;
}
