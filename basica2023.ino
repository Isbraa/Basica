#include <Servo.h>

int Echo = 11 ; // PINES PWM
int Trigger = 12 ; // PINES PWM


int uno=4; // de izquierda a derecha en el sigue linea 
int dos=5;
int tres=6;
int cuatro=7;
int cinco=10;

int lectura(){
  return (-20*digitalRead(uno)-10*digitalRead(dos)+0*digitalRead(tres)+10*digitalRead(cuatro)+20*digitalRead(cinco));
  }

// contador
int Sensor = ;//sensor ultra arriba
int CONTADOR=0;


//MOVIMIENTO

double izquierdo;
double derecho;

Servo servo_2;
Servo servo_3;

void adelante(int vel) {
  servo_3.write(((derecho - vel)));
  servo_2.write(((izquierdo + vel)));
}


void izquierda(int vel) {
  servo_2.write(((izquierdo - vel)));
  servo_3.write(((derecho - vel)));
}

void derecha(int vel) {
  servo_3.write(((derecho + vel)));
  servo_2.write(((izquierdo + vel)));
}

void atras(int vel) {
  servo_3.write((derecho+vel));
  servo_2.write(((izquierdo - vel)));
}

void parar() {
  servo_3.write(90);
  servo_2.write(90);
}

// SIGUE LINEA

void seguir(){
Serial.println ("seguir");

    
if(lectura()==0){
  
if(digitalRead(tres) == 0) {
    adelante(80);
  }
  else{
    if((digitalRead(uno) == 1) && (digitalRead(cinco) == 1)){
      adelante(80);
    }
  }
}
if(lectura()==10){
  izquierda(20);
  delay(3);
}
    
if(lectura()==20){
  izquierda(20);
  delay(3);
}
    

if(lectura()==30){
  izquierda(20);
  delay(3);
}
    

if(lectura()==-10){
  derecha(20);
  delay(3);
}
    

if(lectura()==-20){
  derecha(20);
  delay(3);
}
  
if(lectura()==-30){
  derecha(20);
  delay(3);
}

  
}

void cumple(); {
   if(A0 > 30) { 
      while (! d <25) {
        izquierda(70);
      }
        while (d <2) {
        derecha(50);
        delay(1000);
          while (! lectura == 0) {
        adelante(70);
        }
     }
    }

void zona(); {
    while (! (digitalRead(uno) && digitalRead(dos) && digitalRead(tres) && digitalRead(cuatro) && digitalRead(cinco) == 1)) { // el ultra de arriba no declarado
      adelante(80);
    }
        if ( digitalRead(uno) && digitalRead(dos) && digitalRead(tres) && digitalRead(cuatro) && digitalRead(cinco) == 1)
          parar();
          (CONTADOR = 4);
}


void setup() {
Serial.begin (9600);
pinMode (Trigger, OUTPUT);
pinMode (Echo, INPUT);
digitalWrite (Trigger, LOW); 
servo_2.attach(2);
servo_3.attach(3);
pinMode (Sensor, INPUT); 

derecho = 90;
izquierdo = 90;
}

void loop() {
// DISTANCIA
long t;
long d; 
digitalWrite (Trigger, HIGH);
delayMicroseconds (10);
digitalWrite (Trigger,LOW);
t = pulseIn (Echo, HIGH);
d = t/59;
Serial.print ("Distancia");
Serial.print (d);
Serial.print ("cm");
Serial.println ();
delay (100);

  seguir();

// CONTADOR
if ((digitalRead (Sensor)) ==LOW){
  if (CONTADOR == 1)
    CONTADOR = 0;
  else
    CONTADOR = 1;
}

Serial.println (CONTADOR);
  delay (10);

    if (digitalRead(uno) && digitalRead(dos) && digitalRead(tres) && digitalRead(cuatro) && digitalRead(cinco) == 0) {
      if(CONTADOR == 1) 
        while (! lectura == 0){
          derecha(20);
          (CONTADOR == 2);
        }
      else
        while (! lectura == 0){
          izquierda(20);
          (CONTADOR == 2);
        } 
    }
  

    

}
