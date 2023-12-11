//define as saídas das rodas
#define FORWARD_LEFT_PIN 12                //pino de saída positiva da roda esquerda
#define BACKWARD_LEFT_PIN 8                //pino de saída negativa da roda esquerda
#define FORWARD_RIGHT_PIN 7                //pino de saída positiva da roda direita
#define BACKWARD_RIGHT_PIN 4               //pino de saída negativa da roda direita

//define as entradas e saídas do controlador de velocidade
#define SPEED_INPUT_PIN A0                 //pino que recebe as informações de velocidade
#define SPEED_OUTPUT_PIN 3                 //pino que envia o sinal de velocidade

//define a entrada do controlador de direção
#define DIRECTION_INPUT_PIN A1             //pino que recebe os dados de direção
#define DIRECTION_INPUT_MARGIN 341         //margem para ativar as direções

//função que aciona as rodas para ir para frente
void goForward() {
  digitalWrite(FORWARD_LEFT_PIN, HIGH);
  digitalWrite(BACKWARD_LEFT_PIN, LOW);
  digitalWrite(FORWARD_RIGHT_PIN, HIGH);
  digitalWrite(BACKWARD_RIGHT_PIN, LOW);
}

//função que aciona as rodas para ir para trás
void goBackward() {
  digitalWrite(FORWARD_LEFT_PIN, LOW);
  digitalWrite(BACKWARD_LEFT_PIN, HIGH);
  digitalWrite(FORWARD_RIGHT_PIN, LOW);
  digitalWrite(BACKWARD_RIGHT_PIN, HIGH);
}

//função que ativa o modo de freio
void triggerBrake() {
  digitalWrite(FORWARD_LEFT_PIN, HIGH);
  digitalWrite(BACKWARD_LEFT_PIN, HIGH);
  digitalWrite(FORWARD_RIGHT_PIN, HIGH);
  digitalWrite(BACKWARD_RIGHT_PIN, HIGH);
}

//função que desliga os motores
void shutdownMotors() {
  digitalWrite(FORWARD_LEFT_PIN, LOW);
  digitalWrite(BACKWARD_LEFT_PIN, LOW);
  digitalWrite(FORWARD_RIGHT_PIN, LOW);
  digitalWrite(BACKWARD_RIGHT_PIN, LOW);
}

//função que aciona os motores para virar para esquerda
void turnLeft() {
  digitalWrite(FORWARD_LEFT_PIN, LOW);
  digitalWrite(BACKWARD_LEFT_PIN, LOW);
  digitalWrite(FORWARD_RIGHT_PIN, HIGH);
  digitalWrite(BACKWARD_RIGHT_PIN, LOW);
}

//função que aciona os motores para virar para direita
void turnRight() {
  digitalWrite(FORWARD_LEFT_PIN, HIGH);
  digitalWrite(BACKWARD_LEFT_PIN, LOW);
  digitalWrite(FORWARD_RIGHT_PIN, LOW);
  digitalWrite(BACKWARD_RIGHT_PIN, LOW);
}

// função que define a direção do robô e retorna um valor
// booleano que indica se o robô está virando ou não
boolean updateDirection() {
  int inputValue = analogRead(DIRECTION_INPUT_PIN);

  if (inputValue < 511 - DIRECTION_INPUT_MARGIN) {
    turnLeft();
    return true;
  }

  if (inputValue > 511 + DIRECTION_INPUT_MARGIN) {
    turnRight();
    return true;
  }

  return false;
}

//função que envia o sinal para regular a velocidade dos motores
void updateSpeed(int intensity) {
  analogWrite(SPEED_OUTPUT_PIN, intensity);
}

//função que calcula o valor de saída com base no valor de entrada do pino de velocidade
int getSpeedIntensity() {
  int inputValue = analogRead(SPEED_INPUT_PIN);
  float proportion = inputValue / 1024.0;
  return (int)(proportion * 255.0);
}

void setup()
{
  pinMode(FORWARD_LEFT_PIN, OUTPUT);
  pinMode(BACKWARD_LEFT_PIN, OUTPUT);
  pinMode(FORWARD_RIGHT_PIN, OUTPUT);
  pinMode(BACKWARD_RIGHT_PIN, OUTPUT);
  pinMode(SPEED_INPUT_PIN, INPUT);
  pinMode(SPEED_OUTPUT_PIN, OUTPUT);
  pinMode(DIRECTION_INPUT_PIN, INPUT);
}

void loop()
{
  int speedIntensity = getSpeedIntensity();
  updateSpeed(speedIntensity);
  
  if (updateDirection() == false) {
    goForward();
  }
}