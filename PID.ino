void PIDhesap()
{
  hata = pozisyon - 3500;
  if (cizgivar == 0) integral = 0; // çizgi kaybında integral temizle
  integral += hata;
  integral = constrain(integral, -8000, 8000); // anti-windup
  int duzeltmehizi = Kp * hata + Kd * (hata - sonhata) + Ki * integral;
  sonhata = hata;
  sagmotorpwm = ortalamaHIZ + duzeltmehizi ;
  solmotorpwm = ortalamaHIZ - duzeltmehizi ;
  sagmotorpwm = constrain(sagmotorpwm, -100, maxHIZ); // 2000RPM motorlar için sınır
  solmotorpwm = constrain(solmotorpwm, -100, maxHIZ);
}
