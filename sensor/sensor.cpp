// definição dos PINS
#define PHOTORESISTOR_PIN A0
#define BUZZER_PIN 3

// definição dos valores mínimo e máximo
#define PHOTORESISTOR_MIN 6
#define PHOTORESISTOR_MAX 338

float getMin(float a, float b)
{
  return a < b ? a : b;
}

float getMax(float a, float b)
{
  return a > b ? a : b;
}

float getProportion(float total, float value)
{
  return getMax(0.0, getMin(total / value, 1.0));
}

void setup()
{
  Serial.begin(9600);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int photoresistorValue = analogRead(PHOTORESISTOR_PIN);

  Serial.print("valor do fotoresistor: ");
  Serial.println(photoresistorValue);

  float sensorProportionValue = getProportion(PHOTORESISTOR_MAX - PHOTORESISTOR_MIN, photoresistorValue - PHOTORESISTOR_MIN);
  analogWrite(BUZZER_PIN, PHOTORESISTOR_MIN + (sensorProportionValue * (PHOTORESISTOR_MAX - PHOTORESISTOR_MIN)));
}