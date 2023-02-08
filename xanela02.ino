/*
Automatismo de xanela dun coche subida e baixada pasando por paro.

Programa para simular a función dunha ventana de un automovil, da maneira 
simplificada. O pulsador (pin entrada 7) acciona o motor de subida (pin saida 11) o ser premido. unha 
segunda pulsación para o motor e unha terceira fai que se accione o motor de baixada (pin saida 12). 
O percorrido do motor dura 7 segundos.

Entradas: Pulsador (dixital)
Saídas: Relé (2x dixital)

Autor: Marcos Antonio Mariño Mota
Data: Febreiro de 2023
*/

#define motorArriba 11
#define motorAbaixo 12
#define pulsador     7

int estado = 1;    //valores: 0(arriba) , 1(paro) , 2(abixo) , 3(para)
int contador = 0; // Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);
  
  Serial.begin(9600);
  int estado;
  
  Serial.println(estado);
}

void loop() {
  // Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado++; 
    if(estado > 3) {
      estado = 0;
    }
    
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  // Fin da lectura do pulador
  
  Serial.print("valor do contador: ");
  Serial.println(contador);
  Serial.print("estado: ");
  Serial.println(estado);
  
  // Accionamiento dos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
      contador--;
    }
    else if(estado == 2) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70);
      contador--;
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
    }
  }
  else {             // Se non está o motor accionado, lee botón 10 veces/s
    delay(100);
  }
  // Fin de accionamentos dos motores
  delay(7);
  if (contador ==0) {
    digitalWrite(motorArriba, LOW);
    digitalWrite(motorAbaixo, LOW);
  }
}
