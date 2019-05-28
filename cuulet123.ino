//LMP35 Pin Variables
int sensorPin = A7; //the analog pin the LM35 Vout (sense) pin is connected to A0
                        //the resolution is 10 mV / degree centigrade with a
   int layer[4]={A3,A2,A1,A0}; //initializing and declaring led layers
  int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; //initializing and declaring led rows          
 /*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */

// added part by niq_ro
float vmed = 0;
float ve = 0;  

 float temperatureC;
void setup()
{

  for(int i = 0; i<16; i++)   
  {
    pinMode(column[i], OUTPUT);  //setting rows to ouput
  }
  
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
  
  randomSeed(analogRead(10));  //seeding random for random pattern
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}
 void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  for(int j=0;j<4;j++)
  {
     digitalWrite(layer[j],0);
   }
    
}
void pornire(int h,int g)
{digitalWrite(column[h],0);

digitalWrite(layer[g],1);
delay(700);
  }
void temp()
{ 
  
 vmed = 0;
 ve=0;
  
 for (int j = 0; j < 10; j++)  {
  
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
    
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 vmed = vmed + voltage;
 delay(200);
 
 }
 ve = vmed/10;
 
 
 
 // now print out the temperature
  temperatureC = ve * 100 ;  //converting from 10 mv per degree 
                                               //to degrees (voltage) times 100)
 Serial.print((int)temperatureC);

   /*for(int j=0;j<4;j++)
     for(int g=0;g<16;g++)
         pornire(g,j);*/
  int count=0;
   
   
 for(int i=3;i>=0;i--)
{ turnColumnsOff();
  for(int j=0;j<16;j++)
      {
        if( count==(int)temperatureC)
          { 
            break;
            }
        digitalWrite(layer[i],1);
        if(j==0)
         {digitalWrite(column[13],0);
         delay(100);
         digitalWrite(layer[i], 0);
         digitalWrite(column[13], 1);
         delay(100);
         }
         else
         if(j<3)
          {digitalWrite(column[16-j],0);
          delay(100);
          digitalWrite(layer[i], 0);
         // digitalWrite(column[16-j], 1);
          delay(100);
      }
         else
         if(j>=3)
           {digitalWrite(column[15-j],0);
           delay(100);
           digitalWrite(layer[i], 0);
          //digitalWrite(column[15-j], 1);
          delay(100);
          }
            count++;
        delay(400);    
        Serial.println(temperatureC);
         Serial.println(count);
        
        }
        if( count==(int)temperatureC)
           {
            break;
           }
  }
  
  
 
  }
  

  void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}
void turnEverythingOff()
 {digitalWrite(layer[0], 0);
     digitalWrite(layer[1], 0);
     digitalWrite(layer[2], 0);
     digitalWrite(layer[3], 0);
   for(int i = 0; i<16; i++)
   {delay(200);
   
     digitalWrite(column[i], 1);
     
     delay(100);
   }
  
 }
 void turnEverythingOff1()
 {digitalWrite(layer[0], 0);
     digitalWrite(layer[1], 0);
     digitalWrite(layer[2], 0);
     digitalWrite(layer[3], 0);
   for(int i = 0; i<16; i++)
   {delayMicroseconds(10);
   
     digitalWrite(column[i], 1);
     
    delayMicroseconds(10);
   }
  
 }
void randomRain()
{
  turnEverythingOff();
  int x = 20;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    int randomColumn1 = random(0,16);
    int randomColumn2 = random(0,16);
    int randomColumn3 = random(0,16);
    int randomColumn4 = random(0,16);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(column[randomColumn1], 0);
    digitalWrite(column[randomColumn2], 0);
    digitalWrite(column[randomColumn3], 0);
    digitalWrite(column[randomColumn4], 0);
    digitalWrite(layer[0], 1);
    delay(x+100);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x+50);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x+20);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+10);
    digitalWrite(layer[3], 0);
    digitalWrite(column[randomColumn], 1);
    digitalWrite(column[randomColumn1], 1);
    digitalWrite(column[randomColumn2], 1);
    digitalWrite(column[randomColumn3], 1);
    digitalWrite(column[randomColumn4], 1);
  }
}

void randomflicker_raze()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  if(randomColumn!=5 && randomColumn!=6 && randomColumn!=9 && randomColumn!=10)
  {digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(x);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(x);
  } 
  }
}
void spiralInAndOut()
{
  turnEverythingOn();
  int x = 100;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
//spiral out counter clockwise
    /*digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
//spiral in counter clock wise
   /* digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
//spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    */
  }
}



void aprinde()
{ int x=100;




digitalWrite(layer[0], 1);
digitalWrite(layer[1], 1);
digitalWrite(layer[2], 1);
digitalWrite(layer[3], 1);
for(int i=0;i<6;i++)
{
  digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);

}
  }
void spiral()
{
  turnEverythingOn();
  int x = 100;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
//spiral out counter clockwise
    /*digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
//spiral in counter clock wise
   /* digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
//spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    */
  
}
}


