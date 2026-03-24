diff --git a/motorkontrol.ino b/motorkontrol.ino
index 6c589f6257da6e4a6180b5eee608f779f2bc5829..304b4bb3faa1e5a617152dd0f1b6f1bbe211707a 100644
--- a/motorkontrol.ino
+++ b/motorkontrol.ino
@@ -1,27 +1,42 @@
-void motorkontrol(int solmotorpwm, int sagmotorpwm) {
-  if (sagmotorpwm <= 0) {
-    sagmotorpwm = sagmotorpwm * (-1);
-    digitalWrite(sagmotor1, LOW);
-    digitalWrite(sagmotor2, HIGH);
-    analogWrite(sagmotorpwmpin, sagmotorpwm);
-  }
-  else {
-    digitalWrite(sagmotor1, HIGH);
-    digitalWrite(sagmotor2, LOW);
-    analogWrite(sagmotorpwmpin, sagmotorpwm);
-  }
-  if (solmotorpwm <= 0) {
-    solmotorpwm = solmotorpwm * (-1);
-    digitalWrite(solmotor1, LOW);
-    digitalWrite(solmotor2, HIGH);
-    analogWrite(solmotorpwmpin, solmotorpwm);
-  }
-  else {
-    digitalWrite(solmotor1, HIGH);
-    digitalWrite(solmotor2, LOW);
-    analogWrite(solmotorpwmpin, solmotorpwm);
-  }
-}
-void motorDurdur(int sure) {
-  motorkontrol(0, 0); delay(sure);
-}
+int sonSolPwm = 0;
+int sonSagPwm = 0;
+
+void motorkontrol(int solmotorpwm, int sagmotorpwm) {
+  const int pwmDegisimLimiti = 20; // ani hızlanmayı engelle
+
+  int hedefSolPwm = constrain(solmotorpwm, sonSolPwm - pwmDegisimLimiti, sonSolPwm + pwmDegisimLimiti);
+  int hedefSagPwm = constrain(sagmotorpwm, sonSagPwm - pwmDegisimLimiti, sonSagPwm + pwmDegisimLimiti);
+
+  if (hedefSagPwm < 0) {
+    digitalWrite(sagmotor1, LOW);
+    digitalWrite(sagmotor2, HIGH);
+  } else {
+    digitalWrite(sagmotor1, HIGH);
+    digitalWrite(sagmotor2, LOW);
+  }
+  analogWrite(sagmotorpwmpin, abs(hedefSagPwm));
+
+  if (hedefSolPwm < 0) {
+    digitalWrite(solmotor1, LOW);
+    digitalWrite(solmotor2, HIGH);
+  } else {
+    digitalWrite(solmotor1, HIGH);
+    digitalWrite(solmotor2, LOW);
+  }
+  analogWrite(solmotorpwmpin, abs(hedefSolPwm));
+
+  sonSolPwm = hedefSolPwm;
+  sonSagPwm = hedefSagPwm;
+}
+
+void motorDurdur(int sure) {
+  sonSolPwm = 0;
+  sonSagPwm = 0;
+  analogWrite(sagmotorpwmpin, 0);
+  analogWrite(solmotorpwmpin, 0);
+  digitalWrite(sagmotor1, LOW);
+  digitalWrite(sagmotor2, LOW);
+  digitalWrite(solmotor1, LOW);
+  digitalWrite(solmotor2, LOW);
+  delay(sure);
+}
