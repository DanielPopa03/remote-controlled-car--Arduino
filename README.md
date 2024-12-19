# Remote Control Car Using Arduino Uno and HC-05 Bluetooth Modules
This project showcases a remote-controlled car powered by an Arduino Uno. The car is driven by four motors and controlled wirelessly 
via Bluetooth using an HC-05 module. The remote control is built using an Arduino Nano, a joystick, and another HC-05 Bluetooth module.

### Features
Wireless Control: Bluetooth communication enables seamless wireless operation.

Joystick Navigation: Intuitive control of car movement using a joystick.

Multi-Motor Drive: Four motors provide stability and maneuverability.

Modular Design: Separate units for the car and the remote control for ease of maintenance and upgrades.

### Components

Car Unit

1x Arduino Uno

1x HC-05 Bluetooth Module

4x DC Motors (or geared motors)

1x Motor Driver Module (L298N or equivalent)
Power Supply (e.g., battery pack for motors and Arduino)
Remote Control Unit'

1x Arduino Nano

1x HC-05 Bluetooth Module

1x Joystick Module

Power Supply (e.g., battery pack or USB power for Nano)

### Laboratoare Incluse:

Laboratorul 0 - Debouncing, 
Timere -PWM, 
Intreruperi, 
USART - serial pt modulul de HC-05

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
| 4 Baterii AA              | 1             | Din Laborator                                                                                            |
| Baterie 9V                | 1             | Din Laborator                                                                                            |
| 4 AA holder               | 1             | Din Laborator              



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

![image](https://github.com/user-attachments/assets/301c5a54-4ad2-4255-8a60-ff5edc6547e3)


![Untitled-1](https://github.com/user-attachments/assets/578c5c6f-dabf-4f33-9b2c-88b621720a55)


![Untitled-2](https://github.com/user-attachments/assets/013f9625-f279-495e-bda3-a06927e7652d)



https://github.com/user-attachments/assets/7850d1cc-df6f-4007-b0ef-c2babf746db3