void lucire(int x)
{
  digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
  for(int i=0;i<16;i++)
  {
    if(i%2==1)
    {
  digitalWrite(layer[0], 1);
  digitalWrite(column[i], 0);
  //delay(x);
  digitalWrite(layer[2], 1);
  digitalWrite(column[i], 0);
  delay(x);
  digitalWrite(layer[0], 0);
  digitalWrite(column[i], 1);
  delay(x);
  
  digitalWrite(layer[2], 0);
  digitalWrite(column[i], 1);
  delay(x);
    }
    else{
    digitalWrite(layer[1], 1);
  digitalWrite(column[i], 0);
  //delay(x);
  digitalWrite(layer[3], 1);
  digitalWrite(column[i], 0);
  delay(x);
  digitalWrite(layer[1], 0);
  digitalWrite(column[i], 1);
  delay(x);
  
  digitalWrite(layer[3], 0);
  digitalWrite(column[i], 1);
  delay(x);
    }
  }
}
void raza_de_soare()
  {  turnEverythingOff();
    digitalWrite(column[5],0);
    digitalWrite(column[6],0);
    digitalWrite(column[9],0);
    digitalWrite(column[10],0);
   
    // randomflicker_raze();
     
    digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
  
   
   
   delay(900);
   //turnEverythingOff();
    int randomColumn;
  int x = 100;
   for(int i = 0; i!=120; i+=2)
  {
    randomColumn = random(0,16);
    
    if(randomColumn!=5 && randomColumn !=6 && randomColumn !=9 && randomColumn !=10  )
    {digitalWrite(column[randomColumn], 0);
    
    delay(50);
     digitalWrite(column[randomColumn], 1);
     }
  }
  delay(300);
  for(int i = 0; i!=60; i+=2)
  {
     randomColumn = random(0,16);
    int randomColumn1 = random(0,16);
     int randomColumn2 = random(0,16);
    if(randomColumn!=5 && randomColumn !=6 && randomColumn !=9 && randomColumn !=10  )
    if(randomColumn1!=5 && randomColumn1!=6&& randomColumn1!=9&& randomColumn1!=10)
    if(randomColumn2!=5 && randomColumn2!=6&& randomColumn2!=9&& randomColumn2!=10)
    {digitalWrite(column[randomColumn], 0);
    digitalWrite(column[randomColumn1], 0);
    digitalWrite(column[randomColumn2], 0);
    delay(900);
     digitalWrite(column[randomColumn], 1);
     digitalWrite(column[randomColumn1], 1);
     digitalWrite(column[randomColumn2], 1);}
   
    /*digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+50);
    digitalWrite(layer[3], 0);
    */
   
  
    
  }
    }

void fulger()
{
   /*digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
*/
  /*for(int i=15;i>=0;i--)
    {
      if(i==14)
      {
        digitalWrite(layer[0],1);
        digitalWrite(column[14],0);

        delay(100);
        digitalWrite(layer[0],0);
        
        }
    }


    
    digitalWrite(column[1],1);
    digitalWrite(layer[2],1);
    
    digitalWrite(column[4],1);
    digitalWrite(layer[8],1);

    digitalWrite(column[7],1);
    digitalWrite(layer[11],1);

    digitalWrite(column[13],1);
    digitalWrite(layer[14],1);

   */

 
 for(int h=0;h<20;h++)
  {
    digitalWrite(layer[0],1);
    delay(100);
 digitalWrite(layer[2],1);
    digitalWrite(column[15],0);
    delay(100);
  digitalWrite(column[10],0);
  delay(100);
  digitalWrite(column[5],0);
  delay(100);
  digitalWrite(column[9],0);
  delay(100);
  digitalWrite(column[0],0);
delay(100);
  digitalWrite(layer[0],0);
 digitalWrite(layer[2],0);
  delay(100);
  }
 
  
  } 
void fulger1()
{for(int h=0;h<20;h++)
  {
     digitalWrite(column[15],0);
    digitalWrite(layer[0],1);
    delay(200);
    digitalWrite(layer[0],0);
    digitalWrite(column[15],1);
    delay(200);
    
    digitalWrite(layer[2],1);
  digitalWrite(column[5],0);
  delay(200);
  digitalWrite(layer[2],0);
  digitalWrite(column[5],1);
  delay(200);
  
  digitalWrite(column[10],0);
  digitalWrite(layer[2],1);
  delay(200);
  digitalWrite(layer[2],0);
  digitalWrite(column[10],1);
  delay(200);

  
  digitalWrite(column[0],0);
  digitalWrite(layer[3],1);
  delay(200);
  digitalWrite(layer[3],0);
  digitalWrite(column[0],1);
  delay(100);
 turnEverythingOff();
  
  }
}
  void fulger2()
  {int x=400;
    
  for(int h=0;h<20;h++);
  {
    delay(x);
    digitalWrite(column[13],0);
   digitalWrite(column[14],0);
    digitalWrite(layer[0],1);
    delay(x);
    digitalWrite(layer[0],0);
    digitalWrite(column[13],1);
    digitalWrite(column[14],1);
    delay(200);
    
    digitalWrite(layer[1],1);
  digitalWrite(column[5],0);
   digitalWrite(column[6],0);
  delay(x);
  digitalWrite(layer[1],0);
  digitalWrite(column[5],1);
  digitalWrite(column[6],1);
  delay(200);
  
  digitalWrite(column[10],0);
  digitalWrite(column[9],0);
  digitalWrite(layer[2],1);
  delay(x);
  digitalWrite(layer[2],0);
  digitalWrite(column[10],1);
  digitalWrite(column[9],1);
  delay(200);

  
  digitalWrite(column[1],0);
  digitalWrite(column[2],0);
  digitalWrite(layer[3],1);
  delay(x);
  digitalWrite(layer[3],0);
  digitalWrite(column[1],1);
  digitalWrite(column[2],1);
  delay(400);

  turnEverythingOn();
     delay(100);
     turnEverythingOff(); 
     delay(100);
// turnEverythingOff();
  }
  } 

