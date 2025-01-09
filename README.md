# Remote Control Car Using Arduino Uno and HC-05 Bluetooth Modules
This project showcases a remote-controlled car powered by an Arduino Uno. The car is driven by four motors and controlled wirelessly 
via Bluetooth using an HC-05 module. The remote control is built using an Arduino Nano, a joystick, and another HC-05 Bluetooth module.

### Features
Wireless Control: Bluetooth communication enables seamless wireless operation.

Joystick Navigation: Intuitive control of car movement using a joystick.

Multi-Motor Drive: Four motors provide stability and maneuverability.

Modular Design: Separate units for the car and the remote control for ease of maintenance and upgrades.

### Video
In this video, the car's response time is demonstrated to be nearly instantaneous.
https://github.com/user-attachments/assets/9dd132e5-4b86-436c-b303-646866f958a5

You can clearly observe the car responding promptly to input commands, moving forward, backward, and to the right with precision. This effectively showcases the car's ability to execute commands smoothly and perform movements accurately and efficiently.

https://github.com/user-attachments/assets/452cddff-55b8-4d2d-a3f4-6021f6f6540f




### Components

Car Unit

1x Arduino Uno

1x HC-05 Bluetooth Module

4x DC Motors (or geared motors)

1x Motor Driver Module (L298N or equivalent)

4x AA battery

1x 9V Battery

Remote Control Unit'

1x Arduino Nano

1x HC-05 Bluetooth Module

1x Joystick Module

1x 9V Battery

### Laboratoare Incluse:

Laboratorul 0 - Debouncing, 
Lab Timere -PWM, 
Lab Intreruperi, 
Lab USART - serial pt modulul de HC-05, debugging

Milestone 2

### BOM (Bill of Materials)

