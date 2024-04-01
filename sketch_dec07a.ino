
#include <Adafruit_Fingerprint.h>    // Libreria  para el Sensor de huella dactilar
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C
#include <Wire.h>
#include <RTClib.h>

#define BUZER_PASIVO 10    // buzzer pasivo en pin 10
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // direccion del objero , E, RW, RS, D4, D5, D6, D7
SoftwareSerial mySerial(2, 3);     // Crear Serial para Sensor  Rx, TX del Arduino
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);  // Crea el objeto Finger comunicacion pin 2 , 3 


int motor1=A0;
int motor2=A1;
int motor3=A2;
int motor4=A3;


int pul1=4;
int pul2=5;
int pul3=6;
int pul4=7;
int pul5=8;
int mone=9;

//precio de  los 4 productos: ******************************************
int pre1=2;
int pre2=3;
int pre3=5;
int pre4=8;


int m=0,i=0,o=0,t=1,a=0,f=1,b=0;
int A=0,B=0,C=0,D=0,e=0;

void setup()  
{
  pinMode(BUZER_PASIVO, OUTPUT);  
  pinMode(pul1,INPUT);
  pinMode(pul2,INPUT);
  pinMode(pul3,INPUT);
  pinMode(pul4,INPUT);
  pinMode(pul5,INPUT);
  pinMode(mone,INPUT);

  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  
  lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
  lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
  lcd.begin(16, 2);     // 16 columnas por 2 lineas para LCD 1602A
  lcd.clear();      // limpia pantalla
  Serial.begin(9600);
  while (!Serial);       //  Yun/Leo/Micro/Zero/...


  finger.begin(57600);  // inicializa comunicacion con sensor a 57600 Baudios
  delay(5);
    if (finger.verifyPassword()) {
    Serial.println("Detectado un sensor de huella!");
  } else {
    Serial.println("No hay comunicacion con el sensor de huella");
    Serial.println("Revise las conexiones");
    while (1) { delay(1); }
  }



  if(! rtc.begin()){
    Serial.println ("Modulo RTC no encontrado");
    while(1);
  }
     // rtc.adjust (DateTime(__DATE__, __TIME__ ));  //para ajustar la hora actual de la computadora  si la quiere ajustar quitele las lineas para que sea codigo
}