void un_fulger()
{
  for(int j=0;j<6;j++)
  {
    //coloanele din spate
    digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(100);

   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(20);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(100); 


   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(100);


   digitalWrite(column[14],0);
  digitalWrite(layer[2],1);
   delay(20);
   digitalWrite(column[14],1);
  digitalWrite(layer[2],0);
   delay(100);


   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delay(100);


   //penultimele coloane
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(100);

   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(100); 


   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(100);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
  digitalWrite(layer[2],1);
   delay(50);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
  digitalWrite(layer[2],0);
   delay(100);

   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delay(100);



//randul 2 
digitalWrite(column[5],0);
digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(200);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(100);

   digitalWrite(column[6],0);
   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(200);
   digitalWrite(column[6],1);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(100); 


   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(200);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(100);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
digitalWrite(column[6],0);
  digitalWrite(layer[2],1);
   delay(200);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
   digitalWrite(column[6],1);
  digitalWrite(layer[2],0);
   delay(100);

   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(200);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delay(100);


//primul rand

digitalWrite(column[1],0);
digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(500);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(100);

   digitalWrite(column[2],0);
   digitalWrite(column[6],0);
   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
   digitalWrite(layer[1],1);
   delay(500);
   digitalWrite(column[2],1);
   digitalWrite(column[6],1);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(100); 


   digitalWrite(column[1],0);
   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(500);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(100);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
digitalWrite(column[6],0);
digitalWrite(column[2],0);
  digitalWrite(layer[2],1);
   delay(500);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
   digitalWrite(column[6],1);
   digitalWrite(column[2],1);
  digitalWrite(layer[2],0);
   delay(100);

   digitalWrite(column[1],0);
   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(500);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delay(50);
   turnEverythingOn();
   delay(100);
   turnEverythingOff();
   delay(5);
   
   
    }
}
void norisor()
{turnEverythingOn();
 digitalWrite(layer[0],1);
 digitalWrite(layer[1],1);
 digitalWrite(layer[2],1);
 digitalWrite(layer[3],1);
 digitalWrite(column[0],1);
 delay(100);
 digitalWrite(column[1],1);
 digitalWrite(column[4],1);
 delay(100);
 digitalWrite(column[2],1);
 digitalWrite(column[5],1);
 digitalWrite(column[8],1);
 delay(100);
 digitalWrite(column[3],1);
 digitalWrite(column[6],1);
 digitalWrite(column[9],1);
 digitalWrite(column[12],1);
 delay(100);
 digitalWrite(column[7],1);
 digitalWrite(column[10],1);
 digitalWrite(column[13],1);
 delay(100);
 digitalWrite(column[11],1);
 digitalWrite(column[14],1);
delay(100);
digitalWrite(column[15],1);
delay(100); 

 
  } 


void vant()
{   
  
  for(int g=0;g<4;g++)
  {turnEverythingOff1(); 
  delay(10); 
    digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
    delay(400);

    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
    delay(200);

    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    delay(100);

    digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    delay(50);
     
   turnEverythingOff1();
   delay(60);
 digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
    
    digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    delay(400);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    delay(200);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
   delay(100);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
     delay(50); 

 turnEverythingOff1();
 delay(60);
 digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
     digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
    delay(100);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
   delay(100);
    turnEverythingOff1();
    delay(30);
     }
  }   

 void vant1()
 {
  
  for(int i=0;i<4;i++)
  {
    digitalWrite(column[12],0);
    digitalWrite(layer[0],1);
    digitalWrite(column[4],0);
    delay(50);
    digitalWrite(layer[0],0);
    digitalWrite(column[12],1);
    digitalWrite(column[4],1);
    delay(50);
    digitalWrite(column[13],0);
    digitalWrite(column[5],0);
    digitalWrite(layer[1],1);
    delay(50);
   digitalWrite(column[13],1);
   digitalWrite(column[5],1);
    digitalWrite(layer[1],0); 
    digitalWrite(column[8],0);
    digitalWrite(column[0],0);
    digitalWrite(layer[1],1);
    delay(50);
    digitalWrite(column[14],1);
    digitalWrite(layer[0],0);
    digitalWrite(column[15],0);
     digitalWrite(layer[1],1);
     
     digitalWrite(column[15],0);
     digitalWrite(layer[1],1);
     delay(50);
     digitalWrite(column[15],0);
     digitalWrite(layer[1],1);
     
  }
    }
