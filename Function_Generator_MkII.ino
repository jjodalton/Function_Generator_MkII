//----------------------------------------------//
// File: Function_Generator_MkII                //
// Description: multi-purpose DDS generator		//
// Author: Jeremy Dalton                        //
// Creation Date: 30/10/2012                    //
//----------------------------------------------//

#define verbose 1 // Verbose information output setting
#define debug 1 // Debug information output setting

#define inPin 0	// Analog input pin to use
#define outPin 2	// Digital output pin to use

double analogIn = 0;
int outputDelay = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(inPin, INPUT);
	pinMode(outPin, OUTPUT);
	if (verbose >= 1) Serial.println("Function generator ready");
}

void loop()
{
	analogIn = analogRead(inPin);
	if (debug >= 1) Serial.println(analogIn);

	outputDelay = map(analogIn, 200, 1023, 500, 4); // valueIn, inLower, inUpper, outLower, outUpper [e.g. 0, 1023, 0, 250]
	if (debug >= 1) Serial.println(outputDelay);

	if (analogIn <= 200) {
		digitalWrite(outPin,LOW);
	}

	digitalWrite(outPin, HIGH);
	delay(outputDelay);
	digitalWrite(outPin, LOW);
	delay(outputDelay);
}