void loop()                    
{
 DateTime fecha=rtc.now();

 
 if(m==0){
  lcd.setCursor(3,0);
  lcd.print("Bienvenid@");
  lcd.setCursor(0,1);
  lcd.print("Elija producto");

  
  if(digitalRead(pul5) == HIGH){
     lcd.clear();
    if(fecha.hour() <= 11){
       tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.setCursor(14,0);
      lcd.print("AM");
      lcd.setCursor(0,0);
      lcd.print("Fecha y hora:");
      lcd.setCursor(0,1);
      lcd.print(fecha.day());
      lcd.print("/");
      lcd.print(fecha.month());
      lcd.print("/");
      lcd.print(fecha.year());
      lcd.print(" ");
      lcd.print(fecha.hour());
      lcd.print(":");
      lcd.print(fecha.minute());
      delay(5000);
      lcd.clear();
    }
   else if(fecha.hour() >= 12){
     tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.setCursor(14,0);
      lcd.print("PM");
      lcd.setCursor(0,0);
      lcd.print("Fecha y hora:");
      lcd.setCursor(0,1);
      lcd.print(fecha.day());
      lcd.print("/");
      lcd.print(fecha.month());
      lcd.print("/");
      lcd.print(fecha.year());
      lcd.print(" ");
      lcd.print(fecha.hour());
      lcd.print(":");
      lcd.print(fecha.minute());
      delay(5000);
      lcd.clear();
    }
    

}
  }
  

  if(e==1){
          if(digitalRead(pul5) == HIGH){
             tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);
      tone(BUZER_PASIVO,700);
      delay(200);
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      o=0;
      m=0;
      i=0;
      t=1;
      b=0;
      f=1;
      a=0;
      A=0;
      B=0;
      C=0;
      D=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Operacion");
      lcd.setCursor(0,1);
      lcd.print("cancelada");
      delay(2000);
      lcd.clear();
      e=0;
    }
  }
  
  //******************************************************calculo para proceso de producto 1**********************************************
   if((digitalRead(pul1) == HIGH && o==0) || f == 0 ){
     tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.clear();
      m=1;
      t=0;
      b=1;
      f=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("coloque Q");
      lcd.setCursor(9,0);
      lcd.print(pre1);
      lcd.setCursor(0,1);
      lcd.print("O huella digital");
      A=1;
      B=0;
      C=0;
      D=0;
      e=1;
   }
 
    if(A==1){
    if(pre1 == i || a==1){
       tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 600);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
      digitalWrite(motor1,1);
      delay(1300);
      digitalWrite(motor1,0);
      lcd.clear();
      o=0;
      m=0;
      i=0;
      t=1;
      b=0;
      f=1;
      a=0;
      A=0;
      B=0;
      C=0;
      D=0;
      e=0;
    }

     if(digitalRead(mone)==HIGH  && t==0){
      tone(BUZER_PASIVO, 700);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 900);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
        f=1;
        o=1;
        b=0;
        lcd.clear();
        i++;
        delay(700);
        lcd.setCursor(0,0);
        lcd.print("MONEDAS puestas");
        lcd.setCursor(0,1);
        lcd.print(i);
      }
      if(b==1){
       getFingerprintIDez();
     delay(60); 
      }
    }


    //******************************************************calculo para proceso de producto 2**********************************************
   if((digitalRead(pul2) == HIGH && o==0) || f == 0 ){
     tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.clear();
      m=1;
      t=0;
      b=1;
      f=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("coloque Q");
      lcd.setCursor(9,0);
      lcd.print(pre2);
      lcd.setCursor(0,1);
      lcd.print("O huella digital");
      B=1;
      A=0;
      C=0;
      e=1;
      D=0;
   }
 
    if(B==1){
    if(pre2 == i || a==1){
      tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 600);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
      digitalWrite(motor2,1);
      delay(1300);
      digitalWrite(motor2,0);
      lcd.clear();
      o=0;
      m=0;
      i=0;
      t=1;
      b=0;
      f=1;
      a=0;
      A=0;
      B=0;
      C=0;
      D=0;
      e=0;
    }

     if(digitalRead(mone)==HIGH  && t==0){
        tone(BUZER_PASIVO, 700);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 900);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
        f=1;
        o=1;
        b=0;
        lcd.clear();
        i++;
        delay(700);
        lcd.setCursor(0,0);
        lcd.print("MONEDAS puestas");
        lcd.setCursor(0,1);
        lcd.print(i);
      }
      if(b==1){
       getFingerprintIDez();
     delay(60); 
      }
    }


     //******************************************************calculo para proceso de producto 3**********************************************
   if((digitalRead(pul3) == HIGH && o==0) || f == 0 ){
     tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.clear();
      m=1;
      t=0;
      b=1;
      f=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("coloque Q");
      lcd.setCursor(9,0);
      lcd.print(pre3);
      lcd.setCursor(0,1);
      lcd.print("O huella digital");
      C=1;
      A=0;
      B=0;
      D=0;
      e=1;
   }
 
    if(C==1){
    if(pre3 == i || a==1){
      tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 600);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
      digitalWrite(motor3,1);
      delay(1300);
      digitalWrite(motor3,0);
      lcd.clear();
      o=0;
      m=0;
      i=0;
      t=1;
      b=0;
      f=1;
      a=0;
      A=0;
      B=0;
      C=0;
      D=0;
      e=0;
    }

     if(digitalRead(mone)==HIGH  && t==0){
        tone(BUZER_PASIVO, 700);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 900);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
        f=1;
        o=1;
        b=0;
        lcd.clear();
        i++;
        delay(700);
        lcd.setCursor(0,0);
        lcd.print("MONEDAS puestas");
        lcd.setCursor(0,1);
        lcd.print(i);
      }
      if(b==1){
       getFingerprintIDez();
     delay(60); 
      }
    }


 //******************************************************calculo para proceso de producto 4**********************************************
   if((digitalRead(pul4) == HIGH && o==0) || f == 0 ){
     tone(BUZER_PASIVO, 500);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      lcd.clear();
      m=1;
      t=0;
      b=1;
      f=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("coloque Q");
      lcd.setCursor(9,0);
      lcd.print(pre4);
      lcd.setCursor(0,1);
      lcd.print("O huella digital");
      D=1;
      A=0;
      B=0;
      C=0;
      e=1;
   }
 
    if(D==1){
    if(pre4 == i || a==1){
     tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 600);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 800);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
      digitalWrite(motor4,1);
      delay(1300);
      digitalWrite(motor4,0);
      lcd.clear();
      o=0;
      m=0;
      i=0;
      t=1;
      b=0;
      f=1;
      a=0;
      A=0;
      B=0;
      C=0;
      D=0;
      e=0;
    }

     if(digitalRead(mone)==HIGH  && t==0){
        tone(BUZER_PASIVO, 700);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
      delay(200);
       tone(BUZER_PASIVO, 900);  // ejecuta el tono con la duracion
      delay(200);         // demora con valor de pausa
      noTone(BUZER_PASIVO);        // detiene reproduccion de tono
        f=1;
        o=1;
        b=0;
        lcd.clear();
        i++;
        delay(700);
        lcd.setCursor(0,0);
        lcd.print("MONEDAS puestas");
        lcd.setCursor(0,1);
        lcd.print(i);
      }
      if(b==1){
       getFingerprintIDez();
     delay(60); 
      }
    }

    
      
    
    

   
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) { 
    
    return -1;
  }
 
   if(finger.fingerID == 1  || finger.fingerID == 2){
     a=1; 
   }


   
  return finger.fingerID; 
}
