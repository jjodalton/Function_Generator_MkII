//----------------------------------------------//
// File: Function_Generator_MkII                //
// Description: multi-purpose DDS generator		//
// Author: Jeremy Dalton                        //
// Creation Date: 30/10/2012                    //
//----------------------------------------------//

#define inPin 2	// Analog input pin to use
#define outPin 0	// Digital output pin to use
#define inLower 100
#define inUpper 1000

double analogIn = 0;
int outputDelay = 0;
int currentOutput = 0;

void setup()
{
	pinMode(outPin, OUTPUT);
}

void loop()
{
	analogIn = analogRead(inPin);
        currentOutput = !currentOutput;

	if (analogIn <= inLower) {
		digitalWrite(outPin, 0);
	}
        else if (analogIn >= inUpper)
        {
	  digitalWrite(outPin, currentOutput);
	  delay(2);
        }
        else 
        {
	  outputDelay = map(analogIn, inLower, inUpper, 500, 3); // valueIn, inLower, inUpper, outLower, outUpper [e.g. 100, 1023, 500, 2]
        
	  digitalWrite(outPin, currentOutput);
	  delay(outputDelay);
        }
}
