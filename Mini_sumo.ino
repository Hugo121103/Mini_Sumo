
#include <AFMotor.h>
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);
//Sensor ultrasonico del fente
int ECOF = 1;
int TRIGF = 2;
int distanciaF;
int duracionF;
//Sensor ultrasonico de la derecha 
int ECOI = 10;
int TRIGI = 13;
int distanciaI;
int duracionI;
//Sensor ultrasonico del Izquierda 
int ECOD = A0;
int TRIGD = A1;
int distanciaD;
int duracionD;
// sensores infrarrojo
int infra_frente = A2;
int infra_atras = A3;

// D1,D2,D10,D13   A0,A1,A2,A3,A4,A5 piner disponibres
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  // put your setup code here, to run once:
  //Sensor ultrasonico del fente
  pinMode (TRIGF, OUTPUT);
  pinMode (ECOF, INPUT);
  //Sensor ultrasonico de la derecha 
   pinMode (TRIGD, OUTPUT);
  pinMode (ECOD, INPUT);
  //Sensor ultrasonico del Izquierda 
  pinMode (TRIGI, OUTPUT);
  pinMode (ECOI, INPUT);
  //sensores 
  pinMode (infra_frente, INPUT);
    pinMode (infra_atras, INPUT);
      pinMode (infra_izquierda, INPUT);
        pinMode (infra_derecha, INPUT);  
        Motor1.run(RELEASE);
        Motor2.run(RELEASE);
        Motor3.run(RELEASE);
        Motor4.run(RELEASE);
        delay (5000);

}

