void MixColours(int BrightnessR, int BrightnessG, int BrightnessB) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, BrightnessG, BrightnessR, BrightnessB, 0);
  }
  ring.show();
  Serial.println("mixed");
  
  for (int i = 0; i < ring2.numPixels(); i++) {
    ring2.setPixelColor(i, BrightnessG, BrightnessR, BrightnessB, 0);
  }
  ring2.show();
  Serial.println("mixed2");
}

void Anger(int Brightness) {
  Serial.println("RED");
  for (int i = 0; i < 16; i++) {
    ring.setPixelColor(i, 0, Brightness, 0, 0);
  }
  ring.show();
}

void Sad() {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, 0, 0, 255, 0);
  }
  ring.show();
  Serial.println("BLUE");
}

void Happy() {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, 255, 0, 0, 0);
  }
  ring.show();
  Serial.println("Green");
}

void HalfColour(int BrightnessR2, int BrightnessG2, int BrightnessB2) {
  for (int i = 0; i < 8; i++) {
    ring.setPixelColor(i, BrightnessG2, BrightnessR2, BrightnessB2, 0);
    ring.show();
    delay(100);
  }
  Serial.println("half");

  for (int i = 0; i < 8; i++) {
    ring2.setPixelColor(i, BrightnessG2, BrightnessR2, BrightnessB2, 0);
    ring2.show();
    delay(100);
  }
  Serial.println("half2");
}