const int ledPin = 9;         // Número del pin al que está conectado el LED (debe ser compatible con PWM)
const int micPin = A0;        // Número del pin al que está conectado el micrófono
const int threshold = 50;     // Umbral para detectar sonido
const int maxMicValue = 1023; // Valor máximo posible del micrófono

void setup() {
  pinMode(ledPin, OUTPUT);    // Configura el pin del LED como salida
  Serial.begin(9600);         // Inicializa la comunicación serial para depuración
}

void loop() {
  int micValue = analogRead(micPin);  // Lee el valor del micrófono

  // Imprime el valor del micrófono en el monitor serial (opcional)
  Serial.print("Mic Value: ");
  Serial.println(micValue);

  // Detecta si el sonido ha superado el umbral
  if (micValue > threshold) {
    // Mapea el valor del micrófono al rango de PWM (0-255)
    int ledBrightness = map(micValue, threshold, maxMicValue, 0, 255);
    analogWrite(ledPin, ledBrightness); // Ajusta el brillo del LED
  } else {
    analogWrite(ledPin, 0);  // Apaga el LED si el sonido está por debajo del umbral
  }

  delay(10);  // Pequeña demora para estabilizar las lecturas
}
