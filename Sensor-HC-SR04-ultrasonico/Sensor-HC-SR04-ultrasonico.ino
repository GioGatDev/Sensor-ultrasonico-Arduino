#define Puertoecho 6
#define Puertotrig 7
int led = 8;
long duracion, distancia;   
 
void setup() {                
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  pinMode(Puertoecho, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Puertotrig, OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(led, OUTPUT);
  }
  
void loop() {
  
  digitalWrite(Puertotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Puertotrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Puertotrig, LOW);
  
  duracion = pulseIn(Puertoecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // no mide nada
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(led, LOW);               // led apagado
  }
  
   if (distancia <= 4 && distancia >= 1){
    digitalWrite(led, HIGH);                     // El led se enciende, si la distancia es menor a 10cm
    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }
  delay(400);                                // espera 400ms para que se logre ver la distancia en la consola
}
