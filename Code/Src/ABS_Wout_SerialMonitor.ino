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
}

void loop()
{ 
  if(clk[0] > 60000)
  {
    Modulate();
  }
}

void Modulate(int modTime) // modTime is what determines how long
{						               // The wheel is locked up, and is given in milliseconds 
  digitalWrite(stop, HIGH); // it will be at least 70,000 and as it increases, the 
  delay(100);              // time that the wheel is locked up should decrease 
  digitalWrite(PSI, HIGH); // exponentially. In light of this, the duty cycle
  delay(300);              // (locked/cycle time) should decrease as the number jumps 
  digitalWrite(PSI, LOW);  // a larger gap. Another variable can be calculated for this
  delay(100);              // every time an interrupt is raised.
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

}

