/****** Hatay Robot Yarışması ******/
/* Temel Çizgi İzleyen Eğitim Kodu */
/************** 2026 ***************/
// Sabitler
#define sagmotor1 7
#define sagmotor2 8
#define sagmotorpwmpin 6
#define solmotor1 3
#define solmotor2 4
#define solmotorpwmpin 5
#define MZ80 10
#define LED 13


// Değişkenler
int ortalamaHIZ=155;  // maksimum 255
byte K, gorensensor;
float Kp = 0.070, Kd = 1, Ki = 0.0001;  // PID Değişkenleri
int sensormin[8]; int sensormax[8]; int SVal[8]; int SValx[8];
int sagmotorpwm = 0; int solmotorpwm = 0; int sonhata = 0; byte cizgivar;
unsigned int pozisyon = 3500; int integral = 0; int hata = 0; int sondeger = 0;

void setup() {
  pinMode(MZ80, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(sagmotor1, OUTPUT);
  pinMode(sagmotor2, OUTPUT);
  pinMode(solmotor1, OUTPUT);
  pinMode(solmotor2, OUTPUT);
  digitalWrite(LED, LOW);  // LED Söndür
  motorDurdur(2000);       // 2 saniye motorları durdur
  digitalWrite(LED, HIGH); // LED Yak
  kalibrasyonYap();
  digitalWrite(LED, LOW);  // LED Söndür
  delay(2000);
  engelKontrol();
  //degerokuma();
}

void loop() {
  engelKontrol();
  pozisyon = sensoroku();
  PIDhesap();
  motorkontrol(solmotorpwm, sagmotorpwm);
}
