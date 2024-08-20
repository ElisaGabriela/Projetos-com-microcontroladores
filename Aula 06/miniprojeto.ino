#define DO_MENOR 261
#define RE 294
#define MI 329
#define FA 349
#define SOL 392
#define LA 440
#define SI 493
#define DO_MAIOR 523


char notes[] = "ccggaagffeeddc"; // MUSICA 1
int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};

void setup() {
  pinMode(9, OUTPUT); 
}

void loop() {
  for (int i = 0; i < sizeof(notes); i++) {
    int frequencia;
    switch (notes[i]) {
      case 'a':
        frequencia= DO_MENOR;
        break;
      case 'b':
        frequencia= RE;
        break;
      case 'c':
        frequencia= MI;
        break;
      case 'd':
        frequencia= FA;
        break;
      case 'e':
        frequencia= SOL;
        break;
      case 'f':
        frequencia= LA;
        break;
      case 'g':
        frequencia= SI;
        break;
      case 'h':
        frequencia= DO_MAIOR;
        break;
      default:
	      frequencia = 0;    
    }

    if (frequencia!= 0) {
	    //tone (pino, frequencia, duração)
      tone(9, frequencia, 1000 / beats[i]); 
      delay(1000 / beats[i]);
      //noTone(pino)
      noTone(9);
    } else {
      delay(1000 / beats[i]);
    }
  }
}