| **Componentă**            | **Cantitate** | **Link/Datasheet**                                                                                         |
|----------------------------|---------------|------------------------------------------------------------------------------------------------------------|
| Arduino Uno               | 1             | Din Laborator                                                                                            |
| Arduino Nano              | 1             | Din Laborator                                                                                            |
| Modul Driver L9110S       | 1             | [L9110S Motor Driver](https://www.optimusdigital.ro/ro/drivere-de-motoare-cu-perii/8246-modul-driver.html) |
| HC-05 Bluetooth Module    | 2             | Din Laborator                                                                                            |
| Joystick                  | 1             | [Joystick Module](https://components101.com/sensors/joystick-module)                                     |
| Motoare cu roți           | 4             | Din Laborator                                                                                            |
| Rezistențe 1 kΩ           | 2             | Din Laborator                                                                                            |
| Rezistențe 2 kΩ           | 2             | Din Laborator                                                                                            |
| 4 Baterii AA              | 1             | Cumparate                                                                                              |
| Baterie 9V                | 1             | Cumparate                                                                                               |
| 4 AA holder               | 1             | Cumparat              



Descriere Funcționalitate Hardware
Arduino Uno:

Role: Control principal pentru motoare.
Conectat la HC-05 și Motor Driver.
Utilizează pinii D3, D5, D6, D9 pentru control PWM al driverului de motoare.
Arduino Nano:

Role: Interfața utilizatorului, preluând comenzi de la joystick.
Comunică cu HC-05 pentru a transmite datele către Uno.
HC-05 Bluetooth Modules:

Un modul este pereche cu Nano și celălalt cu Uno pentru comunicare wireless.
Alimentare de 3.3V pentru siguranță.
Joystick:

Utilizat pentru a controla mișcarea vehiculului.
Axele X și Y generează tensiuni analogice interpretate de Nano.
Driverul de Motoare L9110S:

Controlează motoarele pe baza semnalelor PWM primite de la Uno.
Protecție integrată la supraîncălzire.
Rezistențe:

Divizorul de tensiune (1 kΩ și 2 kΩ) protejează pinul RX al HC-05 de tensiunea de 5V.

Pini Arduino

| **Pin**                  | **Conectat la**             | **Funcție**                                     |
|--------------------------|-----------------------------|-------------------------------------------------|
| leftMotor1Foward (D2)    | Driver L9110S D1           | Control motor stânga 1 - direcție înainte       |
| leftMotor1Back (D3)      | Driver L9110S D2           | Control motor stânga 1 - direcție înapoi        |
| leftMotor2Foward (D6)    | Driver L9110S B1           | Control motor stânga 2 - direcție înainte       |
| leftMotor2Back (D7)      | Driver L9110S B2           | Control motor stânga 2 - direcție înapoi        |
| rightMotor1Foward (D4)   | Driver L9110S C1           | Control motor dreapta 1 - direcție înainte      |
| rightMotor1Back (D5)     | Driver L9110S C2          | Control motor dreapta 1 - direcție înapoi       |
| rightMotor2Foward (D8)   | Driver L9110S A1           | Control motor dreapta 2 - direcție înainte      |
| rightMotor2Back (D9)     | Driver L9110S A2           | Control motor dreapta 2 - direcție înapoi       |
| stateBluetooth (D10)     | HC-05 State Pin             | Detectarea conexiunii Bluetooth                 |
| txdBluetooth (D11)       | HC-05 RX                   | Transmiterea datelor către modulul Bluetooth HC-05 |
| rxdBluetooth (D12)       | HC-05 TX                   | Recepționarea datelor de la HC-05               |

Pini Nano

| **Pin**       | **Conectat la**            | **Funcție**                                 |
|---------------|----------------------------|---------------------------------------------|
| BT_TX (D2)    | HC-05 RX                   | Transmiterea datelor către modulul Bluetooth HC-05 |
| BT_RX (D3)    | HC-05 TX                   | Recepționarea datelor de la HC-05           |
| BT_STATE (D4) | HC-05 State Pin            | Detectarea conexiunii Bluetooth             |
| VRX_PIN (A0)  | Joystick Axă X             | Citire poziție joystick - direcție orizontală |
| VRY_PIN (A1)  | Joystick Axă Y             | Citire poziție joystick - direcție verticală |

![schemaMasina](https://github.com/user-attachments/assets/82179c45-614b-4717-985f-5db7f53d376d)

Schema electrică rămâne aproape la fel, numai că uni din pini au fost schimbati (vezi tabel Pini Nano)
![Untitled-2](https://github.com/user-attachments/assets/756bb7f3-4a97-4569-a215-b38d546a3092)


https://github.com/user-attachments/assets/7850d1cc-df6f-4007-b0ef-c2babf746db3


## Milestone 3

### Stadiul actual al implementării software

Au fost implementate toate funcțiile descrise în introducere: mașina se conectează prin Bluetooth la telecomandă, modulul Bluetooth comunică prin USART cu placa de dezvoltare, iar finalul fiecărei transmisii declanșează o întrerupere. Protocolul USART este utilizat și pentru debugging.

Există patru tipuri de mișcare: înainte, stânga, dreapta și spate. Controlul PWM se aplică doar asupra mișcării înainte, deoarece, neavând mecanism de direcție, mișcările la stânga și dreapta nu ar genera suficient demaraj. Mișcarea înainte începe cu un startDuty (procentul inițial de putere aplicat asupra roților) și crește cu 10% la fiecare mișcare consecutivă în aceeași direcție, până la un maxim de 100%.

Pentru a preveni șocurile motoarelor, comenzile sunt puse într-o coadă circulară cu o capacitate de 5 elemente. Coada stochează comenzi consecutive și reține procentul de putere asociat fiecărei comenzi. Dacă se primește o comandă care inițiază o mișcare într-o direcție diferită, coada curentă este resetată și se creează o nouă coadă, oferind astfel o senzație de responsiveness. La inițializarea unei cozi noi, se adaugă un prim element, iar un timer este declanșat. Timerul rulează la un interval de 0.5 secunde, elimină câte un element din coadă și execută comanda corespunzătoare.

### Motivați alegerea bibliotecilor folosite în cadrul proiectului:

Biblioteca SoftwareSerial.h a fost aleasă pentru a permite realizarea unei comunicări seriale pe pini diferiți față de cei folosiți pentru comunicarea cu portul serial principal (de obicei, RX0 și TX0). În cadrul acestui proiect, am folosit SoftwareSerial pentru a configura o comunicare bidirecțională între microcontroler și modulul Bluetooth HC-05, atât pe partea telecomenzii, cât și pe partea mașinii robotizate.

### Evidențiați elementul de noutate al proiectului

Elementul de noutate al proiectului constă în utilizarea unei soluții de comunicare wireless prin Bluetooth pentru controlul unei mașini robotizate, precum și modul inovativ de configurare și integrare a acestei comunicări în cadrul sistemului. Proiectul folosește modulul Bluetooth HC-05, care permite o conexiune fără fir între telecomandă și mașină, oferind o soluție accesibilă și eficientă pentru controlul la distanță.

Un aspect inovativ este abordarea configurării modulului Bluetooth pentru a asigura o comunicare bidirecțională stabilă și rapidă. Comunicarea serială cu modulul HC-05 se realizează prin biblioteca SoftwareSerial, care permite utilizarea unui port serial suplimentar pe microcontroler, diferit de portul principal utilizat pentru debugging. Astfel, s-a reușit simultan comunicarea cu dispozitivele externe și monitorizarea comportamentului sistemului, fără a întrerupe fluxul de date între telecomandă și mașină.

### Justificați utilizarea funcționalităților din laborator în cadrul proiectului

#### PWM (Laboratorul Timere - PWM)
Controlul precis al motoarelor este realizat prin utilizarea timere-lor pentru generarea semnalelor PWM. În proiect
PWM-ul este folosit pentru reglarea vitezei mișcărilor înainte, asigurând un demaraj progresiv și evitând șocurile mecanice asupra motoarelor.

#### Întreruperi și Timere(Laboratorul Întreruperi)
Întreruperile sunt fundamentale pentru gestionarea eficientă a transmisiei datelor prin protocolul USART. În proiect, fiecare transmisie de la modulul Bluetooth către placa de dezvoltare declanșează o întrerupere, care permite procesarea comenzilor primite fără a bloca execuția altor operații. Acest mecanism asigură un răspuns rapid și consistent la comenzile utilizatorului.
Timerele sunt utilizate pentru a controla progresia comenzilor stocate în coada circulară, executând comenzile la fiecare 0.5 secunde.

#### USART (Laboratorul Debugging)
Protocolul USART este folosit pentru comunicarea între modulul Bluetooth HC-05 și placa de dezvoltare.

HC-05 primește comenzile de la telecomandă și le transmite către microcontroller prin USART.
În plus, debugging-ul este realizat prin același protocol, permițând monitorizarea procesului de execuție a comenzilor și detectarea eventualelor erori.


### Explicați scheletul proiectului, interacțiunea dintre functionalități și modul în care a fost validat că acestea funcționează conform

Proiectul este format din două componente principale: telecomanda și mașina controlată prin Bluetooth, care comunică prin intermediul modulului HC-05. Telecomanda are rolul de a prelua input-ul utilizatorului prin joystick-uri analogice și de a trimite comenzi corespunzătoare către mașină. Valorile analogice ale joystick-ului sunt citite și comparate cu un centru prestabilit (500) și un prag de variație (200), determinând direcția mișcării. În funcție de aceste valori, telecomanda trimite comenzi codificate ('F' pentru înainte, 'B' pentru spate, 'L' pentru stânga și 'R' pentru dreapta) către modulul Bluetooth. Transmisiunile sunt validate prin afișarea în consola serială a comenzilor și a valorilor analogice detectate.

Mașina primește comenzile prin modulul HC-05 și le procesează utilizând o structură de coadă circulară pentru gestionarea progresivă a intensității mișcării. Dacă două comenzi consecutive sunt identice, intensitatea PWM crește cu 10%, păstrând continuitatea mișcării. În cazul unei comenzi diferite, coada este resetată, iar un nou set de comenzi este inițiat. Timerul configurat generează o întrerupere la fiecare 500 ms, care este folosită pentru a extrage și a executa comenzile din coadă, aplicând semnalele PWM către motoare.

Validarea funcționalităților s-a realizat prin afișarea comenzilor primite și a valorilor PWM aplicate în consola serială. Pentru telecomandă, verificările au inclus testarea pragurilor și interpretarea corectă a mișcărilor joystick-ului. La nivelul mașinii, au fost testate scenarii de procesare a comenzilor consecutive și gestionarea resetării cozii, iar rezultatele au fost monitorizate în timp real pentru a asigura coerența între comenzile primite și acțiunile executate. Această integrare a funcționalităților a garantat comportamentul corect al sistemului în timpul testelor practice.


### Explicați cum ați realizat calibrarea elementelor de senzoristică


Calibrarea elementelor de senzoristică în proiectul nostru a fost realizată în principal prin configurarea și ajustarea modului Bluetooth HC-05 folosind comenzi AT.

Pentru a configura modul Bluetooth HC-05, am utilizat următorul cod
```
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // TX=2, RX=3 BLUETOOTH MODULE
void setup() {
Serial.begin(9600);
Serial.println("Enter AT commands:");
mySerial.begin(38400);
}
void loop()
{
if (mySerial.available())
Serial.write(mySerial.read());
if (Serial.available())
mySerial.write(Serial.read());
}
```
care a activat modul AT pe HC-05, permițând astfel transmiterea și modificarea setărilor acestuia printr-o conexiune serială. La început, am setat modul Bluetooth pentru a intra în modul AT prin apăsarea butonului de pe modulul HC-05, urmată de reconectarea USB-ului. Aceasta a făcut ca LED-ul modulului Bluetooth să clipească la fiecare 2 secunde, indicând faptul că modulul era pregătit pentru a primi comenzi AT.

După conectarea corectă a modulului HC-05 la Arduino și configurarea setărilor de baud rate (9600 bps), am început să interacționăm cu modulul Bluetooth prin comenzi AT. Am verificat dacă modulul răspunde corect la comenzile de tip AT, care sunt folosite pentru a configura parametrii modulului, precum numele dispozitivului, rolul acestuia (master sau slave) și setările de comunicație serială.

Prin comenzi precum AT+ROLE=0 (pentru configurarea modulului ca slave) și AT+ROLE=1 (pentru configurarea modulului ca master), am definit rolurile fiecărei unități din cadrul rețelei Bluetooth. De asemenea, am folosit comanda AT+BIND=, care permite asocieri între un modul master și un modul slave, pentru a asigura legătura corectă între telecomandă și mașina robotizată.

Această calibrare a fost crucială pentru a asigura o conexiune stabilă și eficientă între cele două dispozitive, permițând controlul la distanță al mașinii prin telecomandă, utilizând tehnologia wireless Bluetooth. Validarea acestui proces a fost realizată prin observarea sincronizării LED-urilor celor două module Bluetooth, care au început să clipească simultan, confirmând astfel că legătura între ele a fost realizată cu succes.