void gheata(int x,int u,int z)
{ 
turnEverythingOff1();
  for(int i=3;i>=0;i--)
    {  digitalWrite(column[12],0);
       digitalWrite(column[3],0);
       digitalWrite(layer[i],1);
       delay(x);
       
       
        digitalWrite(column[2],0);
       digitalWrite(column[7],0);
       digitalWrite(column[8],0);
       digitalWrite(column[13],0);
         delay(x);
       
       
      
       //toate coloanele deschise 
        for(int j=0;j<16;j++)
           {digitalWrite(column[j],0);
           delay(x);
           }
       // delay(20);
         x=x-z;
         if(i==0)
         {turnEverythingOn();
         delay(u);
          }
      turnEverythingOff1();
      }
  for(int y=0;y<4;y++){digitalWrite(layer[y],1);}
    for(int t=0;t<16;t++)
       {
        digitalWrite(column[t],0);
        
       
        }
  delay(u);
  }
  void asteptare()
  { 
    turnEverythingOff1();
    for(int i=3;i>=0;i--)
   {
    digitalWrite(layer[i],1);
    delay(400);
    digitalWrite(column[5],0);
    delay(300);
    digitalWrite(column[5],1);
    digitalWrite(column[6],0);
    delay(200);
    digitalWrite(column[6],1);
    digitalWrite(column[10],0);
    delay(100);
    digitalWrite(column[10],1);
    digitalWrite(column[9],0);
    delay(50);
    digitalWrite(column[9],0);
    digitalWrite(layer[i],0);
    
   } 
   turnEverythingOff1();
   int x=100;
    for(int i=0;i<4;i++)
   {  for(int j=0;j<16;j++)
       {if(j!=5 && j!=6 && j!=9 && j!=10)
         {digitalWrite(column[j],0);
          digitalWrite(layer[i],1);
          delay(20);
          
         
          
          }
          digitalWrite(column[j],1);
          

       }
       delay(x-20);
       x=x-20;
       digitalWrite(layer[i],0);
    } 
    turnEverythingOff1();
    }

