#include <TFT.h>  // Arduino TFT library
#include <SPI.h>  // Serial Communication

// pins für Arduino Uno
#define cs   10
#define dc   9
#define rst  8

// Obejt für Display
TFT TFTscreen = TFT(cs, dc, rst);

// Char Array für Sekunden als Char
char numberChar[11];

// Long für Sekunden als Zahl
unsigned long time;

void setup() {
  // TFT Display initialisieren
  TFTscreen.begin();

  // Hintergrund auf Schwarz setzen
  TFTscreen.background(0, 0, 0);

  // Textfarbe auf Weiß setzen
  TFTscreen.stroke(255, 255, 255);
  
  // Textgröße Setzen
  
  // Text oben links ausegben
  TFTscreen.text("Sekunden vergangen:\n ", 0, 0);
  
  TFTscreen.setTextSize(2);
}

void loop() {
  // Jede vergangene Sekunde seit Start speichern
  time = millis() / 1000;

  // Long in Char Array umwandeln
  itoa(time, numberChar, 10);

  // Textfarbe auf Weiß setzen und Zeit ausgeben
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.text(numberChar, 0, 20);

  delay(900);

  // Textfarbe auf Schwarz setzen und Zeit mit Zeit in dunkel überschreiben ("löschen")
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(numberChar, 0, 20);
}

