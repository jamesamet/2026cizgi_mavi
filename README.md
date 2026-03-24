diff --git a/README.md b/README.md
index c3be25dc48447c932895f6dd9741d97e375194bf..7248cf8332bed3337dc1de6b8046269077cfdfd6 100644
--- a/README.md
+++ b/README.md
@@ -1,2 +1,11 @@
 # 2026cizgi_mavi
 meb yeni robotu.
+
+## 2026 Güncellemesi (2000RPM + 2 Sürücü)
+- Motorlar 1000RPM'den 2000RPM'e çıkarıldığı için temel hız ve PID değerleri düşürülüp yumuşatıldı.
+- Kodda iki ayrı sürücü enable pini tanımlandı:
+  - `surucu1EN -> D11`
+  - `surucu2EN -> D12`
+- Kart bağlantınızda sürücülerin EN/STBY pinleri farklıysa `TemelCizgi2026.ino` içindeki pin numaralarını güncelleyin.
+- Motor sürüşünde ani PWM sıçramasını engelleyen rampa limiti eklendi.
+- Sensör okuma bölümüne sıfıra bölme koruması eklendi.