void loop() {
  
 // Motor1.setSpeed(200);    // Definimos la velocidad de  Motor1
 //Motor1.run(RELEASE); //mpotor en punto muerto    
//Motor1.run(FORDWARD); //motor avance 
//Motor1.run(BACKWARD); //retroceder motor 
/// motores uno y dos Izquierda 
// motores 34 derecha 
//////////////////////cuanod el sendor ultrasonoco detecta algo deja de tomar medicion para hacer la condicional, no quiero que deje de tomar mediones

// sensor ultrasonico del frente, toamr medicion
digitalWrite (TRIGF, HIGH);
delay (1);
digitalWrite (TRIGF, LOW);
duracionF = pulseIn(ECOF, HIGH);
distanciaF = duracionF / 58.2;
// sensor ultrasonico de derecha 
digitalWrite (TRIGD, HIGH);
delay (1);
digitalWrite (TRIGD, LOW);
duracionD = pulseIn(ECOD, HIGH);
distanciaD = duracionD / 58.2;
// sensor ultrasonico de izquierda, toamr medicion
digitalWrite (TRIGI, HIGH);
delay (1);
digitalWrite (TRIGI, LOW);
duracionI = pulseIn(ECOI, HIGH);
distanciaI = duracionI / 58.2;
//medidas de sensorees infrarrojos
 int valuef = 0;
  valuef = digitalRead(infra_frente );  //lectura digital de pin
   int valuea = 0;
  valuea = digitalRead(infra_atras);  //lectura digital de pin
   int valuei= 0;
  valuei = digitalRead(infra_izquierda);  //lectura digital de pin
   int valuei = 0;
  valuei = digitalRead(infra_derecha);  //lectura digital de pin

//////// proceso de arranque
////////girar en su eje para buscar oponenete
if (distanciaF <= 30) {
  digitalWrite (TRIGF, HIGH);
delay (1);
digitalWrite (TRIGF, LOW);
duracionF = pulseIn(ECOF, HIGH);
distanciaF = duracionF / 58.2;
Motor1.setSpeed(255);    // Definimos la velocidad
Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
}
///////maniobras para no salirme

if (valuef == LOW){
  Motor1.setSpeed(250);
  Motor2.setSpeed(250);    // Definimos la velocidad
Motor3.setSpeed(250);    // Definimos la velocidad
Motor4.setSpeed(250);    // Definimos la velocidad
Motor1.run(BACKWARD); //motor avance
Motor2.run(BACKWARD); //motor avance
Motor3.run(BACKWARD); //motor avance
Motor4.run(BACKWARD); //motor avance
delay (1500);
}
if (valuea == LOW){
  Motor1.setSpeed(255);    // Definimos la velocidad
  Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (1500);
}
if (valuei == LOW){
   Motor1.setSpeed(255);
   Motor2.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
delay (150);

Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (300);
  
}
if (valued == LOW){
  Motor1.setSpeed(150);
    Motor2.setSpeed(150);
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
delay (255);
Motor3.setSpeed(150);
    Motor4.setSpeed(150);
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (300);
}
//////////RECUERDA HACER MANIOBRA PARA QUE EL IMPACTO SE DE LADO
if (distanciaF <= 5 && valuea == HIGH  ) {
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (3000);
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad

Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor3.run(BACKWARD); //motor avance
Motor4.run(BACKWARD); //motor avance
delay (350);
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(BACKWARD); //motor avance
Motor2.run(BACKWARD); //motor avance
Motor3.run(BACKWARD); //motor avance
Motor4.run(BACKWARD); //motor avance
delay (300);
////////////////checar si no quedo de lado, y que sea mas dificil que me saquen a mi 
digitalWrite (TRIGF, HIGH);
delay (1);
digitalWrite (TRIGF, LOW);
duracionF = pulseIn(ECOF, HIGH);
distanciaF = duracionF / 58.2;
 if (distanciaF <= 10 ){
  
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (250);
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
 }

 if (valuef == HIGH && distanciaF >= 30 && distanciaD>= 30 && distanciaI>= 30){
  
    Motor1.run(RELEASE);
        Motor2.run(RELEASE);
        Motor3.run(RELEASE);
        Motor4.run(RELEASE);
  }
  else {
    
  }
}else{if(distanciaF <= 5 && valuef == HIGH  ){
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (4000);
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor1.run(BACKWARD); //motor avance
Motor2.run(BACKWARD); //motor avance
Motor1.setSpeed(200);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor3.run(BACKWARD); //motor avance
Motor4.run(BACKWARD); //motor avance
delay (200);
Motor1.setSpeed(255);    // Definimos la velocidad
 Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (4000);
}
}//hacer mas rutinas de luchas
////OBRAS DE EVACION SI NO ESTOY EN LA LINEA, PERO ME TOMA DE UN LADO
///////////////////////////////////////////////////////////////////////////////PARA BUSCAR RIBAL QUE NO DE BUELTAS, NO PUEDE

////////////MANIOBRAS DE EVACION SI ESTOY EN LA LINEA
if (valuef == LOW){
  Motor1.setSpeed(250);
  Motor2.setSpeed(250);    // Definimos la velocidad
Motor3.setSpeed(250);    // Definimos la velocidad
Motor4.setSpeed(250);    // Definimos la velocidad
Motor1.run(BACKWARD); //motor avance
Motor2.run(BACKWARD); //motor avance
Motor3.run(BACKWARD); //motor avance
Motor4.run(BACKWARD); //motor avance
delay (1500);
}
if (valuea == LOW){
  Motor1.setSpeed(255);    // Definimos la velocidad
  Motor2.setSpeed(255);    // Definimos la velocidad
Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (1500);
}
if (valuei == LOW){
   Motor1.setSpeed(255);
   Motor2.setSpeed(255);    // Definimos la velocidad
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
delay (150);

Motor3.setSpeed(255);    // Definimos la velocidad
Motor4.setSpeed(255);    // Definimos la velocidad
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (300);
  
}
if (valued == LOW){
  Motor1.setSpeed(150);
    Motor2.setSpeed(150);
Motor1.run(FORWARD); //motor avance
Motor2.run(FORWARD); //motor avance
delay (255);
Motor3.setSpeed(150);
    Motor4.setSpeed(150);
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
delay (300);
}
Motor1.setSpeed(150);    // Definimos la velocidad
 Motor2.setSpeed(150);    // Definimos la velocidad
Motor3.setSpeed(150);    // Definimos la velocidad
Motor4.setSpeed(150);    // Definimos la velocidad
Motor1.run(BACKWARD); //retroceder motor 
Motor2.run(BACKWARD); //retroceder motor 
Motor3.run(FORWARD); //motor avance
Motor4.run(FORWARD); //motor avance
}
