#define GREEN_PIN 2
#define YELLOW_PIN 4
#define RED_PIN 7

// definição das funções
void allowedSignal()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
}

void warningSignal()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
}

void forbiddenSignal()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}
// definição das funções

void setup()
{
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop()
{
  allowedSignal();
  delay(10000);
  warningSignal();
  delay(3000);
  forbiddenSignal();
  delay(10000);
}