void muta_cubul()
{
  temp();
  for(int i=0;i<(int)temperatureC;i++)
  {  digitalWrite(layer[3],1);
     digitalWrite(layer[2],1);
     digitalWrite(column[15],0);
     digitalWrite(column[11],0);
     digitalWrite(column[10],0);
     digitalWrite(column[14],0);
     delay(100);
     digitalWrite(column[15],1);
     digitalWrite(column[11],1);
     digitalWrite(column[10],1);
     digitalWrite(column[14],1);

     digitalWrite(column[11],0);
     digitalWrite(column[10],0);
     digitalWrite(column[6],0);
     digitalWrite(column[7],0);

     delay(100);
     digitalWrite(column[11],1);
     digitalWrite(column[10],1);
     digitalWrite(column[6],1);
     digitalWrite(column[7],1);
     digitalWrite(layer[3],0);
     digitalWrite(layer[2],0);

     
     
     
    }
    
  }
  void unu()
  {turnEverythingOff1();

    for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
   
   digitalWrite(column[14],0);
   
   digitalWrite(column[10],0);
   
   digitalWrite(column[6],0);
   
   digitalWrite(column[2],0);
   digitalWrite(column[7],0);
    delay(1000);

   turnEverythingOff1();
   
    }

    void doi()
    { turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
      digitalWrite(column[3],0);
      digitalWrite(column[2],0);
      digitalWrite(column[1],0);
      digitalWrite(column[5],0);
      digitalWrite(column[6],0);
      digitalWrite(column[7],0);
      digitalWrite(column[11],0);
      digitalWrite(column[15],0);
      digitalWrite(column[14],0);
      digitalWrite(column[13],0);
      delay(10000);
      turnEverythingOff1();
      }
    void trei()
    {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
    digitalWrite(column[2],0);
     digitalWrite(column[1],0);
     digitalWrite(column[5],0);
     digitalWrite(column[6],0);
     digitalWrite(column[9],0);
     digitalWrite(column[13],0);
     digitalWrite(column[14],0);
     delay(10000);
     turnEverythingOff1(); 
      }  
    void patru()
    {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);

    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[9],0);
    
    digitalWrite(column[13],0);
   delay(10000);
     turnEverythingOff1(); 
      }  


    void cinci()
    {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);


    digitalWrite(column[1],0);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    digitalWrite(column[14],0);
    delay(10000);
    turnEverythingOff1();
      
      } 

  void sase()
  {
    turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);

    digitalWrite(column[1],0);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
    digitalWrite(column[13],0);
    digitalWrite(column[9],0);
    delay(10000);
    turnEverythingOff1();
    
    }   
    void sapte()
    {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);

    digitalWrite(column[2],0);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    
   
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    delay(10000);
    turnEverythingOff1();

    } 

     void zero()
     {
      turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);

    digitalWrite(column[2],0);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[6],0);
     digitalWrite(column[9],0);
    digitalWrite(column[10],0);
    digitalWrite(column[13],0);
    digitalWrite(column[14],0);
    
    delay(10000);
    turnEverythingOff1();
      }

   void noua()
   {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);

    digitalWrite(column[1],0);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
     digitalWrite(column[14],0);
    delay(10000);
    turnEverythingOff1();
    
    }
  void punct()
  {
    turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
    digitalWrite(column[6],0);
     digitalWrite(column[5],0);
     digitalWrite(column[9],0);
     digitalWrite(column[10],0);
     delay(600);
    turnEverythingOff1();
    }
    void opt()
    {turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
    digitalWrite(column[6],0);
     digitalWrite(column[5],0);
     digitalWrite(column[1],0);
     digitalWrite(column[2],0);
     delay(1000);
       
      turnEverythingOff1();
      for(int i=0;i<4;i++)
    digitalWrite(layer[i],1);
    digitalWrite(column[6],0);
     digitalWrite(column[5],0);
     digitalWrite(column[9],0);
     digitalWrite(column[10],0);
     digitalWrite(column[13],0);
     digitalWrite(column[14],0);
     delay(1000);
      turnEverythingOff1();
      } 


  void astept()
  {turnEverythingOff1();
  digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(column[9],0);
    delay(300);
    digitalWrite(column[10],0);
    delay(200);
    digitalWrite(column[6],0);
    delay(100);
     digitalWrite(column[5],0);
     delay(200);
    turnEverythingOff1();
    digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(column[9],0);
    //delay(300);
    digitalWrite(column[10],0);
    //delay(200);
    digitalWrite(column[6],0);
    //delay(100);
     digitalWrite(column[5],0);
     delay(200);

     turnEverythingOff1();
     turnColumnsOff();
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(column[9],0);
    delay(300);
    digitalWrite(column[10],0);
    delay(200);
    digitalWrite(column[6],0);
    delay(100);
     digitalWrite(column[5],0);
     delay(200);
     turnEverythingOff1();
     digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(column[9],0);
    //delay(300);
    digitalWrite(column[10],0);
    //delay(200);
    digitalWrite(column[6],0);
    //delay(100);
     digitalWrite(column[5],0);
     delay(200);
     turnEverythingOff1();
     turnColumnsOff();
     digitalWrite(layer[2],1);
     digitalWrite(layer[3],1);
    digitalWrite(column[9],0);
    delay(300);
    digitalWrite(column[10],0);
    delay(200);
    digitalWrite(column[6],0);
    delay(100);
     digitalWrite(column[5],0);
     delay(300);

     turnEverythingOff1();
     turnColumnsOff();
     digitalWrite(layer[2],1);
     digitalWrite(layer[3],1);
    digitalWrite(column[9],0);
    //delay(300);
    digitalWrite(column[10],0);
    //delay(200);
    digitalWrite(column[6],0);
    //delay(100);
     digitalWrite(column[5],0);
     delay(300);
     turnColumnsOff();
     
    } 

        
  void scrie_temp(float c)
  {  
    int d=c;
    int p1=d%10;
    int p2=d/10;
    int  rest=(c-d)*100;  
    int p3=rest%10;
    int p4=rest/10;
turnEverythingOff1();
    switch(p2){
      case 0:zero();break;
      case 1:unu();break;
      case 2:doi();break;
      case 3:trei();break;
      case 4:patru();break;
      case 5:cinci();break;
      case 6:sase();break;
      case 7:sapte();break;
      case 8:opt();break;
      case 9:noua();break;}
turnEverythingOff1();
     switch(p1){
      case 0:zero();break;
      case 1:unu();break;
      case 2:doi();break;
      case 3:trei();break;
      case 4:patru();break;
      case 5:cinci();break;
      case 6:sase();break;
      case 7:sapte();break;
      case 8:opt();break;
      case 9:noua();break;}  
turnEverythingOff1();
       switch(p4){
      case 0:zero();break;
      case 1:unu();break;
      case 2:doi();break;
      case 3:trei();break;
      case 4:patru();break;
      case 5:cinci();break;
      case 6:sase();break;
      case 7:sapte();break;
      case 8:opt();break;
      case 9:noua();break;}
turnEverythingOff1();
       switch(p3){
      case 0:zero();break;
      case 1:unu();break;
      case 2:doi();break;
      case 3:trei();break;
      case 4:patru();break;
      case 5:cinci();break;
      case 6:sase();break;
      case 7:sapte();break;
      case 8:opt();break;
      case 9:noua();break;}
      turnEverythingOff1();
   /* if(p1==0)
      zero();
    else
      if(p1==1)
        unu();
      else
        if(p1==2)
          doi(); 
          */ 
    
    } 


