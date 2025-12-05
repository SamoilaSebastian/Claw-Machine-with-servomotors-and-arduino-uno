# Claw Machine cu Arduino Uno 🕹️🤖

Un proiect de tip braț robotic (Claw Machine) controlat manual printr-un joystick. Proiectul folosește servomotoare cu rotație continuă pentru deplasarea pe axe și un servomotor standard de putere pentru acționarea cleștelui/ghearei.

## 📦 Componente Hardware

* **1x Placă de dezvoltare:** Arduino Uno
* **2x Servomotoare cu Rotație Continuă:** Model **DS04-NFC** (folosite pentru axele X și Y - deplasare stânga/dreapta și față/spate).
* **1x Servomotor Standard:** Model **MG995** (Metal Gear) - folosit pentru axa Z (coborârea/ridicarea sau închiderea/deschiderea ghearei).
* **1x Modul Joystick:** (tip KY-023 sau similar)
* **Sursă de alimentare externă** (Recomandat: 5V pentru servomotoare, deoarece MG995 consumă mult curent).
* Fire Jumper și Breadboard.

## 🔌 Diagrama de Conexiuni (Pinout)

Conectează componentele la pinii Arduino conform tabelului de mai jos, bazat pe codul sursă:

| Componentă | Pin Componentă | Pin Arduino |
| :--- | :--- | :--- |
| **Servo OX** (Stânga/Dreapta) | Semnal (Orange/Galben) | **D8** |
| **Servo OY** (Față/Spate) | Semnal (Orange/Galben) | **D9** |
| **Servo OZ** (Gheară/Lift) | Semnal (Orange/Galben) | **D10** |
| **Joystick** | VRx | **A0** |
| **Joystick** | VRy | **A1** |
| **Joystick** | SW (Buton) | **D2** |
| **Toate** | VCC (+) | 5V |
| **Toate** | GND (-) | GND |

> **Notă:** Asigură-te că masa (GND) sursei externe de alimentare este conectată la masa (GND) plăcii Arduino.

## ⚙️ Cum funcționează codul

Sistemul citește valorile analogice de la Joystick și controlează motoarele astfel:

### 1. Axa OX (Deplasare Orizontală) - DS04-NFC
* **Joystick Stânga:** Servomotorul se rotește într-o direcție (`write(0)`).
* **Joystick Dreapta:** Servomotorul se rotește în direcția opusă (`write(180)`).
* **Joystick Centru:** Servomotorul stă pe loc (`write(90)` - punct neutru pentru rotație continuă).

### 2. Axa OY (Deplasare Verticală/Adâncime) - DS04-NFC
* Funcționează identic cu axa OX, controlând al doilea motor cu rotație continuă.

### 3. Axa OZ (Acțiune Gheară) - MG995
* Acționat prin **apăsarea butonului** de pe Joystick.
* **Ciclul de funcționare:**
    1.  La apăsare, servo-ul execută o mișcare de coborâre/apucare (`180 grade`).
    2.  Așteaptă **3 secunde** (`delay(3000)`).
    3.  Revine la poziția inițială de ridicare (`0 grade`).

## 🚀 Instalare și Utilizare

1.  Descarcă acest repository.
2.  Deschide fișierul `.ino` în Arduino IDE.
3.  Instalează biblioteca `Servo.h` (dacă nu este deja instalată).
4.  Selectează placa **Arduino Uno** și portul corect.
5.  Încarcă (Upload) codul pe placă.

## ⚠️ Sfaturi Importante
* **Alimentare:** Servomotorul MG995 este puternic. Dacă observi că Arduino se restartează când se mișcă gheara, înseamnă că portul USB nu oferă suficient curent. Folosește o sursă externă (baterii sau alimentator 5V 2A+).
* **Calibrare:** Dacă servomotoarele cu rotație continuă se mișcă ușor chiar și când joystick-ul este la centru, ajustează valoarea `90` din cod (ex: 89 sau 91) până când se opresc complet.
