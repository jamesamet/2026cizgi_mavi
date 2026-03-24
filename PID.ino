diff --git a/PID.ino b/PID.ino
index 1cfdd1918d69155e76aad91a7e1dc77995d3c227..df9765ece38a59e9f2a1e7af4da0b3eb1d2e5afe 100644
--- a/PID.ino
+++ b/PID.ino
@@ -1,12 +1,13 @@
-void PIDhesap()
-{  
-  hata = pozisyon - 3500;
-  integral += hata;
-  if (abs(hata) < 1000) integral = 0;
-  int duzeltmehizi = Kp * hata + Kd * (hata - sonhata) + Ki * integral;
-  sonhata = hata;
-  sagmotorpwm = ortalamaHIZ + duzeltmehizi ;
-  solmotorpwm = ortalamaHIZ - duzeltmehizi ;
-  sagmotorpwm = constrain(sagmotorpwm, -100, 255); // Hız aralığı
-  solmotorpwm = constrain(solmotorpwm, -100, 255);
-}
+void PIDhesap()
+{  
+  hata = pozisyon - 3500;
+  if (cizgivar == 0) integral = 0; // çizgi kaybında integral temizle
+  integral += hata;
+  integral = constrain(integral, -8000, 8000); // anti-windup
+  int duzeltmehizi = Kp * hata + Kd * (hata - sonhata) + Ki * integral;
+  sonhata = hata;
+  sagmotorpwm = ortalamaHIZ + duzeltmehizi ;
+  solmotorpwm = ortalamaHIZ - duzeltmehizi ;
+  sagmotorpwm = constrain(sagmotorpwm, -100, maxHIZ); // 2000RPM motorlar için sınır
+  solmotorpwm = constrain(solmotorpwm, -100, maxHIZ);
+}
