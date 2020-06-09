# Zdalnie sterowany dwukołowy pojazd

Pojazd zbudowany na mikrokontrolerze STM32F407VG Discovery

## Instrukcja:

### Aplikacja:

Interfejs graficzny aplikacji składa się z siedmiu przycisków:
* connect - nawiązanie połączenia
* disconnect - przerwanie połączenia
* Forward - jazda do przodu
* Left - obrót w lewo
* Right - obrót w prawo
* LF - skręt w lewo 
* RF - skręt w prawo

1. Po uruchomieniu urządzenia oraz aplikacji, należy wpisać w odpowiednich polach adres IP oraz port, następnie kliknąć przycisk 'connect'.

2. Po połączeniu mamy możliwość wciśnięcia przycisków odpowiadających za sterowanie pojazdem.

3. Do sterowania pojazdem można również użyć przycisków na klawiaturze (Forward - W, Left - A, Right - D, LF - Q, RF - E).

4. Aby przerwać połączenie należy kliknąć przycisk 'disconnect'.

## Elementy wykorzystane do budowy pojazdu:

* Mikrokontroler STM32F407VG Discovery
* Moduł WiFi ESP-12E na układzie ESP8266
* Ultradźwiękowe czujniki odległości HC-SR04 (3x)
* Dwukanałowy sterownik silników SparkFun TB6612FNG
* Powerbank o pojemności 5000 mAh
* Baterie AA połączone szeregowo (4x)
* Silniki DC (2x)
* Model pojazdu dwukołowego
* Klocki lego

## Technologie:

* Język C - oprogramowanie mikrokontrolera
* Język C# - aplikacja kliencka

### Biblioteki:

* dwt_stm32_delay(C)

## Autorzy:

* Mateusz Kuźniak
* Jordan Kondracki