void coloane(float c)
{
  int d=c;
    int p1=d%10;
    int p2=d/10;
    int  rest=(c-d)*100;  
    int p3=rest%10;
    int p4=rest/10;
   turnEverythingOff1();
   delay(100);
  for(int i=0;i<p2;i++)
  {  for(int j=0;j<4;j++)
       digitalWrite(layer[j],1);
    digitalWrite(column[11],0);
    digitalWrite(column[7],0);
    delay(70);
     turnEverythingOff();
    
    }
   for(int i=0;i<p1;i++)
  {  for(int j=0;j<4;j++)
       digitalWrite(layer[j],1);
    digitalWrite(column[10],0);
    digitalWrite(column[6],0);
    delay(70);
     turnEverythingOff();
    
    }
     for(int i=0;i<p4;i++)
  {  for(int j=0;j<4;j++)
       digitalWrite(layer[j],1);
    digitalWrite(column[9],0);
    digitalWrite(column[5],0);
    delay(70);
     turnEverythingOff();
    
    }
     for(int i=0;i<p3;i++)
  {  for(int j=0;j<4;j++)
       digitalWrite(layer[j],1);
    digitalWrite(column[8],0);
    digitalWrite(column[4],0);
   delay(70);
     turnEverythingOff();
    
    }
  } 


 //toate functiile foarte rapid


 void aprinde_repede()
{ int x=10;

digitalWrite(layer[0], 1);
digitalWrite(layer[1], 1);
digitalWrite(layer[2], 1);
digitalWrite(layer[3], 1);
for(int i=0;i<6;i++)
{
  digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);

}
  }  

void raza_de_soare_repede(int d,int h)
  {  turnEverythingOff1();
    digitalWrite(column[5],0);
    digitalWrite(column[6],0);
    digitalWrite(column[9],0);
    digitalWrite(column[10],0);
   
    // randomflicker_raze();
     
    digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
  
   
   
   delay(d);
   //turnEverythingOff();
    int randomColumn;
  int x = 50;
   for(int i = 0; i!=h; i+=2)
  {
    randomColumn = random(0,16);
    
    if(randomColumn!=5 && randomColumn !=6 && randomColumn !=9 && randomColumn !=10  )
    {digitalWrite(column[randomColumn], 0);
    
    delay(20);
     digitalWrite(column[randomColumn], 1);
     }
  }
  delay(d);
  for(int i = 0; i!=60; i+=2)
  {
     randomColumn = random(0,16);
    int randomColumn1 = random(0,16);
     int randomColumn2 = random(0,16);
    if(randomColumn!=5 && randomColumn !=6 && randomColumn !=9 && randomColumn !=10  )
    if(randomColumn1!=5 && randomColumn1!=6&& randomColumn1!=9&& randomColumn1!=10)
    if(randomColumn2!=5 && randomColumn2!=6&& randomColumn2!=9&& randomColumn2!=10)
    {digitalWrite(column[randomColumn], 0);
    digitalWrite(column[randomColumn1], 0);
    digitalWrite(column[randomColumn2], 0);
    delay(d);
     digitalWrite(column[randomColumn], 1);
     digitalWrite(column[randomColumn1], 1);
     digitalWrite(column[randomColumn2], 1);}
   
    /*digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+50);
    digitalWrite(layer[3], 0);
    */
   
  
    
  }
    } 

  void norisor_repede()
{turnEverythingOn();
 digitalWrite(layer[0],1);
 digitalWrite(layer[1],1);
 digitalWrite(layer[2],1);
 digitalWrite(layer[3],1);
 digitalWrite(column[0],1);
 delay(50);
 digitalWrite(column[1],1);
 digitalWrite(column[4],1);
 delay(50);
 digitalWrite(column[2],1);
 digitalWrite(column[5],1);
 digitalWrite(column[8],1);
 delay(50);
 digitalWrite(column[3],1);
 digitalWrite(column[6],1);
 digitalWrite(column[9],1);
 digitalWrite(column[12],1);
 delay(50);
 digitalWrite(column[7],1);
 digitalWrite(column[10],1);
 digitalWrite(column[13],1);
 delay(50);
 digitalWrite(column[11],1);
 digitalWrite(column[14],1);
delay(50);
digitalWrite(column[15],1);
delay(50); 

 
  } 

void un_fulger_repede()
{
  for(int j=0;j<3;j++)
  {
    //coloanele din spate
    digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(50);

   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(20);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(50); 


   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(50);


   digitalWrite(column[14],0);
  digitalWrite(layer[2],1);
   delay(20);
   digitalWrite(column[14],1);
  digitalWrite(layer[2],0);
   delay(50);


   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(20);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delayMicroseconds(5);


   //penultimele coloane
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(50);

   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(50); 


   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(50);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
  digitalWrite(layer[2],1);
   delay(50);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
  digitalWrite(layer[2],0);
   delay(50);

   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(50);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delayMicroseconds(10);



//randul 2 
digitalWrite(column[5],0);
digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(50);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(50);

   digitalWrite(column[6],0);
   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[6],1);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(50); 


   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(50);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
digitalWrite(column[6],0);
  digitalWrite(layer[2],1);
   delay(50);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
   digitalWrite(column[6],1);
  digitalWrite(layer[2],0);
   delay(50);

   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(50);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
   delayMicroseconds(10);

//primul rand

digitalWrite(column[1],0);
digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[0],1);
   delay(50);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[0],0);
   delay(50);

   digitalWrite(column[2],0);
   digitalWrite(column[6],0);
   digitalWrite(column[10],0);
   digitalWrite(column[14],0);
   digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[2],1);
   digitalWrite(column[6],1);
   digitalWrite(column[10],1);
   digitalWrite(column[14],1);
  digitalWrite(layer[1],0);
   delay(50); 


   digitalWrite(column[1],0);
   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[1],1);
   delay(50);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[1],0);
   delay(50);


