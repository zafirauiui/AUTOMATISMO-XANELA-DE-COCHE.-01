/*Esta práctica corresponde a un  funcionamento que controla o 
 *programa para a subida e a baixada dunha ventá dun coche.
 *O programa vai facer que no momento de pulsar o pulsador este
 *mova o primeiro motor, transcurridos 7s deba parar.
 *Ao volver pulsar o pulsador o segundo motor comenzará a 
 *funcionar, pero coa condición de que o primeiro esté parado.
 *AUTORA:DOLORES PATIÑO
 *DATA:ABRIL 2025
*/

//Declaración dos pins de E/S
#define PULS 10
#define RELE_ARRIBA 11
#define RELE_ABAIXO 12

//Declaración de variables globais
bool estado = 0;     //ESTADO 0 SUBINDO, ESTADO 1 BAIXANDO
int contador = 100; //IMPULSOS DO MOTOR

void setup() {
  pinMode(PULS, INPUT);
  pinMode(RELE_ARRIBA, OUTPUT);
  pinMode(RELE_ABAIXO, OUTPUT);
  
  Serial.begin(9600);
  int estado;
  
  Serial.println(estado);
}

void loop() {
  // Empeza a leer o pulsador
  if(digitalRead(PULS)) {
    estado = !estado; 
    contador = 100;
    while(digitalRead(PULS)) {    //ÚNICA LECTURA
      delay(20);
    }
  }
  // Fin de leer do pulador
  
  Serial.print(contador);
  Serial.println(contador);
  
  //Funcionamento dos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(RELE_ARRIBA, HIGH);    //MOTOR PRIMEIRO ENCENDIDO
      digitalWrite(RELE_ABAIXO, LOW);     //MOTOR SEGUNDO APAGADO
      delay(70);
      contador--;
    }
    else {
      digitalWrite(RELE_ARRIBA, LOW);    //MOTOR PRIMEIRO APAGADO
      digitalWrite(RELE_ABAIXO, HIGH);   //MOTOR SEGUNDO ENCENDIDO
      delay(70);
      contador--;
    }
  }
  else {            
    delay(100);
  }
  // Fin do funcionamento dos motores
  delay(7);
  if (contador ==0) {
    digitalWrite(RELE_ARRIBA, LOW);    //MOTOR PRIMEIRO APAGADO
    digitalWrite(RELE_ABAIXO, LOW);    //MOTOR SEGUNDCO APAGADO
  }
}
