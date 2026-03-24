void PIDhesap()
{  
  hata = pozisyon - 3500;
  integral += hata;
  if (abs(hata) < 1000) integral = 0;
  int duzeltmehizi = Kp * hata + Kd * (hata - sonhata) + Ki * integral;
  sonhata = hata;
  sagmotorpwm = ortalamaHIZ + duzeltmehizi ;
  solmotorpwm = ortalamaHIZ - duzeltmehizi ;
  sagmotorpwm = constrain(sagmotorpwm, -100, 255); // Hız aralığı
  solmotorpwm = constrain(solmotorpwm, -100, 255);
}