digitalWrite(column[14],0);
digitalWrite(column[10],0);
digitalWrite(column[6],0);
digitalWrite(column[2],0);
  digitalWrite(layer[2],1);
   delay(50);
   digitalWrite(column[14],1);
   digitalWrite(column[10],1);
   digitalWrite(column[6],1);
   digitalWrite(column[2],1);
  digitalWrite(layer[2],0);
   delay(50);

   digitalWrite(column[1],0);
   digitalWrite(column[5],0);
   digitalWrite(column[9],0);
   digitalWrite(column[13],0);
  digitalWrite(layer[3],1);
   delay(50);
   digitalWrite(column[1],1);
   digitalWrite(column[5],1);
   digitalWrite(column[9],1);
   digitalWrite(column[13],1);
  digitalWrite(layer[3],0);
  //delayMicroseconds(10);
  delay(50);
   turnEverythingOn();
   //delayMicroseconds(5);
   delay(200);
   turnEverythingOff1();
 delayMicroseconds(10);
   
   
    }
}

void vant_repede()
{   
  
  for(int g=0;g<2;g++)
  {turnEverythingOff1(); 
  delay(10); 
    digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
    delay(50);

    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
    delay(50);

    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    delay(50);

    digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    delay(50);
     
   turnEverythingOff1();
   delay(60);
 digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
    
    digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    delay(50);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    delay(50);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
   delay(50);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
     delay(50); 

 turnEverythingOff1();
 delay(60);
 digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    digitalWrite(layer[3],1);
     digitalWrite(column[0],0);
    digitalWrite(column[4],0);
    digitalWrite(column[8],0);
    digitalWrite(column[12],0);
    digitalWrite(column[2],0);
    digitalWrite(column[6],0);
    digitalWrite(column[10],0);
    digitalWrite(column[14],0);
    delay(50);
    digitalWrite(column[1],0);
    digitalWrite(column[5],0);
    digitalWrite(column[9],0);
    digitalWrite(column[13],0);
    digitalWrite(column[3],0);
    digitalWrite(column[7],0);
    digitalWrite(column[11],0);
    digitalWrite(column[15],0);
   delay(50);
    turnEverythingOff1();
    delay(30);
     }
  }   
  void randomRain_repede()
{
  turnEverythingOff1();
  int x = 20;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    int randomColumn1 = random(0,16);
    int randomColumn2 = random(0,16);
    int randomColumn3 = random(0,16);
    int randomColumn4 = random(0,16);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(column[randomColumn1], 0);
    digitalWrite(column[randomColumn2], 0);
    digitalWrite(column[randomColumn3], 0);
    digitalWrite(column[randomColumn4], 0);
    digitalWrite(layer[0], 1);
    delay(x+10);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x+10);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x+10);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+10);
    digitalWrite(layer[3], 0);
    digitalWrite(column[randomColumn], 1);
    digitalWrite(column[randomColumn1], 1);
    digitalWrite(column[randomColumn2], 1);
    digitalWrite(column[randomColumn3], 1);
    digitalWrite(column[randomColumn4], 1);
  }
} 

 void asteptare_repede()
  { 
    turnEverythingOff1();
    for(int i=3;i>=0;i--)
   {
    digitalWrite(layer[i],1);
    delay(30);
    digitalWrite(column[5],0);
    delay(30);
    digitalWrite(column[5],1);
    digitalWrite(column[6],0);
    delay(30);
    digitalWrite(column[6],1);
    digitalWrite(column[10],0);
    delay(30);
    digitalWrite(column[10],1);
    digitalWrite(column[9],0);
    delay(30);
    digitalWrite(column[9],0);
    digitalWrite(layer[i],0);
    
   } 
   turnEverythingOff1();
   int x=90;
    for(int i=0;i<4;i++)
   {  for(int j=0;j<16;j++)
       {if(j!=5 && j!=6 && j!=9 && j!=10)
         {digitalWrite(column[j],0);
          digitalWrite(layer[i],1);
          delay(20);
          
         
          
          }
          digitalWrite(column[j],1);
          

       }
       delay(x-20);
       x=x-20;
       digitalWrite(layer[i],0);
    } 
    turnEverythingOff1();
    }  


 void ceas()
 {
    turnEverythingOff1();
   digitalWrite(layer[0],1);
    digitalWrite(layer[1],1);
    digitalWrite(layer[2],1);
    
      
  digitalWrite(column[10],0);
  digitalWrite(column[9],0);
  digitalWrite(column[5],0);
  digitalWrite(column[6],0);
  delay(50);
  digitalWrite(layer[0],0);

digitalWrite(column[11],0);
   digitalWrite(column[7],0);
   delay(20);
    digitalWrite(column[11],1);
   digitalWrite(column[7],1);
   

   digitalWrite(column[11],0);
   digitalWrite(column[7],0);
   delay(20);
    digitalWrite(column[11],1);
   digitalWrite(column[7],1);
   
  
   
  
 
  } 
  void coloane2(float c)  {

    int d=c;
    int p1=d%10;
    int p2=d/10;
    int  rest=(c-d)*100;  
    int p3=rest%10;
    int p4=rest/10;
   turnEverythingOff1();
   delay(100);
  for(int i=0;i<p2;i++)
  {  //for(int j=0;j<4;j++)
       digitalWrite(layer[0],1);
    digitalWrite(column[3],0);
    //digitalWrite(column[7],0);
    //delay(20);
     turnEverythingOff();
    
    }
   for(int i=0;i<p1;i++)
  {  //for(int j=0;j<4;j++)
       digitalWrite(layer[0],1);
    digitalWrite(column[2],0);
   // digitalWrite(column[6],0);
    //delay(20);
     turnEverythingOff();
    
    }
     for(int i=0;i<p4;i++)
  {  //for(int j=0;j<4;j++)
       digitalWrite(layer[0],1);
    digitalWrite(column[1],0);
    //digitalWrite(column[5],0);
    //delay(20);
     turnEverythingOff();
    
    }
     for(int i=0;i<p3;i++)
  {  //for(int j=0;j<4;j++)
       digitalWrite(layer[0],1);
    digitalWrite(column[0],0);
    //digitalWrite(column[4],0);
   // delay(20);
     turnEverythingOff();
    
    } 

        
    } 


 void boom(int c)
 { for(int i=0;i<c;i++)
     {digitalWrite(layer[0],1);
      digitalWrite(layer[1],1);
      digitalWrite(layer[2],1);
      digitalWrite(layer[3],1);
       digitalWrite(column[0],0);
       digitalWrite(column[1],0);
       digitalWrite(column[2],0);
       digitalWrite(column[3],0);
       digitalWrite(column[4],0);
       digitalWrite(column[8],0);
       digitalWrite(column[12],0);
       digitalWrite(column[13],0);
       digitalWrite(column[14],0);
       digitalWrite(column[15],0);
       digitalWrite(column[11],0);
       digitalWrite(column[7],0);
       delay(100);
       digitalWrite(column[0],1);
       digitalWrite(column[1],1);
       digitalWrite(column[2],1);
       digitalWrite(column[3],1);
       digitalWrite(column[4],1);
       digitalWrite(column[8],1);
       digitalWrite(column[12],1);
       digitalWrite(column[13],1);
       digitalWrite(column[14],1);
       digitalWrite(column[15],1);
       digitalWrite(column[11],1);
       digitalWrite(column[7],1);
        //turnColumnsOff();
        delay(100);
        digitalWrite(column[5],0);
       digitalWrite(column[6],0);
       digitalWrite(column[9],0);
       digitalWrite(column[10],0);
       delay(200);
       digitalWrite(column[5],1);
       digitalWrite(column[6],1);
       digitalWrite(column[9],1);
       digitalWrite(column[10],1);
      delay(900);
      digitalWrite(column[5],0);
       digitalWrite(column[6],0);
       digitalWrite(column[9],0);
       digitalWrite(column[10],0);
       delay(200);
       digitalWrite(column[5],1);
       digitalWrite(column[6],1);
       digitalWrite(column[9],1);
       digitalWrite(column[10],1);
       //turnColumnsOff1();
      
      }
      delay(900);
      turnEverythingOff1();
      
  }     
