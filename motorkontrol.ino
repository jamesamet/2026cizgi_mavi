int sonSolPwm = 0;
int sonSagPwm = 0;

void motorkontrol(int solmotorpwm, int sagmotorpwm) {
  const int pwmDegisimLimiti = 20; // ani hızlanmayı engelle

  int hedefSolPwm = constrain(solmotorpwm, sonSolPwm - pwmDegisimLimiti, sonSolPwm + pwmDegisimLimiti);
  int hedefSagPwm = constrain(sagmotorpwm, sonSagPwm - pwmDegisimLimiti, sonSagPwm + pwmDegisimLimiti);

  if (hedefSagPwm < 0) {
    digitalWrite(sagmotor1, LOW);
    digitalWrite(sagmotor2, HIGH);
  } else {
    digitalWrite(sagmotor1, HIGH);
    digitalWrite(sagmotor2, LOW);
  }
  analogWrite(sagmotorpwmpin, abs(hedefSagPwm));

  if (hedefSolPwm < 0) {
    digitalWrite(solmotor1, LOW);
    digitalWrite(solmotor2, HIGH);
  } else {
    digitalWrite(solmotor1, HIGH);
    digitalWrite(solmotor2, LOW);
  }
  analogWrite(solmotorpwmpin, abs(hedefSolPwm));

  sonSolPwm = hedefSolPwm;
  sonSagPwm = hedefSagPwm;
}

void motorDurdur(int sure) {
  sonSolPwm = 0;
  sonSagPwm = 0;
  analogWrite(sagmotorpwmpin, 0);
  analogWrite(solmotorpwmpin, 0);
  digitalWrite(sagmotor1, LOW);
  digitalWrite(sagmotor2, LOW);
  digitalWrite(solmotor1, LOW);
  digitalWrite(solmotor2, LOW);
  delay(sure);
}
