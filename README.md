# Auteur

Je suis 
[Gerard KESSE](http://5.48.215.193:8855/presentation/ "Accédez à mon site web (ReadyDev)"),  
Ingénieur en Développement Informatique C/C++/Qt,  
Avec à la fois des compétences en Systèmes Embarqués et en Robotique.  

* Site Web : [ReadyDev](http://5.48.215.193:8855 "Accédez à mon site web (ReadyDev)")
* Email : [tiakagerard@hotmail.com](mailto:tiakagerard@hotmail.com?subject=Contact&body=Bonjour "Me contactez par email")
* Tel : [(+33) 06.58.77.23.97](tel:00330658772397 "Contactez-moi")
* Localité : **Toulouse - France**

# Ready8051

**Ready8051** est une bibliothèque de fonction C pour le développement de système 
embarqué mutlitâche temps réel sur des microcontrôleurs de la famille 8051.
Elle est construite autour de l'architecture TTA (Time Triggered Architecture), 
une architecture logicielle déclenchée par le temps et certifiée pour le développement 
de systèmes de sécurité critique. Il suffit d'un Timer pour mettre en place 
cette architecture RTOS. Elle est portable sur plusieurs cibles de microcontrôleurs 
(8051, PIC) et de microprocesseurs (ARM).  
C'est une bibliothèque développée en C et maintenu par 
[Gerard KESSE](http://5.48.215.193:8855/presentation/ "Accédez à mon site web (ReadyDev)").

Bases:  
* [Lecture et Ecriture sur un Port](https://github.com/gkesse/Ready8051/tree/master/Port "Lecture et Ecriture sur un Port")  
* [Lecture et Ecriture sur un Bit](https://github.com/gkesse/Ready8051/tree/master/Bit "Lecture et Ecriture sur un Bit")  

Délais:  
* [Délai Logiciel](https://github.com/gkesse/Ready8051/tree/master/Delai "Délai Logiciel")  
* [Délai Timer T0](https://github.com/gkesse/Ready8051/tree/master/Délai_Timer_T0 "Délai Timer T0")  
* [Délai Timer T1](https://github.com/gkesse/Ready8051/tree/master/Délai_Timer_T1 "Délai Timer T1")  
* [Délai Timer T2](https://github.com/gkesse/Ready8051/tree/master/Délai_Timer_T2 "Délai Timer T2")  

Interruptions:  
* [Interruption Timer T0](https://github.com/gkesse/Ready8051/tree/master/Interruption_Timer_T0 "Interruption Timer T0")  
* [Interruption Timer T1](https://github.com/gkesse/Ready8051/tree/master/Interruption_Timer_T1 "Interruption Timer T1")  
* [Interruption Timer T2](https://github.com/gkesse/Ready8051/tree/master/Interruption_Timer_T2 "Interruption Timer T2")  

Architectures Standards:  
* [Boucle Infinie](https://github.com/gkesse/Ready8051/tree/master/Boucle_Infinie "Boucle Infinie")  
* [Boucle Infinie Amélioriée](https://github.com/gkesse/Ready8051/tree/master/Boucle_Infinie_Amelioration "Boucle Infinie Amélioriée")  
* [Machine à Etats Finis](https://github.com/gkesse/Ready8051/tree/master/Machine_Etat "Machine à Etats Finis")  

Architectures RTOS:  
* [Système d'Exploitation Embarqué Simple](https://github.com/gkesse/Ready8051/tree/master/Systeme_Exploitation_Embarque_Simple "Système d'Exploitation Embarqué Simple")  
* [Ordonnanceur Multitâche Temps Réel](https://github.com/gkesse/Ready8051/tree/master/Ordonnanceur "Ordonnanceur")  
* [Ordonnanceur Coopérative](https://github.com/gkesse/Ready8051/tree/master/Ordonnanceur_Cooperative "Ordonnanceur Coopérative")  
* [Ordonnanceur Hybride](https://github.com/gkesse/Ready8051/tree/master/Bit "Bit")  

Périphériques d'Entrée:  
* [Bouton Poussoir](https://github.com/gkesse/Ready8051/tree/master/Bouton "Bouton Poussoir")  
* [Clavier Linéaire](https://github.com/gkesse/Ready8051/tree/master/Clavier "Clavier Linéaire")  
* [Clavier Matriciel](https://github.com/gkesse/Ready8051/tree/master/Clavier_Matriciel "Clavier Matriciel")  

Périphériques de Sortie:  
* [Diode LED](https://github.com/gkesse/Ready8051/tree/master/LED "Diode LED")  
* [Afficheur 7-segment](https://github.com/gkesse/Ready8051/tree/master/7Segment "Afficheur 7-segment")  
* [Afficheur LCD Alphanumérique](https://github.com/gkesse/Ready8051/tree/master/LCD "Afficheur LCD Alphanumérique")  
* [Afficheur LCD Graphique](https://github.com/gkesse/Ready8051/tree/master/LCD_Graphique "Afficheur LCD Graphique")  

Protocoles:
* [I2C](https://github.com/gkesse/Ready8051/tree/master/I2C "I2C")  
* [UART](https://github.com/gkesse/Ready8051/tree/master/UART "UART")  
* [SPI](https://github.com/gkesse/Ready8051/tree/master/SPI "SPI")  
* [CAN](https://github.com/gkesse/Ready8051/tree/master/CAN "CAN")  
* [Bluetooth](https://github.com/gkesse/Ready8051/tree/master/Bluetooth "Bluetooth")  
* [ZigBee](https://github.com/gkesse/Ready8051/tree/master/ZigBee "ZigBee")  
* [WiFi](https://github.com/gkesse/Ready8051/tree/master/WiFi "WiFi")  
* [Ethernet](https://github.com/gkesse/Ready8051/tree/master/Ethernet "Ethernet")  

# Technologies

Le développement de la bibliothèque **Ready8051** a nécessité les technologies suivantes :

* Langage : **C**
* Microcontrôleur 8051 : **AT89C52, INFINEON C515**
* Microcontrôleur PIC : **PIC18F452**
* Microprocesseur ARM : **LPC1769, LPC2148**
* IDE 8051: **Keil µVision**
* IDE PIC: **MPLab**
* IDE ARM: **GNU ARM Eclipse**
* Compilateur 8051 : **SDDC**
* Simulateur de Circuit Electrique : **Proteus**
* Protocoles : **RS232, I2C, SPI, CAN, USB, Bluetooth, WiFi**
* Modules : **Switch , Button, Keypad, LED, 7-segment, LCD, PWD**
* Architecture Logicielle : **TTA (Time Triggered Architecture)**
* Cible : **8051, PIC, ARM**