void loop()                    
 { //temp();
  //astept();
  //aprinde();
 // scrie_temp(12.73);
 // zero();
 // unu();
  //doi();
  //trei();
  //patru();
  //cinci();
  //sase();
  //sapte();
  //opt();
  //noua();
 //temp();
  //turnEverythingOff1();
  //coloane(temperatureC);
  //delay(900);
  
  turnEverythingOff1();
  aprinde();
  turnEverythingOff1();
  delayMicroseconds(10);
  raza_de_soare();
  norisor();
  norisor();
  norisor();
  un_fulger();
  vant();
  randomRain();
  asteptare();
  gheata(400,400,130);
  turnEverythingOff1();
  lucire(100);
  turnEverythingOff1();
  delay(5);
  astept();
  temp();
  delay(5);
  boom(temperatureC);
  turnEverythingOff1();
  coloane(temperatureC);
  delay(900);
  turnEverythingOff1();
  lucire(10);
  delay(5);
  gheata(75,40,20);
  delay(5);
  asteptare_repede();
  delay(5);
  randomRain_repede();
  delay(5);
  vant_repede();
  delay(5);
  un_fulger_repede();
  delay(100);
  norisor_repede();
  norisor_repede();
  norisor_repede();
  delay(5);
  turnEverythingOff1();
  delay(5);
  raza_de_soare_repede(50,90);
  delay(100);
  turnEverythingOff1();
  delay(5);
  
 turnEverythingOff1();
  spiralInAndOut();
 delay(500);
 astept();
delay(900);






 



 
 /*
 for(int i=3;i>=0;i--)
{  for(int j=0;j<16;j++)
      {
        digitalWrite(layer[i],1);
         digitalWrite(column[j],0);
         delay(100);
        digitalWrite(layer[i],0);
         digitalWrite(column[j],1);
      }
 delay(900);
 */
 /*
 if(temperatureC<26)
 randomRain();
 else
 spiralInAndOut();*/
 
}
