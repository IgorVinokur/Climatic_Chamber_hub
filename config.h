// WiFi
#define AP_DEFAULT_SSID   "Climatic Chamber"   // Стандартное имя точки доступа ESP (До 20-ти символов)
#define AP_DEFAULT_PASS   "00000000"    // Стандартный пароль точки доступа ESP (До 20-ти символов)
#define STA_DEFAULT_SSID  ""            // Стандартное имя точки доступа роутера (До 20-ти символов)
#define STA_DEFAULT_PASS  ""            // Стандартный пароль точки доступа роутера (До 20-ти символов)
#define CONNECT_TIMEOUT 10000
#define GH_FS LittleFS
#define EE_KEY            'B'           // Ключ EEPROM (1 байт) - измени, чтобы сбросить настройки
#define STA_CONNECT_EN    0             // 1/0 - вкл./выкл. подключение к роутеру
#define OLED_CONTRAST     100           // Яркость дисплея по умолчанию (%)
//#define Debug
float temperature = 0.0;
float humidity = 0.0;


//* ============ List of libraryes ============= */
#include <Wire.h>           //  I2C
#include <FileData.h>       // EEprome replase to file
#include <LittleFS.h>       // File system
#include <GyverHub.h>       // Gyver Hub web Interface


//* ============ List of Objects ============= */
GyverHub hub("MyDevices", "Climatic Chamber", "");  //Hub - network name, device name, icon


//* ========= Глобальные переменные =========== */
struct {                                // Структура со всеми настройками
  char apSsid[21] = AP_DEFAULT_SSID;    // Имя сети для AP режима по умолчанию
  char apPass[21] = AP_DEFAULT_PASS;    // Пароль сети для AP режима по умолчанию
  char staSsid[21] = STA_DEFAULT_SSID;  // Имя сети для STA режима по умолчанию
  char staPass[21] = STA_DEFAULT_PASS;  // Пароль сети для STA режима по умолчанию
  bool staModeEn = STA_CONNECT_EN;      // Подключаться к роутеру по умолчанию?
  int gmt = 2;
  float temp = 10.0;
  float temp_hys = 0.0;
  int16_t humidity = 70;
  int humidity_hys = 0;
  int16_t drainage = 70;
  int drainage_hys = 0;
  bool sw_temp;
  bool sw_humidity;
  bool sw_drainage;
  bool sw_a_circulation;
  bool sw_ventilation;
  bool sw_q_lamp;
  bool sw_tempmode = false;  //Temperature Relay Mode : 0=NORMAL for Cooling, and 1=REVERSE for Heatting
  float fan_pwr = 100;
  int16_t air_circulation_Hours = 2;
  int16_t circulation_work_time = 2;
  int16_t venta_Hours = 2;
  int16_t venta_work_time = 2;
  int16_t quartz_Hours = 2;
  int16_t quartz_work_time = 2;
  float tempOffset = 0.0;
  int16_t humidityOffset = 0;
} mydata;
FileData data(&LittleFS, "/data.dat", EE_KEY, &mydata, sizeof(mydata));  // Insted of EEprom, write parameters to file

