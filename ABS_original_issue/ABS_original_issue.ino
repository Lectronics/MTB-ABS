int stop = 12;
int PSI = 13;
int WSSin = 2;
unsigned int clk[5];

void setup()
{
  pinMode(stop, OUTPUT);
  pinMode(PSI, OUTPUT);
  pinMode(WSSin, INPUT);
  clk[0] = 1000;
  clk[1] = 1000;
  clk[2] = 1000;
  clk[3] = 10000;
  clk[4] = 10000;
  attachInterrupt(digitalPinToInterrupt(2), clking, RISING);
  Serial.begin(9600);
}

void loop()
{ 
  if(clk[0] > 60000)
  {
    Modulate();
  }
}

void Modulate() // modTime is what determines how long
{						               // The wheel is locked up 
  digitalWrite(stop, HIGH); 
  delay(100);
  digitalWrite(PSI, HIGH);
  delay(300);
  digitalWrite(PSI, LOW);
  delay(100);
  digitalWrite(stop, LOW);
  delay(300);
}
                  
void clking()
{
    delay(10);
    clk[3] = clk[4];
    clk[4] = millis();
    clk[2] = clk[1];
    clk[1] = clk[0];
    clk[0] = clk[2] - clk[3];
  	Serial.println(clk[2]);
    Serial.println(clk[1]);
    Serial.println(clk[0]);
    Serial.println("-------");
}

