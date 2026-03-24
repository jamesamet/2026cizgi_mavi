# 2026cizgi_mavi
meb yeni robotu.

## 2026 Güncellemesi (2000RPM + 2 Sürücü)
- Motorlar 1000RPM'den 2000RPM'e çıkarıldığı için temel hız ve PID değerleri düşürülüp yumuşatıldı.
- Kodda iki ayrı sürücü enable pini tanımlandı:
  - `surucu1EN -> D11`
  - `surucu2EN -> D12`
- Kart bağlantınızda sürücülerin EN/STBY pinleri farklıysa `TemelCizgi2026.ino` içindeki pin numaralarını güncelleyin.
- Motor sürüşünde ani PWM sıçramasını engelleyen rampa limiti eklendi.
- Sensör okuma bölümüne sıfıra bölme koruması eklendi.
- Engel algılama, 100ms doğrulama ile yapılıp yarış bitiminde robot kalıcı olarak güvenli şekilde durduruluyor.
