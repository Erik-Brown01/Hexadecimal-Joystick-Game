//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
int x;
int delayTime=5100;
int lives=3;
int score=0;
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
  do{
    x=random(0,15);
    switch(x){
      case 0:
        Display(0);
        break;
      case 1:
        Display(1);
        break;
      case 2:
        Display(2);
        break;
      case 3:
        Display(3);
        break;
      case 4:
        Display(4);
        break;
      case 5:
        Display(5);
        break;
      case 6:
        Display(6);
        break;
      case 7:
        Display(7);
        break;
      case 8:
        Display(8);
        break;
      case 9:
        Display(9);
        break;
      case 10:
        Display(10);
        break;
      case 11:
        Display(11);
        break;
      case 12:
        Display(12);
        break;
      case 13:
        Display(13);
        break;
      case 14:
        Display(14);
        break;
      case 15:
        Display(15);
        break;
    }
    delayTime=delayTime-150;
    delay(delayTime);
    if((x>0)&&(x<8)&&(x%2==1)){
      if((analogRead(X_pin)>512)&&(analogRead(Y_pin)<512)){
        Serial.print("Good Job!\n");
        score++;
      }
      else{
        Serial.print("That's not it!\n");
        lives--;
        Serial.print(lives);
        Serial.print(" lives left!\n");
      }
    }
    else if((x>0)&&(x<8)&&(x%2==0)){
      if((analogRead(X_pin)<512)&&(analogRead(Y_pin)<512)){
        Serial.print("Good Job!\n");
        score++;
      }
      else{
        Serial.print("That's not it!\n");
        lives--;
        Serial.print(lives);
        Serial.print(" lives left!\n");
      }
    }
    else if((x>8)&&(x<16)&&(x%2==0)){
      if((analogRead(X_pin)<512)&&(analogRead(Y_pin)>512)){
        Serial.print("Good Job!\n");
        score++;
      }
      else{
        Serial.print("That's not it!\n");
        lives--;
        Serial.print(lives);
        Serial.print(" lives left!\n");
      }
    }
    else if((x>8)&&(x<16)&&(x%2==1)){
      if((analogRead(X_pin)>512)&&(analogRead(Y_pin)>512)){
        Serial.print("Good Job!\n");
        score++;
      }
      else{
        Serial.print("That's not it!\n");
        lives--;
        Serial.print(lives);
        Serial.print(" lives left!\n");
      }
    }
    else if((x==8)||(x==0)){
      if((digitalRead(SW_pin))==0){
        Serial.print("Good Job!\n");
        score++;
      }
      else{
        Serial.print("That's not it!\n");
        lives--;
        Serial.print(lives);
        Serial.print(" lives left!\n");
      }
    }
  }while(lives>0);
  Serial.print("Game Over\n");
  Serial.print("Score: ");
  Serial.print(score);
  delay(10000000000000);

}
