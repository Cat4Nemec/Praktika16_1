// C++ code
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/
enum ColorsLed {
	GREEN, YELLOW, ORANGE, BLUE, RED, WHITE
};
enum StateLed {
	OFF, ON
};
class LED {
public:
	LED();
	LED(int newPin, ColorsLed newColor, StateLed newState);
	StateLed getState();
	void setState(StateLed newState);
	int getPin() { return _pin; };
	String getColor();
	ColorsLed getColorNum() { return _color; };
private:
	StateLed _state;
	int _pin;
	ColorsLed _color;
};
LED::LED() {
	_state = OFF;
	_pin = 13;
	_color = RED;
}
LED::LED(int newPin, ColorsLed newColor, StateLed newState) {
	_pin = newPin;
	_color = newColor;
	_state = newState;
}
StateLed LED::getState() {
	return _state;
}

void LED::setState(StateLed newState) {
	_state = newState;
}
String LED::getColor() {

}
LED redLed(13, RED, OFF);
LED greenLed(5, GREEN, OFF);
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9800);
	Serial.println(redLed.getState());
	redLed.setState(ON);
	Serial.println(redLed.getState());
	Serial.println("Color LED1: " + redLed.getColorNum());
	Serial.println("Color LED2: " + greenLed.getColorNum());
}

void loop()
{
	redLed.setState(ON);
	digitalWrite(redLed.getPin(), redLed.getState());
	redLed.setState(ON);
	digitalWrite(greenLed.getPin(), greenLed.getState());
	delay(200); // Wait for 1000 millisecond(s)
	redLed.setState(OFF);
	digitalWrite(redLed.getPin(), redLed.getState());
	delay(200);
}
